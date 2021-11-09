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
    vector<string>options;
    vector<string>lineToVector;

    string textLine;
        ifstream MyReadFile;
        MyReadFile.open("Questions.txt");
        while(getline(MyReadFile,textLine)){
            //int lev;

            lineSplit(lineToVector,textLine);
            int i=stoi(lineToVector[0]);
            if(i==levels){

                string textquestion =lineToVector[1];
                string correct=lineToVector[2];
                for(int j=2;j<lineToVector.size();j++){
                    options.push_back(lineToVector[j]);
                }

                Questions.push_back(Question(textquestion,correct,options));
                options.clear();
            }
            lineToVector.clear();
        }
}
template<class T>
void level::lineSplit(vector<T> &stringVector,string line){
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

level::~level()
{
    Questions.clear();
    //dtor
}
