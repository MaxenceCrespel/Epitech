import React, { useEffect, useState } from 'react';
import { useHistory } from 'react-router-dom';
import { useAuth } from '../AuthContext';
import '../styles/Dashboard.css';
import GetUserData from '../request/GetUserData';
import GetApplets from '../components/GetApplets';
import ExecuteApplet from '../components/ExecuteApplet';
import StopApplet from '../components/StopApplet';
import logo from '../assets/logo.png';
import { getGoogleUserData } from '../request/GoogleCallback';

const Dashboard = () => {
  const history = useHistory();
  const [userData, setUserData] = useState(null);
  const { token, login } = useAuth();
  const [backgroundColor, setBackgroundColor] = useState('white');
  const [textColor, setTextColor] = useState('black');
  const [AppletsList, setAppletsList] = useState([]);

  const goSettings = () => {
    history.push('/Settings');
  };

  const goAction = () => {
    history.push('/Action');
  };

  const changeBackgroundColor = () => {
    const newBackgroundColor = backgroundColor === 'black' ? 'white' : 'black';
    setBackgroundColor(newBackgroundColor);
    localStorage.setItem('backgroundColor', newBackgroundColor);
    const newTextColor = textColor === 'white' ? 'black' : 'white';
    setTextColor(newTextColor);
    localStorage.setItem('textColor', newTextColor);
    document.body.style.backgroundColor = newBackgroundColor;
  };

  useEffect(() => {
    if (token && !userData) {
      GetUserData(token)
        .then((response) => {
          if (response.status === 200) {
            setUserData(response.data);
          } else {
            console.error("Erreur lors de la récupération des données de l'utilisateur.");
          }
        })
        .catch((error) => {
          console.error("Erreur lors de la récupération des données de l'utilisateur.", error);
        });
    }
    const savedBackgroundColor = localStorage.getItem('backgroundColor');
    const savedTextColor = localStorage.getItem('textColor');
    if (savedBackgroundColor) {
      setBackgroundColor(savedBackgroundColor);
      document.body.style.backgroundColor = savedBackgroundColor;
    }
    if (savedTextColor) {
      setTextColor(savedTextColor);
    }
    handleGoogleCallback();
  }, [token, userData]);

  useEffect(() => {
    GetApplets(token)
      .then((responseData) => {
        if (responseData.status === 200) {
          setAppletsList(responseData.data);
        } else {
          console.error('Error fetching action list');
        }
      })
      .catch((error) => {
        console.error('Error fetching action list:', error);
      });
  }, [token]);

  function start(id) {
    ExecuteApplet(id, token).then((response) => {
      if (response.status === 200) {
        console.log('Service started: ', response);
      } else {
        console.log('Error while starting service');
      }
    });
  }

  function stop(id) {
    StopApplet(id, token).then((response) => {
      if (response.status === 200) {
        console.log('Service stopped: ', response);
      } else {
        console.log('Error while stopping service');
      }
    });
  }

  const handleGoogleCallback = async () => {
    try {
      const urlParams = new URLSearchParams(window.location.search);
      const code = urlParams.get('code');
      if (code) {
        const Response = await getGoogleUserData(code);
        const userData = Response.user;
        const token = Response.token
        login(token);
      } else {
        console.log("error");
      }
    } catch (error) {
      console.error('Error fetching user data from Google:', error);
    }
  };

  return (
    <div>
      <div class="dashboard-container" style={{ backgroundColor: backgroundColor }}>
        <div class="top-bar" style={{ borderBottom: "3px solid", borderColor: textColor }}>
          <img src={logo} alt="Your Logo" class="logo" />
          <h1 class="dashboard-title" style={{ color: textColor }}>Dashboard</h1>
          <div>
            <button class="btn btn-settings" onClick={goSettings} style={{ backgroundColor: backgroundColor, borderColor: textColor, color: textColor }}>
              Settings
            </button>
            <button
              class="btn btn-dark-theme"
              onClick={changeBackgroundColor}
              style={{ backgroundColor: backgroundColor, borderColor: textColor, color: textColor }}
            >
            {backgroundColor === 'white' ? 'Dark theme' : 'Light theme'}
            </button>
          </div>
        </div>
        <div class="window-dashboard">
          <h1 class="welcome-text" style={{ color: textColor, backgroundColor: backgroundColor }}>
            Welcome {userData ? userData.firstname : ''}
          </h1>
          <button onClick={goAction} class="btn-action">
            Create an applet
          </button>
          {AppletsList.length === 0 ? (
            <p class="no-applets" style={{ color: textColor, fontFamily: 'Roboto, sans-serif' }}>No applet yet</p>
          ) : (
            <div class="applets-container">
              {AppletsList.map((applet, index) => (
                <div key={index} class="applet-rectangle" style={{ backgroundColor: backgroundColor, borderColor: textColor, color: textColor }}>
                  <h2>{applet.name}</h2>
                  <p>{applet.description}</p>
                  <button class="start-button" onClick={() => start(applet._id)}>
                    Start
                  </button>
                  <button class="stop-button" onClick={() => stop(applet._id)}>
                    Stop
                  </button>
                </div>
              ))}
            </div>
          )}
        </div>
      </div>
    </div>
  );
};

export default Dashboard;
