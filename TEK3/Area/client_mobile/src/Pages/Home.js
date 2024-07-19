import { Box, Button, ButtonText, Center, GluestackUIProvider, Input, InputField, Text, ScrollView, View } from '@gluestack-ui/themed';
import React, { useState, useEffect, useContext } from "react";
import AsyncStorage from '@react-native-async-storage/async-storage';
import ButtonChangeTheme from "../Components/Basics/Buttons/ChangeTheme";
import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";
import ThemeContext, { useTheme } from "../../assets/style/themeContext";
import loadStyle from "../../assets/style/base";
import GetCurrentUser from "../Middlewares/GetCurrentUser";
import GetUserApplets from '../Middlewares/GetUserApplets';
import List from "../Components/Services/List";
import UserInfo from "../../data/user/info";

import ButtonSubmit from '../Components/Basics/Buttons/Submit';

export default function Home({ navigation }) {
    const styles = loadStyle(useContext(ThemeContext));
    const { theme, setTheme } = useTheme();

    const [user, setUser] = useState('');
    const [userRequest, setUserRequest] = useState('');
    const [applets, setApplets] = useState('');

    const [alert, setAlert] = useState('');

    useEffect(() => {
        const unsubscribe = navigation.addListener('focus', async () => {
            const savedUser = await AsyncStorage.getItem("user");

            if (savedUser) {
                setUserRequest({ data: { email: "Loading...", name: "Loading..." } });
                setUser(JSON.parse(savedUser));

                const fetchedUser = await GetCurrentUser(setAlert);
                const fetchedApplets = await GetUserApplets(setAlert);

                setApplets(fetchedApplets);
                setUserRequest(fetchedUser);

                UserInfo._id = fetchedUser.data._id;
                UserInfo.email = fetchedUser.data.email;
                UserInfo.name = fetchedUser.data.name;
                UserInfo.surname = fetchedUser.data.surname;
                UserInfo.username = fetchedUser.data.username;

                try {
                    await AsyncStorage.setItem("user", JSON.stringify(UserInfo));
                } catch (error) {
                    console.log(error);
                }
            } else {
                navigation.navigate("Login");
            }
        });

        return unsubscribe;
    }, [navigation]);

    return (
        <View>
            <Box justifyContent="center" alignItems="center" minHeight="100%" bg={styles.colorBackground} width={'100%'}>
                {HeaderHalfCircle()}
                {HeaderTitle("Home")}
                {ButtonChangeTheme(theme, setTheme)}

                {alert}

                <Text color={styles.colorPrimary} size="3xl" bold={true} italic={true} marginBottom={10}>
                    AreApp
                </Text>

                <Text color={styles.colorPrimary} size="xl" bold={true} italic={true} marginBottom={10}>
                    Welcome {userRequest?.data?.name}
                </Text>

                <Text color={styles.colorPrimary} size="xl" bold={true} italic={true} marginBottom={10}>
                    Your email is {userRequest?.data?.email}
                </Text>

                <Text color={styles.colorPrimary} size="xl" bold={true} italic={true} marginBottom={10}>
                    You have {applets?.data?.length} applets created by you.
                </Text>

                <List navigation={navigation} />

                {ButtonSubmit(true, () => { navigation.navigate("ActionForm") }, "Create Applet")}
            </Box>
        </View>
    );
}

