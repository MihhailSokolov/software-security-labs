#include <limits.h>
#include <stdio.h>

int check_num1(int param_1) {
  int uVar1;
  if (param_1 < 0x38) {
    uVar1 = 0;
  } else if (param_1 < 0x6c) {
    if (param_1 / 2 < param_1 + -0x31) {
      uVar1 = 1;
    } else {
      uVar1 = 0;
    }
  } else {
    uVar1 = 0;
  }
  return uVar1;
}

int check_num2(int param_1) {
  int uVar1;
  param_1 = param_1 + -0x4153;
  if (param_1 < 1) {
    uVar1 = 0;
  } else if (param_1 * 3 + -0x80 < (int)((param_1 - (param_1 >> 0x1f) & 1U) +
                                         (param_1 >> 0x1f) + param_1)) {
    uVar1 = 1;
  } else {
    uVar1 = 0;
  }
  return uVar1;
}

int check_num3(int param_1) {
  int uVar1;
  if ((param_1 & 1) == 0) {
    uVar1 = 0;
  } else if ((int)param_1 % 7 == 0) {
    if ((int)param_1 < 0x1f0f3) {
      uVar1 = 0;
    } else if ((int)(param_1 * 5) < (int)(((int)param_1 / 0x6930) * param_1)) {
      uVar1 = 0;
    } else {
      uVar1 = 1;
    }
  } else {
    uVar1 = 0;
  }
  return uVar1;
}

int check_num4(int param_1) {
  int uVar1;

  if ((int)param_1 >> 4 < 0x395eb) {
    uVar1 = 0;
  } else if ((int)(param_1 * 2) < 0x72bde0) {
    if ((param_1 & 1) == 0) {
      uVar1 = 1;
    } else {
      uVar1 = 0;
    }
  } else {
    uVar1 = 0;
  }
  return uVar1;
}

int check_key(int num1, int num2, int num3, int num4) {
  int iVar1 = check_num1(num1);
  if ((iVar1 != 0) && (10 < num3)) {
    num3 = (num3 + -2) * 3;
    int local_18 = check_num2(num2);
    int local_14 = check_num3(num3);
    if ((local_18 != 0) && (local_14 != 0)) {
      int iVar1 = check_num4(num4);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int i = 100;
  int j = 16780;
  int k = 8800745;
  int l = 3759800;
  int res = check_key(i, j, k, l);
  if (res) {
    printf("%d-%d-%d-%d is valid! :)\n", i, j, k, l);
  } else {
    printf("%d-%d-%d-%d is invalid! :(\n", i, j, k, l);
  }
  return 0;
}