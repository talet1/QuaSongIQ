#include <iostream>
using namespace std;

class Game {
    int numDevils[3] = {0, 3, 0}, numPriests[3] = {0, 3, 0}, boatSide = 1;

public:
    void play() {
        while (numDevils[2] != 3 || numPriests[2] != 3) {
            while (true) {
                displayGameState();
                int tempnumDevils, tempnumPriests;
                getInput(tempnumDevils, tempnumPriests);
                if (!inputValidation(tempnumDevils, tempnumPriests)) {
                    cout << "Invalid number of passengers. Please choose again" << endl;
                    continue;
                } else {
                    numDevils[boatSide] -= tempnumDevils;
                    numPriests[boatSide] -= tempnumPriests;
                    numDevils[3 - boatSide] += tempnumDevils;
                    numPriests[3 - boatSide] += tempnumPriests;
                    moveBoat();
                    // Check if there are more "devil" than "priest" on the either side
                    if ((numDevils[1] > numPriests[1] && numPriests[1] > 0) || (numDevils[2] > numPriests[2] && numPriests[2] > 0)) {
                        cout << "Game Over! There are more devils than priests" << endl;
                        return;
                    }
                    break;
                }
            }
        }
        cout << "You win!" << endl;
    }

private:
    /*void displayGameState() {
        cout << "Side 1: " << numDevils[1] << " Devils, " << numPriests[1] << " Priests" << endl;
        cout << "Side 2: " << numDevils[2] << " Devils, " << numPriests[2] << " Priests" << endl;
        cout << "Boat: " << (boatSide == 1 ? "-->" : "<--") << endl;
    }
    */
   
   // Display game state with ASCII art
   void displayGameState() {
        cout << "Side 1: " << string(numDevils[1], 'D') << " " << string(numPriests[1], 'P') << endl;
        cout << "       " << endl;
        cout << "    ]" << string(20, '~')<< "[" << endl;
        cout << "    ]" << string(5, '~') << (boatSide == 1 ? " Boat --> " : " Boat <-- ") << string(5, '~') << "[" << endl;
        cout << "    ]" << string(20, '~') << "[" << endl;
        cout << "       " << endl;
        cout << "Side 2: " << string(numDevils[2], 'D') << " " << string(numPriests[2], 'P') << endl;
    }

    // Get input
    void getInput(int &numDevils, int &numPriests) {
        cout << "Enter number of devils: ";
        cin >> numDevils;
        cout << "Enter number of priests: ";
        cin >> numPriests;
    }
    // Validate input
    bool inputValidation(int tempnumDevils, int tempnumPriests) {
        // Check if the number of "devil" and "priest" on the current side will go below zero
        if (numDevils[boatSide] - tempnumDevils < 0 || numPriests[boatSide] - tempnumPriests < 0) {
            return false;
        }
        // Check if the number of "devil" and "priest" on the other side will be valid after the move
        if ((numDevils[3 - boatSide] + tempnumDevils > numPriests[3 - boatSide] + tempnumPriests && numPriests[3 - boatSide] + tempnumPriests > 0) ||
            (numDevils[boatSide] - tempnumDevils > numPriests[boatSide] - tempnumPriests && numPriests[boatSide] - tempnumPriests > 0)) {
            return false;
        }
        return true;
    }

    // Move boat to the other side
    void moveBoat() {
        if (boatSide == 1) {
            boatSide = 2;
        } else {
            boatSide = 1;
        }
    }
};

int main() {
    cout << "Welcome to the game!" << endl;
    cout << "Game Rules:" << endl;
    cout << "1. The boat can carry at most two passengers." << endl;
    cout << "2. The boat cannot move without passengers." << endl;
    cout << "3. If there are more devils than priests on either side of the river, you lose." << endl;
    cout << "4. Move all the priests and devils from side 1 to side 2 to win." << endl;

    char readyToPlay;
    cout << "Are you ready to start the game? (y/n): ";
    cin >> readyToPlay;
    if (readyToPlay == 'n' || readyToPlay == 'N') {
        return 0;
    }
    
    char playAgain;
    do {
        Game game;
        game.play();
        cout << "Do you want to play again (y/n): ";
        cin >> playAgain;
    } while(playAgain == 'y'|| playAgain == 'Y');
    return 0;
}