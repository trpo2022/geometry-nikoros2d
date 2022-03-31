#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../thirdparty/ctest.h"
#include "../src/libmake/functions.c"

CTEST(suite_geometry, test_perimetr) {
  int i = 0;
  const int exp = 62;
  float number1[6];
  float perimetr[6];
  number1[i] = 10;
  perimetrcir(perimetr,i,number1);
  ASSERT_EQUAL(exp,perimetr[i]);
}
CTEST(suite_geometry, test_perecechenie) {
  int i = 1;
  const int exp = 0;
  float number1[10];
  float pointx[5][6], pointy[5][6]; int k[5][6];
  pointx[0][0]=1;
  pointx[0][1]=1;
  pointy[0][0]=3;
  pointy[0][1]=40;
  number1[1] = 1;
  number1[0] = 1;
  object[0]='c';
  perececheniecie(i,pointx,pointy,k,number1);
  int dd; dd=k[0][i];
  ASSERT_EQUAL(exp,dd);
}
CTEST(suite_geometry, test_radiusconflict) {
  int i = 1,gg = 0;
  const int exp = 1;
  float number1[6];
  number1[1]=-1;
  gg=velikiytest1(number1,i,gg);
  ASSERT_EQUAL(exp,gg);
}
CTEST(suite_geometry, test_triperimetr) {
  int i = 1;
  const int exp = 13;
  float pointx[5][6], pointy[5][6], perimetr[6];
  pointx[0][1]=1;
  pointy[0][1]=1;
  pointx[1][1]=2;
  pointy[1][1]=3;
  pointx[2][1]=7;
  pointy[2][1]=1;
  perimetrtri(perimetr, i, pointx, pointy);
  ASSERT_EQUAL(exp,perimetr[i]);
}
CTEST(suite_geometry, test_tryploshad) {
  int i = 1;
  const int exp = 6;
  float pointx[5][6], pointy[5][6], ploshad[6];
  pointx[0][1]=1;
  pointy[0][1]=1;
  pointx[1][1]=2;
  pointy[1][1]=3;
  pointx[2][1]=7;
  pointy[2][1]=1;
  ploshadtri(ploshad, i, pointx, pointy);
  ASSERT_EQUAL(exp,ploshad[i]);
}


