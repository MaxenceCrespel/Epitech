import mongoose, { Document, Schema } from 'mongoose';

export interface IAction extends Document {
    name: string;
    serviceName: string;
    description: string;
    lastData: {
        type: Object,
    };
    created_at: Date | null;
    params: Array<Object>;
    user: {
        type: Schema.Types.ObjectId,
        ref: 'User'
    };
    applet?: {
        type: Schema.Types.ObjectId,
        ref: 'Applet'
    };
}

export const ActionSchema: Schema = new Schema({
    name: { type: String, required: true },
    serviceName: { type: String, required: true },
    lastData: { type: Object, required: false },
    description: { type: String, required: true },
    params: { type: Array, required: true },
    user: { type: Schema.Types.ObjectId, ref: 'User' },
    applet: { type: Schema.Types.ObjectId, ref: 'Applet', required: false },
    created_at: { type: Date, default: Date.now},
});

export default mongoose.model<IAction>('Action', ActionSchema);
