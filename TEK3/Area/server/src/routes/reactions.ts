import { getAvailableReaction, createReaction, getAllReactions, getReactionById, updateReactionById, deleteReactionById} from "../controllers/reactions";
import { auth } from "../middlewares/auth";

import { canCreateReaction, canSeeAllReactions, canSeeReaction, canUpdateReaction, canDeleteReaction } from "../middlewares/havePermission";

module.exports = function (fastify: any, opts: any, done: any) {
    fastify.get('/functions', {
        preHandler: auth,
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
    }, getAvailableReaction);
    fastify.get('/', {
        onRequest: [auth],
        preHandler: [canSeeAllReactions],
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
    }, getAllReactions);
    fastify.get('/:id', {
        onRequest: [auth],
        preHandler: [canSeeReaction],
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
    }, getReactionById);
    fastify.post('/', {
        onRequest: [auth],
        preHandler: [canCreateReaction],
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
    }, createReaction);
    fastify.put('/:id', {
        onRequest: [auth],
        preHandler: [canUpdateReaction],
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
    }, updateReactionById);
    fastify.delete('/:id', {
        onRequest: [auth],
        preHandler: [canDeleteReaction],
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
    }, deleteReactionById);
    done();
}
