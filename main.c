#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double kwadratowa(double a, double b, double c, double x)
{
	return (a * x * x) + (b * x) + c;
}



int main(int argc, char *argv[]) {
    FILE *result;
	
    result = fopen("result.txt","w");
    if (result == NULL)
    {
        printf("Error with opening file\n");
        exit(1);
    }

	double a,b,c;

	double zakres1, zakres2;
	double length;

	int n;
	//pobieranie danych
	printf("Enter a,b,c\n");
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);
	printf("a = %lf\n", a);
	printf("%.2lfx^2 + %.2lfx + %.2lf", a,b,c);
	printf("\nPodaj range: ");
	scanf("%lf", &zakres1);
	scanf("%lf", &zakres2);
	printf("Zakres: (%lf - %lf)", zakres1, zakres2);
	printf("\Enter number of measurements:");
	scanf("%d", &n);


	//odległość pomiędzy zakresami
	length = fabs(zakres1 - zakres2);
	printf("Length =  %lf", length);

	double i;
	double y;
	//Obliczanie odległości pomiędzy punktami
	double between = length/(n-1);
	printf("\nBetween = %lf", between);

	//Obliczanie kolejnych punktów
	for (i = zakres1; i<= zakres2; i+=between)
	{
	//	x = x + (length/(n - 1)) * i;
		y = kwadratowa(a, b, c, i);
		printf("\ny = %.2lf, x = %.2lf", y, i);
		//wpisywanie do pliku
		fprintf(result, "y = %lf, x = %lf\n", y, i);
	}



    fclose(result);

	return 0;
}
