using namespace std;

#include <iostream>
#include <string>
#include "../include/Card.h"


Card::Card(Shape shape) : shape(shape) {}

Shape Card::getShape() {
    return shape;
}

//~Card

FigureCard::FigureCard(Shape shape, Figure figure) : Card(shape), figure(figure) {}

string FigureCard::toString() {
    string* str= new string("");
    switch (figure){
        case Jack:
            *str = "J";
            break;
        case Queen:
            *str = "Q";
            break;
        case King:
            *str = "K";
            break;
        case Ace:
            *str = "A";
            break;
    }
    switch (this->getShape()) {
        case Club:
            *str += "C";
            break;
        case Diamond:
            *str += "D";
            break;
        case Heart:
            *str += "H";
            break;
        case Spade:
            *str += "S";
            break;
    }
    return *str;
}

string FigureCard::getFigure() {
    string* str= new string("");
    switch (figure){
        case Jack:
            *str+=("J");
            break;
        case Queen:
            *str+=("Q");
            break;
        case King:
            *str+=("K");
            break;
        case Ace:
            *str+=("A");
            break;
    }
    return *str;
}

NumericCard::NumericCard(Shape shape, int number) : Card(shape), number(number){};

int NumericCard::getNum() {
    return number;
}

string NumericCard::toString() {
    string* str=new string("");
    string* str2=new string("");
    switch (this->getShape()) {
        case Club:
            *str = "C";
            break;
        case Diamond:
            *str= "D";
            break;
        case Heart:
            *str = "H";
            break;
        case Spade:
            *str = "S";
            break;
    }
    *str2= to_string(number);
    return (*str2).append(*str);
}
