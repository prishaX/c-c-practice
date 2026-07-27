#include <stdio.h>

int main(){

struct book{
  char name;
  float price;
  int pages;
};

struct book b1,b2;

printf ( "\nEnter names, prices & no. of pages of 2 books\n" );
scanf("%c %f %d", &b1.name, &b1.price, &b1.pages);
scanf("%c %f %d", &b2.name, &b2.price, &b2.pages);

printf ( "\nAnd this is what you entered" ) ;
printf ( "\n%c %f %d", b1.name, b1.price, b1.pages );
printf ( "\n%c %f %d", b2.name, b2.price, b2.pages );

    return 0;
}