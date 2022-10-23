#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global variable to set the maximum number to be generated to recall the users input for the new max throughout the program
int max_number = 10;
int main()
{
    int numberOfGuess, guess, option, max, win = 0, randomNumber;
    char c[2];
    FILE *fp;
    // do-while loop for the list of menu user can choose until the exit by entering option 3
    do
    {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");
        scanf("%d", &option);
        // switch case is implemented to perform each task according to user input
        switch (option)
        {
        case 1:
            numberOfGuess = 0;
            // Generate a random number from 0 to maximum number set by the user
            if (access("./maxNumber.txt", F_OK) == 0)
            {
                // File exist
                fp = fopen("maxNum.txt", "r");
                fscanf(fp, "%d", &max_number);
            }
            else
            {
                // File doesnt exist
                max_number = 10;
            }

            randomNumber = rand() % max_number + 1;
            printf("Please enter a number \n");
            do
            {
                scanf("%s", &c);
                // when user enters q it quits the game
                if (c[0] == 'q')
                    break;
                else
                {
                    // if the input is not q then it must be a guessed number convert the string to a number
                    guess = atoi(c);
                    // if the guessed number is greater than the random generated number
                    if (guess > randomNumber)
                        printf("You are too high\n");
                    // if the guessed number is greater than the random generated number
                    else if (guess < randomNumber)
                        printf("You are too low\n");
                    else
                    {
                        win = 1;
                        printf("You have guessed the correct number\n");
                        break;
                    }
                    // count the total number of guess the user takes to find the correct number
                    numberOfGuess++;
                }
            } while (c[0] != 'q' || randomNumber == guess);
            // if user enter q or the guess is correct exit from the game
            break;
        case 2:
            // ask the user to set the new maximum number
            char arr[20];
            printf("Enter the new maximum number:\n");
            do
            {
                scanf("%d", &max);
                // if the new maximum number is not between 0 to 10
                if (max <= 0 || max > 10)
                    printf("Please enter a valid number \n");
                // if the new number is valid assign it to our global variable
                else
                {
                    fp = fopen("maxNumber.txt", "w");
                    itoa(max, arr, 10);
                    fprintf(fp, arr);
                    fclose(fp);
                    max_number = max;
                    break;
                }
            } while (max <= 0 || max > 10);
            printf("The new maximum number generated will be between 0 to %d\n", max_number);
            break;
        case 3:
            // if user enters to quit the game print the results of the game they played
            printf("Thank you for playing the game\n");
            printf("The results of the games played are:\n");
            if (win == 1)
            {
                printf("You have won the game\n");
                printf("Number of guess required to win are %d", numberOfGuess);
            }
            else
            {
                printf("You have lost the game");
            }
            break;
        }
    } while (option != 3);
    // loop exits if user enters option 3
    return 0;
}
