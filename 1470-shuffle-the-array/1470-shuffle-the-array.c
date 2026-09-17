

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* ans = (int*) malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize / 2; i++){
        ans[i * 2] = nums[i];
        ans[2 * i + 1] = nums[i + n];
    }

    *returnSize = numsSize;
    return ans;
}