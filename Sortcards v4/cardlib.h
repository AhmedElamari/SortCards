#pragma once

// header file for cardlib
// RJM 06/01/24


#include <string>

enum Suit { clubs, diamonds, hearts, spades };      // define suits

struct aCard {                          // defines a card
    int cardVal;                        // number 1..13
    Suit cardSuit;                      // suit
};

std::string cardToStr(aCard c);			// declare function to represent a card as a two character string

aCard getCard(std::string stdno);        // declares function to get a card from stdno string

int comparecards(aCard c1, aCard c2); // declares function to compare two cards

void SwapCards(int n1, int n2); // declares function to swap two cards

void bubbleSort(aCard thePack[], int maxCard);// declares function to sort an array of cards
void printPack(std::string mess); // declares function to print the pack of cards
void Qsort (aCard thePack[], int lndx, int hndx, int& numSwaps, int& numComps);
int maxLevel(int n);
// function for maximum level recursion of a quicksort and mergesort function


