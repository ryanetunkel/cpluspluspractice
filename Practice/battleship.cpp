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
        char** getOpponentGrid() {
            char** tempGrid = 0;
            tempGrid = new char*[GRIDWIDTH];
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++) {
                tempGrid[yCoordIndex] = new char[GRIDWIDTH];
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
        char opponentGrid[GRIDHEIGHT][GRIDWIDTH] = {
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
        Player getActivePlayer() {
            return activePlayer;
        }
        int setActivePlayer(Player* activePlayerInput) {
            Player tempActivePlayer;
            Player* tempActivePlayerPtr = &tempActivePlayer;
            return activePlayer = &tempActivePlayerPtr;
        }
        bool getActivePlayerIndex() {
            return players[1].playerNum == activePlayer.playerNum
        }
        int startGame() {
            displayPlayerGrid(players[0]);
            displayPlayerGrid(players[1]);
            return setActivePlayer(players[rand() % 2]);
        }
        int takeTurn() {
            displayGrids(getActivePlayer());
            return setActivePlayer(players[!getActivePlayerIndex()]);
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
            for (auto &yCoord : playerInput.getOpponentGrid()) {
                for (auto &xCoord : yCoord) {
                    cout << xCoord << " ";
                }
                cout << endl;
            }
            return 0;
        }
        int displayGrids(Player playerInput) {
            displayPlayerGrid(playerInput);
            cout << endl;
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
        bool shoot() {
            int coord = players[!getActivePlayerIndex()].getPlayerGrid[getShotCoords()[0]][getShotCoords()[1]];
            if (coord == 0) {
                cout << "Miss." << endl;
            }
            else if (coord == 1) {
                cout << "HIT!" << endl;
                shotMade = 1;
            } 
            else if (coord == 2 || coord == 3) {
                cout << "Already shot there, shoot elsewhere." << endl;
            } 
            return coord == 0 || coord == 1;
        }
        int takeTurn(Player playerInput) {
            int yCoord, xCoord;
            int tempShotCoords[2];
            while (!shoot()) {
                displayGrids(playerInput);
                cout << "Player " + (getActivePlayerIndex() + 1) + endl;
                cout << "The top grid displays your opponent\'s fleet, the bottom grid displays yours." << endl:
                cout << "Xs are hits, Os are misses." << endl;
                cout << "Take your shot."
                cout << "Input the y coordinate of your shot, a value between 1 and 10:" << endl;
                cin >> yCoord;
                cout << "Input the x coordinate of your shot, a value between 1 and 10:" << endl;
                cin >> xCoord;
                tempShotCoords[0] = yCoord;
                tempShotCoords[1] = xCoord;
                setShotCoords(tempShotCoords);
                shoot();  
            }
            return setActivePlayer(!getActivePlayer());
        }
        int takeSetupTurn(Player playerInput) {
            int yStartCoord, xStartCoord,
                yEndCoord, xEndCoord;
            for (int shipIndex = 0; shipIndex < FLEETSIZE; shipIndex++) {
                cout << "Player " + (getActivePlayerIndex() + 1);
                cout << ", place your ship of length ";
                if (shipIndex == 0) {
                    cout << "4. " << endl;
                }
                else if (shipIndex > 0 && shipIndex < 3) {
                    cout << "3. " << endl;
                } else {
                    cout << "2. " << endl;
                }
                cout << "Input your starting y coordinate, a value between 1 and 10:" << endl;
                cin >> yCoord;
                cout << "Input your starting x coordinate, a value between 1 and 10:" << endl;
                cin >> xCoord;
                cout >> "";
                tempString.clear();
            }
        }
    protected:
        Player activePlayer;
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