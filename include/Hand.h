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
private:
	list <Card*> hand;


/*	int findMostAppeared();
	int findLeastAppeared();
	Card* getMinVal();
	Card* getMaxVal();
 */
    int comparTo(Card& card1, Card& card2);
	int changeToInt(string& s);

public:
    Hand();
    bool search(Card& value);
	Hand(int num);
	bool addCard(Card& card);
	bool removeCard(Card& card);
	//int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"
	//list<Card*> give(int val);
	bool isEqual(Card& card1, Card& card2);
    vector<Card*> giveFigures(int val);
};


#endif
