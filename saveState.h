#ifndef SAVESTATE_H
#define SAVESTATE_H

/*
@file saveState.h
	Functions to save the state of the game for play at a later time
	**REQUIRES PLAYER CLASS***
	**REQUIRES GAMELOGIC CLASS**
	**REQUIRES GAMEDRIVER CLASS**
@author AA*/
#include "gameLogic.h"
#include "player.h"
#include "gameDriver.h"
#include <vector>
#include <iostream>
#include <fstream>

class SaveState{
	public:
		/*readSave method 
		@param None.
		@pre None.
		@post Returns must be 1,2 or 3.
		@return Unsigned int of the condition of the save files
		        1 = all save files are present
		        2 = some save files are present
		        3 = no save files are present*/
		unsigned int readSave();

		/*writeSave method 
		@param thePlayer Player object to pull stats at quit.
		@param theGame GameLogic object to pull state of game at quit.
		@param wordBank vector of strings of the word bank used in game at quit.
		@param wordQuit string that holds the word to be guessed at quit
		@param scrambeledWord string that holds the scrambeled version of the key at quit
		@pre None.
		@post None.
		@return creates various save files holding the players progress*/
		void writeSave(Player &thePlayer, GameLogic &theGame, std::vector<std::string> &wordBank,std::string wordQuit,std::string scrambeledWord);

		/*loadSave method 
		@param thePlayer Player object to push stats from last session into.
		@param theGame GameLogic object to push state from last session into.
		@param wordBank vector of strings to load from word bank used in from last session.
		@param wordQuit string to push the word to guess from last session.
		@param scrambeledWord string that holds the scrambeled version of the key from last session to display.
		@pre None.
		@post None.
		@return creates various save files holding the players progress*/
		void loadSave(Player &thePlayer, GameLogic &theGame, GameDriver &theEngine, std::string &wordQuit);
};

#endif
