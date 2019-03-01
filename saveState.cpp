#include "saveState.h"
#include "gameLogic.h"
#include "player.h"
#include "gameDriver.h"

/*
@file saveState.cpp
	Funcitons to draw the board, handle input validation of the game, and act as a GUI
	**REQUIRES PLAYER CLASS***
	**REQUIRES GAMELOGIC CLASS**
	**REQUIRES GAMEDRIVER CLASS**
@author AA*/

#include <iostream>
#include <vector>
#include <fstream>

/*readSave method 
@param None.
@pre None.
@post Returns must be 1,2 or 3.
@return Unsigned int of the condition of the save files
        1 = all save files are present
        2 = some save files are present
        3 = no save files are present*/
unsigned int SaveState::readSave(){

	std::string pSave = "save1P.save";
	std::string cSave = "save2C.save";
	std::string sSave = "save3S.save";
	std::string wSave = "save4W.save";

	//establish four checks 
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	bool check4 = false;

	//instantiate fstream object for file reading
	std::ifstream saveCheck;

	//if playerSave is open, check1 is true
	saveCheck.open(pSave);
	if(saveCheck.is_open()){
		check1=true;
	}
	//close file
	saveCheck.close();

	//if corectSave is open, check2 is true
	saveCheck.open(cSave);
	if(saveCheck.is_open()){
		check2=true;
	}
	//close file
	saveCheck.close();

	//if skippedSave is open, check3 is true
	saveCheck.open(sSave);
	if(saveCheck.is_open()){
		check3=true;
	}
	//close file
	saveCheck.close();

	//if wordListSave is open, check4 is true
	saveCheck.open(wSave);
	if(saveCheck.is_open()){
		check4=true;
	
	}
	//close file
	saveCheck.close();

	//if all checks are true, all save files are present->return a value of 1
	if(check1==true && check2==true && check3==true && check4==true){
		return 1;
	}	

	//if not all checks are true, some save files are present->return a value of 2
	if(check1==true || check2==true || check3==true || check4==true){
		return 2;
	}

	//if no checks are true, no save files are present->return a value of 3
	if(check1==false && check2==false && check3==false && check4==false){
		return 3;
	}
}

/*writeSave method 
@param thePlayer Player object to pull stats at quit.
@param theGame GameLogic object to pull state of game at quit.
@param wordListSave vector of strings of the word bank used in game at quit.
@param wordQuit string that holds the word to be guessed at quit.
@param scrambeledWord string that holds the scrambeled version of the key at quit
@pre None.
@post None.
@return creates various save files holding the players progress*/
void SaveState::writeSave(Player &thePlayer, GameLogic &theGame, std::vector<std::string> &wordListSave,std::string wordQuit, std::string scrambeledWord){

	//create an output stream
	std::ofstream saveStream;

	//open\create save file for player stats
	saveStream.open("save1P.save");
	//if open, output data
	if(saveStream.is_open()){
		//output level at quit on first line
		saveStream<<thePlayer.getLevel()<<"\n";
		//output number of lifelines at quit on second line
		saveStream<<thePlayer.getLife()<<"\n";
		//output number of correct guesses at quit on third line
		saveStream<<thePlayer.getCorrect()<<"\n";
		//output word the player was to guess at quit on fourth line
		saveStream<<wordQuit<<"\n";
		//output the scrambeled version of the word
		saveStream<<scrambeledWord<<"\n";
	}
	//close stream
	saveStream.close();

	//get size of vector of the list of correctly guessed words
	unsigned int cvSize = theGame.getCorrectList().size();

	//open\create save file for list of correctly guessed word
	saveStream.open("save2C.save");
	//if open, output data
	if(saveStream.is_open()){
		//transfer every line of the list to a corresponding line
		for(int a=0;a<cvSize;a++){
			saveStream<<theGame.getCorrectList()[a]<<"\n";
		}
	}
	//close stream
	saveStream.close();

	//get size of the vector of the list of skpped words
	unsigned int svSize = theGame.getSkippedList().size();

	//open\create save file for list of skipepd words
	saveStream.open("save3S.save");

	//if open, output data
	if(saveStream.is_open()){
		//transfer every line of the list to a corresponding line
		for(int b=0;b<svSize;b++){
			saveStream<<theGame.getSkippedList()[b]<<"\n";
		}
	}
	//close stream
	saveStream.close();

	//get size of word bank vector of the game the player used at quit
	unsigned int wvSize = wordListSave.size();

	//open\create size o the vector of the list of wordListSave
	//save4W.save IS THE UNIVERSAL TEXT FILE USED BY THE PROGRAM
	saveStream.open("save4W.save");
	//if open, output data
	if(saveStream.is_open()){
		//transfer every line of the list to a corresponding line
		for(int c=0;c<wvSize;c++){
			saveStream<<wordListSave[c]<<"\n";
		}
	}
	//close stream
	saveStream.close();
}

/*loadSave method 
@param thePlayer Player object to pull stats from last session.
@param theGame GameLogic object to pull state from last session.@param wordListSave vector of strings of the word bank used in from last session.
@param wordQuit string that holds the word to be guessed from last session.
@param scrambeledWord string that holds the scrambeled version of the key from last session.
@pre None.
@post None.
@return creates various save files holding the players progress*/
void SaveState::loadSave(Player &thePlayer, GameLogic &theGame, GameDriver &theEngine, std::string &wordQuit){

	//create an input stream
	std::ifstream loadStream;

	//open save file for player stats
	loadStream.open("save1P.save");

	//variables to hold values to initialize player object
	unsigned int pLevel;
	unsigned int pLife;
	unsigned int pCorrect;
	std::string currentWord;
	std::string currentScramble;

	//if open, accept data input
	if(loadStream.is_open()){
		//first line is the player's level
		loadStream>>pLevel;
		//second line is the players life
		loadStream>>pLife;
		//third line is the player's correct guess count
		loadStream>>pCorrect;
		//fourth line is the player's keyword at end of last session
		loadStream>>currentWord;
		//fifrth line is the player's scrambeled form at the end of last session
		loadStream>>currentScramble;
	} 
	//close the stream
	loadStream.close();
	//update the player level
	while(thePlayer.getLevel()<pLevel){
		thePlayer.levelUp();
	}
	//update player life
	while(thePlayer.getLife()>pLife){
		thePlayer.useLife();
	}
	//reset guess counter 
	thePlayer.countReset();
	//update player correct guess count by counting up from 0
	while(thePlayer.getCorrect()<pCorrect){
		thePlayer.correctUp();
	}

	//update the current word to be used as key
	wordQuit = currentWord;
	//update displayed scrambled word
	theEngine.setSaveWord(currentScramble);
	

	//update correct list of GameLogic update	
	loadStream.open("save2C.save");
	do{
		std::string temp;
		loadStream>>temp;
		theGame.addCorrect(temp);
	}while(loadStream.eof()==false);
	//close stream
	loadStream.close();

	//update skipped list of GameLogic update
	loadStream.open("save3S.save");
	do{
		std::string temp;
		loadStream>>temp;
		theGame.addSkipped(temp);
	}while(loadStream.eof()==false);
	//close stream
	loadStream.close();
}
