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
exports.updateActionById = exports.deleteActionById = exports.getActionById = exports.getAllActions = exports.createAction = exports.getAvailableAction = void 0;
const list_1 = require("../services/actions/list");
const ActionsSchema_1 = __importDefault(require("../models/ActionsSchema"));
function getAvailableAction(req, res) {
    return res.status(200).send({ actions: list_1.list });
}
exports.getAvailableAction = getAvailableAction;
function createAction(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const actionBody = req.body;
            const newAction = new ActionsSchema_1.default(actionBody);
            const savedAction = yield newAction.save();
            if (savedAction && savedAction._id) {
                return { action: savedAction };
            }
            else {
                throw { statusCode: 500, message: "Something went wrong" };
            }
        }
        catch (e) {
            console.log(e);
            throw { statusCode: 500, message: "Something went wrong" };
        }
    });
}
exports.createAction = createAction;
function getAllActions(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const actions = yield ActionsSchema_1.default.find();
            return actions;
        }
        catch (e) {
            console.log(e);
            throw { statusCode: 500, message: "Unable to get actions" };
        }
    });
}
exports.getAllActions = getAllActions;
function getActionById(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const action = yield ActionsSchema_1.default.findById(req.params.id);
            if (!action) {
                throw { statusCode: 404, message: "Action not found" };
            }
            return action;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to get action" };
        }
    });
}
exports.getActionById = getActionById;
function updateActionById(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const action = yield ActionsSchema_1.default.findByIdAndUpdate(req.params.id, req.body, { new: true });
            if (!action) {
                throw { statusCode: 404, message: "Action not found" };
            }
            return action;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to update action" };
        }
    });
}
exports.updateActionById = updateActionById;
function deleteActionById(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const action = yield ActionsSchema_1.default.findByIdAndDelete(req.params.id);
            if (!action) {
                throw { statusCode: 404, message: "Action not found" };
            }
            return action;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to delete action" };
        }
    });
}
exports.deleteActionById = deleteActionById;
