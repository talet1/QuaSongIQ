document.getElementById('startGame').addEventListener('click', startGame);

class Game {
    constructor() {
        this.numDevils = [0, 3, 0];
        this.numPriests = [0, 3, 0];
        this.boatSide = 1;
    }
    async play() {
        while (this.numDevils[2] < 3 || this.numPriests[2] < 3) {
            while (true) {
                this.displayGameState();
                let {numDevils: tempnumDevils, numPriests: tempnumPriests} = await this.getInput();
                if (!this.inputValidation(tempnumDevils, tempnumPriests)) {
                    console.log("Invalid move. Please try again.");
                    continue;
                } else {
                    this.numDevils[this.boatSide] -= tempnumDevils;
                    this.numPriests[this.boatSide] -= tempnumPriests
                    this.numDevils[3 - this.boatSide] += tempnumDevils
                    this.numPriests[3 - this.boatSide] += tempnumPriests
                    this.moveBoat();
                    // Check if there are more "devil" than "priest" on the either side
                    if ((this.numDevils[1] > this.numPriests[1] && this.numPriests[1] > 0) || (this.numDevils[2] > this.numPriests[2] && this.numPriests[2] > 0)) {
                        console.log("You lost! There are more devils than priests on one side of the river.");
                        return;
                    }
                    break;
                }
            }
        }    
        console.log("You won!");
    }

    // Display game state to console
    displayGameState() {
        console.log("Side 1: " + "D".repeat(this.numDevils[1]) + " " + "P".repeat(this.numPriests[1]));
        console.log("\n");
        console.log("    ]" + "~".repeat(20) + "[");
        console.log("    ]" + "~".repeat(5) + (this.boatSide == 1 ? " Boat --> " : " Boat <-- ") + "~".repeat(5) + "[");
        console.log("    ]" + "~".repeat(20) + "[");
        console.log("\n");
        console.log("Side 2: " + "D".repeat(this.numDevils[2]) + " " + "P".repeat(this.numPriests[2]));
    }

    // Get input
    async getInput() {
        const readline = require('readline').createInterface({
            input: process.stdin,
            output: process.stdout
        });

        let numDevils = await new Promise(resolve => readline.question('Enter number of devils: ', resolve));
        while(isNaN(numDevils)) {
            numDevils = await new Promise(resolve => readline.question('Invalid input. Please enter an integer: ', resolve));
        }

        let numPriests = await new Promise(resolve => readline.question('Enter number of priests: ', resolve));
        while(isNaN(numPriests)) {
            numPriests = await new Promise(resolve => readline.question('Invalid input. Please enter an integer: ', resolve));
        }

        readline.close();

        return { numDevils: parseInt(numDevils), numPriests: parseInt(numPriests) };
    }
    // Validate input
    inputValidation(tempnumDevils, tempnumPriests) {
        // Check if the number of "devil" and "priest" on the current side will go below zero
        if (this.numDevils[this.boatSide] - tempnumDevils < 0 || this.numPriests[this.boatSide] - tempnumPriests < 0) {
            return false;
        }
        // Check if the number of "devil" and "priest" on the other side will be valid after the move
        if ((this.numDevils[3 - this.boatSide] + tempnumDevils > this.numPriests[3 - this.boatSide] + tempnumPriests && this.numPriests[3 - this.boatSide] + tempnumPriests > 0) ||
            (this.numDevils[this.boatSide] - tempnumDevils > this.numPriests[this.boatSide] - tempnumPriests && this.numPriests[this.boatSide] - tempnumPriests > 0)) {
            return false;
        }
    
        return true;
    }

    // Move boat
    moveBoat() {
        if (this.boatSide == 1) {
            this.boatSide = 2;
        } else {
            this.boatSide = 1;
        }
    }
}

async function startGame() {
    console.log("Welcome to the game!");
    console.log("Game Rules:");
    console.log("1. The boat can carry at most two passengers.");
    console.log("2. The boat cannot move without passengers.");
    console.log("3. If there are more devils than priests on either side of the river, you lose.");
    console.log("4. Move all the priests and devils from side 1 to side 2 to win.");

    const readline = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });

    let readyToPlay = await new Promise(resolve => readline.question('Are you ready to start the game? (y/n): ', resolve));
    if (readyToPlay.toLowerCase() === 'n') {
        readline.close();
        return;
    }

    let playAgain;
    do {
        let game = new Game();
        await game.play();
        playAgain = await new Promise(resolve => readline.question('Do you want to play again? (y/n): ', resolve));
    } while (playAgain.toLowerCase() === 'y');

    readline.close();
}

startGame();