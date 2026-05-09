#include<stdio.h>
#include<stdlib.h>
//This problem when use #include<conio.h>
#define dash printf("--------------------------------------------------------------\n")
int main()
{
    system("clear");// Clear the console on MacOS
    int password=2026;
    int inpassword,chance=0;// Variable to store the input password and the number of chances used
    void welcome(),menu();// Function prototype
    welcome();// Call the welcome function
    do{
        printf("[%d]\n",chance+1);
        printf("Enter the password:");
        scanf("%d",&inpassword);
        chance++;
    }while(chance<3 && inpassword!=password);
    if(chance==3){
        printf("Password incorrect.\a\n");
        return 0;
    }
    else{
        menu();
    }
    return 0;
}

void welcome(){

    // Output the stars
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j < i; j++){
            printf("*");
        }
        for (int j = i; j > 0; j--){
            printf(" ");
        }
        printf("\n");
    }
    for (int i = 10; i < 20; i++){
        for (int j = 20; j > i; j--){
            printf(" ");
        }
        for (int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    dash;
    printf("\n");
    printf("This is a great place for me to practice C programming!\n");
    printf("Please follow the instructions.\n");
    printf("I hope you will like my program :) \n");
    printf("\n");
    dash;
    printf("You have 3 chances to enter the correct password.\n");
}

void menu(){
    system("clear");// Clear the console on MacOS
    void A(),B(),C();// Function prototype
    dash;
    printf("|                a. Draw a right triangle                    |\n");
    printf("|                b. Show multiplication table                |\n");
    printf("|                c. End                                      |\n");
    dash;
    char choice;
    int valid=1;
    while(valid==1){
        valid=0;
        printf("Enter your choice:");
        scanf(" %c",&choice);
        if(choice-'A'>=0 && choice-'C'<=0){// Convert uppercase(A-C) to lowercase
            choice=choice-'A'+'a';
        }
        switch(choice){
            case 'a':
                A();
                break;
            case 'b':
                B();
                break;
            case 'c':
            
                break;
            default:
                printf("Invalid choice.\n");
                valid=1;
        }
    }

    
    
}

void A(){
    system("clear");// Clear the console on MacOS
    char height;
    printf("Enter the one of a to n:");
    scanf(" %c",&height);
    while(height-'a'<0 || height-'n'>0){// Check if the input is valid
        printf("Your enter is wrong.Please enter the one of a to n:");
        scanf(" %c",&height);
    }
    for(int i=0;i<height-'a'+1;i++){
        for(int j=0;j<height-'a'-i;j++){
            printf(" ");
        }
        for(int j=i;j>=0;j--){
            printf("%c",height-j);
        }
        printf("\n");
    }
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu();
    
}
void B(){
    int n;
    printf("Please enter a number in 1 to 9:");
    scanf(" %d",&n);
    while(n<1 || n>9){// Check if the input is valid
        printf("Your enter is wrong.Please enter a number in 1 to 9:");
        scanf(" %d",&n);
    }
    printf("Multiplication Table:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%2d*%-2d=%2d ",j,i,i*j);
        }
        printf("\n");

    }
    
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu();
}
