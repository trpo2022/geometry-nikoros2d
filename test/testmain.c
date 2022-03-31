#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../thirdparty/ctest.h"
#include "../src/libmake/functions.c"

CTEST(suite_geometry, test_perimetr) {
  int i = 0;
  const int exp = 62;
  float number1[10];
  float perimetr[5];
  number1[i] = 10;
  perimetrcir(perimetr,i,number1);
  ASSERT_EQUAL(exp,perimetr[i]);
}
CTEST(suite_geometry, test_perecechenie) {
  int i = 1;
  const int exp = 0;
  float number1[10];
  float pointx[5][6], pointy[5][6];int k[5][6];
  pointx[0][0]=1;
  pointx[0][1]=1;
  pointy[0][0]=3;
  pointy[0][1]=4;
  number1[1] = 1;
  number1[0] = 1;
  perececheniecie(i,pointx,pointy,k,number1);
  ASSERT_EQUAL(exp,k[0][1]);
}

