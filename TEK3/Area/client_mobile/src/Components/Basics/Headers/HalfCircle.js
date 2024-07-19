import { Box, Button, ButtonText, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';

import { StyleSheet, TouchableOpacity, View } from 'react-native';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

export default function HeaderHalfCircle() {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <View
            style={{
                position: 'absolute',
                width: "200%",
                height: "100%",
                top: "-87%",
                borderRadius: 400,
                backgroundColor: styles.colorPrimary,
            }}
        />
    );
}
