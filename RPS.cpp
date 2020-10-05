#include <iostream>
#include <iomanip>
#include <random>
using namespace std;
void intro();
int userChoice();
void userinput(int);
void compChoice(int);
int win_result(int,int);

int main()
{   intro(); // introduction to the program
    int x = 0;
    x = userChoice(); // takes user value and stores in x
    userinput(x);
    // computer will randomize number between 1 - 3
    srand(time(NULL));
    int computerChoice = rand() % 3 + 1;

    compChoice(computerChoice);

    int winner;
    winner = win_result(computerChoice, x);

    while (winner == 1){
        cout << endl << "It's a draw, Running program again to determine the winner" << endl;
        cout << endl << " Enter 1 for Rock \n Enter 2 for Paper \n Enter 3 for Scissors" << endl;
        x = userChoice();
        userinput(x);

        //srand(time(NULL));
        int computerChoice = rand() % 3 + 1;
        compChoice(computerChoice);

        winner = win_result(computerChoice, x);
        }

    if (winner == 2)
    {
        cout << "Your Win" << endl;
    }
    else if(winner == 3)
    {
        cout << "Computer Wins" << endl;
    }
    return 0;
}

void intro()
{
    cout << "This is Bhakti's rock paper scissor game."<< endl << endl;
    cout << " Rules: \n *Rock smashes scissors, so rock wins. \n"
            " *Scissors cuts paper, so scissors wins. \n"
            " *Paper wraps rock, so paper wins. \n"
            " *If both players make same choice, game must be played again to determine winner.";
    cout << endl;
    cout << endl;
    cout << " Enter 1 for Rock \n Enter 2 for Paper \n Enter 3 for Scissors" << endl;

}
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
   return userinput;
    }

return userinput;
}

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

void userinput(int x){
    if (x == 1){
        cout << "Your choice: Rock" << endl;
    }
    else if (x==2){

        cout << "Your choice: Paper" << endl;
    }
    else if (x == 3){

        cout << "Your choice: Scissor" << endl;
    }

}
