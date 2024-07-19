import { login, reset, googleAuthLink, googleLogin } from "../controllers/auth";
import { auth } from "../middlewares/auth";

module.exports = function (fastify: any, opts: any, done: any) {
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
    }, login
    );
    fastify.put('/refresh', {
        preHandler: auth,
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
    }, reset);
    done();
    // Google OAuth
    fastify.get('/google', {
        schema: {
            description: 'Google OAuth link endpoint',
            tags: ['auth'],
        },
    }, googleAuthLink);
    fastify.get('/google/callback', {
        schema: {
            description: 'Google OAuth callback endpoint',
            tags: ['auth'],
        },
    }, googleLogin);
    done();
}