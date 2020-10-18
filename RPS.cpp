#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;
void men2();
void intro();
void menu();
int userChoice();
void userinput(int);
void compChoice(int);
int win_result(int,int);

int main()
{   intro();
    int y;
    do{
    men2();
    cout << endl;
    cout << endl;
    cout << "Would you like to run the program again?"<<endl;
    cout << "Enter '1' for Yes, '0' for No: " << endl;
    cin >> y;
    cout << endl;

    if (y == 1){
        menu();
    }
    }while(y == 1);

    return 0;
}

// introduction
void intro()
{
        cout << "This is Bhakti's rock paper scissor game."<< endl << endl;
        cout << " Rules: \n *Rock smashes scissors, so rock wins. \n"
            " *Scissors cuts paper, so scissors wins. \n"
            " *Paper wraps rock, so paper wins. \n"
            " *If both players make same choice, game must be played again to determine winner.";
        cout << endl;
        cout << endl;
    menu();

}
//ask user input
int userChoice()
{
    int userinput;
        cout << endl;
        cout << "Enter your choice : ";
        cin >> userinput;

    while (userinput >= 4 || userinput <= 0){
        cout << endl;
        cout << "invalid choice, Enter your choice : ";
        cin >> userinput;
    }
return userinput;
}

//determines winner
int win_result(int CompC, int UserC)
{
    if ((CompC == 1 && UserC == 1) || (CompC == 2 && UserC == 2) || (CompC == 3 && UserC == 3)){
        return 1;
    }

    else if ((UserC == 1  && CompC == 3)||(UserC == 3  && CompC == 2)||(UserC == 2  && CompC == 1)){
        return 2;
    }
    else if((UserC == 3  && CompC == 1)||(UserC == 2  && CompC == 3)||(UserC == 1  && CompC == 2)){
        return 3;
    }

}

//defines computer choice
void compChoice(int y){
    if (y == 1){
        cout << "Computer choice: Rock" << endl;
    }
    else if (y==2){

        cout << "Computer choice: Paper" << endl;
    }
    else if (y == 3){

        cout << "Computer choice: Scissor" << endl;
    }

}

//defines user choice
void userinput(int x){
    if (x == 1){
        cout << endl << "Your choice: Rock" << endl;
    }
    else if (x==2){

        cout << endl << "Your choice: Paper" << endl;
    }
    else if (x == 3){

        cout << endl <<  "Your choice: Scissor" << endl;
    }

}

// outputs menu
void menu(){

        cout <<endl << " Enter 1 for Rock \n Enter 2 for Paper \n Enter 3 for Scissors" << endl;
}
// This function will determines the whole game, which will be called in main
void men2(){

   // intro(); // introduction to the program

    int x = 0;
    x = userChoice(); // takes user value and stores in x
    userinput(x); // determines what user picked

    // computer will randomize number between 1 - 3
    srand(time(NULL));
    int computerChoice = rand() % 3 + 1;

    compChoice(computerChoice); // determines what computer picked

    int winner;
    winner = win_result(computerChoice, x); // determines winner

    // if draw, it will run the program again
    while (winner == 1){
        cout << endl << "It's a draw, Running program again to determine the winner" << endl;
        menu(); //outputs menu
        x = userChoice();
        userinput(x);

        srand(time(NULL));
        int computerChoice = rand() % 3 + 1;
        compChoice(computerChoice);

        winner = win_result(computerChoice, x);
        }
    //output if it's a winnner
    if (winner == 2)
    {
        cout << "Your Win" << endl;
    }
    //output if computer wins
    else if(winner == 3)
    {
        cout << "Computer Wins" << endl;
    }

}
