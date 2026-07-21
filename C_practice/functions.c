#include <stdio.h>

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

int calcum(int x,int y,int z){
    int sum;
    sum=x+y+z;
    return sum;
}

int power(int base,int exp){
   if (exp==0){
       return 1;
   }
    return base*power(base,exp-1);
}

int sum_of_digits(int a){
 int q=a%10;
    if (a==0)
        return 0;
    
 return q + sum_of_digits(a/10);
}

int num_of_digits(int a){
   int q=a/10;
   if(a<10)
   return 1;
 return 1+num_of_digits(a/10) ;
}

int factorial(int n){
    if(n==0)
        return 1;
   return n * factorial(n-1);
}


int main() {

    int a, b, c, d;
    printf("enter 4 digits to check max and calc sum of firs three- \n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("the max of the four numbers is: %d \n", ans);
    
    int sumofthree=calcum(a,b,c);
    printf("the sum of the first three numbers is: %d \n", sumofthree);

    int base,exp;
    printf("enter base and exp-");
    scanf("%d %d", &base, &exp);
    int p = power(base,exp);
    printf(" %d raised to the power %d is %d\n",base,exp,p);

    int digit;
    printf("enter a digit to calc sum of digits and number of digits in it-");
    scanf("%d", &digit);
    int sumdigits= sum_of_digits(digit);
    printf(" sum of digits of %d is %d\n",digit,sumdigits);
    int numdigits= num_of_digits(digit);
    printf(" digits in %d is %d\n",digit,numdigits);

    int factdigit;
    printf("enter a digit to calc factorial-");
    scanf("%d", &factdigit);
    int fact= factorial(factdigit);
    printf("factorial of %d is %d\n",factdigit,fact);

    return 0;
}
