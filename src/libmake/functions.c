#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pi 3.14

void thevvod(float pointx[][5], float pointy[][5], float number1[], int i)
{ 
	char object[10], circle[7] = "c", triangle[9] = "t", polygon[8] = "p";
	scanf("%s", &object[0]);
	float perimetr[i], ploshad[i];
	int k;
	if (strcmp(object, circle) == 0)
	{
		scanf("%f%f", &pointx[0][i], &pointy[0][i]);
		scanf("%f", &number1[i]);
		perimetr[i] = (pi *2 *number1[i]);
		ploshad[i] = number1[i] *number1[i] *pi;
		printf("perimetr=%f, ploshad=%f", perimetr[i], ploshad[i]);
	}
	else if (strcmp(object, triangle) == 0)
	{
		scanf("%f%f", &pointx[0][i], &pointy[0][i]);
		scanf("%f%f", &pointx[1][i], &pointy[1][i]);
		scanf("%f%f", &pointx[2][i], &pointy[2][i]);
		perimetr[i] = sqrt(pow((pointx[0][i] - pointx[1][i]), 2) + pow((pointy[0][i] - pointy[1][i]), 2)) + sqrt(pow((pointx[1][i] - pointx[2][i]), 2) + pow((pointy[1][i] - pointy[2][i]), 2)) + sqrt(pow((pointx[2][i] - pointx[0][i]), 2) + pow((pointy[2][i] - pointy[0][i]), 2));
        	k = 0.5* ((pointx[0][i] - pointx[2][i]) *(pointy[1][i] - pointy[2][i]) - (pointx[1][i] - pointx[2][i]) *(pointy[0][i] - pointy[2][i]));
		ploshad[i]=abs(k);
		printf("perimetr=%f, ploshad=%f", perimetr[i], ploshad[i]);
	}
	else if (strcmp(object, polygon) == 0)
	{
		scanf("%f%f", &pointx[0][i], &pointy[0][i]);
		scanf("%f%f", &pointx[1][i], &pointy[1][i]);
		scanf("%f%f", &pointx[2][i], &pointy[2][i]);
		scanf("%f%f", &pointx[3][i], &pointy[3][i]);
	}
	else
		printf("Wrong object type");
}
