import { Octokit } from "octokit";
async function gitAction(params: any) {
    const octokit = new Octokit({
        auth: params.token
    });

    const data = {
        url: "",
        message: "",
    };

    const response = await octokit.request("GET /repos/{owner}/{repo}/commits", {
        owner: params.owner,
        repo: params.repo,
    });
    data.url = response.data[0].html_url;
    data.message = "New Commit: " + response.data[0].commit.message;
    return data;

}
export default gitAction;
