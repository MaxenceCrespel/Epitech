import axios from "axios";

export default async function StopApplet(id, Token) {
    try {

        let requestUrl = 'http://localhost:8080/v1/applets/' + id + '/stop';
        if (Token) {
            const config = {
                method: "post",
                maxBodyLength: Infinity,
                url: requestUrl,
                headers: {
                    Authorization: `Bearer ${Token}`,
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