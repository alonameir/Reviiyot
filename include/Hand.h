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
	int size;

	//Card* search(object value);
	Card* findMostAppend();
	Card* findLeastAppend();
	Card* getMinVal();
	Card* getMaxVal();
public:
	Hand();
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
 //in a sorted order, ex: "2S 5D 10H"
};

#endif
