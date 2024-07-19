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
const lodash_1 = __importDefault(require("lodash"));
const ActionsSchema_1 = __importDefault(require("../../../../models/ActionsSchema"));
function onChange(applet, appletActions, actionsResponse) {
    return __awaiter(this, void 0, void 0, function* () {
        let changed = false;
        if (appletActions[0].lastData) {
            changed = !lodash_1.default.isEqual(appletActions[0].lastData, actionsResponse[0]);
            if (changed) {
                appletActions[0].lastData = actionsResponse[0];
                yield ActionsSchema_1.default.updateOne({ _id: appletActions[0]._id }, { $set: { lastData: actionsResponse[0] } });
                console.log(applet.id + " changed");
            }
            else {
                console.log(applet.id + " not changed");
            }
        }
        else {
            appletActions[0].lastData = actionsResponse[0];
            yield ActionsSchema_1.default.updateOne({ _id: appletActions[0]._id }, { $set: { lastData: actionsResponse[0] } });
            console.log("First time");
            changed = false;
        }
        return changed;
    });
}
exports.default = onChange;
