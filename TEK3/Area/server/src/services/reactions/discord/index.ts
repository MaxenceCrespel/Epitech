import axios, { AxiosError } from 'axios';
import schema from './schema.json';

async function discordWebHook(params: any, data: any) {
    const url = params.url;

    const payload = {
        content: data.message,
    }
    try {
        await axios.post(url, payload);
        return { message: 'ok' };
    } catch (err) {
        const error = err as AxiosError;
        return { error: error.message };
    }
}

export default discordWebHook;