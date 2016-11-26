
#include <string>
#include <iostream>


#include "../include/Card.h"

using namespace std;

Card::Card(Shape shape) : shape(shape) {}

Shape Card::getShape() {
    return shape;
}

Card::~Card() {}

Card::Card() {
    shape = Diamond;
}

const Shape Card::getShapeCopy() const{
    return shape;
}

Card::Card(const Card &other): shape(other.getShapeCopy()) {}

//void Card::setShape(Shape other) {
//    shape=other;
//}
//
//Card &FigureCard::operator=(const FigureCard &other) {
//    if (this==&other)
//        return *this;
//    figure=other.getFigure();
//    this->setShape(other.getShape());
//    return *this;
//}

FigureCard::FigureCard(Shape shape, Figure figure)
        : Card(shape), figure(figure) {}

string FigureCard::toString() {
    string str("");
    switch (figure) {
        case Jack:
            str = "J";
            break;
        case Queen:
            str = "Q";
            break;
        case King:
            str = "K";
            break;
        case Ace:
            str = "A";
            break;
    }
    switch (this->getShape()) {
        case Club:
            str += "C";
            break;
        case Diamond:
            str += "D";
            break;
        case Heart:
            str += "H";
            break;
        case Spade:
            str += "S";
            break;
    }
    return str;
}

FigureCard::~FigureCard() {}

int FigureCard::firstLetter() {
    int ans;
    switch (figure) {
        case Jack:
            ans = -4;
            break;
        case Queen:
            ans = -3;
            break;
        case King:
            ans = -2;
            break;
        case Ace:
            ans = -1;
            break;
    }
    return ans;
}

FigureCard::FigureCard(const Card &other): Card(other.getShapeCopy()), figure(((FigureCard)other).getFigureCopy()) {}

const Figure FigureCard::getFigureCopy() const {
    const Figure newFigure=figure;
    return newFigure;
}

NumericCard::NumericCard(Shape shape, int number) : Card(shape), number(number) {};

NumericCard::~NumericCard() {}

int NumericCard::firstLetter() {
    return (number);
}

string NumericCard::toString() {
    string *str = new string("");
    string *str2 = new string("");
    switch (this->getShape()) {
        case Club:
            *str = "C";
            break;
        case Diamond:
            *str = "D";
            break;
        case Heart:
            *str = "H";
            break;
        case Spade:
            *str = "S";
            break;
    }
    *str2 = to_string(number);
    return (*str2).append(*str);
}

const int NumericCard:: getNumericCopy() const{
    return number;
}

NumericCard::NumericCard(const Card& other): Card(other.getShapeCopy()){
    number=((NumericCard)other).getNumericCopy();
}
