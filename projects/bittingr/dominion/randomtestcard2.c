/* 	Random Test 2 - Smithy
	
	Rachel Bitting
	11/14/2018
	
*/

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>

#define TESTS_TO_RUN 2000
#define VILLAGE_CARDS_ADDED 1
#define DISCARDED 1

int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus);

void assertTrue(int a, int b, int operator, char* string) {
	// If operator is true, check that a is greater than b instead of equal to
	if ((a > b && operator == 1) || (a == b && operator != 1)) {
		printf("%s PASSED\n", string);
	}
	else {
		printf("%s FAILED\n", string);
	}
}

int main(int argc, char* argv[]) {
	// Use current time as seed for random generator 
    srand(time(0));
	
	printf("**************** randomtestcard2.c - Testing Village ****************\n");
	
	// Initialize variables
    int handpos = 0, choice1 = -1, choice2 = -1, choice3 = -1, bonus = 0; 
    int thisPlayer = 0;
    int shuffledCards = 0;
	int numOfPlayers, seed, i;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	
	for (i=0;i<TESTS_TO_RUN;i++) {
		struct gameState G, testG;
		
		// Get random vals for number of players and seed
		numOfPlayers = (rand() % (MAX_PLAYERS - 2)) + 2;	//Get a random number between 2 and max players
		seed = rand()+1;	// Seed should be a minimum of 1
		
		// Initialize a game state and player cards
		initializeGame(numOfPlayers, k, seed, &G);
		
		// Intentional failure to get 100% coverage
		if (i==0) {
			G.handCount[thisPlayer] = rand() % MAX_HAND;
			G.deckCount[thisPlayer] = -1;
			G.discardCount[thisPlayer] = MAX_DECK - G.deckCount[thisPlayer];
		}
		else {
			// Assign random vals for these hand, deck, and discard counts 	(consts defined in dominion.h)
			G.handCount[thisPlayer] = rand() % MAX_HAND;
			G.deckCount[thisPlayer] = rand() % MAX_DECK;
			G.discardCount[thisPlayer] = MAX_DECK - G.deckCount[thisPlayer];
		}
		
		// Calculate expected final deck count
		int expectedDeck = G.deckCount[thisPlayer] - VILLAGE_CARDS_ADDED + shuffledCards;
		// If zero, count from max deck
		if (G.deckCount[thisPlayer] == 0) {
			expectedDeck = MAX_DECK - VILLAGE_CARDS_ADDED + shuffledCards;
		}
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
		
		// Actions being added
		int newActions = 2;
		
		// Hand should have 1 card added after playing Village
		printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + VILLAGE_CARDS_ADDED - DISCARDED);
		
		// Deck should have 1 less than before card play
		printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], expectedDeck);
		
		// Actions should have 2 more added
		printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions);
		
		assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + VILLAGE_CARDS_ADDED - DISCARDED, 0, "Hand counts match?");
		assertTrue(testG.deckCount[thisPlayer], expectedDeck, 0, "Deck counts match?");
		assertTrue(testG.numActions, G.numActions + newActions, 0, "Number of actions match?");
	}
	
	return 0;
}