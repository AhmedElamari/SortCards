// RJM's file for getting a random card
// 6/2/24

#include "cardlib.h"
using namespace std;

string cardToStr(aCard c) { // function to represent a card as a two character string
    std::string csuit = "CDHS"; // suits 
    std::string cval = "A23456789TJQK"; // change the s at index 9 to 'T'
    return cval.substr(c.cardVal -1 , 1) + csuit.substr(c.cardSuit , 1); // return two character string
}



aCard getCard(string stdno)
{  // function returns a card  - using student number stdno (8 numerical chars)
    aCard ans;
    string rcardstr = stdno.substr(rand() % 8, 1) + stdno.substr(rand() % 8, 1);    // two random characters from stdno
    int rcard = stoi(rcardstr) % 52;          // get integer in range 0..51
    string res = "  ";
    ans.cardVal = 1 + rcard % 13;                          // give cardVal 1..13 
    ans.cardSuit = static_cast<Suit>(rcard / 13);         // and for suit
    return ans;
}
