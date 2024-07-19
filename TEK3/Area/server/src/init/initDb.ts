import db from "../utils/db";
import User, { IUser } from "../models/UserSchema";
import Permissions, { IPerm } from "../models/PermissionsSchema";
import PermissionsList from "../utils/permissionsList";
import dotenv from "dotenv";
import bcrypt from "bcryptjs";
dotenv.config({ path: "../../.env"});

db.connect();

const password = process.env.DEFAULT_USER_PASSWORD;

if (!password) {
    console.error("DEFAULT_USER_PASSWORD is not defined in .env file.");
    process.exit(1);
}

createTestUser();
createPermissions();
createAdminUser();

async function createTestUser() {
    const user = {
        username: "test",
        password: bcrypt.hashSync((password || ''), 16),
        email: "test@gmail.com",
        firstname: "test",
        name: "test",
    };
    User.findOneAndDelete({ username: user.username }).then(() => {
        const newUser: IUser = new User(user);
        newUser.save().then(() => {
            console.log("Test user created.");
        });
    });
}


async function createPermissions() {
    const permissions = {
        permissionsList: PermissionsList,
    };
    Permissions.findOneAndDelete({}).then(() => {
        const newPermissions: IPerm = new Permissions(permissions);
        newPermissions.save().then(() => {
            console.log("Permissions created.");
        });
    });
}

async function createAdminUser() {
    const user = {
        username: "admin",
        password: bcrypt.hashSync((password || ''), 16),
        email: "admin@gmail.com",
        firstname: "admin",
        name: "admin",
        permissions: PermissionsList.ADMIN,
    };
    User.findOneAndDelete({ username: user.username }).then(() => {
        const newUser: IUser = new User(user);
        newUser.save().then(() => {
            console.log("Admin user created.");
        });
    });
}