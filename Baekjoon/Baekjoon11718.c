#include <stdio.h>
char s[101];
int main() {
    while(~scanf("%[^\n]\n", s)) printf("%s\n", s);
    return 0;
}