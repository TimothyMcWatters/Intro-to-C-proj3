#include <stdio.h>

/**
 * Prints a histogram to the screen using horizontal bar chart.
 * Parameters:
 *   list - a list of integers
 *   n - the number of values in the list
 */
void printHistogram ( int *list, int n );

/**
 * This program requests data from the user and then
 * computes and prints a histogram. You may assume that
 * the data values entered are in the range of 0 to 9.
 */
int main ( void )
{
	int i, n, j, l, k, total;

	// Data entry
	//
	printf ("How many values in your data set? ");
	scanf ("%d", &n);

	int list[n];
	for (i=0; i < n; i++) {
		printf ("Enter a value: ");
		scanf ("%d", &list[i]);
	}

	// Processing data to compute histogram
	//
	int hist[10];
    
   for (j = 0; j <= 9; ++j) {
      total = 0;
      for (k = 0; k < n; ++k) {
         if (list[k] == j) {
            total = total + 1;
         }
      }
      hist[j] = total;
   }
   
   //printing histogram overview
   //although this part was not explicitly requested
   //in the instructions, it showed it in the example.
   printf("{");
   for (l = 0; l <= 9; ++l) {
      printf("%d", hist[l]);
         if (l <= 8) {
            printf(", ");
         }
   }
   printf("}\n\n");

	// Printing histogram
	printHistogram ( list, n);

	return 0;
}

void printHistogram ( int *list, int n )
{
    int i, j;

    for (i=0; i < 10; i++) {
		printf ("[%d] ", i);
		for (j = 0; j < n; j++) {
			if (list[j] == i) {
            printf ("*");
         }
      }
      printf ("\n");
    }
}
