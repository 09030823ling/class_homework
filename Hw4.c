#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define dash printf("-----------------------------------------------------------------\n")

typedef struct {
    char name[20];
    char id[20];
    int math;
    int physics;
    int english;
    float average;

}student_info;

int main()
{
    system("clear");// Clear the console on MacOS

    int password=2026;
    int inpassword,chance=0;// Variable to store the input password and the number of chances used
    void welcome(),menu(int,student_info *);// Function prototype
    welcome();// Call the welcome function
    do{
        printf("[%d]\n",chance+1);
        printf("Enter the password:");
        scanf(" %d",&inpassword);
        chance++;
    }while(chance<3 && inpassword!=password);
    if(chance>=4){
        printf("Password incorrect.\a\n");
        return 0;
    }
    else{
        int n;// Variable to store the number of students
        student_info students[10];// Variable to store the student information
        student_info *sp=students;// Pointer to the student information
        menu(n,sp);
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
void menu(int n, student_info *sp){
    system("clear");// Clear the console on MacOS
    
    int A(int ,student_info *);
    void B(int,student_info *),C(int,student_info *),D(int,student_info *),E(int,student_info *);// Function prototype
    printf("--------------------------[Booking System]--------------------------\n");
    printf("|                a. Enter student grades                           |\n");
    printf("|                b. Display student grades                         |\n");
    printf("|                c. Search for student grades                      |\n");
    printf("|                d. Grade ranking                                  |\n");
    printf("|                e. Exit                                           |\n");
    dash;
    char choice;
    int valid=1;
    while(valid==1){
        valid=0;
        printf("Enter your choice:");
        scanf(" %c",&choice);
        if(choice-'A'>=0 && choice-'D'<=0){// Convert uppercase(A-D) to lowercase
            choice=choice-'A'+'a';
        }
        switch(choice){
            case 'a':
                n=A(n,sp);
                break;
            case 'b':
                B(n,sp);
                break;
            case 'c':
                C(n,sp);
                break;
            case 'd':
                D(n,sp);
                break;
            case 'e':
                E(n,sp);
                break;
            default:
                printf("Invalid choice.\n");
                valid=1;
        }
    }

    
    
}



int A(int n,student_info *sp){
    system("clear");// Clear the console on MacOS
    n=0;
    int idcount=0;
    printf("Enter the number of students (2~10):");
    scanf(" %d", &n);
    while(n<2 || n>10){// Check if the input is valid
        printf("Your enter is wrong.Please enter a number in 2 to 10:");
        scanf(" %d", &n);
    }
    
    for(int i=0;i<n;i++){
        (sp+i)->name[0]='\0';
        (sp+i)->id[0]='\0';
        (sp+i)->math=-1;
        (sp+i)->physics=-1;
        (sp+i)->english=-1;
    }
    for(int i=0;i<n;){
        idcount=0;
        while((sp+i)->name[0]=='\0'){// Check if the name is valid
            printf("Enter the name of student %d:",i+1);
            scanf(" %s", (sp+i)->name);
            if((sp+i)->name[0]=='\0'){
                printf("Your enter is wrong.Please enter the name again.\n");
            }
        }
        while(idcount==0){// Check if the id is valid
            printf("Enter the id of student %d (9 digits):",i+1);
            scanf(" %s", (sp+i)->id);
            for(int j=0;(sp+i)->id[j]!='\0';j++)  idcount++;
            if(idcount!=9){
                idcount=0;
                printf("Your enter is wrong.Please enter the id again.\n");
            }
        }
        while((sp+i)->math<0 || (sp+i)->math>100){// Check if the math score is valid
            printf("Enter the math score of student %d (0~100):",i+1);
            scanf(" %d", &(sp+i)->math);
            if((sp+i)->math<0 || (sp+i)->math>100){
                printf("Your enter is wrong.Please enter the math score again.\n");
            }
        }
        while((sp+i)->physics<0 || (sp+i)->physics>100){// Check if the physics score is valid
            printf("Enter the physics score of student %d (0~100):",i+1);
            scanf(" %d", &(sp+i)->physics);
            if((sp+i)->physics<0 || (sp+i)->physics>100){
                printf("Your enter is wrong.Please enter the physics score again.\n");
            }
        }
        while((sp+i)->english<0 || (sp+i)->english>100){// Check if the english score is valid
            printf("Enter the english score of student %d (0~100):",i+1);
            scanf(" %d", &(sp+i)->english);
            if((sp+i)->english<0 || (sp+i)->english>100){
                printf("Your enter is wrong.Please enter the english score again.\n");
            }
        }
        (sp+i)->average=((float)((sp+i)->math+(sp+i)->physics+(sp+i)->english))/3.0;
        i++;
    }
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu(n,sp); // Call the menu function --- IGNORE ---
    return n;
}

void B(int n,student_info *sp){
    printf("Student   |     Name    |     ID     |    Math   |   Physics  |   English  |   Average  |\n");
    for(int i=0;i<n;i++){
        printf("Student%2d | %10s  | %10s |    %3d    |     %3d    |     %3d    |    %5.1f   |\n", i+1, (sp+i)->name, (sp+i)->id, (sp+i)->math, (sp+i)->physics, (sp+i)->english, (sp+i)->average);
    }
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu(n,sp);
    return;
}

void C(int n,student_info *sp){
    char name[20];
    printf("Enter the name of the student you want to search:");
    scanf(" %s", name);
    int found=1;
    for(int i=0;i<n;i++){
        if(strcmp((sp+i)->name,name)==0) {
            printf("Student   |     Name    |     ID     |    Math   |   Physics  |   English  |   Average  |\n");
            printf("Student%2d | %10s  | %10s |    %3d    |     %3d    |     %3d    |    %5.1f   |\n", i+1, (sp+i)->name, (sp+i)->id, (sp+i)->math, (sp+i)->physics, (sp+i)->english, (sp+i)->average);
            found=0;
        }
    }
    if(found){
        printf("The student is not found.\n");
    }
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu(n,sp);
    return;
    
}
/*

6. [15%] 使用者若輸入’d’， 則清除螢幕，在螢幕上依平均成績的高低順序列出學生的姓名、學號及平均成績。待使用者按下任何鍵則清除螢幕，回到主選單。

7. [5%] 使用者若輸入’e’，在螢幕上輸出‘確定離開？ (y/n)’如果使用者輸入’n’,則回到主選單；如果使用者輸入’y’，則結束程式回到作業系統。若是其他鍵，再問一次。

8. [30%] 註解及說明。程式碼須加上註解。相關說明、討論與心得也一併寫在程式的原始碼檔內。程式執行中請加上適當的提示句引導使用者順利操作。

*/
void D(int n,student_info *sp){
    for(int i=0;i<n;i++){
        int max=i;
        for(int j=i;j<n;j++){
            if((sp+max)->average < (sp+j)->average){
                max=j;
                printf("Max average: %5.1f\n", (sp+max)->average);
            }
            student_info Max=*(sp+max);
            *(sp+max)=*(sp+i);
            *(sp+i)=Max;
        }
    }
    printf("Student   |     Name    |     ID     |    Math   |   Physics  |   English  |   Average  |\n");
    for(int i=0;i<n;i++){
        printf("Student%2d | %10s  | %10s |    %3d    |     %3d    |     %3d    |    %5.1f   |\n", i+1, (sp+i)->name, (sp+i)->id, (sp+i)->math, (sp+i)->physics, (sp+i)->english, (sp+i)->average);
    }
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu(n,sp);
    return;

   
}
void E(int n,student_info *sp){
    printf("Continue?(y/n)\n");
    char answer;
    scanf(" %c",&answer);
    if(answer-'A'>=0 && answer-'Z'<=0){// Convert uppercase(Y/N) to lowercase
        answer=answer-'A'+'a';
    }
    while(answer!='y' && answer!='n'){// Check if the input is valid
        printf("Your enter is wrong.Please enter y or n:");
        scanf(" %c",&answer);
    }
    if(answer=='y'){
        menu(n,sp);
    }
    else{
        printf("Goodbye!\n");
        return;
    }
    return;
}
/*
My Reflection
Through this student management program, I became more familiar with C programming, especially structures and pointers.
 While learning pointers, I made many attempts and mistakes, particularly with data passing and memory access, which helped me better understand how they work. 
 I also learned how to design validate input and implement sorting. 
 Overall, this project improved my logical thinking and debugging skills, and it was a very valuable learning experience.


*/