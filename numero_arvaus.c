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
	
	/* Game in running.... */
	do{
		/* Update round number */
		count++;
		
		/* User quess */
		printf(" Give number: ");
		scanf("%d", &your_quess);
		
		/* Check how well user quess */
		
		/* Quess too high */
		if(your_quess > random_number)		{
			printf(" Your quess is too high \n");
		}
		/* Quess too low */
		else if(your_quess < random_number){
			printf(" Your quess is too low \n");
		}
		/* Quess is correct! */
		else{
			printf(" Wow! You guessed corrected number in round %d \n", count);
		}
	/* Continue untill quess is correct */
	}while(random_number != your_quess);
	
	/* Game is over */	
	return 0;
}
