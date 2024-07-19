import { Box, Button, ButtonText, Center, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { useState, useContext } from 'react';
import { StyleSheet, TouchableOpacity, View } from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome';

import InputBasic from "../Components/Basics/Inputs/Basic";
import InputPassword from "../Components/Basics/Inputs/Password";

import ButtonLogin from '../Components/Basics/Buttons/Login';
import ButtonChangeTheme from "../Components/Basics/Buttons/ChangeTheme";

import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";

import FooterRegistration from "../Components/Basics/Footers/Registration"

import ThemeContext, { useTheme } from "../../assets/style/themeContext";
import loadStyle from "../../assets/style/base";

import IsEmail from '../Middlewares/IsEmail';

import LoginFunction from "../Controllers/Login";

export default function Login({ navigation }) {
    const styles = loadStyle(useContext(ThemeContext));
    const { theme, setTheme } = useTheme();

    const [email, setEmail] = useState('');
    const [isEmailEmpty, setIsEmail] = useState(true);

    const [password, setPassword] = useState('');
    const [isPasswordEmpty, setIsPasswordEmpty] = useState(true);
    const [showPassword, setShowPassword] = useState(false);

    const [passwordVisible, setPasswordVisible] = useState(false);

    const togglePasswordVisibility = () => {
        setPasswordVisible(!passwordVisible);
    };

    const handleEmailChange = (newEmail) => {
        setEmail(newEmail);
        setIsEmail(newEmail === '');
    };

    const handlePasswordChange = (newPassword) => {
        setPassword(newPassword);
        setIsPasswordEmpty(newPassword === '');
    };

    const toggleShowPassword = () => {
        setShowPassword(!showPassword);
    };

    let validEmail = IsEmail(email);
    let emailErrorText = validEmail ? "" : "Invalid email format";

    let canUserLogin = canLogin(email, password);

    const [alert, setAlert] = useState('');

    return (
        <Box
            justifyContent="center"
            alignItems="center"

            h="100%"

            bg={styles.colorBackground}
        >
            {HeaderHalfCircle()}
            {HeaderTitle("Login")}

            {ButtonChangeTheme(theme, setTheme)}

            <Center>

                <Text
                    color={styles.colorPrimary}

                    size="3xl"

                    bold={true}
                    italic={true}

                    marginBottom={10}
                >
                    AreApp
                </Text>

            </Center>

            {alert}

            {InputBasic("Email*", handleEmailChange, "", validEmail, emailErrorText)}
            {InputPassword(handlePasswordChange, showPassword, toggleShowPassword)}

            {ButtonLogin(canUserLogin, email, password, navigation, setAlert)}

            {FooterRegistration(navigation, "Register")}
        </Box>
    );
}

function canLogin(email, password) {
    if (email !== '' && password !== '' && IsEmail(email)) {
        return true;
    }
    return false;
}
