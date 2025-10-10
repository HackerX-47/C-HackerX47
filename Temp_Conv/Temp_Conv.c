// This program converts the given temperature to Fahrenheit or Celcius as per given input
#include<stdio.h>

void instructions(void); // Function prototype for displaying instructions when called

int main(void){ // Function main starts

    float temperature=0; // Initializes variable temperature, which stores the numerical value of temperature user want to convert
    char unit='\0'; // Initializes variable unit, which stores the unit of temperature
    /* C - Celsius
       F - Fahrenheit
       E - End the program
       Any other - Wrong Input*/

    printf("---- Temperature Converter Program ----\n"); // Opening of program

    instructions(); // Calls the instructions function, displays the instructions of the program

    printf("Unit="); 
    scanf(" %c",&unit); // Inputs the unit of temperature for ex:- 60 C has unit C  

    while(unit!='E'){ // While condition executes till E not input

        printf("Tell me the numerical value of temperature = ");
        scanf("\n%f",&temperature); // Inputs the numerical value of temperature for ex:- -20 C has numerical value -20

        if(unit == 'C'){ // Tells the program that conversion as Celsius -> Fahrenheit

            printf("Converted Temperature\n%.2f %c\n",((9.00/5.00)*temperature)+32,'F'); // As we know (9/5)C=F-32

        }
        else{

            if(unit == 'F'){ // Tells the program that conversion as Fahrenheit -> Celsius

                printf("Converted Temperature\n%.2f %c\n",(temperature-32)*(5.00/9.00),'C'); // As we know (9/5)C=F-32

            }
            else{ // Assigned for units other than Celsius(C), Fahrenheit(F)

                printf("Wrong unit input.\nTry again\n"); // Displays that wrong input is given
                instructions(); // Displays the instructions to run the program

            }
        }

        printf("Unit=");
        scanf(" %c",&unit); // Inputs the unit of temperature for ex:- 60 C has unit C

    }

    printf("Program terminating ...\n"); // When user enters E , program termination statement

}

void instructions(void){ // Instructions function definition

    printf("\n\nInstructions:\n"); 
    printf("1. Input unit as C if you want to convert to Fahrenheit from Celsius\n"); // For conversion Celsius -> Fahrenheit
    printf("2. Input unit as F if you want to convert to Celsius from Fahrenheit\n"); // For conversion Fahrenheit -> Celsius
    printf("3. Input E for terminating the program\n\n"); // For terminating the program

}

// End of program