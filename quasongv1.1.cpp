#include <iostream>
using namespace std;

class Game {
private:
    int numQuyBoat, numSuBoat, numQuy1, numSu1, numQuy2, numSu2, boatSide;

public:
    Game() {
        numQuyBoat = 0;
        numSuBoat = 0;
        numQuy1 = 3;
        numSu1 = 3;
        numQuy2 = 0;
        numSu2 = 0;
        boatSide = 1;
    }

    void play() {
        while (numQuy2 != 3 && numSu2 != 3) {
            displayGameState();
            getInput();
            inputValidation();
            moveBoat();
        }
        cout << "Bạn đã thắng cuộc!" << endl;
    }

private:
    void displayGameState() {
        cout << "Bờ 1: " << numQuy1 << " quý, " << numSu1 << " sứ" << endl;
        cout << "Bờ 2: " << numQuy2 << " quý, " << numSu2 << " sứ" << endl;
        cout << "Thuyền: ";
        if (boatSide == 1) {
            cout << "<--";
        } else {
            cout << "-->";
        }
        cout << " (" << numQuyBoat << " quý, " << numSuBoat << " sứ)" << endl;
        //log message
        cout << "Current game state: numQuy1 = " << numQuy1 << ", numSu1 = " << numSu1 << ", numQuy2 = " << numQuy2 << ", numSu2 = " << numSu2 << ", boatSide = " << boatSide << endl;
    }

    void getInput() {
        cout << "Nhập số lượng quý và sứ bạn muốn chuyển sang bờ đối diện: ";
        //log message
        cout << "Current game state: numQuy1 = " << numQuy1 << ", numSu1 = " << numSu1 << ", numQuy2 = " << numQuy2 << ", numSu2 = " << numSu2 << ", boatSide = " << boatSide << endl;
        cin >> numQuyBoat >> numSuBoat;
    }

    void inputValidation() {
        if (numQuyBoat < 0 || numSuBoat < 0 || numQuyBoat + numSuBoat > 2 || numQuyBoat + numSuBoat == 0 ||
            numQuyBoat > numQuy1 || numSuBoat > numSu1 || numQuy2 + numQuyBoat > 3 || numSu2 + numSuBoat > 3 ||
            numQuyBoat + numSuBoat > numQuy1 + numSu1 || numQuy1 + numQuy2 > 3 || numSu1 + numSu2 > 3) {
            cout << "Số lượng quý và sứ không hợp lệ. Đang hoàn tác thao tác..." << endl;
            numQuyBoat = 0;
            numSuBoat = 0;
            //boatSide return to previous state
            if (boatSide == 1) {
                boatSide = 2;
            } else {
                boatSide = 1;
            }
        }
}

    void moveBoat() {
        if (boatSide == 1) {
            numQuy1 -= numQuyBoat;
            numSu1 -= numSuBoat;
            numQuy2 += numQuyBoat;
            numSu2 += numSuBoat;
            boatSide = 2;
        } else {
            numQuy2 -= numQuyBoat;
            numSu2 -= numSuBoat;
            numQuy1 += numQuyBoat;
            numSu1 += numSuBoat;
            boatSide = 1;
        }
        numQuyBoat = 0;
        numSuBoat = 0;
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}