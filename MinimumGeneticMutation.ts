function minMutation(startGene: string, endGene: string, bank: string[]): number {
    const queue: [string, number][] = [[startGene, 0]];
    const visited: Map<string, boolean> = new Map();
    while(queue.length > 0){
        const [gene, mutations] = queue.shift();
        if (gene === endGene) return mutations;
        for(const b of bank){
            let i = 0;
            let match = 0;
            for(const g of gene){
                if (g == b[i++]) ++match;
            }
            if (match === 7 && !visited.has(b)){
                visited.set(b, true);
                queue.push([b, mutations + 1]);
            }
        }
    }
    return -1;
};
