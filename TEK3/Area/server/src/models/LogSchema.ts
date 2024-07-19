import mongoose, { Document, Schema } from 'mongoose';

export interface ILog extends Document {
    date: Date;
    applet: {
        type: Schema.Types.ObjectId,
        ref: 'Applet'
    }
    user: {
        type: Schema.Types.ObjectId,
        ref: 'User'
    };
    level: string;
    message: string;
}

export const LogSchema: Schema = new Schema({
    date: { type: Date, required: true },
    applet: { type: Schema.Types.ObjectId, ref: 'Applet', required: false },
    user: { type: Schema.Types.ObjectId, ref: 'User', required: false },
    level: { type: String, required: true },
    message: { type: String, required: true },
});

export default mongoose.model<ILog>('Log', LogSchema);
