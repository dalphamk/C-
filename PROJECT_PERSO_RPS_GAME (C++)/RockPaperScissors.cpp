/**
 * Author: Alpha Mamadou Diallo
 * 
 * Version: 1.0
 * 
 * Date: January 2022
 * 
 * Desctiption: A simple Rock Paper Scissors text game where each player selects their choice 
 * on each round. The win-loss ratio of each of them is also available
 * 
 **/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cstdio>

using namespace std;

class RPSGame {
private:
    const int rounds = 2;
    int player1Score;
    int player2Score;
    int player1Loss;
    int player2Loss;
    int currentRound;
    int gamenumber;
    int Rockwin;
    int RockLoss;
    int RockTie;
    int Paperwin;
    int PaperLoss;
    int PaperTie;
    int Scissorswin;
    int ScissorsLoss;
    int ScissorsTie;
    vector<string> messages = { "Rock smashes scissors", "Paper wraps Rock", "Scissors cut paper", "Player 1 wins", "Player 2 wins", "Tie" };
    vector<string> choices = { "Rock", "Paper", "Scissors" };
    vector<int> winners;
    char player1Choice;
    char player2Choice;

public:
    RPSGame() {
        player1Score = 0;
        player2Score = 0;
        player1Loss = 0;
        player2Loss = 0;
        currentRound = 0;
        gamenumber = 0;
        Rockwin = 0;
        RockLoss = 0;
        RockTie = 0;
        Paperwin = 0;
        PaperLoss = 0;
        PaperTie = 0;
        Scissorswin = 0;
        ScissorsLoss = 0;
        ScissorsTie = 0;
    }

    char getPlayer1Choice() {
        return player1Choice;
    }

    char getComputerInput() {
        int choice = rand() % 3;
        return choices[choice][0];
    }

    int getPlayer1Score() {
        return player1Score;
    }

    int getPlayer2Score() {
        return player2Score;
    }

    void printRules() {
        printHeader();
        cout << "Hi, it's Lay and Welcome to my RPS game, Enjoy!!\n";
        cout << "100 rounds will be played in this game.\n";
        cout << "Select your choice:\n1- Rock\n2- Paper\n3- Scissors\n";
    }

    void modifyRound() {
        int roundNumber = rounds;
        cout << "Enter the round number you want to modify: ";
        cin >> roundNumber;
        roundNumber--;

        if (roundNumber < 0 || roundNumber >= winners.size()) {
            cout << "Invalid round number.\n";
            return;
        }

        cout << "Round " << roundNumber + 1 << endl;
        cout << "Player 1 chose " << choices[winners[roundNumber * 2]] << endl;
        cout << "Player 2 chose " << choices[winners[roundNumber * 2 + 1]] << endl;

        char choice;
        cout << "Select your option:\n1- Edit\n2- Delete\n3- Cancel\n";
        cin >> choice;

        if (choice == '1') {
            char newChoice;
            cout << "Enter the new choice for Player 1: ";
            cin >> newChoice;

            while (newChoice != '1' && newChoice != '2' && newChoice != '3') {
                cout << "Invalid choice, please try again: ";
                cin >> newChoice;
            }

            winners[roundNumber * 2] = newChoice - '1';

            cout << "Enter the new choice for Player 2: ";
            cin >> newChoice;

            while (newChoice != '1' && newChoice != '2' && newChoice != '3') {
                cout << "Invalid choice, please try again: ";
                cin >> newChoice;
            }

            winners[roundNumber * 2 + 1] = newChoice - '1';

            cout << "Round modified successfully.\n";
        }
        else if (choice == '2') {
            winners.erase(winners.begin() + roundNumber * 2, winners.begin() + roundNumber * 2 + 2);
            cout << "Round deleted successfully.\n";
        }
    }

    void resetStats() {
        player1Score = 0;
        player2Score = 0;
        player1Loss = 0;
        player2Loss = 0;
        currentRound = 0;
        gamenumber = 0;
        Rockwin = 0;
        RockLoss = 0;
        RockTie = 0;
        Paperwin = 0;
        PaperLoss = 0;
        PaperTie = 0;
        Scissorswin = 0;
        ScissorsLoss = 0;
        ScissorsTie = 0;
        winners.clear();
    }
     void game(int gameNumber) {
        gamenumber++;
        currentRound = 0;

        while (currentRound < rounds) {
            currentRound++;

            cout << "\n\nRound " << currentRound << endl;
            cout << "------------------" << endl;

            player1Choice = getPlayer1Input();
            player2Choice = getComputerInput();

            cout << "Player 1 chose " << player1Choice << endl;
            cout << "Player 2 chose " << player2Choice << endl;

            printRoundResult();
        }
    }

int getRoundWinner() {
    if (player1Choice == '1' && player2Choice == '3') {
        Rockwin++;
        ScissorsLoss++;
        return 1;
    }
    if (player1Choice == '2' && player2Choice == '1') {
        Paperwin++;
        RockLoss++;
        return 1;
    }
    if (player1Choice == '3' && player2Choice == '2') {
        Scissorswin++;
        PaperLoss++;
        return 1;
    }
    if (player1Choice == player2Choice) {
        RockTie++;
        PaperTie++;
        ScissorsTie++;
        return 0;
    }
    return 2;
}
    void printRoundResult() {
        int roundWinner = getRoundWinner();
        switch (roundWinner) {
        case 1:
            cout << messages[0] << " - Player 1 wins" << endl;
            player1Score++;
            break;
        case 2:
            cout << messages[1] << " - Player 2 wins" << endl;
            player2Score++;
            break;
        case 0:
            cout << messages[2] << " - Tie" << endl;
            break;
        default:
            break;
        }
    }
   

    char getPlayer1Input() {
        cout << "Enter your choice: ";
        char c;
        cin >> c;
        while (c != '1' && c != '2' && c != '3') {
            cout << "Invalid choice, please try again: ";
            cin >> c;
        }
        return c;
    }

    void printHeader() {
        cout << "\n===================================" << endl;
        cout << "========== Rock-Paper-Scissors ==========" << endl;
        cout << "===================================\n\n" << endl;
    }
    void printGameResults() {
        cout << "\nResults:" << endl;
        cout << "Player 1 won " << player1Score << " times." << endl;
        cout << "Player 2 won " << player2Score << " times." << endl;
        cout << "There were " << rounds - player1Score - player2Score << " ties." << endl;

        cout << "\nStats:" << endl;
        cout << "Rock wins: " << Rockwin << ", losses: " << RockLoss << ", ties: " << RockTie << endl;
        cout << "Paper wins: " << Paperwin << ", losses: " << PaperLoss << ", ties: " << PaperTie << endl;
        cout << "Scissors wins: " << Scissorswin << ", losses: " << ScissorsLoss << ", ties: " << ScissorsTie << endl;

        cout << "\n\n";
        cout << "Select your option:\n1- View, edit, or delete a round\n2- Play again\n3- Exit\n";
        char choice;
        cin >> choice;

        if (choice == '1') {
            modifyRound();
        }
        else if (choice == '2') {
            resetStats();
            game(gamenumber);
        }
        else if (choice == '3') {
            exit(0);
        }
    }
    void getNextGame() {
        cout << "Do you want to play again (y/n)? ";
        char c;
        cin >> c;
        if (c == 'y' || c == 'Y') {
            resetStats();
            game(0);
        }
        else {
            cout << "Thanks for playing.\n";
        }
    }

    
   
};
int main() {
    RPSGame game;
    //printHeader();
    game.printRules();
    game.game(0);
    game.printGameResults();

    game.getNextGame();
    return 0;
}