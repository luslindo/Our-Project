#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream>
#include <vector>
#include "Question.h"

using namespace std;


class Participant
{
    public:
        Participant(string name,string surname,string email);
        virtual ~Participant();

        string Getname() { return name; }
        string Getsurname() { return surname; }
        string Getemail() { return email; }
        bool getregistered(){return registered;}

        int getScore();

        void attempt();//attempting a quiz
        void viewTotalScore();//viewing the total score s/he got
        void review(); //review the attempted quiz , where s/he gone wrong
        void quit(); //quiz the quiz


    protected:

    private:
        string name;
        string surname;
        string email;
        int score ;
        int lev ; // the level participant want to attempt
        vector <Question>attemptedQuestions;
        vector <string>answers;
        bool registered =false;

};
#endif // PARTICIPANT_H
