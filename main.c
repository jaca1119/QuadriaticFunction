#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double quadraticFunction(double a, double b, double c, double x)
{
	return (a * x * x) + (b * x) + c;
}



int main(int argc, char *argv[]) {
    FILE *result;

    result = fopen("results.txt","w");
    if (result == NULL)
    {
        printf("Error with opening file\n");
        exit(1);
    }

	double a,b,c;

	double range1, range2;
	double length;

	int n;
	//Get data from user input
	printf("Enter a, b, c, to quadratic function:\n");
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);

	printf("%.2lfx^2 + %.2lfx + %.2lf", a,b,c);

	printf("\nEnter range (from - to): ");
	printf("\nFrom: ");
	scanf("%lf", &range1);
	printf("To: ");
	scanf("%lf", &range2);

	printf("Range: (%.2lf - %.2lf)", range1, range2);

	printf("\nEnter number of measurements:");
	scanf("%d", &n);

	//range length (absolute value)
	length = fabs(range1 - range2);
	printf("Length =  %lf", length);

	double i;
	double y;

	//distance between each measurement
	double between = length/(n-1);
	printf("\nBetween = %lf", between);

	//Obliczanie kolejnych punktów
	//count each measurement
	for (i = range1; i<= range2; i+=between)
	{
		y = quadraticFunction(a, b, c, i);
		printf("\ny = %.2lf, x = %.2lf", y, i);

		//writing to file
		fprintf(result, "y = %lf, x = %lf\n", y, i);
	}

    fclose(result);

	return 0;
}
