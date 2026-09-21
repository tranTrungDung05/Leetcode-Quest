int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if ((tokens[i][0] == '+' || tokens[i][0] == '-' || 
             tokens[i][0] == '*' || tokens[i][0] == '/') && tokens[i][1] == '\0') {
            
            int b = stack[top--];
            int a = stack[top--];

            if (tokens[i][0] == '+') {
                stack[++top] = a + b;
            } else if (tokens[i][0] == '-') {
                stack[++top] = a - b;
            } else if (tokens[i][0] == '*') {
                stack[++top] = a * b;
            } else if (tokens[i][0] == '/') {
                stack[++top] = a / b;
            }
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}