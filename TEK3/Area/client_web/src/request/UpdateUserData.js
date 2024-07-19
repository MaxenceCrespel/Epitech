import axios from 'axios';

async function UpdateUserData(userData, token) {
  try {
    const response = await axios.put(`/v1/users/${userData._id}`, userData, {
      headers: {
        Authorization: `Bearer ${token}`,
      },
    });
    return response.data;
  } catch (error) {
    console.error('Error updating user data:', error);
    throw error;
  }
}

export default UpdateUserData;