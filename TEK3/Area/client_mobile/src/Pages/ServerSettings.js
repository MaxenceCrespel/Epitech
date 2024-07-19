import { Box, Button, ButtonText, Center, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { useState, useContext } from 'react';
import { StyleSheet, TouchableOpacity, View } from 'react-native';
import AsyncStorage from "@react-native-async-storage/async-storage";

import Icon from 'react-native-vector-icons/FontAwesome';

import InputBasic from "../Components/Basics/Inputs/Basic";

import ButtonChangeTheme from "../Components/Basics/Buttons/ChangeTheme";

import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";

import ButtonConfirmServerSettings from '../Components/Basics/Buttons/ConfirmServerSettings';

import AlertError from '../Components/Basics/Alerts/Error';

import ThemeContext, { useTheme } from "../../assets/style/themeContext";
import loadStyle from "../../assets/style/base";

import IsServerOnline from '../Middlewares/IsServerOnline';

import ServerInfo from "../../data/server/info"

export default function ServerSettings({ navigation }) {
    const styles = loadStyle(useContext(ThemeContext));

    const { theme, setTheme } = useTheme();

    const [serverIp, setServerIp] = useState('');
    const [serverPort, setServerPort] = useState('');
    const [webPort, setWebPort] = useState('');

    const [alert, setAlert] = useState('');

    // if (ServerInfo.server_ip != null) {
    //     setServerIp(ServerInfo.server_ip);
    // }

    // if (ServerInfo.server_port != null) {
    //     setServerPort(ServerInfo.server_port);
    // }

    // if (ServerInfo.web_port != null) {
    //     setWebPort(ServerInfo.web_port);
    // }

    return (
        <Box
            justifyContent="center"
            alignItems="center"

            h="100%"

            bg={styles.colorBackground}
        >

            {HeaderHalfCircle()}

            {HeaderTitle("Server")}
            {ButtonChangeTheme(theme, setTheme)}

            {alert}

            {InputBasic("Server IP", setServerIp)}
            {InputBasic("Server Port", setServerPort, ServerInfo.server_port)}
            {InputBasic("Web Port", setWebPort, ServerInfo.web_port)}

            {ButtonConfirmServerSettings(IsServerOnline(), serverIp, serverPort, webPort, navigation, setAlert)}

        </Box>
    );
}
