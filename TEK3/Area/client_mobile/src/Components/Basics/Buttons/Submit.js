import { Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';
import { View } from "react-native";

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

export default function ButtonSubmit(disabled = false, submitFunction, buttonText) {
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
                submitFunction();
            }}
        >

            <ButtonText
                color="$white"
            >
                {buttonText}
            </ButtonText>

        </Button>
    )
}
