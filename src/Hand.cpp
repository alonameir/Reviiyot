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
Hand::Hand();
Card* Hand:: search(Object value);
Card* Hand:: findMostAppend();
Card* Hand::findLeastAppend();
Card* Hand::getMinVal();
Card* Hand::getMaxVal();


bool Hand:: addCard(Card &card);
bool Hand::removeCard(Card &card);
int Hand:: getNumberOfCards(); // Get the number of cards in hand
string Hand:: toString();
