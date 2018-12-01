/* 	Unit Test 1 - isGameOver()
	
	Rachel Bitting
	10/24/2018
*/


#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

int main(int argc, char* argv[]) {
	int successCount = 0;
	int TOTAL_COUNT = 3;
	struct gameState* g = malloc(sizeof(struct gameState));	// Create gameState
	
	printf("----------------- UNIT TEST 1: isGameOver() ----------------\n");
	
	/*** Test 1 ***/
	g->supplyCount[3] = 0; // Initialize province enum supply count as 0
	if (isGameOver(g) == 1) {
		successCount++;
	}
	else {
		printf("Test 1 failed. 0 supply count for province should return true for game over.\n");
	}
	g->supplyCount[3] = 1; // Revert province supply count to non-zero
	
	/*** Test 2 ***/
	// Initialize 3 card supply counts as 0
	g->supplyCount[2] = 0; 
	g->supplyCount[18] = 0; 
	g->supplyCount[6] = 0;
	if (isGameOver(g) == 1) {
		successCount++;
	}
	else {
		printf("Test 2 failed. 0 supply count for three cards should return true for game over.\n");
	}
	
	/*** Test 3 ***/
	int i;
	// Set every card supply to >0
	for (i = 0; i < 25; i++) {
		g->supplyCount[i] = 5;
    }
	if (isGameOver(g) == 0) {
		successCount++;
	}
	else {
		printf("Test 3 failed. Game over returned true when only 2 decks are out of cards.\n");
	}
	
	// Print final results
	printf("%i out of %i tests passed.\n", successCount, TOTAL_COUNT);
	
	return 0;
}
