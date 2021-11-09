#include "Question.h"
#include <algorithm>
#include <random>
#include <chrono>

Question::Question(string questionText,string correctAnswer,vector<string>options)
{
    this->questionText=questionText;
    this->correctAnswer=correctAnswer;
    this->options=options;

}

void Question::shuffleOptions(){
        unsigned seed = std::chrono::system_clock::now()
						.time_since_epoch()
						.count();
	shuffle(options.begin(), options.end(), std::default_random_engine(seed));
}
string Question::getOption(int index){
    return options[index];
}
void Question::display(){
    cout<<this->questionText<<"  (5 Marks)"<<endl;
    this->shuffleOptions();
    for(int i=0;i<options.size();i++){
        cout<<"["<<i+1<<"] "<<options[i]<<endl;
    }
}


