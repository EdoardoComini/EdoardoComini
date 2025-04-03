#include <iostream>
using namespace std;

// Funzione per muovere il robot in avanti, tenendo conto della direzione e del bordo della griglia
void moveForward(int& x, int& y, char direction, int gridSize) {
    if (direction == 'U' && y < gridSize - 1) {
        y++;  // Muove il robot in alto (direzione 'Up')
    }
    else if (direction == 'D' && y > 0) {
        y--;  // Muove il robot in basso (direzione 'Down')
    }
    else if (direction == 'L' && x > 0) {
        x--;  // Muove il robot a sinistra (direzione 'Left')
    }
    else if (direction == 'R' && x < gridSize - 1) {
        x++;  // Muove il robot a destra (direzione 'Right')
    }
    else {
        cout << "Ostacolo o bordo raggiunto!" << endl;
    }
}

// Funzione per girare il robot a destra
void turnRight(char& direction) {
    if (direction == 'U') direction = 'R';  // Da su a destra
    else if (direction == 'R') direction = 'D';  // Da destra a giù
    else if (direction == 'D') direction = 'L';  // Da giù a sinistra
    else if (direction == 'L') direction = 'U';  // Da sinistra a su
}

// Funzione per girare il robot a sinistra
void turnLeft(char& direction) {
    if (direction == 'U') direction = 'L';  // Da su a sinistra
    else if (direction == 'L') direction = 'D';  // Da sinistra a giù
    else if (direction == 'D') direction = 'R';  // Da giù a destra
    else if (direction == 'R') direction = 'U';  // Da destra a su
}

int main() {
    int gridSize = 5;  // Dimensione della griglia (5x5)
    int robotPosX = 2;  // Posizione iniziale X del robot (al centro)
    int robotPosY = 2;  // Posizione iniziale Y del robot (al centro)
    char robotDirection = 'U';  // Direzione iniziale del robot: 'U' = Up (su)

    // Mostra la posizione iniziale del robot
    cout << "Posizione iniziale del robot: (" << robotPosX << ", " << robotPosY << ") direzione: " << robotDirection << endl;

    // Muove il robot in avanti
    moveForward(robotPosX, robotPosY, robotDirection, gridSize);
    cout << "Posizione dopo aver avanzato: (" << robotPosX << ", " << robotPosY << ")" << endl;

    // Gira il robot a destra
    turnRight(robotDirection);
    cout << "Nuova direzione dopo giro a destra: " << robotDirection << endl;

    // Muove di nuovo il robot in avanti
    moveForward(robotPosX, robotPosY, robotDirection, gridSize);
    cout << "Posizione dopo aver avanzato: (" << robotPosX << ", " << robotPosY << ")" << endl;

    // Gira il robot a sinistra
    turnLeft(robotDirection);
    cout << "Nuova direzione dopo giro a sinistra: " << robotDirection << endl;

    // Muove il robot in avanti
    moveForward(robotPosX, robotPosY, robotDirection, gridSize);
    cout << "Posizione finale del robot: (" << robotPosX << ", " << robotPosY << ")" << endl;

    return 0;
}
