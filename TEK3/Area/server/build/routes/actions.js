"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const actions_1 = require("../controllers/actions");
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
                        actions: { type: 'array' },
                    },
                },
            },
            description: 'Get available actions functions',
            tags: ['actions'],
        },
    }, actions_1.getAvailableAction);
    fastify.get('/', {
        preHandler: [auth_1.auth, havePermission_1.canSeeAllActions],
        schema: {
            security: [{ Bearer: [] }],
            response: {
                200: {
                    type: 'array',
                },
            },
            description: 'Get all actions',
            tags: ['actions'],
        },
    }, actions_1.getAllActions);
    fastify.get('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canSeeAction],
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
                    type: 'array',
                },
            },
            description: 'Get action by id',
            tags: ['actions'],
        },
    }, actions_1.getActionById);
    fastify.post('/', {
        onRequest: [auth_1.auth],
        preHandler: [havePermission_1.canCreateAction],
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
            description: 'Create an action',
            tags: ['actions'],
        },
    }, actions_1.createAction);
    fastify.put('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canUpdateAction],
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
            description: 'Update an action',
            tags: ['actions'],
        },
    }, actions_1.updateActionById);
    fastify.delete('/:id', {
        preHandler: [auth_1.auth, havePermission_1.canDeleteAction],
        schema: {
            params: {
                type: 'object',
                properties: {
                    id: { type: 'string' },
                },
            },
            security: [{ Bearer: [] }],
            description: 'Delete an action',
            tags: ['actions'],
        },
    }, actions_1.deleteActionById);
    done();
};
