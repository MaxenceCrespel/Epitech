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
exports.stopApplet = void 0;
const agenda_1 = __importDefault(require("../../utils/agenda"));
const list_1 = __importDefault(require("../actions/list"));
const list_2 = __importDefault(require("../reactions/list"));
const list_3 = __importDefault(require("./functions/list"));
const AppletSchema_1 = __importDefault(require("../../models/AppletSchema"));
const ReactionsSchema_1 = __importDefault(require("../../models/ReactionsSchema"));
const ActionsSchema_1 = __importDefault(require("../../models/ActionsSchema"));
function stopApplet(applet) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            agenda_1.default.cancel({ name: applet.functionName + " " + applet._id });
            const updatedApplet = yield AppletSchema_1.default.findByIdAndUpdate(applet._id, { active: false }, { new: true });
            return updatedApplet;
        }
        catch (e) {
            console.log(e);
        }
    });
}
exports.stopApplet = stopApplet;
function executeApplet(applet) {
    return __awaiter(this, void 0, void 0, function* () {
        console.log(applet);
        let appletActions = [];
        let appletReactions = [];
        let name = applet.functionName + " " + applet._id;
        try {
            agenda_1.default.cancel({ name: name });
            agenda_1.default.define(name, (job) => __awaiter(this, void 0, void 0, function* () {
                appletActions = yield ActionsSchema_1.default.find({ _id: { $in: applet.actions } });
                appletReactions = yield ReactionsSchema_1.default.find({ _id: { $in: applet.reactions } });
                if (!appletActions || !appletReactions) {
                    throw { statusCode: 404, message: "Applet not found" };
                }
                let actionsResponse = [];
                let reactionsResponse = [];
                actionsResponse = yield executeActionsFunction(applet, appletActions);
                console.log(actionsResponse);
                const functionToExecute = yield list_3.default[applet.functionName](applet, appletActions, actionsResponse);
                console.log(functionToExecute);
                if (functionToExecute) {
                    reactionsResponse = yield executeReactionsFunction(applet, appletReactions, actionsResponse);
                }
                else {
                    reactionsResponse = [];
                }
                return reactionsResponse;
            }));
            yield agenda_1.default.every(applet.frequency, name);
            const updatedApplet = yield AppletSchema_1.default.findByIdAndUpdate(applet._id, { active: true }, { new: true });
            return updatedApplet;
        }
        catch (e) {
            console.log(e);
        }
    });
}
function executeActionsFunction(applet, appletActions) {
    return __awaiter(this, void 0, void 0, function* () {
        let actionsResponse = [];
        for (const action of appletActions) {
            const actionFunction = list_1.default[action.serviceName];
            if (!actionFunction) {
                throw { statusCode: 404, message: "Action not found" };
            }
            const actionResponse = yield actionFunction(action.params[0]);
            if (!actionResponse) {
                throw { statusCode: 500, message: "Something went wrong (Action)" };
            }
            actionsResponse.push(actionResponse);
        }
        return actionsResponse;
    });
}
function executeReactionsFunction(applet, appletReactions, actionsResponse) {
    return __awaiter(this, void 0, void 0, function* () {
        let reactionsResponse = [];
        for (const reaction of appletReactions) {
            const reactionFunction = list_2.default[reaction.serviceName];
            if (!reactionFunction) {
                throw { statusCode: 404, message: "Reaction not found" };
            }
            const reactionResponse = yield reactionFunction(reaction.params[0], actionsResponse[0]);
            if (!reactionResponse) {
                throw { statusCode: 500, message: "Something went wrong (Reaction)" };
            }
            reactionsResponse.push(reactionResponse);
        }
        return reactionsResponse;
    });
}
exports.default = executeApplet;
