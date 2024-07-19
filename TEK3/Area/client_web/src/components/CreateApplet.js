import axios from "axios";

export default async function CreateApplet(data, Token) {
    try {
        const requestUrl = 'http://localhost:8080/v1/applets/';
        const informations = {
            name: data.name,
            description: data.description,
            actions: data.actions,
            reactions: data.reactions,
            user: data.user,
            functionName: data.functionName,
            frequency: data.frequency,
        };
        console.log(informations);
        if (Token) {
            const config = {
                method: "post",
                maxBodyLength: Infinity,
                url: requestUrl,
                headers: {
                    Authorization: `Bearer ${Token}`,
                },
                data: informations,
            };
            try {
                let response = await axios.request(config);
                console.log(response.data)
                return {
                    status: response.status,
                    data: response.data,
                };

            }
            catch (error) {
                if (error.response === undefined) {
                    return {
                        status: 500,
                    };
                } else {
                    return {
                        status: error.response.status,
                    };
                }
            }
        } else {
            return {
                status: 403,
            };
        }
    } catch (error) {
        console.log(error);
    }
}