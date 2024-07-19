import { createServer } from './server';
import agenda from './utils/agenda';
async function startServer() {
    const server = await createServer();
    server.listen({
        port: 3000,
        host: '0.0.0.0'
    }, (err, address) => {
        if (err) {
            console.error(err);
            process.exit(1);
        }
        console.log(`Server listening at ${address}`);
    });
}
startServer();