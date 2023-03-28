#include<iostream.h>
#include<vector>
#include "hangman_functions.h"

using namespace std;
int main()
{
   greet();  //Tells what's going on and what is the objective of the game

   string codeword = "codingcleverly";
   string answer = "_____________";

   int misses=0;
   vector<char> incorrect;
   bool guess = false;
   char letter;


   while(answer!=codeword && misses < 7)
   {
    display_misses(misses);
    display_status(incorrect, answer);

    cout<<"\n\nPlease enter your guess:";
    cin>>letter;  //Inputs the guess

    for(int i=0;i<codeword.length(); i++)
    {
        if(letter==codeword[i])
        {
            answer[i] = letter;
            guess = true;
        }
    }
    if(guess)
    {
        cout<<"\nCorrect!!\n";
    }
    else 
    {
        cout<<"\nIncorrect! Another portion of the person has been drawm.\n";
        incorrect.push_back(letter);
        misses++;
    }
    guess = false;
   }

   end_game(answer, codeword);
    return 0;
}