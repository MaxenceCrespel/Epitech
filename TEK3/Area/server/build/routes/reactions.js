"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const reactions_1 = require("../controllers/reactions");
const auth_1 = require("../middlewares/auth");
const havePermission_1 = require("../middlewares/havePermission");
module.exports = function (fastify, opts, done) {
    fastify.get('/functions', {
        preHandler: auth_1.auth,
        schema: {
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'object',
                    properties: {
                        reactions: { type: 'array' },
                    },
                },
            },
            description: 'Get available reactions',
            tags: ['reactions'],
        },
    }, reactions_1.getAvailableReaction);
    fastify.get('/', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canSeeAllReactions],
        schema: {
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'array',
                },
            },
            description: 'Get all reactions',
            tags: ['reactions'],
        },
    }, reactions_1.getAllReactions);
    fastify.get('/:id', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canSeeReaction],
        schema: {
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'object',
                },
            },
            description: 'Get reaction by id',
            tags: ['reactions'],
        },
    }, reactions_1.getReactionById);
    fastify.post('/', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canCreateReaction],
        schema: {
            security: [{ Bearer: [] }],
            body: {
                type: 'object',
                properties: {
                    name: { type: 'string' },
                    serviceName: { type: 'string' },
                    description: { type: 'string' },
                    params: { type: 'array' },
                    applet: { type: 'string' },
                    user: { type: 'string' },
                },
            },
            description: 'Create a reaction',
            tags: ['reactions'],
        },
    }, reactions_1.createReaction);
    fastify.put('/:id', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canUpdateReaction],
        schema: {
            security: [{ Bearer: [] }],
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            body: {
                type: 'object',
                properties: {
                    name: { type: 'string' },
                    serviceName: { type: 'string' },
                    description: { type: 'string' },
                    params: { type: 'array' },
                    applet: { type: 'string' },
                    user: { type: 'string' },
                },
            },
            response: {
                200: {
                    type: 'object',
                },
            },
            description: 'Update a reaction',
            tags: ['reactions'],
        },
    }, reactions_1.updateReactionById);
    fastify.delete('/:id', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canDeleteReaction],
        schema: {
            security: [{ Bearer: [] }],
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            response: {
                200: {
                    type: 'object',
                },
            },
            description: 'Delete a reaction',
            tags: ['reactions'],
        },
    }, reactions_1.deleteReactionById);
    done();
};
