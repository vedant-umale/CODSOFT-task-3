#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column,i,j;
int number;
char turn='X';
bool tie=false;
string n1="";
string n2="";
char again;

void board(){
    cout<<"player 1[X]\tplayer 2[O]\n";
    cout<<"\t     |     |    \n";
    cout<<"\t"<<space[0][0]<<"    | "<<space[0][1]<<"   | "<<space[0][2]<<"\n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |    \n";
    cout<<"\t"<<space[1][0]<<"    | "<<space[1][1]<<"   | "<<space[1][2]<<"\n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |    \n";
    cout<<"\t"<<space[2][0]<<"    | "<<space[2][1]<<"   | "<<space[2][2]<<"\n";
    cout<<"\t     |     |    \n";
    cout<<endl;
}

void playerTurn(){

    if(turn=='X'){
        cout<<n1<<" player 1.. please enter :";
        cin>>number;
        cout<<endl;
    }
    else if(turn=='O'){
        cout<<n2<<" player 2.. please enter :";
        cin>>number;
        cout<<endl;
    }

    switch(number){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"sorry.. You entered wrong number.";
    }

    if(turn=='X' && space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='X';
        turn='O';
    }
    else if(turn=='O' && space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='O';
        turn='X';
    }
    else{
        cout<<"There is no empty space!!\n";
        playerTurn();
    }

}

bool checkWin(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][0] && space[0][i]==space[2][i]){
            return true;
        }
        if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
            return true;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            }
        }
    }
    tie=false;
    return true;
     
}

int main(){
   while(again!='N'){
    cout<<"\n\t\t\t********************************";
    cout<<"\n\t\t\t* Welcome to TIC TAC TOE game! *";
    cout<<"\n\t\t\t********************************\n";

    cout<<"Enter the name of first player : ";
    cin>>n1;
    cout<<"Enter the name of second player : ";
    cin>>n2;
    cout<<n1<<" is first player so he/she will play first."<<endl;
    cout<<n2<<" is second player so he/she will play second.\n"<<endl;


   
        while(!checkWin() && again!='N'){
            board();
            playerTurn();
            checkWin();
        } 

        if(turn=='X' && tie==false){
            cout<<"\nCONGRATULATIONS!!! player 2 wins the game."<<endl;
            cout<<"Want to play the game again ? (Enter Y for yes and N for no.) : ";
            cin>>again;
        }
        else if(turn=='O' && tie==false){ 
            cout<<"\nCONGRATULATIONS!!! player 1 wins the game."<<endl;
            cout<<"Want to play the game again ? (Enter Y for yes and N for no.) : ";
            cin>>again;
        }
        else{
            cout<<"Game draw"<<endl;
            cout<<"Want to play the game again ? (Enter Y for yes and N for no.) : ";
            cin>>again;
        }
   }
    return 0;
}