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
    vector <Card*> gave = other.give(value);
    int ans= (int) gave.size();
    for (vector <Card *>::iterator it = gave.begin(); it != gave.end(); ++it){
        Card* curr= *it;
        addCard(*curr);
    }
    return ans;
}

int Player:: myPosition(){
    return position;
}


PlayerType1 :: PlayerType1(string _name, int _position): Player(_name, _position){}

int  PlayerType1 :: whatToAsk(){
    int toAsk= findMostAppeared();
    return toAsk;
}

 int PlayerType1 :: getType(){
    return 1;
}

int PlayerType1 :: whoToAsk(int numOfPlayers){
    return -1;
}


PlayerType2 :: PlayerType2(string _name, int _position): Player(_name, _position){}

int  PlayerType2 :: whatToAsk(){
    int toAsk= findLeastAppeared();
    return toAsk;
}

int PlayerType2 :: getType(){
    return 2;
}

int PlayerType2 :: whoToAsk(int numOfPlayers){
    return -1;
}



PlayerType3 :: PlayerType3(string _name, int _position): Player(_name, _position){
    if (_position==0)
       nextPosition=1;
    else{
        nextPosition=0;
    }
}

int  PlayerType3 :: whatToAsk(){
    int toAsk= getMaxVal();
    return toAsk;
}

int PlayerType3:: whoToAsk(int numOfPlayers){
    int ret= nextPosition;
    nextPosition++;
    nextPosition= nextPosition%numOfPlayers;
    if (nextPosition==myPosition()){
        nextPosition++;
        nextPosition= nextPosition%numOfPlayers;
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

int PlayerType4:: whoToAsk(int numOfPlayers){
    int ret= nextPosition;
    nextPosition++;
    nextPosition= nextPosition%numOfPlayers;
    if (nextPosition==myPosition()){
        nextPosition++;
        nextPosition= nextPosition%numOfPlayers;
    }
    return ret;
}

int PlayerType4 :: getType(){
    return 4;
}