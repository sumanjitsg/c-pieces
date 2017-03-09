#include <stdio.h>

/* Count blanks, tabs and newlines
 * from an input stream
 */

int main()
{
	int c;
	int num_spaces, num_tabs, num_newlines;

	num_spaces = num_tabs = num_newlines = 0;

	printf("---------------------------\n");
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++num_spaces;
		else if (c == '\t')
			++num_tabs;
		else if (c == '\n')
			++num_newlines;
	}

	printf("\n---------------------------\n"
			"Number of Blanks: %d\n"
			"Number of Tabs: %d\n"
			"Number of Newlines: %d\n"
			"---------------------------\n",
			num_spaces, num_tabs, num_newlines);
	return 0;
}
