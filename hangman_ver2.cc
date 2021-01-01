#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

string hang[10] = {"STRING", "ARRAY", "INTEGER", "FLOAT", "LIBRARY", "VARIABLE", "POINTER", "ADDRESS", "NAMESPACE", "FUNCTION"};
string userword = {"000000000"};
int chances = 15;

void Word(string word){

    string userinput;

            cout << "What is your guess?" << endl;
            cin >> userinput;
            if(userinput.compare(word) != 0){
              cout << "Wrong guess. Try again." << endl;
              chances -= 1;
              cout << "Chances left: " << chances << endl;
            }
            else{
              cout << "Amazing! That was correct!" << endl;
            }

    return;
}

void Letter(string wd, string usrwd){

            char letter;

            cout << "What is the letter you are guessing?" << endl;
            cin >> letter;

            for(int i = 0;i<wd.length();i++){
              if(wd[i] == letter){
                cout << i+1 << ". Correct." << endl;
                usrwd.at(i) = letter;
              }

              else{
                cout << i+1 << ". Wrong" << endl;
              }
            }
            chances -= 1;
            cout << "The word so far: " << usrwd << endl;
            /*for(int i = 0; i< wd.length(); i++){
              cout << usrwd[i];
            }*/
            //cout << "\n";
            cout << "Chances left: " << chances << endl;

}




int main(){

    string start, word, userinput;
    string end, End("No"), END("no");
    int guess, input;


    cout << "\nWelcome to the Hangman game." << endl;
    cout << "The theme of the words used is PROGRAMMING SYNTAX." << endl;
    cout << "The words used are: 'STRING', 'ARRAY', 'INTEGER', 'FLOAT', 'LIBRARY', 'VARIABLE', 'POINTER', 'ADDRESS', 'NAMESPACE', 'FUNCTION'" << endl;
    cout << "The letters are case sensitive, so please input in CAPITALS." << endl;
    

    while(end.compare(End) != 0 && end.compare(END) !=0){

        int input;
        srand(time(NULL));
        guess = rand() % 10;
        word = hang[guess];

        chances = 15;

        do{

            cout << "\nYou have " << chances << " chances." << endl;
            cout << "Do you wish to guess a letter or the entire word?" << endl;
            cout << "1. Word" << endl;
            cout << "2. Letter" << endl;
            cout << "3. I quit." << endl;

            cin >> input;

            switch (input){

                case 1:
                // WORD function goes here
                Word(word);
                break;

                case 2:
                // LETTER function goes here
                Letter(word, userword);
                break;

                case 3:
                    chances = 0;
                    break;

            }

        }while(chances != 0);

        cout << "\nThe word was: " << word << endl;
        cout << "Do you wish to play again? (Yes/No)" << endl;
        cin >> end;

    }

    cout << "\nThank you for playing Hangman." << endl;
    cout << "ver 1.0 ca: 2019" << endl;

    return 0;

}