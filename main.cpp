/*
@file main.cpp
	main
@author AA*/

#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "gameLogic.h"
#include "drawBoard.h"
#include "gameDriver.h"
#include "saveState.h"
#include "inputValidation.h"

using namespace std;

int main(int argc, char* argv[]){

	//create SaveState object
	SaveState saveFile;
	//referenceList output vector to use to contruct GameLogic vector
	vector <string> referenceList;
	//determines if a new game will be started or not (1= continue) (2=newgame)
	unsigned int path=2;

	//if user does not specify filename at command line, check for saves
	if(argc==1){
		//if all save files are available prompt user to choose new game or continue
		if(saveFile.readSave()==1){
			cout << "\033[2J\033[1;1H";
			cout<<"Save File found!"<<endl;
			cout<<endl;
			cout<<"Do you wish to contine or start a new game?"<<endl;
			cout<<"1. Continue"<<endl;
			cout<<"2. New Game"<<endl;
			cout<<endl;
			cout<<"Please type a choice and press enter: ";
			bool check=false;

			//ensure that input is valid
			while(check==false){
				cin>>path;

				if(cin.fail()){
					cout<<"Please enter a valid input [1 or 2]: ";
					cin.clear();
					cin.ignore(999,'\n');
				}

				if(path==1 || path==2){
					check=true;
				}
				else{
					cout<<"Please enter a valid input [1 or 2]: ";
					cin.clear();
					cin.ignore(999,'\n');
				}
			}
		}

		//if some save files are missing alert player of the error and start new game
		else if(saveFile.readSave()==2){
			cout << "\033[2J\033[1;1H";
			cout<<"ERROR 6SF!"<<endl;
			cout<<"\t"<<"Corrupt/missing save file(s)"<<endl;
			cout<<"Starting a new game."<<endl;
			cout<<endl;
			cout<<"Type 1 and then press enter to continue: ";
			path=2;
			bool check=false;
			unsigned int confirm=0;

			//ensure that input is valid
			while(check==false){
				cin>>confirm;

				if(cin.fail()){
					cout<<"Type 1 and then press enter to continue: ";
					cin.clear();
					cin.ignore(999,'\n');
				}

				if(confirm==1){
					check=true;
				}
				else{
					cout<<"Type 1 and then press enter to continue: ";
					cin.clear();
					cin.ignore(999,'\n');
				}
			}
		}

		//anything else also leads to a new game, no need to alert player
		else{
			path=2;
		}
	}

	//if all save files are available set referenceList to the save file vector
	if(path==1){
		//input stream object
		ifstream saveLoad;
		//set name of file to open from save
		saveLoad.open("save4W.save");
		do{
			//temporary string
			string temp;
			saveLoad>>temp;
			//build vector until end of file
			referenceList.push_back(temp);
		}while(saveLoad.eof()==false);
		//close stream
		saveLoad.close();
	}

	else if(path==2){

		//if user specified file name at command line, utilize
		if(argc>1){
			string userFile = argv[1];
			//check for valid file contents
			InputValidation userReq(userFile);
			//output various errors if found
			if(userReq.ifFileFound()==false){
				cout<<"ERROR 1IV"<<endl;
				return 0;
			}
			if(userReq.goodDifficultyCount()==false){
				cout<<"ERROR 2IV"<<endl;
				return 0;
			}
			if(userReq.goodWordSize()==false){
				cout<<"ERROR 3IV"<<endl;
				return 0;
			}
		}

		//if no specified file was present, utilize default word bank
		else{
			//check for validity 
			InputValidation defaultFile("wordList.txt");
		}

		//open the parsed word bank file
		ifstream newLoad;
		newLoad.open("wordListTRUE.txt");
		do{
			//pass strings to the vector
			string temp;
			newLoad>>temp;
			referenceList.push_back(temp);
		}while(newLoad.eof()==false);
	}

	//declare and construct Player object using variables
	Player playerNow;
	//declare and construct GameLogic object pass vector
	GameLogic gameNow(referenceList);
	//declare DrawBoard class to create user interface
	DrawBoard gameGui;
	//declare GameDriver class 
	GameDriver realGame;


	//holdWord string to store word from previous save
	string holdWord;
	//false if saveFile has not been loaded yet, true if it has
	bool ifloadSave=false;

	//if complete save file is there load the save file and set bool to true
	if(path==1){
		saveFile.loadSave(playerNow,gameNow,realGame,holdWord);
		ifloadSave=true;
	}

	//show initial welcome screen and FAQ
	gameGui.welcomeScreen();
	//Player has to complete this to continue
	cout<<"Type 1 and then enter to continue."<<endl;
	realGame.pressContinue();

	//While the game state is not a win, loop the game
	while(gameNow.gameWin(playerNow)==false){

		//get next word for player to guess
		string newWord = gameNow.nextWord(playerNow.getLevel());

		//if ERROR 4GL persists, no more words are available at that level of //difficulty, increase level until one is found
		while(newWord == "ERROR 4GL"){
			//increase level in this case
			gameNow.nextLevel(playerNow);
			//find the next word
			newWord = gameNow.nextWord(playerNow.getLevel());
		}

		//if save has been loaded, set key word to the hold word
		if(ifloadSave==true){
			newWord = holdWord;
			//set to false, no longer needed in future loops
			ifloadSave=false;
		}
		//check if the change in level in case of error leads to a game end state
		if(gameNow.gameWin(playerNow)==true){
			gameGui.playerWin();
			return 0;
		}

		//variable to check the main branches of the main
		unsigned int fork = 0;

		//choice when word is displayed
		fork = realGame.theGame(playerNow,gameNow,newWord,gameGui);

		//player has chosen to guess
		if(fork==1){
			//if guess is true, execute correct functionality
			if(realGame.guess(playerNow,gameNow,newWord,gameGui)){
				realGame.correct(playerNow,gameNow,newWord,gameGui);
			}
			//if guess is false, display message and redraw
			else{
				cout<<endl;
				cout<<"Incorrect answer, try again"<<endl;
				cout<<"Type 1 and then enter to continue."<<endl;
				realGame.pressContinue();
			}
		}

		//player has chosen to use life line
		else if(fork==2){
			realGame.lifeline(playerNow,gameNow,newWord,gameGui);
		}

		//player has chosen to quit
		else if(fork==3){
			saveFile.writeSave(playerNow,gameNow,referenceList,newWord,realGame.getScrambledWord());
			gameGui.playerQuit();
			return 0;
		}
	}

	gameGui.playerWin();
return 0;	
}



