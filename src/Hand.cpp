//
// Created by romybu on 21/11/16.
//
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "../include/Card.h"
#include "../include/Hand.h"



using namespace std;
Hand::Hand():hand(){
}

//bool Hand::search(const Card& value);
/*



*/
//Card* Hand::give(Card& card);

/*
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

*/
/*
int Hand::findLeastAppeared(){//notFinish
    int minval=0;
    int minsum=1;
    int tempval=0;
    int tempsum=1;
    for (list<Card *>::iterator it = (*hand).begin(); it != hand->end(); ++it) {
        string* s=new string("");
        (*s).append((*it)->toString());
        int changeto=changeToInt(*s);
        if (tempval==changeto){
            tempsum=tempsum+1;
            tempval=changeto;
        }
        else{
            if (minsum>=tempsum){
                minval=changeto;
                minsum=tempsum;
            }
            tempsum=1;
            tempval=changeto;
        }
    }
    return minval;
}

int Hand:: findMostAppeared(){
    int highestval=0;
    int highestsum=0;
    int tempval=0;
    int tempsum=1;
    for (list<Card *>::iterator it = (*hand).begin(); it != hand->end(); ++it) {
        string* s=new string("");
        (*s).append((*it)->toString());
        int changeto=changeToInt(*s);
        if (tempval==changeto){
            tempsum=tempsum+1;
            tempval=changeto;
        }
        else{
            if (highestsum<=tempsum){
                highestval=changeto;
                highestsum=tempsum;
            }
            tempsum=1;
            tempval=changeto;
        }
    }
    return highestval;
}

int Hand::getMaxVal(){
    Card *curr= hand->back();
    string *s= new string (curr->toString());
    int ret=changeToInt(*s);
    delete curr;
    delete s;
    return ret;

}

int Hand::getMinVal(){
    Card* curr= hand->front();
    string *s= new string (curr->toString());
    int ret=changeToInt(*s);
    delete s;
    return ret;
}
*/
bool Hand:: addCard(Card &card){
    bool isAdd=false;
   // if ((hand->search(&card))==false){
        int val=0;
        int i=0;
        for (list<Card *>::iterator it = hand.begin(); (!isAdd) && it != hand.end(); ++it) {
            if (comparTo(**it, card) != (-1)) {
                hand.insert(it, &card);
                isAdd = true;
            }
        }
        if (!isAdd) {
            hand.push_back(&card);
        }
  //  }
    return isAdd;
}

int Hand::comparTo(Card& card1, Card& card2){
    int ans=-2;
    string s1=card1.toString();
    string s2=card2.toString();
    char shape1=s1.back();
    char shape2= s2.back();
    int val1= changeToInt(s1);
    int val2= changeToInt(s2);
    if (val1<0 & val2>0)
        ans=1;
    else if ((val1>0 & val2>0)|| (val1<0 & val2<0)){
        if (val1>val2)
            ans= 1;
        else if (val1==val2 && shape1>shape2)
            ans= 1;
        else if (val1==val2 && shape1<shape2)
            ans= -1;
        else if(val1<val2)
            ans=-1;
    }
    else if (val1>0 & val2<0){
        ans= -1;
    }
    else {
        throw invalid_argument ("Invalid comparTo arguments");
    }
    return ans;

}

int Hand::changeToInt(string s){
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
    string toAns=("");
    for (list<Card*>::iterator it=(hand).begin(); it != hand.end(); ++it){
            toAns.append((**it).toString());
            toAns.append(" ");
        }
    return toAns;
}

int Hand::getNumberOfCards(){
    int sum=hand.size();
    return sum;
} // Get the number of cards in hand

bool Hand::isEqual(Card* card1, Card* card2) {
    if ((*card1).toString().compare((*card2).toString())==0){
        return true;
    }
    return false;
}