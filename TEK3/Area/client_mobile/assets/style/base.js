import { StyleSheet } from "react-native";

const loadStyle = ({theme, setTheme}) => {

    return (StyleSheet.create({
        colorBackground: (theme == 'light') ? "$light200" : "$light900",
        colorPrimary: (theme == 'light') ? "#390038" : "#800080",
        colorSecondary: (theme == 'light') ? "#AF7BBD" : "#FF00FF",
        colorThird: (theme == 'light') ? "#FF4444" : "red",
        colorFourth: (theme == 'light') ? "black" : "white",

        input: {
            variant: "rounded",
            size: "md"
        },

        viewButtonChangeTheme: {
            position: 'absolute',
            top: 15,
            right: -15
        },
    }));
};

export default loadStyle;