import { Box, Button, ButtonText, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';
import Icon from 'react-native-vector-icons/FontAwesome';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

export default function ButtonTogglePassword(toggleShowPassword, showPassword) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <Button
            bg={styles.third}

            borderTopLeftRadius={0}

            onPress={toggleShowPassword}
        >

            <Icon
                name={showPassword ? 'eye' : 'eye-slash'}
                size={24}
                color={styles.colorSecondary}
            />

        </Button>
    )
}
