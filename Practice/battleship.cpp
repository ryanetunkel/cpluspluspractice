#include <string>
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
            for (int yCoordIndex = 0; yCoordIndex < getLength(); yCoordIndex++) {
                for (int xCoordIndex = 0; xCoordIndex < getLength(); xCoordIndex++) {
                    coords[yCoordIndex][xCoordIndex] = coordsInput[yCoordIndex][xCoordIndex];
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
            for (int shipIndex = 0; !shipAdded && shipIndex < FLEETSIZE; shipIndex++) {
                shipArray[shipIndex] = addedShip;
                shipArray[shipIndex].setLength(addedShip.getLength());
                shipArray[shipIndex].setCoords(addedShip.getCoords());
                shipAdded = 1;
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
        int setPoints(int pointsInput) {
            return points = pointsInput;
        }
        int getPoints() {
            return points;
        }
        int placeShip(int** coordsInput) {
            fleet.createShip(coordsInput);
            return 0;
        }
        int setPlayerNum(bool playerNumInput) {
            return playerNum = playerNumInput;
        }
        bool getPlayerNum() {
            return playerNum;
        }
        int setPlayerFleet(Fleet fleetInput) {
            fleet = fleetInput;
            return 0;
        }
        Fleet getPlayerFleet() {
            return fleet;
        }
        int setPlayerGrid(int** playerGridInput) {
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++) {
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++) {
                    playerGrid[yCoordIndex][xCoordIndex] = playerGridInput[yCoordIndex][xCoordIndex];
                }   
            }
            return 0;
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
        int setOpponentGrid(char playerGridInput[][GRIDWIDTH]) {
            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++) {
                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++) {
                    playerGrid[yCoordIndex][xCoordIndex] = playerGridInput[yCoordIndex][xCoordIndex];
                }   
            }
            return 0;
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
        int points;
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
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
            {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
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
            setActivePlayer(tempActivePlayer);
            cout << "Player " << tempActivePlayer.getPlayerNum() + 1 << ", you go first." << endl;
            takeSetupTurn(tempActivePlayer);
            setActivePlayer(players[!getActivePlayerIndex()]);
            cout << "Player " << tempActivePlayer.getPlayerNum() + 1 << ", your turn now." << endl;
            takeSetupTurn(tempActivePlayer);
            return 0;
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
        int checkScore(Player playerInput) {
            return playerInput.getPoints();
        }
        int playerWin() {
            int player1Score = checkScore(players[0]);
            int player2Score = checkScore(players[1]);
            if (player1Score > player2Score && player1Score >= 6) {
                return 1;
            } 
            else if (player2Score > player1Score && player2Score >= 6) {
                return 2;
            } else {
                return 0;
            }
        }
        bool gameEnd() {
            switch (playerWin()) {
                case 0: 
                    break;
                case 1:
                    cout << "Player 1 Wins!" << endl;
                    return 1;
                case 2:
                    cout << "Player 2 Wins!" << endl;
                    return 1;
            }
            return 0;
        }
        bool shoot() { // 0 means no ship and no shots, 1 means ship and no shots, 2 means no ship and a shot, 3 means a ship and a shot.
            int coord = players[!getActivePlayerIndex()].getPlayerGrid()[getShotCoords()[0]][getShotCoords()[1]];
            if (coord == 0 || coord == 1) {
                Fleet tempFleet = players[!getActivePlayerIndex()].getPlayerFleet();
                Ship tempShip;
                int tempCoords[2];
                bool shipStanding = 1;
                int* tempShipVals = 0;
                char tempGrid[GRIDHEIGHT][GRIDWIDTH];
                for (int fleetIndex = 0; fleetIndex < FLEETSIZE; fleetIndex++) {
                    tempShip = tempFleet.getShipArray()[fleetIndex];
                    for (int shipLengthIndex = 0; shipLengthIndex < tempShip.getLength(); shipLengthIndex++) {
                        tempShipVals = new int [tempShip.getLength()];
                        tempCoords[0] = tempShip.getCoords()[shipLengthIndex][0];
                        tempCoords[1] = tempShip.getCoords()[shipLengthIndex][1];
                        if (tempCoords[0] == getShotCoords()[0] && tempCoords[1] == getShotCoords()[1]) {
                            players[!getActivePlayerIndex()].getPlayerGrid()[getShotCoords()[0]][getShotCoords()[1]] += 2;
                            for (int yCoordIndex = 0; yCoordIndex < GRIDHEIGHT; yCoordIndex++) {
                                for (int xCoordIndex = 0; xCoordIndex < GRIDWIDTH; xCoordIndex++) {
                                    tempGrid[yCoordIndex][xCoordIndex] 
                                    = players[getActivePlayerIndex()].getOpponentGrid()[yCoordIndex][xCoordIndex];
                                }
                            }
                            tempGrid[getShotCoords()[0]][getShotCoords()[1]] = 'X';
                            getActivePlayer().setOpponentGrid(tempGrid);
                            if (coord == 0) {
                                cout << "Miss." << endl;
                            } else {
                                cout << "HIT!" << endl;
                            }
                        }
                        tempShipVals[shipLengthIndex] = 
                        players[!getActivePlayerIndex()].getPlayerGrid()[getShotCoords()[0]][getShotCoords()[1]];
                    }
                    for (int tempShipValsIndex = 0; tempShipValsIndex < tempShip.getLength(); tempShipValsIndex++) {
                        switch (tempShipVals[tempShipValsIndex]) {
                            case 1:
                                shipStanding = 1;
                                tempShipValsIndex = tempShip.getLength();
                            case 3:
                                shipStanding = 0;
                        }
                    }
                    if (!shipStanding) {
                        getActivePlayer().setPoints(getActivePlayer().getPoints() + 1);
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
            string currentPlayerStringInput;
            while (!shoot()) {
                displayGrids(playerInput);
                cout << "Player " << (getActivePlayerIndex() + 1) << endl;
                cout << "The top grid displays your opponent\'s fleet, the bottom grid displays yours." << endl;
                cout << "Xs are hits, Os are misses." << endl;
                cout << "Take your shot." << endl;
                cout << "Input the y coordinate of your shot, a value between 1 and 10:" << endl;
                cin >> currentPlayerStringInput;
                yCoord = stoi(currentPlayerStringInput);
                currentPlayerStringInput.clear();
                cout << "Input the x coordinate of your shot, a value between 1 and 10:" << endl;
                cin >> currentPlayerStringInput;
                xCoord = stoi(currentPlayerStringInput);
                currentPlayerStringInput.clear();
                tempShotCoords[0] = yCoord;
                tempShotCoords[1] = xCoord;
                setShotCoords(tempShotCoords);
                shoot();  
            }
            return setActivePlayer(players[!getActivePlayerIndex()]);
        }
        int takeSetupTurn(Player playerInput) {
            Fleet tempFleet = getActivePlayer().getPlayerFleet();
            int shipLength = 0;
            int yStartCoord = 0, xStartCoord = 0,
                yEndCoord = 0, xEndCoord = 0;
            int startCoords[2], endCoords[2];
            bool validYStartCoord = 0, validXStartCoord = 0,
                validStartCoords = 0, validEndCoords = 0;
            bool shipInWay = 0;
            int validEndCoordsArray[4][2];
            int chosenCoordsOption = 0;
            int numOptions = 0;
            int yDirectionMultiplier = 0, xDirectionMultiplier;
            string currentPlayerStringInput;
            for (int shipIndex = 0; shipIndex < FLEETSIZE; shipIndex++) {
                displayPlayerGrid(getActivePlayer());
                cout << "Player " << (getActivePlayerIndex());
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
                    numOptions = 0;
                    yDirectionMultiplier = 0;
                    xDirectionMultiplier = 0;
                    startCoords[0] = 0;
                    startCoords[1] = 0;
                    while (!validXStartCoord) {
                        cout << "Input your starting X coordinate, a value between 1 and 10 (including 1 and 10):" << endl;
                        cin >> currentPlayerStringInput;
                        startCoords[1] = stoi(currentPlayerStringInput);
                        currentPlayerStringInput.clear();
                        validXStartCoord = 
                            (startCoords[1] >= 0 
                            && startCoords[1] <= GRIDWIDTH - 1);
                        if (!validXStartCoord) {
                            cout << "Invald coordinate: Improper value." << endl;
                        }
                    }
                    startCoords[1] -= 1; // Converts to index number

                    while (!validYStartCoord) {
                        cout << "Input your starting Y coordinate, a value between 1 and 10 (including 1 and 10):" << endl;
                        cin >> currentPlayerStringInput;
                        startCoords[0] = stoi(currentPlayerStringInput);
                        currentPlayerStringInput.clear();
                        validYStartCoord = 
                            startCoords[0] >= 0 
                            && startCoords[0] <= GRIDHEIGHT - 1;
                        if (!validYStartCoord) {
                            cout << "Invald coordinate: Improper value." << endl;
                        }
                    }
                    startCoords[0] -= 1; // Converts to index number
                    
                    for (int directionIndex = 0; !shipInWay && directionIndex < 4; directionIndex++) { //placeholder
                        for (int shipCoordIndex = 0; shipCoordIndex < shipLength; shipCoordIndex++) {
                            switch (directionIndex) {
                                case 0: // North
                                    if (startCoords[0] - shipLength + 1 >= 0 ) {
                                        shipInWay = tempFleet.getShipArray()[shipIndex].getCoords()[startCoords[0] - shipCoordIndex][startCoords[1]] != 1;
                                        yDirectionMultiplier = -1;
                                        xDirectionMultiplier = 0;
                                    }
                                    break;
                                case 1: // South
                                    if (startCoords[0] + shipLength - 1 >= 0) {
                                        shipInWay = tempFleet.getShipArray()[shipIndex].getCoords()[startCoords[0] + shipCoordIndex][startCoords[1]] != 1;
                                        yDirectionMultiplier = 1;
                                        xDirectionMultiplier = 0;
                                    }
                                    break;
                                case 2: // East
                                    if (startCoords[1] + shipLength - 1 >= 0) {
                                        shipInWay = tempFleet.getShipArray()[shipIndex].getCoords()[startCoords[0]][startCoords[1] + shipCoordIndex] != 1;
                                        yDirectionMultiplier = 0;
                                        xDirectionMultiplier = 1;
                                    }
                                    break;
                                case 3: // West
                                    if (startCoords[1] - shipLength + 1 >= 0) {
                                        shipInWay = tempFleet.getShipArray()[shipIndex].getCoords()[startCoords[0]][startCoords[1] - shipCoordIndex] != 1;
                                        yDirectionMultiplier = 0;
                                        xDirectionMultiplier = -1;
                                    }
                                    break;
                            }
                        }
                        if (!shipInWay) {
                            validEndCoordsArray[numOptions][0] 
                                = tempFleet.getShipArray()[shipIndex].getCoords()
                                [startCoords[0] + ((shipLength - 1) * yDirectionMultiplier)]
                                [startCoords[1] + ((shipLength - 1) * xDirectionMultiplier)] != 1;
                            validEndCoordsArray[numOptions][1] 
                                = tempFleet.getShipArray()[shipIndex].getCoords()
                                [startCoords[0] + ((shipLength - 1) * yDirectionMultiplier)]
                                [startCoords[1] + ((shipLength - 1) * xDirectionMultiplier)] != 1;
                            numOptions++; // counts number of options there are, used later
                        } else {
                            shipInWay = 0; // Resets, reusing in this instance to only add valid coords
                        }
                    }
                    shipInWay = (numOptions > 0);
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
                    cout << "The length of the ship you are placing is: " << shipLength;
                    cout << " and your starting coordinates are X: " << (startCoords[1] + 1);
                    cout << " , Y: " << (startCoords[0] + 1) << endl;
                    cout << "Which of these coordinates would you like the back end of the ship to be placed in?." << endl; 
                    for (int validEndCoordsArrayIndex = 0; validEndCoordsArrayIndex < numOptions; validEndCoordsArrayIndex++) {
                        cout << "Type \"" << (validEndCoordsArrayIndex + 1) << "\" for: X: " << validEndCoordsArray[validEndCoordsArrayIndex][0];
                        cout << ", Y: " << validEndCoordsArray[validEndCoordsArrayIndex][1] << "." << endl;
                    }
                    cin >> currentPlayerStringInput;
                    chosenCoordsOption = stoi(currentPlayerStringInput);
                    currentPlayerStringInput.clear();
                    if (chosenCoordsOption > 0 && chosenCoordsOption <= numOptions) {
                        endCoords[0] = validEndCoordsArray[chosenCoordsOption - 1][0];
                        endCoords[1] = validEndCoordsArray[chosenCoordsOption - 1][1];
                        endCoords[0] -= 1; // Converts to index number
                        endCoords[1] -= 1; // Converts to index number
                        validEndCoords = 1;
                        // Math for adding the full coords to the ship
                        int* finalCoords[shipLength];
                        finalCoords[0][0] = startCoords[0];
                        finalCoords[0][1] = startCoords[1];
                        for (int finalCoordsIndex = 0; finalCoordsIndex < shipLength - 2; finalCoordsIndex++) {
                            finalCoords[finalCoordsIndex][0] = 
                            startCoords[0] + ((shipLength - 1) * yDirectionMultiplier);
                            finalCoords[finalCoordsIndex][1] =
                            startCoords[1] + ((shipLength - 1) * xDirectionMultiplier);
                        }
                        finalCoords[shipLength][0] = endCoords[0];
                        finalCoords[shipLength][1] = endCoords[1];
                        tempFleet.getShipArray()[shipIndex].setCoords(finalCoords);// HERE HERE
                        players[getActivePlayerIndex()].setPlayerFleet(tempFleet);
                    } else {
                        cout << "Invalid Selection: Number not listed." << endl;
                    }
                }
            }
            return 0;
        }
    protected:
        Player activePlayer;
        int* shotCoords;
};

int main() {
    Game game;
    Game* gameptr = &game;
    game.startGame();
    while (!(game.gameEnd())) {
        Player currentPlayer = game.getActivePlayer();
        game.takeTurn(currentPlayer);
    }
}