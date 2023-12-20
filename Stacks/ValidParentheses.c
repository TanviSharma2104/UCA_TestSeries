bool isValid(char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    char* stack = (char*)malloc((length + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } else {
            if (top == -1 || 
                (current == ')' && stack[top] != '(') ||
                (current == '}' && stack[top] != '{') ||
                (current == ']' && stack[top] != '[')) {
                free(stack);
                return false;
            }
            top--;
        }
    }

    free(stack);
    return top == -1;
}
