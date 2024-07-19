# User management and requests

On this server, a user have the following properties:

- name
- firstname
- email (have to be unique)
- username (have to be unique)
- password (hashed)

(Planned properties)

- avatar url

(Invisible properties)

- permissions

## User Inteface (in typescript)
```TS
export interface IUser extends Document {
    username: string;
    name: string;
    firstname: string;
    email: string;
    password: string;
    permissions: number;
    created_at: Date | null;
}
```

By default a new user will have no permissions, so the admin will have to update the user with necessary permissions.

A user can login himself with email or username. [Login informations](./login.md)

### Api requests

- GET /v1/users (to list all users)
- GET /v1/users/{id} (to get a specific user)
- GET /v1/users/me (to get current logged user)
- POST /v1/users/ (to create a new user)
- PUT /v1/users/{id} (to update a specific user)
- DEL /v1/users/{id} (to delete a specific user)

#### Response types :
if there is many result (for the list of the users), it will be an array of Users.

If there is only one result, it will be the user.

Exemple:
-
```TS
// DEL /v1/users/{id} (to delete a specific user)
// Will return :
{
    username: string;
    name: string;
    firstname: string;
    email: string;
    permissions: number;
    created_at: Date | null;
}
```

The possible status codes are :
- 200 : its ok.
- 500 : Server error
- 404 : Ressource not found
- 403 : Unauthorized
- 401 : Invalid / Missing token