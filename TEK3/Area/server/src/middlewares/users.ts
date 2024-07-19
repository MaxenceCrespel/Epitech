import { FastifyRequest, FastifyReply, HookHandlerDoneFunction } from 'fastify';
import { IUser } from '../models/UserSchema';

const canCreateUser = (
    req: FastifyRequest<{ Body: IUser }>,
    res: FastifyReply,
    next: HookHandlerDoneFunction
) => {
    const { email, password } = req.body;
    if (!email || !password) {
        res.status(400).send({
            message: 'Missing required fields: email and password',
        });
        return;
    }
    next();
};

export { canCreateUser };