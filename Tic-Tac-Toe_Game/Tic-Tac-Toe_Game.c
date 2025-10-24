/*
    Tic-Tac-Toe Game program - This program code is a menu driven system which lets two users to play a tic-tac-toe game.
    The first player has X and second player has O
    The players have to input from the options available from the tic-tac-toe game board and the one whose 3 symbols are in a line wins
    ( Rules are simple as of tic-tac-toe game )
*/

// Starting of program
#include<stdio.h>

// Functions prototypes 
void displayBoard ( char board [ 9 ] ) ; // displayBoard display the tic-tac-toe board with the available options written on it
int win ( int counter , char board [ 9 ] , int chosenValues [ 9 ] ) ; // win functions checks whether which player win after making move
int input ( int counter , char board [ 9 ] , int chosenValues [ 9 ] ) ; // input function has the task to input the given symbol of user in the board at the specified location from user
int subset ( int array1 [ 3 ] , int array2 [ 5 ] ) ; // subset function checks whether if array1 is subset of array2
void instructions ( ) ; // instructions function displays all the instructions of using the program on terminal

int main ( void ) // program running function main

{ // starting of main function body

    printf ( "--------- Tic-Tac-Toe Game ---------\n\n" ) ; // first line to be print on screen

    instructions ( ) ; // prints instructions

    int choice = 0 ; // initialize variable choice to store the value of choice inputted by user
    printf ( "Tell me choice\n? " ) ;
    scanf ( "\n%d" , &choice ) ; // inputs the choice

    while ( choice != 0 ) // loop to check whether users wants to play game multiple times or not
    
    {

        if ( choice == 1 ) // if statement to bottleneck the while loop condition to choice =1 for playing the game multiple times
        
        {

            int counter = 1 ; // initialize the counter variable which stores the value of how many moves till now have been placed in game
            char board [ 9 ] ; // defining a array which is the tic-tac-toe board
            int chosenValues [ 9 ] ; // defining a array which stores the position values already occupied by symbols

            for ( int i = 0 ; i < 9 ; i++ ) // for loop to initialize both the variable otherwise they will store garbage values
            
            {

                board [ i ] = ' ' ;        // empty board
                chosenValues [ i ] = 0 ;   // no moves yet

            }
            /*
                defines and initialize a variable wIn which stores the return value of win function
            */
            int wIn = win ( counter , board , chosenValues ) ; 
            displayBoard ( board ) ; // displays the empty tic - tac - toe board

            /*
                while loop checks whether the game does not exceed if a player 
                wins or if all the places are occupied
            */
            while ( counter <= 9 && wIn == 0 ) 
            
            { 
                /* 
                    define and initialize a variable position which stores the position value occupied by symbol,
                    simaltaneously call the function input
                */
                int position = input ( counter , board , chosenValues ) ; 
                chosenValues [ counter - 1 ] = position ;   // chosenValues aaray stores the value of user preferred position value                
                wIn = win ( counter , board , chosenValues ) ; // win function checks whether any user wins or not
                displayBoard ( board ) ;    // displayBoard function displays the tic-tac-toe board
                ++counter ;    // increment in the counter by 1

            }

            // after game completion 

            printf ( "Tell me choice\n? " ) ;
            scanf ( "\n%d" , &choice ) ;

        }

        else    // invalid choice opted by user
        
        {

            printf ( "Invalid Input for Choice,\nTry Again\n" ) ;

            printf ( "1. When prompted with \"Tell me choice?\":\n" ) ;
            printf ( "   - Enter 1 to start/play the game.\n" ) ;
            printf ( "   - Enter 0 to exit the program.\n" ) ;

            printf ( "Tell me choice\n? " ) ;
            scanf ( "\n%d" , &choice ) ;

        }

    }

}

// function definitions

void displayBoard ( char board [ 9 ] ) 

{

    printf ( "\n" ) ;  

    for ( int i = 0 ; i < 9 ; ++i )     // for loop to place the symbols and integers in the correct place
    
    {   
          
        if ( board [ i ] == 'X' || board [ i ] == 'O' )    // if occupied by any symbol
        
        {

            printf ( " %c " , board[i] ) ;  // print X or O

        } 
        
        else 
        
        {

            printf ( " %d " , i + 1 ) ;     // print cell number

        }

        if ( ( i + 1 ) % 3 == 0 ) // prints the | (columns)
        
        {

            goto e1 ;

        }

        printf ( "|" ) ; 
        
        e1 :

        if ( ( i + 1 ) % 3 == 0 && i != 8 ) // prints the --- (rows) 
        
        {

            printf ( "\n" ) ;             // new row after 3 cells
            printf ( "---+---+---" ) ;
            printf ( "\n" ) ; 

        }

    }

    printf ( "\n" ) ;             
    printf ( "\n" ) ;

}


int input ( int counter , char board [ 9 ] , int chosenValues [ 9 ] )

{

    int position = 0 ; // holds the position value of a cell of tic-tac-toe board
    int valid = 0 ; // holds the value 1 or 0 either valid input is given by user or not

    while ( ! valid ) // checks whether the input given by user is already occupied or not
    
    {

        printf ( ( counter % 2 ) ? "Player 1 chance\n? " : "Player 2 chance\n? " ) ; // checks which player chance it is now
        scanf ( "%d" , &position); // inputs the position in which symbol is to be placed
        if ( position < 1 || position > 9 )     // if case to sort out the case if user inputs a number not present in board 
        
        {

            printf ( "Invalid input, try again.\n" ) ;
            continue ;

        }

        valid = 1 ; // case for the valid iputs

        for ( int a = 0 ; a < counter-1 ; ++a ) // for loop to check whether the input isn't already occupied 
        
        {

            if ( chosenValues [ a ] == position ) // if case to check whether the position value ( input value ) isn't already present in chosenValues array
            
            {

                printf ( "Position already taken, try again.\n" ) ; 
                valid = 0 ;
                break ;

            }

        }

    }

    if ( counter % 2 == 1 ) // if statement to check which symbol to place in the position value or in simple language to identify which chance is it
    
    {

        board [ position - 1 ] = 'X' ; 

    }

    else
    
    {

        board [ position - 1 ] = 'O' ;
    
    }

    return position ;

}


int win ( int counter , char board [ 9 ] ,int chosenValues [ 9 ] ) 

{

    int x = 0 ; 
    int o = 0 ;

    int counterX [ 5 ] ; // define array counterX to store the position values occupied by symbol X 
    int counterO [ 5 ] ; // define array counterX to store the position values occupied by symbol X 

    for ( int i = 0 ; i < 5 ; ++i ) // initialize the two arrays so that it doesn't store any garbage value
    
    {

        counterX [ i ] = 0 ; 
        counterO [ i ] = 0 ; 

    }

    // arrays storing the position values one symbol needs to win the tic-tac-toe game
    int a [ 3 ] = { 1 , 2 , 3 } ; 
    int b [ 3 ] = { 4 , 5 , 6 } ;
    int c [ 3 ] = { 7 , 8 , 9 } ;
    int d [ 3 ] = { 1 , 4 , 7 } ;
    int e [ 3 ] = { 2 , 5 , 8 } ;
    int f [ 3 ] = { 3 , 6 , 9 } ;
    int g [ 3 ] = { 1 , 5 , 9 } ;
    int h [ 3 ] = { 3 , 5 , 7 } ;

    int position = 1 ; // define and intialize variable position to 1 to hold the position value of current move

    for ( position = 1 ; position <= 9 ; ++position ) // loop to input the position values of already occupied cells in their respective symbol counter array
    
    {

        if ( board [ position - 1 ] == 'X' )
        
        {

            counterX [ x ] = position ;
            ++x ;

        }

        if ( board [ position - 1 ] == 'O' )
        
        {

            counterO [ o ] = position ;
            ++o ;

        }

    }

    if ( subset ( a , counterX ) || subset ( b , counterX ) || subset ( c , counterX ) || subset ( d , counterX ) ||    
         subset ( e , counterX ) || subset ( f , counterX ) || subset ( g , counterX ) || subset ( h , counterX ) )     
        // if X has any of the array a-h as it's subset , X wins
    {

        printf ( "Player 1 Wins!\n" ) ;
        return 1 ;

    }

    else
    
    {
        if ( subset ( a , counterO ) || subset ( b , counterO ) || subset ( c , counterO ) || subset ( d , counterO ) ||
             subset ( e , counterO ) || subset ( f , counterO ) || subset ( g , counterO ) || subset ( h , counterO ) ) 
            // if Y has any of the array a-h as it's subset , Y wins
        {

            printf ( "Player 2 Wins!\n" ) ;
            return 1 ;

        }

        else
        
        {
            // if no one wins till the counter reaches 9, the game draws
            if ( counter == 9 ) printf ( "\nGame Draw.\n" ) ;
            // if no one wins till any counter <= 9 , win function return value is 9
            return 0 ;
        
        }

    }

}


int subset ( int array1 [ 3 ] , int array2 [ 5 ] )

{ // checks whether array1 is subset of array2 or not

    int counter = 0 ; // counter to store how many values of array1 match with array2
    int i = 0 ; 
    int j = 0 ;

    for ( i = 0 ; i < 3 ; ++i )
    
    {
        for ( j = 0 ; j < 5 ; ++j )
        
        {
            if ( array1 [ i ] == array2 [ j ] ) // checks whether any element of array1 matches with element of array2
            
            {

                ++counter ; // increment the counter by 1 if match found

            }

        }

    }

    if ( counter == 3 ) // if every element of array1 matches with any elements of array2 then we can say array1 is subset of array2
    
    {

        return 1 ; // returns 1 if array1 is subset of array2
    
    }
    
    else
    
    {

        return 0 ; // returns 0 is array1 is not subset of array2

    }

}


void instructions ( ) 

{

    printf ( "------ Instructions ------\n\n" ) ;
    printf ( "1. Tic-Tac-Toe is a two-player game.\n" ) ;
    printf ( "2. Player 1 uses 'X' and Player 2 uses 'O'.\n" ) ;
    printf ( "3. The board has 9 positions numbered 1 to 9 as follows:\n\n" ) ;

    printf ( "   1 | 2 | 3 \n" ) ;
    printf ( "  ---+---+---\n" ) ;
    printf ( "   4 | 5 | 6 \n" ) ;
    printf ( "  ---+---+---\n" ) ;
    printf ( "   7 | 8 | 9 \n\n" ) ;

    printf ( "4. Players take turns to place their symbol (X or O) in an empty cell.\n" ) ;
    printf ( "5. To place your symbol, type the number corresponding to the position.\n" ) ;
    printf ( "6. First player to align 3 of their symbols horizontally, vertically, or diagonally wins.\n" ) ;
    printf ( "7. If all positions are filled and no player has 3 in a row, the game is a draw.\n" ) ;
    printf ( "8. Invalid or already-taken positions will be rejected. Enter again safely.\n\n" ) ;

    printf ( "------ How to use this program ------\n" ) ;
    printf ( "1. When prompted with \"Tell me choice?\":\n" ) ;
    printf ( "   - Enter 1 to start/play the game.\n" ) ;
    printf ( "   - Enter 0 to exit the program.\n" ) ;
    printf ( "2. After the game ends, you will be prompted again for choice.\n" ) ;
    printf ( "3. Repeat steps above until you choose 0 to exit.\n\n" ) ;

    printf ( "------ Enjoy the game! ------\n\n" ) ;
    
}