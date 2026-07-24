//printing of "reversed array"
#include <stdio.h>
int main() {
  int size,i;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter %d integers:\n", size);

  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array:\n");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\nreversed array:\n");
  for(i=size-1;i>=0;i--){
  printf("%d ", arr[i]);
  }
    return 0;
}