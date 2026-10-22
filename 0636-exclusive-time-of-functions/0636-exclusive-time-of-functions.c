/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    *returnSize = n;
    int* timer = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(logsSize * sizeof(int));
    int top = -1;

    int prev_time = 0;

    for (int i = 0; i < logsSize; i++) {
        int pid, time;
        char action[10];
        
        sscanf(logs[i], "%d:%[^:]:%d", &pid, action, &time);

        if (action[0] == 's') {
            if (top >= 0) {
                timer[stack[top]] += time - prev_time;
            }
            stack[++top] = pid; 
            prev_time = time;
        } else { 
            timer[stack[top]] += time - prev_time + 1;
            top--;
            prev_time = time + 1; 
        }
    }

    free(stack);
    return timer;
}