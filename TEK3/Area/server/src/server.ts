import fastify from 'fastify';
import cors from '@fastify/cors';

import db from './utils/db';
import agenda from './utils/agenda';
export async function createServer() {

    await db.connect();
    agenda.on('ready', () => {
        console.log('Agenda started');
    }
    );
    agenda.on('start', (job: any) => {
        console.log(`Job ${job.attrs.name} started`);
    });
    agenda.on('complete', (job: any) => {
        console.log(`Job ${job.attrs.name} finished`);
    });
    agenda.on('cancel', (job: any) => {
        console.log(`Job ${job.attrs.name} cancelled`);
    });
    agenda.on('fail', (err: Error, job: any) => {
        console.log(`Job ${job.attrs.name} failed with error: ${err.message}`);
    });

    const server = fastify({
        logger: true,
    });
    server.register(cors, {
        origin: '*',
        methods: ['GET', 'PUT', 'POST', 'DELETE', 'OPTIONS'],
        allowedHeaders: ['Content-Type', 'Authorization'],
    });
    // server.register(require('@fastify/middie'))
    server.register(require('@fastify/swagger'), {
        routePrefix: '/docs',
        swagger: {
            info: {
            title: 'Area API',
            description: 'Documentation of the Area API',
            version: '1.0.0',
            },
            securityDefinitions: {
                Bearer: {
                    type: 'apiKey',
                    name: 'Authorization',
                    in: 'header'
                }
            },
            security: [{ Bearer: [] }],
        },
        exposeRoute: true,
        });

    server.register(require('./routes/'), { prefix: '/v1' });
    server.get('/about.json', async (request, reply) => {
        try {
          // Lire le contenu du fichier about.json et le renvoyer en réponse
          const aboutJson = require('../about.json'); // Assurez-vous que le chemin du fichier est correct
          reply.send(aboutJson);
        } catch (error) {
          reply.status(500).send({ error: 'Internal Server Error' });
        }
      });
    await agenda.start();
    return server;
}
