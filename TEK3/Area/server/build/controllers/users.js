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
exports.getCurrentUser = exports.getUser = exports.deleteUser = exports.updateUser = exports.getAllUsers = exports.createUser = void 0;
const UserSchema_1 = __importDefault(require("../models/UserSchema"));
const bcryptjs_1 = __importDefault(require("bcryptjs"));
function createUser(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        const user = new UserSchema_1.default({
            username: req.body.username,
            name: req.body.name,
            firstname: req.body.firstname,
            email: req.body.email,
            password: bcryptjs_1.default.hashSync(req.body.password, 16)
        });
        try {
            yield user.save();
            return res.send({ message: 'User created successfully' });
        }
        catch (err) {
            return res.status(400).send({ error: 'Email is taken' });
        }
    });
}
exports.createUser = createUser;
function getAllUsers(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const users = yield UserSchema_1.default.find({}, { password: 0, __v: 0, email: 0 });
            return res.status(200).send(users);
        }
        catch (err) {
            return res.status(400).send({ error: 'Something went wrong', data: err });
        }
    });
}
exports.getAllUsers = getAllUsers;
;
function updateUser(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const user = yield UserSchema_1.default.findByIdAndUpdate(req.params.id, req.body, { new: true });
            return res.status(200).send(user);
        }
        catch (err) {
            return res.status(400).send({ error: 'Something went wrong', data: err });
        }
    });
}
exports.updateUser = updateUser;
function deleteUser(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const user = yield UserSchema_1.default.findByIdAndDelete(req.params.id);
            return res.status(200).send(user);
        }
        catch (err) {
            return res.status(400).send({ error: 'Something went wrong', data: err });
        }
    });
}
exports.deleteUser = deleteUser;
function getUser(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const user = yield UserSchema_1.default.find({ _id: req.params.id }, { password: 0, __v: 0, email: 0 });
            return res.status(200).send(user[0]);
        }
        catch (err) {
            return res.status(400).send({ error: 'Something went wrong', data: err });
        }
    });
}
exports.getUser = getUser;
function getCurrentUser(req, res) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const user = yield UserSchema_1.default.findById(req.user.id, { password: 0, __v: 0 });
            return res.status(200).send(user);
        }
        catch (err) {
            return res.status(400).send({ error: 'Something went wrong', data: err });
        }
    });
}
exports.getCurrentUser = getCurrentUser;
