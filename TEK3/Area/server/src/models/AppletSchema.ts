import mongoose, { Document, Schema } from 'mongoose';

export interface IApplet extends Document {
    name: string;
    description: string;
    created_at: Date | null;
    frequency: string;
    functionName: string;
    actions: Array<{
        type: Schema.Types.ObjectId,
        ref: 'Action'
    }>;
    reactions: Array<{
        type: Schema.Types.ObjectId,
        ref: 'Reaction'
    }>;
    user: {
        type: Schema.Types.ObjectId,
        ref: 'User'
    };
    active: boolean;
}

export const AppletSchema: Schema = new Schema({
    name: { type: String, required: true },
    description: { type: String, required: true },
    actions: { type: Array<{
        type: Schema.Types.ObjectId,
        ref: 'Action'
    }>, required: true },
    frequency: { type: String, required: true },
    functionName: { type: String, required: true },
    reactions: { type: Array<{
        type: Schema.Types.ObjectId,
        ref: 'Reaction'
    }>, required: true },
    user: { type: Schema.Types.ObjectId, ref: 'User', required: true },
    active: { type: Boolean, required: true, default: false },
    created_at: { type: Date, default: Date.now},
});

export default mongoose.model<IApplet>('Applet', AppletSchema);