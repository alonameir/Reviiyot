#include <iostream>
using namespace std;

#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Game.h"
#include "../include/Hand.h"
#include <deque>


int main(int argc, char **argv) {
	char* configurationFile = argv[1];

    Game game = Game(configurationFile);
	game.init();
 	Game initializedGame = game;
   initializedGame.printState();
 	game.play();

	cout << std::endl;
 	game.printWinner();
	game.printNumberOfTurns();
	cout << "----------" << endl;
	cout<<"Initial State:"<<endl;
    initializedGame.printState();
	cout<<"----------"<<endl;
	cout<<"Final State:"<<endl;
	game.printState();
	return 0;

	/*FigureCard* test=new FigureCard(Diamond,Jack);
	cout  << (*test).toString() << endl;

	NumericCard* testNum=new NumericCard(Spade, 1000000);
	cout << (*testNum).toString() << endl;
*/
	string* s= new string("KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD");


    Deck* d=new Deck();
    (*d).buildDeck(*s, 3);
	cout << (*d).toString()<<endl;

    Deck d2(*d);

    cout <<d2.toString() <<endl;

//	Hand* h= new Hand();
//    FigureCard* t1= new FigureCard(Diamond, King);
//    FigureCard* t2= new FigureCard(Club, Jack);
//    FigureCard* t3= new FigureCard(Spade, Jack);
//    NumericCard* t4= new NumericCard(Diamond, 1);
//    NumericCard* t5= new NumericCard(Heart, 4);
//    NumericCard* t6= new NumericCard(Diamond, 100);
//
//    h->addCard(*t1);
//    h->addCard(*t2);
//    h->addCard(*t3);
//    h->addCard(*t4);
//    h->addCard(*t5);
//    h->addCard(*t6);
//
//    cout << h->toString() <<endl;
//
//    Hand* hcopy= new Hand(*h);
//
//    cout << hcopy->toString() << endl;
//
//    h->removeCard(*t1);
//    cout << h->toString() <<endl;
//    cout << hcopy->toString() <<endl;


}


