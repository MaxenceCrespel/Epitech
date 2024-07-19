# Applets explanation

The applets are the main part of this api and not the most easiest thing.

## What is an applet ?

In our case an applet is a action (or more than one) and a reaction (or more).

> :warning: An applet need to have at least an action, and a reaction (and of course a user)

Once created, and saved in the database, you can execute it, it will be launched each N seconds, or minutes, depending of your choice.


### How to create an applet ?

A applet, need one action and reaction, so first things first you need to create an action.

As usual, you can post, get, put and delete.

The action endpoint is : /v1/actions

```TS
export interface IAction extends Document {
    name: string;
    serviceName: string;
    description: string;
    lastData: {
        type: Object,
    };
    created_at: Date | null;
    params: Array<Object>;
    user: {
        type: Schema.Types.ObjectId,
        ref: 'User'
    };
    applet?: {
        type: Schema.Types.ObjectId,
        ref: 'Applet'
    };
}
```

After that, you need to create a reaction:

The endpoint is : /v1/reactions
```TS
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
```

And only after that, you can create an applet:

the endpoint is : /v1/applets
```TS
export interface IApplet extends Document {
    name: string;
    description: string;
    created_at: Date | null;
    frequency: string;
    functionName: string;
    actions: Array<{
        type: Schema.Types.ObjectId,
        ref: 'Action'
    }>;
    reactions: Array<{
        type: Schema.Types.ObjectId,
        ref: 'Reaction'
    }>;
    user: {
        type: Schema.Types.ObjectId,
        ref: 'User'
    };
}
```

One created, you can launch it with a post request on this endpoint : /v1/applets/{id}/execute.

#### Code exemple

Post request to create an action :
```JS
const axios = require('axios');
let data = JSON.stringify({
  "name": "New Commit",
  "serviceName": "github_commit",
  "description": "<string>",
  "user": "651a93d2ac533f5afd83b40f"
});

let config = {
  method: 'post',
  maxBodyLength: Infinity,
  url: 'localhost:8080/v1/actions/',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': 'Bearer yourtoken'
  },
  data : data
};

axios.request(config)
.then((response) => {
  console.log(JSON.stringify(response.data));
})
.catch((error) => {
  console.log(error);
});

```

Post request to create a reaction:

```JS
const axios = require('axios');
let data = JSON.stringify({
  "name": "Teams Channel test",
  "serviceName": "teams_webhook",
  "description": "Teams",
  "params": [
    {
      "url": "https://epitechfr.webhook.office.com/webhookb2/0fc61e77-17bf-44fe-bbde-67897ff9fae2@901cb4ca-b862-4029-9306-e5cd0f6d9f86/IncomingWebhook/d7a11e7f1caa4cb9a3949a75afe5b194/c273bfa7-96ee-4716-acdd-72948d867f4b"
    }
  ],
  "user": "651a93d2ac533f5afd83b40f"
});

let config = {
  method: 'post',
  maxBodyLength: Infinity,
  url: 'localhost:8080/v1/reactions/',
  headers: {
    'Content-Type': 'application/json',
    'Accept': '*/*',
    'Authorization': 'Bearer YourToken'
  },
  data : data
};

axios.request(config)
.then((response) => {
  console.log(JSON.stringify(response.data));
})
.catch((error) => {
  console.log(error);
});

```

And finally post request to create applet :

```JS
const axios = require('axios');
let data = JSON.stringify({
  "name": "Applet #1",
  "description": "Applet git>teams",
  "actions": [
    "651e8616ea1e29f95820b115"
  ],
  "frequency": "20 seconds",
  "functionName": "on_change_on_action",
  "reactions": [
    "651e897894b91417822d260a"
  ],
  "user": "651a93d2ac533f5afd83b40f"
});

let config = {
  method: 'post',
  maxBodyLength: Infinity,
  url: 'localhost:8080/v1/applets/',
  headers: {
    'Content-Type': 'application/json',
    'Authorization': 'Bearer yourToken'
  },
  data : data
};

axios.request(config)
.then((response) => {
  console.log(JSON.stringify(response.data));
})
.catch((error) => {
  console.log(error);
});

```