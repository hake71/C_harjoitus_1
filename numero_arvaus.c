/**
	* Version: 0.0.1
	* Author: Hannu Harju
	*/

/**
	*
	* Quess correct number between 0..100
	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NRO 100
int main(int argc, char *argv[]) {
	time_t t;
	unsigned int random_number, count, your_quess;
	
	/* Initialize random number generator */
	srand((unsigned) time(&t));

	/* Generate random number */
	random_number = rand() % MAX_NRO;

	/* Initialize counter */
	count = 0;
	
	/* Start information */
	printf(" Number is generater between 0..%d\n", MAX_NRO);
	printf(" start quessing ...\n");
	
	/* Game is running.... */
	do{

		/* User quess */
		char OK, merkki;
		
		OK = 1;
		your_quess = 0;
		printf(" Give number: ");
		
		/* Check user input */
		do{
			/* Read one char at time */
			merkki = getchar();
			/* If number, add value to ansver number */
			if((merkki >= '0') && (merkki <= '9')){
				your_quess = your_quess * 10 + (merkki - '0');
				OK = 1;
				
			/* If EOL (End Of Line),... */
			}else if(merkki == '\n'){
				/* Input OK, continue to value check ... */
				if(OK == 1){
					OK = 0;
				/* Input Not OK, entered new value... */
				} else {
					your_quess = 0;
					printf(" Give number: ");
				}
			/* Error case: Not number */
			}else{
				printf(" Error: Not number \"%c\"\n", merkki);	
				OK = 2;
			}
			/* Error case: entered value too big (>100) */
			if(your_quess > 100){
				printf(" Error: Entered value %d over maximun value %d \n", \
					your_quess, MAX_NRO);
				OK = 2;
			}
		}while(OK);
		
     
        /* Update round number */
		count++;
		
		/* Check how well user quess */
		
		/* Quess too high */
		if(your_quess > random_number)		{
			printf(" Round %d: Your quess is too high \n", count);
		}
		/* Quess too low */
		else if(your_quess < random_number){
			printf(" Round %d: Your quess is too low \n", count);
		}
		/* Quess is correct! */
		else{
			printf(" Wow! You guessed corrected number in round %d \n", \
				count);
		}
	/* Continue untill quess is correct */
	}while(random_number != your_quess);
	
	/* Game is over */	
	return 0;
}
