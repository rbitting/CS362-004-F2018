/* 	Unit Test 4 - newGame()
	
	Rachel Bitting
	10/25/2018
	
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
	int TOTAL_COUNT = 2;
	
	struct gameState* game = newGame();
	
	printf("----------------- UNIT TEST 4: newGame() ----------------\n");
	
	/*** Test 1 ***/
	if (game != NULL) {
		successCount++;
	}
	else {
		printf("Test failed. newGame() returned null.\n");
	}
	
	/*** Test 2 ***/
	if (game->numPlayers == 0) {
		successCount++;
	}
	else {
		printf("Test failed. gameState variables not initialized.\n");
	}
	
	// Print final results
	printf("%i out of %i test passed.\n", successCount, TOTAL_COUNT);
	
	return 0;
}
