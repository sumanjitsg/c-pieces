#include <stdio.h>

/* Ex. 1-3
 * print Fahrenheit - Celsius table
 * for fahr = 0, 20, ..., 300; floating-point values
 */

int main()
{
	char *fahrstr = "Fahrenheit";
	char *celstr = "Celsius";

	float fahr, celsius;
	int min, max, step;
	min = 0;
	max = 300;
	step = 20;

	printf("Fahrenheit - Celsius Table\n");
	printf("--------------------------\n");
	printf("%10s\t%7s\n", "Fahrenheit", "Celsius");

	for (fahr = 0; fahr <= 300; fahr += step) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%10.0f\t%+7.1f\n", fahr, celsius);
	}

	return 0;
}
