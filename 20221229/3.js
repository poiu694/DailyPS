'use strict';

const fs = require('fs');
const axios = require('axios');

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
 * Complete the 'topArticles' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts INTEGER limit as parameter.
 * base url for copy/paste:
 * https://jsonmock.hackerrank.com/api/articles?page=<pageNumber>
 */

async function fetchArticles(page) {
  const response = await axios.get(
    `https://jsonmock.hackerrank.com/api/articles?page=${page}`
  );
  const { data, total_pages } = response.data;

  return {
    data,
    total_pages,
  };
}

async function fetchAllArticles() {
  let page = 0;
  const { data: articles, total_pages } = await fetchArticles(page);
  const pagesToFetch = Array.from({ length: total_pages + 1 }).map((_, i) => i).slice(1);

  const dataList = await Promise.all(
    pagesToFetch.map(async (page) => {
      const { data } = await fetchArticles(page);
      return data;
    })
  );

  const result = [...articles, ...dataList.flat()]
    .map((article) => ({
      name: article.title ?? article.story_title,
      num_comments: article.num_comments,
    }))
    .filter((article) => article.name)
    .filter(
      (article, i, arr) => arr.findIndex((a) => a.name === article.name) === i
    );
  return result;
}

function compare(a, b) {
  if (a.num_comments === b.num_comments) {
    return b.name > a.name ? 1 : -1;
  }

  return b.num_comments - a.num_comments;
}

async function topArticles(limit) {
  const articles = await fetchAllArticles();
  articles.sort(compare);

  return articles.slice(0, limit).map((article) => article.name);
}

async function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const limit = parseInt(readLine().trim(), 10);

  const result = await topArticles(limit);

  ws.write(result.join('\n') + '\n');

  ws.end();
}
