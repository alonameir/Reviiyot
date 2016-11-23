#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
  Shape shape;
public:
    Card(Shape shape);
    Card(string s);
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    //virtual ~Card();
    Shape getShape();
};

class FigureCard : public Card {
private:
	Figure figure;
public:
    FigureCard(Shape shape, Figure figure);
	virtual string toString() override;
	string getFigure();
};

class NumericCard : public Card {
private:
	int number;
public:
    NumericCard(Shape shape, int number);
	virtual string toString() override;
	int getNum();

 };

#endif
