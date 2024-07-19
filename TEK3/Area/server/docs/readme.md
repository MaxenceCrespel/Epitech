# Documentation for server app
(Version: 10/05/2023)

## How to run it ?

To launch and expose the server app into port 8080
go into root folder and do :

```sh
docker compose up -d
```

then go into : <http://localhost:8080> to see the server.


### How to init the database ?
To init the db (with a test user and the permissionList)
 ```sh
 docker compose up -d
 docker compose exec node_app /bin/sh
 cd build/init
 node initDb.js
 ```
To have more info about this script : [InitDb Script](./initDb.md)


#### Api Documentation
The technical documentation of the api can be found at <http://localhost:8080/docs> or [there](./api.md)
For a more easy step by step documentation, you can follow this tutorial, with code samples and explanations.