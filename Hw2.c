#include<stdio.h>
#include<stdlib.h>
#define dash printf("--------------------------------------------------------------\n")
int main()
{
    int password=2026;
    int inpassword,chance=0;// Variable to store the input password and the number of chances used
    void welcome();// Function prototype
    welcome();// Call the welcome function
    do{
        printf("Enter the password:");
        scanf("%d",&inpassword);
        chance++;
    }while(chance<3 && inpassword!=password);
    if(chance==3){
        printf("Password incorrect.\a\n");
        return 0;
    }
    else{

    }
    return 0;
}

void welcome(){

    // Output the stars
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < i; j++){
            printf("*");
        }
        for (int j = i; j > 0; j--){
            printf(" ");
        }
        printf("\n");
    }
    for (int i = 10; i < 21; i++){
        for (int j = 20; j > i; j--){
            printf(" ");
        }
        for (int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
    dash;
    printf("This is a great place for me to practice C programming!\n");
    printf("Please follow the instructions.\n");
    printf("I hope you will like my program :) \n");
    dash;
}
