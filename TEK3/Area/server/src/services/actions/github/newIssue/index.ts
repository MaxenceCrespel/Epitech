import { Octokit } from "octokit";
async function gitIssue(params: any) {
    const octokit = new Octokit({
        auth: params.token
    });

    const data = {
        url: "",
        message: "",
    };

    const response = await octokit.request("GET /repos/{owner}/{repo}/issues", {
        owner: params.owner,
        repo: params.repo,
    });
    data.url = response.data[0].html_url;
    data.message = "New Issue: " + response.data[0].title;
    return data;

}
export default gitIssue;
