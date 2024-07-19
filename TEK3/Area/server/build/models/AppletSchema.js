"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AppletSchema = void 0;
const mongoose_1 = __importStar(require("mongoose"));
exports.AppletSchema = new mongoose_1.Schema({
    name: { type: String, required: true },
    description: { type: String, required: true },
    actions: { type: (Array), required: true },
    frequency: { type: String, required: true },
    functionName: { type: String, required: true },
    reactions: { type: (Array), required: true },
    user: { type: mongoose_1.Schema.Types.ObjectId, ref: 'User', required: true },
    active: { type: Boolean, required: true, default: false },
    created_at: { type: Date, default: Date.now },
});
exports.default = mongoose_1.default.model('Applet', exports.AppletSchema);
