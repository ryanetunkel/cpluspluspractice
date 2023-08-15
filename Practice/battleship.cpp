#include <iostream>
#include <cmath>
using namespace std;

class Ship {
public:
    int length;
    int **coords;
    int set_length(int length_input);
    int get_length();
    int set_coords(int **coords_input);
    int **get_coords();
};

int Ship::set_length(int length_input) {
    return length = length_input;
}

int Ship::get_length() {
    return length;
}

int Ship::set_coords(int **coords_input)
{
    bool coords_set = 0;
    for (int y_coord_index = 0; y_coord_index < sizeof(coords_input) / sizeof(int); y_coord_index++) {
        for (int x_coord_index = 0; x_coord_index < sizeof(coords_input[y_coord_index]) / sizeof(int); x_coord_index++) {
            coords_input[y_coord_index][x_coord_index] = coords[y_coord_index][x_coord_index];
        }
    }
    set_length(sizeof(coords) / sizeof(int));
    coords = coords_input;
    return coords_set;
}

int **Ship::get_coords() {
    return coords;
}

Ship createShip(**coords_input) {
    Ship new_ship
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
    bool player_turn = rand() % 2;
    cout << "Player " + ((int)player_turn + 1);
    for ()
        if (num_ships)
            cout << " place your ships. Input coordinates of ship length" cout << (player_turn) ? "Player 2, " : "Player 1, ";
}