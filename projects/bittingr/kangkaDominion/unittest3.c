/* 	Unit Test 3 - initializeGame()
	
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

int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);

int main(int argc, char* argv[]) {
	int successCount = 0;
	int TOTAL_COUNT = 5;
	
	struct gameState* game = newGame();
	int validKdCards[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};
	
	printf("----------------- UNIT TEST 3: initializeGame() ----------------\n");
	
	/*** Test 1 ***/
	if (initializeGame(4, validKdCards, 30, game) > -1) {
		successCount++;
		
		/*** Test 2 ***/
		if (supplyCount(curse, game) != 30) {
			printf("Test failed. Incorrect initial count for Curse.\n");
		}
		else {
			successCount++;
		}
		
		/*** Test 3 ***/
		if (supplyCount(duchy, game) != 12) {
			printf("Test failed. Incorrect initial supply count for Duchy.\n");
		}
		else {
			successCount++;
		}
	}
	else {
		printf("Test failed. Valid initialization failed.\n");
	}
	
	/*** Test 4 ***/
	int invalidKdCards[10] = {curse, curse, duchy, province, copper, silver, gold, adventurer, council_room, feast};
	
	if (initializeGame(4, invalidKdCards, 30, game) > -1) {
		printf("Test Failed. Game should not initialize when there are duplicate cards in kingdom cards array.\n");
	}
	else {
		successCount++;
	}
	
	/*** Test 5 ***/
	if (initializeGame(5, validKdCards, 30, game) > -1) {
		printf("Test Failed. Game should not initialize when number of players is over the max allowed.\n");
	}
	else {
		successCount++;
	}
	
	// Print final results
	printf("%i out of %i tests passed.\n", successCount, TOTAL_COUNT);
	
	return 0;
}
