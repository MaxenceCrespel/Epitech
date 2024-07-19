"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const auth_1 = require("../controllers/auth");
const auth_2 = require("../middlewares/auth");
module.exports = function (fastify, opts, done) {
    fastify.post('/login', {
        schema: {
            body: {
                type: 'object',
                properties: {
                    email: {
                        type: 'string',
                        description: 'user email'
                    },
                    username: {
                        type: 'string',
                        description: 'user username'
                    },
                    password: {
                        type: 'string',
                        description: 'user password'
                    }
                },
            },
            response: {
                200: {
                    type: 'object',
                    properties: {
                        token: { type: 'string' },
                    },
                },
            },
            description: 'Login endpoint',
            tags: ['auth'],
        },
    }, auth_1.login);
    fastify.put('/refresh', {
        preHandler: auth_2.auth,
        schema: {
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'object',
                    properties: {
                        token: { type: 'string' },
                    },
                },
            },
            description: 'Refresh token endpoint',
            tags: ['auth'],
        },
    }, auth_1.reset);
    done();
    // Google OAuth
    fastify.get('/google', {
        schema: {
            description: 'Google OAuth link endpoint',
            tags: ['auth'],
        },
    }, auth_1.googleAuthLink);
    fastify.get('/google/callback', {
        schema: {
            description: 'Google OAuth callback endpoint',
            tags: ['auth'],
        },
    }, auth_1.googleLogin);
    done();
};
