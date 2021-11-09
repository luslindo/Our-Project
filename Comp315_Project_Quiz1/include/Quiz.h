#ifndef QUIZ_H
#define QUIZ_H
#include "level.h"
#include "Participant.h"


class Quiz
{
    public:
        Quiz();
        void register_p();//register a new participant
        void mainMenu();



    protected:

    private:
        string name,surname;
        Participant part;
};

#endif // QUIZ_H
