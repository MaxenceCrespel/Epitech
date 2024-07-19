import axios, { AxiosError } from 'axios';
import schema from './schema.json';

async function teamsReaction(params: any, data: any) {
    const url = params.url;
    let card = {
        "type": "message",
        "attachments": [
            {
                "contentType": "application/vnd.microsoft.card.adaptive",
                "contentUrl": null,
                "content": {
                    "$schema": "http://adaptivecards.io/schemas/adaptive-card.json",
                    "type": "AdaptiveCard",
                    "version": "1.2",
                    "body": [
                        {
                            "type": "TextBlock",
                            "text": data.message,
                            "size": "large"
                        }
                    ]
                }
            }
        ]
    }
    try {
        await axios.post(url, card);
        return { message: 'ok' };
    } catch (err) {
        const error = err as AxiosError;
        return { error: error.message };
    }
}

export default teamsReaction;