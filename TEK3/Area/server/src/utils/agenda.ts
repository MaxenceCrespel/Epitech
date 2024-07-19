import Agenda from "agenda";
import dotenv from "dotenv";
dotenv.config({
    path: "../.env",
});
const mongoConnectionString = `mongodb://root:${process.env.MONGO_ROOT_PASSWORD}@mongo_db:27017/AreaAgenda?authSource=admin`;

const agenda = new Agenda({
    db: {
        address: mongoConnectionString,
        collection: "jobs",
    },
});

export default agenda;