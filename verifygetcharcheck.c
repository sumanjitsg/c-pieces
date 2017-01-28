#include <stdio.h>

/* Verify that the expression getchar() != EOF
 * is 0 or 1
 * Press Enter or Ctrl+d (EOF) to mark end of stream (Enter is read as a character)
 * Press Ctrl+d (EOF) at beginning of stream to come out of loop
 */

int main()
{
	int c;

	while(c = getchar() != EOF)
		printf("%d\n", c);

	printf("%d\n", c);
	return 0;
}

