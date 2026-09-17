int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int maxCounted = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            count++;
            if(count > maxCounted){
                maxCounted = count;
            }
        }else{
            count = 0;
        }
    }

    return maxCounted;
}