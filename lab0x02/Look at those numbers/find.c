#include <math.h>
#include <stdio.h>

int is_sqrt_check(int num) {
  double root = sqrt((double)num);
  return num == (int)root * (int)root;
}

int do_weird_math(int rand_var, int num1, int num2) {
  double d = ceil(sqrt((double)rand_var));
  int a = (int)d ;
  do {
    if (rand_var < a) {
      return 1;
    }
    int b = a * a - rand_var;
    int is_sqrt = is_sqrt_check(b);
    if (is_sqrt != 0) {
      d = sqrt((double)b);
      int c = a - (int)d;
      printf("%d-%d\n", c, ((int)d + a));
      if ((((c != 1) && (c != rand_var)) && (c == num1)) && ((int)d + a == num2)) {
        printf("FLAG!\n");
        return 0;
      }
    }
    a = a + 1;
  } while (1);
}

int main() {
    int rand_var = 30193;
    do_weird_math((int) rand_var, 1, 1);
}