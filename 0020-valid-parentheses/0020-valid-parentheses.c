#include<stdbool.h>
#include<string.h>

bool isValid(char* s) {
    int n = strlen(s);
    if ( n % 2 != 0) {
        return false;
    }
    
    char stack[10001];
    int top = -1;

    for (int i =0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c =='[') {
            top++;
            stack[top] = c;
        } else {
            if (top == -1) {
                return false;
            }
            char last_open = stack[top];
            top--;
            if (c == ')' && last_open != '(') {
                return false;
            }
            if (c == '}' && last_open != '{') {
                return false;
            }
            if (c == ']' && last_open != '[') {
                return false;
            }
        }
    }
    return top == -1;
}