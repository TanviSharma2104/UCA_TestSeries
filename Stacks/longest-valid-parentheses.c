#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(const char* s) {
    int* stack = (int*)malloc(sizeof(int) * (strlen(s) + 1));
    int stackIndex = 0;
    stack[stackIndex] = -1;
    int ans = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(') {
            stack[++stackIndex] = i;
        } else {
            if (stackIndex == 0) {
                // No matching opening parenthesis, update the starting index.
                stack[0] = i;
            } else {
                stackIndex--;
                ans = (ans > i - stack[stackIndex]) ? ans : (i - stack[stackIndex]);
            }
        }
    }

    free(stack);
    return ans;
}
