#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
char player='x';
char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char m[3][3]={'1','2','3','4','5','6','7','8','9'};
void draw()
{
    system("cls");
    cout<<"\n\n\t\tTIC TAC TOE V2.0\n\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void input()
{
    char a;
    cout<<"IT'S "<<player<<" TURN "<<"press the no. of the field\n";
    cin>>a;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i][j]==a)
            {
                if(matrix[i][j]!='x' && matrix[i][j]!='o')
                    matrix[i][j]=player;
            }
        }
    }
}
void toggleplayer()
{
    if(player=='x')
        player='o';
    else
        player='x';
}
char win()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==0){
         if((matrix[i][j] == matrix[i+1][j]) && (matrix[i+1][j] == matrix[i+2][j]))
                                            return (matrix[i][j]);}
                                            if(j==0){
         if((matrix[i][j] == matrix[i][j+1]) && (matrix[i][j+1] == matrix[i][j+2]))
            return (matrix[i][j]);}
        if(i==0 && j==2)
        {
            if((matrix[i][j] == matrix[i+1][j-1])&& (matrix[i+1][j-1] == matrix[i+2][j-2]))
            {
                return (matrix[i][j]);}
        }
        if(i==0 && j==0)
        {
         if((matrix[i][j] == matrix[i+1][j+1])&& (matrix[i+1][j+1] == matrix[i+2][j+2]))
            {
                return (matrix[i][j]);}
            }
        }
    }
    return '/';
}
int main()
{
    char ch='y';
    do{
    int n=0;
    for(int i=0;i<3;i++)
         {
             for(int j=0;j<3;j++)
             {
                 matrix[i][j]=m[i][j];
             }
         }
         draw();
    do
    {
        n++;
     input();
     draw();
     /*if(n%9 == 0)
     {
         for(int i=0;i<3;i++)
         {
             for(int j=0;j<3;j++)
             {
                 matrix[i][j]=m[i][j];
             }
         }
     }*/
     if(win()=='x')
        {
            cout<<"x wins"<<endl;
            break;
        }
     else if(win()=='o')
        {
            cout<<"o wins\n";
            break;
        }
        else if(win()=='/' && n==9)
        {
            cout<<"draw"<<endl;
            break;
        }
     toggleplayer();
    }while(1);
    cout<<"do you wanna play more: ";
            cin>>ch;
    }while(ch=='y');
    return 0;
}
