#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input[20] = {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};

	// open output file for writing
	FILE *fptr = fopen("ProgramTwo.out", "w");
	if(fptr == NULL){
		printf("Couldn't open file\n");
		return -1;
	}

	// iterate over input array and check if ASCII value is in a subset of these, then print to consol and file
	for (int i = 0; i < 20; i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z'){	// lower case
			printf("Code: %d    Type: Lower Case    ASCII Char: %c\n", input[i], input[i]);
			fprintf(fptr, "Code: %d    Type: Lower Case    ASCII Char: %c\n", input[i], input[i]);
		} else if(input[i] >= 'A' && input[i] <= 'Z'){ // upper case
			printf("Code: %d    Type: Upper Case    ASCII Char: %c\n", input[i], input[i]);
			fprintf(fptr, "Code: %d    Type: Upper Case    ASCII Char: %c\n", input[i], input[i]);
		} else if(input[i] >= '0' && input[i] <= '9'){	// numbers
			printf("Code: %d    Type: Number   ASCII Char: %c\n", input[i], input[i]);
			fprintf(fptr, "Code: %d    Type: Number   ASCII Char: %c\n", input[i], input[i]);
		} else if(input[i] >= '!' && input[i] <= '/'){	// special characters
			printf("Code: %d    Type: Special Char   ASCII Char: %c\n", input[i], input[i]);
			fprintf(fptr, "Code: %d    Type: Special Char   ASCII Char: %c\n", input[i], input[i]);
		} else if(input[i] >= 0 && input[i] <= 32){	// whitespaces
			printf("Code: %d    Type: White Space   ASCII Char: %c\n", input[i], input[i]);
			fprintf(fptr, "Code: %d    Type: White Space   ASCII Char: %c\n", input[i], input[i]);
		} else{
			printf("Error in parsing ASCII\n");
		}
	}
	fclose(fptr);
	return 0;
}
