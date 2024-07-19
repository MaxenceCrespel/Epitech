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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.createServer = void 0;
const fastify_1 = __importDefault(require("fastify"));
const cors_1 = __importDefault(require("@fastify/cors"));
const db_1 = __importDefault(require("./utils/db"));
const agenda_1 = __importDefault(require("./utils/agenda"));
function createServer() {
    return __awaiter(this, void 0, void 0, function* () {
        yield db_1.default.connect();
        agenda_1.default.on('ready', () => {
            console.log('Agenda started');
        });
        agenda_1.default.on('start', (job) => {
            console.log(`Job ${job.attrs.name} started`);
        });
        agenda_1.default.on('complete', (job) => {
            console.log(`Job ${job.attrs.name} finished`);
        });
        agenda_1.default.on('cancel', (job) => {
            console.log(`Job ${job.attrs.name} cancelled`);
        });
        agenda_1.default.on('fail', (err, job) => {
            console.log(`Job ${job.attrs.name} failed with error: ${err.message}`);
        });
        const server = (0, fastify_1.default)({
            logger: true,
        });
        server.register(cors_1.default, {
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
        server.get('/about.json', (request, reply) => __awaiter(this, void 0, void 0, function* () {
            try {
                // Lire le contenu du fichier about.json et le renvoyer en réponse
                const aboutJson = require('../about.json'); // Assurez-vous que le chemin du fichier est correct
                reply.send(aboutJson);
            }
            catch (error) {
                reply.status(500).send({ error: 'Internal Server Error' });
            }
        }));
        yield agenda_1.default.start();
        return server;
    });
}
exports.createServer = createServer;
