#include "Participant.h"
#include "level.h"
#include <fstream>
#include "Question.h"
#include <windows.h>
#include <conio.h>
#include <iomanip>

Participant::Participant(string name,string surname,string email)
{
    //ctor
    score =0;
}
Participant::Participant(){
    score =0;
    percentage=0.0;
}

void Participant::attempt(){

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"Enter a Level 1-3 : ";
    //cin>>lev;
    while(lev>3 || lev<1){
        cout<<"That level doesn't exist!!!\nPlease Re-enter a Level 1-3 : ";
        cin>>lev;
    }
    system("cls");
    level l(lev);
    l.getQuestions();
    l.shuffleQuestions();
    int numberOfQuestions ;
    if(lev==1){
        numberOfQuestions=10;
    }else if(lev==2){
        numberOfQuestions=14;
    }else{
        numberOfQuestions=18;
    }
    for(int i=0;i<numberOfQuestions;i++){
        cout<<"User : "<<Getname()<<" "<<Getsurname()<<"\n"<<endl;
        cout<<"Level "<<lev<<string( 30, ' ' )<<"Question "<<i+1<<" of "<<numberOfQuestions<<string( 30, ' ' )<<"Score : "<<score<<"\n\n"<<endl;
        int ans;
        cout<<i+1<<". ";
        system("Color 0B");
        l.Questions[i].display();
        attemptedQuestions.push_back(l.Questions[i]);

        cout<<"\nEnter Option: ";
        cin >> ans;

        while(ans<1 ||ans>l.Questions[i].getOptionsSize()){
                cout<<"option out off range !!!\nRe-Enter Option :";
            cin>>ans;
        }
        answers.push_back(l.Questions[i].getOption(ans-1));
        if(answers[i] == l.Questions[i].getCorrectAnswer()){
            score+=5;
            SetConsoleTextAttribute(h,10);
            cout<<"CORRECT "<<endl;
        }else{
            SetConsoleTextAttribute(h,12);
            cout<< "INCORRECT !!!!"<<endl;
        }
        SetConsoleTextAttribute(h,15);
        system("pause");
        system("cls");

    }
    writeRankings();
    getRankings();
    viewTotalScore();
    l.~level();
}
void Participant::writeRankings(){
    ofstream writefile("levelRanking",ios::app);

    string my_string = to_string(lev)+"|"+name+"|"+surname+"|";
    writefile << my_string;
    writefile<<fixed <<setprecision(2)<<(score/((attemptedQuestions.size())*5.0))*100<<"\n";
    writefile.close();
}

void Participant::getRankings(){
    string textLine;
        ifstream MyRankFile;
        MyRankFile.open("levelRanking");
        while(getline(MyRankFile,textLine)){
            Rank r;
            vector<string>lineToVector;
            lineSplit(lineToVector,textLine);

            r.level = stoi(lineToVector[0]);
            r.name = lineToVector[1];
            r.surname = lineToVector[2];
            double perc = stod(lineToVector[3]);
            r.percentage = perc;
            if(r.level==lev){
                rankings.push_back(r);
            }
        }
}
template<class T>
void Participant::lineSplit(vector<T> &stringVector,string line){
    std::istringstream ss(line);
    string take;
    while(std::getline(ss,take,'|')){
        stringVector.push_back(take);
    }
}
int Participant::getScore(){
    for(int i =0;i<answers.size();i++){
        if(answers[i]==attemptedQuestions[i].getCorrectAnswer()){
            score+=5;
        }
    }
    return score;
}
void Participant::viewTotalScore(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    percentage = (score/((attemptedQuestions.size())*5.0))*100;
    if(percentage>=50.0){
        SetConsoleTextAttribute(h,10);
        cout<<"Congratulations !!!! You have Passed Level :"<<lev<<"\n"<<endl;
        SetConsoleTextAttribute(h,15);
        cout<<"Your Score: "<<score<<"/"<<(attemptedQuestions.size())*5<<"\nPercentage : "<<fixed <<setprecision(2)<<percentage<<"%"<<endl;
        system("pause");
        int option;
        if(lev==3){
            cout<<"\n1. Review "<<endl;
            cout<<"2. Quit "<<endl;

            cout<<"Please Enter Option :";

            cin>>option;

            switch(option){
            case 1:
                review();
                break;
            case 2:
                quit();
                break;
            }
        }else{

            cout<<"\n1. Review "<<endl;
            cout<<"2. Next Level "<<endl;
            cout<<"3. Quit "<<endl;
            cout<<"4. Rankings "<<endl;


            cout<<"Please Enter Option :";

            cin>>option;

            switch(option){
            case 1:
                review();
                break;
            case 4:
                rankPlayers();
                break;
            case 2:
                lev++;
                this->~Participant();
                attempt();
                break;
            case 3:
                quit();
                break;
            }
        }


    }else{
        SetConsoleTextAttribute(h,12);
        cout<<"Sorry You have failed level :"<<lev<<"\n"<<endl;
        SetConsoleTextAttribute(h,15);

        cout<<"Your Score: "<<score<<"/"<<(attemptedQuestions.size())*5<<"\nPercentage : "<<fixed <<setprecision(2) <<percentage<<"%"<<endl;
        system("pause");

        cout<<"\n1. Review This Level"<<endl;
        cout<<"2. Try Again "<<endl;
        cout<<"3. Quit "<<endl;

        cout<<"Please Enter Option :";
        int option;
        cin>>option;

        switch(option){
        case 1:
            review();
            break;
        case 2:
            this->~Participant();
            attempt();
            break;
        case 3:
            quit();
            break;
        }
    }
    system("pause");
    viewTotalScore();
}
void Participant::review(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     system("cls");
     cout<<"This is A Review for level: "<<lev<<endl;
     for(int i=0;i<attemptedQuestions.size() ;i++){
        cout<<(i+1)<<". ";
        attemptedQuestions[i].display();
        if(answers[i]==attemptedQuestions[i].getCorrectAnswer()){
            cout<<"Your answer: ";
            SetConsoleTextAttribute(h,10);
            cout<<answers[i]<<endl;
            SetConsoleTextAttribute(h,15);
        }else{
            cout<<"Your answer: ";
            SetConsoleTextAttribute(h,12);
            cout<<answers[i]<<endl;
            SetConsoleTextAttribute(h,15);
        }
        SetConsoleTextAttribute(h,15);

        cout<<"Correct Answer: "<<attemptedQuestions[i].getCorrectAnswer()<<endl;
        cout<<endl;
    }
}
void Participant::quit(){
    exit(0);
}
void Participant::rankPlayers(){
    system("cls");
    InsertionSort(rankings,rankings.size());

    cout<<"Top 5 Participants Passed Level :"<<lev<<endl<<endl;

    const char separator    = ' ';
    const int nameWidth     = 12;
    cout <<"  ";
    cout << left << setw(nameWidth) << setfill(separator) << "Name";
    cout << left << setw(nameWidth) << setfill(separator) << "Surname";
    cout << left << setw(nameWidth) << setfill(separator) << "Percentage(%)\n"<<endl;
    if(rankings.size()<5){
        for(int i=0;i<rankings.size();i++){
            cout <<i+1<<". ";
            cout << left << setw(nameWidth) << setfill(separator) << rankings[i].name;
            cout << left << setw(nameWidth) << setfill(separator) << rankings[i].surname;
            cout << left << setw(nameWidth) << setfill(separator) << rankings[i].percentage<<endl;
        }
    }else{
        for(int i=0;i<5;i++){
            cout <<i+1<<". ";
            cout << left << setw(nameWidth) << setfill(separator) << rankings[i].name;
            cout << left << setw(nameWidth) << setfill(separator) << rankings[i].surname;
            cout << left << setw(nameWidth) << setfill(separator) << rankings[i].percentage<<endl;
        }


    }
}
template <class T>
void Participant::InsertionSort(vector<T>&A, int n) {
   for (int i = 1; i < n; ++i) {
     if (A[i] > A[i-1]) {
        T val = A[i];
        int j = i;
        do { A[j] = A[j-1];
        --j;
        } while ((j > 0) && (val > A[j-1]));
        A[j] = val;
        }
    }
}

Participant::~Participant()
{
    score =0;
    percentage=0.0;
    answers.clear();
    attemptedQuestions.clear();
    rankings.clear();
}
