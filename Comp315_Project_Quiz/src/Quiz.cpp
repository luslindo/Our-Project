#include "Quiz.h"
#include <iostream>

using namespace std;

Quiz::Quiz()
{
    //ctor
}
void Quiz::register_p(){
    string name,surname,email;
    cin>>name,surname,email;

    Participant p(name,surname,email);
}

Quiz::~Quiz()
{
    //dtor
}
