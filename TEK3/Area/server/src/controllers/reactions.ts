import { FastifyRequest, FastifyReply } from "fastify";
import Reaction, {IReaction} from "../models/ReactionsSchema";

import {list} from "../services/reactions/list";

function getAvailableReaction(req: FastifyRequest, res: FastifyReply) {
    res.status(200).send({reactions: list});
}

async function createReaction(req: FastifyRequest<{ Body: IReaction }>, res: FastifyReply): Promise<IReaction> {
    try {
        const reactionBody = req.body as IReaction;
        const newReaction = new Reaction(reactionBody);
        const savedReaction = await newReaction.save();
        if (savedReaction && savedReaction._id) {
            return savedReaction;
        } else {
            throw {statusCode: 500, message: "Something went wrong"}
        }
    } catch (e) {
        console.log(e);
        throw {statusCode: 500, message: "Something went wrong"};
    }
}

async function getAllReactions(req: FastifyRequest, res: FastifyReply): Promise<IReaction[]> {
    try {
        const reactions = await Reaction.find();
        return reactions;
    } catch (e) {
        console.log(e);
        throw {statusCode: 500, message: "Unable to get reactions"};
    }
}

async function getReactionById(req: FastifyRequest<{ Params: { id: string } }>, res: FastifyReply): Promise<IReaction> {
    try {
        const reaction = await Reaction.findById(req.params.id);
        if (!reaction) {
            throw {statusCode: 404, message: "Reaction not found"};
        }
        return reaction;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to get reaction"};
    }
}

async function updateReactionById(req: FastifyRequest<{ Params: { id: string }, Body: IReaction }>, res: FastifyReply): Promise<IReaction> {
    try {
        const reaction = await Reaction.findByIdAndUpdate(req.params.id, req.body, {new: true});
        if (!reaction) {
            throw {statusCode: 404, message: "Reaction not found"};
        }
        return reaction;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to update reaction"};
    }
}

async function deleteReactionById(req: FastifyRequest<{ Params: { id: string } }>, res: FastifyReply): Promise<IReaction> {
    try {
        const reaction = await Reaction.findByIdAndDelete(req.params.id);
        if (!reaction) {
            throw {statusCode: 404, message: "Reaction not found"};
        }
        return reaction;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to delete reaction"};
    }
}

export {
    getAvailableReaction,
    createReaction,
    getAllReactions,
    getReactionById,
    updateReactionById,
    deleteReactionById,
}