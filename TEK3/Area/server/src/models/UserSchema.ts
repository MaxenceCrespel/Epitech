import mongoose, { Document, Schema } from 'mongoose';

export interface IUser extends Document {
    username: string;
    name: string;
    firstname: string;
    email: string;
    password: string;
    permissions: number;
    googleId: string;
    googleTokens: any;
    created_at: Date | null;
    avatar_url: string;
}

const UserSchema: Schema = new Schema({
    username: { type: String, required: true, unique: true },
    email: { type: String, required: true, unique: true },
    firstname: { type: String, required: true },
    permissions: { type: Number, required: true, default: 0 },
    name: { type: String, required: true },
    password: { type: String, required: true },
    googleId: { type: String, required: false },
    googleTokens: { type: Object, required: false },
    created_at: { type: Date, default: Date.now},
    avatar_url: { type: String, required: false }
});

export default mongoose.model<IUser>('User', UserSchema);