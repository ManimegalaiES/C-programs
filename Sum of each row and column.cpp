#include <stdio.h>
int main() {
  int a[10][10],i,j, r, c;
  printf("Enter rows and columns: ");
  scanf("%d %d", &r, &c);
  printf("\nEnter matrix elements:\n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    printf("Enter element a%d%d: ", i + 1, j + 1);
    scanf("%d", &a[i][j]);
  }
  printf("\nEntered matrix: \n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) {
    printf("%d  ", a[i][j]);
    if (j == c - 1)
    printf("\n");
  }
  printf("Calculation of row sum:\n");
  for (int i = 0; i < r; ++i){
   int rowsum=0;
  for (int j = 0; j < c; ++j){
   rowsum=rowsum+a[i][j];
  }
  printf("The sum of all elements in row %d is %d\n",i,rowsum);
 }
  printf("Calculation of column sum:\n");
  for (int i = 0; i < c; ++i){
   int colsum=1;
  for (int j = 0; j < r; j++){
   colsum=colsum+sa[j][i];
  
 }
  printf("The sum of all elements in column %d is %d\n",i,colsum);
 }
 return 0;
}
  
