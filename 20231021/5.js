'use strict';

const fs = require('fs');
const axios = require('axios');
const fetch = require('node-fetch');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputString = inputString.split('\n');

  main();
});

function readLine() {
  return inputString[currentLine++];
}


/*
 * Complete the 'bestInGenre' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING genre as parameter.
 *
 * Base URL: https://jsonmock.hackerrank.com/api/tvseries?page=
 */

async function getData(page) {
  const data = await fetch(`https://jsonmock.hackerrank.com/api/tvseries?page=${page}`).then((data) => data.json());
  return data;
}

async function getFetchAllData(totalPage) {
  const data = await Promise.all(Array.from({ length: totalPage }).map((_, i) => getData(i + 1)));

  return data.map((item) => item.data).flat();
}

async function bestInGenre(genre) {
  // Write your code here
  const data = await getFetchAllData(20);
  const genreData = data.filter((movie) => movie.genre.includes(genre)).sort((a, b) => {
    if (a.imdb_rating === b.imdb_rating) {
      return a.name.toLowerCase().localeCompare(b.name.toLowerCase());
    }
    return b.imdb_rating - a.imdb_rating
  });
  return genreData[0].name;
}
async function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const genre = readLine();

  const result = await bestInGenre(genre);

  ws.write(result + '\n');

  ws.end();
}
