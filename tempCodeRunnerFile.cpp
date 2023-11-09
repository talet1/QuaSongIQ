    cout << "Side 1: " << string(numPriests[1], 'P') << " " << string(numDevils[1], 'D') << endl;
        cout << "       " << (boatSide == 1 ? "Boat: " : "     ") << string(numPriests[boatSide], 'P') << " " << string(numDevils[boatSide], 'D') << endl;
        cout << "~~~~~~~~~~~RIVER~~~~~~~~~~~" << endl;
        cout << "       " << (boatSide == 2 ? "Boat: " : "     ") << string(numPriests[3 - boatSide], 'P') << " " << string(numDevils[3 - boatSide], 'D') << endl;
        cout << "Side 2: " << string(numPriests[2], 'P') << " " << string(numDevils[2], 'D') << endl;