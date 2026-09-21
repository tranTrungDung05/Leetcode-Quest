/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** ans = (char**) malloc((target[targetSize - 1] * 2) * sizeof(char*));

    int idxCount = 0;
    int j = 0;

    for(int i = 1; i <= n; i++){
        if(j == targetSize) break;

        ans[idxCount] = (char*) malloc(5 * sizeof(char));
        strcpy(ans[idxCount++], "Push");

        if(i == target[j]){
            j++;
        }else{ 
            ans[idxCount] = (char*) malloc(4 * sizeof(char));
            strcpy(ans[idxCount++], "Pop");
        }
    }

    *returnSize = idxCount;
    return ans; 
}