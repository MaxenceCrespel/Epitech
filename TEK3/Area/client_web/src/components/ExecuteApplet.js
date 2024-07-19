import axios from "axios";

export default async function ExecuteApplet(id, token) {
    try {
        const requestUrl = 'http://localhost:8080/v1/applets/' + id + '/execute';
        if (token) {
            const config = {
                method: "post",
                maxBodyLength: Infinity,
                url: requestUrl,
                headers: {
                    Authorization: `Bearer ${token}`,
                },
            };
            console.log(config);
            try {
                let response = await axios.request(config);
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
    }
    catch (error) {
        console.log(error);
    }
}