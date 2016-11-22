//
// Created by romybu on 21/11/16.
//
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
bool Hand:: addCard(Card &card){
    bool isAdd=false;
    for (list<Card*>::iterator it=(*hand).begin(); (!isAdd) && it != hand->end(); ++it){
        if (comparTo(**it,card)!=(-1)){
            hand->insert(it,&card);
            isAdd=true;
            cout << (card).toString()<<endl;
        }
    }
    if (!isAdd){
        hand->push_back(&card);
        cout << (card).toString()<<endl;
    }
    return isAdd;
}

int Hand::comparTo(Card& card1, Card& card2){
    string s1=card1.toString();
    string s2=card2.toString();
    int val1= changeToInt(s1);
    int val2= changeToInt(s2);
    if (val1<0 & val2>0)
        return 1;
    if ((val1>0 & val2>0)|| (val1<0 & val2<0)){
        if (val1>val2)
            return 1;
        if (val1==val2)
            return 0;
        if(val1<val2)
            return -1;
    }
    if (val1>0 & val2<0){
        return -1;
    }
    else {
        throw invalid_argument ("Invalid comparTo arguments");
    };

}

int Hand::changeToInt(string& s){
    int ret;
    if (s.at(0) == 'J')
        ret=-4;
    else if (s.at(0) == 'K')
        ret=-2;
    else if (s.at(0) == 'Q')
        ret=-3;
    else if (s.at(0) == 'A')
        ret=-1;
    else{
        s.pop_back();
        ret= stoi(s, 0, 10);
    }
    return ret;
}
string Hand::toString(){
    string *toAns=new string ("");
    for (list<Card*>::iterator it=(*hand).begin(); it != hand->end(); ++it){
            toAns->append((**it).toString());
            toAns->append(" ");
        }
    return *toAns;
}

/*
bool Hand::removeCard(Card &card);
int Hand::getNumberOfCards(); // Get the number of cards in hand

bool Hand::isEqual(Card* card1, Card* card2) {
    if ((*card1).toString().compare((*card2).toString())==0){
        return true;
    }
    return false;
}