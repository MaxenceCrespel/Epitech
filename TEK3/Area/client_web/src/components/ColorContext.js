import React, { createContext, useContext, useState } from 'react';

const ColorContext = createContext();

export const useColor = () => {
  return useContext(ColorContext);
};

export const ColorProvider = ({ children }) => {
  const [backgroundColor, setBackgroundColor] = useState('white');
  const [textColor, setTextColor] = useState('black');

  return (
    <ColorContext.Provider value={{ backgroundColor, textColor, setBackgroundColor, setTextColor }}>
      {children}
    </ColorContext.Provider>
  );
};
