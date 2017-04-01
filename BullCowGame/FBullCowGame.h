#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initilized to 0
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame{
public:
	FBullCowGame();

	void Reset(); //TODO make amore rich return value
	int32 GetMaxTries () const;
	int32 GetCurrentTry () const;
	int32 GetHiddenWordLength() const;
	int32 GetNumValidGuesses () const;
	int32 GetNumInvalidGuesses () const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitGuess(FString);

//ignore for now
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
