import { FastifyRequest, FastifyReply } from "fastify";
import {list} from "../services/actions/list";
import _, { reject } from "lodash";
import Action, {IAction} from "../models/ActionsSchema";

function getAvailableAction(req: FastifyRequest, res: FastifyReply) {
    return res.status(200).send({actions: list});
}

async function createAction(req: FastifyRequest<{ Body: IAction }>, res: FastifyReply) {
    try {
        const actionBody = req.body as IAction;
        const newAction = new Action(actionBody);
        const savedAction = await newAction.save();

        if (savedAction && savedAction._id) {
            return {action: savedAction}
        } else {
            throw {statusCode: 500, message: "Something went wrong"}
        }

    } catch (e) {
        console.log(e);
        throw {statusCode: 500, message: "Something went wrong"};
    }
}

async function getAllActions(req: FastifyRequest, res: FastifyReply): Promise<IAction[]> {
    try {
        const actions = await Action.find();
        return actions;
    } catch (e) {
        console.log(e);
        throw {statusCode: 500, message: "Unable to get actions"};
    }
}

async function getActionById(req: FastifyRequest<{ Params: { id: string } }>, res: FastifyReply): Promise<IAction> {
    try {
        const action = await Action.findById(req.params.id);
        if (!action) {
            throw {statusCode: 404, message: "Action not found"};
        }
        return action;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to get action"};
    }
}

async function updateActionById(req: FastifyRequest<{ Params: { id: string }, Body: IAction }>, res: FastifyReply): Promise<IAction> {
    try {
        const action = await Action.findByIdAndUpdate(req.params.id, req.body, {new: true});
        if (!action) {
            throw {statusCode: 404, message: "Action not found"};
        }
        return action;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to update action"};
    }
}

async function deleteActionById(req: FastifyRequest<{ Params: { id: string } }>, res: FastifyReply): Promise<IAction> {
    try {
        const action = await Action.findByIdAndDelete(req.params.id);
        if (!action) {
            throw {statusCode: 404, message: "Action not found"};
        }
        return action;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to delete action"};
    }
}

export {
    getAvailableAction,
    createAction,
    getAllActions,
    getActionById,
    deleteActionById,
    updateActionById,
}