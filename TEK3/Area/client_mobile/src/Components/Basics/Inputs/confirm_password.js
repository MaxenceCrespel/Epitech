import { Box, Button, ButtonText, FormControl, FormControlError, FormControlErrorText, FormControlErrorIcon, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';
import Icon from 'react-native-vector-icons/FontAwesome';
import { Info } from "lucide-react-native";

import { useState, useContext } from 'react';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import loadStyle from "../../../../assets/style/base";

import ButtonTogglePassword from "../Buttons/TogglePassword";

export default function InputConfirmPassword(handleConfirmPasswordChange, showPassword, toggleShowPassword, invalid, errorText) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <FormControl
            w="80%"

            variant="rounded"
            size="md"

            marginBottom={10}

            isDisabled={false}
            isInvalid={!invalid}
            isReadOnly={false}
            isRequired={true}
        >

            <Input
                variant="rounded"
                bg="$white"
            >
                <InputField
                    placeholder="Confirm password*"
                    onChangeText={newPassword => handleConfirmPasswordChange(newPassword)}
                    secureTextEntry={!showPassword}
                    color="$black"
                />

                {ButtonTogglePassword(toggleShowPassword, showPassword, styles)}

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
