"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.log = void 0;
const LogSchema_1 = __importDefault(require("../models/LogSchema"));
function log(level, message, applet, user) {
    try {
        const log = new LogSchema_1.default({
            date: new Date(),
            applet: applet ? applet : null,
            user: user ? user : null,
            level: level,
            message: message,
        });
        log.save();
        console.log(`[${level}] ${message}`);
        return true;
    }
    catch (error) {
        console.log(error);
        return false;
    }
}
exports.log = log;
