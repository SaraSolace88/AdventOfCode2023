#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.

int NumberInString(string str){
    if(str.find("one") > 0){
        return 1;
    }else if(str.find("two") > 0){
        return 2;
    }else if(str.find("three") > 0){
        return 3;
    }else if(str.find("four") > 0){
        return 4;
    }else if(str.find("five") > 0){
        return 5;
    }else if(str.find("six") > 0){
        return 6;
    }else if(str.find("seven") > 0){
        return 7;
    }else if(str.find("eight") > 0){
        return 8;
    }else if(str.find("nine") > 0){
        return 9;
    }
    return 0;
}

int main()
{
    int sum, first, last;
    string currLine, currLetters;

    // Read from the text file
    ifstream MyReadFile("Day1SmallTest.txt");

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
                        currLetters.clear();
                    }else{
                        first = tmp;
                        last = tmp;
                        currLetters.clear();
                    }
                }else{
                    last = currLine[b] - '0';
                    currLetters.clear();
                }
            }else{
                currLetters += currLine[b];
            }
        }
        if(currLetters != ""){
            int tmp = NumberInString(currLetters);
            if(tmp != 0){
                last = tmp;
                currLetters.clear();
            }
        }
        last += first * 10;
        cout << last;
        cout << "\n";
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