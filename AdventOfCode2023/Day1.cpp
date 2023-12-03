#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.

int NumberInString(string str){
    int tmp;
    int rtnPos = -1;
    int rtnValue = 0;

    tmp = str.find("one");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 1;
    }
    tmp = str.find("two");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 2;
    }
    tmp = str.find("three");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 3;
    }
    tmp = str.find("four");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 4;
    }
    tmp = str.find("five");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 5;
    }
    tmp = str.find("six");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 6;
    }
    tmp = str.find("seven");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 7;
    }
    tmp = str.find("eight");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 8;
    }
    tmp = str.find("nine");
    if(tmp != string::npos && tmp > rtnPos){
        rtnPos = tmp;
        rtnValue = 9;
    }
    return rtnValue;
}

int main()
{
    int sum, first, last;
    string currLine, currLetters;

    // Read from the text file
    ifstream MyReadFile("Day1.2SmallTest.txt");

    //while 
    while (getline (MyReadFile, currLine)) {
        first = -1;
        last = -1;
        currLetters.clear();
        // Output the text from the file
        for(int b = 0; b < currLine.length(); b++){
            if(currLine[b] >= 48 && currLine[b] <= 57){
                if(first == -1){
                    int tmp = NumberInString(currLetters);
                    if(tmp == 0){
                        first = currLine[b] - '0';
                        last = currLine[b] - '0';
                    }else{
                        first = tmp;
                        last = tmp;
                    }
                    currLetters.clear();
                }else{
                    last = currLine[b] - '0';
                    currLetters.clear();
                }
            }else{
                currLetters += currLine[b];
                if(first == -1){
                    int tmp = NumberInString(currLetters);
                    if(tmp != 0){
                        first = tmp;
                        last = tmp;
                    }
                }
            }
        }
        if(currLetters != ""){
            int tmp = NumberInString(currLetters);
            if(tmp != 0){
                last = tmp;
            }
        }
        last += first * 10;
        sum += last;
        }
        cout << sum;
}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file