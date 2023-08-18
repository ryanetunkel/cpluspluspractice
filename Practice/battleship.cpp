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
        Fleet getPlayerFleet() {
            return fleet;
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
        int createPlayer() {
            return 0; // Work on
        }
        Player getActivePlayer() {
            return activePlayer;
        }
        int setActivePlayer(Player activePlayerInput) {
            activePlayer = activePlayerInput;
            return 0;
        }
        bool getActivePlayerIndex() {
            return players[1].getPlayerNum() == activePlayer.getPlayerNum();
        }
        int startGame() { // Work on
            Player tempActivePlayer;
            tempActivePlayer = players[rand() % 2];
            displayPlayerGrid(players[0]);
            displayPlayerGrid(players[1]);
            return setActivePlayer(tempActivePlayer);
        }
        int takeTurn() {
            displayGrids(getActivePlayer());
            return setActivePlayer(players[!getActivePlayerIndex()]);
        }
        int displayPlayerGrid(Player playerInput) {
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++) {
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++ ) {
                    cout << playerInput.getPlayerGrid()[yCoordIndex][xCoordIndex] << " ";
                }
                cout << endl;
            }
            return 0;
        }
        int displayOpponentGrid(Player playerInput) {
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++) {
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++ ) {
                    cout << playerInput.getOpponentGrid()[yCoordIndex][xCoordIndex] << " ";
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
        bool shoot() { // 0 means no ship and no shots, 1 means ship and no shots, 2 means no ship and a shot, 3 means a ship and a shot.
            int coord = players[!getActivePlayerIndex()].getPlayerGrid()[getShotCoords()[0]][getShotCoords()[1]];
            if (coord == 0 || coord == 1) {
                Fleet tempFleet = players[!getActivePlayerIndex()].getPlayerFleet();
                Ship tempShip;
                int tempCoords[2];
                for (int fleetIndex = 0; fleetIndex < FLEETSIZE; fleetIndex++) {
                    tempShip = tempFleet.getShipArray()[fleetIndex];
                    for (int shipLengthIndex = 0; shipLengthIndex < tempShip.getLength(); shipLengthIndex++) {
                        tempCoords[0] = tempShip.getCoords()[shipLengthIndex][0];
                        tempCoords[1] = tempShip.getCoords()[shipLengthIndex][1];
                        if (tempCoords[0] == getShotCoords()[0] && tempCoords[1] == getShotCoords()[1]) {
                            players[!getActivePlayerIndex()].getPlayerGrid()[getShotCoords()[0]][getShotCoords()[1]] += 2;
                            if (coord == 0) {
                                cout << "Miss." << endl;
                            } else {
                                cout << "HIT!" << endl;
                            }
                        }
                    }
                }
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
                cout << "Player " << (getActivePlayerIndex() + 1) << endl;
                cout << "The top grid displays your opponent\'s fleet, the bottom grid displays yours." << endl;
                cout << "Xs are hits, Os are misses." << endl;
                cout << "Take your shot." << endl;
                cout << "Input the y coordinate of your shot, a value between 1 and 10:" << endl;
                cin >> yCoord;
                cout << "Input the x coordinate of your shot, a value between 1 and 10:" << endl;
                cin >> xCoord;
                tempShotCoords[0] = yCoord;
                tempShotCoords[1] = xCoord;
                setShotCoords(tempShotCoords);
                shoot();  
            }
            return setActivePlayer(players[!getActivePlayerIndex()]);
        }
        int checkSpaceTaken() {

        }
        int takeSetupTurn(Player playerInput) {
            Fleet tempFleet = players[!getActivePlayerIndex()].getPlayerFleet();
            int shipLength;
            int yStartCoord, xStartCoord,
                yEndCoord, xEndCoord;
            int startCoords[2], endCoords[2];
            bool validYStartCoord = 0, validXStartCoord = 0,
                validStartCoords = 0, validEndCoords = 0;
            bool north, east, south, west;
            bool shipInWay = 0;
            int validEndCoordsArray[4][2];
            int chosenCoordsOption;
            int numOptions;
            for (int shipIndex = 0; shipIndex < FLEETSIZE; shipIndex++) {
                cout << "Player " << (getActivePlayerIndex() + 1);
                cout << ", place your ship of length ";
                if (shipIndex == 0) {
                    cout << "4. " << endl;
                    shipLength = 4;
                }
                else if (shipIndex > 0 && shipIndex < 3) {
                    cout << "3. " << endl;
                    shipLength = 3;
                } else {
                    cout << "2. " << endl;
                    shipLength = 2;
                }
                while (!validStartCoords) {
                    validStartCoords = 0;
                    shipInWay = 0;
                    startCoords[0] = 0;
                    startCoords[1] = 0;
                    while (!validXStartCoord) {
                        cout << "Input your starting X coordinate, a value between 1 and 10 (including 1 and 10):" << endl;
                        cin >> startCoords[1];
                        validXStartCoord == 
                            startCoords[1] >= 0 
                            && startCoords[1] <= GRIDWIDTH - 1;
                        if (!validXStartCoord) {
                            cout << "Invald coordinate: Improper value." << endl;
                        }
                    }
                    startCoords[1] -= 1; // Converts to index number

                    while (!validYStartCoord) {
                        cout << "Input your starting Y coordinate, a value between 1 and 10 (including 1 and 10):" << endl;
                        cin >> startCoords[0];
                        validYStartCoord == 
                            startCoords[0] >= 0 
                            && startCoords[0] <= GRIDHEIGHT - 1;
                        if (!validYStartCoord) {
                            cout << "Invald coordinate: Improper value." << endl;
                        }
                    }
                    startCoords[0] -= 1; // Converts to index number
                    
                    for (int directionIndex = 0; !shipInWay && directionIndex < 4; directionIndex++) { //placeholder
                        numOptions++; // counts number of options there are, used later
                        switch (shipLength) {
                            case 4:
                                break;
                            case 3:
                                break;
                            case 2:
                                break;
                        }
                        /* && Math to see if there in space in any of the 4 cardinal directions for a ship of this size */;
                        // If there is a ship in the way, shipInWay = 1;
                    }

                    if (!shipInWay) {
                        validStartCoords = 
                            (tempFleet.getShipArray()[shipIndex].getCoords()[startCoords[0]][startCoords[1]]) != 1;
                        if (!validStartCoords) {
                            cout << "Invalid coordinate: Space already occupied." << endl;
                        }
                    } else {
                        cout << "Invalid coordinate: Not enough space for ship." << endl;
                    }

                    
                }
                while (!validEndCoords) {
                    cout << "The length of the ship you are placing is: " + shipLength;
                    cout << " and your starting coordinates are X: " << (startCoords[1] + 1);
                    cout << " , Y: " << (startCoords[0] + 1) << endl;
                    cout << "Which of these coordinates would you like the back end of the ship to be placed in?." << endl; 
                    for (int validEndCoordsArrayIndex = 0; validEndCoordsArrayIndex < numOptions; validEndCoordsArrayIndex++) {
                        cout << "Type \"" << (validEndCoordsArrayIndex + 1) << "\" for: X: " << validEndCoordsArray[validEndCoordsArrayIndex][0];
                        cout << ", Y: " << validEndCoordsArray[validEndCoordsArrayIndex][1] << "." << endl;
                    }
                    cin >> chosenCoordsOption;
                    if (chosenCoordsOption > 0 && chosenCoordsOption <= numOptions) {
                        endCoords[0] = validEndCoordsArray[chosenCoordsOption - 1][0];
                        endCoords[1] = validEndCoordsArray[chosenCoordsOption - 1][1];
                        endCoords[0] -= 1; // Converts to index number
                        endCoords[1] -= 1; // Converts to index number
                        validEndCoords = 1;
                    } else {
                        cout << "Invalid Selection: Number not listed." << endl;
                    }
                }
                cout << "";
                // tempString.clear(); // ??
            }
        }
    protected:
        Player activePlayer;
        int* shotCoords;
};

int main() {
    // Switch 1s to 2s if hit
    bool gameActive = 1;
    Game game;
    Game* gameptr = &game;
    game.startGame(); // Find out way to call methods on Game Object not Game pointer 
    while (gameActive) {
        Player currentPlayer = game.getActivePlayer();
        for (int shipIndex = 0; shipIndex < FLEETSIZE; shipIndex++) {
            cout << "Player " + ((game.getActivePlayerIndex()) + 1);
            cout << " place your ships. Input coordinates of ship length ";
        }
    }
}