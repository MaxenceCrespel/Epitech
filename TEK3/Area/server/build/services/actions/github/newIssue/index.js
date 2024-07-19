"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const octokit_1 = require("octokit");
function gitIssue(params) {
    return __awaiter(this, void 0, void 0, function* () {
        const octokit = new octokit_1.Octokit({
            auth: params.token
        });
        const data = {
            url: "",
            message: "",
        };
        const response = yield octokit.request("GET /repos/{owner}/{repo}/issues", {
            owner: params.owner,
            repo: params.repo,
        });
        data.url = response.data[0].html_url;
        data.message = "New Issue: " + response.data[0].title;
        return data;
    });
}
exports.default = gitIssue;
