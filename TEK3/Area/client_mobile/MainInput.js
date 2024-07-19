// import React from 'react';
// import { TextInput, View, TouchableOpacity } from 'react-native';
// import Icon from 'react-native-vector-icons/FontAwesome'; // Importez l'icône appropriée

// export default function MainInput({
//     label,
//     onChange,
//     secureTextEntry,
//     mode = "flat",
//     value,
//     showPasswordToggle = false,
//     onTogglePasswordVisibility,
//     ...props
// }) {
//     return (
//         <View>
//             <TextInput
//                 mode={mode}
//                 label={label}
//                 onChangeText={onChange}
//                 secureTextEntry={secureTextEntry}
//                 value={value}
//                 {...props}
//             />
//             {showPasswordToggle && (
//                 <TouchableOpacity
//                     onPress={onTogglePasswordVisibility}
//                     style={{ position: 'absolute', top: 1, right: -140 }}
//                 >
//                     {/* Utilisez l'icône de l'œil ici */}
//                     <Icon name={secureTextEntry ? 'eye' : 'eye-slash'} size={24} color="#000" />
//                 </TouchableOpacity>
//             )}
//         </View>
//     );
// }