import axios from "axios";

export default async function CreateAction(data, Token) {
  try {
    const { name, serviceName, description, params } = data;
    let requestData = {
      name,
      serviceName,
      description,
      params: params,
    };
    let requestUrl = 'http://localhost:8080/v1/actions/';
    if (Token) {
      const config = {
        method: "post",
        maxBodyLength: Infinity,
        url: requestUrl,
        headers: {
          Authorization: `Bearer ${Token}`,
        },
        data: requestData,
      };
      try {
        let response = await axios.request(config);
        console.log(response.data)
        return {
          status: response.status,
          data: response.data,
        };
      } catch (error) {
        if (error.response === undefined) {
          return {
            status: 500,
          };
        } else {
          return {
            status: error.response.status,
          };
        }
      }
    } else {
      return {
        status: 403,
      };
    }
  } catch (error) {
    console.log(error);
  }
}
