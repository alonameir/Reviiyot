/*
#include "Deck.h"
#include <iostream>
#include "Card.h"
#include <queue>
#include <string>
using namespace std;


Deck::Deck() {
    // TODO Auto-generated constructor stub

}


Deck::Deck(string& line, int n){
    string temp=new string ("");
    for (int i=0; i<=line.length(); i=i+1){
        char c= line.at(i);
        if(c!=' '){
            temp=temp+c;
        }
        if (c!=' '){
            if (isFigure(temp)){
                deck.push(new FigureCard(temp));
            }
            else{
                deck.push(new NumericCard(temp));
            }
            temp='';
            size=size+1;
        }
    }
    if (size!=n)
        throw "Invalid number of card in deck";
}

bool Deck::isFigure(string& someCard){
    if (someCard.at(0)=='J' || someCard.at(0)=='Q' || someCard.at(0)=='K' ||someCard.at(0)=='A')
        return true;
    return false;
}

Card* Deck::fetchCard(){
    if (isEmpty()==true)
        throw "Empty deck";
    Card toFetch= deck.front();// i need to copy this one because pop will remove it.
    deck.pop();
    size=size-1;
    return toFetch;

}   //Returns the top card of the deck and remove it rom the deck

Deck::~Deck(){
    while (size>0){
        deck.pop();
        size=size-1;
    }
    delete size;
}
int Deck::getNumberOfCards(){
    return size;
} // Get the number of cards in the deck

string Deck:: toString(){
    string toAns;
    for (int i=size; i>0 ; i=i-1){
        Card temp= deck.front();// i need to copy this one because pop will remove it.
        toAns& += (string)(temp.toString());
        deck.pop();
        deck.push(temp);
    }
    return toAns;
} // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"

bool Deck:: isEmpty(){
    if (getNumberOfCards()==0)
        return true;
    return false;
}
*/