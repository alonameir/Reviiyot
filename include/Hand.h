#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <iostream>
#include "../include/Card.h"
#include <list>
#include <string>
#include <vector>
using namespace std;

class Hand {
protected:
	list <Card*> hand;
    bool search(Card& value);
    int comparTo(Card& card1, Card& card2);
	int changeToInt(string s);
    bool isEqual(Card& card1, Card& card2);

public:
    Hand();
   // virtual ~Hand();
	bool addCard(Card& card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString();
    vector <Card*> give(int val);
    int findMostAppeared();
    int findLeastAppeared();
    void delFour();
	int getMinVal();
	int getMaxVal();
};


#endif
