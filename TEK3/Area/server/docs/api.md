---
title: Area API v1.0.0
language_tabs:
  - http: http
language_clients:
  - http: ""
toc_footers: []
includes: []
search: false
highlight_theme: darkula
headingLevel: 2

---

<!-- Generator: Widdershins v4.0.1 -->

<h1 id="area-api">Area API v1.0.0</h1>

> Scroll down for code samples, example requests and responses. Select a language for code samples from the tabs above or the mobile navigation menu.

Documentation of the Area API

# Authentication

* API Key (Bearer)
    - Parameter Name: **Authorization**, in: header.

<h1 id="area-api-utils">utils</h1>

## get__v1._ping

> Code samples

```http
GET /v1./ping HTTP/1.1

Accept: */*

```

`GET /v1./ping`

Ping the API

> Example responses

> 200 Response

<h3 id="get__v1._ping-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1._ping-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» message|string|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

<h1 id="area-api-users">users</h1>

## get__v1_users_

> Code samples

```http
GET /v1/users/ HTTP/1.1

Accept: */*

```

`GET /v1/users/`

Users endpoint

> Example responses

> 200 Response

<h3 id="get__v1_users_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_users_-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» name|string|false|none|none|
|» firstname|string|false|none|none|
|» username|string|false|none|none|
|» email|string|false|none|none|
|» created_at|string|false|none|none|
|» permissions|number|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## post__v1_users_

> Code samples

```http
POST /v1/users/ HTTP/1.1

Content-Type: application/json
Accept: */*

```

`POST /v1/users/`

Create user endpoint

> Body parameter

```json
{
  "name": "string",
  "email": "string",
  "password": "string",
  "username": "string",
  "firstname": "string"
}
```

<h3 id="post__v1_users_-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|body|body|object|false|none|
|» name|body|string|false|user name|
|» email|body|string|false|user email|
|» password|body|string|false|user password|
|» username|body|string|false|user username|
|» firstname|body|string|false|user firstname|

> Example responses

> 200 Response

<h3 id="post__v1_users_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="post__v1_users_-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» message|string|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_users_me

> Code samples

```http
GET /v1/users/me HTTP/1.1

Accept: */*

```

`GET /v1/users/me`

Get current user endpoint

> Example responses

> 200 Response

<h3 id="get__v1_users_me-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_users_me-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» name|string|false|none|none|
|» firstname|string|false|none|none|
|» username|string|false|none|none|
|» email|string|false|none|none|
|» created_at|string|false|none|none|
|» permissions|number|false|none|none|
|» _id|string|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_users_{id}

> Code samples

```http
GET /v1/users/{id} HTTP/1.1

Accept: */*

```

`GET /v1/users/{id}`

Get user endpoint

<h3 id="get__v1_users_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|user id|

> Example responses

> 200 Response

<h3 id="get__v1_users_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_users_{id}-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» name|string|false|none|none|
|» firstname|string|false|none|none|
|» username|string|false|none|none|
|» email|string|false|none|none|
|» created_at|string|false|none|none|
|» permissions|number|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## put__v1_users_{id}

> Code samples

```http
PUT /v1/users/{id} HTTP/1.1

Content-Type: application/json
Accept: */*

```

`PUT /v1/users/{id}`

Update user endpoint

> Body parameter

```json
{}
```

<h3 id="put__v1_users_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|user id|
|body|body|object|false|none|

> Example responses

> 200 Response

<h3 id="put__v1_users_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="put__v1_users_{id}-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» name|string|false|none|none|
|» firstname|string|false|none|none|
|» username|string|false|none|none|
|» email|string|false|none|none|
|» created_at|string|false|none|none|
|» permissions|number|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## delete__v1_users_{id}

> Code samples

```http
DELETE /v1/users/{id} HTTP/1.1

Accept: */*

```

`DELETE /v1/users/{id}`

Delete user endpoint

<h3 id="delete__v1_users_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|user id|

> Example responses

> 200 Response

<h3 id="delete__v1_users_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="delete__v1_users_{id}-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» name|string|false|none|none|
|» firstname|string|false|none|none|
|» username|string|false|none|none|
|» email|string|false|none|none|
|» created_at|string|false|none|none|
|» permissions|number|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

<h1 id="area-api-auth">auth</h1>

## post__v1_auth_login

> Code samples

```http
POST /v1/auth/login HTTP/1.1

Content-Type: application/json
Accept: */*

```

`POST /v1/auth/login`

Login endpoint

> Body parameter

```json
{
  "email": "string",
  "username": "string",
  "password": "string"
}
```

<h3 id="post__v1_auth_login-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|body|body|object|false|none|
|» email|body|string|false|user email|
|» username|body|string|false|user username|
|» password|body|string|false|user password|

> Example responses

> 200 Response

<h3 id="post__v1_auth_login-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="post__v1_auth_login-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» token|string|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## put__v1_auth_refresh

> Code samples

```http
PUT /v1/auth/refresh HTTP/1.1

Accept: */*

```

`PUT /v1/auth/refresh`

Refresh token endpoint

> Example responses

> 200 Response

<h3 id="put__v1_auth_refresh-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="put__v1_auth_refresh-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» token|string|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

<h1 id="area-api-actions">actions</h1>

## get__v1_actions_functions

> Code samples

```http
GET /v1/actions/functions HTTP/1.1

Accept: */*

```

`GET /v1/actions/functions`

Get available actions functions

> Example responses

> 200 Response

<h3 id="get__v1_actions_functions-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_actions_functions-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» actions|[any]|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_actions_

> Code samples

```http
GET /v1/actions/ HTTP/1.1

Accept: */*

```

`GET /v1/actions/`

Get all actions

> Example responses

> 200 Response

<h3 id="get__v1_actions_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_actions_-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## post__v1_actions_

> Code samples

```http
POST /v1/actions/ HTTP/1.1

Content-Type: application/json

```

`POST /v1/actions/`

Create an action

> Body parameter

```json
{
  "name": "string",
  "serviceName": "string",
  "description": "string",
  "params": [
    null
  ],
  "applet": "string",
  "user": "string"
}
```

<h3 id="post__v1_actions_-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|body|body|object|false|none|
|» name|body|string|false|none|
|» serviceName|body|string|false|none|
|» description|body|string|false|none|
|» params|body|[any]|false|none|
|» applet|body|string|false|none|
|» user|body|string|false|none|

<h3 id="post__v1_actions_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|None|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_actions_{id}

> Code samples

```http
GET /v1/actions/{id} HTTP/1.1

Accept: */*

```

`GET /v1/actions/{id}`

Get action by id

<h3 id="get__v1_actions_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

> Example responses

> 200 Response

<h3 id="get__v1_actions_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_actions_{id}-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## put__v1_actions_{id}

> Code samples

```http
PUT /v1/actions/{id} HTTP/1.1

Content-Type: application/json

```

`PUT /v1/actions/{id}`

Update an action

> Body parameter

```json
{
  "name": "string",
  "serviceName": "string",
  "description": "string",
  "params": [
    null
  ],
  "applet": "string",
  "user": "string"
}
```

<h3 id="put__v1_actions_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|
|body|body|object|false|none|
|» name|body|string|false|none|
|» serviceName|body|string|false|none|
|» description|body|string|false|none|
|» params|body|[any]|false|none|
|» applet|body|string|false|none|
|» user|body|string|false|none|

<h3 id="put__v1_actions_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|None|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## delete__v1_actions_{id}

> Code samples

```http
DELETE /v1/actions/{id} HTTP/1.1

```

`DELETE /v1/actions/{id}`

Delete an action

<h3 id="delete__v1_actions_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

<h3 id="delete__v1_actions_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|None|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

<h1 id="area-api-reactions">reactions</h1>

## get__v1_reactions_functions

> Code samples

```http
GET /v1/reactions/functions HTTP/1.1

Accept: */*

```

`GET /v1/reactions/functions`

Get available reactions

> Example responses

> 200 Response

<h3 id="get__v1_reactions_functions-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_reactions_functions-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» reactions|[any]|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_reactions_

> Code samples

```http
GET /v1/reactions/ HTTP/1.1

Accept: */*

```

`GET /v1/reactions/`

Get all reactions

> Example responses

> 200 Response

<h3 id="get__v1_reactions_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_reactions_-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## post__v1_reactions_

> Code samples

```http
POST /v1/reactions/ HTTP/1.1

Content-Type: application/json
Accept: */*

```

`POST /v1/reactions/`

Create a reaction

> Body parameter

```json
{
  "name": "string",
  "serviceName": "string",
  "description": "string",
  "params": [
    null
  ],
  "applet": "string",
  "user": "string"
}
```

<h3 id="post__v1_reactions_-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|body|body|object|false|none|
|» name|body|string|false|none|
|» serviceName|body|string|false|none|
|» description|body|string|false|none|
|» params|body|[any]|false|none|
|» applet|body|string|false|none|
|» user|body|string|false|none|

> Example responses

> 200 Response

<h3 id="post__v1_reactions_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="post__v1_reactions_-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_reactions_{id}

> Code samples

```http
GET /v1/reactions/{id} HTTP/1.1

Accept: */*

```

`GET /v1/reactions/{id}`

Get reaction by id

<h3 id="get__v1_reactions_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

> Example responses

> 200 Response

<h3 id="get__v1_reactions_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_reactions_{id}-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## put__v1_reactions_{id}

> Code samples

```http
PUT /v1/reactions/{id} HTTP/1.1

Content-Type: application/json
Accept: */*

```

`PUT /v1/reactions/{id}`

Update a reaction

> Body parameter

```json
{
  "name": "string",
  "serviceName": "string",
  "description": "string",
  "params": [
    null
  ],
  "applet": "string",
  "user": "string"
}
```

<h3 id="put__v1_reactions_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|
|body|body|object|false|none|
|» name|body|string|false|none|
|» serviceName|body|string|false|none|
|» description|body|string|false|none|
|» params|body|[any]|false|none|
|» applet|body|string|false|none|
|» user|body|string|false|none|

> Example responses

> 200 Response

<h3 id="put__v1_reactions_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="put__v1_reactions_{id}-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## delete__v1_reactions_{id}

> Code samples

```http
DELETE /v1/reactions/{id} HTTP/1.1

Accept: */*

```

`DELETE /v1/reactions/{id}`

Delete a reaction

<h3 id="delete__v1_reactions_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

> Example responses

> 200 Response

<h3 id="delete__v1_reactions_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="delete__v1_reactions_{id}-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

<h1 id="area-api-applets">applets</h1>

## get__v1_applets_functions

> Code samples

```http
GET /v1/applets/functions HTTP/1.1

Accept: */*

```

`GET /v1/applets/functions`

Get available applets functions

> Example responses

> 200 Response

<h3 id="get__v1_applets_functions-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_applets_functions-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» applets|[any]|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_applets_

> Code samples

```http
GET /v1/applets/ HTTP/1.1

Accept: */*

```

`GET /v1/applets/`

Get all applets

> Example responses

> 200 Response

<h3 id="get__v1_applets_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_applets_-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## post__v1_applets_

> Code samples

```http
POST /v1/applets/ HTTP/1.1

Content-Type: application/json

```

`POST /v1/applets/`

Create applet

> Body parameter

```json
{
  "name": "string",
  "description": "string",
  "actions": [
    null
  ],
  "reactions": [
    null
  ]
}
```

<h3 id="post__v1_applets_-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|body|body|object|false|none|
|» name|body|string|false|none|
|» description|body|string|false|none|
|» actions|body|[any]|false|none|
|» reactions|body|[any]|false|none|

<h3 id="post__v1_applets_-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|None|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## get__v1_applets_{id}

> Code samples

```http
GET /v1/applets/{id} HTTP/1.1

Accept: */*

```

`GET /v1/applets/{id}`

Get applet by id

<h3 id="get__v1_applets_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

> Example responses

> 200 Response

<h3 id="get__v1_applets_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="get__v1_applets_{id}-responseschema">Response Schema</h3>

Status Code **200**

|Name|Type|Required|Restrictions|Description|
|---|---|---|---|---|
|» name|string|false|none|none|
|» description|string|false|none|none|
|» actions|[any]|false|none|none|
|» reactions|[any]|false|none|none|
|» functionName|string|false|none|none|
|» _id|string|false|none|none|
|» frequency|string|false|none|none|
|» createdAt|string|false|none|none|
|» user|string|false|none|none|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## put__v1_applets_{id}

> Code samples

```http
PUT /v1/applets/{id} HTTP/1.1

Content-Type: application/json

```

`PUT /v1/applets/{id}`

Update applet

> Body parameter

```json
{
  "name": "string",
  "description": "string",
  "actions": [
    null
  ],
  "reactions": [
    null
  ]
}
```

<h3 id="put__v1_applets_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|
|body|body|object|false|none|
|» name|body|string|false|none|
|» description|body|string|false|none|
|» actions|body|[any]|false|none|
|» reactions|body|[any]|false|none|

<h3 id="put__v1_applets_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|None|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## delete__v1_applets_{id}

> Code samples

```http
DELETE /v1/applets/{id} HTTP/1.1

Accept: */*

```

`DELETE /v1/applets/{id}`

Delete applet by id

<h3 id="delete__v1_applets_{id}-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

> Example responses

> 200 Response

<h3 id="delete__v1_applets_{id}-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|Inline|

<h3 id="delete__v1_applets_{id}-responseschema">Response Schema</h3>

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

## post__v1_applets_{id}_execute

> Code samples

```http
POST /v1/applets/{id}/execute HTTP/1.1

```

`POST /v1/applets/{id}/execute`

Execute applet

<h3 id="post__v1_applets_{id}_execute-parameters">Parameters</h3>

|Name|In|Type|Required|Description|
|---|---|---|---|---|
|id|path|string|true|none|

<h3 id="post__v1_applets_{id}_execute-responses">Responses</h3>

|Status|Meaning|Description|Schema|
|---|---|---|---|
|200|[OK](https://tools.ietf.org/html/rfc7231#section-6.3.1)|Default Response|None|

<aside class="warning">
To perform this operation, you must be authenticated by means of one of the following methods:
Bearer
</aside>

