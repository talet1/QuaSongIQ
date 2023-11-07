#include <iostream>
using namespace std;

class Game {
    int numQuy[3] = {0, 3, 0}, numSu[3] = {0, 3, 0}, boatSide = 1;

public:
    void play() {
        while (numQuy[2] != 3 || numSu[2] != 3) {
            while (true) {
                displayGameState();
                int tempNumQuy, tempNumSu;
                getInput(tempNumQuy, tempNumSu);
                if (!inputValidation(tempNumQuy, tempNumSu)) {
                    cout << "Số lượng quý và sứ không hợp lệ. Vui lòng nhập lại." << endl;
                    continue;
                } else {
                    numQuy[boatSide] -= tempNumQuy;
                    numSu[boatSide] -= tempNumSu;
                    numQuy[3 - boatSide] += tempNumQuy;
                    numSu[3 - boatSide] += tempNumSu;
                    moveBoat();
                    // Check if there are more "quy" than "su" on the either side
                    if ((numQuy[1] > numSu[1] && numSu[1] > 0) || (numQuy[2] > numSu[2] && numSu[2] > 0)) {
                        cout << "Bạn đã thua cuộc! Số lượng quý nhiều hơn sứ." << endl;
                        return;
                    }
                    break;
                }
            }
        }
        cout << "Bạn đã thắng cuộc!" << endl;
    }

private:
    void displayGameState() {
        cout << "Bờ 1: " << numQuy[1] << " quý, " << numSu[1] << " sứ" << endl;
        cout << "Bờ 2: " << numQuy[2] << " quý, " << numSu[2] << " sứ" << endl;
        cout << "Thuyền: " << (boatSide == 1 ? "-->" : "<--") << endl;
    }
    // Get input
    void getInput(int &numQuy, int &numSu) {
        cout << "Nhập số lượng quý: ";
        cin >> numQuy;
        cout << "Nhập số lượng sứ: ";
        cin >> numSu;
    }
    // Validate input
    bool inputValidation(int tempNumQuy, int tempNumSu) {
        // Check if the number of "quý" and "sứ" on the current side will go below zero
        if (numQuy[boatSide] - tempNumQuy < 0 || numSu[boatSide] - tempNumSu < 0) {
            return false;
        }
        // Check if the number of "quý" and "sứ" on the other side will be valid after the move
        if ((numQuy[3 - boatSide] + tempNumQuy > numSu[3 - boatSide] + tempNumSu && numSu[3 - boatSide] + tempNumSu > 0) ||
            (numQuy[boatSide] - tempNumQuy > numSu[boatSide] - tempNumSu && numSu[boatSide] - tempNumSu > 0)) {
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
    char playAgain;
    do {
        Game game;
        game.play();
        cout << "Bạn có muốn chơi lại không? (y/n): ";
        cin >> playAgain;
    } while(playAgain == 'y'|| playAgain == 'Y');
    return 0;
}