/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target)
            count++;
    }
    *returnSize = count;
    int* ans = calloc(*returnSize, sizeof(int));
    int ansSize = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == target){
            ans[ansSize++] = i;
        }
    }

    return ans;
}