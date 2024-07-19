import React from 'react';

function InputPassword({ id, value, onChange, showPassword, onTogglePasswordVisibility, placeholder }) {
    return (
        <div className="form-group">
            <div className="input-group">
                <input
                    type={showPassword ? 'text' : 'password'}
                    id={id}
                    className="input-field"
                    placeholder={placeholder}
                    value={value}
                    onChange={onChange}
                    required
                />
                <div className="input-group-append">
                    <button
                        type="button"
                        className="btn_visibility"
                        onClick={onTogglePasswordVisibility}
                    >
                        {showPassword ? '👁️' : '👁️‍🗨️'}
                    </button>
                </div>
            </div>
        </div>
    );
}

export default InputPassword;
