import axios from 'axios';

axios.defaults.baseURL = 'http://localhost:8080/';

export const loginUser = async (email, password) => {
    try {
        const response = await axios.post('/v1/auth/login', {
            email: email,
            password: password,
        });
        return response.data;
    } catch (error) {
        throw error;
    }
};
