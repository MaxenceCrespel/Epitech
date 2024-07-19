"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.list = void 0;
const teams_1 = __importDefault(require("./teams"));
const schema_json_1 = __importDefault(require("./teams/schema.json"));
const discord_1 = __importDefault(require("./discord"));
const schema_json_2 = __importDefault(require("./discord/schema.json"));
const slack_1 = __importDefault(require("./slack"));
const schema_json_3 = __importDefault(require("./slack/schema.json"));
exports.default = {
    [schema_json_1.default.name]: teams_1.default,
    [schema_json_2.default.name]: discord_1.default,
    [schema_json_3.default.name]: slack_1.default,
};
const list = [
    schema_json_1.default,
    schema_json_2.default,
    schema_json_3.default,
];
exports.list = list;
