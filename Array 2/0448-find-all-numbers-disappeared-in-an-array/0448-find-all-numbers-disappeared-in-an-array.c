/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* count = calloc(numsSize + 1, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }

    int ans_idx = 0;
    int* ans = (int*) malloc(numsSize * sizeof(int));
    for(int i = 1 ; i <= numsSize; i++){
        if(count[i] == 0){
            ans[ans_idx++] = i;
        }
    }

    *returnSize = ans_idx;
    return ans;
}