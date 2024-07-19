"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.googleLogin = exports.googleAuthLink = exports.reset = exports.login = void 0;
const mongoose_1 = require("mongoose");
const jsonwebtoken_1 = __importDefault(require("jsonwebtoken"));
const dotenv_1 = __importDefault(require("dotenv"));
const googleapis_1 = require("googleapis");
dotenv_1.default.config({
    path: '../../.env'
});
const bcryptjs_1 = __importDefault(require("bcryptjs"));
const UserSchema_1 = __importDefault(require("../models/UserSchema"));
const permissionsList_1 = __importDefault(require("../utils/permissionsList"));
// OAuth2 with Google
const oauth2Client = new googleapis_1.google.auth.OAuth2(process.env.GOOGLE_CLIENT_ID, process.env.GOOGLE_CLIENT_SECRET, process.env.GOOGLE_REDIRECT_URL);
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
function signGoogleAsync(code) {
    return __awaiter(this, void 0, void 0, function* () {
        return new Promise((resolve, reject) => {
            oauth2Client.getToken(code, (err, tokens) => {
                if (err) {
                    reject(err);
                }
                else if (tokens) {
                    resolve(tokens);
                }
                else {
                    reject(new mongoose_1.Error("Tokens are undefined"));
                }
            });
        });
    });
}
function getGoogleUserInfo(tokens) {
    return new Promise((resolve, reject) => {
        const oauth2 = googleapis_1.google.oauth2({
            auth: oauth2Client,
            version: 'v2'
        });
        oauth2.userinfo.get((err, res) => {
            if (err) {
                reject(err);
            }
            else if (res) {
                resolve(res.data);
            }
            else {
                reject(new mongoose_1.Error("User info is undefined"));
            }
        });
    });
}
function googleLogin(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        const code = req.query.code;
        if (!code) {
            res.status(400).send({ error: 'Code is required' });
            return;
        }
        try {
            const tokens = yield signGoogleAsync(code);
            oauth2Client.setCredentials(tokens);
            const user = yield getGoogleUserInfo(tokens);
            const userData = yield UserSchema_1.default.findOne({ googleId: user.id });
            if (!userData) {
                const password = Math.random().toString(36).slice(-8);
                const newUser = new UserSchema_1.default({
                    username: user.name.replace(/\s/g, '').toLowerCase().slice(0, 20),
                    email: user.email,
                    name: user.given_name,
                    firstname: user.name,
                    password: bcryptjs_1.default.hashSync(password, 16),
                    permissions: permissionsList_1.default.ADMIN,
                    googleId: user.id,
                    googleTokens: tokens,
                    avatar_url: user.picture,
                    created_at: Date.now()
                });
                yield newUser.save();
                const secret = process.env.JWT_SECRET;
                const token = yield signAsync({ id: newUser._id }, secret, { expiresIn: '1h' });
                // Include the user info in the response
                return res.status(200).send({ token, user: newUser });
            }
            else {
                userData.googleTokens = tokens;
                userData.googleId = user.id;
                userData.save();
                const secret = process.env.JWT_SECRET;
                const token = yield signAsync({ id: userData._id }, secret, { expiresIn: '1h' });
                // Include the user info in the response
                return res.status(200).send({ token, user: userData });
            }
        }
        catch (err) {
            console.log(err);
            return res.status(500).send({ error: 'Something went wrong' });
        }
    });
}
exports.googleLogin = googleLogin;
function googleAuthLink(req, res) {
    const url = getGoogleAuthUrl();
    return res.status(200).send({ url });
}
exports.googleAuthLink = googleAuthLink;
function signAsync(payload, secret, options) {
    return new Promise((resolve, reject) => {
        jsonwebtoken_1.default.sign(payload, secret, options, (err, token) => {
            if (err) {
                reject(err);
            }
            else if (token) {
                resolve(token);
            }
            else {
                reject(new mongoose_1.Error("Token is undefined"));
            }
        });
    });
}
function login(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        const body = req.body;
        const user = {
            email: body.email || undefined,
            username: body.username || undefined,
            password: body.password
        };
        if (!user.email && !user.username) {
            res.status(400).send({ error: 'Email or username is required' });
            return;
        }
        else if (!user.password) {
            res.status(400).send({ error: 'Password is required' });
            return;
        }
        const userData = yield UserSchema_1.default.findOne({ $or: [{ email: user.email }, { username: user.username }] });
        if (!userData) {
            res.status(400).send({ error: 'User not found' });
            return;
        }
        const passwordIsValid = bcryptjs_1.default.compareSync(user.password, userData.password);
        if (!passwordIsValid) {
            res.status(400).send({ error: 'Invalid password' });
            return;
        }
        try {
            const secret = process.env.JWT_SECRET;
            if (!secret) {
                res.status(500).send({ error: 'JWT secret is not defined' });
                return;
            }
            const token = yield signAsync({ id: userData._id }, secret, { expiresIn: '1h' });
            return res.status(200).send({ "token": token });
        }
        catch (err) {
            console.log(err);
            return res.status(500).send({ error: 'Something went wrong' });
        }
    });
}
exports.login = login;
function reset(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        const token = yield signAsync({ id: req.user._id }, process.env.JWT_SECRET, { expiresIn: '1h' });
        return res.status(200).send({ token });
    });
}
exports.reset = reset;
