import onChangeFunction from "./onChange";
import onChange from "./onChange/schema.json";

export default {
    [onChange.name]: onChangeFunction,
}

const list = [
    onChange,
];
export { list };