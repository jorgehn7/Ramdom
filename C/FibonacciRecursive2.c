#include <stdio.h>

int fib(int n){
  return (n < 2) ? 1 : (fib(n-1) + fib(n-2));
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
