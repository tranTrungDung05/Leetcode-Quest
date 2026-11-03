int minMoves(int* nums, int numsSize) {
    int moves = 0;
    int max = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(max < nums[i])
            max = nums[i];
    }

    for(int i = 0; i < numsSize; i++){
        moves += (max - nums[i]);
    }

    return moves;
}