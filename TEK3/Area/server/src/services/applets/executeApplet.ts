import agenda from "../../utils/agenda";
import ActionsList from "../actions/list";
import ReactionsList from "../reactions/list";
import AppletList from "./functions/list";
import Applet, { IApplet } from "../../models/AppletSchema";
import Reaction, { IReaction } from "../../models/ReactionsSchema";
import Action, { IAction } from "../../models/ActionsSchema";

export async function stopApplet(applet: IApplet) {
    try {
        agenda.cancel({ name: applet.functionName + " " + applet._id });
        const updatedApplet = await Applet.findByIdAndUpdate(applet._id, { active: false }, { new: true });
        return updatedApplet;
    } catch (e) {
        console.log(e);
    }
}

async function executeApplet(applet: IApplet) {
    console.log(applet);
    let appletActions: Array<IAction> = [];
    let appletReactions: Array<IReaction> = [];
    let name = applet.functionName + " " + applet._id;
    try {
        agenda.cancel({ name: name });
        agenda.define(name, async (job: any) => {
            appletActions = await Action.find({ _id: { $in: applet.actions } });
            appletReactions = await Reaction.find({ _id: { $in: applet.reactions } });

            if (!appletActions || !appletReactions) {
                throw { statusCode: 404, message: "Applet not found" };
            }
            let actionsResponse: Array<any> = [];
            let reactionsResponse: Array<any> = [];
            actionsResponse = await executeActionsFunction(applet, appletActions);
            console.log(actionsResponse);
            const functionToExecute = await AppletList[applet.functionName](applet, appletActions, actionsResponse);
            console.log(functionToExecute);
            if (functionToExecute) {
                reactionsResponse = await executeReactionsFunction(applet, appletReactions, actionsResponse);
            } else {
                reactionsResponse = [];
            }
            return reactionsResponse;
        });
        await agenda.every(applet.frequency, name);
        const updatedApplet = await Applet.findByIdAndUpdate(applet._id, { active: true }, { new: true });
        return updatedApplet;
    } catch (e) {
        console.log(e);
    }
}

async function executeActionsFunction(applet: IApplet, appletActions: Array<IAction>) {
    let actionsResponse: Array<any> = [];
    for (const action of appletActions) {
        const actionFunction = ActionsList[action.serviceName];
        if (!actionFunction) {
            throw { statusCode: 404, message: "Action not found" };
        }
        const actionResponse = await actionFunction(action.params[0]);
        if (!actionResponse) {
            throw { statusCode: 500, message: "Something went wrong (Action)" };
        }
        actionsResponse.push(actionResponse);
    }
    return actionsResponse;
}

async function executeReactionsFunction(applet: IApplet, appletReactions: Array<IReaction>, actionsResponse: Array<any>) {
    let reactionsResponse: Array<any> = [];
    for (const reaction of appletReactions) {
        const reactionFunction = ReactionsList[reaction.serviceName];
        if (!reactionFunction) {
            throw { statusCode: 404, message: "Reaction not found" };
        }
        const reactionResponse = await reactionFunction(reaction.params[0], actionsResponse[0]);
        if (!reactionResponse) {
            throw { statusCode: 500, message: "Something went wrong (Reaction)" };
        }
        reactionsResponse.push(reactionResponse);
    }
    return reactionsResponse;
}

export default executeApplet;