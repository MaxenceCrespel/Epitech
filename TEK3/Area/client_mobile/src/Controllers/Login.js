import { useState, useContext } from 'react';
import axios from 'axios';
import AsyncStorage from "@react-native-async-storage/async-storage";

import AlertError from '../Components/Basics/Alerts/Error';

import UserInfo from "../../data/user/info"

async function Log(email, password, navigation, setAlert) {
    try {
        const savedApplication = await AsyncStorage.getItem("server");
        const ip = JSON.parse(savedApplication).ip;
        const port = JSON.parse(savedApplication).server_port;

        if (savedApplication !== null && port !== null && ip !== null) {
            let requestUrl = 'http://' + ip + ':' + port + '/v1/auth/login';
            let data = JSON.stringify({
                "email": email.toLowerCase(),
                "password": password
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

            let msg = "Error: ";

            try {
                const response = await axios.request(config);

                UserInfo.email = email;
                UserInfo.token = response.data.token;

                return {
                    status: response.status,
                    token: JSON.stringify(response.data.token)
                };
            } catch (error) {
                if (error.response) {
                    if (error.response.status) {
                        msg = msg + error.response.data.error;
                        setAlert(AlertError(msg));
                        return {
                            status: error.response.status
                        };
                    }
                } else {
                    msg = msg + error.message;
                    setAlert(AlertError(msg));
                    return {
                        status: 500
                    };
                }
            }
        } else {
            setAlert(AlertError("Error: Server not found"));
            return {
                status: 500
            };
        }
    } catch (error) {
        msg = msg + error.message;
        setAlert(AlertError(msg));
        return {
            status: 500
        };
    }
}

export default async function LoginFunction(email, password, navigation, setAlert) {
    let info = await Log(email, password, navigation, setAlert);

    if (info.status == 200) {
        UserInfo.email = email;

        let tokenWithQuotes = info.token;
        UserInfo.token = tokenWithQuotes.substring(1, tokenWithQuotes.length - 1);

        try {
            await AsyncStorage.setItem("user", JSON.stringify(UserInfo));
        } catch (error) {
            console.log(error);
        }
        navigation.navigate("Home");
    } else {
        console.log("Error: " + info.status);
    }
}
