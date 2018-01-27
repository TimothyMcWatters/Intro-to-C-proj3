#include <stdio.h>

int getMax (int *list, int n);

//program sorts a user given list of numbers, and 
//organizes them in accending order.
int main (void) {

   int n = 0; //number to be sorted
	int i = 0; //counter
	int list[n]; //array of numbers to be sorted
	int max = 0;  //holds the arrays max index number from function getMax
	int temp;  
	int j = 0; //counter
	int tempHolder = 0; //holds the index while swapping
	
	//gets how many numbers need to be sorted
	printf("Input how many numbers you need sorted: ");
	scanf("%d", &n);
	
	//gets the list of numbers to sort
	printf("Input your list of numbers, one at a time, in any order: ");
	for (i = 0; i < n; ++i) {
	      scanf("%d", &list[i]);
			if ((i < n) && (n - (i + 1) > 0)) {
			   printf("%d more number(s)", n - (i + 1));
			}
	}
	
	temp = n;
	for (j = temp - 1; j >= 0; --j) {
	   //invokes function getMax
	   max = getMax (list, j + 1);
	   //printf("%d\n", max);
		tempHolder = list[max];
		list[max] = list[j];
		list[j] = tempHolder;
	}
	
	//prints new array of sorted numbers
	for (i = 0; i < n; ++i) {
	      printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}

// gets the max value's index in list[n]
int getMax (int *list, int n) {
   
	int tempMax;
	int i = 0;
	int j = 0;
	int index;
	
	tempMax = list[0];
	for (i = 1; i < n; ++i) {
	   if (list[i] > tempMax) {
		   tempMax = list[i];
		}
	}
	for (j = 0; j < n; ++j) {
      if (list[j] == tempMax) {
		   index = j;
		   break;
		}
	}

	return index;
}
