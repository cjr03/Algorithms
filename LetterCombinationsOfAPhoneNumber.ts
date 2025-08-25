function letterCombinations(digits: string): string[] {
    const DigitToLetter: Map<string, string[]> = new Map([["2", ["a", "b", "c"]], ["3", ["d", "e", "f"]], ["4", ["g", "h", "i"]], ["5", ["j", "k", "l"]], ["6", ["m", "n", "o"]], ["7", ["p", "q", "r", "s"]], ["8", ["t", "u", "v"]], ["9", ["w", "x", "y", "z"]]]);
    let results: Array<string> = [""];
    for(const digit of digits){
        let letters: Array<string> = DigitToLetter.get(digit)!;
        let newResults: Array<string> = new Array();
        for(const result of results) {
            for(const letter of letters){
                newResults.push(result + letter);
            }
        }
        results = newResults;
    }
    return results.length === 1 ? [] : results;
};
