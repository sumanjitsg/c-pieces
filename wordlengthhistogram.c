#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 30

/* Print a histogram of the lengths of words
 * in input stream
 */

int main()
{
	int c;
	int i = 0;
	char word[MAX_WORD_LEN];
	char *word_separators = " \t,.;-_";

	printf("====================\n");
	while ((c = fgetc(stdin)) != '\n' || c != EOF) {
		if (strstr(word_separators, (char *)&c) == NULL)
			word[i++] = c;
		else {
			word[i] = '\0';
			i = 0;

			if (strlen(word) > 0) {
				printf("\n%-*s\t", MAX_WORD_LEN, word);
				while (word[i++] != '\0')
					fputc('-', stdout);
				fputc('\n', stdout);

				word[0] = '\0';
				i = 0;
			}
		}
	}

	return 0;
}
