int sumOfSquares(int* nums, int numsSize) {
    int sos = 0;
    for(int i = 0; i < numsSize; i++){
        if(numsSize % (i + 1) == 0){
            sos += nums[i] * nums[i];
        }
    }

    return sos;
}