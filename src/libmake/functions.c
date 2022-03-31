#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char object[10];

void perececheniecie(int i, float pointx[][6], float pointy[][6], int k[][6], float number1[]) {
  char circle[2] = "c";
  int j;
  if (i > 0) {
    for (j = i - 1; j > -1; j--) {
      if (object[j] == circle[0]) {
        k[j][i] = sqrt(pow((pointx[0][i] - pointx[0][j]), 2) + pow((pointy[0][i] - pointy[0][j]), 2));
        if (k[j][i] < (number1[i] + number1[j])) k[j][i] = 1;
        else k[j][i] = 0;
      }
    }
  }
}
void perimetrtri(float perimetr[], int i, float pointx[][6], float pointy[][6]) {
  perimetr[i] = sqrt(pow((pointx[0][i] - pointx[1][i]), 2) + pow((pointy[0][i] - pointy[1][i]), 2)) + sqrt(pow((pointx[1][i] - pointx[2][i]), 2) + pow((pointy[1][i] - pointy[2][i]), 2)) + sqrt(pow((pointx[2][i] - pointx[0][i]), 2) + pow((pointy[2][i] - pointy[0][i]), 2));
}
void ploshadtri(float ploshad[], int i, float pointx[][6], float pointy[][6]) {
  int d;
  d = 0.5 * ((pointx[0][i] - pointx[2][i]) * (pointy[1][i] - pointy[2][i]) - (pointx[1][i] - pointx[2][i]) * (pointy[0][i] - pointy[2][i]));
  ploshad[i] = abs(d);
}
int velikiytest1(float number1[], int i, int gg) {
  if (number1[i] < 0) gg = 1;
  return gg;
}
void perimetrcir(float perimetr[], int i, float number1[]) {
  perimetr[i] = (M_PI * 2 * number1[i]);
}
void ploshadcir(float ploshad[], int i, float number1[]) {
  ploshad[i] = number1[i] * number1[i] * M_PI;
}
void thevvod(float pointx[][6], float pointy[][6], float number1[], int i) {
  char circle[2] = "c", triangle[2] = "t", polygon[2] = "p";
  int gg = 0;
  printf("\nEnter first letter of object type>");
  scanf("%s", & object[i]);
  int j, k[5][6], t;
  float perimetr[10], ploshad[10];
  if (object[i] == circle[0]) {
    printf("\nEnter 1 point[x][y] value>");
    scanf("%f%f", & pointx[0][i], & pointy[0][i]);
    printf("\nEnter radius value>");
    scanf("%f", & number1[i]);
    gg = velikiytest1(number1, i, gg);
    if (gg == 1) {
      printf("Radius has incorrect value");
      return;
    }
    t = 0;
    perimetrcir(perimetr, i, number1);
    ploshadcir(ploshad, i, number1);
    printf("\nPerimetr = %f, Area = %f", perimetr[i], ploshad[i]);
    perececheniecie(i, pointx, pointy, k, number1);
    for (j = i - 1; j > -1; j--) {
      if (k[j][i] == 1) {
        printf("\nThis object intersects with object #%d", j);
        t = 1;
      }
    }
    if (t == 0)
      printf("\nThis object does not intersect any other");
  } else if (object[i] == triangle[0]) {
    printf("\nEnter 1 point[x][y] value>");
    scanf("%f%f", & pointx[0][i], & pointy[0][i]);
    printf("\nEnter 2 point[x][y] value>");
    scanf("%f%f", & pointx[1][i], & pointy[1][i]);
    printf("\nEnter 3 point[x][y] value>");
    scanf("%f%f", & pointx[2][i], & pointy[2][i]);
    perimetrtri(perimetr, i, pointx, pointy);
    ploshadtri(ploshad, i, pointx, pointy);
    printf("Perimetr = %f, Area = %f", perimetr[i], ploshad[i]);
  } else if (object[i] == polygon[0]) {
    printf("\nEnter 1 point[x][y] value>");
    scanf("%f%f", & pointx[0][i], & pointy[0][i]);
    printf("\nEnter 2 point[x][y] value>");
    scanf("%f%f", & pointx[1][i], & pointy[1][i]);
    printf("\nEnter 3 point[x][y] value>");
    scanf("%f%f", & pointx[2][i], & pointy[2][i]);
    printf("\nEnter 4 point[x][y] value>");
    scanf("%f%f", & pointx[3][i], & pointy[3][i]);
  } else {
    printf("Wrong object type");
  }
}
