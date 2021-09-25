/*
Gravino, Andrew
CS2600, First In-Class Coding Assignment
9/24/21

1. Declare variables that will correspond to a game state, the inputs of a user, and off of elements within the game rules
2. Create pseudorandom number generator
3. Create if statements regarding the results of success vs failure
4. Print out messages depending on success vs failure
5. Loop depending on choice
6. Update loop to stop also depending on choice
7. Terminate
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char playState = 'z';
    char modeChoice = '0';
    time_t t;
    int number;
    int guessedNumber;

    srand((unsigned) time(&t));
    number = (rand() % (10 - 1 + 1)) + 1;
    
    while(playState == 'z'){
        printf("Would you like to play the Guessing Game? (1 to start, 2 to change the max number, 3 to quit)");
        scanf("%s", &modeChoice);
    }

    while(modeChoice == '1' || playState == 'a'){
        playState = 'a';
        printf("Guess a number between 1-10.");
        scanf("%d", &guessedNumber);
        
        if(guessedNumber == number){
            printf("You won!");
            modeChoice = '0';
            number = (rand() % (10 - 1 + 1)) + 1; //refresh
            playState = 'z';
        }
        else if(guessedNumber > number){
            printf("You're too high... Press q to quit or a to try again!");
            scanf("%s", &playState);
        }
        else if(guessedNumber < number){
            printf("You're too low... Press q to quit or a to try again!");
            scanf("%s", &playState);
        }
    }
    if(modeChoice == '2'){
        modeChoice = '0';
        printf("Set a max number between 0 and 32767");
        scanf("%d", &number);
        while(number < 0 || number > 32767){
            printf("Those values are too extreme!");
            modeChoice = '2';
        }
        modeChoice = '1';
    }
    if(modeChoice == '3' || playState == 'q'){
        modeChoice = '3';
        playState = 'q';
        printf("Thank you for playing. Bye!");
    }

    return 0;
}