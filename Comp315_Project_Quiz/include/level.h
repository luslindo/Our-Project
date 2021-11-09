#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <iostream>
#include "Question.h"



class level
{
    public:
        level(int levels);
        virtual ~level();
        void getQuestions();
        void shuffleQuestions();
        void display();
        vector<Question> Questions ;

    protected:

    private:

        int levels;
        void lineSplitt(vector<string> &stringVector,string line);


};
#endif // LEVEL_H
