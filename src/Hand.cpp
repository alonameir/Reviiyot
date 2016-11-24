//
// Created by romybu on 21/11/16.
//
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../include/Card.h"
#include "../include/Hand.h"

using namespace std;


Hand::Hand():hand(){}

bool Hand::search(Card& value) {
    bool isFound = false;
    for (list<Card *>::iterator it = (hand).begin(); (!isFound) && it != hand.end(); ++it) {
        if (isEqual(**it, value)) {
            isFound = true;
        }
    }
    return isFound;
}

vector<Card*> Hand::giveFigures(int val){
    vector<Card*> ans;
    int tmp;
    for (list<Card *>::iterator it = hand.begin(); it != hand.end(); ++it) {
        tmp=(*it)->firstLetter();
        if ((tmp)==val){
            Card* toPush=(*it);
            ans.push_back(toPush);
            it=hand.erase(it);
        }
    }
    return ans;
}

bool Hand::removeCard(Card &card) {
    bool removed = false;
    for (list<Card *>::iterator it = (hand).begin(); (!removed) && it != hand.end(); ++it) {
        if (isEqual(**it, card)) {
            delete *it;
            it = (hand).erase(it);
            removed = true;
        }
    }
    return removed;
}

vector<Card*> Hand::give(int val){
    vector<Card*> ans;
    int tmp;
    for (list<Card *>::iterator it = hand.begin(); it != hand.end(); ) {
        tmp=(*it)->firstLetter();
        if ((tmp)==val){
            Card* toPush=(*it);
            cout << toPush->toString() <<endl;
            ans.push_back(toPush);
            it=hand.erase(it);
            bool a=removeCard(*toPush);
        }
        else
            ++it;
    }
    return ans;
}


int Hand:: findLeastAppeared() {
    int minval = 0;
    int minsum = 1;
    int tempval = 0;
    int tempsum = 0;
    bool isFinigheInit = false;
    list<Card *>::iterator it = hand.begin();
    int index=0;
    //init the values
    while ((!(isFinigheInit)) & it != hand.end()) {
        string s("");
        (s).append((*it)->toString());
        int changeto = changeToInt(s);
        if (tempval == 0) {
            tempval = changeto;
            minval = changeto;
        }
        if (tempval == changeto) {
            tempsum = tempsum + 1;
            ++it;
            index++;
        } else {
            isFinigheInit = true;
            minsum = tempsum;
        }

    }
    while (it != hand.end() && index<hand.size()) {
        string s("");
        (s).append((*it)->toString());
        int changeto = changeToInt(s);
        if(index!=hand.size()-1){
            if (tempval == changeto)
                tempsum = tempsum + 1;
            if(tempval != changeto ){
                    if (tempsum<minsum){
                         minsum=tempsum;
                         minval=tempval;
                    }
                    tempsum=1;
                    tempval=changeto;

                }
        }
        else{
            if (tempval == changeto)
                tempsum = tempsum + 1;
            else{
                tempsum=1;
                //minval=tempval;
            }
            if (tempsum<minsum){
                minsum=tempsum;
                minval=changeto;
            }

        }
        it++;
        index++;
    }
    return minval;
}

int Hand:: findMostAppeared(){
    int highestval=0;
    int highestsum=0;
    int tempval=0;
    int tempsum=0;
    for (list<Card *>::iterator it = hand.begin(); it != hand.end(); ++it) {
        string s ("");
        (s).append((*it)->toString());
        int changeto = changeToInt(s);
        if (tempval==0)
            tempval=changeto;
        if (tempval==changeto){
            tempsum=tempsum+1;
        }
        else{
            tempsum=1;
        }
        if (highestsum<=tempsum){
            highestval=changeto;
            highestsum=tempsum;
            tempval=changeto;
        }
        else{
            tempval=changeto;
            }

    }
    return highestval;
}

int Hand::getMaxVal(){
    Card *curr= hand.back();
    string *s= new string (curr->toString());
    int ret=changeToInt(*s);
    //delete curr;
    delete s;
    return ret;

}

int Hand::getMinVal(){
    Card* curr= hand.front();
    string *s= new string (curr->toString());
    int ret=changeToInt(*s);
    //delete curr;
    delete s;
    return ret;
}

bool Hand:: addCard(Card &card){
    bool isAdd=false;
    if (!(search(card))){
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
    }
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
    for (list<Card*>::iterator it=hand.begin(); it != hand.end(); ++it){
            toAns.append((**it).toString());
            toAns.append(" ");
        }
    return toAns;
}

bool Hand::isEqual(Card& card1, Card& card2) {
    return (card1).toString().compare((card2).toString()) == 0;
}

int Hand::getNumberOfCards(){
    int sum= (int) hand.size();
    return sum;
} // Get the number of cards in hand
