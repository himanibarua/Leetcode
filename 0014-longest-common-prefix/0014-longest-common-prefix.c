#include<string.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty_str = (char*)malloc(sizeof(char));
        empty_str[0] = '\0';
        return empty_str;
    }
    for (int i = 0; i < strlen(strs[0]); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (i >= strlen(strs[j]) || strs[j][i] != c) {
                char* result = (char*)malloc(sizeof(char) * (i + 1));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(result, strs[0]);
    return result;
}