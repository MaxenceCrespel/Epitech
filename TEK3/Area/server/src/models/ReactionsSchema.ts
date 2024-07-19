import mongoose, { Document, Schema } from 'mongoose';

export interface IReaction extends Document {
    created_at: Date | null;
    serviceName: string;
    params: Array<Object>;
    applet?: {
        type: Schema.Types.ObjectId,
        ref: 'Applet'
    }
    user: {
        type: Schema.Types.ObjectId,
        ref: 'User'
    };
}

export const ReactionSchema: Schema = new Schema({
    name: { type: String, required: true },
    serviceName: { type: String, required: true },
    description: { type: String, required: true },
    params: { type: Array, required: true },
    applet: { type: Schema.Types.ObjectId, ref: 'Applet', required: false },
    user: { type: Schema.Types.ObjectId, ref: 'User' },
    created_at: { type: Date, default: Date.now},
});

export default mongoose.model<IReaction>('Reaction', ReactionSchema);
