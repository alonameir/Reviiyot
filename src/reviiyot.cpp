#include <iostream>

#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Game.h"
#include "../include/Hand.h"

using namespace std;

int main(int argc, char **argv) {
	/*char* configurationFile = argv[1];

	Game game = Game(configurationFile);
	game.init();
 	Game initializedGame = game;
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
	 */
	/*FigureCard* test=new FigureCard(Diamond,Jack);
	cout  << (*test).toString() << endl;

	NumericCard* testNum=new NumericCard(Spade, 1000000);
	cout << (*testNum).toString() << endl;
*/
	string* s= new string("KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD ");
    //string* s= new string("KC QH 3D");
/*
	Deck* d= new Deck (*s, 3);
    cout << (*d).getNumberOfCards()<<endl;
    cout << (*d).isEmpty()<<endl;
	cout << (*d).toString()<<endl;
*/
	Hand* h= new Hand();
	FigureCard* t1=new FigureCard(Diamond,Jack);
	FigureCard* t2=new FigureCard(Diamond,King);
    FigureCard* t3=new FigureCard(Diamond,King);
	NumericCard* t4=new NumericCard(Spade, 12);
	NumericCard* t5=new NumericCard(Club, 100000);
    NumericCard* t6=new NumericCard(Club, 100000);
	h->addCard(*t1);
	h->addCard(*t4);
	h->addCard(*t3);
	h->addCard(*t2);
    h->addCard(*t6);
    h->addCard(*t5);
	cout << h->toString() <<endl;
    cout <<h->getNumberOfCards()<<endl;
    cout << (h->getMinVal())->toString() <<endl;
    cout << (h->getMaxVal())->toString() <<endl;
    cout << h->findMostAppeared() <<endl;



}

