import axios from "axios";
import AsyncStorage from "@react-native-async-storage/async-storage";

export default async function GetUserApplets(setAlert) {
    try {
        const savedApplication = await AsyncStorage.getItem("server");
        const ip = JSON.parse(savedApplication).ip;
        const port = JSON.parse(savedApplication).server_port;

        if (savedApplication != null && port != null && ip != null) {
            let requestUrl = 'http://' + ip + ':' + port + '/v1/applets';
            const savedUser = await AsyncStorage.getItem("user");
            const token = JSON.parse(savedUser).token;
            if (savedUser !== null) {
                const config = {
                    method: "get",
                    maxBodyLength: Infinity,
                    url: requestUrl,
                    headers: {
                        "Content-Type": "application/json",
                        "Authorization": "Bearer " + token
                    },
                };
                try {
                    let response = await axios.request(config);
                    response.data = response.data.filter(applet => applet.user_id === JSON.parse(savedUser).id);
                    return {
                        status: response.status,
                        data: response.data,
                    };
                }
                catch (error) {
                    if (error.response === undefined) {
                        setAlert(AlertError("Error: Server not found"));
                        return {
                            status: 500,
                        };
                    } else {
                        setAlert(AlertError(error.response.data.error));
                        return {
                            status: error.response.status,
                        };
                    }
                }
            } else {
                setAlert(AlertError("Error: Forbidden"));
                return {
                    status: 403,
                };
            }
        } else {
            setAlert(AlertError("Error: Server not found"));
            return {
                status: 500,
            };
        }
    } catch (error) {
        console.log(error);
    }
}