#include "Quiz.h"
#include <iostream>

using namespace std;

Quiz::Quiz()
{
    //ctor
}
void Quiz::register_p(){
    cout<<"Register before continue ...\n"<<endl;
    cout<<"Enter a Name :";
    cin>>name;
    cout<<"\nEnter a Surname :";
    cin>>surname;

    part.setName(name);
    part.setSurname(surname);
}
void Quiz::mainMenu(){

    system("cls");

    cout<<"User : "<<part.Getname()<<" "<<part.Getsurname()<<"\n"<<endl;

    int option;
    cout<<"1. Attempt "<<endl;
    cout<<"2. Quit "<<endl;
    cout<<"\nPlease Enter Option :";
    cin>> option;
    while(option<1 ||option>2){
                cout<<"option out off range !!!\nRe-Enter Option :";
            cin>>option;
        }

    switch(option){
    case 1:
        part.attempt();
        break;
    case 2:
        part.quit();
    }
    mainMenu();
}


