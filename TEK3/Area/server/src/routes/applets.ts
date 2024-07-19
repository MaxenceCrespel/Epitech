import { getAppletsFunctions, getAllApplets, getAppletById, deleteAppletById, updateAppletById, createApplet,
execute, stop } from "../controllers/applets";
import { auth } from "../middlewares/auth";
import { canCreateApplet, canSeeAllApplets, canDeleteApplet, canSeeApplet, canUpdateApplet } from "../middlewares/havePermission";

module.exports = function (fastify: any, opts: any, done: any) {
    fastify.get('/functions', {
        preHandler: auth,
        schema: {
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'object',
                    properties: {
                        applets: { type: 'array' },
                    },
                },
            },
            description: 'Get available applets functions',
            tags: ['applets'],
        },
    }, getAppletsFunctions);
    fastify.get('/', {
        preHandler: [auth, canSeeAllApplets],
        schema: {
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'array',
                },
            },
            description: 'Get all applets',
            tags: ['applets'],
        },
    }, getAllApplets);
    fastify.get('/:id', {
        preHandler: [auth, canSeeApplet],
        schema: {
            security: [{ Bearer: [] }],
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            response: {
                200: { type: 'object',
                properties: {
                    name: { type: 'string' },
                    description: { type: 'string' },
                    actions: { type: 'array' },
                    reactions: { type: 'array' },
                    functionName: { type: 'string' },
                    _id: { type: 'string' },
                    frequency: { type: 'string' },
                    createdAt: { type: 'string' },
                    user: { type: 'string' },
                },
                },
            },
            description: 'Get applet by id',
            tags: ['applets'],
        },
    }, getAppletById);
    fastify.post('/', {
        preHandler: [auth, canCreateApplet],
        schema: {
            security: [{ Bearer: [] }],
            body: {
                type: 'object',
                properties: {
                    name: { type: 'string' },
                    description: { type: 'string' },
                    actions: { type: 'array' },
                    reactions: { type: 'array' },
                },
            },
            description: 'Create applet',
            tags: ['applets'],
        },
    }, createApplet);
    fastify.put('/:id', {
        preHandler: [auth, canUpdateApplet],
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
                    description: { type: 'string' },
                    actions: { type: 'array' },
                    reactions: { type: 'array' },
                },
            },
            description: 'Update applet',
            tags: ['applets'],
        },
    }, updateAppletById);
    fastify.delete('/:id', {
        preHandler: [auth, canDeleteApplet],
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
            description: 'Delete applet by id',
            tags: ['applets'],
        },
    }, deleteAppletById);

    fastify.post('/:id/execute', {
        preHandler: [auth, canSeeApplet],
        schema: {
            security: [{ Bearer: [] }],
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            description: 'Execute applet',
            tags: ['applets'],
        },
    }, execute);
    fastify.post('/:id/stop', {
        preHandler: [auth, canSeeApplet],
        schema: {
            security: [{ Bearer: [] }],
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            description: 'Stop applet',
            tags: ['applets'],
        },
    }, stop);

    done();
}