import { FastifyRequest, FastifyReply } from "fastify";
import {list as appletList} from "../services/applets/functions/list";
import _, { reject } from "lodash";
import Applet, {IApplet} from "../models/AppletSchema";
import agenda from "../utils/agenda";
import executeApplet, {stopApplet} from "../services/applets/executeApplet";

function getAppletsFunctions(req: FastifyRequest, reply: FastifyReply) {
    return reply.send({ applets: appletList });
}

async function createApplet(req: FastifyRequest, reply: FastifyReply) {
    try {
        const appletBody = req.body as IApplet;
        const newApplet = new Applet(appletBody);
        const savedApplet = await newApplet.save();
        return savedApplet;
    } catch (e) {
        console.log(e);
        throw {statusCode: 500, message: "Something went wrong"};
    }
}

async function getAllApplets(req: FastifyRequest, reply: FastifyReply) {
    try {
        const applets = await Applet.find();
        return applets;
    } catch (e) {
        console.log(e);
        throw {statusCode: 500, message: "Unable to get applets"};
    }
}

async function getAppletById(req: FastifyRequest<{ Params: { id: string } }>, reply: FastifyReply) {
    try {
        const applet = await Applet.findById(req.params.id);
        if (!applet) {
            throw {statusCode: 404, message: "Applet not found"};
        }
        return applet;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to get applet"};
    }
}

async function updateAppletById(req: FastifyRequest<{ Params: { id: string }, Body: IApplet }>, reply: FastifyReply) {
    try {
        const applet = await Applet.findByIdAndUpdate(req.params.id, req.body, {new: true});
        if (!applet) {
            throw {statusCode: 404, message: "Applet not found"};
        }
        return applet;
    }catch (e) {
        throw {statusCode: 500, message: "Unable to update applet"};
    }
}

async function deleteAppletById(req: FastifyRequest<{ Params: { id: string } }>, reply: FastifyReply) {
    try {
        const applet = await Applet.findByIdAndDelete(req.params.id);
        if (!applet) {
            throw {statusCode: 404, message: "Applet not found"};
        }
        return applet;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to delete applet"};
    }
}

async function execute(req: FastifyRequest<{
    Params: { id: string }
}>, reply: FastifyReply) {
    try {
        const applet = await Applet.findById(req.params.id);
        if (!applet) {
            throw {statusCode: 404, message: "Applet not found"};
        }
        const appletInDb = await executeApplet(applet);
        return appletInDb;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to execute applet"};
    }
}

async function stop(req: FastifyRequest<{
    Params: { id: string }
}>, reply: FastifyReply) {
    try {
        const applet = await Applet.findById(req.params.id);
        if (!applet) {
            throw {statusCode: 404, message: "Applet not found"};
        }
        const appletInDb = await stopApplet(applet);
        return appletInDb;
    } catch (e) {
        throw {statusCode: 500, message: "Unable to stop applet"};
    }
}

export { getAppletsFunctions, createApplet,
    getAllApplets, getAppletById, updateAppletById, deleteAppletById, execute, stop };
