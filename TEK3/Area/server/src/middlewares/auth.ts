import { FastifyRequest, FastifyReply, HookHandlerDoneFunction } from 'fastify';
import User, {IUser} from '../models/UserSchema';
import jwt from 'jsonwebtoken';
import dotenv from 'dotenv';
dotenv.config({
    path: '../../.env'
});

function getJwt(req: FastifyRequest<{ Headers: { authorization: string } }>) {
    const authorization = req.headers.authorization;
    const token = authorization?.split(' ')[1];
    return token;
}

declare module 'fastify' {
    interface FastifyRequest {
        user: IUser
    }
}

export async function jwtVerify(token: string, secret: string): Promise<any> {
    return new Promise((resolve, reject) => {
    jwt.verify(token, secret, (err, decoded) => {
        if (err) return reject(err);
            resolve(decoded);
        });
    });
}

export const auth = async (req: FastifyRequest<{ Headers: { authorization: string } }>, res: FastifyReply, next: HookHandlerDoneFunction) => {
    try {
        const token = getJwt(req);
        if (!token) {
            return res.status(401).send({ error: 'No token provided' });
        }
        const decoded = await jwtVerify(token, process.env.JWT_SECRET || '');
        const user = await User.findById(decoded.id);
        if (!user) {
            return res.status(401).send({ error: 'User not found' });
        }
        req.user = user;
    } catch (err) {
        return res.status(401).send({ error: 'Invalid token' });
    }
};

