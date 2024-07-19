"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.list = void 0;
const onChange_1 = __importDefault(require("./onChange"));
const schema_json_1 = __importDefault(require("./onChange/schema.json"));
exports.default = {
    [schema_json_1.default.name]: onChange_1.default,
};
const list = [
    schema_json_1.default,
];
exports.list = list;
