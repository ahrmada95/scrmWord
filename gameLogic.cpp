#include "gameLogic.h"
#include "player.h"

/*
@file gameLogic.cpp
	A class of game logic and actions that the drawer will use to display the game. 
	**REQUIRES PLAYER CLASS**
@author AA*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator> 
#include <random>
#include <vector>

/*GameLogic Object Constructor
@param properList A vector of strings from the InputValidation class.
@pre None.
@post None.
@return Returns a GameLogic object to represent the game backend, all private members are initalized.*/
GameLogic::GameLogic(std::vector<std::string> &properList){
	//copy properList to wordList via reference
	for(int z=0;z<properList.size();z++){
		wordList.push_back(properList[z]);
	}
	//set maxDifficulty to 0
	maxDifficulty = 0;
	//determine the longest length and thus the hardest difficulty 
	for(int a=0;a<wordList.size();a++){
		if(wordList[a].length()>maxDifficulty){
			maxDifficulty=wordList[a].length(); 
		}
	}
}

/*gameWin method
@param thisPlayer Player object to get stats from.
@pre None.
@post None.
@return True if player has won the game, by reaching a difficulty level higher than maxDifficulty.*/		
bool GameLogic::gameWin(Player &thisPlayer){
	if(thisPlayer.getLevel()>maxDifficulty){
		return true;
	}
	else{
		return false;
	}
}

/*getKey method
@param posList The positon on the wordList the player wants to return.
@pre Must be less than size of the list.
@post None.
@return String of the word on the vector at that location.
		Else will return ERROR 5GL*/
std::string GameLogic::getKey(unsigned int posList){
	//if position desired is of proper bounds, return the word at that position
	if(posList <= wordList.size() && posList > 0){
		return wordList[posList-1];
	}

	//return error code if anything else is given
	else{
		return "ERROR 5GL";
	}
}

/*nextWord method
@param currentLevel The current level of the player to base the next 	word to be scrambled.
@pre None.
@post None.
@return String of the next word the player is to guess
Will return "ERROR 4GL" if there is no next word.*/		
std::string GameLogic::nextWord(unsigned int currentLevel){
	//initalize as an error
	std::string nextWord = "ERROR 4GL";

	//iterate through the wordList
	for(int b=0;b<wordList.size();b++){
		//check if the difficulty of wordList[b] is the one desired 
		bool checkDifficulty=true;
		//check if wordList[b] was already guessed correctly
		bool checkCorrect=true;
		//check if wordList[b] was skipped
		bool checkSkipped=true;

		//if the difficulty is not the same, return false
		if(wordList[b].size()!=currentLevel){
			checkDifficulty=false;
		}

		//iterate through correctList
		for(int c=0;c<correctList.size();c++){
			//if there is a match, set checkCorrect to false
			if(wordList[b]==correctList[c]){
				checkCorrect=false;
			}
		}

		//iterate through skippedList
		for(int d=0;d<skippedList.size();d++){
			//if there is a mathc, set skippedList to false
			if(wordList[b]==skippedList[d]){
				checkSkipped=false;
			}
		}

		//wordList[b] has satsified all conditions to be the next key word 
		if(checkDifficulty==true && checkCorrect==true && checkSkipped==true){
			//set the return
			nextWord=wordList[b];
			//exit for-loop (starts line 80)
			break;
		}
	}

	//return string
	return nextWord;
}

/*addCorrect method
@param correctGuess The correct guess the player has made.
@pre None.
@post None.
@return Adds correctGuess to correctList vector.*/		
void GameLogic::addCorrect(std::string &correctGuess){
	correctList.push_back(correctGuess);
}

/*getCorrectList method
@param None.
@pre None.
@post None.
@return vector of strings of correctList data member.*/	
std::vector<std::string> GameLogic::getCorrectList(){
	return correctList;
}		

/*addSkipped method
@param skippedWord The word the player decided to skip.
@pre None.
@post None.
@return Adds skippedWord to skippedList vector.*/		
void GameLogic::addSkipped(std::string &skippedWord){
	//ensure that the skipped list can only be 5 terms long
	if(skippedList.size()<=5){
		skippedList.push_back(skippedWord);
	}
}

/*getSkippedList method
@param None.
@pre None.
@post None.
@return vector of strings of skippedList data member.*/	
std::vector<std::string> GameLogic::getSkippedList(){
	return skippedList;
}

/*compare method
@param guess The player's guess.
@param key The unscrambeled word.
@pre None.
@post None.
@return True if they are the same.*/		
bool GameLogic::compare(std::string &guess,std::string &key){
	//if guess is correct return true
	if(guess==key){
		return true;
	}

	//else return false in all cases
	else{
		return false;
	}
}

/*scrambleWord method
@param specialWord The word the player is to guess for next.
@pre None.
@post None.
@return String of a scrambeled word.*/		
std::string GameLogic::scrambleWord(std::string &specialWord){
	//create a temporary variable to act upon
	std::string tempWord = specialWord;
	//utilize random_shuffle method from <algorithim> to scramble
	random_shuffle(tempWord.begin(),tempWord.end());

	//if the scramble ends in the same word, reverse the string
	//reverse method is from <algorithim> 
	if(tempWord == specialWord){
		reverse(tempWord.begin(),tempWord.end());
	}

	return tempWord;
}	

/*nextLevel method
@param thisPlayer Player object
@pre None.
@post None.
@return Level increases, correct guesses counter is set to 0.*/		
void GameLogic::nextLevel(Player &thisPlayer){
	thisPlayer.levelUp();
	thisPlayer.countReset();
}
