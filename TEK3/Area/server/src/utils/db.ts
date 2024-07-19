import mongoose from "mongoose";
import dotenv from "dotenv";

dotenv.config();

const url = `mongodb://root:${process.env.MONGO_ROOT_PASSWORD}@mongo_db:27017/Area?authSource=admin`;

const connect = async () => {
    try {
        await mongoose.connect(url);
        console.log("Successfully connected to MongoDB.");
    } catch (error) {
        console.error("Error connecting to MongoDB:", error);
    }
};

const db = {
    connect,
    mongoose,
};

export default db;
