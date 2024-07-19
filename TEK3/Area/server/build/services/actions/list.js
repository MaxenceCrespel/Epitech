"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.list = void 0;
const newCommit_1 = __importDefault(require("./github/newCommit"));
const schema_json_1 = __importDefault(require("./github/newCommit/schema.json"));
const newIssue_1 = __importDefault(require("./github/newIssue"));
const schema_json_2 = __importDefault(require("./github/newIssue/schema.json"));
const current_1 = __importDefault(require("./weather/current"));
const schema_json_3 = __importDefault(require("./weather/current/schema.json"));
exports.default = {
    [schema_json_1.default.name]: newCommit_1.default,
    [schema_json_2.default.name]: newIssue_1.default,
    [schema_json_3.default.name]: current_1.default,
};
const list = [
    schema_json_1.default,
    schema_json_2.default,
    schema_json_3.default,
];
exports.list = list;
