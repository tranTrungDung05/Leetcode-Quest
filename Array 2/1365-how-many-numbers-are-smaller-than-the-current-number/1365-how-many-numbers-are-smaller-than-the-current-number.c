/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int count[101] = {0};
    int* ans = (int*) malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }
    
    int preSum = 0;
    int savePreSum[101] = {0};
    for(int i = 0; i < 101; i++){
        if(count[i] > 0){
            savePreSum[i] = preSum;
            preSum += count[i];
        }
    }
    
    for(int i = 0; i < numsSize; i++){
        ans[i] = savePreSum[nums[i]];
    }

    return ans;
}