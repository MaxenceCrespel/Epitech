"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
module.exports = function (fastify, opts, done) {
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
    }, (request, reply) => __awaiter(this, void 0, void 0, function* () {
        return { message: 'API is working' };
    }));
    done();
};
