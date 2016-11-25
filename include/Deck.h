
#ifndef DECK_H_
#define DECK_H_


#include <iostream>
#include "../include/Card.h"
#include <deque>
#include <string>

using namespace std;

class Deck {
private:
    deque <Card*> deck;
	bool isFigure(string someCard);
	FigureCard* bulidFigureCard(string s);
    NumericCard* bulidNumericCard(string s);

public:

	Card* fetchCard();
	Deck(string line, int n);
	~Deck();
	int getNumberOfCards();
	string toString();
	bool isEmpty();

};

#endif /* DECK_H_ */