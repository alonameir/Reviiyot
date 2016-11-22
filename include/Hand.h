#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <iostream>
#include "../include/Card.h"
#include <list>
#include <string>

using namespace std;

class Hand {
private:
	list <Card*> * hand;

	//bool search(const Card& value);
	//Card* findMostAppeared();
	//Card* findLeastAppeared();
	//Card* getMinVal();
	//Card* getMaxVal();
    int comparTo(Card& card1, Card& card2);
	int changeToInt(string& s);
public:
	Hand();
	bool addCard(Card &card);
	//bool removeCard(Card &card);
	//int getNumberOfCards(); // Get the number of cards in hand
	string toString();
   // Card* give(Card& value);
    // Return a list of the cards, separated by space, in one line,
 //in a sorted order, ex: "2S 5D 10H"
};

#endif
