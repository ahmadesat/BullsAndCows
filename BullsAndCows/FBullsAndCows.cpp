#include "FBullsAndCows.h"

FBullsAndCows::FBullsAndCows() { Reset(); }

int32 FBullsAndCows::GetMaxTries() const { return MaxTries; }
int32 FBullsAndCows::GetCurrentTry() const { return CurrentTryNum; }
int32 FBullsAndCows::GetHiddenWordLength() const { return HiddenWord.length(); }




void FBullsAndCows::Reset()
{
	//initialize the values back to default
	constexpr int32 MAX_TRIES = 10;
	this->MaxTries = MAX_TRIES;


	this->CurrentTryNum = 1;


	//choose a random word from the array
	const FString WordsList[] = { "okay", "wrong", "search", "forest" };
	int32 randomNum = rand() % 4;
	const FString HIDDEN_WORD = WordsList[randomNum];
	this->HiddenWord = HIDDEN_WORD;

	this->bWon = false;

	return;
}



bool FBullsAndCows::CheckGuessValidity(FString theguess) const
{
	//if they have same length, then it is valid
	if (theguess.length() != HiddenWord.length())
	{
		return 0;
	}
	return 1;
}

bool FBullsAndCows::GameIsDone() const
{
	return bWon;
}

FBullsAndCowsCount FBullsAndCows::SubmitGuess(FString theguess)
{
	//increment Try number
	this->CurrentTryNum += 1;

	//initialize Count variable
	FBullsAndCowsCount BullsAndCowsCount;

	//Comparing the guess with the hidden word.
	for (int32 i = 0; i < HiddenWord.length(); i++)
	{
		for (int32 j = 0; j < theguess.length(); j++)
		{
			if (HiddenWord[i] == theguess[j])
			{
				if (i == j)
				{
					BullsAndCowsCount.Bulls++;
				}
				else
				{
					BullsAndCowsCount.Cows++;
				}
			}
		}
	}

	if (BullsAndCowsCount.Bulls == HiddenWord.length()) {this->bWon = true;}

	return BullsAndCowsCount;
}
