#include <iostream>
using namespace std;

#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Game.h"
#include "../include/Hand.h"
#include <deque>


int main(int argc, char **argv) {
//	char* configurationFile = argv[1];

 //   Game game = Game(configurationFile);
//	game.init();
// 	Game initializedGame = game;
// 	game.play();
//
//	cout << std::endl;
// 	game.printWinner();
//	game.printNumberOfTurns();
//	cout << "----------" << endl;
//	cout<<"Initial State:"<<endl;
//  	initializedGame.printState();
//	cout<<"----------"<<endl;
//	cout<<"Final State:"<<endl;
//	game.printState();
//	return 0;

	/*FigureCard* test=new FigureCard(Diamond,Jack);
	cout  << (*test).toString() << endl;

	NumericCard* testNum=new NumericCard(Spade, 1000000);
	cout << (*testNum).toString() << endl;

	string* s= new string("KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD");
    //string* s= new string("KC QH 3D");

	Deck d(*s, 3);
	cout << (d).toString()<<endl;

*/

//	Hand* h= new Hand();
	FigureCard* t1=new FigureCard(Diamond,Jack);
	FigureCard* t2=new FigureCard(Diamond,King);
 t1=t2;

    cout<<t1->toString() <<endl;


}


