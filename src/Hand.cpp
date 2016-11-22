
#include <iostream>
#include <iostream>
#include "Card.h"
#include "Hand.h"
#include <list>
#include <string>

using namespace std;
Hand::Hand(){
    hand=new list<Card*>;
}

bool Hand::search(const Card& value);

void Hand:: sort();
Card* Hand:: findMostAppeared();
Card* Hand::findLeastAppeared();
Card* Hand::getMinVal();
Card* Hand::getMaxVal();

Card* Hand::give(Card& card);
bool Hand:: addCard(Card &card);

bool Hand::removeCard(Card &card){//returns true if card was removed, false otherwise
    bool removed=false;
    if (search(card)){
        for (list<Card*>::iterator it=((hand)->begin()); it!=hand->end() & !removed; ++*it){
            if (isEqual(**it,&card)==0){
                it= (*hand).erase(it);
                removed=true;
            }
        }
    }
    return removed;
}

int Hand:: getNumberOfCards(); // Get the number of cards in hand
string Hand:: toString();

bool Hand::isEqual(Card* card1, Card* card2) {
    if ((*card1).toString().compare((*card2).toString())==0){
        return true;
    }
    return false;
}