import { Box, Button, Text, View, Alert, AlertIcon} from '@gluestack-ui/themed';

import { useState, useContext, useEffect } from 'react';
import { Info,X } from 'lucide-react-native';

import ThemeContext  from '../../../assets/style/themeContext';
import AsyncStorage from '@react-native-async-storage/async-storage';
import AlertError from '../Basics/Alerts/Error';
import GetUserApplets from '../../Middlewares/GetUserApplets';
import ExecuteApplet from '../../Middlewares/ExecuteApplet';
import StopApplet from '../../Middlewares/StopApplet';
import DeleteApplet from '../../Middlewares/DeleteApplet';
import loadStyle from "../../../assets/style/base";

function formatDate(string) {
    var options = { year: 'numeric', month: 'long', day: 'numeric' };
    return new Date(string).toLocaleDateString([], options);
}

export default function AppletList({ navigation}) {
    const styles = loadStyle(useContext(ThemeContext));
    const [applets, setApplets] = useState('');
    const [alert, setAlert] = useState('');
    useEffect(() => {
        const unsubscribe = navigation.addListener('focus', async () => {
            const fetchedApplets = await GetUserApplets();
            setApplets(fetchedApplets);
            // console.log(fetchedApplets);
        });

        return unsubscribe;
    });
    function onPress() {
        setAlert(<Alert
            action="info"
            variant="solid"

            borderRadius={"$full"}

            marginBottom={"$10"}
        ><AlertIcon color={styles.colorThird} as={Info}/><Text> Not implemented yet ! </Text>
        <Button
            action='ghost'
            onPress={() => setAlert('')}
            bg="transparent"
        ><AlertIcon color={styles.colorPrimary} as={X}/></Button>
        </Alert>);
    }

    function start(id) {
        ExecuteApplet(setAlert, id).then(response => {
            if (response.status == 200) {
                console.log("Service started");
            } else {
                console.log("Error while starting service");
            }
        });
    }

    function stop(id) {
        StopApplet(setAlert, id).then(response => {
            if (response.status == 200) {
                console.log("Service stopped");
            } else {
                console.log("Error while stopping service");
            }
        });
    }

    return (
        <Box
            alignItems='center'
            alignContent='center'

            minWidth={300}

            marginBottom={10}
        >
            {alert}

            {applets?.data?.map(applet => (
                <Box
                    key={applet._id}
                    bg={styles.colorPrimary}
                    padding="$2.5"
                >

                    <Text
                        paddingBottom="$1"
                        color={styles.colorThird}
                    >
                        {applet.name} : {applet.description}
                    </Text>

                    <Text
                        paddingBottom="$1"
                        color={styles.colorThird}
                    >
                        Created at : {formatDate(applet.created_at)}
                    </Text>

                    <Box
                        bg={"$green500"}
                        padding="$1"
                        borderRadius="$md"
                        marginBottom={"$1.5"}
                    >
                        <Text
                            color={"$light100"}
                        >
                            Working
                        </Text>
                    </Box>

                    <Button bg={styles.colorBackground} marginBottom={"$1.5"}
                    onPress={
                        () => onPress()
                    }><Text color={styles.colorPrimary}>View more</Text></Button>

                    <Button bg={"$green500"} marginBottom={"$1.5"}
                    onPress={
                        () => start(applet._id)
                    }><Text color={styles.colorPrimary}>Start</Text></Button>

                    <Button bg={"$red500"} marginBottom={"$1.5"}
                    onPress={
                        () => stop(applet._id)
                    }><Text color={styles.colorPrimary}>Stop</Text></Button>

                    <Button bg={"$yellow300"} marginBottom={"$1.5"}
                    onPress={
                        () => onPress()
                    }><Text color={styles.colorPrimary}>Edit</Text></Button>

                    <Button bg={"$red500"} marginBottom={"$1.5"}
                    onPress={
                        () => onPress()
                    }><Text color={styles.colorPrimary}>Delete</Text></Button>
                </Box>
            ))}
        </Box>
    );
}