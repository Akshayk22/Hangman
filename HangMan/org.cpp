#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
void PrintMessage(string message, bool printTop = true, bool printBottom = true) //Draw that Box
{
    if (printTop) //Prints the top lines.
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
       else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();
 
    if (printBottom) //Print the bottom border.
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}
void Hangman(int ACount = 0)
{
    if (ACount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
 
    if (ACount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
 
    if (ACount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);
 
    if (ACount == 4)
        PrintMessage("/  ", false, false);
    
    if (ACount == 5)
        PrintMessage("/| ", false, false);
 
    if (ACount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);
 
    if (ACount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
 
    if (ACount == 8)
        PrintMessage("/", false, false);
 
    if (ACount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}
void PrintLetters(string input, char from, char to) //Display or print all alphabets from A-Z.
{
    string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == string::npos)  //npos means it didn't find the character.
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);
}
void PrintAvailableLetters(string taken)  //It prints all the availabe letters.
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}
bool PrintWordAndCheckWin(string word, string guessed)  //Actual word to be guessed and also to match the guessed word.
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}
string LoadRandomWord(string path)  //Load teh random words.
{
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if (reader.is_open())
    {
        while (std::getline(reader, word))
            v.push_back(word);
 
        int randomLine = rand() % v.size();
 
        word = v.at(randomLine);
        reader.close();
    }
    return word;
}
int TriesLeft(string word, string guessed) //Tells us how many time the user has guessed the word.
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}
int main()
{
    srand(time(0));
    string guesses; //contains the lettes that the user has typerd.
    string wordToGuess;
    wordToGuess = LoadRandomWord("words.txt"); //File name to load the word from the repective file.
    int tries = 0;
    bool win = false;
    do
    {
        system("cls"); //replace this line with system("clear"); if you run Linux or MacOS
        PrintMessage("THE HANGMAN GAME");
        Hangman(tries);
        PrintAvailableLetters(guesses); //get the available letters.
        PrintMessage("Guess the word");
        win = PrintWordAndCheckWin(wordToGuess, guesses);
 
        if (win)
            break;
 
        char x;
        cout << ">"; cin >> x;
 
        if (guesses.find(x) == string::npos)
            guesses += x;
 
        tries = TriesLeft(wordToGuess, guesses);
 
    } while (tries < 10);
 
    if (win)
        PrintMessage("YOU WON!");
    else
        PrintMessage("GAME OVER");
 
    system("pause"); //this line wont work on Linux or MacOS so remove it
    getchar();
    return 0;
}