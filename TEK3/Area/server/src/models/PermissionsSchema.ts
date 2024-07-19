import mongoose, { Document, Schema } from 'mongoose';
import PermissionsList from '../utils/permissionsList';
import { IPermissions } from '../utils/permissionsList';

export interface IPerm extends Document {
    permissionsList: Object;
}

const Permissions: Schema = new Schema({
    permissionsList: { type: Schema.Types.Mixed, required: true, default: () => PermissionsList },
});

export default mongoose.model<IPerm>('Permissions', Permissions);

// This file is a model for the Permissions collection in the database.
// use it to init the collection.