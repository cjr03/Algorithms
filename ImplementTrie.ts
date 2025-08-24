class Trie {
    private prefixes: Set<string> = new Set();
    private words: Set<string> = new Set();

    constructor() {
        
    }

    insert(word: string): void {
        this.words.add(word);
        let prefix: string = "";
        for(let i = 0; i < word.length; ++i){
            prefix += word[i];
            if(!this.prefixes.has(prefix)){
                this.prefixes.add(prefix);
            }
        }
    }

    search(word: string): boolean {
        return this.words.has(word);
    }

    startsWith(prefix: string): boolean {
        return this.prefixes.has(prefix);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
