import { Box, Button, ButtonText, FormControl, FormControlError, FormControlErrorText, FormControlErrorIcon, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';
import Icon from 'react-native-vector-icons/FontAwesome';
import { Info } from "lucide-react-native";

import { useState, useContext } from 'react';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import loadStyle from "../../../../assets/style/base";

export default function InputBasic(string, handleStringChange, value, invalid = true, errorText = "") {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <FormControl
            w="80%"

            variant={styles.input.variant}
            size={styles.input.size}

            marginBottom={10}

            isDisabled={false}
            isInvalid={!invalid}
            isReadOnly={false}
            isRequired={true}
        >

            <Input
                variant={styles.input.variant}
                bg="$white"
            >
                <InputField
                    placeholder={string}
                    defaultValue={value}
                    onChangeText={newString => handleStringChange(newString)}
                    color="$black"
                />

            </Input>

            <FormControlError>

                <FormControlErrorIcon as={Info} />

                <FormControlErrorText>
                    {errorText}
                </FormControlErrorText>

            </FormControlError>

        </FormControl>
    );
}
