'use strict';

const fs = require('fs');

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
 * Complete the 'extractErrorLogs' function below.
 *
 * The function is expected to return a 2D_STRING_ARRAY.
 * The function accepts 2D_STRING_ARRAY logs as parameter.
 */

function extractErrorLogs(logs) {
    // Write your code here
    return logs.filter((log) => {
        const status = log[2];
        return status === "ERROR" || status === "CRITICAL";
    }).sort((a, b) => {
        const aDate = new Date(a[0].slice(6), a[0].slice(3, 5), a[0].slice(0, 2), a[1].slice(0, 2), a[1].slice(3, 5));
        const bDate = new Date(b[0].slice(6), b[0].slice(3, 5), b[0].slice(0, 2), b[1].slice(0, 2), b[1].slice(3, 5));
        return aDate - bDate;
    })
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const logsRows = parseInt(readLine().trim(), 10);

    const logsColumns = parseInt(readLine().trim(), 10);

    let logs = Array(logsRows);

    for (let i = 0; i < logsRows; i++) {
        logs[i] = readLine().replace(/\s+$/g, '').split(' ');
    }

    const result = extractErrorLogs(logs);

    ws.write(result.map(x => x.join(' ')).join('\n') + '\n');

    ws.end();
}
