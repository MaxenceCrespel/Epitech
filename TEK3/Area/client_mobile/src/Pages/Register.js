import { Box, Button, ButtonText, Center, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { useState, useContext } from 'react';
import { StyleSheet, TouchableOpacity, View } from 'react-native';
import AsyncStorage from "@react-native-async-storage/async-storage";

import Icon from 'react-native-vector-icons/FontAwesome';

import InputBasic from "../Components/Basics/Inputs/Basic";
import InputPassword from "..//Components/Basics/Inputs/Password";
import InputConfirmPassword from "..//Components/Basics/Inputs/confirm_password";

import ButtonChangeTheme from "../Components/Basics/Buttons/ChangeTheme";
import ButtonRegister from '../Components/Basics/Buttons/Register';

import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";

import FooterRegistration from "../Components/Basics/Footers/Registration"

import AlertError from '../Components/Basics/Alerts/Error';

import ThemeContext, { useTheme } from "../../assets/style/themeContext";
import loadStyle from "../../assets/style/base";

import IsEmail from '../Middlewares/IsEmail';

export default function Register({ navigation }) {
    const styles = loadStyle(useContext(ThemeContext));

    const { theme, setTheme } = useTheme();

    const [alert, setAlert] = useState('');

    const [email, setEmail] = useState('');
    const [isEmailEmpty, setIsEmail] = useState(true);

    const [username, setUsername] = useState('');
    const [isUsernameEmpty, setIsUsername] = useState(true);

    const [name, setName] = useState('');
    const [isNameEmpty, setIsName] = useState(true);

    const [surname, setSurname] = useState('');
    const [isSurnameEmpty, setIsSurname] = useState(true);

    const [password, setPassword] = useState('');
    const [isPasswordEmpty, setIsPasswordEmpty] = useState(true);
    const [showPassword, setShowPassword] = useState(false);

    const [confirmPassword, setConfirmPassword] = useState('');

    const [passwordVisible, setPasswordVisible] = useState(false);

    const togglePasswordVisibility = () => {
        setPasswordVisible(!passwordVisible);
    };

    const handleUsernameChange = (newUsername) => {
        setUsername(newUsername);
        setIsUsername(newUsername === '');
    };

    const handleEmailChange = (newEmail) => {
        setEmail(newEmail);
        setIsEmail(newEmail === '');
    };

    const handlePasswordChange = (newPassword) => {
        setPassword(newPassword);
        setIsPasswordEmpty(newPassword === '');
    };

    const handleConfirmPasswordChange = (newConfirmPassword) => {
        setConfirmPassword(newConfirmPassword);
        setIsPasswordEmpty(newConfirmPassword === '');
    };

    const handleNameChange = (newName) => {
        setName(newName);
        setIsName(newName === '');
    };

    const handleSurnameChange = (newSurname) => {
        setSurname(newSurname);
        setIsSurname(newSurname === '');
    };

    const toggleShowPassword = () => {
        setShowPassword(!showPassword);
    };

    let emailValid = IsEmail(email);
    let emailErrorText = emailValid ? "" : "Invalid email format";

    let passwordValid = verifyPassword(password, confirmPassword);
    let passwordErrorText = passwordValid ? "" : "Passwords do not match";

    let canRegisterUser = canRegister(email, username, name, surname, password, confirmPassword, emailValid, passwordValid);

    return (
        <Box
            justifyContent="center"
            alignItems="center"

            h="100%"

            bg={styles.colorBackground}
        >

            {HeaderHalfCircle()}

            {HeaderTitle("Register")}
            {ButtonChangeTheme(theme, setTheme)}

            <Center>

                <Text
                    size="3xl"

                    bold={true}
                    italic={true}

                    color={styles.colorPrimary}

                    marginBottom={10}
                >
                    AreApp
                </Text>

            </Center>

            {alert}

            {InputBasic("Email*", handleEmailChange, "", emailValid, emailErrorText)}
            {InputBasic("Username*", handleUsernameChange, "")}
            {InputBasic("Name*", handleNameChange, "")}
            {InputBasic("Surname*", handleSurnameChange, "")}
            {InputPassword(handlePasswordChange, showPassword, toggleShowPassword, passwordValid, passwordErrorText)}
            {InputConfirmPassword(handleConfirmPasswordChange, showPassword, toggleShowPassword, passwordValid, passwordErrorText)}

            {ButtonRegister(canRegisterUser, email, username, name, surname, password, navigation, setAlert)}
            {FooterRegistration(navigation, "Login")}

        </Box>
    );
}

function verifyPassword(password, confirmPassword) {
    if (!password || !confirmPassword || (password === confirmPassword)) {
        return true;
    }
    return false;
}

function canRegister(email, username, name, surname, password, confirmPassword, emailValid, passwordValid) {
    if (email !== '' && username !== '' && name !== '' && surname !== '' && password !== '' && confirmPassword !== '' && emailValid && passwordValid) {
        return true;
    }

    return false;
}
