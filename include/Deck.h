
#ifndef DECK_H_
#define DECK_H_

#include "Deck.h"
#include <iostream>
#include "Card.h"
#include <queue>
#include <string>

using namespace std;

class Deck {
private:
	int size;
	queue <Card*> deck;
	bool isFigure(string& someCard);

public:
	Card* fetchCard();
	Deck();
	virtual ~Deck();
	Deck::Deck(string& line, int n);
	Deck::~Deck();
	int getNumberOfCards();
	string toString();
	bool isEmpty();
    FigureCard* bulidFigureCard(string& s);
    NumericCard* bulidNumericCard(string& s);
};

#endif /* DECK_H_ */