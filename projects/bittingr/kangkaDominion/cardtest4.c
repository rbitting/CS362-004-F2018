/* 	Card Test 3 - Embargo
	
	Rachel Bitting
	10/28/2018
	
	+2 coins. Trash this. Add an Embargo token to a Supply pile. (For the rest of the game, when a player buys a card from that pile, they gain a Curse.)
	
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
		else {
			printf("%s FAILED\n", string);
		}
	}
	// Otherwise check for match
	else {
		if (a == b) {
			printf("%s PASSED\n", string);
		}
		else {
			printf("%s FAILED\n", string);
		}
	}
}

int main(int argc, char* argv[]) {
    int discarded = 1;
    int shuffledCards = 0;

    int handpos = 0, choice1 = smithy, choice2 = -1, choice3 = -1, bonus = 0; 
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);


	// ----------- CARD TEST 4: Testing Embargo (+2 coins) --------------
	printf("----------------- CARD TEST 4: Embargo ----------------\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(embargo, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	// Hand should have 1 card added after playing Embargo
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded);
	
	// Deck should have 1 less than before card play
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] + shuffledCards);
	
	// Embargo on choice1 (smithy) should be increased by 1
	printf("embargo tokens on smithy = %i, expected = %i\n", testG.embargoTokens[choice1], G.embargoTokens[choice1] + 1);
	
	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded, 0, "Hand counts match?");
	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] + shuffledCards, 0, "Deck counts match?");
	assertTrue(testG.embargoTokens[choice1], G.embargoTokens[choice1] + 1, 0, "Embargo tokens on smithy match?");
	
	return 0;
}