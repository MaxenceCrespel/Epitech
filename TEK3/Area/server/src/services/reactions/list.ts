import teamsReaction from "./teams";
import teams from './teams/schema.json';

import discordReaction from "./discord";
import discord from './discord/schema.json';

import slackReaction from "./slack";
import slack from './slack/schema.json';

export default {
    [teams.name]: teamsReaction,
    [discord.name]: discordReaction,
    [slack.name]: slackReaction,
};

const list = [
    teams,
    discord,
    slack,
]

export { list };