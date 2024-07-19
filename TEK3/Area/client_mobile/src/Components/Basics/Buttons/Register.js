import { Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { View } from "react-native";

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

import RegisterFunction from "../../../Controllers/Register";

export default function ButtonRegister(disabled = false, email, username, name, surname, password, navigation, setAlert) {
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
                RegisterFunction(email, username, name, surname, password, navigation, setAlert);
            }}
        >

            <ButtonText
                color="$white"
            >
                Register
            </ButtonText>

        </Button>
    )
}
