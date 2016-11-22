#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <vector>
#include "../include/Card.h"
#include <list>
#include <string>

using namespace std;

class Hand {
private:
	list <Card*> * hand;
    vector <int> * sum;

	//bool search(const Card& value);
    int comparTo(Card& card1, Card& card2);


public:
	Hand(int n);
    int changeToInt( string& s);
	bool addCard(Card& card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string* toString(); // Return a list of the cards, separated by space, in one line,
	//in a sorted order, ex: "2S 5D 10H"
	Card* give(int val);
	bool isEqual(Card* card1, Card* card2);
    int findMostAppeared();
    //int findLeastAppeared();
    Card* getMinVal();
    Card* getMaxVal();
};


#endif
