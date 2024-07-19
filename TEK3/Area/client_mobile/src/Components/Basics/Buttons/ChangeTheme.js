import { Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';
import { View } from "react-native";

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

import { Moon, Sun } from "lucide-react-native";

export default function ButtonChangeTheme(theme, setTheme) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <View style={styles.viewButtonChangeTheme}>
            <Button
                variant = "rounded"

                borderRadius="$full"
                size="lg"
                bg="$transparent"

                marginBottom={10}

                onPress={() => {
                    setTheme(theme == 'light' ? 'dark' : 'light');
                }}
            >

               <ButtonIcon as={(theme == "light" ? Moon : Sun)} color={styles.colorSecondary} fill={styles.colorSecondary} size={35} />

            </Button>
        </View>
    )
}
