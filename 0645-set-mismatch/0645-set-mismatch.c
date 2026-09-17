/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*) malloc(2 * sizeof(int));
    int* count = (int*) malloc((numsSize + 1) * sizeof(int));

    for(int i = 0; i < numsSize + 1; i++){
        count[i] = 0;
    }

    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }

    for(int i = 1; i < numsSize + 1; i++){
        if(count[i] == 2){
            ans[0] = i;
        }else if(count[i] == 0){
            ans[1] = i;
        }
    }

    free(count);
    *returnSize = 2;
    return ans;
}