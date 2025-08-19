function removeDuplicates(nums: number[]): number {
    let k: number = nums.length;
    for(let i = 1; i < k;){
        if(nums[i-1] === nums[i]){
            nums.splice(i, 1);
            --k;
        } else {
            ++i;
        }
    }
    return k;
};
