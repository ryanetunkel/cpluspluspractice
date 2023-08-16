#include <iostream>
#include <cmath>
using namespace std;

class Ship: public Fleet {
    public:
        int setLength(int lengthInput) {
            return length = lengthInput;
        }
        int getLength();
        int setCoords(int** coordsInput);
        int** getCoords();
    
    protected:
        int length;
        int** coords;
};



int Ship::getLength() {
    return length;
}

int Ship::setCoords(int** coordsInput)
{
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

int** Ship::getCoords() {
    return coords;
}

class Fleet: public Player {
    public:
        Ship shipArray[6];
        Ship createShip(int** coordsInput);
        int addShip(Ship *addedShip);
};
// Ships
// 1 4
// 2 3s
// 3 2s

int Fleet::addShip(Ship* addedShip): {
    shipArray.append(addedShip);
    return shipArray.contains(addedShip);
}

Ship Fleet::createShip(int** coordsInput) {
    Ship* newShip;
    fleet.addShip(newShip);
    newShip.setCoords(coordsInput);
    return newShip;
}

class Player {
    bool playerNum;
    int** coordsInput;
    Fleet fleet;
    int** setCoordsInput(int** coordsInput);
    int placeShip(Ship ship);
};

int Player::placeShip(Ship ship) {
    return 0;
}

class Game {
    Player players[2];
    bool playerTurn;
    int takeTurn();
};

int Game::takeTurn() {
    return 0;
}

int main() {
    // Switch 1s to 2s if hit
    int ships1[10][10] = {
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int ships2[10][10] = {
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    bool playerTurn = rand() % 2;
    cout << "Player " + ((int)playerTurn + 1);
    for () {
        if (numShips <= player.fleet.size()) {
            cout << " place your ships. Input coordinates of ship length "; 
            cout << (playerTurn) ? "Player 2, " : "Player 1, ";
        }
    }
}