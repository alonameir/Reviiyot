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
	Card();
    Card(Shape shape);
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
    Shape getShape();
	virtual Card* copy()=0;
    const Shape getShapeCopy() const;
	virtual int firstLetter()=0;
	Card(const Card& other);
	//virtual Card&operator=(const Card& other);
};

class FigureCard : public Card {
private:
	Figure figure;
public:
    virtual ~FigureCard();
	const Figure getFigureCopy() const;
	//FigureCard&operator=(const FigureCard& other);

	FigureCard(Shape shape, Figure figure);
	virtual string toString() override;
	virtual int firstLetter();
	FigureCard(const FigureCard& other);
    virtual Card* copy();
};

class NumericCard : public Card {
private:
	int number;
public:
    virtual ~NumericCard();
	//NumericCard&operator=(const NumericCard& other);

	NumericCard(Shape shape, int number);
	virtual string toString() override;
	virtual int firstLetter();
	const int getNumericCopy() const;
	NumericCard(const NumericCard& other);
    virtual Card* copy();
};

#endif
