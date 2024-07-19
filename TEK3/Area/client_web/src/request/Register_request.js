import axios from "axios";

axios.defaults.baseURL = 'http://localhost:8080/';

export const RegisterUser = async (name, email, password, username, firstname) => {
    try {
        console.log(name, email, password, username, firstname)
        await axios.post('v1/users/', {
            name,
            email,
            password,
            username,
            firstname,
        });
    } catch (error) {
        console.error('Erreur lors de la création du compte :', error);
    }
};