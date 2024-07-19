import React, { useEffect, useState } from 'react';
import { useHistory } from 'react-router-dom';
import { useAuth } from '../AuthContext';
import '../styles/Settings.css';
import InputSettings from '../components/InputSettings';
import GetUserData from '../request/GetUserData';
import UpdateUserData from '../request/UpdateUserData';
import logo from '../assets/logo.png';

const Settings = () => {
  const history = useHistory();
  const { token } = useAuth();
  const [userData, setUserData] = useState(null);
  const [updateSuccess, setUpdateSuccess] = useState(false);

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
    const fetchUserData = async () => {
      try {
        const response = await GetUserData(token);
        const userData = response.data;
        setUserData(userData);
      } catch (error) {
        console.error('Error fetching user data:', error);
      }
    };
    fetchUserData();
  }, [token]);

  const ChangeSettings = async (e) => {
    e.preventDefault();
    try {
      await UpdateUserData(userData, token);
      setUpdateSuccess(true);
    } catch (error) {
      console.error('Error updating user data:', error);
    }
  };

  const updateUserData = (field, value) => {
    setUserData((prevUserData) => ({
      ...prevUserData,
      [field]: value,
    }));
  };

  const goHome = () => {
    history.push('/Dashboard');
  };

  document.body.style.backgroundColor = theme.backgroundColor;
  document.body.style.color = theme.textColor;

  return (
    <div className="settings-container">
      <div className="top-bar" style={{ borderBottom: "3px solid", borderColor: theme.textColor }}>
        <img src={logo} alt="Your Logo" class="logo" />
        <h1 class="settings-title" style={{ color: theme.textColor }}>Settings</h1>
        <button class="btn btn-dashboard" onClick={goHome} style={{ backgroundColor: theme.backgroundColor, borderColor: theme.textColor, color: theme.textColor }}>
          Dashboard
        </button>
      </div>
      <div className="window-settings" style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center', marginTop: "100px" }}>
        {userData ? (
          <form onSubmit={ChangeSettings}>
            <InputSettings defaultText={userData.firstname} header={"Name:"} type={"text"} updateField={(value) => updateUserData('firstname', value)} />
            <InputSettings defaultText={userData.name} header={"Firstname:"} type={"text"} updateField={(value) => updateUserData('name', value)} />
            <InputSettings defaultText={userData.username} header={"Username:"} type={"text"} updateField={(value) => updateUserData('username', value)} />
            <InputSettings defaultText={userData.email} header={"email:"} type={"text"} updateField={(value) => updateUserData('email', value)} />
            <button type="submit" className='Submit-button'>Update user data</button>
            {updateSuccess && <p style={{ color: 'green' }}>Data updated successfully!</p>}
          </form>
        ) : (
          <p>Loading user data...</p>
        )}
      </div>
    </div>
  );
};

export default Settings;
