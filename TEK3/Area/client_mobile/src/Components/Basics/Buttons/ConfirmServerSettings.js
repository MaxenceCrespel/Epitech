import { Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { View } from "react-native";
import AsyncStorage from '@react-native-async-storage/async-storage';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

import ServerInfo from "../../../../data/server/info"

import IsServerOnline from "../../../Middlewares/IsServerOnline";

import AlertError from '../Alerts/Error';

export default function ButtonConfirmServerSettings(disabled = false, server_ip, server_port, web_port, navigation, setAlert) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <Button
            variant="outlined"
            isDisabled={!disabled}

            size="lg"

            bg={styles.colorPrimary}

            borderTopLeftRadius={16}
            borderTopRightRadius={16}
            borderBottomLeftRadius={16}
            borderBottomRightRadius={16}

            marginBottom={10}

            onPress={() => {
                WriteServerInfo(server_ip, server_port, web_port, setAlert).then((result) => {
                    if (result) {
                        navigation.navigate("Register");
                    }
                });
            }}
        >

            <ButtonText
                color="$white"
            >
                Confirm
            </ButtonText>

        </Button>
    )
}

async function WriteServerInfo(server_ip, server_port, web_port, setAlert) {
    ServerInfo.ip = server_ip;
    ServerInfo.port = server_port;
    ServerInfo.webPort = web_port;

    try {
        await AsyncStorage.setItem("server", JSON.stringify(ServerInfo));
    } catch (error) {
        console.log(error);
    }

    let serverOnline = await IsServerOnline();

    if (serverOnline.status == 200) {
        return true;
    } else {
        setAlert(AlertError("Error: Server status " + serverOnline.status));
        return false;
    }
}
