#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float thevvod(int i)
{
char object[10], circle[7] = "circle", triangle[9] = "triangle", polygon[8] = "polygon";
float pointx[5][5], pointy[5][5], number1;
scanf("%s", &object);
if (strcmp(object, circle) == 0)
{
scanf("%f%f", &pointx[0][i], &pointy[0][i]);
scanf("%f", &number1);
}
else if (strcmp(object, triangle) == 0)
{
scanf("%f%f", &pointx[0][i], &pointy[0][i]);
scanf("%f%f", &pointx[1][i], &pointy[1][i]);
scanf("%f%f", &pointx[2][i], &pointy[2][i]);
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
return 0;
}

int main()
{
int j, i = 0;
char ans[2], yes[2] = "y";
for (j = 0; j < 5; j++)
{
printf("\nWould you like to add object?(y/n)>");
scanf("%s", &ans);
if (strcmp(ans, yes) == 0)
{
thevvod(i);
i++;
}
else
break;
}
}
