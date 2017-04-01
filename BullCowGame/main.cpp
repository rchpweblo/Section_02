/* 
This is the consle executable, that makes use of the BullCow class this acts as the view ina MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGuess(FText);
FText GetValidGuess();
bool AskPlayAgain();

FBullCowGame BCGame; //instantiate a new game

void main() {
	PrintIntro();
	do {
		PlayGame();
	} while (AskPlayAgain());
}

void PrintIntro() {
	//introduce the game
	std::cout << "Welcome to Bulls and Cows, a word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << "Max Turns: " << BCGame.GetMaxTries() << std::endl;
	FText Guess = "";
	//loop for the number of turns the player will play
	for (int32 i = 0; i < MaxTries; i++) { //TODO change from FOR to WHILE loop
		Guess = GetValidGuess();

		//submit valid guess to the game, and recevie counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		//print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls << ". Cows: " << BullCowCount.Cows << "." << std::endl << std::endl;
	}
	//TODO summarize game
}
//loop continuenly till the user gives a valid guess
FText GetValidGuess() {
	//get current try
	std::cout << "Try " << BCGame.GetCurrentTry() << ". ";
	EGuessStatus Status;
	do {
		//get a guess from the player
		std::cout << "Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << std::endl << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << std::endl << "Please enter a isogram (a word without repeating letters).";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << std::endl << "Please enter all characters in lowercase.";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //keep looping until we get no errors
}

bool AskPlayAgain() {
	std::cout << "Do you want to play again? (Yes/No) ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'Y' || Response[0] == 'y');
}