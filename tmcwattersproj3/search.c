#include <stdio.h>

int searchLinear(int s, int *list, int n);
int searchBinary(int s, int *list, int n);

int main (void)
{
   const int n = 10;  
	int list[n];
	int numMore = 0;
	int i = 0;
	int s = 0;
	int valueLinear = 0;
	int valueBinary = 0;
	
	//collects 10 integers in ascending order
	printf("Input 10 positive integers, one at a time, in ascending order: ");
	scanf("%d", &(list[0]));
	
	for (i = 1; i < n; ++i) {
	   numMore = n - i;
		printf("Input %d more positive integers in ascending order: ", numMore);
		scanf("%d", &(list[i]));
	}
	
	//inputs a number to search for
	printf("\nInput a number to search for: ");
	scanf("%d", &s);
	
	//invokes fuction searchLinear
	valueLinear = searchLinear (s, list, n);
	
	//prints result of searchLinear
	if (valueLinear != -1) {
	   printf("The location of your searched number was located by linear search at index: %d\n", valueLinear);
	} 
	else {
	   printf("The value was not found via linear search.\n");
	} 
	
	//invokes function searchBinary
   valueBinary = searchBinary (s, list, n);
	
	//prints result of searchBinary
	if (valueBinary != -1) {
	   printf("The location of your searched number was located by binary search at index: %d\n", valueBinary);
	} 
	else {
	   printf("The value was not found via binary search.\n");
	} 

	return 0;
}

//function searchLiner iterates through the array list, and looks for the int s
int searchLinear(int s, int *list, int n) {
   int i = 0;
	int linearMatch = 0;  
	
	//search for int s, if found passes array index to linearMatch
	//if not found passes -1 to linearMatch
   for (i = 0; i < n; ++i) {
      if (list[i] == s) {
		   linearMatch = i;
		   break;
		}
		else {
		   linearMatch = -1;
		}
	}

   //returns array index or -1
   return linearMatch;
}

//function searchBinary searches through the array list by cutting the array in half and looks for s
int searchBinary(int s, int *list, int n) {	
	int lowestEle = 0;
	int highestEle = n - 1;
	int k = 0;
	int binaryMatch = 0;
	k = (lowestEle + highestEle) / 2;
	
	while (lowestEle <= highestEle) {
	   if (list[k] == s) {
		   binaryMatch = k;
			break;
		}
		else if (list[k] < s) {
		lowestEle = k + 1;
		}
		else {
		   highestEle = k - 1; 
		}
					
	   k = (lowestEle + highestEle) / 2;
	}
	
	if ((lowestEle > highestEle) && (k != s)) {
	   binaryMatch = -1;
	}
	
	//returns array index or -1				
   return binaryMatch;
}

