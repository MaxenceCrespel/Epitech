import { getAvailableAction, createAction,getAllActions, getActionById, deleteActionById, updateActionById } from "../controllers/actions";
import { auth } from "../middlewares/auth";
import { canCreateAction, canSeeAllActions, canSeeAction, canUpdateAction, canDeleteAction} from "../middlewares/havePermission";

module.exports = function (fastify: any, opts: any, done: any) {
    fastify.get('/functions', {
        preHandler: auth,
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
    }, getAvailableAction);
    fastify.get('/', {
        preHandler: [auth, canSeeAllActions],
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
    }, getAllActions);
    fastify.get('/:id', {
        preHandler: [auth, canSeeAction],
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
    }, getActionById);
    fastify.post('/', {
        onRequest: [auth],
        preHandler: [canCreateAction],
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
    }, createAction);

    fastify.put('/:id', {
        preHandler: [auth, canUpdateAction],
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
    }, updateActionById);

    fastify.delete('/:id', {
        preHandler: [auth, canDeleteAction],
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
    }, deleteActionById);
    done();
}