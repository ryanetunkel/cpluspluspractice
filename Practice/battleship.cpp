#include <iostream>
#include <cmath>
using namespace std;

const int 
    GRIDHEIGHT = 10, 
    GRIDWIDTH = 10,
    FLEETSIZE = 6;

class Ship {
    public:
        int setLength(int lengthInput) {
            return length = lengthInput;
        }
        int getLength() {
            return length;
        }
        int setCoords(int** coordsInput) {
            bool coordsSet = 0;
            for (int yCoordIndex = 0; yCoordIndex < sizeof(coordsInput) / sizeof(int); yCoordIndex++) {
                for (int xCoordIndex = 0; xCoordIndex < sizeof(coordsInput[yCoordIndex]) / sizeof(int); xCoordIndex++) {
                    coordsInput[yCoordIndex][xCoordIndex] = coords[yCoordIndex][xCoordIndex];
                }
            }
            setLength(sizeof(coords) / sizeof(int));
            coords = coordsInput;
            return coordsSet;
        }
        int** getCoords() {
            return coords;
        }
    
    protected:
        int length;
        int** coords;
};

class Fleet {
    public:
        Ship* getShipArray() {
            return shipArray;
        }
        int addShip(Ship* addedShip) {
            bool shipAdded = 0;
            Ship* shipArray = getShipArray();
            if (!shipAdded) {
                for (int shipIndex = 0; shipIndex < sizeof(shipArray) / sizeof(Ship); shipIndex++) {
                    if (shipArray[shipIndex].getLength() != NULL) {
                        shipArray[shipIndex] = &addedShip;
                        shipAdded = 1;
                    }
                }
            }
            return 0;
        }
        Ship* createShip(int** coordsInput) {
            Ship newShip;
            Ship* newShipPtr = &newShip;
            addShip(newShipPtr);
            newShip.setCoords(coordsInput);
            return newShipPtr;
        }
    protected:
        Ship shipArray[FLEETSIZE];
};
// Ships
// 1 4
// 2 3s
// 3 2s

class Player {
    public:
        int placeShip(int** coordsInput) {
            fleet.createShip(coordsInput);
            return 0;
        }
        int** getGrid() {
            int** tempGrid = 0;
            tempGrid = new int*[GRIDWIDTH];
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++ ) {
                tempGrid[yCoordIndex] = new int[GRIDWIDTH];
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++) {
                    tempGrid[yCoordIndex][xCoordIndex] = grid[yCoordIndex][xCoordIndex];
                }
            }
            return tempGrid;
        }
    protected:
        bool playerNum;
        Fleet fleet;
        int grid[GRIDHEIGHT][GRIDWIDTH] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
};

class Game {
    public:
        Player players[2];
        bool getPlayerTurn() {
            return playerTurn;
        }
        int setPlayerTurn(bool playerTurnInput) {
            return playerTurn = playerTurnInput;
        }
        int startGame() {
            return setPlayerTurn(rand() % 2);
        }
        int displayPlayerGrid() {
            cout << players[playerTurn].getGrid();
            return 0;
        }
        int takeTurn() {
            bool tempPlayerTurn = getPlayerTurn();
            displayPlayerGrid();
            return setPlayerTurn(!tempPlayerTurn);
        }
    protected:
        bool playerTurn;
};

int main() {
    // Switch 1s to 2s if hit
    bool gameActive = 1;
    Game* game = 0;
    game = new Game;
    game.startGame();
    while (gameActive) {
        Player* currentPlayer = game.players[game.getPlayerTurn()];
        for (int shipIndex = 0; shipIndex < FLEETSIZE; shipIndex++) {
            cout << "Player " + ((int)(game.getPlayerTurn()) + 1);
            cout << " place your ships. Input coordinates of ship length ";
        }
    }
}