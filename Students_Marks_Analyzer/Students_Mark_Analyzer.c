// starting of program
#include<stdio.h> // included stdio.h to use standard input and output functions of C functions library
#include<string.h> // included string.h to use the specific function strncpy to copy string as array element

void instructions ( void ) ;

int main ( void ) { // starting of body of main function, void shows the main fuction returns nothing

    int i = 0 ; // will be used to toggle between rows ( students )
    int j = 0 ; // will be used to toggle between columns ( subjects )

    int choice = 0 ;
    int no_of_students = 0 ; // stores the value of number of students in a class given the specific test
    int no_of_subjects = 0 ; // stores the value of number of subjects as per curriculum of school
    double studentTotal = 0 ; // stores the sum of marks of all subjects scored by an individual student
    int fail = 0 ; // counter to verify that fail does not occurs twice while writing grade
    double classTotal = 0 ; // this variable stores the value of class total which will be further used to calculate class average
    int largestIndex = 0 ; // stores the index value of highest marks achieved by an individual student in a specific subject
    int lowestIndex = 0 ; // stores the index value of highest marks achieved by an individual student in a specific subject

    printf ( "---- Students Marks Analyzer ----" ) ; // starting line to be displayed on terminal screen, entering into program
    start:
        instructions () ;
        printf ( "Enter Your Choice (0 or 1) :- " ) ;
        scanf ( "\n%d" , &choice ) ;
        if ( choice == 1 ) {
            printf ( "\nNumber of students in class = " )  ; // asks about the number of students in class from user 
            scanf ( "%d" , &no_of_students ) ; // inputs the value and stores it in the address of variable no_of_students

            while ( no_of_students <= 0 ) { // loop and conditional statement used to verify whether the user doesn't input wrong details

                printf ( "Invalid Input, Try Again" ) ; // prints the statement Invalid Input and asks the user to input again , the correct number of students
                scanf ( "%d" , &no_of_students ) ; // inputs the value of number of students and stores it in place of old value of number of students
            }

            printf ( "Number of subjects = " ) ; // asks about the number of subjects as per school curriculum
            scanf ( "%d" , &no_of_subjects ) ; // inputs the value and stores it in the address of variable no_of_students

            while ( no_of_subjects<=0 ) { // loop and conditional statement used to verify whether the user doesn't input wrong details

                printf ( "Invalid Input, Try Again" ) ; // prints the statement Invalid Input and asks the user to input again , the correct number of students
                scanf ( "%d" , &no_of_subjects ) ; // inputs the value of number of students and stores it in place of old value of number of students

            }


            char name [ no_of_students ] [ 100 ] ; // initializes an array which will hold the names of students in the report
            int rollNumber [ no_of_students ] ; // initializes an array which will hold the roll number of students in the report
            double table [ no_of_students ] [ no_of_subjects ] ; // initializes a 2-D array which will hold the marks of each student in each exam 
            double studentTotalMarks [ no_of_students ] ; // initializes an array which will hold the sum of marks of students from all subjects
            double studentPercent [ no_of_students ] ; // initializes an array which will hold the percentage of marks of students from all subjects
            char result [ no_of_students ] [ 6 ] ; // initializes an array which will hold the result of each student whether he/she pass or failed
            char grade [ no_of_students ] ;  // initializes an array which will hold the grade of all students
            int highest [ no_of_subjects ] ; // initializes an array which will hold highest marks obtained by students in specific subject
            int lowest [ no_of_subjects ] ; // initializes an array which will hold lowest marks obtained by students in specific subject 
            int topperIndex[ no_of_students ]; // initializes an array which will hold the list of class toppers index values
            

            // nested loops for inputting the marks of all students in each subjects 

            for ( i = 0 ; i < no_of_students ; ++i ) { // this loop changes the student

                printf ( "Enter name of student :- " ) ;
                scanf ( "%99s" , name [ i ] ) ; // inputs name of student from user

                printf ( "Enter roll number of student :- " ) ;
                scanf ( "%d" , &rollNumber [ i ] ) ; // inputs roll number of student from user

                for ( j = 0 ; j < no_of_subjects ; ++j ) { // second loop ( nested one ) used to change the subject while remaining on same children

                    printf ( "Enter %s marks of subject %d :- " , name [ i ] , j+1 ) ; 
                    scanf ( "%lf" , &table [ i ] [ j ] ) ; // input marks of student in specific subject from user

                    while ( table [ i ] [ j ] < 0 || table [ i ] [ j ] > 100 ) { // third loop, for verification if the user dooesn' enters wrong input

                        printf ( "Invalid Input, Try Again" ) ;
                        scanf ( "%lf" , &table [ i ] [ j ] ) ; // inputs the correct marks from user after entering wrong one

                    }
                }

            }

            // nested loops for calculating the total, percentage of each student

            for ( i = 0 ; i < no_of_students ; ++i ) { // first loop changes the student

                for ( j = 0 ; j < no_of_subjects ; ++j ) { // second loop changes the subject

                    studentTotal += table [ i ] [ j ] ; // adds the marks scored by students to compute the total of each student

                }

                studentPercent [ i ] = ( studentTotal / ( no_of_subjects * 100 ) ) * 100 ; // used to calculate the percent marks of student
                studentTotalMarks [ i ] = studentTotal ; // stores the total marks of an student in array
                studentTotal = 0 ; // reinitializes the variable to zero so that it can be used to calculate the total marks of next student

            }

            // loops and nested if..else to store grade of each student

            for ( i = 0 ; i < no_of_students ; ++i ) { // loop which changes the student

                if ( studentPercent [ i ] >= 90) {  // if student scores above 90% , he/she will get X grade

                    grade [ i ] = 'X' ;

                }

                else {

                    if ( studentPercent [ i ] >= 80 && studentPercent [ i ] < 90 ) {

                        grade [ i ] = 'A' ; // if student scores above 80% , he/she will get A grade

                    }

                    else {


                        if ( studentPercent [ i ] >= 70 && studentPercent [ i ] < 80 ) {

                            grade [ i ] = 'B' ; // if student scores above 70% , he/she will get B grade

                        }

                        else {

                            if ( studentPercent [ i ] >= 60 && studentPercent [ i ] < 70 ) {

                                grade [ i ] = 'C' ; // if student scores above 60% , he/she will get C grade
                            
                            }

                            else {

                                if ( studentPercent [ i ] >= 50 && studentPercent [ i ] < 60 ) {

                                    grade [ i ] = 'D' ; // if student scores above 50% , he/she will get D grade

                                }
                                else {

                                    if ( studentPercent [ i ] >= 33.33 && studentPercent [ i ] < 50 ) {

                                        grade [ i ] = 'E' ; // if student scores above  33.33% , he/she will get E grade

                                    }
                                    else {

                                        if (studentPercent [ i ] >= 0 && studentPercent [ i ] < 33.33 ) {

                                            grade [ i ] = 'F' ; // student gets F grade if he/she fails in the examination

                                        }

                                    }

                                }

                            }

                        }

                    }

                }   

            }

            // nested loops pass or fail deciding program

            
            for ( i = 0 ; i < no_of_students ; ++i ) { // first loop changes the student

                fail = 0 ; 

                for ( j = 0 ; j < no_of_subjects ; ++j ) { // second loop changes the subject 

                    if ( table [ i ] [ j ] < 33.33 ) { // if marks stored by student in any subject is less than 33.33 he/she get fail in the following subject

                        strcpy ( result[ i ] , "FAIL" ) ;
                        fail = 1 ;

                    }

                }

                if ( studentPercent [ i ] < 33.33 ) {

                    strcpy ( result[ i ] , "FAIL" ) ; // if marks stored by student in total is less than 33.33 he/she get fail in the exams
                    if ( fail == 0 ) {

                        fail = 1 ;

                    }

                }

                if( !fail ) {

                    strcpy ( result[ i ] , "PASS" ) ; // if students doesn't fills in any of the above criterion then it means he/she has passed the exam
                
                }

            }

            // class total and average calculating program 

            for ( i = 0 ; i < no_of_students ; ++i ) { // first loop changes the student

                for ( j = 0 ; j < no_of_subjects ; ++j ) { // second loop changes the subject 

                    classTotal += table[ i ][ j ] ; // variable classTotal sums up all merks of all the students in all subjects to figure out classAvg

                }

            }

            double classAvg = ( classTotal ) / ( no_of_students*no_of_subjects ) ; // formula for computing class average and stores it in variable classAvg

            // program to find the subject wise largest marks obtained by a student

            for ( j = 0 ; j < no_of_subjects ; ++j ) { // first loop here changes the subject

                largestIndex = 0 ;

                for ( i = 1 ; i < no_of_students ; ++i ) { // second loop changes the student 

                    if ( table [ i ] [ j ] > table [ largestIndex ] [ j ] ) { // conditional statement if checks wheher the next student got higher marks or not in same subject

                        largestIndex = i ; // if yes, the largestIndex variable stores the index value of that student

                    }

                }

                highest [ j ] = largestIndex ; // the array stores the index of students who scored the maximum marks in each subject

            }

            // program to find the subject wise lowest marks obtained by a student

            for ( j = 0 ; j < no_of_subjects ; ++j ) { // first loop here changes the subject

                lowestIndex = 0 ;

                for ( i = 1 ; i < no_of_students ; ++i ) { // second loop changes the student

                    if ( table [ i ] [ j ] < table [ lowestIndex ] [ j ] ) { // conditional statement if checks wheher the next student got lower marks or not in same subject

                        lowestIndex = i ; // if yes, the lowestIndex variable stores the index value of that student

                    }

                }

                lowest [ j ] = lowestIndex ;  // the array stores the index of students who scored the minimum marks in each subject

            }

            // program to get the index value of class topper ( the student who scored maximum percentage in exam )

            int topperIndexValue = 0 ; // the variable stores the value of index of topper

            int t=0;
            for ( i = 1 ; i < no_of_students ; ++i ) { // first loop to change the student

                if ( studentPercent [ i ] >= studentPercent [ topperIndexValue ] ) { // checks whether the next student has scored a more percentage or not
                    topperIndexValue=i;  // if yes, the variable topperIndexValue stores the value of it
                } 
            }

            topperIndex [ t ] = topperIndexValue ; // now the array topperIndex first input is the index of first topper
            int highestMarks = studentPercent[topperIndex[0]];

            // program to check whether there is one or many toppers, stores index value acordingly 

            int topperCount = 0;
            topperIndex[topperCount++] = topperIndexValue;

            for (i = 0; i < no_of_students; ++i) {

                if ( i != topperIndexValue && studentPercent [ i ] == highestMarks) {

                    topperIndex [ topperCount ++ ] = i;

                }

            }


            // program to print the report of marks  

            printf ( "\n\n%-24s%-12s" , "Name" , "Roll Number" ) ; 

            for ( j = 0 ; j < no_of_subjects ; ++j ) { // loop to print subject1, subject2, ..etc

                printf ( "%-12s%-3d " , "Subject" , j+1 ) ; 

            }

            printf ( "%-13s%-10s%-7s%-7s" , "Total Marks" , "Percent" , "Result" , "Grade" ) ; // loop to print other column names

            for ( i = 0 ; i < no_of_students ; ++i ) { // loop to print each student data

                printf ( "%-24s" , name [ i ] ) ; // to print name of student
                printf ( "%-12d" , rollNumber [ i ] ) ; // to print roll number of each student

                for ( j = 0 ; j < no_of_subjects ; ++j ) { // loop to print marks of each student in every subject

                    printf ( "%-13.2f" , table [ i ] [ j ] ) ;

                }

                printf ( "%-13.2f%-10.2f%-7s%-7c" , studentTotalMarks [ i ] , studentPercent [ i ] , result [ i ] , grade [ i ] ) ; // to print student total marks, percentage, grade, result 
                printf ( "\n" ) ; // to change the row such that it can print another student data

            }

            printf ( "\n\n\n%-36s" , "Highest :- " ) ; // to print highest marks obtained by students in specific subject

            for ( j = 0 ; j < no_of_subjects ; ++j ) { // first loop to change the subject

                printf ( "%-12.2f" , table [ highest [ j ] ] [ j ] ) ; // prints the highest marks obtained in the specific subject

            }

            printf ( "\n%-36s","Lowest :- " ) ; // to print lowest marks obtained by students in specific subject

            for ( j = 0 ; j < no_of_subjects ; ++j ) { // first loop to change the subject

                printf ( "%-12.2f" , table [ lowest [ j ] ] [ j ] ) ; // prints the lowest marks obtained in the specific subject

            }

            printf ( " \n\nClass Average = %.2f " , classAvg ) ; // print the class average

            for ( int t = 0 ; t < topperCount ; ++t ){ // loop to print the list of class toppers 
                printf ( "Class topper :- %s %.2f%% \n" , name [ topperIndex[t] ] , studentPercent [ topperIndex[t] ] ) ; 
            }
        }

        else {

            if ( choice == 0 ) {

                printf ( "\nProgram Terminating ..." ) ;
                return 0;

            }

            else {

                printf ( "Invalid Input, Try Again" ) ; 
                goto start;
            }

        }
    
}

// Function to display instructions to the user
void instructions(void) {
    printf("==============================================\n");
    printf("Welcome to the Student Marks Analyzer Program!\n\n");
    
    printf("Follow the steps below to use this program:\n");
    printf("1. Enter the number of students in the class.\n");
    printf("   ➤ Only positive integer values are allowed.\n\n");
    
    printf("2. Enter the number of subjects in your curriculum.\n");
    printf("   ➤ Only positive integer values are allowed.\n\n");
    
    printf("3. For each student:\n");
    printf("   ➤ Enter the student's name (without spaces).\n");
    printf("   ➤ Enter the student's roll number (numeric only).\n");
    printf("   ➤ Enter marks for each subject (from 0 to 100).\n\n");

    printf("4. Once all data is entered, the program will:\n");
    printf("   ➤ Calculate total and percentage for each student.\n");
    printf("   ➤ Assign grades (X, A, B, C, D, E, F) based on percentage.\n");
    printf("   ➤ Determine pass/fail status for each student.\n");
    printf("   ➤ Identify highest and lowest marks in each subject.\n");
    printf("   ➤ Display class average and list of toppers.\n\n");

    printf("5. The final report will show:\n");
    printf("   ➤ Each student's marks, total, percentage, result, and grade.\n");
    printf("   ➤ Subject-wise highest and lowest marks.\n");
    printf("   ➤ Class average and topper details.\n\n");

    printf("Note:\n");
    printf("• Marks must be between 0 and 100 (inclusive).\n");
    printf("• Failing in even one subject marks the student as FAIL.\n");
    printf("• If two or more students have the same highest percentage,\n");
    printf("  all of them are declared class toppers.\n");

    printf("==============================================\n");
    printf("Press ENTER to continue...\n");
    while (getchar() != '\n'); // clear leftover input
    printf("Press ENTER to continue...");
    getchar(); // wait for Enter key

    printf("==============================================\n\n");
}