import React, { useEffect, useState } from 'react';
import "../styles/Applet.css"
import { useAuth } from '../AuthContext';
import { useHistory } from 'react-router-dom';
import GetApplets from '../components/GetApplets';
import CreateApplet from '../components/CreateApplet';
import ExecuteApplet from '../components/ExecuteApplet'
import StopApplet from '../components/StopApplet'
import InputSettings from '../components/InputSettings';
import GetUserData from '../request/GetUserData';
import logo from '../assets/logo.png';

const Applet = () => {
    const { token } = useAuth();
    const history = useHistory();
    const [Name, setName] = useState('');
    const [Description, setDescription] = useState('');
    const [Frequency, setFrequency] = useState('');
    const actionId = localStorage.getItem('actionId');
    const reactionId = localStorage.getItem('reactionId');
    const [userData, setUserData] = useState(null);

    const getStoredTheme = () => {
        const savedBackgroundColor = localStorage.getItem('backgroundColor');
        const savedTextColor = localStorage.getItem('textColor');
        return {
            backgroundColor: savedBackgroundColor || 'white',
            textColor: savedTextColor || 'black',
        };
    };
    const [theme, setTheme] = useState(getStoredTheme);

    function Applet(e) {
        e.preventDefault();
        if (actionId && reactionId && userData) {
            let data = {
                name: Name,
                description: Description,
                actions: [actionId],
                reactions: [reactionId],
                frequency: Frequency + " seconds",
                functionName: "on_change_on_action",
                user: userData._id,
            };
            CreateApplet(data, token)
                .then(responseData => {
                    localStorage.setItem('appletId', responseData);
                    history.push('/Dashboard');
                })
                .catch(error => {
                    console.error('Error from CreateApplet:', error);
                });
        }
    }
    useEffect(() => {
        if (token && !userData) {
            GetUserData(token)
                .then((response) => {
                    if (response.status === 200) {
                        setUserData(response.data);
                    } else {
                        console.error('Erreur lors de la récupération des données de l\'utilisateur.');
                    }
                })
                .catch((error) => {
                    console.error('Erreur lors de la récupération des données de l\'utilisateur.', error);
                });
        }
    });

    return (
        <div className='applet-container'>
            <div class="top-bar" style={{ borderBottom: "3px solid", borderColor: theme.textColor }}>
                <img src={logo} alt="Your Logo" class="logo" />
                <h1 class="action-title" style={{ color: theme.textColor, marginRight: "50%" }}>Applet</h1>
            </div>
            <div className="window">
                <form onSubmit={Applet} style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center', marginTop: "100px"}}>
                    <InputSettings defaultText={''} header={"Name:"} type={"text"} updateField={(value) => setName(value)}></InputSettings>
                    <InputSettings defaultText={''} header={"Description:"} type={"text"} updateField={(value) => setDescription(value)}></InputSettings>
                    <InputSettings defaultText={''} header={"Frequency (in seconds):"} type={"text"} updateField={(value) => setFrequency(value)}></InputSettings>
                    <button type="submit" className=''>Create the Applet</button>
                </form>
            </div>
        </div>
    );
}

export default Applet;