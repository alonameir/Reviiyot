//
// Created by romybu on 21/11/16.

#include <iostream>
#include <iostream>
#include "Card.h"
#include "Hand.h"
#include <list>
#include <string>

using namespace std;

Hand::Hand() {
    hand=new list<Card*>;
};
bool Hand:: search(const Card& value);
Card* Hand:: findMostAppeared();
Card* Hand:: findLeastAppeared();
Card* Hand:: getMinVal();
Card* Hand:: getMaxVal();


bool Hand:: addCard(Card &card){
    bool isAdd=false;
    for (list<Card*>::iterator it=(*hand).begin(); (!isAdd) && it != hand->end(); ++it){
        if (comparTo(**it,card)!=(-1)){
            hand->insert(it,&card);
            isAdd=true;
        }
    }
    if (!isAdd){
        hand->push_back(&card);
    }
    return isAdd;
}

int Hand::comparTo(Card& card1, Card& card2){
    string s1=card1.toString();
    string s2=card2.toString();
    int val1= changeToInt(s1);
    int val2= changeToInt(s2);
    if (val1<val2)

}

int Hand::changeToInt(string& s){
    int ret;
    if (s1.at(0) == 'J')
        val1 = Jack;
    else if (s.at(0) == 'K')
        figure = King;
    else if (s.at(0) == 'Q')
        figure = Queen;
    else if (s.at(0) == 'A')
        figure = Ace;
}

bool Hand::removeCard(Card &card);
int Hand::getNumberOfCards(); // Get the number of cards in hand
string Hand::toString();
Card* Hand:: give(Card& value);