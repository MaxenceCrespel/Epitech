import loadStyle from "./assets/style/base";

import { NavigationContainer, Theme } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
// import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';

import { Box, Button, ButtonText, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';
import { useState, useContext } from 'react';
import { StyleSheet, Text, View } from 'react-native';

import Login from "./src/Pages/Login";
import Register from "./src/Pages/Register";
import ServerSettings from "./src/Pages/ServerSettings";
import Home from "./src/Pages/Home";
import ActionForm from "./src/Pages/ActionForm";
import ReactionForm from "./src/Pages/ReactionForm";
import AppletForm from "./src/Pages/AppletForm";

import ThemeContext, { ThemeProvider, useTheme } from './assets/style/themeContext';

const stack = createNativeStackNavigator();

export default function App() {
    const [theme, setTheme] = useState('light');

    return (
        <ThemeProvider>

            <GluestackUIProvider colorMode={theme}>

                <NavigationContainer>
                    <stack.Navigator>
                        <stack.Screen
                            name="ServerSettings"
                            component={ServerSettings}
                            options={{ headerShown: false }}
                        />

                        <stack.Screen
                            name="Register"
                            component={Register}
                            options={{ headerShown: false }}
                        />

                        <stack.Screen
                            name="Login"
                            component={Login}
                            options={{ headerShown: false }}
                        />

                        <stack.Screen
                            name="Home"
                            component={Home}
                            options={{ headerShown: false }}
                        />
                        <stack.Screen
                            name="ActionForm"
                            component={ActionForm}
                            options={{ headerShown: false }}
                        />
                        <stack.Screen
                            name="ReactionForm"
                            component={ReactionForm}
                            options={{ headerShown: false }}
                        />
                        <stack.Screen
                            name="AppletForm"
                            component={AppletForm}
                            options={{ headerShown: false }}
                        />
                    </stack.Navigator>
                </NavigationContainer>

            </GluestackUIProvider>
        </ThemeProvider>
    );
}

const styles = StyleSheet.create({
    third: "#800080"
});
