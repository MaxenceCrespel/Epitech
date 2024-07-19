import LogSchema from "../models/LogSchema";

export function log(level: string, message: string, applet?: number | string, user?: number | string) : boolean {
    try {
        const log = new LogSchema({
            date: new Date(),
            applet: applet ? applet : null,
            user: user ? user : null,
            level: level,
            message: message,
        });
        log.save();
        console.log(`[${level}] ${message}`);
        return true;
    } catch (error) {
        console.log(error);
        return false;
    }
}
