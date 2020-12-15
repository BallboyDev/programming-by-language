#include <stdio.h>

int fib_iter(int n);

int main(){
        int n, k;
        scanf("%d", &n);
        k = fib_iter(n);
        printf("%d", k);
}

int fib_iter(int n){
        if(n < 2) return n;
        else {
                int i, tmp, current = 1, last = 0;
                for(i = 2; i <= n; i++){
                        tmp = current;
                        current += last;
                        last = tmp;
                }
                return current;
        }
}
