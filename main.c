#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// User-defined function prototype
void displayMenu();
void setDifficulty(int *pDiff);
void setNumGames(int *pNumOfGames);
void getComputerPegs(int *pCPeg1, int *pCPeg2,
                     int *pCPeg3, int *pCPeg4,
                     int nPegs);
void getHumanPegs(int *pHPeg1, int *pHPeg2,
                  int *pHPeg3, int *pHPeg4,
                  int nPegs, int nAttempt,
                  int isHumanCodebreaker);
void checkPegValues(int *pCPeg1, int *pCPeg2,
                    int *pCPeg3, int *pCPeg4,
                    int *pHPeg1, int *pHPeg2,
                    int *pHPeg3, int *pHPeg4,
                    int *pCorrect);
void showScoreBoard(int nNumOfGames,
                       int nHPoints,
                       int nCPoints);
void showCodePegs(int nDiff);
void playGame(int *pDiff, int *pGames,
              int *pHPoints, int *pCPoints);
void showWinner(int nHPoints, int nCPoints);


int main()
{
    srand(time(0));
    displayMenu();
    return 0;
}


/*******************************************************************************
    Description:    This function simulates the menu.
         @param:    <None>
        @return:    <None>
*******************************************************************************/
void displayMenu()
{
    int nChoice, nDiff, nNumOfGames,
        nHPoints = 0, nCPoints = 0;

    do
    {

    system("cls");
    // Intro Screen
    printf("                  __ __  ___  __   __      \n");
    printf("                 |  V  || __|/ _] /  \\    \n");
    printf("                 | \\_/ || _|| [/\\| /\\ | \n");
    printf("                 |_| |_||___|\\__/|_||_|   \n");
    printf(" __ __   __    __  _____  ___  ___  __ __  _  __  _  __      \n");
    printf("|  V  | /  \\ /' _/|_   _|| __|| _ \\|  V  || ||  \\| || _\\ \n");
    printf("| \\_/ || /\\ |`._`.  | |  | _| | v /| \\_/ || || | ' || v | \n");
    printf("|_| |_||_||_||___/  |_|  |___||_|_\\|_| |_||_||_|\\__||__/   \n\n");
    printf("  (1) Play Game\n");
    printf("  (2) Instructions\n");
    printf("  (3) Exit\n");

        do
        {
            do
            {
                printf("Enter Choice (1,2,3): ");
                scanf("%d", &nChoice);
                if (!(1 <= nChoice && nChoice <= 3))
                    printf("Enter a valid choice!\n");
            }
            while (getchar() != '\n');
        }
        while (!(1 <= nChoice && nChoice <= 3));
        if (nChoice == 1)
        {
            system("cls");
            setDifficulty(&nDiff);
            setNumGames(&nNumOfGames);
            playGame(&nDiff, &nNumOfGames, &nHPoints, &nCPoints);
            showScoreBoard(nNumOfGames, nHPoints, nCPoints);
            showWinner(nHPoints, nCPoints);
            system("pause");
        }
        else if (nChoice == 2)
        {
            system("cls");
            printf("===================== INSTRUCTIONS ====================\n");
            printf("The code can be made up of any combination of the\n");
            printf("lettered pegs. You may not use two or more pegs of the\n");
            printf("same letter.\n\n");
            printf("Once the code is set, the codebreaker can begin\n");
            printf("guessing, trying to duplicate the exact letters and\n");
            printf("positions of the hidden code pegs.\n\n");
            printf("Each guess is made by placing a row of code pegs on\n");
            printf("the terminal. Each row of pegs should be left in\n");
            printf("position throughout the game.\n\n");
            printf("After every guess, the codemaker must inform the\n");
            printf("codebreaker of their progress. (W) for correct peg but\n");
            printf("in the wrong position, (B) for correct peg and in the\n");
            printf("right position\n");
            printf("=======================================================\n");
            system("pause");
        }
        else if (nChoice == 3)
        {
            printf("Goodbye! Have a nice day!");
        }
    }
    while (nChoice != 3);
}


/*******************************************************************************
    Description:    This function sets the difficulty of the game.
         @param:    int *pDiff
        @return:    int *pDiff
*******************************************************************************/
void setDifficulty(int *pDiff)
{
    int nDiff;
    printf("-------------(1)-EASY-------------------\n");
    printf("   6 Possible Code Pegs, 10 Attempts    \n");
    printf("----------------------------------------\n\n");
    printf("-------------(2)-AVERAGE----------------\n");
    printf("   8 Possible Code Pegs, 12 Attempts    \n");
    printf("----------------------------------------\n\n");
    printf("-------------(3)-DIFFICULT--------------\n");
    printf("   10 Possible Code Pegs, 16 Attempts   \n");
    printf("----------------------------------------\n\n");
    printf("-------------(4)-EXTREME----------------\n");
    printf("   16 Possible Code Pegs, 20 Attempts   \n");
    printf("----------------------------------------\n\n");
    do
    {
        do
        {
            printf("Select Difficulty (1,2,3,4): ");
            scanf("%d", &nDiff);
            if (!(1 <= nDiff && nDiff <= 4))
            {
                printf("Enter a valid choice!\n");
            }
            printf("\n");
        }
        while (getchar() != '\n');
    }
    while (!(1 <= nDiff && nDiff <= 4));
    *pDiff = nDiff;
}


/*******************************************************************************
    Description:    This function sets the number of games to be played.
         @param:    int *pNumOfGames 
        @return:    int *pNumOfGames
*******************************************************************************/
void setNumGames(int *pNumOfGames)
{
    int nGames;
    do
    {
        /**********************************************
        While loop to clean input buffer.
        Handles infinite loop when entered a character.
        **********************************************/
        do
        {
            printf("Set number of games (2,4,6,8,10): ");
            scanf("%d", &nGames);
            if (!(nGames >= 2 &&
                nGames <= 10 &&
                nGames % 2 == 0))
            {
                printf("Enter a valid choice!\n");
            }
            printf("\n");
        }
        while (getchar() != '\n');
    }
    while (!(nGames >= 2 &&
             nGames <= 10 &&
             nGames % 2 == 0));
    *pNumOfGames = nGames;
}


/*******************************************************************************
    Description:    This function sets unique random pegs for AI.
         @param:    int *pCPeg1, *pCPeg2, *pCPeg3,
                        *pCPeg4, nPegs
        @return:    int *pCPeg1, *pCPeg2, *pCPeg3,
                        *pCPeg4
*******************************************************************************/
void getComputerPegs(int *pCPeg1, int *pCPeg2,
                     int *pCPeg3, int *pCPeg4,
                     int nPegs)
{
    int nLower = 65,
        nUpper = 65 + nPegs;

    do
    {
        *pCPeg1 = (rand() % (nUpper - nLower + 1)) + nLower;
        *pCPeg2 = (rand() % (nUpper - nLower + 1)) + nLower;
        *pCPeg3 = (rand() % (nUpper - nLower + 1)) + nLower;
        *pCPeg4 = (rand() % (nUpper - nLower + 1)) + nLower;
    }
    while (*pCPeg1 == *pCPeg2 ||
           *pCPeg1 == *pCPeg3 ||
           *pCPeg1 == *pCPeg4 ||
           *pCPeg2 == *pCPeg3 ||
           *pCPeg2 == *pCPeg4 ||
           *pCPeg3 == *pCPeg4);
}


/*******************************************************************************
    Description:    This function sets the human pegs.
         @param:    int *pHPeg1, *pHPeg2, *pHPeg3, *pHPeg4,
                        nGame, nAttempt
        @return:    int *pHPeg1, *pHPeg2, *pHPeg3,
                        *pHPeg4
*******************************************************************************/
void getHumanPegs(int *pHPeg1, int *pHPeg2,
                  int *pHPeg3, int *pHPeg4,
                  int nPegs, int nAttempt,
                  int isHumanCodebreaker)
{
    char cPeg1, cPeg2, cPeg3, cPeg4;
    do
    {
        if (isHumanCodebreaker)
        {
            printf("Attempt %d (use spaces in between):\t", nAttempt);
        }
        else
        {
            printf("Make a Code: ");
        }
        scanf(" %c %c %c %c", &cPeg1, &cPeg2, &cPeg3, &cPeg4);
        *pHPeg1 = toupper(cPeg1);
        *pHPeg2 = toupper(cPeg2);
        *pHPeg3 = toupper(cPeg3);
        *pHPeg4 = toupper(cPeg4);
        if (!(65 <= *pHPeg1 && *pHPeg1 <= 65 + nPegs &&
             65 <= *pHPeg2 && *pHPeg2 <= 65 + nPegs &&
             65 <= *pHPeg3 && *pHPeg3 <= 65 + nPegs &&
             65 <= *pHPeg4 && *pHPeg4 <= 65 + nPegs))
        {
            printf("Enter a valid peg!\n");
        }
        if ((*pHPeg1 == *pHPeg2 ||
             *pHPeg1 == *pHPeg3 ||
             *pHPeg1 == *pHPeg4 ||
             *pHPeg2 == *pHPeg3 ||
             *pHPeg2 == *pHPeg4 ||
             *pHPeg3 == *pHPeg4))
        {
            printf("Do not enter duplicates!\n");
        }
    }
    while (!(65 <= *pHPeg1 && *pHPeg1 <= 65 + nPegs &&
             65 <= *pHPeg2 && *pHPeg2 <= 65 + nPegs &&
             65 <= *pHPeg3 && *pHPeg3 <= 65 + nPegs &&
             65 <= *pHPeg4 && *pHPeg4 <= 65 + nPegs) ||
                  (*pHPeg1 == *pHPeg2 ||
                   *pHPeg1 == *pHPeg3 ||
                   *pHPeg1 == *pHPeg4 ||
                   *pHPeg2 == *pHPeg3 ||
                   *pHPeg2 == *pHPeg4 ||
                   *pHPeg3 == *pHPeg4));
}


/*******************************************************************************
    Description:    This function checks all peg values.
         @param:    int *pCPeg1, *pCPeg2, *pCPeg3,
                        *pCPeg4, *pHPeg1, *pHPeg2,
                        *pHPeg3, *pHPeg4, *pCorrect
        @return:    int *pCorrect
*******************************************************************************/
void checkPegValues(int *pCPeg1, int *pCPeg2,
                    int *pCPeg3, int *pCPeg4,
                    int *pHPeg1, int *pHPeg2,
                    int *pHPeg3, int *pHPeg4,
                    int *pCorrect)
{
    int nClose = 0,
        nCorrect = 0;

    // Loading 
    printf("Checking pegs");
    Sleep(500);
    printf("...");
    Sleep(500);
    printf("...");
    Sleep(500);
    printf(".. ");
    printf("done!\n");

    // Count Close Peg    
    if (*pHPeg1 == *pCPeg2 ||
        *pHPeg1 == *pCPeg3 ||
        *pHPeg1 == *pCPeg4)
    {
        nClose += 1;
    }
    if (*pHPeg2 == *pCPeg1 ||
        *pHPeg2 == *pCPeg3 ||
        *pHPeg2 == *pCPeg4)
    {
        nClose += 1;
    }
    if (*pHPeg3 == *pCPeg1 ||
        *pHPeg3 == *pCPeg2 ||
        *pHPeg3 == *pCPeg4)
    {
        nClose += 1;
    }
    if (*pHPeg4 == *pCPeg1 ||
        *pHPeg4 == *pCPeg2 ||
        *pHPeg4 == *pCPeg3)
    {
        nClose += 1;
    }

    // Count Correct Peg
    if (*pHPeg1 == *pCPeg1)
    {
        nCorrect += 1;
    }
    if (*pHPeg2 == *pCPeg2)
    {
        nCorrect += 1;
    }
    if (*pHPeg3 == *pCPeg3)
    {
        nCorrect += 1;
    }
    if (*pHPeg4 == *pCPeg4)
    {
        nCorrect += 1;
    }

    printf("Here are the results: ");
    for (int i = 0; i < nCorrect; i++)
    {
        printf("B ");
    }
    for (int j = 0; j < nClose; j++)
    {
        printf("W ");
    }
    printf("\n\n");

    *pCorrect = nCorrect;
}


/*******************************************************************************
    Description:    This function displays all possible code pegs.
         @param:    int nDiff 
        @return:    <None>
*******************************************************************************/
void showCodePegs(int nDiff)
{
    // Possible Code Pegs
    switch(nDiff)
    {
        case 1:
            printf("-------------- POSSIBLE CODE PEGS -------------\n");
            printf("                A, B, C, D, E, F               \n");
            printf("-----------------------------------------------\n\n");
            break;
        case 2:
            printf("-------------- POSSIBLE CODE PEGS -------------\n");
            printf("             A, B, C, D, E, F, G, H            \n");
            printf("-----------------------------------------------\n\n");
            break;
        case 3:
            printf("-------------- POSSIBLE CODE PEGS -------------\n");
            printf("          A, B, C, D, E, F, G, H, I, J         \n");
            printf("-----------------------------------------------\n\n");
            break;
        case 4:
            printf("-------------- POSSIBLE CODE PEGS -------------\n");
            printf("             A, B, C, D, E, F, G, H            \n");
            printf("             I, J, K, L, M, N, O, P            \n");
            printf("-----------------------------------------------\n\n");
            break;
    }
}


/*******************************************************************************
    Description:    This function displays the score board.
         @param:    int nNumOfGames, nHPoints, nCPoints
        @return:    <None>
*******************************************************************************/
void showScoreBoard(int nNumOfGames,
                       int nHPoints,
                       int nCPoints)
{
    printf("----------------- SCORE BOARD -----------------\n");
    printf("    Game: %d    |    Human: %d    |    AI: %d \n",
            nNumOfGames, nHPoints, nCPoints);
    printf("-----------------------------------------------\n\n");
}


/*******************************************************************************
    Description:    This function starts the game.
         @param:    int *pDiff, *pGames, *pHPoints, *pCPoints
        @return:    int *pHPoints, *pCPoints
*******************************************************************************/
void playGame(int *pDiff, int *pGames,
              int *pHPoints, int *pCPoints)
{
    int nGame = 1;
    int nCorrect, nPegs,
        nCPeg1, nCPeg2,
        nCPeg3, nCPeg4,
        nHPeg1, nHPeg2,
        nHPeg3, nHPeg4,
        nAttempts, nAttempt,
        isHumanCodebreaker;

    switch(*pDiff)
    {
        case 1:
            nPegs = 6;
            nAttempts = 10;
            break;
        case 2:
            nPegs = 8;
            nAttempts = 12;
            break;
        case 3:
            nPegs = 10;
            nAttempts = 16;
            break;
        case 4:
            nPegs = 16;
            nAttempts = 20;
            break;
        default:
            nPegs = 6;
            nAttempts = 10;
    }
    nPegs--;

    while (nGame <= *pGames)
    {
        nAttempt = 1;
        nCorrect = 0;

        system("cls");
        showScoreBoard(nGame, *pHPoints, *pCPoints);
        showCodePegs(*pDiff);

        // Human as Codebreaker 
        isHumanCodebreaker = 1;
        printf("----------- YOU ARE THE CODEBREAKER! ----------\n");
        getComputerPegs(&nCPeg1, &nCPeg2, &nCPeg3,
                        &nCPeg4, nPegs);
        printf("\n");
        while (nAttempts >= nAttempt && nCorrect != 4)
        {
            getHumanPegs(&nHPeg1, &nHPeg2, &nHPeg3,
                         &nHPeg4, nPegs, nAttempt,
                         isHumanCodebreaker);
            checkPegValues(&nCPeg1, &nCPeg2,
                           &nCPeg3, &nCPeg4,
                           &nHPeg1, &nHPeg2,
                           &nHPeg3, &nHPeg4,
                           &nCorrect);
            *pCPoints += 1;
            nAttempt++;
        }
        if (nCorrect == 4)
        {
            printf("------ CONGRATULATIONS! YOU GOT THE CODE! -----\n\n");
            nCorrect = 0;
        }
        else
        {
            printf("------ NICE TRY! BUT THE CODE WAS %c %c %c %c -----\n\n",
                    nCPeg1, nCPeg2,
                    nCPeg3, nCPeg4);
            nCorrect = 0;
            *pCPoints += 1;
        }
        nAttempt = 1;
        system("pause");
        system("cls");


        // AI as Codebreaker
        isHumanCodebreaker = 0;
        showScoreBoard(nGame, *pHPoints, *pCPoints);
        showCodePegs(*pDiff);
        printf("-------------YOU ARE THE CODEMAKER! -----------\n");
        getHumanPegs(&nHPeg1, &nHPeg2, &nHPeg3,
                     &nHPeg4, nPegs, nAttempt,
                     isHumanCodebreaker);
        printf("\n");
        while (nAttempts >= nAttempt && nCorrect != 4)
        {
            getComputerPegs(&nCPeg1, &nCPeg2,
                            &nCPeg3, &nCPeg4,
                            nPegs);

            printf("Attempt %d (use spaces in between):\t", nAttempt);
            printf("%c %c %c %c\n",
                    nCPeg1, nCPeg2,
                    nCPeg3, nCPeg4);
            checkPegValues(&nCPeg1, &nCPeg2,
                           &nCPeg3, &nCPeg4,
                           &nHPeg1, &nHPeg2,
                           &nHPeg3, &nHPeg4,
                           &nCorrect);
            *pHPoints += 1;
            nAttempt++;
        }
        if (nCorrect == 4)
        {
            printf("------ CONGRATULATIONS! YOU GOT THE CODE! -----\n\n");
        }
        else
        {
            printf("------ NICE TRY! BUT THE CODE WAS %c %c %c %c -----\n\n",
                    nHPeg1, nHPeg2,
                    nHPeg3, nHPeg4);
            *pHPoints += 1;
        }
        system("pause");
        system("cls");
        nGame++;
    }
}


/*******************************************************************************
    Description:    This function displays the winner
         @param:    int nHPoints, nCPoints
        @return:    <None>
*******************************************************************************/
void showWinner(int nHPoints, int nCPoints)
{
    if (nHPoints < nCPoints)
    {
        printf(" __  _  _   ___ ___   _____  ___ __   __ _      \n");
        printf("|  \\| || | / _/| __| |_   _|| _ \\\\ `v' // \\ \n");
        printf("| | ' || || \\__| _|    | |  | v / `. .' \\_/   \n");
        printf("|_|\\__||_| \\__/|___|   |_|  |_|_\\  !_!  (_)  \n");
    }
    else if (nHPoints > nCPoints)
    {
        printf("__   __ __   _  _   _   _   __   __  _  _       \n");
        printf("\\ `v' //__\\ | || | | | | | /__\\ |  \\| |/ \\ \n");
        printf(" `. .'| \\/ || \\/ | | 'V' || \\/ || | ' |\\_/  \n");
        printf("  !_!  \\__/  \\__/  !_/ \\_! \\__/ |_|\\__|(_) \n");
    }
    else
    {
        printf(" __   ___   __   _   _  _  \n");
        printf("| _\\ | _ \\ /  \\ | | | |/ \\ \n");
        printf("| v || v /| /\\ || 'V' |\\_/ \n");
        printf("|__/ |_|_\\|_||_|!_/ \\_!(_) \n");
    }
}