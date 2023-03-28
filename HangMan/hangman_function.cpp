#include<iostream>
#include<vector>
#include "hangman_functions.h"
using namespace std;
//define functions

void greet()
{
  std::cout<<"================\n";
  std::cout<<"Hangman: The Game\n";
  std::cout<<"================\n";
  std::cout<<"Instructions: Save your friend from being hanged by guessing the correct letters in the codeword.\n"
}

void display_misses(int misses)
{
    if(misses===0)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<" ========= \n";


    }
    else if(misses==1)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"  O    | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<" ========= \n";

    }
    else if(misses==2)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"  O    | \n";
      cout<<"  |    | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<" ========= \n";

    }
    else if(misses==3)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"  O    | \n";
      cout<<" /|    | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<" ========= \n";


    }
    else if(misses==4)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"  O    | \n";
      cout<<" /|\\  | \n";
      cout<<"       | \n";
      cout<<"       | \n";
      cout<<" ========= \n";


    }
    else if(misses==5)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"  O    | \n";
      cout<<" /|\\  | \n";
      cout<<" /     | \n";
      cout<<"       | \n";
      cout<<" ========= \n";


    }
    else if(misses==6)
    {
      cout<<"  +----+ \n";
      cout<<"  |    | \n";
      cout<<"  O    | \n";
      cout<<" /|\\  | \n";
      cout<<" / \\  | \n";
      cout<<"       | \n";
      cout<<" ========= \n";


    }
    

}


void display_status(vector<char> incorrect, string answer)
{
    cout<<"Incorrect Guesses: \n";

    for(int i=0; i<incorrect.size(); i++)  //Display's all content that is incorrect
    {
      cout<<incorrect[i]<<" ";

    }

    cout<<"\nCodeword:\n";

    for(int i=0; i<answer.length(); i++)
    {
       cout<<answer[i]<<" ";
    }
}


void end_game(string answer, string codeword)
{
    if(answer==codeword)
    {
        cout<<"Hurry!! You save the person from being hanged.";
        cout<<"Congratulations!\n";
    }
    else
    {
        cout<<"Oh no! The man is Hanged! \n";
    }
}