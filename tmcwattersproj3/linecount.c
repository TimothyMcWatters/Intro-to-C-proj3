#include <stdio.h>
#include <stdlib.h>

void linecount (FILE* inFile);

int main(void) {
   FILE* inFile = NULL;
	      
   // Open file
   inFile = fopen("myfile.txt", "r");
   
	// Invoke function linecount	
	linecount (inFile);
	   
   // Done with file, so close it   
   fclose(inFile);
   
   return 0;
}

// Function to read a file, count its \n, and print the number to a new file
void linecount (FILE* inFile) {

   FILE* outFile = NULL; 
   int countLine = 0; //counter
	//int fileNum;
	char c;

   // Prints error if file doesnt open or is busy
   if (inFile == NULL) {
      printf("Could not open file myfile.txt.\n");
   }
	// Otherwise counts each \n
	else {
	   while ((c = fgetc(inFile))!= EOF){
         if(c == '\n') {
			   countLine++;
			}
      }
	}

   // Open file
   outFile = fopen("newfile.txt", "w");
   
   if (outFile == NULL) {
      printf("Could not open file myoutfile.txt.\n");
   }
   
   // Write to file
   fprintf(outFile, "Total number of lines in the file: %d\n", countLine);
   
   // Finished, close file
   fclose(outFile);

   return;
}