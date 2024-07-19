
module.exports = function (fastify:any, opts:any, done:any) {
    fastify.register(require('./users'), { prefix: '/users' });
    fastify.register(require('./auth'), { prefix: '/auth' });
    fastify.register(require('./actions'), { prefix: '/actions' });
    fastify.register(require('./reactions'), { prefix: '/reactions' });
    fastify.register(require('./applets'), { prefix: '/applets' });
    fastify.get('/ping', {
        schema: {
            response: {
                200: {
                    type: 'object',
                    properties: {
                        message: { type: 'string' },
                    },
                },
            },
            description: 'Ping the API',
            tags: ['utils'],
        },
    },
        async (request:any, reply:any) => {
        return { message: 'API is working' };
    });
    done();
}