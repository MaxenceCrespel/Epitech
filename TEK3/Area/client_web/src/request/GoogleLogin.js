import axios from 'axios';

axios.defaults.baseURL = 'http://localhost:8080/';

const GoogleLogin = async (e) => {
  e.preventDefault();
  try {
    const response = await axios.get('/v1/auth/google');
    window.location.href = response.data.url;
  } catch (error) {
    console.error('Erreur lors de l\'authentification Google:', error);
  }
};

export default GoogleLogin;
