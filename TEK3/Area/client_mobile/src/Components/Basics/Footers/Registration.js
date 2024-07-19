import { Box, Button, ButtonText, Center, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';

import { StyleSheet, TouchableOpacity, View } from 'react-native';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

export default function FooterRegistration(navigation, page) {
    const styles = loadStyle(useContext(ThemeContext));

    let txt;

    if (page == "Register") {
        txt = "New on AreApp? ";
    } else {
        txt = "Not new on AreApp? ";
    }

    return (
        <Center>

            <View style={{ flexDirection: 'row', alignItems: 'center' }}>

                <Text
                    color={styles.colorFourth}
                    size="sm" marginBottom={10}>{txt}</Text>

                <TouchableOpacity onPress={() => navigation.navigate(page)}>

                    <Text
                        color={styles.colorPrimary}

                        size="sm"

                        italic={true}
                        underline={true}

                        marginBottom={10}
                    >
                        {page}
                    </Text>

                </TouchableOpacity>

            </View>

        </Center>
    );
}
