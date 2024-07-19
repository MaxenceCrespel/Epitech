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
exports.deleteReactionById = exports.updateReactionById = exports.getReactionById = exports.getAllReactions = exports.createReaction = exports.getAvailableReaction = void 0;
const ReactionsSchema_1 = __importDefault(require("../models/ReactionsSchema"));
const list_1 = require("../services/reactions/list");
function getAvailableReaction(req, res) {
    res.status(200).send({ reactions: list_1.list });
}
exports.getAvailableReaction = getAvailableReaction;
function createReaction(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const reactionBody = req.body;
            const newReaction = new ReactionsSchema_1.default(reactionBody);
            const savedReaction = yield newReaction.save();
            if (savedReaction && savedReaction._id) {
                return savedReaction;
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
exports.createReaction = createReaction;
function getAllReactions(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const reactions = yield ReactionsSchema_1.default.find();
            return reactions;
        }
        catch (e) {
            console.log(e);
            throw { statusCode: 500, message: "Unable to get reactions" };
        }
    });
}
exports.getAllReactions = getAllReactions;
function getReactionById(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const reaction = yield ReactionsSchema_1.default.findById(req.params.id);
            if (!reaction) {
                throw { statusCode: 404, message: "Reaction not found" };
            }
            return reaction;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to get reaction" };
        }
    });
}
exports.getReactionById = getReactionById;
function updateReactionById(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const reaction = yield ReactionsSchema_1.default.findByIdAndUpdate(req.params.id, req.body, { new: true });
            if (!reaction) {
                throw { statusCode: 404, message: "Reaction not found" };
            }
            return reaction;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to update reaction" };
        }
    });
}
exports.updateReactionById = updateReactionById;
function deleteReactionById(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const reaction = yield ReactionsSchema_1.default.findByIdAndDelete(req.params.id);
            if (!reaction) {
                throw { statusCode: 404, message: "Reaction not found" };
            }
            return reaction;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to delete reaction" };
        }
    });
}
exports.deleteReactionById = deleteReactionById;
