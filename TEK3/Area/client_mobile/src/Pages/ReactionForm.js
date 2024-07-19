import InputBasic from "../Components/Basics/Inputs/Basic";
import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";
import IconButton from "../Components/Basics/Buttons/IconButton";
import { Undo2, ChevronDown } from "lucide-react-native";
import { Box, Button, Select, SelectItem, SelectContent, SelectPortal, SelectInput, SelectTrigger, SelectDragIndicator, SelectBackdrop, SelectDragIndicatorWrapper, SelectIcon, Text, Icon, FormControl, ButtonText, set, Input, InputField } from "@gluestack-ui/themed";
import loadStyle from "../../assets/style/base";
import { useContext, useState, useEffect, Fragment } from "react";
import GetReactionsList from "../Middlewares/GetReactionsList";
import CreateReaction from "../Middlewares/CreateReaction";
import ThemeContext, { useTheme } from "../../assets/style/themeContext";

import SelectReactions from "../Components/Basics/Selects/Reactions";
import ButtonSubmit from "../Components/Basics/Buttons/Submit";

const ReactionForm = ({ route, navigation }) => {
    const action = route.params.action;

    const styles = loadStyle(useContext(ThemeContext));
    const [title, setTitle] = useState('title');
    const [description, setDescription] = useState('description');
    const [reactionList, setReactionList] = useState([]);
    const [reactionParams, setReactionParams] = useState([]);
    const [SelectPlaceholder, setSelectPlaceholder] = useState('Select a reaction');
    const [alert, setAlert] = useState('');

    useEffect(() => {
        const unsubscribe = navigation.addListener('focus', async () => {
            const fetchedReactionList = await GetReactionsList(setAlert);
            setReactionList(fetchedReactionList);
        });

        return unsubscribe;
    })

    function onChange(value) {
        let reaction = reactionList.data.reactions.find(reaction => reaction.name == value);
        setReactionParams(reaction.params);
    }

    function Submit() {
        let data = {
            "name": title,
            "serviceName": SelectPlaceholder,
            "description": description,
            "params": reactionParams,
        }
        CreateReaction(setAlert, data).then(response => {
            if (response.status == 201 || response.status == 200) {
                navigation.navigate("AppletForm", { action: action, reaction: response.data });
            }
        });
    }

    return (
        <Box justifyContent="center" alignItems="center" minHeight="100%" bg={styles.colorBackground} width={'100%'}>

            {HeaderHalfCircle()}
            {HeaderTitle("Reaction")}
            {IconButton(Undo2, () => { navigation.navigate("Home") })}

            {alert}

            {InputBasic("Title", setTitle, title)}
            {InputBasic("Description", setDescription, description)}

            <SelectReactions
                value={SelectPlaceholder}
                onChange={(value) => {
                    onChange(value);
                    setSelectPlaceholder(value);
                }}
                placeholder={SelectPlaceholder}
                reactionList={reactionList}
            />

            <Text
                color={styles.colorPrimary}
                size="xl"

                bold={true}
                italic={true}

                marginBottom={10}
            >
                Parameters of the reaction
            </Text>

            <FormControl>
                {
                    reactionParams.map(param => (
                        <Box
                            key={param.name}
                            minWidth="80%"
                        >
                            <Input
                                variant={styles.input.variant}
                                bg="$white"
                                marginBottom={10}
                            >
                                <InputField
                                    label={param.name}
                                    placeholder={param.name}
                                    onChangeText={(text) => { param.value = text }}
                                    defaultValue=""
                                    color="$black"
                                />
                            </Input>
                        </Box>
                    ))
                }
            </FormControl>

            {ButtonSubmit(true, Submit, "Create")}
        </Box>
    );
};

export default ReactionForm;
