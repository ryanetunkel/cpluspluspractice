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
        int addShip(Ship addedShip) {
            bool shipAdded = 0;
            Ship* shipArray = getShipArray();
            for (int shipIndex = 0; !shipAdded && shipIndex < sizeof(shipArray) / sizeof(Ship); shipIndex++) {
                if (shipArray[shipIndex].getLength() == NULL) {
                    shipArray[shipIndex] = addedShip;
                    shipArray[shipIndex].setLength(addedShip.getLength());
                    shipArray[shipIndex].setCoords(addedShip.getCoords());
                    shipAdded = 1;
                }
            }
            return 0;
        }
        Ship* createShip(int** coordsInput) {
            Ship newShip;
            Ship* newShipPtr = &newShip;
            newShip.setCoords(coordsInput);
            addShip(newShip);
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
        bool getPlayerNum() {
            return playerNum;
        }
        int** getPlayerGrid() {
            int** tempGrid = 0;
            tempGrid = new int*[GRIDWIDTH];
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++ ) {
                tempGrid[yCoordIndex] = new int[GRIDWIDTH];
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++) {
                    tempGrid[yCoordIndex][xCoordIndex] = playerGrid[yCoordIndex][xCoordIndex];
                }
            }
            return tempGrid;
        }
        int** getOpponentGrid() {
            int** tempGrid = 0;
            tempGrid = new int*[GRIDWIDTH];
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++ ) {
                tempGrid[yCoordIndex] = new int[GRIDWIDTH];
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++) {
                    tempGrid[yCoordIndex][xCoordIndex] = opponentGrid[yCoordIndex][xCoordIndex];
                }
            }
            return tempGrid;
        }
    protected:
        int playerNum;
        Fleet fleet;
        int playerGrid[GRIDHEIGHT][GRIDWIDTH] = {
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
        int opponentGrid[GRIDHEIGHT][GRIDWIDTH] = {
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
            displayGrids(players[0]);
            displayGrids(players[1]);
            return setPlayerTurn(rand() % 2);
        }
        int displayPlayerGrid(Player playerInput) {
            for (auto &yCoord : playerInput.getPlayerGrid()) {
                for (auto &xCoord : yCoord) {
                    cout << xCoord << " ";
                }
                cout << endl;
            }
            return 0;
        }
        int displayOpponentGrid(Player playerInput) {
            cout << playerInput.getOpponentGrid(); // Unsure if will print as wanted
            return 0;
        }
        int displayGrids(Player playerInput) {
            displayPlayerGrid(playerInput);
            displayOpponentGrid(playerInput);
            return 0;
        }
        int* getShotCoords() {
            return shotCoords;
        }
        int setShotCoords(int* coordsInput) {
            for (int coordIndex = 0; coordIndex < 2; coordIndex++) {
                getShotCoords()[coordIndex] = coordsInput[coordIndex];
            }
            return 0;
        }
        int shoot() {
            
        }
        int takeTurn(Player playerInput) {
            displayGrids(playerInput);
            shoot()
            return setPlayerTurn(!getPlayerTurn());
        }
    protected:
        bool playerTurn;
        int* shotCoords;
};

int main() {
    // Switch 1s to 2s if hit
    bool gameActive = 1;
    Game* game = 0;
    game = new Game;
    game.startGame(); // Find out way to call methods on Game Object not Game pointer 
    while (gameActive) {
        Player* currentPlayer = game.players[game.getPlayerTurn()];
        for (int shipIndex = 0; shipIndex < FLEETSIZE; shipIndex++) {
            cout << "Player " + ((int)(game.getPlayerTurn()) + 1);
            cout << " place your ships. Input coordinates of ship length ";
        }
    }
}