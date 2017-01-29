#include <stdio.h>

/* Copy input to output while replacing tabs with \t,
 * backspace with \b and each backslash with \\
 * Use 'Ctrl-H' to send a backspace (^H is same as backspace 
 * having ASCII character #8)
 */

int main()
{
	int c;

	printf("--------------------\n");
	while ((c = fgetc(stdin)) != '\n' && c != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			fputc(c, stdout);
	}

	printf("\n--------------------\n");
	return 0;
}
