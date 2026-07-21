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

int calcum(x,y,z)
int x,y,z;{
    int sum;
    sum=x+y+z;
    return sum;
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("the max of the four numbers is: %d \n", ans);
    int sumofthree=calcum(a,b,c);
    printf("the sum of the three numbers is: %d \n", sumofthree);
    return 0;
}
