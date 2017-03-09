#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* Print Celsius - Fahrenheit table
 * for celsius values - 0, 20, ..., 300
 */

int main()
{
	int celsius;
	float fahr;

	printf("Celsius - Fahrenheit Table\n"
			"==========================\n"
			"Celsius\tFahrenheit\n");
	for(celsius = LOWER; celsius <= UPPER; celsius += STEP) {
		fahr = (5.0/9.0) * celsius + 32.0;
		printf("%7d\t%10.1f\n", celsius, fahr);
	}
	return 0;
}
