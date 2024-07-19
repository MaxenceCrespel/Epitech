import axios from 'axios';

export const getGoogleUserData = async (code) => {
  try {
    const response = await axios.get(`/v1/auth/google/callback?code=${code}`);
    return response.data;
  } catch (error) {
    throw error;
  }
};
