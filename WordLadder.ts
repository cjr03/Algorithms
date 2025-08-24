function ladderLength(beginWord: string, endWord: string, wordList: string[]): number {
    if (!wordList.includes(endWord)) return 0;

    const L = beginWord.length;
    const queue: [string, number][] = [[beginWord, 1]];
    const visited: Set<string> = new Set([beginWord]);
    const allComboDict: Map<string, string[]> = new Map();

    for (const word of wordList) {
        for (let i = 0; i < L; i++) {
            const pattern = word.slice(0, i) + "*" + word.slice(i + 1);
            if (!allComboDict.has(pattern)) allComboDict.set(pattern, []);
            allComboDict.get(pattern)!.push(word);
        }
    }  

    while (queue.length > 0) {
        const [word, level] = queue.shift()!;

        for (let i = 0; i < L; i++) {
            const pattern = word.slice(0, i) + "*" + word.slice(i + 1);
            const neighbors = allComboDict.get(pattern) || [];

            for (const nextWord of neighbors) {
                if (nextWord === endWord) return level + 1;

                if (!visited.has(nextWord)) {
                    visited.add(nextWord);
                    queue.push([nextWord, level + 1]);
                }
            }
        }
    }

    return 0;
}
