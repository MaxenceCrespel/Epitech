import { Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';
import { View } from "react-native";

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";
export default function IconButton(icon, onPress) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <View style={styles.viewButtonChangeTheme}>
            <Button
                variant = "rounded"

                borderRadius="$full"
                size="lg"
                bg="$transparent"

                marginBottom={10}
                onPress={onPress}
            >

                <ButtonIcon as={icon} color={styles.colorSecondary} size={35} />

            </Button>
        </View>
    )
}
