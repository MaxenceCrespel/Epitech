import _ from 'lodash';
import { IApplet } from '../../../../models/AppletSchema';
import Action, { IAction } from '../../../../models/ActionsSchema';

async function onChange(applet: IApplet, appletActions: Array<any>, actionsResponse: Array<any>): Promise<boolean> {
    let changed: boolean = false;
    if (appletActions[0].lastData) {
        changed = !_.isEqual(appletActions[0].lastData, actionsResponse[0]);
        if (changed) {
            appletActions[0].lastData = actionsResponse[0];
            await Action.updateOne({ _id: appletActions[0]._id }, { $set: { lastData: actionsResponse[0] } });
            console.log( applet.id + " changed");
        } else {
            console.log( applet.id + " not changed");
        }
    } else {
        appletActions[0].lastData = actionsResponse[0];
        await Action.updateOne({ _id: appletActions[0]._id }, { $set: { lastData: actionsResponse[0] } });
        console.log("First time");
        changed = false;
    }
    return changed;
}

export default onChange;