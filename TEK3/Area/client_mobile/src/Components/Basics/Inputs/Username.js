import { Box, Button, ButtonText, GluestackUIProvider, Input, InputField } from '@gluestack-ui/themed';

import { useState, useContext } from 'react';

import ThemeContext, { useTheme } from "../../../../assets/style/themeContext";
import loadStyle from "../../../../assets/style/base";

export default function InputUsername(handleUsernameChange) {
    const styles = loadStyle(useContext(ThemeContext));

    return (
        <Input
            w="80%"
            bg='$white'

            variant={styles.input.variant}
            size={styles.input.size}

            borderTopLeftRadius={16}
            borderTopRightRadius={16}
            borderBottomLeftRadius={16}
            borderBottomRightRadius={16}

            marginBottom={10}

            isDisabled={false}
            isInvalid={false}
            isReadOnly={false}
        >

            <InputField
                placeholder="Username"
                onChangeText={newUsername => handleUsernameChange(newUsername)}
                color="$black"
            />

        </Input>
    );
}
