import { Box, Button, ButtonText, GluestackUIProvider, Input, InputField, Text } from '@gluestack-ui/themed';

import { StyleSheet, TouchableOpacity, View } from 'react-native';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

export default function HeaderTitle(headerTitle) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <View style={{ position: 'absolute', top: 10, left: 10 }}>
            <Text color={styles.colorSecondary} size="4xl">
                {headerTitle}
            </Text>
        </View>
    );
}
