//Basic Header
#include <stdio.h>
#include <stdlib.h>

//For isdigit() and isalpha() function
#include <ctype.h>
//For Random
#include <time.h>

//Function for the game
int game(char player, char computer){
    //Returns -1 if its a Draw
    //Returns 1 if its a Win
    //Returns 0 if its a Lose
    if(player == computer){
        return -1;
    }

    if(player == 'R' && computer == 'S'){
        return 1;
    }else if(player == 'S' && computer == 'R'){
        return 0;
    }

    if(player == 'S' && computer == 'P'){
        return 1;
    }else if(player == 'P' && computer == 'S'){
        return 0;
    }

    if(player == 'P' && computer == 'R'){
        return 1;
    }else if(player == 'R' && computer == 'P'){
        return 0;
    }
}

int main()
{
    int numBegin, randomNumber;
    char player , computer, result;

    //User Design
    printf("\t\t\t====================================================================\n");
    printf("\t\t\t|                 Welcome To The Rock, Paper, Scissors Game        |\n");
    printf("\t\t\t|                    Developed By: John Paul B. Singco             |\n");
    printf("\t\t\t====================================================================\n\n");
    printf("\t\t\t1. Start\n");
    printf("\t\t\t2. Exit\n\n");

    //User Input
    printf("\t\t\tChoose: ");
    scanf("%d", &numBegin);

    //Determines if the user inputs more than 1
    //Keeps looping as long as the numBegin is not equals to 1 or 2
    while(numBegin != 1 && numBegin != 2){
        //This is used to clear the console
        system("cls");
        printf("Please select 1 or 2: ");
        scanf("%d", &numBegin);
        if(numBegin == 1){
            system("cls");
            break;
        }else if(numBegin == 2){
            system("cls");
            break;
        }
    }

    if(numBegin == 1){
        system("cls");
        printf("\t\t\t==========================================================\n");
        printf("\t\t\t|                   \"S\" for Scissors                     |\n");
        printf("\t\t\t|                   \"R\" for Rock                         |\n");
        printf("\t\t\t|                   \"P\" for Paper                        |\n");
        printf("\t\t\t==========================================================\n\n");
    }else if(numBegin == 2){
        printf("Exiting...");
        exit(0);
    }
    //Chooses the random number
    srand(time(NULL));

    //Limits the random number from 0 to 2
    randomNumber = rand() % 3;


    if(randomNumber == 0){
        computer = 'R';
    }else if(randomNumber == 1){
        computer = 'S';
    }else if(randomNumber == 2){
        computer = 'P';
    }

    //User input
    printf("\t\t\tPlease Choose Wisely: ");
    scanf("%s", &player);

    //Converts the player to uppercase
    player = toupper(player);

    result = game(player, computer);

    if(result == -1){
        printf("\n\t\t\tLol! Its a draw\n\n");
    }else if(result == 1){
        printf("\n\t\t\tCongrats! You win!\n\n");
    }else{
        printf("\n\t\t\tNoob! You lose!\n\n");
    }
    printf("\t\t\tThe computer choosed %c while you choose %c\n\n\n", computer,player);
    return 0;
}
