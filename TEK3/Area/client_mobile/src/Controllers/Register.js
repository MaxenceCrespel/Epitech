import axios from 'axios';
import AsyncStorage from '@react-native-async-storage/async-storage';
import AlertError from '../Components/Basics/Alerts/Error';

import LoginFunction from './Login';

export default async function RegisterFunction(email, username, name, surname, password, navigation, setAlert) {
    let msg = "Error: ";

    try {
        const savedApplication = await AsyncStorage.getItem("server");
        const ip = JSON.parse(savedApplication).ip;
        const port = JSON.parse(savedApplication).server_port;

        if (savedApplication !== null && port !== null && ip !== null) {
            let requestUrl = "http://" + ip + ":" + port + "/v1/users";

            let data = JSON.stringify({
                "name": surname,
                "email": email.toLowerCase(),
                "password": password,
                "username": username,
                "firstname": name
            });

            let config = {
                method: 'post',
                maxBodyLength: Infinity,
                url: requestUrl,
                headers: {
                    'Content-Type': 'application/json'
                },
                data: data
            };

            axios.request(config)
                .then((response) => {
                    LoginFunction(email, password, navigation, setAlert);
                })
                .catch((error) => {
                    if (error.response) {
                        msg = msg + error.response.data.error;
                        setAlert(AlertError(msg));
                    } else {
                        msg = msg + error.message;
                        setAlert(AlertError(msg));
                    }
                });
        } else {
            setAlert(AlertError("Error: Server not found"));
            return {
                status: 500
            };
        }
    } catch (error) {
        msg = msg + error.message;
        setAlert(AlertError(msg));
    }
}
