#include <stdio.h>
#include <string.h>

/* Print input one word per line
 * (Multiple single apostrophes between words get printed as one)
 */

int main()
{
	int c;
	int first_punc, fresh_line;
	const char *word_separators = " \t,.;\'\"\\!:?/=+*-()[]{}<>\n";

	fresh_line = 1;
	first_punc = 1;

	printf("=========================\n");
	while ((c = getchar()) != EOF) {
		if (!fresh_line && strstr(word_separators, (char *)&c)) {
			if (c == '\'' && !feof(stdin) && first_punc) {
				c = getchar();
				if (strstr(word_separators, (char *)&c) == NULL)
					putchar('\'');
				ungetc(c, stdin);
			} else if (c != '\n' && first_punc) {
				first_punc = 0;
				if (!feof(stdin))
					putchar('\n');
			}
		}
		if (strstr(word_separators, (char *)&c) == NULL) {
			fresh_line = 0;
			first_punc = 1;
			putchar(c);
		}
		if (feof(stdin)) {
			fresh_line = 1;
			first_punc = 1;
			printf("--------------------\n");
		}
	}
	printf("\n=========================\n");

	return 0;
}
