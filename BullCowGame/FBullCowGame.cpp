#include "FBullCowGame.h"
//#include <iostream>

FBullCowGame::FBullCowGame() {
	Reset();
}

//getters
int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const {
	return MyHiddenWord.length();
}

int32 FBullCowGame::GetNumValidGuesses() const {
	return 0;
}

int32 FBullCowGame::GetNumInvalidGuesses() const {
	return 0;
}
//getters


void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (false) { //if the guess isn't an isogram
		return EGuessStatus::Not_Isogram;
	} else if (false) { //if the guess isn't all lowercase
		return EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLength()) {	//if the guess is the wrong length Guess.length() != GetHiddenWordLength()
		return EGuessStatus::Wrong_Length;
	} else {
		return EGuessStatus::OK;
	}
}

//recives a valid guess, increments, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	//inrement the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
	int32 HiddenWordLength = GetHiddenWordLength();
	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) {
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			//if they match
			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				if (GChar == HWChar) { //incriment bulls if they're in the same place
					BullCowCount.Bulls++;
				} else { //incriment cows if not
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
