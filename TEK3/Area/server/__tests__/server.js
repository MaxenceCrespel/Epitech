const request = require('supertest');
const dotenv = require('dotenv');
dotenv.config();

let token = '';

describe('API Tests', () => {
    beforeAll(async () => {
        const res = await request('http://localhost:8080')
            .post('/v1/auth/login')
            .set('Content-Type', 'application/json')
            .send({
                "username": "admin",
                "password": process.env.DEFAULT_USER_PASSWORD
            });

        expect(res.statusCode).toEqual(200);
        token = res.body.token;
    });

    describe('Server is online', () => {
        it('should respond with a success status code', async () => {
            const res = await request('http://localhost:8080').get('/v1/ping');
            expect(res.statusCode).toEqual(200);
        });
    });
});
