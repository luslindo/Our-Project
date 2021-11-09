#ifndef QUESTION_H
#define QUESTION_H
#include <vector>
#include <iostream>
using namespace std;

class Question
{
    public:
        Question(string questionText,string correctAnswer,vector<string>options);
        virtual ~Question();
        void shuffleOptions();
        void display();
        string getOption(int index);
        string getCorrectAnswer(){return correctAnswer;}
        int getOptionsSize(){return options.size();}

    protected:

    private:
        string questionText;
        string correctAnswer;
        vector<string>options;

};

#endif // QUESTION_H
