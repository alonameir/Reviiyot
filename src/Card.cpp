using namespace std;

#include <iostream>
#include "../include/Card.h"
#include <string>

Card::Card(Shape shape) : shape(shape) {}

Card::Card(string s) {
    if (s.at(0)=='D')
        shape=Diamond;
    else if (s.at(0)=='H')
        shape=Heart;
    else if (s.at(0)=='S')
        shape=Spade;
    else if (s.at(0)=='C')
        shape=Club;
}

string Card::toString() {
    string str;

    return str;

};

Shape Card::getShape() {
    return shape;
}

//~Card

FigureCard::FigureCard(Shape shape, Figure figure) : Card(shape), figure(figure) {}

string FigureCard::toString() {
    string str;
    switch (figure){
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

NumericCard::NumericCard(Shape shape, int number) : Card(shape), number(number){};

NumericCard::NumericCard(string& s){


}
