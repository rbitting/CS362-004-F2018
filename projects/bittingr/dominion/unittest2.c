/* 	Unit Test 2 - getCost()
	
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

int getCost(int cardNumber);

int main(int argc, char* argv[]) {
	int successCount = 0; 	// Keep track of successes
	int total_count = 0;	// Keep track of total tests
	
	printf("----------------- UNIT TEST 2: getCost() ----------------\n");
	
	// Check every card for correct cost
	
	if (getCost(curse) != 0) {
		printf("Curse cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(estate) != 2) {
		printf("Estate cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(duchy) != 5) {
		printf("Duchy cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(province) != 8) {
		printf("Province cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(copper) != 0) {
		printf("Copper cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(silver) != 3) {
		printf("Silver cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(gold) != 6) {
		printf("Gold cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(adventurer) != 6) {
		printf("Adventurer cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(council_room) != 5) {
		printf("Council Room cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(council_room) != 5) {
		printf("Council Room cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(feast) != 4) {
		printf("Feast cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(gardens) != 4) {
		printf("Gardens cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(mine) != 5) {
		printf("Mine cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(remodel) != 4) {
		printf("Remodal cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(smithy) != 4) {
		printf("Smithy cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(village) != 3) {
		printf("Village cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(baron) != 4) {
		printf("Baron cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(great_hall) != 3) {
		printf("Great Hall cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(minion) != 5) {
		printf("Minion cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(steward) != 3) {
		printf("Steward cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(tribute) != 5) {
		printf("Tribute cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(ambassador) != 3) {
		printf("Ambassador cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(cutpurse) != 4) {
		printf("Cutpurse cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(embargo) != 2) {
		printf("Embargo cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(outpost) != 5) {
		printf("Outpost cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(salvager) != 4) {
		printf("Salvager cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(sea_hag) != 4) {
		printf("Sea Hag cost is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(treasure_map) != 4) {
		printf("Treasure Map is incorrect.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
	if (getCost(90) != -1) {
		printf("Invalid card did not return -1.\n");
	}
	else {
		successCount++;
	}
	total_count++;
	
  
	// Print final results
	printf("%i out of %i tests passed.\n", successCount, total_count);

	return 0;
}