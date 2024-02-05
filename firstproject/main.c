#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char ListOfWords[9][255] = {"Film", "Moneky", "Paint", "Run", "Tiger", "Rough", "Car", "Pigeon", "Player", "Further"};
    char *pCharinput = (char *)malloc(sizeof(char));
    char *pWord = (char *)malloc(255*sizeof(char));
    char * UsedLetters = (char *)malloc(255 * sizeof(char));
    char *HiddenWord = (char *)malloc(strlen(pWord) * sizeof(char));
    int stillPlaying = 1;
    int stage = 1;

    while(stillPlaying){
    srand(time(0));
    int lives = 5;
    int finished = 0;

    do{
        printf("Are you ready to begin Y/N: ");
        scanf("%s", pCharinput);


        if(toupper(*pCharinput) == 'Y'){
        stage = 2;
        }else if(toupper (*pCharinput) == 'N'){
            printf("End");
            stillPlaying = 0;
            break;
        }else{
            scanf("%c", pCharinput);
        }
        close();
        }while(stage == 1);

        //STAGE 2
        while(stage == 2){

        pWord = ListOfWords[rand() % 9];
        strupr(pWord);
        //printf("%s, %d\n", pWord, strlen(pWord));

        int foundchars[strlen(HiddenWord)];
        int repeated = 0;

        for(int i = 0; i < strlen(pWord); i++){
            UsedLetters[i] = '\0';
        }



        for(int i = 0; i < strlen(pWord); i++){
            foundchars[i] = 0;
        }

        while(lives > 0 && finished == 0){


        for(int i = 0; i < strlen(pWord); i++){

            if(foundchars[i] == 1){
                HiddenWord[i] = pWord[i];
            }else{
                HiddenWord[i] = '_';
            }
        }

            HiddenWord[strlen(pWord)] = '\0';

            if(strcmp(pWord, HiddenWord) == 0){
                finished = 1;
            }

            printf("||You have %d lives remaning||:",lives);
            printf("%s", HiddenWord);
            printf("||\n");
            printf("You've used: ");


            for(int i = 0; i < strlen(UsedLetters);i++){
                printf("%c ",UsedLetters[i]);
            }

             printf("\n");
             repeated = 0;

             if(finished == 0){
             printf("Enter a new letter: ");
             scanf("%s", pCharinput);
             }



             for(int i = 1; i < strlen(pCharinput); i++){
                pCharinput[i] = '\0';
             }


            for(int i = 0; i < strlen(UsedLetters); i++){
                if(UsedLetters[i] == toupper(*pCharinput)){
                    repeated = 1;
                }

            }



            if(repeated == 0){

            UsedLetters[strlen(UsedLetters)] = toupper(*(pCharinput));
            UsedLetters[strlen(UsedLetters) + 1] = ' \0';

                if(strchr(pWord, toupper(*pCharinput)) == NULL){
                   lives--;
                }else{
                    for(int i = 0; i < strlen(pWord); i++){
                    if(pWord[i] == toupper(*(pCharinput))){
                    foundchars[i] = 1;
                }

            }
        }
            }else if(finished == 0){
            printf("Already used this letter\n");
            }

    }

        if(finished){
            stage = 3;
        }else if(!finished){
            stage = 0;
        }
        // STAGE 0
        if(stage == 0){
            printf("****************************************************\nTHE WORD WAS %s", pWord);
            printf(" YOU LOSE!!" , pWord);
        }

        if(stage == 3){
            printf("****************************************************\nTHE WORD WAS %s", pWord);
            printf(" YOU WIN");
        }

        printf("\nWant to play again Y to continue: ");
        scanf("%s", pCharinput);

        if(pCharinput[0] == 'Y' || pCharinput[0] == 'y'){
            printf("*******************************************\n\n");
            continue;
        }else{
            stillPlaying = 0;
            break;
     }
     close();
    }

    }
    return 0;
}








