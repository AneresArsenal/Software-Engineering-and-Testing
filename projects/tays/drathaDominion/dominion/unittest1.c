/*
Assignment 3 - Learn how to create unit tests
Unit Test 1 
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // initialize and set variables
    struct gameState pre, post;
    int k[10] = {feast, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    printf("Starting Unit Test 1 - playBaron function \n\n");

    initializeGame(2, k, 1234, &pre);
    printf("Game initialized \n\n");

    int choice1 = 1,
        // handPos = 0,
        // bonus = 0,
        currentPlayer = 1,
        r = 10;

    pre.handCount[currentPlayer] = r;

    // randomly assign cards
    for (int i = 0; i < r; i++)
    {
        pre.hand[currentPlayer][i] = k[9 - i];
    }

    memcpy(&post, &pre, sizeof(struct gameState));
    printf("Test case 1: Estate card exist in hand and player choose to discard estate. \n\n");
    // set one to be estate
    post.hand[currentPlayer][4] = estate;


    // call the refactored functions
    baronCard(choice1, &post);

    // assert the results
    // bonus points should be added
    if (post.coins != pre.coins + 4)
    {
        printf("Bug #1 found! Bonus not added properly! \n");
        printf("Pre-call coin tally: %d \n", pre.coins);
        printf("Post-call coin tally: %d \n\n", post.coins);
    }

    if (post.handCount[currentPlayer] != pre.handCount[currentPlayer] - 2)
    {
        printf("Bug Found! Baron card and estate card found should both be discarded! \n");
        printf("Pre-call handCount: %d \n", pre.handCount[currentPlayer]);
        printf("Post-call handCount: %d \n\n", post.handCount[currentPlayer]);
    }

    if (post.supplyCount[estate] != pre.supplyCount[estate])
    {
        printf("Bug #2 found! No estate card should be gained. \n");
        printf("Pre-call supply count for Estate: %d \n", pre.supplyCount[estate]);
        printf("Post-call supply count for Estate: %d \n\n", post.supplyCount[estate]);
    }

    int j = post.discardCount[currentPlayer];
    int countEstate = 0;

    for (int i = 0; i < j; i++)
    {
        if (post.discard[currentPlayer][i] == estate)
        {
            countEstate++;
        }
    }

    // only one estate card should be in the discard pile (the one that is discarded)
    if (countEstate != 1)
    {
        printf("Bug Found!Only one Estate card should exist in discard pile! \n");
        printf("Pre-call Estate discardCount: %d \n", 0);
        printf("Post-call Estate discardCount: %d \n\n", countEstate);
    }

    memcpy(&post, &pre, sizeof(struct gameState));
    printf("Test case 2: Estate card do not exist in hand and player choose to discard estate. \n\n");

    // call the refactored functions
    baronCard(choice1, &post);

    // assert the results
    // bonus points should not be added
    if (post.coins == pre.coins)
    {
        printf("Valid! Bonus not added! \n");
        printf("Pre-call coin tally: %d \n", pre.coins);
        printf("Post-call coin tally: %d \n\n", post.coins);
    }

    if (post.handCount[currentPlayer] != pre.handCount[currentPlayer] - 1)
    {
        printf("Error!  Baron card not discarded! \n");
        printf("Pre-call handCount: %d \n", pre.handCount[currentPlayer]);
        printf("Post-call handCount: %d \n\n", post.handCount[currentPlayer]);
    }

        if (post.supplyCount[estate] != pre.supplyCount[estate] - 1)
    {
        printf("Bug #2 found! Estate card not gained. \n");
        printf("Pre-call supply count for Estate: %d \n", pre.supplyCount[estate]);
        printf("Post-call supply count for Estate: %d \n\n", post.supplyCount[estate]);
    }


    memcpy(&pre, &post, sizeof(struct gameState));
    printf("Test case 3: Estate card do not exist in hand and player choose not to discard estate. \n\n");

    // call the refactored functions
    baronCard(choice1, &post);

    // assert the results
    // bonus points should be added
    if (post.coins == pre.coins)
    {
        printf("Valid! Bonus not added! \n");
        printf("Pre-call coin tally: %d \n", pre.coins);
        printf("Post-call coin tally: %d \n\n", post.coins);
    }

    if (post.handCount[currentPlayer] == pre.handCount[currentPlayer] - 1)
    {
        printf("Valid! Only Baron card discarded! \n");
        printf("Pre-call handCount: %d \n", pre.handCount[currentPlayer]);
        printf("Post-call handCount: %d \n\n", post.handCount[currentPlayer]);
    }

    if (post.handCount[currentPlayer] != pre.handCount[currentPlayer] - 1)
    {
        printf("Error! Baron card not discarded! \n");
        printf("Pre-call handCount: %d \n", pre.handCount[currentPlayer]);
        printf("Post-call handCount: %d \n\n", post.handCount[currentPlayer]);
    }

        if (post.supplyCount[estate] != pre.supplyCount[estate] - 1)
    {
        printf("Bug #2 found! Estate card not gained. \n");
        printf("Pre-call supply count for Estate: %d \n", pre.supplyCount[estate]);
        printf("Post-call supply count for Estate: %d \n\n", post.supplyCount[estate]);
    }

    printf("Unit Test 1 completed! \n\n");
    return 0;
}
