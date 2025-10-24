#include<stdio.h>
// games starts with X then O
void displayBoard(char board[9]); // display a board 
int win(int counter,char board[9],int chosenValues[9]);
int input(int counter , char board[9], int chosenValues[9]);
int subset(int array1[3],int array2[5]);
int main(void){
    int choice=0;
    scanf("\n%d",&choice);
    while(choice!=0){
        int counter=1;
        char board[9];
        int chosenValues[9];
        for(int i = 0; i < 9; i++){
            board[i] = ' ';        // empty cell
            chosenValues[i] = 0;   // no moves yet
        }
        int wIn = win(counter,board,chosenValues);
        displayBoard(board);
        while(counter<=9 && wIn==0){ 
            int position = input(counter, board, chosenValues); // call once
            chosenValues[counter-1] = position;                // store in chosenValues
            wIn = win(counter, board, chosenValues);
            displayBoard(board);
            ++counter;
        }
        scanf("\n%d",&choice);
    }
}

void displayBoard(char board[9]) {
    printf("\n");             // new row after 3 cells
    printf("---------------");
    printf("\n");  
    for(int i = 0; i < 9; ++i) {
          
        if(board[i] == 'X' || board[i] == 'O') {
            printf("| %c |", board[i]);  // print X or O
        } else {
            printf("| %d |", i + 1);     // print cell number
        }

        if ((i + 1) % 3 == 0 && i!=8) {
            printf("\n");             // new row after 3 cells
            printf("----++---++----");
            printf("\n");  
        }
    }
    printf("\n");             // new row after 3 cells
    printf("---------------");
    printf("\n");
}


int input(int counter , char board[9], int chosenValues[9]){
    int i=0;
    int j=0;
    int position=0;
    int valid = 0;
    while(!valid) {
        scanf("%d", &position);
        if(position < 1 || position > 9) {
            printf("Invalid input, try again.\n");
            continue;
        }
        valid = 1;
        for(int a = 0; a < counter-1; ++a) {
            if(chosenValues[a] == position) {
                printf("Position already taken, try again.\n");
                valid = 0;
                break;
            }
        }
    }

    if(counter%2==1){
                board[position-1]='X';
            }
            else{
                board[position-1]='O';
            }
    return position;
}

int win(int counter , char board[9],int chosenValues[9]){
    int x=0;
    int o=0;
    int counterX[5];
    int counterO[5];
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    int c[3]={7,8,9};
    int d[3]={1,4,7};
    int e[3]={2,5,8};
    int f[3]={3,6,9};
    int g[3]={1,5,9};
    int h[3]={3,5,7};
    int position=0;
    for(position=0;position<9;++position){
        if(board[position]=='X'){
            counterX[x]=position;
            ++x;
        }
        if(board[position]=='O'){
            counterO[o]=position;
            ++o;
        }
    }
    if(subset(a,counterX)||subset(b,counterX)||subset(c,counterX)||subset(d,counterX)||subset(e,counterX)||subset(f,counterX)||
        subset(g,counterX)||subset(h,counterX)) {
            printf("X Wins!\n");
            return 1;
    }
    else{
        if(subset(a,counterO)||subset(b,counterO)||subset(c,counterO)||subset(d,counterO)||subset(e,counterO)||subset(f,counterO)||
        subset(g,counterO)||subset(h,counterO)) {
            printf("O Wins!\n");
            return 1;
        }
        else{
            if(counter==9) printf("\nGame Draw.\n");
            return 0;
        }
    }
}

int subset(int array1[3],int array2[5]){
    int counter=0;
    int i=0;
    int j=0;
    for(i=0;i<3;++i){
        for(j=0;j<5;++j){
            if(array1[i]==array2[j]){
                ++counter;
            }
        }
    }
    if(counter==3){
        return 1;
    }else{
        return 0;
    }
}