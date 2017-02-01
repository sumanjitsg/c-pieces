#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20

/* Print histogram of word lengths from input stream
 * Misreads arrow keys/special key combinations
 * (need ncurses/terminfo libraries to detect them)
*/

int main()
{
	int c, i, empty_stream, alpha_stream;
	char word[MAX_WORD_LEN] = {'\0'};
	char *word_separators = " \t\n,.;:?!@#$%^*()-_=+`~[]{}\\|\'\"<>/";

	alpha_stream = i = 0;
	empty_stream = 1;
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n\n");
	while ((c = fgetc(stdin)) != EOF) {
		if (!strstr(word_separators, (char *)&c)) {
			empty_stream = 0;
			alpha_stream = 1;
			word[i++] = c;
			if (feof(stdin))
				ungetc('\n', stdin);
		} else {
			word[i] = '\0';
			if (strlen(word) > 0) {
				printf("\n%-20s", word);
				while (i-- > 0) {
					fputc('-', stdout);
				}
				word[++i] = '\0';
			}
			if (c != ' ' && c != '\t' && c != '\n')
				empty_stream = 0;
			if (c == '\n' && !empty_stream) {
				empty_stream = 1;
				if (!alpha_stream)
					printf("\n--No alpha-numeric characters in stream--\n");
				else {
					alpha_stream = 0;
					printf("\n");
				}
				printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n\n");
			}
		}
	}

	return 0;
}
