import React from 'react';

function InputText({ id, value, onChange, placeholder }) {
    return (
        <div className="form-group">
            <input
                type="text"
                id={id}
                className="input-field"
                placeholder={placeholder}
                value={value}
                onChange={onChange}
                required
            />
        </div>
    );
}

export default InputText;
