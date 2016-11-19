using namespace std;

#include <iostream>
#include "../include/Card.h"

class Card{

    Card::Card(Shape shape): shape(shape){
        switch(shape){
            case Club: shape="C"; break;
            case Diamond: shape="D"; break;
            case Heart: shape="H"; break;
            case Spade: shape="S"; break;
        }

        string Card::toString(){
            string str;
            switch (shape){
                case Club: str="C"; break;
                case Diamond: str="D"; break;
                case Heart: str="H"; break;
                case Spade: str="S"; break;
            }
            return str;

        };

        //~Card
        //getShape
    }

    class FigureCard: public Card{

        FigureCard::FigureCard(): shape(Diamond), figure(Jack){} //Default ctor

        FigureCard::FigureCard(Shape shape, Figure figure): shape(shape){
                    switch(figure){
                case Jack: figure="J"; break;
                case Queen: figure="Q"; break;
                case King: figure="K"; break;
                case Ace: figure="A"; break;
            }
        }

        string FigureCard::toString() {

        }

    };
};