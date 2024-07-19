// LoginForm.js
import React, { useState } from 'react';
import { useHistory, Link } from 'react-router-dom';
import InputText from '../components/InputText';
import InputPassword from '../components/InputPassword';
import logo from '../assets/logo.png';
import { useAuth } from '../AuthContext';
import '../styles/LoginForm.css';
import { loginUser } from "../request/Login_request";
import GoogleLogin from '../request/GoogleLogin';

function LoginForm() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [showPassword, setShowPassword] = useState(false);
  const history = useHistory();
  const { login } = useAuth();
  const [errorMessage, setErrorMessage] = useState('');

  const getStoredTheme = () => {
    const savedBackgroundColor = localStorage.getItem('backgroundColor');
    const savedTextColor = localStorage.getItem('textColor');
    return {
      backgroundColor: savedBackgroundColor || 'white',
      textColor: savedTextColor || 'black',
    };
  };

  const [theme, setTheme] = useState(getStoredTheme);

  const handleEmailChange = (e) => {
    setEmail(e.target.value);
  };

  const handlePasswordChange = (e) => {
    setPassword(e.target.value);
  };

  const handleTogglePasswordVisibility = () => {
    setShowPassword(!showPassword);
  };

  const handleLogin = async (e) => {
    e.preventDefault();
    try {
      const response = await loginUser(email, password);
      const { token } = response;
      login(token);
      history.push('/Dashboard');
    } catch (error) {
      setErrorMessage('Adresse e-mail ou mot de passe incorrect.');
    }
    setEmail('');
    setPassword('');
  };

  const handleGoogleLogin = async (e) => {
    GoogleLogin(e);
  };

  document.body.style.backgroundColor = theme.backgroundColor;
  document.body.style.color = theme.textColor;

  return (
    <div className="login-container">
      <img src={logo} alt="Logo" className="mb-3" width="100" height="100" />
      <h2>AreApp</h2>
      <form onSubmit={handleLogin}>
        <InputText
          id="email"
          label="Email"
          placeholder="Email"
          value={email}
          onChange={handleEmailChange}
        />
        <InputPassword
          id="password"
          label="Mot de passe"
          value={password}
          placeholder="Password"
          onChange={handlePasswordChange}
          showPassword={showPassword}
          onTogglePasswordVisibility={handleTogglePasswordVisibility}
        />
        <button type="submit" className="btn_submit">
          Login
        </button>
        <button type="button" className="btn_submit_google" onClick={handleGoogleLogin}>
          Login Google
        </button>
      </form>
      {errorMessage && <p style={{ marginTop: '40px', color: "white" }} className="error-message">{errorMessage}</p>}
      <p className="text-center" style={{color: "white"}}>
        New on AreaApp ?{' '}
        <Link to="/RegistrationForm" style={{ textDecoration: "none", color: "inherit" }}>Register</Link>
      </p>
      <div className="line"></div>
    </div>
  );
}

export default LoginForm;
