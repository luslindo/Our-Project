#include <iostream>
#include <level.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <Quiz.h>
#include <cwchar>

using namespace std;
/*static void changeFont(int n)
    {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = 0;                   // Width of each character in the font
        cfi.dwFontSize.Y = n;                  // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
        std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }*/
static void welcome(){
    cout<<"========================================================="<<endl;
    cout<<"           ***WELCOME TO QUIZ APPLICATION***             "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"         *The Introduction to Java Programming*          "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"         Developed  by  Olothando  &  Lusanda            "<<endl;
    cout<<"=========================================================\n"<<endl;

}
void instruction(){
    system("cls");
    cout<<"***************************************************INSTRUCTIONS***************************************************\n"<<endl;
    cout<<"-This Quiz consist of 3 Levels with questions in each, the number of questions varies per level, as levels ";
    cout<<"\n increase the number of questions increase and they get harder.\n";
    cout<<"-The type of Questions in this Quiz Game are Multiple-choice and True/False questions\n"<<endl;
    cout<<"1. Please use NUMBERS ONLY as OPTIONS in this quiz.\n2. Please Press ENTER after entering OPTION"<<endl;
    cout<<"3. At the end of each Level you will be provided with 3 options\n   1. To review the level(Review) this option will help you see where you went wrong and the correct answer"<<endl;
    cout<<"   correct answers will be marked Green and incorrect ones will be marked Red\n   2. To navigate to the next level if you passed the previous one else retake the level."<<endl;
    cout<<"   3. To Quit  this will help you exit the quiz Game if you don't want to take another level."<<endl;
    cout<<"4. Each Question weights 5 marks.\n";
    cout<<"\n***************************************************GOOD LUCK***************************************************\n";
    system("pause");
}

int main()
{


    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    //changeFont(40);
    SetConsoleTextAttribute(h,11);
    welcome();
    SetConsoleTextAttribute(h,15);
    //changeFont(24);

    Quiz q;
    q.register_p();
    instruction();
    q.mainMenu();

    return 0;
}
