#include <stdio.h>

/* Copy input stream to output, replacing each string of
 * one or more blanks by a single blank.
 */

int main()
{
	int c, first_space;

	first_space = 1;
	printf("-------------------------\n");
	while ((c = getchar()) != '\n' && c != EOF) {
		if (c == ' ' && first_space) {
			putchar(c);
			first_space = 0;
		} else if (c == ' ' && !first_space)
			continue;
		else {
			putchar(c);
			first_space = 1;
		}
	}

	printf("\n-------------------------\n");
	return 0;
}
