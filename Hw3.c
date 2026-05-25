#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//This problem when use #include<conio.h>
#define dash printf("--------------------------------------------------------------\n")
int pos[9][9]={0}; 
int main()
{
    
    system("clear");// Clear the console on MacOS
    srand((unsigned int)time(NULL));
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
    if(chance>=4){
        printf("Password incorrect.\a\n");
        return 0;
    }
    else{
        menu();
    }
    return 0;
}

void welcome(){
    void create();
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
    create();

}
void menu(){
    system("clear");// Clear the console on MacOS
    void A(),B(),C(),D();// Function prototype
    printf("----------------------[Booking System]--------------------------\n");
    printf("|                a. Available seats                            |\n");
    printf("|                b. b. Arrange for you                         |\n");
    printf("|                c. Choose by yourself                         |\n");
    printf("|                d. Exit                                       |\n");
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
                A();
                break;
            case 'b':
                B();
                break;
            case 'c':
                C();
                break;
            case 'd':
                D();
                break;
            default:
                printf("Invalid choice.\n");
                valid=1;
        }
    }

    
    
}

//考慮一下要不要整合@ *輸出 ----不要
void show(){
    printf("\\123456789\n");
    for(int i=8;i>=0;i--){
        printf("%d",i+1);
        for(int j=0;j<9;j++){
            if(pos[i][j]==1) printf("*");
            //if else (pos[i][j]==0) printf(" ");
            else printf("-");
        }
        printf("\n");
    }
    printf("\n");
}
void show_book(){
    printf("The booked seats are marked with @.\n");
    printf("\\123456789\n");
    for(int i=8;i>=0;i--){
        printf("%d",i+1);
        for(int j=0;j<9;j++){
            if(pos[i][j]==1) printf("*");
            else if(pos[i][j]==2) printf("@");
            else printf("-");
        }
        printf("\n");
    }
    printf("\n");
    
    //意願紀錄
    char choice;
    printf("Do you want to confirm the booking? (y/n):");
    scanf(" %c",&choice);
    while(choice!='y' && choice!='n'){// Check if the input is valid
        printf("Your enter is wrong.Please enter y or n:");
        scanf(" %c",&choice);
        if(choice-'A'>=0 && choice-'Z'<=0){// Convert uppercase(A-C) to lowercase
            choice=choice-'A'+'a';
        }
    }
    if(choice=='y'){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(pos[i][j]==2) pos[i][j]=1;//confirm the booking
            }
        }
        return;
    }
    else{
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(pos[i][j]==2) pos[i][j]=0;//cancel the booking
            }
        }
        return;
    }

}
void A(){
    system("clear");// Clear the console on MacOS
    show();
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu();
    
}
void create(){
    int count=0;
    while(count<10){
        int r=rand()%9;
        int c=rand()%9;
        if(pos[r][c]==0){
            pos[r][c]=1;
            count++;
        } 
    }
    return;
}

void B(){
    void show_book();
    int n;
    printf("Please enter a number what you want of seats in 1 to 4:");
    scanf(" %d",&n);
    while(n<1 || n>4){// Check if the input is valid
        printf("Your enter is wrong.Please enter a number in 1 to 4:");
        scanf(" %d",&n);
    }
    int found=1;// Variable to indicate whether the seats are found
    int checkr[9]={0};// Check if the row has been checked
    int count=0;
    
    //先看列，再看行
    while(found && count<9){
        int r=rand()%9;
        int checkc[9]={0};// Check if the column has been checked
        int countc=0;
        if(checkr[r]==0){
            checkr[r]=1;
            count++;
        }
        else continue;
        if(n!=4){
            while(countc<9-n+1 && found){
                int c=rand()%(9-n+1);
                if(checkc[c]==0){
                    checkc[c]=1;
                    countc++;
                    int seat=0;// Count the number of available seats
                    for(int i=c;i<c+n;i++){
                        if(pos[r][i]==0) seat++;
                    }
                    if(seat>=n){
                        for(int i=c;i<c+n;i++){
                            pos[r][i]=2;// Book the seats
                        }
                        found=0;
                        show_book();
                    }
                }
                else continue;
            }
        }
        else{
            if(r==8){//the last row can only consider 4 in a row
                
                while(countc<9-3 && found){
                    int c=rand()%(9-3);
                    if(checkc[c]==0){
                        checkc[c]=1;
                        countc++;
                        int seat=0;// Count the number of available seats
                        for(int i=c;i<c+n;i++){
                            if(pos[r][i]==0) seat++;
                        }
                        if(seat>=n){
                            for(int i=c;i<c+n;i++){
                                pos[r][i]=2;// Book the seats
                            }
                            found=0;
                            show_book();
                        }
                    }
                    else continue;
                }
            }
            else{
                int rchoice=rand()%2;// Randomly choose to check 4 in a row or 2+2
                for(int i=0;i<2;i++){
                    if(i==1) rchoice=1-rchoice;// Change the choice to check the other option
                    if(rchoice==0){
                        while(countc<9-3 && found){
                        int c=rand()%(9-3);
                        if(checkc[c]==0){
                            checkc[c]=1;
                            countc++;
                            int seat=0;// Count the number of available seats
                            for(int i=c;i<c+n;i++){
                                if(pos[r][i]==0) seat++;
                            }
                            if(seat>=n){
                                for(int i=c;i<c+n;i++){
                                    pos[r][i]=2;// Book the seats
                                }
                                found=0;
                                show_book();
                            }
                        }
                        else continue;
                        }
                    }
                    else{
                        //r列和r+1列的2+2
                        while(countc<9-1 && found){
                            int c=rand()%(9-1);
                            if(checkc[c]==0){
                                checkc[c]=1;
                                countc++;
                                int seat=0;// Count the number of available seats
                                for(int i=c;i<c+2;i++){
                                    if(pos[r][i]==0 && pos[r+1][i]==0) seat++;
                                }
                                if(seat>=2){
                                    for(int i=c;i<c+2;i++){
                                        pos[r][i]=2;// Book the seats
                                        pos[r+1][i]=2;
                                    }
                                    found=0;
                                    show_book();
                                }
                            }
                            else continue;
                        }
                    }



                }
                
                


            }

        }

    }
    if(count>=9){
        printf("Sorry, there are no available seats for you.\n");
    }
    
    
    printf("Press any key to return to the menu...");
    fflush(stdout);//because the output is buffered, we need to flush it before waiting for user input
    system("read -n 1 -s");// Wait for user input before returning to the menu (This is search on the internet, I don't know how to use getch() in MacOS or VScode)
    menu();
}
void C(){
    void show_book(),show();
    int rb[82]={0},cb[82]={0};
    int check=1;// Variable to check if the input is valid
    int found=1;// Variable to indicate whether the seats are found
    int p=0,now=0;// Variable to store the row and column of the seats
    char seat[250];// Variable to store the input seat
    getchar(); // clear the input buffer
    while(found){
        for(int i=0;i<=250;i++){
            seat[i]='0';
        }
        printf("Please enter the number what you want of the row-column of seats, and use space to separate (like:1-2 2-4 3-5(Enter)):\n");
        fgets(seat, sizeof(seat), stdin);
        printf("You entered: %s\n",seat);
        //scanf(" %d-%d",&r[p],&c[q]);
        while(seat[now]!='\n'){// Check if the input is valid
            rb[p]=seat[now]-'0';
            check=seat[now+1]-'-';
            cb[p]=seat[now+2]-'0';
            
            while((rb[p]<1 || rb[p]>9) || (cb[p]<1 || cb[p]>9) || check!=0){
                for(int i=0;i<=250;i++){
                    seat[i]='0';
                }
                printf("Your enter is wrong.Please enter the row-column of seats again (like:1-2 2-4 3-5(Enter)):\n");
                fgets(seat, sizeof(seat), stdin);
                now=0;
                for(int i=0;i<=p;i++){
                    rb[i]=0;
                    cb[i]=0;
                }
                p=0;
                rb[p]=seat[now]-'0';
                check=seat[now+1]-'-';
                cb[p]=seat[now+2]-'0';
            }
            if(seat[now+3]!='\n'){
                now+=4;
                p++;
            }
            else{
                now+=3;
            }
        }
        for(int i=0;i<p+1;i++){
            if(pos[rb[i]-1][cb[i]-1]==0){
                pos[rb[i]-1][cb[i]-1]=2;// Book the seats
                found=0;
            }
            else{
                printf("Sorry, seat %d-%d is not available.\n",rb[i],cb[i]);
                found=1;
                now=0;
                p=0;
                break;
            }
        }
        if(found==0){
            show_book();
        }
    }
    printf("Press any key to return to the menu...");
    fflush(stdout);
    system("read -n 1 -s");
    menu();
}
void D(){
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
        menu();
    }
    else{
        printf("Goodbye!\n");
        return;
    }
    return;
}
/*
My Reflection
This project allowed me to focus more on practical program design and handling real-world user interactions. 
I implemented a seat reservation system that required careful management of a two-dimensional array to represent seat states and transitions between available, selected, and confirmed bookings.
A key challenge in this assignment was parsing user input with flexible formats, especially when dealing with multiple seat selections in a single line. 
I learned how to properly use fgets and manual string parsing instead of relying on simpler input functions, which improved the program’s reliability.
I also strengthened my understanding of control flow by handling various edge cases, such as invalid formats and already-occupied seats. 
Designing these checks required me to think more carefully about program robustness and user experience.

*/