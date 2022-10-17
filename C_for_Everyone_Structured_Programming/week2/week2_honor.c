//=============================================================================
//! \brief      Use a struct to define a card as an enumerated member that is its suit value and a short that is its pips value.
//!             Write a function that randomly shuffles the deck.
//!             Then deal out 7 card hands and evaluate the probability that a hand has no pair, one pair,
//!             two pair, three of a kind, full house and 4 of a kind.
//!             Use at least 1 million randomly generated hands.
//!
//! \date       Oct 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_CARDS 52
#define PICKED_CARDS 7
#define PICKTIMES 10000000

// decalre the combination of cards as global variable
int no_pair = 0, one_pair = 0, two_pair = 0, three_of_a_kind = 0, full_house = 0, four_of_a_kind = 0, royal_flush = 0, straight_flush = 0, flush = 0, straight = 0;
int cnt1 = 0, cnt2 = 0;
int cnt_suits[4] = {0};
int cnt_pips[13] = {0};

typedef enum suit
{
    spade = 0,
    heart,
    diamond,
    club
} suit;

typedef struct card
{
    suit s;
    short p;
} card;

void generate_deck(card deck[])
{
    for (int i = 0; i < NUM_OF_CARDS; i++)
    {
        deck[i].s = i % 4;
        deck[i].p = i % 13;
    }
}

void print_card(card picked[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%d-%d ", picked[i].s, picked[i].p);
    }
    printf("\n");
}

int check_duplicate(int index, int already_picked[])
{
    for (int i = 0; i < PICKED_CARDS; i++)
    {
        if (already_picked[i] == index)
        {
            return 1;
        }
    }
    // if not duplicated, put this index into already_picked array
    for (int i = 0; i < PICKED_CARDS; i++)
    {
        if (already_picked[i] == -1)
        {
            already_picked[i] = index;
            break;
        }
    }
    return 0;
}

void pick_cards(card deck[], card picked[])
{
    int already_picked[PICKED_CARDS] = {-1, -1, -1, -1, -1, -1, -1};
    for (int i = 0; i < PICKED_CARDS; i++)
    {
        int random = rand() % NUM_OF_CARDS;
        if (check_duplicate(random, already_picked))
        {
            i--; // if the card is already picked, pick again
        }
        else
        {
            picked[i] = deck[random];
        }
    }
}

void checkFlush(card picked[], int valid_suit, int *isRoyalFlush, int *isStraightFlush)
{
    int pips[13] = {0};
    for (int i = 0; i < PICKED_CARDS; i++)
    {
        if (picked[i].s == valid_suit)
        {
            pips[picked[i].p]++;
        }
    }
    // 10, J, Q, K, A and flush
    if ((pips[12] > 0) && (pips[11] > 0) && (pips[10] > 0) && (pips[9] > 0) && (pips[0] > 0))
    {
        *isRoyalFlush = 1;
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        if (pips[i] > 0 && pips[i + 1] > 0 && pips[i + 2] > 0 && pips[i + 3] > 0 && pips[i + 4] > 0)
        {
            *isStraightFlush = 1;
            return;
        }
        // 10, J, Q, K, A
        if (pips[0] > 0 && pips[9] > 0 && pips[10] > 0 && pips[11] > 0 && pips[12] > 0)
        {
            *isStraightFlush = 1;
            return;
        }
    }
}

void calculate_combo(card picked[])
{
    int pips[13] = {0};
    int suits[4] = {0};
    int pair = 0, three = 0, four = 0;
    int flush_flag = 0, straight_flag = 0;
    for (int i = 0; i < PICKED_CARDS; i++)
    {
        pips[picked[i].p]++;
        suits[picked[i].s]++;
    }
    for (int i = 0; i < 13; i++)
    {
        if (pips[i] == 2)
        {
            pair++;
        }
        else if (pips[i] == 3)
        {
            three++;
        }
        else if (pips[i] == 4)
        {
            four++;
        }
    }
    int valid_suit = -1;
    for (int i = 0; i < 4; i++)
    {
        if (suits[i] >= 5)
        {
            flush_flag = 1;
            valid_suit = i;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (pips[i] > 0 && pips[i + 1] > 0 && pips[i + 2] > 0 && pips[i + 3] > 0 && pips[i + 4] > 0)
        {
            straight_flag = 1;
        }
        // 10, J, Q, K, A
        if (pips[0] > 0 && pips[9] > 0 && pips[10] > 0 && pips[11] > 0 && pips[12] > 0)
        {
            straight_flag = 1;
        }
    }
    int isRoyalFlush = 0;
    int isStraightFlush = 0;
    if (flush_flag && straight_flag)
    {
        checkFlush(picked, valid_suit, &isRoyalFlush, &isStraightFlush);
    }
    if (isRoyalFlush)
    {
        royal_flush++;
    }
    else if (isStraightFlush)
    {
        straight_flush++;
    }
    else if (four)
    {
        four_of_a_kind++;
    }
    // two threes like (9,9,9,J,J,J) is also considered full house
    else if ((three > 0 && pair > 0) || (three == 2))
    {
        full_house++;
    }
    else if (flush_flag)
    {
        flush++;
    }
    else if (straight_flag)
    {
        straight++;
    }
    else if (three > 0)
    {
        three_of_a_kind++;
    }
    else if (pair >= 2)
    {
        two_pair++;
    }
    else if (pair == 1)
    {
        one_pair++;
    }
    else
    {
        no_pair++;
    }
}

void print_result()
{
    double no_pair_prob = (double)no_pair / PICKTIMES;
    double one_pair_prob = (double)one_pair / PICKTIMES;
    double two_pair_prob = (double)two_pair / PICKTIMES;
    double three_of_a_kind_prob = (double)three_of_a_kind / PICKTIMES;
    double full_house_prob = (double)full_house / PICKTIMES;
    double four_of_a_kind_prob = (double)four_of_a_kind / PICKTIMES;
    double royal_flush_prob = (double)royal_flush / PICKTIMES;
    double straight_flush_prob = (double)straight_flush / PICKTIMES;
    double flush_prob = (double)flush / PICKTIMES;
    double straight_prob = (double)straight / PICKTIMES;

    printf("Royal Flush: %d, probability: %f, expected: 0.00003232\n", royal_flush, royal_flush_prob);
    printf("Straight Flush: %d, probability: %f, expected: 0.00027851\n", straight_flush, straight_flush_prob);
    printf("Four of a kind: %d, probability: %f, expected: 0.00168067\n", four_of_a_kind, four_of_a_kind_prob);
    printf("Full house: %d, probability: %f, expected: 0.02596102\n", full_house, full_house_prob);
    printf("Flush: %d, probability: %f, expected: 0.03025494\n", flush, flush_prob);
    printf("Straight: %d, probability: %f, expected: 0.04619382\n", straight, straight_prob);
    printf("Three of a kind: %d, probability: %f, expected: 0.04829870\n", three_of_a_kind, three_of_a_kind_prob);
    printf("Two pair: %d, probability: %f, expected: 0.23495536\n", two_pair, two_pair_prob);
    printf("One pair: %d, probability: %f,  expected: 0.43822546\n", one_pair, one_pair_prob);
    printf("No pair: %d, probability: %f, expected: 0.17411920\n", no_pair, no_pair_prob);
}

int main(void)
{
    time_t t;
    srand((unsigned)time(&t)); // Initialize random number generator
    card deck[NUM_OF_CARDS];
    generate_deck(deck);
    card picked[PICKED_CARDS];
    for (int i = 0; i < PICKTIMES; i++)
    {
        pick_cards(deck, picked);
        calculate_combo(picked);
    }
    print_result();
    return 0;
}