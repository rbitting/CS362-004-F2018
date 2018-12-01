/* 	Card Test 1 - Adventurer
	
	Rachel Bitting
	10/28/2018
	
	Reveal cards from your deck until you reveal 2 Treasure cards. Put those Treasure cards into your hand and discard the other revealed cards.
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


	// ----------- CARD TEST 2: Testing Adventurer --------------
	printf("----------------- CARD TEST 2: Adventurer ----------------\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	// Cards being added to hand
	newCards = 2;
	
	// Hand should have 2 more (treasure) cards after playing adventurer 
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	
	// Deck should be 2 fewer than original
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	
	// Coins should be greater than original
	printf("coins = %d, expected = greater than %d\n", testG.coins, G.coins);
	
	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded, 0, "Hand counts match?");
	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards, 0, "Deck counts match?");
	assertTrue(testG.coins, G.coins, 1, "Coin count has increased?");
	
	return 0;
}
