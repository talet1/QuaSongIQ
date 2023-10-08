#include <iostream>
using namespace std;



void declare(int& numQuy1, int& numSu1, int& numQuy2, int& numSu2, int& boatSide, int& numQuyBoat, int& numSuBoat) {
    numQuy1 = 3;
    numSu1 = 3;
    numQuy2 = 0;
    numSu2 = 0;
    boatSide = 1;
    numQuyBoat = 0;
    numSuBoat = 0;
}
// function prototype
void inputValidation(int numQuyBoat, int numSuBoat, int numQuy1, int numSu1, int numQuy2, int numSu2, int boatSide);

int gameStart(int numQuy1, int numSu1, int numQuy2, int numSu2, int boatSide, int numQuyBoat, int numSuBoat){
    while(numQuy2 != 3 || numSu2 != 3){
        // Display the game state
        cout << "Bờ sông 1: " << numQuy1 << " quỷ, " << numSu1 << " sư" << endl;
        cout << "Bờ sông 2: " << numQuy2 << " quỷ, " << numSu2 << " sư" << endl;
        cout << "Thuyền ở bờ " << (boatSide == 1 ? "1" : "2") << endl;

        // Ask for user input
        cout << "Chọn số lượng quỷ và sư muốn chuyển sang bờ đối diện:" << endl;
        cin >> numQuyBoat >> numSuBoat;

        // Validate the user input
        inputValidation(numQuyBoat, numSuBoat, numQuy1, numSu1, numQuy2, numSu2, boatSide);

        // Move the quy and su to the other side
        if(boatSide == 1){
            numQuy1 -= numQuyBoat;
            numSu1 -= numSuBoat;
            numQuy2 += numQuyBoat;
            numSu2 += numSuBoat;
            boatSide = 2;
        }
        else{
            numQuy2 -= numQuyBoat;
            numSu2 -= numSuBoat;
            numQuy1 += numQuyBoat;
            numSu1 += numSuBoat;
            boatSide = 1;
        }
    }
    cout << "Chúc mừng bạn đã giúp quỷ qua sông thành công!" << endl;
    cout << "Bấm phím bất kỳ để thoát"<< endl;
    return 0;
}

void inputValidation(int numQuyBoat, int numSuBoat, int numQuy1, int numSu1, int numQuy2, int numSu2, int boatSide){
    if(numQuyBoat + numSuBoat > 2){
        cout << "Thuyền chỉ chở được 2 người" << endl;
        gameStart(numQuy1, numSu1, numQuy2, numSu2, boatSide, numQuyBoat, numSuBoat);
    }
    else if(numQuyBoat + numSuBoat == 0){
    cout << "Bạn phải chọn ít nhất 1 người" << endl;
    gameStart(numQuy1, numSu1, numQuy2, numSu2, boatSide, numQuyBoat, numSuBoat);
    }
    else if(numQuy1 > numSu1 && numSu1 > 0){
    cout << "Game over, quỷ đã ăn thịt nhà sư." << endl;
    return;
    }
    else if(numQuy2 > numSu2 && numSu2 > 0){
    cout << "Game over, quỷ đã ăn thịt nhà sư." << endl;
    return;
    }

}


int main() {

    cout << "Chào mừng bạn đến với trò chơi Quỷ Sư Qua Sông" << endl;
    cout << "Bên bờ sông có 3 nhà sư cùng với 3 con quỷ.\n";
    cout << "Bạn phải giúp 3 nhà sư và 3 con quỷ qua sông mà không được để quỷ ăn thịt nhà sư.\n";
    cout << "Thuyền chỉ chở được 2 người, bạn phải chọn ít nhất 1 người để chở qua sông.\n";
    cout << "Hãy chọn số lượng quỷ và sư muốn chuyển sang bờ đối diện.\n";
    cout << "Chúc bạn may mắn!" << endl;


    int numQuy1, numSu1, numQuy2, numSu2, boatSide, numQuyBoat, numSuBoat;
    declare(numQuy1, numSu1, numQuy2, numSu2, boatSide, numQuyBoat, numSuBoat);
    gameStart(numQuy1, numSu1, numQuy2, numSu2, boatSide, numQuyBoat, numSuBoat);

    return 0;
}

