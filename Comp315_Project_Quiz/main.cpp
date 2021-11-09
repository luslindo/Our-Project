#include <iostream>
#include <level.h>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <Participant.h>

using namespace std;
static void print_rectangle()
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        int n =6;
        int m =40;
        int i, j;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (i == 1 || i == n ||j == 1 || j == m){
                    SetConsoleTextAttribute(h,FOREGROUND_RED);
                    cout<<("*");
                }else{
                    cout<<(" ");
                }
            }
            cout<<endl;
        }
        SetConsoleTextAttribute(h,7);

    }


int main()
{

    print_rectangle();
    Participant p("olothando","gwiji","olog@mail.com");
    p.attempt();

    p.review();
    p.viewTotalScore();
    /*int n;
    level l(1);
    l.getQuestions();
    l.shuffleQuestions();
    //l.display();
    for(int i=0;i<5;i++){
        cout<<i+1<<". ";
        l.Questions[i].display();
        cin>>n;
        system("cls");

    }*/
    cout << "Hello world!" << endl;
    return 0;
}
