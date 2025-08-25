class TrieNode {
    children: Map<string, TrieNode>;
    isWord: boolean;

    constructor() {
        this.children = new Map();
        this.isWord = false;
    }
}

class WordDictionary {
    private root: TrieNode;

    constructor() {
        this.root = new TrieNode();
    }

    addWord(word: string): void {
        let node = this.root;
        for (const c of word) {
            if (!node.children.has(c)) {
                node.children.set(c, new TrieNode());
            }
            node = node.children.get(c)!;
        }
        node.isWord = true;
    }

    search(word: string): boolean {
        const dfs = (index: number, node: TrieNode): boolean => {
            if (index === word.length) return node.isWord;

            const c = word[index];

            if (c === ".") {
                for (const child of node.children.values()) {
                    if (dfs(index + 1, child)) return true;
                }
                return false;
            } else {
                if (!node.children.has(c)) return false;
                return dfs(index + 1, node.children.get(c)!);
            }
        };

        return dfs(0, this.root);
    }
}
