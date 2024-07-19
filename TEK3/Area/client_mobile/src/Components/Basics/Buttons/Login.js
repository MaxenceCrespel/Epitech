import { Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { View } from "react-native";

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

import LoginFunction from "../../../Controllers/Login";

export default function ButtonLogin(disabled = false, email, password, navigation, setAlert) {
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
                LoginFunction(email, password, navigation, setAlert);
            }}
        >

            <ButtonText
                color="$white"
            >
                Login
            </ButtonText>

        </Button>
    )
}
