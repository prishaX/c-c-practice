#include <stdio.h>
/*
MAX OF 4 NUMBERS FUNCTION 
*/
int max_of_four(int a,int b,int c,int d){
   int max;
    if(a>b && a>c){
        max=a;
    }
    else if (b>a && b>c){
        max=b;
    }
    else {
        max=c;
    }
    
    if (max>d){
        max=max;
    }
    else {
        max=d;
    }
    return max;
    }

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("the max of the four numbers is: %d \n", ans);
  
    return 0;
}
