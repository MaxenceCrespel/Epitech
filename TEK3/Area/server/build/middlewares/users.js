"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.canCreateUser = void 0;
const canCreateUser = (req, res, next) => {
    const { email, password } = req.body;
    if (!email || !password) {
        res.status(400).send({
            message: 'Missing required fields: email and password',
        });
        return;
    }
    next();
};
exports.canCreateUser = canCreateUser;
