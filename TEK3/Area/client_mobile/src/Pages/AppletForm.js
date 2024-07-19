import InputBasic from "../Components/Basics/Inputs/Basic";

import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";

import IconButton from "../Components/Basics/Buttons/IconButton";

import { Box, Button, ScrollView, Select, SelectItem, SelectContent, SelectPortal, SelectInput, SelectTrigger, SelectDragIndicator, SelectBackdrop, SelectDragIndicatorWrapper, SelectIcon, Text, Icon, FormControl, ButtonText, set, Input, InputField } from "@gluestack-ui/themed";
import { Undo2, ChevronDown } from "lucide-react-native";

import AsyncStorage from "@react-native-async-storage/async-storage";

import loadStyle from "../../assets/style/base";
import ThemeContext, { useTheme } from "../../assets/style/themeContext";

import { useContext, useState, useEffect, Fragment } from "react";

import ButtonSubmit from "../Components/Basics/Buttons/Submit";

import GetActionList from "../Middlewares/GetActionsList";
import GetReactionsList from "../Middlewares/GetReactionsList";

import GetAvailableActions from "../Middlewares/GetAvailableActions";
import GetAvailableReactions from "../Middlewares/GetAvailableReactions";

import CreateApplet from "../Middlewares/CreateApplet";

const AppletForm = ({ route, navigation }) => {
    const action = route.params.action;
    const reaction = route.params.reaction;

    const styles = loadStyle(useContext(ThemeContext));

    const [title, setTitle] = useState('title');
    const [description, setDescription] = useState('description');

    const [actionList, setActionList] = useState([]);
    const [reactionList, setReactionList] = useState([]);
    const [appletParams, setAppletParams] = useState([]);
    const [ActionSelectPlaceholder, setActionSelectPlaceholder] = useState('Select an action');
    const [ReactionSelectPlaceholder, setReactionSelectPlaceholder] = useState('Select a reaction');

    const [frequency, setFrequency] = useState('');

    const [user, setUser] = useState('');
    const [alert, setAlert] = useState('');

    useEffect(() => {
        const unsubscribe = navigation.addListener('focus', async () => {
            const savedUser = await AsyncStorage.getItem("user");

            if (savedUser) {
                setUser(JSON.parse(savedUser));

                const fetchedActionList = await GetAvailableActions(setAlert);
                const fetchedReactionList = await GetAvailableReactions(setAlert);

                setActionList(fetchedActionList);
                setReactionList(fetchedReactionList);
            } else {
                navigation.navigate("Login");
            }
        });

        return unsubscribe;
    })

    function Submit() {
        let requestFrequency = frequency + " seconds";

        let selectedAction = actionList.data.find(action => action.name == ActionSelectPlaceholder);
        let selectecReaction = reactionList.data.find(reaction => reaction.name == ReactionSelectPlaceholder);

        let actionID = [selectedAction._id];
        let reactionID = [selectecReaction._id];

        let data = {
            "name": title,
            "description": description,
            "actions": actionID,
            "reactions": reactionID,
            "frequency": requestFrequency,
            "functionName": "on_change_on_action",
            "user": user._id,
        }

        CreateApplet(setAlert, data).then(response => {
            if (response.status == 201 || response.status == 200) {
                navigation.navigate("Home");
            } else {
                console.log(response)
            }
        });
    }

    return (
        <Box justifyContent="center" alignItems="center" minHeight="100%" bg={styles.colorBackground} width={'100%'}>
            {alert}
            {HeaderHalfCircle()}
            {HeaderTitle("Applet")}
            {IconButton(Undo2, () => { navigation.navigate("Home") })}
            {InputBasic("Title", setTitle, title)}
            {InputBasic("Description", setDescription, description)}

            <Select
                w="50%"
                paddingBottom={10}
                onValueChange={
                    (value) => {
                        setActionSelectPlaceholder(value);
                    }
                }
            >

                <SelectTrigger variant="outline" size="md" >
                    <Text
                        marginLeft={10}
                    >
                        {ActionSelectPlaceholder}
                    </Text>

                    <SelectIcon
                        mr="$3"
                    >
                        <Icon as={ChevronDown} />
                    </SelectIcon>
                </SelectTrigger>

                <SelectPortal>
                    <SelectBackdrop />

                    <SelectContent>

                        <SelectDragIndicatorWrapper>
                            <SelectDragIndicator />
                        </SelectDragIndicatorWrapper>

                        {actionList?.data?.map(action => (
                            <SelectItem key={action.id} label={action.name} value={action.name} />
                        ))}

                    </SelectContent>

                </SelectPortal>
            </Select>

            <Select
                w="50%"
                paddingBottom={10}

                onValueChange={
                    (value) => {
                        setReactionSelectPlaceholder(value);
                    }
                }
            >

                <SelectTrigger variant="outline" size="md" >
                    <Text
                        marginLeft={10}
                    >
                        {ReactionSelectPlaceholder}
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

                        {reactionList?.data?.map(reaction => (
                            <SelectItem key={reaction.id} label={reaction.name} value={reaction.name} />
                        ))}

                    </SelectContent>

                </SelectPortal>
            </Select>

            <Text color={styles.colorPrimary} size="xl" bold={true} italic={true} marginBottom={10}>
                Parameters of the Applet
            </Text>

            {InputBasic("Frequency (in seconds)", setFrequency)}

            {ButtonSubmit(true, Submit, "Create")}

        </Box>
    );
};

export default AppletForm;
