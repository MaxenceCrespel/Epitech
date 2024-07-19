import React, { useState } from 'react';


function InputSettings({ defaultText, header, type, updateField }) {
  const [inputValue, setInputValue] = useState(defaultText);

  const handleInputChange = (e) => {
    const newValue = e.target.value;
    setInputValue(newValue);
    updateField(newValue);
  };

  return (
    <div>
      <div style={{ display: 'flex', alignItems: 'center' }}>
        <div
          style={{
            textAlign: "center",
            position: 'relative',
            left: '0%',
            width: '300px',
            height: '50px',
            backgroundColor: '#2CB252',
            color: 'white',
            padding: '10px',
            borderTopLeftRadius: '10px',
            borderBottomLeftRadius: '10px',
          }}
        >
          <p>{header}</p>
        </div>
        <input
          type={type}
          id="inputField"
          value={inputValue}
          onChange={handleInputChange}
          style={{
            position: 'relative',
            left: '0%',
            width: '300px',
            height: '50px',
            color: '#390038',
            padding: '10px',
            borderTopRightRadius: '10px',
            borderBottomRightRadius: '10px',
          }}
        />
      </div>
      <div style={{
        position: 'relative',
        left: '10%',
        width: '60%',
        border: '1px solid black',
        margin: '20px 0'
      }}></div>
    </div>
  );
}

export default InputSettings;
