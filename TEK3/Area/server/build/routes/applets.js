"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const applets_1 = require("../controllers/applets");
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
                        applets: { type: 'array' },
                    },
                },
            },
            description: 'Get available applets functions',
            tags: ['applets'],
        },
    }, applets_1.getAppletsFunctions);
    fastify.get('/', {
        preHandler: [auth_1.auth, havePermission_1.canSeeAllApplets],
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
    }, applets_1.getAllApplets);
    fastify.get('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canSeeApplet],
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
    }, applets_1.getAppletById);
    fastify.post('/', {
        preHandler: [auth_1.auth, havePermission_1.canCreateApplet],
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
    }, applets_1.createApplet);
    fastify.put('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canUpdateApplet],
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
    }, applets_1.updateAppletById);
    fastify.delete('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canDeleteApplet],
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
    }, applets_1.deleteAppletById);
    fastify.post('/:id/execute', {
        preHandler: [auth_1.auth, havePermission_1.canSeeApplet],
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
    }, applets_1.execute);
    fastify.post('/:id/stop', {
        preHandler: [auth_1.auth, havePermission_1.canSeeApplet],
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
    }, applets_1.stop);
    done();
};
