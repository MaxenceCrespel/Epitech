import React, { useEffect, useState } from 'react';
import GetReactionList from '../components/GetReactionList';
import "../styles/Reaction.css"
import { useAuth } from '../AuthContext';
import { useHistory } from 'react-router-dom';
import InputSettings from '../components/InputSettings';
import CreateReaction from '../components/CreateReaction';
import logo from '../assets/logo.png';

const Reaction_form = () => {
    const [ReactionList, setReactionList] = useState([]);
    const [selectedReaction, setSelectedReaction] = useState(null);
    const [Name, setName] = useState('');
    const [Description, setDescription] = useState('');
    const { token } = useAuth();
    const history = useHistory();

    const getStoredTheme = () => {
        const savedBackgroundColor = localStorage.getItem('backgroundColor');
        const savedTextColor = localStorage.getItem('textColor');
        return {
            backgroundColor: savedBackgroundColor || 'white',
            textColor: savedTextColor || 'black',
        };
    };
    const [theme, setTheme] = useState(getStoredTheme);

    useEffect(() => {
        GetReactionList(token)
            .then(responseData => {
                if (responseData.status === 200) {
                    setReactionList(responseData.data.reactions);
                } else {
                    console.error('Error fetching Reaction list');
                }
            })
            .catch(error => {
                console.error('Error fetching Reaction list:', error);
            });
    }, [token]);

    const handleReactionClick = (Reaction) => {
        setSelectedReaction(Reaction);
    };

    const changeName = (e) => {
        setName(e);
    }

    const changeDescription = (e) => {
        setDescription(e);
    }

    function Reaction(e) {
        e.preventDefault();
        if (selectedReaction) {
            const updatedParamsObject = {};
            const updatedParamsArray = Object.keys(selectedReaction.params).map(paramName => ({
                url: selectedReaction.params[paramName].value,
            }));
            const data = {
                name: Name,
                serviceName: selectedReaction.name,
                description: Description,
                params: updatedParamsArray,
            };
            CreateReaction(data, token)
                .then(responseData => {
                    localStorage.setItem('reactionId', responseData.data._id);
                    history.push('/Applet');
                })
                .catch(error => {
                    console.error('Error from CreateReaction:', error);
                });
        }
    }

    document.body.style.backgroundColor = theme.backgroundColor;
    document.body.style.color = theme.textColor;

    return (
        <div className='reaction-container'>
            <div class="top-bar" style={{ borderBottom: "3px solid", borderColor: theme.textColor }}>
                <img src={logo} alt="Your Logo" class="logo" />
                <h1 class="action-title" style={{ color: theme.textColor, marginRight: "50%" }}>Reaction</h1>
            </div>
            <div className="window">
                <div className="reaction-list">
                    <div className='available-reactions-container'>
                        {Array.isArray(ReactionList) ? (
                            ReactionList.map((Reaction, index) => (
                                <div key={index}
                                    onClick={() => handleReactionClick(Reaction)}
                                    className={`available-reaction ${selectedReaction === Reaction ? 'selected' : ''}`}>
                                    {Reaction.name.replace(/_/g, ' ')}
                                </div>
                            ))
                        ) : (
                            <p>No Reactions available.</p>
                        )}
                    </div>
                </div>
                <div className="selected-reaction" style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center' }}>
                {selectedReaction && (
                    <div>
                        <InputSettings defaultText={''} header={"Name:"} type={'text'} updateField={(value) => changeName(value)}></InputSettings>
                        <InputSettings defaultText={''} header={"Description:"} type={'text'} updateField={(value) => changeDescription(value)}></InputSettings>
                        {selectedReaction.params && (
                            <div>
                                <h3>Parameters:</h3>
                                <ul>
                                    {Object.keys(selectedReaction.params).map(paramName => (
                                        <div key={paramName}>
                                            <InputSettings defaultText={''} header={selectedReaction.description} type={"text"} updateField={(value) => {
                                                setSelectedReaction((prevState) => ({
                                                    ...prevState,
                                                    params: {
                                                        ...prevState.params,
                                                        [paramName]: {
                                                            ...prevState.params[paramName],
                                                            value: value
                                                        }
                                                    }
                                                }));
                                            }}
                                            ></InputSettings>
                                        </div>
                                    ))}
                                </ul>
                            </div>
                        )}
                        <button className='reaction-button' style={{ visibility: selectedReaction ? 'visible' : 'hidden' }} onClick={Reaction}>
                            Call Reaction
                        </button>
                    </div>
                )}
                </div>
            </div>
        </div>
    );
};

export default Reaction_form;
