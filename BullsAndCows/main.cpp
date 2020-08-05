/* 
This main.cpp, this is the console executable, and is responsible for all user int32eraction.
For the game logic, check FBullsAndCows class.
*/

#include <iostream>
#include <string>
#include "FBullsAndCows.h"


/*
using For Type Aliases
unreal engine coding standards is:
to use FText for the outputs that will be given to the user,
and FString for mutable objects of the logic side of the game.

Also, we use int3232 instead of int32, to make sure the game is compatible for all the cross-platforms.
(Note : keep main() function return as int, because that is what the system expects.)
*/
using FText = std::string;
using int32 = int;

void Intro();
void TheGame();
FText PlayerGuess();
void EndOfGame();

bool AskToPlayAgain();
bool bPlayAgain = true; //initally true

FBullsAndCows BCGame;


int main(){

	while (bPlayAgain)
	{
		TheGame();
		std::cout << std::endl;
	}
}

void Intro() 
{
	int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to " << "my C++ Practice\n";
	std::cout << "Game is simple, all you have to do is guess the word\n";
	std::cout << "Bulls number is how many letters are correct, and in the correct position\n";
	std::cout << "Cows number is how many letters are correct, but in the wrong position\n\n";
	std::cout << "Try to guess the " << WORD_LENGTH << " letters word.\n";
	std::cout << std::endl;

	return;

}

void TheGame() {

	//initialize the values to default
	BCGame.Reset();
	//show the intro
	Intro();

	//start the guessing game
	while (!BCGame.GameIsDone() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
		FText Guess = PlayerGuess();
		std::cout << "Your guess is: " << Guess << std::endl;
		if (!BCGame.CheckGuessValidity(Guess))
		{
			std::cout << "Your guess is invalid. Please make sure that your word is made of " << BCGame.GetHiddenWordLength() << " letters.";
			std::cout << std::endl << std::endl;
		}
		else
		{
			//submit the guess, and save the return in a variable
			FBullsAndCowsCount BullsAndCowsCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls: " << BullsAndCowsCount.Bulls;
			std::cout << std::endl;
			std::cout << "Cows: " << BullsAndCowsCount.Cows;
			std::cout << std::endl << std::endl;
		}
		
	}

	EndOfGame();
	bPlayAgain = AskToPlayAgain();

	return;
}

FText PlayerGuess() {
	//Player's guess
	std::cout << "This is your " << BCGame.GetCurrentTry() << "th try, out of " << BCGame.GetMaxTries() << " tries.";
	FText PlayerGuess = "";
	std::cout << "Type in your guess: ";
	getline(std::cin, PlayerGuess); 	//getline (from, int32o)

	return PlayerGuess;
}

void EndOfGame()
{
	if (BCGame.GameIsDone())
	{
		std::cout << "Congratulations, YOU WIN !!\n\n";
	}
	else
	{
		std::cout << "You Lose. Better Luck Next Time !\n\n";

	}
}


bool AskToPlayAgain()
{
	std::cout << "Would You Like To Play Again? (Yes/No): ";
	FText Answer = "";
	getline(std::cin, Answer);
	std::cout << std::endl;

	return (Answer[0] == 'y') || (Answer[0] == 'Y');

}
