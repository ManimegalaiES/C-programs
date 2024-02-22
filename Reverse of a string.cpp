#include<stdio.h>
#include<string.h>
int main(){
 char str[10];
 printf("Enter the string to be reversed:");
 scanf("%s",str);
 printf("After reversing the string:%s",strrev(str));
 return 0;
 
}
