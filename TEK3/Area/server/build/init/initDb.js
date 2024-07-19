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
const db_1 = __importDefault(require("../utils/db"));
const UserSchema_1 = __importDefault(require("../models/UserSchema"));
const PermissionsSchema_1 = __importDefault(require("../models/PermissionsSchema"));
const permissionsList_1 = __importDefault(require("../utils/permissionsList"));
const dotenv_1 = __importDefault(require("dotenv"));
const bcryptjs_1 = __importDefault(require("bcryptjs"));
dotenv_1.default.config({ path: "../../.env" });
db_1.default.connect();
const password = process.env.DEFAULT_USER_PASSWORD;
if (!password) {
    console.error("DEFAULT_USER_PASSWORD is not defined in .env file.");
    process.exit(1);
}
createTestUser();
createPermissions();
createAdminUser();
function createTestUser() {
    return __awaiter(this, void 0, void 0, function* () {
        const user = {
            username: "test",
            password: bcryptjs_1.default.hashSync((password || ''), 16),
            email: "test@gmail.com",
            firstname: "test",
            name: "test",
        };
        UserSchema_1.default.findOneAndDelete({ username: user.username }).then(() => {
            const newUser = new UserSchema_1.default(user);
            newUser.save().then(() => {
                console.log("Test user created.");
            });
        });
    });
}
function createPermissions() {
    return __awaiter(this, void 0, void 0, function* () {
        const permissions = {
            permissionsList: permissionsList_1.default,
        };
        PermissionsSchema_1.default.findOneAndDelete({}).then(() => {
            const newPermissions = new PermissionsSchema_1.default(permissions);
            newPermissions.save().then(() => {
                console.log("Permissions created.");
            });
        });
    });
}
function createAdminUser() {
    return __awaiter(this, void 0, void 0, function* () {
        const user = {
            username: "admin",
            password: bcryptjs_1.default.hashSync((password || ''), 16),
            email: "admin@gmail.com",
            firstname: "admin",
            name: "admin",
            permissions: permissionsList_1.default.ADMIN,
        };
        UserSchema_1.default.findOneAndDelete({ username: user.username }).then(() => {
            const newUser = new UserSchema_1.default(user);
            newUser.save().then(() => {
                console.log("Admin user created.");
            });
        });
    });
}
