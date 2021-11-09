#include "level.h"
#include <fstream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

level::level(int levels)
{
    //ctor
    this->levels=levels;

}
void level::getQuestions(){

    string textLine;
        ifstream MyReadFile;
        MyReadFile.open("Questions.txt");
        while(getline(MyReadFile,textLine)){
            //int lev;
            vector<string>lineToVector;
            lineSplitt(lineToVector,textLine);
            int i=stoi(lineToVector[0]);
            if(i==levels){
                vector<string>options;
                string textquestion =lineToVector[1];
                string correct=lineToVector[2];
                for(int j=2;j<lineToVector.size();j++){
                    options.push_back(lineToVector[j]);
                }

                Questions.push_back(Question(textquestion,correct,options));
            }else{
                continue;
            }
        }
}
void level::lineSplitt(vector<string> &stringVector,string line){
    std::istringstream ss(line);
    string take;
    while(std::getline(ss,take,'|')){
        stringVector.push_back(take);
    }
}
void level::shuffleQuestions(){
    unsigned seed = std::chrono::system_clock::now()
						.time_since_epoch()
						.count();
	shuffle(Questions.begin(), Questions.end(), std::default_random_engine(seed));
}
void level::display(){
    shuffleQuestions();
    for(int i =0;i<Questions.size();i++){
        Questions[i].shuffleOptions();
        Questions[i].display();
    }
}

level::~level()
{
    //dtor
}
