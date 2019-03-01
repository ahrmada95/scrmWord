#include "gameDriver.h"
#include "gameLogic.h"
#include "player.h"
#include "drawBoard.h"
/*
@file gameDriver.cpp
	Implementation of the game phases
@author AA*/

#include <iostream>

/*theGame method 
@param Player thisPlayer Player object to pull stats from.
@param GameLogic currentGame GameLogic object of the current state 
@param nextWord Confirmed next word of difficulty for.
@param DrawBoard gameUI DrawBoard object used to draw the GUI
@pre None.
@post None.
@return Unsigned int of the players choice.*/
unsigned int GameDriver::theGame(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard &gameUI){

	if(scrambledWord == "no change"){
		//scramble the next word to be displayed
		scrambledWord = currentGame.scrambleWord(nextWord);
	}
	
	//draw banner and body
	gameUI.banner(thisPlayer);
	gameUI.body(scrambledWord);

	//depending on amount of lives show different choices
	if(thisPlayer.getLife()>0){
		gameUI.choiceLife();
		return check123();
	}
	else{
		gameUI.choiceNoLife();
		return check13();
	}
}

/*guess method 
@param Player thisPlayer Player object to pull stats from.
@param GameLogic currentGame GameLogic object of the current state 
@param nextWord Confirmed next word of difficulty for.
@param DrawBoard gameUI DrawBoard object used to draw the GUI
@pre None.
@post None.
@return True if the answer was a match. Draws the game board.*/
bool GameDriver::guess(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard &gameUI){

	//input for guess
	std::string input;
	//draw banner and body
	gameUI.banner(thisPlayer);
	gameUI.body(scrambledWord);
	//draw guess option
	gameUI.guessScreen();

	//input
	std::cin>>input;

	//
	return currentGame.compare(input,nextWord);
}

/*correct method 
@param Player thisPlayer Player object to pull stats from.
@param GameLogic currentGame GameLogic object of the current state 
@param nextWord Confirmed next word of difficulty for.
@param DrawBoard gameUI DrawBoard object used to draw the GUI
@pre None.
@post None.
@return Integer that incdicates that the player has been alerted about their answer being correct.*/
unsigned int GameDriver::correct(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard &gameUI){

	//increase the number of correct guesses
	thisPlayer.correctUp();
	//if player has made 3 correct guesses, increase difficulty 
	if(thisPlayer.getCorrect()>2){
		//reset count and increase level
		thisPlayer.levelUp();
		thisPlayer.countReset();
	}

	//draw banner and body
	gameUI.banner(thisPlayer);
	gameUI.body(nextWord);
	//add the word to the correctList vector
	currentGame.addCorrect(nextWord);
	//Tell player they were correct
	gameUI.guessRight();
	std::cout<<std::endl;
	std::cout<<"Enter 1 then press enter to continue"<<std::endl;
	scrambledWord = "no change";
	return pressContinue();
}

/*lifeline method 
@param Player thisPlayer Player object to pull stats from.
@param GameLogic currentGame GameLogic object of the current state 
@param nextWord Confirmed next word of difficulty for.
@param DrawBoard gameUI DrawBoard object used to draw the GUI
@pre None.
@post None.
@return Integer that incdicates that the player has been alerted about their a life line being used.*/
unsigned int GameDriver::lifeline(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard gameUI){

	//decrease life line of player by 1
	thisPlayer.useLife();
	currentGame.addSkipped(nextWord);

	//draw banner and body
	gameUI.banner(thisPlayer);
	gameUI.body(scrambledWord);
	//draw life line option
	gameUI.usedLifeLine();
	std::cout<<"Enter 1 then press enter to continue"<<std::endl;

	scrambledWord = "no change";
	return pressContinue();
}

/*getscrambledWord
@param None.
@pre None.
@post None.
@return string scrambledWord of this data memeber*/
std::string GameDriver::getScrambledWord(){
	return scrambledWord;
}

/*setSaveWord
@param lastWord string of the scrambled word displayed last game.
@pre None.
@post None.
@return changes scrambledWord for save file update*/
void GameDriver::setSaveWord(std::string lastWord){
	scrambledWord = lastWord;
}



/*check123 method 
@param None.
@pre None.
@post Must be either 1,2,or 3.
@return Unsigned int that is the players choice.*/	
unsigned int GameDriver::check123(){
	std::cout<<"Choice: ";
	//what the player enters
	unsigned int choice;
	//check if the entered value is proper or not
	bool check=false;

	//While the value is improper repeat player entry until proper entry
	while(check==false){
		//user entry
		std::cin>>choice;

		//if the entry is an integer or not
		if(std::cin.fail()){
			std::cout<<"Please enter a valid input [1,2,or3]: ";
			std::cin.clear();
			std::cin.ignore(999,'\n');
		}

		//if the entry is the proper integer or not
		if(choice == 1 || choice == 2 || choice == 3){
			//satsified all conditions, check is true
			check=true;
		}
		else{
			std::cout<<"Please enter a valid input [1,2,or3]: ";
			check=false;
			std::cin.clear();
			std::cin.ignore(999,'\n');
		}
	}
	//return the integer
	return choice;
}

/*check12 method 
@param None.
@pre None.
@post Must be either 1 or 3.
@return Unsigned int that is the players choice.*/	
unsigned int GameDriver::check13(){
	std::cout<<"Choice: ";
	//what the player enters
	unsigned int choice;
	//check if the entered value is proper or not
	bool check=false;

	//While the value is improper repeat player entry until proper entry
	while(check==false){
		//user entry
		std::cin>>choice;

		//if the entry is an integer or not
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(999,'\n');
		}

		//if the entry is the proper integer or not
		if(choice == 1 || choice == 3){
			//satsified all conditions, check is true
			check=true;
		}

		if(choice == 2){
			std::cout<<"You have no more Life Lines remaining!"<<std::endl;
			std::cout<<"Please type either [1 or 3] and press enter: ";
		}
	}
	//return the integer
	return choice;
}

/*pressContinue method
@param None.
@pre None.
@post Must be 1.
@return Unisnged int to progress the game.*/	
unsigned int GameDriver::pressContinue(){
	std::cout<<"Choice: ";
	//what the player enters
	unsigned int choice;
	//check if the entered value is proper or not
	bool check=false;

	//While the value is improper repeat player entry until proper entry
	while(check==false){
		//user entry
		std::cin>>choice;

		//if the entry is an integer or not
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(999,'\n');
		}

		//if the entry is the proper integer or not
		if(choice == 1){
			//satsified all conditions, check is true
			check=true;
		}

		else{
			std::cout<<"Please type [1] and press enter: ";
		}
	}
	//return the integer
	return choice;
}
