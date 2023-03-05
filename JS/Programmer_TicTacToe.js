function isAlreadyFinish(board, target) {
    // check row
    const rowBoard = [...board];
    for (let i=0; i<rowBoard.length; i++) {
        if (rowBoard[i].split('').every((cell) => cell === target)) {
            return true;
        }
    }
    // check column
    const rotate90Board = board[0].split('').map((_, colIndex) => board.map(row => row[colIndex]));
    for (let i=0; i<rotate90Board.length; i++) {
        if (rotate90Board[i].every((cell) => cell === target)) {
            return true;
        }
    }
    // check diagonol
    if (board[0][0] === target && board[1][1] === target
            && board[2][2] === target) {
        return true;
    }
    if (board[0][2] === target && board[1][1] === target
            && board[2][0] === target) {
        return true;
    }
    return false;
}

function getXOCount(board) {
    let xCnt = 0;
    let oCnt = 0;
    
    for (let i=0; i<board.length; i++) {
        for (let j=0; j<board.length; j++) {
            if (board[i][j] === 'X') xCnt++;
            else if (board[i][j] === 'O') oCnt++;
        }
    }
    return { x: xCnt, o: oCnt };
}

function solution(board) {
    const xWin = isAlreadyFinish(board, 'X');
    const oWin = isAlreadyFinish(board, 'O');
    const { x, o } = getXOCount(board);
    
    // Check for invalid state
    if (xWin && oWin) {
        return 0;
    }
    if (o < x || o > x + 1) {
        return 0;
    }
    if (oWin && o !== x + 1) {
        return 0;
    }
    if (xWin && x !== o) {
        return 0;
    }
    return 1;
}