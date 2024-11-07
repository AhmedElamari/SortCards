#include "cardlib.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

const int maxCard = 5; // maximum number of cards in a pack

aCard thePack[maxCard];

void printPack(string mess) { // print the pack of cards
    cout << mess << ":";
    for (int ct = 0; ct < maxCard; ct++) // for each card
        cout << cardToStr(thePack[ct]) << ',';
}

int maxRecursionLevel = 0; // maximum level of recursion

void Qsort(aCard thePack[], int lndx, int hndx, int& numSwap, int& numComp, int currentRecursion = 0)
{
    if (currentRecursion > maxRecursionLevel) {
        maxRecursionLevel = currentRecursion;
    }
    aCard pivot = thePack[(lndx + hndx) / 2];
    int i = lndx, j = hndx;
    do {
        while (comparecards(pivot, thePack[i]) == 1) {
            i++; numComp++;
        } numComp++;
            while (comparecards(thePack[j], pivot) == 1) {
                j--; numComp++;
            } numComp++;
        if (i <= j) {
            if (i < j) SwapCards(i, j); numSwap++; 
            i++; j--;
        }
    } while (i <= j);
    if (lndx < j) Qsort(thePack, lndx, j, numSwap, numComp, currentRecursion + 1);
    if (i < hndx) Qsort(thePack, i, hndx, numSwap, numComp, currentRecursion + 1);
}

    void SwapCards(int n1, int n2) { // swap two cards
        aCard temp = thePack[n1]; // swap the cards
        thePack[n1] = thePack[n2];  // swap the cards
        thePack[n2] = temp; // swap the card
    }

    void bubbleSort(aCard thePack[], int maxCard) { //sort an array of cards using bubblesort algorithm
        int numComp = 0; int numSwap = 0; // counters for number of comparisons and swaps
        for (int i = 0; i < maxCard - 1; i++) { // for each card
            for (int j = maxCard - 1; j >= i + 1; j--) { //starting at end maxcard, and working down to swap cards
                if (comparecards(thePack[j - 1], thePack[j]) == 1) { // if card is greater than the next card, swap.
                    numComp++; // increment number of comparisons
                    SwapCards(j - 1, j); numSwap++; // swap cards and increment number of swaps
                }
                else numComp++; // increment number of comparisons
            }
        }
        printPack("\nSorted pack (BubbleSort)"); // print the sorted pack
        cout << "\nNumber of comparisons: " << numComp << endl; cout << "Number of swaps: " << numSwap << endl; //print number of comparisons and swaps
    }

    int comparecards(aCard c1, aCard c2) { // compare two cards
        if (c1.cardSuit < c2.cardSuit) return -1; // if suit is smaller, return -1
        else if (c1.cardSuit > c2.cardSuit) return 1; // if suit is larger, return 1
        else { // if suits are the same
            if (c1.cardVal < c2.cardVal) return -1; // if card value is smaller, return -1
            else if (c1.cardVal > c2.cardVal) return 1; // if card value is larger, return 1
            else return 0; // if card value is the same, return 0
        }
    }

    int main() { // main function
     
            for (int ct = 0; ct < maxCard; ct++) { // for each card
                thePack[ct] = getCard("32013680"); // get a card with a random see
            }
        
            cout << "Number of cards being sorted: " << maxCard << endl; // print the number of cards being sorted
            printPack("Unsorted pack"); // print the unsorted pack
            bubbleSort(thePack, maxCard); // sort the pack using BubbleSort
            

            int numComp = 0, numSwap = 0;
            Qsort(thePack, 0, maxCard - 1, numSwap, numComp, 0); // sort the pack using QuickSort
            printPack("Sorted pack (QuickSort)"); // print the sorted pack
            cout << "\nNumber of comparisons: " << numComp << endl;
            cout << "Number of swaps: " << numSwap << endl; //print number of comparisons and swaps
            cout << "Maximum level of recursion: " << maxRecursionLevel << endl; //print maximum level of    
    }

        
    
    
