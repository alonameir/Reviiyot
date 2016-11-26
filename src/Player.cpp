//
// Created by romybu on 24/11/16.
//

#include <iostream>


#include <string>
#include <vector>
#include "Hand.h"
#include "Deck.h"
#include "Player.h"
#include "Card.h"
using namespace std;

Player::Player(string _name, int _position): name(_name), position(_position){}

Player::~Player(){}

string Player:: getName(){
    return name;
}

//string Player::toString(){
//    string s=getName();
//    s.append(" ");
//    s.append(to_string(position));
//    return s;
//}

int Player:: exchange(int value, Player& other){
    vector <Card*> gave = give(value);
    int ans= (int) gave.size();
    for (vector <Card *>::iterator it = gave.begin(); it != gave.end(); ++it){
        Card* curr= *it;
        other.addCard(*curr);
    }
    //delete gave;
    return ans;
}

int Player:: myPosition(){
    return position;
}

PlayerType1 :: PlayerType1(string _name, int _position): Player(_name, _position){}

int PlayerType1::whoToAsk(){return -1;}

int  PlayerType1 :: whatToAsk(){
    int toAsk= findMostAppeared();
    return toAsk;
}

PlayerType1::~PlayerType1(){}

int PlayerType1 :: getType(){
    return 1;
}

PlayerType2 :: PlayerType2(string _name, int _position): Player(_name, _position){}

PlayerType2::~PlayerType2(){}

int  PlayerType2 :: whatToAsk(){
    int toAsk= findLeastAppeared();
    return toAsk;
}

int PlayerType2 :: getType(){
    return 2;
}

int PlayerType2::whoToAsk(){return -1;}

PlayerType3 :: PlayerType3(string _name, int _position): Player(_name, _position){
    if (_position==0)
       nextPosition=1;
    else{
        nextPosition=0;
    }
}

PlayerType3::~PlayerType3(){}

int  PlayerType3 :: whatToAsk(){
    int toAsk= getMaxVal();
    return toAsk;
}

int PlayerType3:: whoToAsk(){
    int ret= nextPosition;
    nextPosition++;
    if (nextPosition==myPosition()){
        nextPosition++;
    }
    return ret;
}

int PlayerType3 :: getType(){
    return 3;
}

PlayerType4 :: PlayerType4(string _name, int _position): Player(_name, _position){
    if (_position==0)
        nextPosition=1;
    else{
        nextPosition=0;
    }
}

int  PlayerType4 :: whatToAsk(){
    int toAsk= getMinVal();
    return toAsk;
}

int PlayerType4:: whoToAsk(){
    int ret= nextPosition;
    nextPosition++;
    if (nextPosition==myPosition()){
        nextPosition++;
    }
    return ret;
}

int PlayerType4 :: getType(){
    return 4;
}

PlayerType4::~PlayerType4(){}
