using namespace std;

#include <iostream>
#include <deque>
#include <string>
#include "../include/Card.h"
#include  "../include/Deck.h"

Deck::Deck() : deck() {}

Deck::Deck(string &line, int n) : deck() {
    string temp;
    for (int i = 0; i < line.size(); i = i + 1) {
        char c = line.at((unsigned long) i);
        if ((i == line.size() - 1) && (c != ' ')) {
            temp.push_back(c);
            if (isFigure(temp)) {
                FigureCard *toPut = bulidFigureCard(temp);
                deck.push_back(toPut);
            } else {
                NumericCard *toPut;
                toPut = bulidNumericCard(temp);
                deck.push_back(toPut);
            }
        } else {
            if (c != ' ') {
                temp.push_back(c);
            } else {
                if (isFigure(temp)) {
                    FigureCard *toPut;
                    toPut = bulidFigureCard(temp);
                    deck.push_back(toPut);
                } else {
                    NumericCard *toPut;
                    toPut = bulidNumericCard(temp);
                    deck.push_back(toPut);
                }
                temp.clear();
            }
        }
    }
    if (deck.size() != (n + 3) * 4)
        throw invalid_argument("Invalid number of card in deck");
}

FigureCard *Deck::bulidFigureCard(string s) {
    if (s.size() != 2)
        throw "invalid input to buildFigureCard";
    else {
        Shape shape = Club;
        Figure figure = Jack;
        if (s.at(0) == 'J')
            figure = Jack;
        else if (s.at(0) == 'K')
            figure = King;
        else if (s.at(0) == 'Q')
            figure = Queen;
        else if (s.at(0) == 'A')
            figure = Ace;
        if (s.at(1) == 'C')
            shape = Club;
        else if (s.at(1) == 'D')
            shape = Diamond;
        else if (s.at(1) == 'H')
            shape = Heart;
        else if (s.at(1) == 'S')
            shape = Spade;

        return new FigureCard(shape, figure);
    }
}

NumericCard *Deck::bulidNumericCard(string s) {
    Shape shape;
    if (s.at(s.size() - 1) == 'C')
        shape = Club;
    else if (s.at(s.size() - 1) == 'D')
        shape = Diamond;
    else if (s.at(s.size() - 1) == 'H')
        shape = Heart;
    else if (s.at(s.size() - 1) == 'S')
        shape = Spade;
    else {
        throw invalid_argument("invalid shape in numericCard ");
    }
    s.pop_back();
    int num = stoi(s, 0, 10);
    return new NumericCard(shape, num);

}

bool Deck::isFigure(string someCard) {
    return someCard.at(0) == 'J' || someCard.at(0) == 'Q' || someCard.at(0) == 'K' || someCard.at(0) == 'A';
}

//Returns the top card of the deck and remove it rom the deck
Card *Deck::fetchCard() {
    if (isEmpty())
        throw "Empty deck";
    Card *toFetch = deck.front();// i need to copy this one because pop will remove it.
    deck.pop_front();
    return toFetch;

}

string Deck::toString() {
    string ans = "";
    deque<Card *>::iterator it = deck.begin();
    while (it != deck.end()) {
        ans = ans + (*it)->toString();
        ans = ans + " ";
        it++;
    }
    return ans;
}

Deck::~Deck() {
    for (deque<Card *>::iterator it = deck.begin(); it != deck.end(); ++it) {
        delete (*it);
    }
    deck.clear();
}

int Deck::getNumberOfCards() {
    return (int) deck.size();
} // Get the number of cards in the deck

// Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"

bool Deck::isEmpty() {
    return getNumberOfCards() == 0;
}

Deck::Deck(const Deck &other): deck() {
    for (deque<Card *>::iterator it = (other.getDeck()).begin(); it != (other.getDeck()).end(); ++it) {
        if ((**it).firstLetter()<0){
            string s;
            s=(**it).toString();
            FigureCard* tmp= bulidFigureCard(s);
            cout <<tmp->toString() <<endl;
            deck.push_back(tmp);
        }
        else{
            string s;
            s=(**it).toString();
            NumericCard* tmp= bulidNumericCard(s);
            cout << tmp->toString() <<endl;
            deck.push_back(tmp);
        }
    }

}

deque<Card *> Deck::getDeck() const {
    return (deck);
}