import gitAction from "./github/newCommit";
import github from "./github/newCommit/schema.json";

import gitIssue from "./github/newIssue";
import githubIssue from "./github/newIssue/schema.json";

import weather from "./weather/current";
import weatherCurrent from "./weather/current/schema.json";

export default {
    [github.name]: gitAction,
    [githubIssue.name]: gitIssue,
    [weatherCurrent.name]: weather,
};

const list = [
    github,
    githubIssue,
    weatherCurrent,
]

export { list };