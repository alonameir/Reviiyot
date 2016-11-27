
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


public:
	Deck();
	~Deck();
	Deck(const Deck& other);
	deque<Card*> getDeck() const;
	Card* fetchCard();
	Deck(string &line, int n);
	int getNumberOfCards();
	string toString();
	bool isEmpty();
	FigureCard* bulidFigureCard(string s);
	NumericCard* bulidNumericCard(string s);
};

#endif /* DECK_H_ */