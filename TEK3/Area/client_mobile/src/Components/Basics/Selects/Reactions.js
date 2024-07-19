import React from 'react';
import { Select, SelectTrigger, Text, SelectIcon, Icon, SelectPortal, SelectBackdrop, SelectContent, SelectDragIndicatorWrapper, SelectDragIndicator, SelectItem } from "@gluestack-ui/themed";
import { ChevronDown } from "lucide-react-native";

const SelectReactions = ({ value, onChange, placeholder, reactionList }) => {
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

                    {reactionList?.data?.reactions?.map((reaction) => (
                        <SelectItem key={reaction._id} label={reaction.name} value={reaction.name} />
                    ))}

                </SelectContent>

            </SelectPortal>
        </Select>
    );
};

export default SelectReactions;
