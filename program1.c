#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


int16_t input[11][3] = {{-7, 10, 4}, { -7, 9, 4}, {-7, 10, 5}, {-10, 10, 4}, {236, 10, 8}, {0354, 8, 8}, {0xEB, 16, 8}, {-125, 10, 8}, {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16}};

static FILE *fptr;

void dec2bin(int16_t dec){
	uint16_t absdec = abs(dec);
	if(absdec > 1)
		dec2bin(absdec/2);

	fprintf(fptr, "%d", absdec % 2);
	return;
}

void dec2binmag(int16_t dec){
	if(dec < 1){
		fprintf(fptr, "1");
		dec2bin(dec);
	}
	else{
		fprintf(fptr, "0");
		dec2bin(dec);
	}
	return;
}

void dec2bin1s(int16_t dec, uint16_t operand) 
{ 
    int i; 
    for (i = 1 << operand; i > 0; i = i / 2) 
        (~(abs(dec)) & i)? fprintf(fptr, "1"): fprintf(fptr, "0"); 
} 

void dec2bin2s(int dec, int operand) 
{ 
    int i; 
    for (i = 1 << operand; i > 0; i = i / 2) 
        (dec & i)? fprintf(fptr, "1"): fprintf(fptr, "0"); 
} 

int main(void) {

	// open output file for writing
	fptr = fopen("ProgramOne.out", "w");
	if(fptr == NULL){
		printf("Couldn't open file\n");
		return -1;
	}

	for(int i=0; i < 11; i++){
		if(((input[i][1] == 8) || (input[i][1] == 10) || (input[i][1] == 16)) && ((input[i][2] == 4) || (input[i][2] == 8) || (input[i][2] == 16))){
			fprintf(fptr, "\nInput:				Value %d    Radix %d		Operand %d\n", input[i][0], input[i][1], input[i][2]);
			fprintf(fptr, "Output:				Value		Maximum		Minimum\n");


			
			fprintf(fptr, "Binary (abs):			0b");
			dec2bin(input[i][0]);

			fprintf(fptr, "	0b");
			double max_size = pow((double)2, (double)input[i][2]);
			max_size -= 1;
			dec2bin((uint16_t)max_size);

			fprintf(fptr, "	0b");
			dec2bin2s(0, input[i][2]);

			fprintf(fptr, "\nOctal (abs):		           0%o       0%o		0\n", abs(input[i][0]), (uint16_t)max_size);

			fprintf(fptr, "Decimal (abs): 		         %d        	%d			0\n", abs(input[i][0]), (uint16_t)max_size);

			fprintf(fptr, "Hex (abs):    		        0x%X       	0x%X			0x0\n", abs(input[i][0]), (uint16_t)max_size);

			fprintf(fptr, "Binary (1's):			0b");
			dec2bin1s(input[i][0], input[i][2]);

			double max_size1 = pow((double)2, ((double)input[i][2] - 1));
			max_size1 -= 1;
			fprintf(fptr, "	0b");
			dec2bin((uint16_t)max_size1);

			double min_size1 = pow((double)2, ((double)input[i][2] - 1));
			fprintf(fptr, "	0b");
			dec2bin((uint16_t)min_size1);
			fprintf(fptr, "\n");

			fprintf(fptr, "Binary (2's):			0b");
			dec2bin2s(input[i][0], input[i][2]);

			double max_size2 = pow((double)2, ((double)input[i][2] - 1));
			max_size2 -= 1;
			fprintf(fptr, "	0b");
			dec2bin((uint16_t)max_size2);

			double min_size2 = pow((double)2, ((double)input[i][2] - 1));
			min_size2 += 1;
			fprintf(fptr, "	0b");
			dec2bin((uint16_t)min_size2);

			fprintf(fptr, "\n");

			fprintf(fptr, "Binary (sign mag):		0b");
			dec2binmag(input[i][0]);

			double max_sizem = pow((double)2, ((double)input[i][2] - 1));
			max_sizem -= 1;
			fprintf(fptr, "	0b");
			dec2binmag((uint16_t)max_sizem);

			fprintf(fptr, "	0b");
			dec2binmag(-((uint16_t)max_sizem));
			fprintf(fptr, "\n");


		}
		else{
			fprintf(fptr, "Error\n");
		}
	}
	fclose(fptr);
	return 0;
}
