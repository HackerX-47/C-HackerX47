// Starting of Program "Matrix Calculator"
#include<stdio.h>

void instructions ( void ) ; // instructions function prototype, which shows the instructions to use the program
void inputMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] ) ; // inputMatrix function prototype, which inputs the data from user to matrix
void displayMatrix ( int rows , int columns , double matrix [ rows ] [ columns ]  ) ; // displayMatrix function prototype, which prints the matrix
void addMatrix ( int rows , int columns , double matrix1 [ rows ] [ columns ] , double matrix2 [ rows ] [ columns ] ) ; // addMatrix function prototype, which adds two matrices and display the resultant matrix
void subtractMatrix ( int rows , int columns , double matrix1 [ rows ] [ columns ] , double matrix2 [ rows ] [ columns ] ) ; // subtractMatrix function prototype, which subtract two matrices and display the resultant matrix
void multiplicationMatrix ( int a , int b , int c , double matrix1 [ a ] [ b ] , double matrix2 [ b ] [ c ] ) ; // multiplicationMatrix function prototype, which multiplies two matrices and display the resultant matrix
void transposeMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] ) ; // transposeMatrix function prototype, which takes the matrix, and prints the transpose of the matrix
double determinant ( int rows , int columns , double matrix [ rows ] [ columns ] ) ; // determinant function prototype, which takes the matrix, and prints the determinant of matrix
void inverseMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] ) ; // inverseMatrix function prototype, which takes the matrix, and prints the inverse of matrix

int main ( void ) { // starting of main function body

    int row_1 = 0 ; // inititalize variable row_1 for 2 matrix calculations 
    int row_2 = 0 ; // inititalize variable row_2 for 2 matrix calculations

    int column_1 = 0 ; // inititalize variable column_1 for 2 matrix calculations
    int column_2 = 0 ; // inititalize variable column_1 for 2 matrix calculations

    int row = 0 ; // initialize variable row for 1 matrix calculations
    int column = 0 ; // initialize variable column for 1 matrix calculations

    int choice = 0 ; // initialize variable choice for menu driven system

    wrong_choice : 

        instructions ( ) ; // prints instructions for using the program
        scanf ( "\n%d" , &choice ) ; // scans the choice, for using the menu driven system of program

        switch ( choice ) // switch case statement
        
        {  

            case 1 : // Addition of Two matrices

                {

                    printf ( "\n\n-- Addition of two matrices --\n\n" ) ;

                    printf ( "Enter number of rows in first matrix = " ) ;
                    scanf ( "\n%d" , &row_1 ) ;
                    printf ( "Enter number of columns in first matrix = " ) ;
                    scanf ( "\n%d" , &column_1 ) ;

                    printf ( "Enter number of rows in second matrix = " ) ;
                    scanf ( "\n%d" , &row_2 ) ;
                    printf ( "Enter number of columns in second matrix = " ) ;
                    scanf ( "\n%d" , &column_2 ) ;

                    while ( row_1 != row_2 || column_1 != column_2 )
                    
                    { 

                        // for using addition of 2 matrices, number of rows and columns should be equal in 2 matrices

                        printf ( "\nWrong Inputs\n" ) ;

                        printf ( "Enter number of rows in first matrix = " ) ;
                        scanf ( "\n%d" , &row_1 ) ;
                        printf ( "Enter number of columns in first matrix = " ) ;
                        scanf ( "\n%d" , &column_1 ) ;

                        printf ( "Enter number of rows in second matrix = " ) ;
                        scanf (  "\n%d" , &row_2 ) ;
                        printf ( "Enter number of columns in second matrix = " ) ;
                        scanf ( "\n%d" , &column_2 ) ;

                    }

                    double matrix1 [ row_1 ] [ column_1 ] ; // initialize a 2-D Array to store data of matrix 1 
                    double matrix2 [ row_2 ] [ column_2 ] ; // initialize a 2-D Array to store data of matrix 2

                    inputMatrix ( row_1 , column_1 , matrix1 ) ; 
                    inputMatrix ( row_2 , column_2 , matrix2 ) ;

                    addMatrix ( row_1 , column_1 , matrix1 , matrix2 ) ;

                    printf ( "\nOperation completed successfully.\n\n " ) ;

                    break ;

                }
            
            case 2 : // subtraction of two matrices

                {

                    printf ( "\n\n-- Subtraction of two matrices --\n" ) ;

                    printf ( "Enter number of rows in first matrix = " ) ;
                    scanf ( "\n%d" , &row_1 ) ;
                    printf ( "Enter number of columns in first matrix = " ) ;
                    scanf ( "\n%d" , &column_1 ) ;

                    printf ( "Enter number of rows in second matrix = " ) ;
                    scanf ( "\n%d" , &row_2 ) ;
                    printf ( "Enter number of columns in second matrix = " ) ;
                    scanf ( "\n%d" , &column_2 ) ;

                    while ( row_1 != row_2 || column_1 != column_2 )
                    
                    {
                        // for using subtraction of 2 matrices, number of rows and columns should be equal in 2 matrices

                        printf ( "\nWrong Inputs\n" ) ;

                        printf ( "Enter number of rows in first matrix = " ) ;
                        scanf ( "\n%d" , &row_1 ) ;
                        printf ( "Enter number of columns in first matrix = " ) ;
                        scanf ( "\n%d" , &column_1 ) ;

                        printf ( "Enter number of rows in second matrix = " ) ;
                        scanf ( "\n%d" , &row_2 ) ;
                        printf ( "Enter number of columns in second matrix = " ) ;
                        scanf ( "\n%d" , &column_2 ) ;

                    }

                    double matrix1 [ row_1 ] [ column_1 ] ; // initialize a 2-D Array to store data of matrix 1 
                    double matrix2 [ row_2 ] [ column_2 ] ; // initialize a 2-D Array to store data of matrix 2

                    inputMatrix ( row_1 , column_1 , matrix1 ) ;
                    inputMatrix ( row_2 , column_2 , matrix2 ) ;

                    subtractMatrix ( row_1 , column_1 , matrix1 , matrix2 ) ;
                    
                    printf ( "\nOperation completed successfully.\n\n" ) ;

                    break ;

                }

            case 3 : // multiplication of two matrices

                {

                    printf ( "\n\n-- Multiplication of two matrices --\n\n" ) ;

                    printf ( "Enter number of rows in first matrix = " ) ;
                    scanf ( "\n%d" , &row_1 ) ;
                    printf ( "Enter number of columns in first matrix = " ) ;
                    scanf ( "\n%d" , &column_1 ) ;

                    printf ( "Enter number of rows in second matrix = " ) ;
                    scanf ( "\n%d" , &row_2 ) ;
                    printf ( "Enter number of columns in second matrix = " ) ;
                    scanf ( "\n%d" , &column_2 ) ;

                    while ( column_1 != row_2 )
                    
                    {

                        // for using multiplication of 2 matrices, number of columns of 1st matrix and rows of 2nd matrix should be equal

                        printf ( "\nWrong Inputs\n" ) ;

                        printf ( "Enter number of columns in first matrix = " ) ;
                        scanf ( "\n%d" , &column_1 ) ;
                        printf ( "Enter number of rows in second matrix = " ) ;
                        scanf ( "\n%d" , &row_2 ) ;

                    }

                    double matrix1 [ row_1 ] [ column_1 ] ; // initialize a 2-D Array to store data of matrix 1
                    double matrix2 [ row_2 ] [ column_2 ] ; // initialize a 2-D Array to store data of matrix 2

                    inputMatrix ( row_1 , column_1 , matrix1 ) ;
                    inputMatrix ( row_2 , column_2 , matrix2 ) ;

                    multiplicationMatrix ( row_1 , column_1 , column_2 , matrix1 , matrix2 ) ;

                    printf ( "\nOperation completed successfully.\n\n" ) ;

                    break ;

                }

            case 4 : // transpose of a matrix

                {

                    printf ( "\n\n-- Transpose of matrix --\n\n" ) ;

                    printf ( "Enter number of rows in matrix = " ) ;
                    scanf ( "\n%d" , &row ) ;
                    printf ( "Enter number of columns in matrix = " ) ;
                    scanf ( "\n%d" , &column ) ;

                    double matrix [ row ] [ column ] ; // initialize a 2-D array to store data of matrix

                    inputMatrix ( row , column , matrix ) ;

                    transposeMatrix ( row , column , matrix ) ;

                    printf ( "\nOperation completed successfully.\n\n" ) ;

                    break ;

                }

            case 5 : // determinant of a matrix

                {

                    printf ( "\n\n-- Determinant of matrix --\n\n" ) ;

                    printf ( "Enter number of rows in matrix = " ) ;
                    scanf ( "\n%d" , &row ) ;
                    printf ( "Enter number of columns in matrix = " ) ;
                    scanf ( "\n%d" , &column ) ;

                    double matrix [ row ] [ column ] ; // initialize a 2-D array to store data of matrix

                    while ( column != row )
                    
                    {

                        // for finding determinant, the given matrix should be a square matrix

                        printf ( "Enter number of rows in matrix = " ) ;
                        scanf ( "\n%d" , &row ) ;
                        printf ( "Enter number of columns in matrix = " ) ;
                        scanf ( "\n%d" , &column ) ;

                    }

                    inputMatrix ( row , column , matrix ) ;

                    printf ( "\nDeterminant = %.2f" , determinant ( row , column , matrix ) ) ;

                    printf ( "\nOperation completed successfully.\n\n" ) ;

                    break ; 

                }   

            case 6 : // inverse of a matrix

                {

                    printf ( "\n\n-- Inverse of matrix --\n\n" ) ;

                    printf ( "Enter number of rows in matrix = " ) ;
                    scanf ( "\n%d" , &row ) ;
                    printf ( "Enter number of columns in matrix = " ) ;
                    scanf ( "\n%d" , &column ) ;

                    double matrix [ row ] [ column ] ; // initialize a 2-D array to store data of matrix

                    inputMatrix ( row , column , matrix ) ;

                    inverseMatrix ( row , column , matrix ) ;

                    printf ( "\nOperation completed successfully.\n\n" ) ;

                    break ;

                }

            case 0 :

                {   

                    printf ( "Program terminating ...\n" ) ;
                    break ;

                }

            default : 

                {
                    
                    printf ( "Invalid choice, Try again\n" ) ;
                    goto wrong_choice ;

                }

        }

}

void instructions ( void ) 

{

    printf ( "====================================\n" ) ;
    printf ( "        MATRIX CALCULATOR\n" ) ; 
    printf ( "====================================\n\n" ) ;
    printf ( " This program performs various matrix operations such as addition,\n" ) ;
    printf ( "subtraction , multiplication , transpose , and more.\n\n" ) ;

    printf ( "Available Operations:\n" ) ;
    printf ( "1. Addition of two matrices\n" ) ;
    printf ( "2. Subtraction of two matrices\n" ) ;
    printf ( "3. Multiplication of two matrices\n" ) ;
    printf ( "4. Transpose of a matrix\n" ) ;
    printf ( "5. Determinant of a matrix\n" ) ;
    printf ( "6. Inverse of a matrix\n" ) ;
    printf ( "0. Exit\n\n" ) ;

    printf ( "Input Format:\n" ) ;
    printf ( "- First, enter the number of rows and columns for each matrix.\n" ) ;
    printf ( "- For addition and subtraction, both matrices must have the same dimensions.\n" ) ;
    printf ( "- For multiplication, columns of first matrix = rows of second matrix.\n" ) ;
    printf ( "- Enter each element row by row.\n\n" ) ;

    printf ( "Notes:\n" ) ;
    printf ( "- Enter only integer values.\n" ) ;
    printf ( "- Choose operation numbers carefully (1–7).\n\n" ) ;

    printf ( "------------------------------------\n" ) ;
    printf ( "Enter your choice to begin: " ) ;

}

void inputMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] )

{

    printf ( "\n\n" ) ;

    for ( int i = 0 ; i < rows ; ++i )
    
    {

        for ( int j = 0 ; j < columns ; ++j )
        
        {

            printf ( "a[%d][%d] = " , i , j ) ;
            scanf ( "%lf" , &matrix [ i ] [ j ] ) ;

            printf ( "\n" ) ;

        }

    }

    displayMatrix ( rows , columns , matrix ) ;

}

void displayMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] )

{

    printf ( "\n\n" ) ;

    for ( int i = 0 ; i < rows ; ++i ) 
    
    {
        
        printf ( "\n| " ) ;

        for ( int j = 0 ; j < columns ; ++j )
        
        {

            printf ( "%.2f ", matrix [ i ] [ j ] ) ;

        }

        printf ( "| \n" ) ;

    }

    printf ( "\n" ) ;

}

void addMatrix ( int rows , int columns , double matrix1 [ rows ] [ columns ] ,double matrix2 [ rows ] [ columns ] )

{

    double sumMatrix [ rows ] [ columns ] ;
    printf ( "\n\n" ) ;

    for ( int i = 0 ; i < rows ; ++i )
    
    {

        for ( int j = 0 ; j < columns ; ++j ) 
            
        {

            sumMatrix [ i ] [ j ] = matrix1 [ i ] [ j ] + matrix2 [ i ] [ j ] ; 

        }

    }

    printf ( "Output :-" ) ;
    displayMatrix ( rows , columns , sumMatrix ) ;

}

void subtractMatrix ( int rows , int columns , double matrix1 [ rows ] [ columns ] ,double matrix2 [ rows ] [ columns ] )

{

    double subtractMatrix [ rows ] [ columns ] ;
    printf ( "\n\n" ) ;

    for ( int i = 0 ; i < rows ; ++i ) 

    {

        for ( int j = 0 ; j < columns ; ++j ) 

        {

            subtractMatrix [ i ] [ j ] = matrix1 [ i ] [ j ] - matrix2 [ i ] [ j ] ; 

        }

    }

    printf ( "Output :-" ) ;
    displayMatrix ( rows , columns , subtractMatrix ) ;

}

void transposeMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] ) 

{

    double transposeMatrix [ columns ] [ rows ] ;
    printf ( "\n\n" ) ;
    for ( int i = 0 ; i < rows ; ++i )
    
    {

        for ( int j = 0 ; j < columns ; ++j )
        
        {

            transposeMatrix [ j ] [ i ] = matrix [ i ] [ j ] ;

        }

    }

    printf ( "Output :-" ) ;
    displayMatrix ( columns , rows , transposeMatrix ) ;

}

void multiplicationMatrix ( int a , int b , int c , double matrix1 [ a ] [ b ] , double matrix2 [ b ] [ c ] ) 

{

    double multiplicationMatrix [ a ] [ c ] ;
    printf ( "\n\n" ) ;

    for ( int x = 0 ; x < a ; ++x )
    
    {

        for ( int z = 0 ; z < c ; ++z ) 
        
        {

            double total = 0 ;

            for ( int y = 0 ; y < b ; ++y )
            
            {

                total += ( matrix1 [ x ] [ y ] ) * ( matrix2 [ y ] [ z ] ) ;

            }

            multiplicationMatrix [ x ] [ z ] = total ;

        }

    }

    printf ( "Output :-" ) ;
    displayMatrix ( a , c , multiplicationMatrix ) ;

}

double determinant ( int rows , int columns , double matrix [ rows ] [ columns ] )

{
    
    int n = rows ;

    // Base case: 1x1 matrix
    if ( n == 1 ) 
    
    {

        return matrix [ 0 ] [ 0 ] ;

    }

    // Base case: 2x2 matrix
    if ( n == 2 ) 
    
    {

        return matrix [ 0 ] [ 0 ] * matrix [ 1 ] [ 1 ] - matrix [ 0 ] [ 1 ] * matrix [ 1 ] [ 0 ] ;

    }

    double det = 0;

    for ( int j = 0 ; j < n ; j++ ) 
    
    {

        // Create submatrix excluding row 0 and column j
        double subMatrix [ n - 1 ] [ n - 1 ] ;
        int subi = 0 ;
        for ( int i = 1 ; i < n ; i++ ) 
        
        {

            int subj = 0 ;
            for ( int k = 0 ; k < n ; k++ ) 
            
            {

                if ( k == j ) continue ;

                subMatrix [ subi ] [ subj ] = matrix [ i ] [ k ] ;
                subj++ ;

            }

            subi++ ;

        }

        int sign = ( j % 2 == 0 ) ? 1 : -1 ;

        det += sign * matrix [ 0 ] [ j ]  * determinant ( n - 1 , n - 1 , subMatrix ) ;

    }

    return det ;

}

void inverseMatrix ( int rows , int columns , double matrix [ rows ] [ columns ] )

{
    
    printf ( "\n\n" ) ;
    
    if ( rows != columns ) 
    
    {

        printf ( "Inverse not defined for non-square matrices.\n" ) ;
        return ;

    }

    int n = rows ;
    double det = determinant ( n , n , matrix ) ;

    if ( det == 0 ) 
    
    {

        printf ( "Matrix is singular, inverse does not exist.\n" ) ;
        return ;

    }

    // Create adjoint matrix internally
    double adj [ n ] [ n ] ;

    for ( int i = 0 ; i < n ; i++ ) 
    
    {

        for ( int j = 0 ; j < n ; j++ ) 
        
        {

            // Create submatrix excluding row i and column j
            double subMatrix [ n - 1 ] [ n - 1 ] ;

            int subi = 0 ;

            for ( int r = 0 ; r < n ; r++ ) 
            
            {

                if ( r == i ) continue;

                int subj = 0;
                for ( int c = 0 ; c < n ; c++ ) 
                
                {

                    if ( c == j ) continue ;
                    subMatrix [ subi ] [ subj++ ] = matrix [ r ] [ c ] ;

                }

                subi++ ;

            }

            int sign = ( ( i + j ) % 2 == 0) ? 1 : -1 ;

            // Fill adjoint (transpose while assigning)
            adj [ j ] [ i ] = sign * determinant ( n - 1 , n - 1 , subMatrix ) ; 

        }

    }

    double inv [ n ] [ n ] ;

    for ( int i = 0 ; i < n ; i++ ) 
    
    {

        for ( int j = 0 ; j < n ; j++ ) 
        
        {

            inv [ i ] [ j ] = adj [ i ] [ j ] / det ;

        }

    }

    printf ( "Output :-" ) ;
    displayMatrix ( n , n , inv ) ;

}