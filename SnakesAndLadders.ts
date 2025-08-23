function snakesAndLadders(board: number[][]): number {
    const n = board.length;

    function getCoordinates(s: number): [number, number] {
        const quot = Math.floor((s - 1) / n);
        const rem = (s - 1) % n;
        const row = n - 1 - quot;
        let col = quot % 2 === 0 ? rem : n - 1 - rem;
        return [row, col];
    }

    const visited: boolean[] = new Array(n * n + 1).fill(false);
    const queue: [number, number][] = [[1, 0]];
    visited[1] = true;

    while (queue.length > 0) {
        const [square, moves] = queue.shift()!;

        if (square === n * n) return moves;

        for (let dice = 1; dice <= 6; dice++) {
            let nextSquare = square + dice;
            if (nextSquare > n * n) continue;

            const [r, c] = getCoordinates(nextSquare);
            if (board[r][c] !== -1) {
                nextSquare = board[r][c];
            }

            if (!visited[nextSquare]) {
                visited[nextSquare] = true;
                queue.push([nextSquare, moves + 1]);
            }
        }
    }
    
    return -1;
}
