"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const agenda_1 = __importDefault(require("agenda"));
const dotenv_1 = __importDefault(require("dotenv"));
dotenv_1.default.config({
    path: "../.env",
});
const mongoConnectionString = `mongodb://root:${process.env.MONGO_ROOT_PASSWORD}@mongo_db:27017/AreaAgenda?authSource=admin`;
const agenda = new agenda_1.default({
    db: {
        address: mongoConnectionString,
        collection: "jobs",
    },
});
exports.default = agenda;
