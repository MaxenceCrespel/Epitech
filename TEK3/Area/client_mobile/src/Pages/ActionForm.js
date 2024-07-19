import { Box, Button, Select, SelectItem, SelectContent, SelectPortal, SelectInput, SelectTrigger, SelectDragIndicator, SelectBackdrop, SelectDragIndicatorWrapper, SelectIcon, Text, Icon, Input, InputField, FormControl, ButtonText, set } from "@gluestack-ui/themed";
import { useContext, useState, useEffect } from "react";

import loadStyle from "../../assets/style/base";
import ThemeContext, { useTheme } from "../../assets/style/themeContext";

import InputBasic from "../Components/Basics/Inputs/Basic";

import HeaderHalfCircle from "../Components/Basics/Headers/HalfCircle";
import HeaderTitle from "../Components/Basics/Headers/Title";

import IconButton from "../Components/Basics/Buttons/IconButton";
import { Undo2, ChevronDown } from "lucide-react-native";

import ButtonSubmit from "../Components/Basics/Buttons/Submit";

import SelectActions from "../Components/Basics/Selects/Actions";

import AlertError from "../Components/Basics/Alerts/Error";

import GetActionList from "../Middlewares/GetActionsList";
import CreateAction from "../Middlewares/CreateAction";

const ActionForm = ({ navigation }) => {
    const styles = loadStyle(useContext(ThemeContext));
    const [title, setTitle] = useState('title');
    const [description, setDescription] = useState('description');
    const [actionList, setActionList] = useState([]);
    const [actionParameters, setActionParameters] = useState({});
    const [SelectPlaceholder, setSelectPlaceholder] = useState('Select an action');
    const [alert, setAlert] = useState('');

    useEffect(() => {
        const unsubscribe = navigation.addListener('focus', async () => {
            const fetchedActionList = await GetActionList(setAlert);
            // console.log(fetchedActionList.data.actions);
            setActionList(fetchedActionList);
        });

        return unsubscribe;
    })

    function onChange(value) {
        let action = actionList.data.actions.find(action => action.name === value);
        setActionParameters(action.params);
    }

    function Submit() {
        let data = {
            "name": title,
            "serviceName": SelectPlaceholder,
            "description": description,
            "params": actionParameters
        }
        CreateAction(setAlert, data).then(response => {
            if (response.status == 201 || response.status == 200) {
                navigation.navigate("ReactionForm", { action: response.data });
            } else {
                setAlert(AlertError("Error while creating action"));
            }
        });
    }

    return (
        <Box justifyContent="center" alignItems="center" minHeight="100%" bg={styles.colorBackground} width={'100%'}>
            {alert}
            {HeaderHalfCircle()}
            {HeaderTitle("Action")}
            {IconButton(Undo2, () => { navigation.navigate("Home") })}
            {InputBasic("Title", setTitle, title)}
            {InputBasic("Description", setDescription, description)}

            <SelectActions
                value={SelectPlaceholder}
                onChange={(value) => {
                    onChange(value);
                    setSelectPlaceholder(value);
                }}
                placeholder={SelectPlaceholder}
                actionList={actionList}
            />

            <Text
                color={styles.colorPrimary}
                size="xl"

                bold={true}
                italic={true}

                marginBottom={10}
            >
                Parameters of the action
            </Text>

            <FormControl>
                {Object.keys(actionParameters).map(parameter => (
                    <Box
                        key={parameter}
                        minWidth="80%"
                    >
                        <Input
                            variant={styles.input.variant}
                            bg="$white"
                            marginBottom={10}
                        >
                            <InputField
                                placeholder={parameter + " " + (actionParameters[parameter].required ? "*" : "")}
                                defaultValue=""
                                onChangeText={newString => setActionParameters({
                                    ...actionParameters, [parameter]: {
                                        ...actionParameters[parameter],
                                        value: newString
                                    }
                                })}
                                color="$black"
                            />
                        </Input>
                    </Box>
                ))}
                {ButtonSubmit(true, Submit, "Create")}
            </FormControl>

        </Box>
    );
};

export default ActionForm;
