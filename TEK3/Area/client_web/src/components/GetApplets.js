import axios from "axios";

export default async function GetApplets(token) {
    try {
        let requestUrl = 'http://localhost:8080/v1/applets/';
        if (token) {
            const config = {
                method: "get",
                maxBodyLength: Infinity,
                url: requestUrl,
                headers: {
                    Authorization: `Bearer ${token}`,
                },
            };
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
    } catch (error) {
        console.log(error);
    }
}