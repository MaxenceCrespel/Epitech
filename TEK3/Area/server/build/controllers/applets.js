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
exports.stop = exports.execute = exports.deleteAppletById = exports.updateAppletById = exports.getAppletById = exports.getAllApplets = exports.createApplet = exports.getAppletsFunctions = void 0;
const list_1 = require("../services/applets/functions/list");
const AppletSchema_1 = __importDefault(require("../models/AppletSchema"));
const executeApplet_1 = __importStar(require("../services/applets/executeApplet"));
function getAppletsFunctions(req, reply) {
    return reply.send({ applets: list_1.list });
}
exports.getAppletsFunctions = getAppletsFunctions;
function createApplet(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const appletBody = req.body;
            const newApplet = new AppletSchema_1.default(appletBody);
            const savedApplet = yield newApplet.save();
            return savedApplet;
        }
        catch (e) {
            console.log(e);
            throw { statusCode: 500, message: "Something went wrong" };
        }
    });
}
exports.createApplet = createApplet;
function getAllApplets(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const applets = yield AppletSchema_1.default.find();
            return applets;
        }
        catch (e) {
            console.log(e);
            throw { statusCode: 500, message: "Unable to get applets" };
        }
    });
}
exports.getAllApplets = getAllApplets;
function getAppletById(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const applet = yield AppletSchema_1.default.findById(req.params.id);
            if (!applet) {
                throw { statusCode: 404, message: "Applet not found" };
            }
            return applet;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to get applet" };
        }
    });
}
exports.getAppletById = getAppletById;
function updateAppletById(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const applet = yield AppletSchema_1.default.findByIdAndUpdate(req.params.id, req.body, { new: true });
            if (!applet) {
                throw { statusCode: 404, message: "Applet not found" };
            }
            return applet;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to update applet" };
        }
    });
}
exports.updateAppletById = updateAppletById;
function deleteAppletById(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const applet = yield AppletSchema_1.default.findByIdAndDelete(req.params.id);
            if (!applet) {
                throw { statusCode: 404, message: "Applet not found" };
            }
            return applet;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to delete applet" };
        }
    });
}
exports.deleteAppletById = deleteAppletById;
function execute(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const applet = yield AppletSchema_1.default.findById(req.params.id);
            if (!applet) {
                throw { statusCode: 404, message: "Applet not found" };
            }
            const appletInDb = yield (0, executeApplet_1.default)(applet);
            return appletInDb;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to execute applet" };
        }
    });
}
exports.execute = execute;
function stop(req, reply) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const applet = yield AppletSchema_1.default.findById(req.params.id);
            if (!applet) {
                throw { statusCode: 404, message: "Applet not found" };
            }
            const appletInDb = yield (0, executeApplet_1.stopApplet)(applet);
            return appletInDb;
        }
        catch (e) {
            throw { statusCode: 500, message: "Unable to stop applet" };
        }
    });
}
exports.stop = stop;
