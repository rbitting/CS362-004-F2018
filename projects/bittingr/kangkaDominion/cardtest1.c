/* 	Card Test 1 - Smithy
	
	Rachel Bitting
	10/28/2018
	
*/


#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

void assertTrue(int a, int b, int operator, char* string) {
	// Operator boolean signals to check for greater than
	if (operator == 1) {
		if (a > b) {
			printf("%s PASSED\n", string);
		}
		else if (a != b) {
			printf("%s FAILED\n", string);
		}
	}
	// Otherwise check for match
	else {
		if (a == b) {
			printf("%s PASSED\n", string);
		}
		else if (a != b) {
			printf("%s FAILED\n", string);
		}
	}
}

int main(int argc, char* argv[]) {
	int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int handpos = 0, choice1 = -1, choice2 = -1, choice3 = -1, bonus = 0; 
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);


	// ----------- CARD TEST 1: Testing Smithy (+3 cards) --------------
	printf("----------------- CARD TEST 1: Smithy ----------------\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	// Cards being added to hand
	newCards = 3;
	
	// Hand should have 3 cards added after playing Smithy
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	
	// Deck should have 3 less than before card play
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	
	assertTrue(testG.handCount[thisPlayer],G.handCount[thisPlayer] + newCards - discarded, 0, "Hand counts match?");
	assertTrue(testG.deckCount[thisPlayer],G.deckCount[thisPlayer] - newCards + shuffledCards, 0, "Deck counts match?");
	
	return 0;
}
