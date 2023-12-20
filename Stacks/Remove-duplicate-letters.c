char* removeDuplicateLetters(char* s) {
    int last_occurrence[26];
    memset(last_occurrence, -1, sizeof(last_occurrence));

    int len = strlen(s);

    for (int i = 0; i < len; ++i) {
        last_occurrence[s[i] - 'a'] = i;
    }

    char result[len + 1];
    int resultIndex = 0;

    char stack[len];
    int stackIndex = -1;
    int used[26] = {0};

    for (int i = 0; i < len; ++i) {
        char currChar = s[i];

        if (!used[currChar - 'a']) {
            while (stackIndex != -1 && currChar < stack[stackIndex] &&
                   last_occurrence[stack[stackIndex] - 'a'] > i) {
                used[stack[stackIndex] - 'a'] = 0;
                stackIndex--;
            }

            stack[++stackIndex] = currChar;
            used[currChar - 'a'] = 1;
        }
    }

    for (int i = 0; i <= stackIndex; ++i) {
        result[resultIndex++] = stack[i];
    }

    result[resultIndex] = '\0';

    char* finalResult = (char*)malloc(resultIndex + 1);
    strcpy(finalResult, result);

    return finalResult;
}
