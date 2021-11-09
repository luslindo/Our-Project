#include "Participant.h"
#include "level.h"
#include "Question.h"
#include <conio.h>
Participant::Participant(string name,string surname,string email)
{
    //ctor
    name=name;
    surname =surname;
    email=email;
    score =0;
}

void Participant::attempt(){
    cout<<"Enter a Level 1-3 : ";
    cin>>lev;
    while(lev>3 || lev<1){
        cout<<"INVALID level !!!\n please Re-enter a Level 1-3 : ";
        cin>>lev;
    }
    system("cls");
    level l(lev);
    l.getQuestions();
    l.shuffleQuestions();
    for(int i=0;i<5;i++){
        int ans;
        cout<<i+1<<". ";
        l.Questions[i].display();
        attemptedQuestions.push_back(l.Questions[i]);
        cout<<"Enter Option :";
        cin>>ans;
        while(ans<1 ||ans>l.Questions[i].getOptionsSize()){
                cout<<"option out off range !!!\nRe-Enter Option :";
            cin>>ans;
        }
        answers.push_back(l.Questions[i].getOption(ans-1));
        system("cls");

    }
}
int Participant::getScore(){
    for(int i =0;i<answers.size()-1;i++){
        if(answers[i]==attemptedQuestions[i].getCorrectAnswer()){
            score+=5;
        }
    }
    return score;
}
void Participant::viewTotalScore(){
    cout<<"Your Score: "<<getScore()<<"/"<<(attemptedQuestions.size())*5;
}
void Participant::review(){
     for(int i=0;i<4 ;i++){
        attemptedQuestions[i].display();
        cout<<"Your answer: "<<answers[i]<<endl;
        cout<<"Correct Answer: "<<attemptedQuestions[i].getCorrectAnswer()<<endl;
    }
}
void Participant::quit(){

}

Participant::~Participant()
{
    //dtor
}
