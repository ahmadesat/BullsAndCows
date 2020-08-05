#pragma once
#include <string>

/*
using For Type Aliases
(unreal engine coding standards is to use FText for the outputs that will be given to the user,
and FString for mutable objects of the logic side of the game)
*/
using FString = std::string;
using int32 = int;


/* struct is like a simple class, with its values being public by default*/
struct FBullsAndCowsCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullsAndCows
{


public:
	FBullsAndCows();
	void Reset();

	//const functions mean they won't change any value of the class. But they can show the values.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool CheckGuessValidity(FString theguess) const;
	bool GameIsDone() const;

	FBullsAndCowsCount SubmitGuess(FString theguess);

private:
	int32 MaxTries;
	int32 CurrentTryNum;
	FString HiddenWord;
	bool bWon;
};
