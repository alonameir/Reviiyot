
#include <iostream>
#include "../include/Card.h"
#include  "../include/Deck.h"

#include <string>
#include <cstring>
#include <queue>

using namespace std;

/*
Deck::Deck() {
    // TODO Auto-generated constructor stub

}
*/

Deck::Deck(string& line, int n) {
    deck= new queue <Card*>;
    size=0;
    string* temp=new string ("");
    for (int i=0; i<=line.size(); i=i+1){
        if (i==line.size()){
            if (isFigure(*temp)){
                FigureCard* toPut;
                toPut = bulidFigureCard(*temp);
                deck->push(toPut);
                cout << (*toPut).toString()<<endl;
            }
            else{
                NumericCard* toPut;
                toPut=bulidNumericCard(*temp);
                cout << (*toPut).toString()<<endl;
            }
            size=size+1;
        }

        else {
            char c = line.at(i);
            if (c != ' ') {
                temp->push_back(c);
            } else if (c == ' ') {
                if (isFigure(*temp)) {
                    FigureCard *toPut;
                    toPut = bulidFigureCard(*temp);
                    deck->push(toPut);
                    cout << (*toPut).toString() << endl;
                } else {
                    NumericCard *toPut;
                    toPut = bulidNumericCard(*temp);
                    cout << (*toPut).toString() << endl;
                }
                temp->clear();
                size = size + 1;
            }
        }
    }
    if (size!=(n+3)*4)
        throw new runtime_error("Invalid number of card in deck");
}

FigureCard* Deck:: bulidFigureCard(string& s){
    if (s.size()!=2)
        throw "invalid input to buildFigureCard";
    else{
        Shape shape;
        Figure figure;
        if (s.at(0)=='J')
            figure=Jack;
        else if (s.at(0)=='K')
            figure=King;
        else if (s.at(0)=='Q')
            figure=Queen;
        else if (s.at(0)=='A')
            figure=Ace;
        if  (s.at(1)=='C')
            shape=Club;
        else if  (s.at(1)=='D')
            shape=Diamond;
        else if  (s.at(1)=='H')
            shape=Heart;
        else if  (s.at(1)=='S')
            shape=Spade;

        return new FigureCard(shape,figure);
    }
}

NumericCard* Deck:: bulidNumericCard(string& s){
    Shape shape;
    if  (s.at(s.size()-1)=='C')
        shape=Club;
    else if  (s.at(s.size()-1)=='D')
        shape=Diamond;
    else if  (s.at(s.size()-1)=='H')
        shape=Heart;
    else if  (s.at(s.size()-1)=='S')
        shape=Spade;
    else {
        throw "invalid shape in numericCard ";
    }
    s.pop_back();
    int num= stoi (s, 0, 10);
    return new NumericCard(shape,num);

}

bool Deck::isFigure(string& someCard){
    if (someCard.at(0)=='J' || someCard.at(0)=='Q' || someCard.at(0)=='K' ||someCard.at(0)=='A')
        return true;
    return false;
}


 Card* Deck::fetchCard(){
    if (isEmpty())
        throw "Empty deck";
    Card* toFetch= deck->front();// i need to copy this one because pop will remove it.
    deck->pop();
    size=size-1;
     cout  << (*toFetch).toString() << endl;
    return toFetch;

}
//Returns the top card of the deck and remove it rom the deck
/*
string* Deck:: toString(){
    string* toAns;
    for (int i=size; i>0 ; i=i-1){
        Card* temp= deck->front();// i need to copy this one because pop will remove it.
        strcat(toAns,(*temp).toString());
        deck->pop();
        deck->push(temp);
    }
    return toAns;
}
*/


Deck::~Deck(){
    while (size>0){
        deck->pop();
        size=size-1;
    }
    delete (size);
}
 */
int Deck::getNumberOfCards(){
    return size;
}

bool Deck:: isEmpty(){
    if (getNumberOfCards()==0)
        return true;
    return false;
}
