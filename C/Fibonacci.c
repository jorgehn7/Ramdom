#include <stdio.h>

int fib(int n){
  int a = 1, b = 1, c = 0, i;
  for (i = 3; i <= n; i++) {
    printf("%d ", c);
    a = b;
    b = c;
    c = a + b;
  }           
  return b;
}


int main(int argc, char *argv[]){
  int fibNum;
  puts("Enter a Possitive Number");
  scanf("%d", &fibNum);
  
  if(fibNum < 0){
    puts("That is not a possitive Number\n");
    main(1, NULL);
  }

  printf("\n%d\n", fib(fibNum));

  return 0;
}
// Awesome document to find fib number
