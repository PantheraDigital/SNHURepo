#DropwizardProject

A program created using Java that utilizes RESTful API, Maven, and Dropwizard.

TODOs indicate the tasks I compleated to make the program work.

Run the program and visit http://localhost:8080/gameusers

Valid usernames to try are “guest”, “user”, “player”, and “admin”, all with the same password value of “password”.
Upon successful authentication, you will see the list of game players returned as a JSON string:

[{"id":1,"firstName":"Lokesh","lastName":"Gupta","email":"India"},
{"id":2,"firstName":"John","lastName":"Gruber","email":"USA"},
{"id":3,"firstName":"Melcum","lastName":"Marshal","email":"AUS"}]

Visiting the URL http://localhost:8080/gameusers/1 while logged in as a user in the USER role will return the player whose ID is 1 (Lokesh Gupta). Visiting the URL with /2 will return the player whose ID is 2 (John Gruber), and so on. Close the browser, then reopen it and try accessing the same URL as a player or guest, and you should see the following JSON string displayed:

{"code":403,"message":"User not authorized."}
