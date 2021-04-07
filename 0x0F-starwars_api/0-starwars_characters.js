#!/usr/bin/node
/*  script that prints all characters of a Star Wars movie */

const fs = require('request');

const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
fs(url, function (err, response, body) {
  if (err) {
    console.log(err);
  }
  const data = JSON.parse(body);
  const chardict = {};
  for (const car in data.characters) {
    fs(data.characters[car], function (errorr, responser, bodyr) {
      if (errorr) {
        return console.log(errorr);
      }
      const Mybodychar = JSON.parse(bodyr);
      chardict[car] = Mybodychar.name;
      if (Object.values(chardict).length === data.characters.length) {
        for (const car in data.characters) {
          console.log(chardict[car]);
        }
      }
    });
  }
});
