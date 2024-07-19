import { createUser, getAllUsers, deleteUser, updateUser,getUser, getCurrentUser } from "../controllers/users";
import { canCreateUser } from "../middlewares/users";
import { IUser } from "../models/UserSchema";
import { auth } from "../middlewares/auth";
import { canDeleteUser, canSeeAllUsers, canUpdateUser  } from "../middlewares/havePermission";

module.exports = function (fastify:any, opts:any, done:any) {
    fastify.get('/', {
        onRequest: [auth],
        preHandler: [canSeeAllUsers],
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
    }, getAllUsers
    );
    fastify.get('/me', {
        preHandler: [auth],
        schema: {
            response: {
                200 : {
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
    }, getCurrentUser);
    fastify.get('/:id', {
        preHandler: [auth, canSeeAllUsers],
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
        }, getUser);


    fastify.post('/', {
        preHandler: canCreateUser,
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
    }, createUser);

    fastify.put('/:id', {
        preHandler: [auth, canUpdateUser],
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
    }, updateUser);

    fastify.delete('/:id', {
        preHandler: [auth, canDeleteUser],
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
    }, deleteUser);
    done();
}