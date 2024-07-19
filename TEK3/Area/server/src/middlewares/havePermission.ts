import PermissionsList, {IPermissions} from "../utils/permissionsList";
import { hasAllPermissions, hasPermission, hasAnyPermission } from "../utils/permissionsFunctions";
import { FastifyRequest } from "fastify";
import Action, { IAction } from "../models/ActionsSchema";
import { IUser } from "../models/UserSchema";
import Reaction,{ IReaction } from "../models/ReactionsSchema";
import Applet, { IApplet } from "../models/AppletSchema";

async function canSeeAllUsers(request:FastifyRequest, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.USER.READ)) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canUpdateUser(request:FastifyRequest<{
    Params: { id: string };
    Body: IUser;
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.USER.UPDATE)
    || request.user._id == request.params.id) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canDeleteUser(request:FastifyRequest<{
    Params: { id: string };
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.USER.DELETE) ||
    request.user._id == request.params.id) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

// Actions permissions

async function canSeeAllActions(request:any, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.ACTIONS.READ)) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canUpdateAction(request:FastifyRequest<{
    Params: { id: string };
    Body: IAction;
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.ACTIONS.UPDATE) ||
    request.user._id == request.body.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canDeleteAction(request:FastifyRequest<{
    Params: { id: string };
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    const action = await Action.findById(request.params.id);
    if (!action) {
        reply.status(404).send({ message: 'Action not found' });
        return;
    }
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.ACTIONS.DELETE) ||
    request.user._id == action.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canCreateAction(request:FastifyRequest<{
    Body: IAction;
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.ACTIONS.CREATE) ||
    request.user._id == request.body.user) {
    } else {
        return reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
    }
}

async function canSeeAction(request:FastifyRequest<{
    Params: {
        id: string
    }
}>, reply:any, done: any) {
    const action = await Action.findById(request.params.id);
    if (!action) {
        throw {statusCode: 404, message: 'Action not found'};
    }
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.ACTIONS.READ) ||
    request.user._id == action.user) {
    } else {
        throw {statusCode: 403, message: 'Forbidden access, this will be reported.'};
    }
}

// Applets permissions

async function canSeeAllApplets(request:any, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.APPLET.READ)) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canCreateApplet(request:any, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.APPLET.CREATE)) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}


async function canUpdateApplet(request:FastifyRequest<{
    Params: { id: string };
    Body: IApplet;
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    const applet = await Applet.findById(request.params.id);
    if (!applet) {
        reply.status(404).send({ message: 'Applet not found' });
        return;
    }
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.APPLET.UPDATE)
    || request.user._id == applet.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canDeleteApplet(request:FastifyRequest<{
    Params: { id: string };
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    const applet = await Applet.findById(request.params.id);
    if (!applet) {
        reply.status(404).send({ message: 'Applet not found' });
        return;
    }
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.APPLET.DELETE)
    || request.user._id == applet.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canSeeApplet(request:FastifyRequest<{
    Params: {
        id: string
    }
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    const applet = await Applet.findById(request.params.id);
    if (!applet) {
        reply.status(404).send({ message: 'Applet not found (middleware)' });
        return;
    }
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.APPLET.READ) ||
    request.user._id == applet.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

// Reactions permissions

async function canCreateReaction(request:FastifyRequest<{
    Body: IReaction
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (!hasAnyPermission(userPerms, [PermissionsList.ADMIN, PermissionsList.REACTIONS.CREATE])
    && request.user._id != request.body.user) {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canSeeAllReactions(request:any, reply:any, done:any) {
    const userPerms = request.user.permissions;
    if (!hasAnyPermission(userPerms, [PermissionsList.ADMIN, PermissionsList.REACTIONS.READ])) {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canSeeReaction(request:FastifyRequest<{
    Params: {
        id: string
    }
}>, reply:any, done: any) {
    const reaction = await Reaction.findById(request.params.id);
    if (!reaction) {
        throw {statusCode: 404, message: 'Reaction not found'};
    }
    const userPerms = request.user.permissions;
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.REACTIONS.READ) ||
    request.user._id == reaction.user) {
    } else {
        throw {statusCode: 403, message: 'Forbidden access, this will be reported.'};
    }
}

async function canUpdateReaction(request:FastifyRequest<{
    Params: { id: string };
    Body: IReaction;
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    const reaction = await Reaction.findById(request.params.id);
    if (!reaction) {
        reply.status(404).send({ message: 'Reaction not found' });
        return;
    }
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.REACTIONS.UPDATE) ||
    request.user._id == reaction.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

async function canDeleteReaction(request:FastifyRequest<{
    Params: { id: string };
}>, reply:any, done:any) {
    const userPerms = request.user.permissions;
    const reaction = await Reaction.findById(request.params.id);
    if (!reaction) {
        reply.status(404).send({ message: 'Reaction not found' });
        return;
    }
    if (hasPermission(userPerms, PermissionsList.ADMIN)) {
    } else if (hasPermission(userPerms, PermissionsList.REACTIONS.DELETE) ||
    request.user._id == reaction.user) {
    } else {
        reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        return;
    }
}

export {
    canSeeAllUsers,
    canUpdateUser,
    canDeleteUser,
    canSeeAllActions,
    canSeeAction,
    canUpdateAction,
    canDeleteAction,
    canCreateAction,
    canSeeAllApplets,
    canCreateApplet,
    canUpdateApplet,
    canSeeApplet,
    canDeleteApplet,
    canCreateReaction,
    canSeeAllReactions,
    canSeeReaction,
    canUpdateReaction,
    canDeleteReaction,
};