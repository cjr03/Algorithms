function minMutation(startGene: string, endGene: string, bank: string[]): number {
    const bankSet: Set<string> = new Set(bank);
    if (!bankSet.has(endGene)) return -1;
    const queue: [string, number][] = [[startGene, 0]];
    const visited: Set<string> = new Set([startGene]);
    const choices = ['A', 'C', 'G', 'T'];
    while (queue.length > 0) {
        const [gene, steps] = queue.shift()!;
        for (let i = 0; i < gene.length; i++) {
            for (const c of choices) {
                if (c === gene[i]) continue;
                const mutated = gene.slice(0, i) + c + gene.slice(i + 1);
                if (mutated === endGene) return steps + 1;
                if (bankSet.has(mutated) && !visited.has(mutated)) {
                    visited.add(mutated);
                    queue.push([mutated, steps + 1]);
                }
            }
        }
    }
    return -1;
}
