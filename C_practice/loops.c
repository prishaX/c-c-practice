#include <stdio.h>
int main(){

printf("\n\n"); 


    // prime numbers
    int y,x,isprime;
    x=2;
    y=2;
    for (x=2;x<=300;x++){
        isprime=1;
      for (y=2; y<x; y++){
        if (x%y==0){
            isprime=0;
        }
      }
      if (isprime==1)
      printf("%d ",x);
    }

    printf("\n\n");

    // all combinations of 1,2,3

    int a,b,c;
    for (a=1;a<=3;a++){
        for (b=1;b<=3;b++){
            for (c=1;c<=3;c++){
                if(c!=b && c!=a && c!=a){
                    printf("\n%d", a*100+b*10+c);
                }
            }
        }
    }

    printf("\n\n");

    //printing the pattern 
    int i,j,k,l,m;

 for (l=7;l>=1;l--){ //rows
     printf("\n");
    for (i=1;i<=l;i++){   //first half
        printf("%d ",i);}
        
        for (m = 0; m <= (7-l)*4-3;m++){ //spaces
            if (l==7){
                printf("");
            }
            else{
    printf(" ");}}
        
        if (l==7){         //second half
          for (k=6;k>=1;k--){
        printf("%d ",k);} }
        else {
            for (k=l;k>=1;k--){
        printf("%d ",k);}
        }

 }
 
 printf("\n\n");

//patten 2

    int s,ls,r,num;
    num=1;
    for (s=1;s<=4;s++){ //rows
        printf("\n");
         for (ls=4;ls>s;ls--){ //printing leading spaces
            printf(" ");
      }
      for (r=1;r<=s;r++){
                printf("%d ", num); //printing digits
                num++;
            }
    }

printf("\n\n");

    /* the way these patterms work is, the outermost loop is for the number of rows,
    as each pattern is broken into parts depending on the lead spaces, spaces, gaps, 
    or even the halfs of the numerical/alphabetical patterns, the inner loops are meant for those
    parts, like the first loop was broken into 3 parts, the first was the digits, the second was spaces
    the third were digits in reverse, so the inner 3 loops were meant for these. */

    int q, p, z;
    scanf("%d\n%d", &p, &q);
  	// Complete the code.
    char *numbers[10] = {"zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"};
    
    for (z=p;z<=q;z++){
        if (z<=9){
            printf("%s\n",numbers[z]);
        }
        else {
            if (z%2==0){
                printf("even\n");
            }
            else{
                printf("odd\n");
            }
        }
     }
    
    printf("\n\n");

    // while loop, sum of digits of a number

    int nn,qq,summ=0;
    scanf("%d", &nn);
    
    while(nn!=0){
        qq=nn%10;
        summ=summ+qq;
        nn=nn/10;
    }
    printf("\n%d\n ", summ);
    
        return 0;
}