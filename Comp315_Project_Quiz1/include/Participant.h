#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream>
#include <vector>
#include <set>
#include "Question.h"

using namespace std;

struct Rank{
    int level;
    double percentage;
    string name;
    string surname;
    bool operator >(Rank r){
        if(percentage!=r.percentage){
            return percentage>r.percentage;
        }else{
            if(surname!=r.surname)
                return r.surname>surname;
            else
                return r.name>name;
        }
    }
};

class Participant
{
    public:
        Participant(string name,string surname,string email);
        Participant();
        ~Participant();

        string Getname() { return name; }
        string Getsurname() { return surname; }

        void setName(string name){this->name=name;}
        void setSurname(string surname){this->surname=surname;}

        int getScore();
        void writeRankings();//writing passed participant for rankings
        void getRankings();

        void attempt();//attempting a quiz
        void viewTotalScore();//viewing the total score s/he got
        void review(); //review the attempted quiz , where s/he gone wrong
        void quit(); //quiz the quiz
        void rankPlayers();
        template <class T>
        void InsertionSort(vector<T>&A, int n);

    protected:
        template<class T>
        void lineSplit(vector<T> &stringVector,string line);

    private:
        string name;
        string surname;
        int score ;
        float percentage ;
        int lev=1 ; // the level participant want to attempt
        vector <Question>attemptedQuestions;
        vector <string>answers;
        vector <Rank> rankings;
       // set<Rank> rankingset;

};
#endif // PARTICIPANT_H
