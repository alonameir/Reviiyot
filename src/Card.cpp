using namespace std;

#include <iostream>
#include "../include/Card.h"

Card::Card(Shape shape) : shape(shape) {}

string Card::toString() {
    string str;
    switch (shape) {
        case Club:
            str = "C";
            break;
        case Diamond:
            str = "D";
            break;
        case Heart:
            str = "H";
            break;
        case Spade:
            str = "S";
            break;
    }
    return str;

};

Shape Card::getShape() {
    return shape;
}

//~Card


FigureCard::FigureCard(Shape shape, Figure figure) : Card(shape), figure(figure) {}

string FigureCard::toString() {

}


