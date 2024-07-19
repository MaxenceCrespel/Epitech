import User, { IUser } from '../models/UserSchema'
import { FastifyRequest, FastifyReply } from 'fastify'
import bcrypt from 'bcryptjs'

async function createUser(req:any, res:any) {
    const user: IUser = new User(
        {
            username: req.body.username,
            name: req.body.name,
            firstname: req.body.firstname,
            email: req.body.email,
            password: bcrypt.hashSync(req.body.password, 16)
        }
    )
    try {
        await user.save();
        return res.send({ message: 'User created successfully' })
    } catch (err) {
        return res.status(400).send({ error: 'Email is taken' })
    }
}

async function getAllUsers(req: FastifyRequest,res: FastifyReply) {
    try {
        const users = await User.find({}, { password: 0, __v: 0, email: 0 });
        return res.status(200).send(users);
    } catch (err) {
        return res.status(400).send({ error: 'Something went wrong', data: err });
    }
};

async function updateUser(req: FastifyRequest<{
    Params: { id: string };
    Body: IUser;
}>, res: FastifyReply) {
    try {
        const user = await User.findByIdAndUpdate(req.params.id, req.body, { new: true });
        return res.status(200).send(user);
    } catch (err) {
        return res.status(400).send({ error: 'Something went wrong', data: err });
    }
}

async function deleteUser(req: FastifyRequest<{
    Params: { id: string };
}>, res: FastifyReply) {
    try {
        const user = await User.findByIdAndDelete(req.params.id);
        return res.status(200).send(user);
    } catch (err) {
        return res.status(400).send({ error: 'Something went wrong', data: err });
    }
}

async function getUser(req: FastifyRequest<{
    Params: { id: string };
}>, res: FastifyReply) {
    try {
        const user = await User.find({ _id: req.params.id }, { password: 0, __v: 0, email: 0 });
        return res.status(200).send(user[0]);
    } catch (err) {
        return res.status(400).send({ error: 'Something went wrong', data: err });
    }
}

async function getCurrentUser(req: FastifyRequest,
res: FastifyReply) {
    try {
        const user = await User.findById(req.user.id, { password: 0, __v: 0 });
        return res.status(200).send(user);

    } catch (err) {
        return res.status(400).send({ error: 'Something went wrong', data: err });
    }
}

export { createUser, getAllUsers, updateUser, deleteUser, getUser, getCurrentUser };