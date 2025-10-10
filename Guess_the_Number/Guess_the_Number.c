// Welcome to guess the number game

#include<stdio.h> 
#include<stdlib.h> // for the functions rand() and srand()
#include<time.h> // for the function srand()

void instructions(void); // prototype for displaying instructions of the program

int main(void){ // starting of body

    int input_number = 0 ; // input number will be the number user will guess, input
    int program_number = 0 ; // program number will be the random generated number in the range (1,option)
    int option = 0 ; // option will be the maximum number upto which the rand() function will generate random number

    printf("---- Guess The Number ----\n"); // starting of the game

    srand(time(NULL)); // seeds the rand() function by the time, since time can't reverse, generated numbers will not follow a pattern  
    instructions(); // prints the instructions for using the program 

    printf("Tell me the option=\n? "); 
    scanf("\n%d",&option); // ask for the option

    while( option != 0 ){ // loop begins 

        if( option > 1 ){

            program_number = 1+rand()%(option) ; // program_number stores the random generated number in the range (1,option)

            for( int i = 1 ; i <=3 ; i += 1 ){ // another loop, give the user three trials to input correct answer

                printf("Trial %d:-\n",i); // for first trial , it prints trial 1
                printf("Guess the number\n"); 
                printf("? ");
                scanf("\n%d",&input_number); // asks the guess of user

                if( input_number <= option ){ // checks whether the user guess is not outside the range

                    if( input_number == program_number ){

                        printf("You made it in the trial %d.\nYou guessed the number right.\n",i);
                        break; // securely comes out of the for loop body 

                    }
                    else{

                        if( input_number > program_number ){ // tells whether the guessed number was greater than the generated number or not

                            printf("The guess was high.\n");

                        }

                        if( input_number < program_number ){ // tells whether the guessed number was lesser than the generated number or not

                            printf("The guess was low.\n");

                        }

                        if( i < 3 ){ // checks whether more trials are left or not
                            
                            printf("Try again\n"); // tells the user that you have more try left

                        }

                        if( i == 3 ){ // if no trials left then gives the following output

                            printf("You lose.\nTry again.\n"); // tells the user that he/she has lose, the program again asks option
                            break;

                        }
                    }
                }
                else{

                    printf("Input is outside the range.\n");

                    if( i < 3 ){ // checks whether more trials are left or not

                        printf("Try again\n"); // tells the user that you have more try left

                    }

                    if( i == 3 ){ // if no trials left then gives the following output

                        printf("You lose.\nTry again.\n"); // tells the user that he/she has lose, the program again asks option
                        break;

                    }
                }
             
            }
            

        } 
        if( option == 1 || option < 0 ){ // if the user made a wrong input such as 1,-1,-8 which are not valid in the program

            printf("You made a wrong input.\nTry again.\n");
            instructions();

        }

        printf("Tell me the option=\n? "); // loop continuation statement 
        scanf("\n%d",&option); // asks for the option

    }

    // option = 0

    printf("Program terminating ...\n"); // if option = 0 at any step , program terminates

} // end of main function

// functions definitions

void instructions(void) { // instructions tells the user how to use the program securely.

    printf("\nInstructions:\n");
    printf("1. Enter the maximum number (option).\n"); // option is the max value upto which random numbers will be generated
    printf("2. Try to guess the number between 1 and that number.\n"); // user has to guess the number and input it
    printf("3. Enter 0 to quit the game.\n"); // for quiting the game user has to input 0 in the option
    printf("4. 1 is not a valid input in this game.\n\n"); // since if option = 1, the guessed number will be always equal to generated number

    }