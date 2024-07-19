import React, { useState } from 'react';
import { useHistory, Link } from 'react-router-dom';
import InputText from '../components/InputText';
import InputPassword from '../components/InputPassword';
import logo from '../assets/logo.png';
import '../styles/RegistrationForm.css';
import { RegisterUser } from '../request/Register_request';
import { loginUser } from '../request/Login_request';
import { useAuth } from '../AuthContext';

const RegistrationForm = () => {
  const history = useHistory();
  const { login } = useAuth();
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [password_bis, setPassword_bis] = useState('');
  const [name, setName] = useState('');
  const [username, setUsername] = useState('');
  const [firstname, setFirstname] = useState('');
  const [showPassword, setShowPassword] = useState(false);
  const [showPasswordconfirmation, setShowPasswordconfirmation] = useState(false);

  const getStoredTheme = () => {
    const savedBackgroundColor = localStorage.getItem('backgroundColor');
    const savedTextColor = localStorage.getItem('textColor');
    return {
      backgroundColor: savedBackgroundColor || 'white',
      textColor: savedTextColor || 'black',
    };
  };

  const [theme, setTheme] = useState(getStoredTheme);

  const handleTogglePasswordconfirmationVisibility = () => {
    setShowPasswordconfirmation(!showPasswordconfirmation);
  };

  const handleTogglePasswordVisibility = () => {
    setShowPassword(!showPassword);
  };

  const handleEmailChange = (e) => {
    setEmail(e.target.value);
  };

  const handlePasswordChange = (e) => {
    setPassword(e.target.value);
  };

  const handlePassword_bisChange = (e) => {
    setPassword_bis(e.target.value);
  };

  const handleNameChange = (e) => {
    setName(e.target.value);
  };

  const handleUsernameChange = (e) => {
    setUsername(e.target.value);
  };

  const handleFirstnameChange = (e) => {
    setFirstname(e.target.value);
  };

  const handleRegistrationForm = async (e) => {
    e.preventDefault();
    if (password === password_bis) {
      await RegisterUser(name, email, password, username, firstname);
      const response = await loginUser(email, password);
      const { token } = response;
      login(token);
      history.push('/Dashboard');
    } else {
      console.log('Le mot de passe et la confirmation du mot de passe doivent être identiques');
    }
  };

  document.body.style.backgroundColor = theme.backgroundColor;
  document.body.style.color = theme.textColor;

  return (
    <div className="create-container">
      <img src={logo} alt="Logo" className="logo" width="100" height="100" />
      <h2 className="header">Account creation</h2>
      <form onSubmit={handleRegistrationForm}>
        <InputText
          id="name"
          label="Nom"
          placeholder="Name"
          value={name}
          onChange={handleNameChange}
          required
        />
        <InputText
          id="firstname"
          label="Prénom"
          placeholder="Firstname"
          value={firstname}
          onChange={handleFirstnameChange}
          required
        />
        <InputText
          id="username"
          label="Nom d'utilisateur"
          placeholder="Username"
          value={username}
          onChange={handleUsernameChange}
          required
        />
        <InputText
          id="email"
          label="Email"
          placeholder="Email"
          value={email}
          onChange={handleEmailChange}
          required
        />
        <InputPassword
          id="password"
          label="Mot de passe"
          placeholder="Password"
          value={password}
          onChange={handlePasswordChange}
          showPassword={showPassword}
          onTogglePasswordVisibility={handleTogglePasswordVisibility}
          required
        />
        <InputPassword
          id="password-confirmation"
          label="Confirmer mot de passe"
          placeholder="Confirm your password"
          value={password_bis}
          onChange={handlePassword_bisChange}
          showPassword={showPasswordconfirmation}
          onTogglePasswordVisibility={handleTogglePasswordconfirmationVisibility}
          required
        />
        <button type="submit" className="btn_submit">
          Create my account
        </button>
      </form>
      <p className="text-center" style={{color: "white"}}>
        Already have an account? <Link to="/" style={{ textDecoration: "none", color: "inherit" }}>Login here</Link>
      </p>
    </div>
  );
};

export default RegistrationForm;
