"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const users_1 = require("../controllers/users");
const users_2 = require("../middlewares/users");
const auth_1 = require("../middlewares/auth");
const havePermission_1 = require("../middlewares/havePermission");
module.exports = function (fastify, opts, done) {
    fastify.get('/', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canSeeAllUsers],
        schema: {
            response: {
                200: {
                    type: 'array',
                    properties: {
                        name: { type: 'string' },
                        firstname: { type: 'string' },
                        username: { type: 'string' },
                        email: { type: 'string' },
                        created_at: { type: 'string' },
                        permissions: { type: 'number' },
                    }
                },
            },
            description: 'Users endpoint',
            tags: ['users'],
        },
    }, users_1.getAllUsers);
    fastify.get('/me', {
        preHandler: [auth_1.auth],
        schema: {
            response: {
                200: {
                    type: 'object',
                    properties: {
                        name: { type: 'string' },
                        firstname: { type: 'string' },
                        username: { type: 'string' },
                        email: { type: 'string' },
                        created_at: { type: 'string' },
                        permissions: { type: 'number' },
                        _id: { type: 'string' },
                    }
                }
            },
            description: 'Get current user endpoint',
            tags: ['users'],
        },
    }, users_1.getCurrentUser);
    fastify.get('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canSeeAllUsers],
        schema: {
            params: {
                type: 'object',
                properties: {
                    id: {
                        type: 'string',
                        description: 'user id'
                    },
                },
            },
            response: {
                200: {
                    type: 'object',
                    properties: {
                        name: { type: 'string' },
                        firstname: { type: 'string' },
                        username: { type: 'string' },
                        email: { type: 'string' },
                        created_at: { type: 'string' },
                        permissions: { type: 'number' },
                    }
                },
            },
            description: 'Get user endpoint',
            tags: ['users'],
        },
    }, users_1.getUser);
    fastify.post('/', {
        preHandler: users_2.canCreateUser,
        schema: {
            body: {
                type: 'object',
                properties: {
                    name: {
                        type: 'string',
                        description: 'user name'
                    },
                    email: {
                        type: 'string',
                        description: 'user email'
                    },
                    password: {
                        type: 'string',
                        description: 'user password'
                    },
                    username: {
                        type: 'string',
                        description: 'user username'
                    },
                    firstname: {
                        type: 'string',
                        description: 'user firstname'
                    },
                },
            },
            response: {
                200: {
                    type: 'object',
                    properties: {
                        message: { type: 'string' },
                    },
                },
            },
            description: 'Create user endpoint',
            tags: ['users'],
        },
    }, users_1.createUser);
    fastify.put('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canUpdateUser],
        schema: {
            body: {
                type: 'object',
            },
            params: {
                type: 'object',
                properties: {
                    id: {
                        type: 'string',
                        description: 'user id'
                    },
                },
            },
            response: {
                200: {
                    type: 'object',
                    properties: {
                        name: { type: 'string' },
                        firstname: { type: 'string' },
                        username: { type: 'string' },
                        email: { type: 'string' },
                        created_at: { type: 'string' },
                        permissions: { type: 'number' },
                    }
                },
            },
            description: 'Update user endpoint',
            tags: ['users'],
        }
    }, users_1.updateUser);
    fastify.delete('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canDeleteUser],
        schema: {
            params: {
                type: 'object',
                properties: {
                    id: {
                        type: 'string',
                        description: 'user id'
                    },
                },
            },
            response: {
                200: {
                    type: 'object',
                    properties: {
                        name: { type: 'string' },
                        firstname: { type: 'string' },
                        username: { type: 'string' },
                        email: { type: 'string' },
                        created_at: { type: 'string' },
                        permissions: { type: 'number' },
                    }
                },
            },
            description: 'Delete user endpoint',
            tags: ['users'],
        },
    }, users_1.deleteUser);
    done();
};
