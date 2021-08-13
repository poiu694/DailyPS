const bfs = (graph, start) => {
    const dx = [1, 0, -1, 0];
    const dy = [0, 1, 0, -1];   
    
    const n = graph.length;
    const m = graph[0].length;
    let visited = [...graph].map((r) => r.map((c) => 1));
    let q = [];
    q.push(start);
    visited[0][0] = 0;
    while(q.length !== 0) {
        const [x, y, cnt] = q.shift();
        if (x === n - 1 && y === m - 1 ) return cnt;
        
        for (let i=0; i<4; i++) {
            const nx = x + dx[i];
            const ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            if (visited[nx][ny] === 0 || graph[nx][ny] === 0) continue;
            
            visited[nx][ny] = 0;
            q.push([nx, ny, cnt + 1]);
        }
    }
    
    return -1;
};

function solution(maps) {
    const startNode = [0, 0, 1];
    return bfs(maps, startNode);
}