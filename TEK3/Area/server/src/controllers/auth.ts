
import { Error } from 'mongoose';
import jsonwebtoken from 'jsonwebtoken';
import dotenv from 'dotenv';
import { google } from 'googleapis';

dotenv.config({
    path: '../../.env'
});


import bcrypt from 'bcryptjs';

import User, { IUser } from '../models/UserSchema';
import { FastifyReply, FastifyRequest } from 'fastify';
import PermissionsList from '../utils/permissionsList';

interface ILogin {
    email: string | undefined;
    username: string | undefined;
    password: string;
}

// OAuth2 with Google

const oauth2Client = new google.auth.OAuth2(
    process.env.GOOGLE_CLIENT_ID,
    process.env.GOOGLE_CLIENT_SECRET,
    process.env.GOOGLE_REDIRECT_URL
);

function getGoogleAuthUrl() {
    const scopes = [
        'https://www.googleapis.com/auth/userinfo.profile',
        'https://www.googleapis.com/auth/userinfo.email'
    ];
    return oauth2Client.generateAuthUrl({
        access_type: 'offline',
        prompt: 'consent',
        scope: scopes
    });
}

async function signGoogleAsync(code: string) {
    return new Promise((resolve, reject) => {
        oauth2Client.getToken(code, (err, tokens) => {
            if (err) {
                reject(err);
            } else if (tokens) {
                resolve(tokens);
            } else {
                reject(new Error("Tokens are undefined"));
            }
        });
    });
}

function getGoogleUserInfo(tokens: any) {
    return new Promise((resolve, reject) => {
        const oauth2 = google.oauth2({
            auth: oauth2Client,
            version: 'v2'
        });
        oauth2.userinfo.get((err, res) => {
            if (err) {
                reject(err);
            } else if (res) {
                resolve(res.data);
            } else {
                reject(new Error("User info is undefined"));
            }
        });
    });
}

async function googleLogin(req: FastifyRequest<{
    Querystring: {
        code: string
    }
}>, res: any) {
    const code = req.query.code;
    if (!code) {
        res.status(400).send({ error: 'Code is required' });
        return;
    }
    try {
        const tokens: any = await signGoogleAsync(code);
        oauth2Client.setCredentials(tokens);
        const user: any = await getGoogleUserInfo(tokens);
        const userData = await User.findOne({ googleId: user.id });
        if (!userData) {
            const password = Math.random().toString(36).slice(-8);
            const newUser = new User({
                username: user.name.replace(/\s/g, '').toLowerCase().slice(0, 20),
                email: user.email,
                name: user.given_name,
                firstname: user.name,
                password: bcrypt.hashSync(password, 16),
                permissions: PermissionsList.ADMIN,
                googleId: user.id,
                googleTokens: tokens,
                avatar_url: user.picture,
                created_at: Date.now()
            });
            await newUser.save();
            const secret: string | undefined = process.env.JWT_SECRET;
            const token = await signAsync({ id: newUser._id }, secret as string, { expiresIn: '1h' });

            // Include the user info in the response
            return res.status(200).send({ token, user: newUser });
        } else {
            userData.googleTokens = tokens;
            userData.googleId = user.id;
            userData.save();
            const secret: string | undefined = process.env.JWT_SECRET;
            const token = await signAsync({ id: userData._id }, secret as string, { expiresIn: '1h' });

            // Include the user info in the response
            return res.status(200).send({ token, user: userData });
        }
    } catch (err) {
        console.log(err);
        return res.status(500).send({ error: 'Something went wrong' });
    }
}


function googleAuthLink(req: FastifyRequest, res: FastifyReply) {
    const url = getGoogleAuthUrl();
    return res.status(200).send({ url });
}

function signAsync(payload: object, secret: string, options: object): Promise<string> {
    return new Promise((resolve, reject) => {
        jsonwebtoken.sign(payload, secret, options, (err, token) => {
            if (err) {
                reject(err);
            } else if (token) {
                resolve(token);
            } else {
                reject(new Error("Token is undefined"));
            }
        });
    });
}


async function login(req: any , res: any) {
    const body = req.body as ILogin;
    const user : ILogin = {
        email: body.email || undefined,
        username: body.username || undefined,
        password: body.password
    }

    if (!user.email && !user.username) {
        res.status(400).send({ error: 'Email or username is required' });
        return;
    } else if (!user.password) {
        res.status(400).send({ error: 'Password is required' });
        return;
    }

    const userData = await User.findOne({ $or: [{ email: user.email }, { username: user.username }] });
    if (!userData) {
        res.status(400).send({ error: 'User not found' });
        return;
    }
    const passwordIsValid = bcrypt.compareSync(user.password, userData.password);
    if (!passwordIsValid) {
        res.status(400).send({ error: 'Invalid password' });
        return;
    }
    try {
        const secret: string | undefined = process.env.JWT_SECRET;
        if (!secret) {
            res.status(500).send({ error: 'JWT secret is not defined' });
            return;
        }
        const token = await signAsync({ id: userData._id }, secret as string, { expiresIn: '1h' });
        return res.status(200).send({ "token": token });
    } catch (err) {
        console.log(err);
        return res.status(500).send({ error: 'Something went wrong' });
    }
}

async function reset(req: any, res: any) {
    const token = await signAsync({ id: req.user._id }, process.env.JWT_SECRET as string, { expiresIn: '1h' });
    return res.status(200).send({ token });
}

export { login, reset, googleAuthLink, googleLogin};