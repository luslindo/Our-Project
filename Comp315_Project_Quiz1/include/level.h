#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <iostream>
#include "Question.h"



class level
{
    public:
        level(int levels);
        ~level();
        void getQuestions();
        void shuffleQuestions();
        vector<Question> Questions ;
        template<class T>
        void lineSplit(vector<T> &stringVector,string line);

    protected:

    private:

        int levels;



};
#endif // LEVEL_H
