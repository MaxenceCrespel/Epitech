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
exports.canDeleteReaction = exports.canUpdateReaction = exports.canSeeReaction = exports.canSeeAllReactions = exports.canCreateReaction = exports.canDeleteApplet = exports.canSeeApplet = exports.canUpdateApplet = exports.canCreateApplet = exports.canSeeAllApplets = exports.canCreateAction = exports.canDeleteAction = exports.canUpdateAction = exports.canSeeAction = exports.canSeeAllActions = exports.canDeleteUser = exports.canUpdateUser = exports.canSeeAllUsers = void 0;
const permissionsList_1 = __importDefault(require("../utils/permissionsList"));
const permissionsFunctions_1 = require("../utils/permissionsFunctions");
const ActionsSchema_1 = __importDefault(require("../models/ActionsSchema"));
const ReactionsSchema_1 = __importDefault(require("../models/ReactionsSchema"));
const AppletSchema_1 = __importDefault(require("../models/AppletSchema"));
function canSeeAllUsers(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.USER.READ)) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canSeeAllUsers = canSeeAllUsers;
function canUpdateUser(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.USER.UPDATE)
            || request.user._id == request.params.id) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canUpdateUser = canUpdateUser;
function canDeleteUser(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.USER.DELETE) ||
            request.user._id == request.params.id) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canDeleteUser = canDeleteUser;
// Actions permissions
function canSeeAllActions(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ACTIONS.READ)) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canSeeAllActions = canSeeAllActions;
function canUpdateAction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ACTIONS.UPDATE) ||
            request.user._id == request.body.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canUpdateAction = canUpdateAction;
function canDeleteAction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        const action = yield ActionsSchema_1.default.findById(request.params.id);
        if (!action) {
            reply.status(404).send({ message: 'Action not found' });
            return;
        }
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ACTIONS.DELETE) ||
            request.user._id == action.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canDeleteAction = canDeleteAction;
function canCreateAction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ACTIONS.CREATE) ||
            request.user._id == request.body.user) {
        }
        else {
            return reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
        }
    });
}
exports.canCreateAction = canCreateAction;
function canSeeAction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const action = yield ActionsSchema_1.default.findById(request.params.id);
        if (!action) {
            throw { statusCode: 404, message: 'Action not found' };
        }
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ACTIONS.READ) ||
            request.user._id == action.user) {
        }
        else {
            throw { statusCode: 403, message: 'Forbidden access, this will be reported.' };
        }
    });
}
exports.canSeeAction = canSeeAction;
// Applets permissions
function canSeeAllApplets(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.APPLET.READ)) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canSeeAllApplets = canSeeAllApplets;
function canCreateApplet(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.APPLET.CREATE)) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canCreateApplet = canCreateApplet;
function canUpdateApplet(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        const applet = yield AppletSchema_1.default.findById(request.params.id);
        if (!applet) {
            reply.status(404).send({ message: 'Applet not found' });
            return;
        }
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.APPLET.UPDATE)
            || request.user._id == applet.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canUpdateApplet = canUpdateApplet;
function canDeleteApplet(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        const applet = yield AppletSchema_1.default.findById(request.params.id);
        if (!applet) {
            reply.status(404).send({ message: 'Applet not found' });
            return;
        }
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.APPLET.DELETE)
            || request.user._id == applet.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canDeleteApplet = canDeleteApplet;
function canSeeApplet(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        const applet = yield AppletSchema_1.default.findById(request.params.id);
        if (!applet) {
            reply.status(404).send({ message: 'Applet not found (middleware)' });
            return;
        }
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.APPLET.READ) ||
            request.user._id == applet.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canSeeApplet = canSeeApplet;
// Reactions permissions
function canCreateReaction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if (!(0, permissionsFunctions_1.hasAnyPermission)(userPerms, [permissionsList_1.default.ADMIN, permissionsList_1.default.REACTIONS.CREATE])
            && request.user._id != request.body.user) {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canCreateReaction = canCreateReaction;
function canSeeAllReactions(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        if (!(0, permissionsFunctions_1.hasAnyPermission)(userPerms, [permissionsList_1.default.ADMIN, permissionsList_1.default.REACTIONS.READ])) {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canSeeAllReactions = canSeeAllReactions;
function canSeeReaction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const reaction = yield ReactionsSchema_1.default.findById(request.params.id);
        if (!reaction) {
            throw { statusCode: 404, message: 'Reaction not found' };
        }
        const userPerms = request.user.permissions;
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.REACTIONS.READ) ||
            request.user._id == reaction.user) {
        }
        else {
            throw { statusCode: 403, message: 'Forbidden access, this will be reported.' };
        }
    });
}
exports.canSeeReaction = canSeeReaction;
function canUpdateReaction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        const reaction = yield ReactionsSchema_1.default.findById(request.params.id);
        if (!reaction) {
            reply.status(404).send({ message: 'Reaction not found' });
            return;
        }
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.REACTIONS.UPDATE) ||
            request.user._id == reaction.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canUpdateReaction = canUpdateReaction;
function canDeleteReaction(request, reply, done) {
    return __awaiter(this, void 0, void 0, function* () {
        const userPerms = request.user.permissions;
        const reaction = yield ReactionsSchema_1.default.findById(request.params.id);
        if (!reaction) {
            reply.status(404).send({ message: 'Reaction not found' });
            return;
        }
        if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.ADMIN)) {
        }
        else if ((0, permissionsFunctions_1.hasPermission)(userPerms, permissionsList_1.default.REACTIONS.DELETE) ||
            request.user._id == reaction.user) {
        }
        else {
            reply.status(403).send({ message: 'Forbidden access, this will be reported.' });
            return;
        }
    });
}
exports.canDeleteReaction = canDeleteReaction;
