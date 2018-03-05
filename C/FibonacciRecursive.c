#include <stdio.h>

int fib(int x) {

  if(x == 0)
    return 0;
  
  if(x == 1)
    return 1;
  
  return fib(x-1)+fib(x-2);
}


int main(int argc, char *argv[]){
  int fibNum=0;

  puts("Enter a Positive Integer:");
  scanf("%d", &fibNum);

  if( fibNum < 0 ){
    puts("That is not a valid number\n");
    main(1, NULL);
  }

  printf("%d\n", fib(fibNum));

  return 0;
}
