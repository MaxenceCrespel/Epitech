import axios, { AxiosError } from 'axios';

async function slackReaction(params: any, data: any) {
    const url = params.url;
    const payload = {
        text: data.message,
    }

    try {
        await axios.post(url, payload);
        return { message: 'Message envoyé avec succès sur Slack' };
    } catch (err) {
        const error = err as AxiosError;
        return { error: error.message };
    }
}

export default slackReaction;
