import React from 'react';
import { Select, SelectTrigger, Text, SelectIcon, Icon, SelectPortal, SelectBackdrop, SelectContent, SelectDragIndicatorWrapper, SelectDragIndicator, SelectItem } from "@gluestack-ui/themed";
import { ChevronDown } from "lucide-react-native";

const SelectActions = ({ value, onChange, placeholder, actionList }) => {
    return (
        <Select
            w="50%"
            paddingBottom={10}
            onValueChange={onChange}
        >

            <SelectTrigger variant="outline" size="md">
                <Text
                    marginLeft={10}
                >
                    {value}
                </Text>

                <SelectIcon mr="$3">
                    <Icon as={ChevronDown} />
                </SelectIcon>

            </SelectTrigger>

            <SelectPortal>
                <SelectBackdrop />

                <SelectContent>

                    <SelectDragIndicatorWrapper>
                        <SelectDragIndicator />
                    </SelectDragIndicatorWrapper>

                    {actionList?.data?.actions?.map((action) => (
                        <SelectItem key={action._id} label={action.name} value={action.name} />
                    ))}

                </SelectContent>

            </SelectPortal>
        </Select>
    );
};

export default SelectActions;
