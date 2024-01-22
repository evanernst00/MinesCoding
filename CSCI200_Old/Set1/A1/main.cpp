/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Evan Ernst
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     N/A
 *
 *     User chooses rock, paper, scissors, etc. via input and the computer does the same. A winner is decided and outputted. The user has the option to play again.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <ctime>
#include <cstdlib>
#include <string> // For string class

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
const bool LIZARD_SPOCK = true; // Allow Lizard and Spock?

int main()
{
    srand(time(0)); // Seed the random number generator

    char cont = 'y'; // Player determines whether to continue
    char playerChoice; // Stores the player's input
    int computerChoice; // Stores the computer's input
    string player, computer; // Stores the string values corresponding to each choice

    float wins = 0, losses = 0, ties = 0; // Game statistics

    cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock! (Enter R, P, S, L for Lizard, or V for Spock)" << endl;

    while(cont == 'y')
    {
        // Recieve input
        cout << "Choose your move: ";
        cin >> playerChoice;
        cout << endl;

        // Decide computer's choice
        if(LIZARD_SPOCK)
        {
            computerChoice = rand() % 5 + 1;
        }
        else
        {
            computerChoice = rand() % 3 + 1;
        }

        // Convert player's input value to a string
        playerChoice = (char) tolower(playerChoice);
        switch(playerChoice)
        {
            case 'r':
                player = "Rock";
                break;
            case 'p':
                player = "Paper";
                break;
            case 's':
                player = "Scissors";
                break;
            case 'l':
                if(LIZARD_SPOCK==true)
                {
                    player = "Lizard";
                }
                else
                {
                    cout << "Lizard and Spock are not enabled. Program terminated.";
                    return(0);
                }
                break;
            case 'v':
                if(LIZARD_SPOCK==true)
                {
                    player = "Spock";
                }
                else
                {
                    cout << "Lizard and Spock are not enabled. Program terminated.";
                    return(0);
                }
                break;
            default:
                cout << "Invalid input. Program terminated.";
                return(0);
        }


        // Convert computer selection to a string
        switch(computerChoice)
        {
            case 1:
                computer = "Rock";
                break;
            case 2:
                computer = "Paper";
                break;
            case 3:
                computer = "Scissors";
                break;
            case 4:
                computer = "Lizard";
                break;
            case 5:
                computer = "Spock";
                break;
        }


        cout << "You chose " << player << ". The computer chose " << computer << "." << endl;

        if(player == computer)
        {
            cout << "You tied!" << endl;
            ties++;
        }
        else if 
            (
                (player == "Rock" && computer == "Scissors") || 
                (player == "Rock" && computer == "Lizard") || 
                (player == "Paper" && computer == "Rock") || 
                (player == "Paper" && computer == "Spock") || 
                (player == "Scissors" && computer == "Paper") || 
                (player == "Scissors" && computer == "Lizard") || 
                (player == "Lizard" && computer == "Spock") || 
                (player == "Lizard" && computer == "Paper") || 
                (player == "sSpock" && computer == "Scissors") ||
                (player == "Spock" && computer == "Rock")
            )
        {
            cout << player << " beats " << computer << ". You win!" << endl;
            wins++;
        }
        else
        {
            cout << computer << " beats " << player << ". You lose!" << endl;
            losses++;
        }
        

        // Play again
        cout << "Would you like to play again? (Y/N) ";
        cin >> cont;
        cout << endl;

        cont = (char) tolower(cont);
    }

    // Game end message
    float winPercentage = 100*wins/(wins+losses+ties);
    float lossPercentage = 100*losses/(wins+losses+ties);
    float winLossRatio = wins/(wins+losses);

    cout << "Thanks for playing! You won " << wins << " games, lost " << losses << " games, and tied " << ties << " games." << endl
        << "You won " << winPercentage << "% of the time and lost " << lossPercentage << "% of the time with a win/loss ratio of " << winLossRatio << endl;

    return 0; // signals the operating system that our program ended OK.
}
