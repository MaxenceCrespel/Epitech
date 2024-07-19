import React, { useEffect, useState } from 'react';
import GetActionList from '../components/GetActionList';
import "../styles/Action.css"
import { useAuth } from '../AuthContext';
import { useHistory } from 'react-router-dom';
import InputSettings from '../components/InputSettings';
import CreateAction from '../components/CreateAction'
import logo from '../assets/logo.png';

const Action_form = () => {
    const [actionList, setActionList] = useState([]);
    const [selectedAction, setSelectedAction] = useState(null);
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
        GetActionList(token)
            .then(responseData => {
                if (responseData.status === 200) {
                    setActionList(responseData.data.actions);
                } else {
                    console.error('Error fetching action list');
                }
            })
            .catch(error => {
                console.error('Error fetching action list:', error);
            });
    }, [token]);

    const handleActionClick = (action) => {
        setSelectedAction(action);
    };

    const changeName = (e) => {
        setName(e);
    }

    const changeDescription = (e) => {
        setDescription(e);
    }

    function Action(e) {
        e.preventDefault();
        if (selectedAction) {
            const updatedParamsObject = {};
            for (const paramName in selectedAction.params) {
                updatedParamsObject[paramName] = selectedAction.params[paramName].value;
            }
            const data = {
                name: Name,
                serviceName: selectedAction.name,
                description: Description,
                params: [updatedParamsObject],
            };
            CreateAction(data, token)
                .then(responseData => {
                    localStorage.setItem('actionId', responseData.data.action._id);
                    history.push('/Reaction');
                })
                .catch(error => {
                    console.error('Error from CreateAction:', error);
                });
        }
    }

    document.body.style.backgroundColor = theme.backgroundColor;
    document.body.style.color = theme.textColor;

    return (
        <div className='action-container'>
            <div class="top-bar" style={{ borderBottom: "3px solid", borderColor: theme.textColor }}>
                <img src={logo} alt="Your Logo" class="logo" />
                <h1 class="action-title" style={{ color: theme.textColor, marginRight: "50%" }}>Action</h1>
            </div>
            <div className="window">
                <div className="action-list">
                    <div className="available-actions-container">
                        {Array.isArray(actionList) ? (
                            actionList.map((action, index) => (
                                <div
                                    key={index}
                                    onClick={() => handleActionClick(action)}
                                    className={`available-action ${selectedAction === action ? 'selected' : ''}`}
                                >
                                    {action.name.replace(/_/g, ' ')}
                                </div>
                            ))
                        ) : (
                            <p>No actions available.</p>
                        )}
                    </div>
                </div>
                <div className="selected-action" style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center' }}>
                    {selectedAction && (
                        <div>
                            <InputSettings defaultText={''} header={"Name:"} type={'text'} updateField={(value) => changeName(value)} />
                            <InputSettings defaultText={''} header={"Description:"} type={'text'} updateField={(value) => changeDescription(value)} />
                            {selectedAction.params && (
                                <div>
                                    <h3>Parameters:</h3>
                                    <ul>
                                        {Object.keys(selectedAction.params).map(paramName => (
                                            <div key={paramName}>
                                                <InputSettings defaultText={''} header={paramName} type={"text"} updateField={(value) => {
                                                    setSelectedAction({
                                                        ...selectedAction,
                                                        params: {
                                                            ...selectedAction.params,
                                                            [paramName]: {
                                                                ...selectedAction.params[paramName],
                                                                value: value
                                                            }
                                                        }
                                                    });
                                                }} />
                                            </div>
                                        ))}
                                    </ul>
                                </div>
                            )}
                            <button style={{ visibility: selectedAction ? 'visible' : 'hidden' }} className='action-button' onClick={Action}>
                                Call Action
                            </button>
                        </div>
                    )}
                </div>
            </div>
        </div>
    );
};

export default Action_form;
