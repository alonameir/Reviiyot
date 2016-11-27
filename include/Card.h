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
//	const Shape getShape() const;
	virtual int firstLetter()=0;
//	virtual Card(const Card& other)=0;
//	virtual Card & operator=(const Card& other)=0;
//	virtual void setShape(Shape other);
};

class FigureCard : public Card {
private:
	Figure figure;
public:
    ~FigureCard();
    FigureCard(Shape shape, Figure figure);
	virtual string toString() override;
	virtual int firstLetter();
//	Figure getFigure() const;
//	Card & operator=(const FigureCard& other);
};

class NumericCard : public Card {
private:
	int number;
public:
    ~NumericCard();
    NumericCard(Shape shape, int number);
	virtual string toString() override;
	virtual int firstLetter();
//	Card & operator=(const NumericCard& other);
//	const int getNumber() const;
 };

#endif
