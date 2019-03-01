README

//INTRO////////////////////////////////////////////////////////////////////////

Hello, welcome to wordScram: a basic C++ word based game.

The object of the game is to guess the scrambled word that is displayed to you.

All answers should be lower case.

Difficulty level is determined by the length of the word. If you manage to solve 3 of the words of the same difficulty level, you will "level up" and go up to the next level.

If a word has you particularly stumped, feel free to use a LifeLine. LifeLines allow you to skip a word permanently and move on to the next word. You may utilize this 5 times. You should remember that if there are no more words of that diffculty level, you will be automtaically "leveled up" to the next level, so use LifeLines wisely!

You win the game if you get past the highest difficulty level.
If you guess incorrectly, you may try again (with no consequence) or quit. 



//GAME UI//////////////////////////////////////////////////////////////////////
The game UI is straight forward, in the top right are the player's current level and the number of life lines remaining. 

In the center of the screen is the player's scrambled word they must guess.

At the bottom are the choices available to the player. To choose a choice, simply type in the number and press enter. If an invalid input is given, you will prompted to enter a proper one until satisfied.



//BUILDING THE GAME////////////////////////////////////////////////////////////

First you must place your desired word bank into the directory. To have the game automatically parse and load that data, title the word bank as "wordList.txt"

There is an included wordList.txt file

If you do not wish to rename the file, typing in the name of the file and the extension on the commandline will also load that data.

The contents will be formatted and placed into a new text file called "wordListTRUE.txt"

There is an included makeFile. To compile the game simply type in "make" on the command line when in the proper directory.

To run "./scrmWord"

Any encountered errors can be referened in the included "ERROR DOCUMENTATION.txt" file. If it is not listed there, congratulations! You found a bug I missed, please let me know what type of bug it was and the conditions to replicate it.

//SOFTWARE DESIGN PHILOSOPHY///////////////////////////////////////////////////

For this project I decided to focus on making a polished and robust final product/executable. In earlier projects, in earlier classes we never told to worry about the user's inputs. My goal was to make a program that wouldn't crash because of bad inputs or misteps in my code.

However this may have backfired on me because ensuring that proper inputs were given and expected values passed with no mistake, caused my code to baloon in size.

6 classes were made to hold the core functions of the game:

class Player - holds statistics of the player (level, lives, # of guesses).

class GameLogic - holds the state of the game: the word bank, list of words 	corretly guessed, list of words skipped, etc. It contains methods to 		update the state of the game as well as recognize when the game has been 	 won. 

class DrawBoard - UI class that draws the three basic parts of the program
	1. banner that displays player stats
	2. body with the scrambeled word
	3. choices that the player has

class GameDriver - ties up the previous three classes into methods to run the 	  game in it's full state.

class SaveState - methods and variables to save the player stats and game state
	into a variety of .save files to be loaded if the player desires at the next game.

class InputValidation - methods to determine if a text file in question 		contains a valid list of words (all words are 3 letters or longer, and 		there are at least 3 words of each length).

I believe this could have been better streamlined, as main is where the flow of the game depending on various conditions the player is under is determined. This has caused main to be quite chaotic. Better pseudocoding with more encompassing classes would have been a superior approach. 
