function twoSum(nums: number[], target: number): number[] {
    let numToIndex: Map<number, number> = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (numToIndex.has(target - nums[i])) {
            return [numToIndex.get(target-nums[i]), i];
        } else {
            numToIndex.set(nums[i], i);
        }
    }
    return [-1, -1];
};
