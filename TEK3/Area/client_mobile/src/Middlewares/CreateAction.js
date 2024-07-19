import axios from "axios";
import AsyncStorage from "@react-native-async-storage/async-storage";
import AlertError from "../Components/Basics/Alerts/Error";

export default async function CreateAction(setAlert, data) {
    try {
        const savedApplication = await AsyncStorage.getItem("server");
        const ip = JSON.parse(savedApplication).ip;
        const port = JSON.parse(savedApplication).server_port;
        const transformedParams = {};

        Object.keys(data.params).forEach((key) => {
            transformedParams[key] = data.params[key].value;
        });

        data.params = [transformedParams];

        if (savedApplication != null && port != null && ip != null) {
            let requestUrl = 'http://' + ip + ':' + port + '/v1/actions/';

            const savedUser = await AsyncStorage.getItem("user");
            const token = JSON.parse(savedUser).token;

            if (savedUser !== null) {
                const config = {
                    method: "post",
                    maxBodyLength: Infinity,
                    url: requestUrl,
                    headers: {
                        "Content-Type": "application/json",
                        "Authorization": "Bearer " + token
                    },
                    data: data,
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