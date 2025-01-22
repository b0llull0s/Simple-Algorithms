#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::string;

string getComputerChoice() {
    int x = rand() % 3;
    if (x == 0) return "rock";
    else if (x == 1) return "paper";
    else return "scissor";
}

string getHumanChoice() {
    string choice;
    cout << "Rock, Paper or Scissor? ";
    cin >> choice;
    return choice;
}

void playRound(const string& humanChoice, const string& computerChoice, int& humanScore, int& computerScore) {
    if (humanChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((humanChoice == "rock" && computerChoice == "scissor") ||
               (humanChoice == "paper" && computerChoice == "rock") ||
               (humanChoice == "scissor" && computerChoice == "paper")) {
        humanScore++;
        cout << "You win! " << humanChoice << " beats " << computerChoice << "\n";
    } else {
        computerScore++;
        cout << "You lose! " << computerChoice << " beats " << humanChoice << "\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int humanScore = 0;
    int computerScore = 0;

    for (int i = 0; i < 5; i++) {
        string humanChoice = getHumanChoice();
        string computerChoice = getComputerChoice();
        playRound(humanChoice, computerChoice, humanScore, computerScore);
    }

    cout << "Final Score: Human - " << humanScore << ", Computer - " << computerScore << "\n";

    return 0;
}
