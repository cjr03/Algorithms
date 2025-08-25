class TrieNode {
    children: Map<string, TrieNode>;
    word: string | null;

    constructor() {
        this.children = new Map();
        this.word = null;
    }
}

function findWords(board: string[][], words: string[]): string[] {
    const root = buildTrie(words);
    const result: string[] = [];
    const rows = board.length;
    const cols = board[0].length;

    function dfs(r: number, c: number, node: TrieNode) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        const char = board[r][c];
        if (char === "#" || !node.children.has(char)) return;

        const nextNode = node.children.get(char)!;

        if (nextNode.word !== null) {
            result.push(nextNode.word);
            nextNode.word = null;
        }

        board[r][c] = "#";

        dfs(r + 1, c, nextNode);
        dfs(r - 1, c, nextNode);
        dfs(r, c + 1, nextNode);
        dfs(r, c - 1, nextNode);

        board[r][c] = char;

        if (nextNode.children.size === 0) {
            node.children.delete(char);
        }
    }

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            dfs(r, c, root);
        }
    }

    return result;
}

function buildTrie(words: string[]): TrieNode {
    const root = new TrieNode();
    for (const word of words) {
        let node = root;
        for (const char of word) {
            if (!node.children.has(char)) {
                node.children.set(char, new TrieNode());
            }
            node = node.children.get(char)!;
        }
        node.word = word;
    }
    return root;
}
