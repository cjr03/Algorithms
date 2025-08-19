function wordPattern(pattern: string, s: string): boolean {
    const words: string[] = s.split(' ');
    if (pattern.length !== words.length) {
        return false;
    }
    let wordToChar: Map<string, string> = new Map();
    let charToWord: Map<string, string> = new Map();

    for(let i = 0; i < pattern.length; ++i){
        const c = pattern[i];
        const w = words[i];
        if (wordToChar.has(w)) {
            if (wordToChar.get(w) != c) {
                return false;
            }
        } else {
            wordToChar.set(w, c);
        }
        if (charToWord.has(c)) {
            if (charToWord.get(c) != w) {
                return false;
            }
        } else {
            charToWord.set(c, w);
        }
    }
    return true;
};
