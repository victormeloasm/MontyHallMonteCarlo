#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIMULATIONS 1000000

int simulateMontyHall() {
    int carLocation = rand() % 3;
    int initialChoice = rand() % 3;
    int revealedGoat;
    do {
        revealedGoat = rand() % 3;
    } while (revealedGoat == carLocation || revealedGoat == initialChoice);

    int switchedChoice;
    do {
        switchedChoice = rand() % 3;
    } while (switchedChoice == initialChoice || switchedChoice == revealedGoat);

    return initialChoice == carLocation;
}

int main() {
    srand(time(NULL));

    int winsBySticking = 0;
    int winsBySwitching = 0;

    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        int win = simulateMontyHall();
        winsBySticking += win;
        winsBySwitching += !win;
    }

    double stickWinProbability = (double)winsBySticking / NUM_SIMULATIONS;
    double switchWinProbability = (double)winsBySwitching / NUM_SIMULATIONS;

    printf("Monte Carlo Simulation Results:\n");
    printf("Wins by sticking: %d/%d (%.4f)\n", winsBySticking, NUM_SIMULATIONS, stickWinProbability);
    printf("Wins by switching: %d/%d (%.4f)\n", winsBySwitching, NUM_SIMULATIONS, switchWinProbability);
    getch();
    return 0;
}
