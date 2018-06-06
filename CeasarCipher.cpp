/*
*In cryptography, a Caesar cipher, also known as Caesar's cipher,
*the shift cipher, Caesar's code or Caesar shift, is one of the
*simplest and most widely known encryption techniques. It is a
*type of substitution cipher in which each letter in the plaintext
*is replaced by a letter some fixed number of positions down the alphabet.
*For example, with a left shift of 3, D would be replaced by A, E would
*become B, and so on. The method is named after Julius Caesar, who used
*it in his private correspondence.
*You can find more about this in wiki: https://en.wikipedia.org/wiki/Caesar_cipher
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

/*
*   Func "GenAlphabet" - generate latin alphabet
*/

void GenAlphabet(char* arr)
{
    for (int i = 0; i < 26; i++)
    {
        arr[i] = (char) (i + 97);
    }
}

/*
* Func "Transform" - find a replacing letter index in array "alphabet"
*/

int Transform(char* arr, char& symbol)
{
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == symbol)
        {
            if((i + 3) > 25)
            {
                return(i-23);
            }

            else{return(i+3);}
        }

    }
}

/*
*   Func "FileEncryption" - encrypt your file using the Caesar cipher
*/

int FileEncryption(char* alphabet)
{
    char inFileName[256];
    char outFileName[256];

    cout << "File for encrypt: ";
    cin.getline(inFileName, 256);

    cout << "\nOutput file: ";
    cin.getline(outFileName, 256);

    ifstream fromFile(inFileName);
    ofstream outFile(outFileName);

    if(!fromFile)
    {
        cerr << "\tFatal Error!\n" << "Can't open the file.\n";
        return(1);
    }

    char letter;    //In this variable will read the symbols one by one

    while((letter = fromFile.get()) != EOF) //Encrypt loop
    {
        if(!isalpha(letter))
        {
            outFile << letter;
        }

        else if(isupper(letter))
        {
            letter = tolower(letter);
            letter = toupper(alphabet[Transform(alphabet, letter)]);
            outFile << letter;
        }

        else
        {
            letter = alphabet[Transform(alphabet, letter)];
            outFile << letter;
        }
    }

    fromFile.close();
    outFile.close();
    return(0);
}


int main()
{
    char* alphabet = new char[26];

    GenAlphabet(alphabet);

    if(!FileEncryption(alphabet))
    {
        cout << "\tSuccess!\n"
        << "Your text was encrypted!\n";
    }


    delete[] alphabet;

    return(0);
}
