#include<stdio.h>

void instructions(void);

int main(void){ 
    
    //Starting of the program

    printf("---- Simple Calculator ----\n\n");
    printf("Welcome to the simple calculator program.\n");
    printf("By this program you can use the basic calculation operators such as\n");
    printf("Addition Operator\nSubstraction Operator\nMultiplication Operator\nDivision Operator\nModulo Operator\n");

    //Initializing variables 

    double number1 = 0;
    double number2 = 0;
    int option = 0;
    
    //Telling the instructions for using the calculator

    instructions();
    
    // Asking the operator which user want to use 

    scanf("\n%d",&option);
    if(option != 0){

    // Asking the user the input for variables

    printf("1st Number = ");
    scanf("\n%lf",&number1);  // Inputting first number.
    printf("2nd Number = ");  
    scanf("\n%lf",&number2);  // Inputting second number

    }
    
    // Loop statement which ensures that program continues till user optes Zero

    while(option != 0){

        // Switch statement which tells the program which operator to use for given input
    
        switch(option){
            
            // Option = 1
            // Addition

            case 1:

            printf("%s\n","You have opted for addition of the two numbers.");
            printf("%.2lf + %.2lf = %.2lf\n",number1,number2,( number1 + number2 ));
    
            break;

            // Option = 2
            // Subtraction

            case 2:

            printf("%s\n","You have opted for subtraction of the two numbers.");
            printf("%.2lf - %.2lf = %.2lf\n",number1,number2,( number1 - number2 ));

            break;

            // Option = 3
            // Multiplication

            case 3:

            printf("%s\n","You have opted for multiplication of the two numbers.");
            printf("%.2lf * %.2lf = %.2lf\n",number1,number2,( number1 * number2 ));

            break;

            // Option = 4
            // Division

            case 4:

            if( number2 != 0 ){ // Checks whether the given divisor i.e., number2 variable value is non-zero or not 
                printf("%s\n","You have opted for division of the two numbers.");
                printf("%.2lf / %.2lf = %.2lf\n",number1,number2,( number1 / number2 ));
            }
            else{ // If number2 variable value is 0 then program shows wrong input 
                printf("Wrong Input\nUse a non-zero number for the place of divisor\n");
            }

            break;

            // Option = 5
            // Modulo Operator

            case 5:

            if( number2 != 0 ){ // Checks whether the given number2 variable value is non-zero or not
                if(number1 == (int)number1 && number2 == (int)number2 ){ // Checks whether the given inputs are integers or not
                printf("%s\n","You have opted for remainder of the two numbers.\n");
                printf("%d %% %d = %d\n",(int)number1,(int)number2,( (int)number1 % (int)number2 ));
                }
                else{  // Program shows wrong input if the given two variables values are not integers
                    printf("Wrong input.\nUse integral inputs for use of modulus operator.\n");
                }
            }
            else{ // Program shows that user has entered wrong input for variable number2
                printf("Wrong Input for Second number\n");
            }
        
            break;

            // Option = 0
            // Program termination

            case 0:
            printf("%s","You opted for end of the program.\n");

            break;

            // Default (If no option matches)
            // Shows input for option since all the six cases (+,-,*,/,%,End) are covered above

            default:
            printf("Wrong Input for option.\n");
            instructions();  // Again shows the instruction to user for choosing the correct option
        
        }

        // Loop continuation condition
        // Asks for option if previous option was not zero

        if( option != 0 ){
            printf("? ");
            scanf("\n%d",&option);

            // Now checks the new option and then ask for variables if new option is no equal to zero

            if( option != 0 ){
                printf("1st Number = ");
                scanf("\n%lf",&number1);
                printf("2nd Number = ");
                scanf("\n%lf",&number2);
            }
        }

    } 

    printf("%s","You opted for end of the program.\n");   
}



void instructions(void){
    printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
        "Following are the instructions to follow for using the simple calculator.",
        "  1. Input 1 for using addition operator.",
        "  2. Input 2 for using substraction operator.",
        "  3. Input 3 for using multiplication operator.",
        "  4. Input 4 for using division operator.",
        "  5. Input 5 for using remainder operator.",
        "  6. Input 0 for terminating the program."
    );
}
    
