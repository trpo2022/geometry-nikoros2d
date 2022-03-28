#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../thirdparty/ctest.h"
#define pi 3.14

CTEST(suite_geometry, test_circle) {
  int i = 0, j, t=0;
  const int exp = 1;
  int number1[10], pointx[5][5], pointy[5][5];
  double perimetr[5], ploshad[5],k;
  number1[i] = 100;
  pointx[0][i] = 1;
  pointy[0][i] = 2;
  i = 1;
  number1[i] = 5;
  pointx[0][i] = 16;
  pointy[0][i] = 34;
  perimetr[i] = (pi * 2 * number1[i]);
  if(round(10*perimetr[i])==314)t=1;
  ASSERT_EQUAL(exp,t);
  t=0;
  ploshad[i] = number1[i] * number1[i] * pi;
  if(ploshad[i]==78.5)t=1;
  ASSERT_EQUAL(exp, t);
  if (i > 0) {
    for (j = i - 1; j > -1; j--) {
      k = sqrt(pow((pointx[0][i] - pointx[0][j]), 2) + pow((pointy[0][i] - pointy[0][j]), 2));
      if (k < (number1[i] + number1[j])) {
        printf("\nThis object intersects with object #%d", j);
        t = 1;
      }
    }
    if (t == 0) {
      printf("\nThis object does not intersect any other");
      printf("ERROR #5");
    }
  }
}
