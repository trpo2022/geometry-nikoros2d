#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../thirdparty/ctest.h"
#include "../src/libmake/functions.c"

CTEST(suite_geometry, test_circleplosh) {
  int i = 0;
  const int exp = 314;
  float number1[10];
  float ploshad[5];
  number1[i] = 10;
  ploshadcir(ploshad,i,number1);
  ASSERT_EQUAL(exp,ploshad[i]);
}
