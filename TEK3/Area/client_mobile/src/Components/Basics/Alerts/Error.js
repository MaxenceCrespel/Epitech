import { Alert, AlertIcon, AlertText, Box, Button, ButtonIcon, ButtonText, GluestackUIProvider, Input, InputField, Text, View } from '@gluestack-ui/themed';
import { Info } from 'lucide-react-native'

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import { useContext } from 'react';

import loadStyle from "../../../../assets/style/base";

export default function AlertError(message) {
    let errorMessage = " " + message
    return (
        <Alert
            action="error"
            variant="solid"

            w="80%"
            h="6%"

            borderRadius={"$full"}

            marginBottom={5}
        >
            <AlertIcon as={Info}/>

            <AlertText
                color="$red"
            >
                {errorMessage}
            </AlertText>
        </Alert>
    )
}
