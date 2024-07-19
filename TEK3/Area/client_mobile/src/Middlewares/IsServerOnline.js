import axios from "axios";
import AsyncStorage from "@react-native-async-storage/async-storage";

export default async function IsServerOnline() {
    try {
        const savedApplication = await AsyncStorage.getItem("server");
        const ip = JSON.parse(savedApplication).ip;
        const port = JSON.parse(savedApplication).server_port;

        if (savedApplication !== null && port !== null && ip !== null) {
            let requestUrl = 'http://' + ip + ':' + port + '/v1/ping';

            const config = {
                method: "get",
                maxBodyLength: Infinity,
                url: requestUrl,
                headers: {
                    "Content-Type": "application/json",
                },
            };
            try {
                const response = await axios.request(config);
                return {
                    status: response.status,
                    data: response.data,
                };
            }
            catch (error) {
                console.log(error);
                if (error.response === undefined) {
                    return {
                        status: 500,
                    };
                }

                return {
                    status: error.response.status,
                };
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