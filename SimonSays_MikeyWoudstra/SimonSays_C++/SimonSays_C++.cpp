// SimonSays_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h> 
#include <iostream>
#include <cstdlib>
#include <list>
#include <time.h>
#include <array>
#include <algorithm>
#include <iterator>
 
using std::cout;

int* tempArray;
int startValue;
int* nums;
bool gehaald;

unsigned seed = time(0);

int randomNumer() {
    int result = rand() % 9 + 1;
    return result;
}

void startUp(int amount) {
    nums = new (std::nothrow) int[amount];

    cout << "Remember the numbers!!\n";

    //displays the numbers, if a number in the array is 0 it will generate a new number, otherwise it will repeat
    for (int i = 0; i < amount; i++) {
        if (tempArray[i] != 0) {
            nums[i] = tempArray[i];
            cout << nums[i] << std::endl;
        }
        else {
            int num = randomNumer();
            cout << num << std::endl;
            nums[i] = num;
        }
    }
    
    //simple countdown
    cout << std::endl;
    cout << "4 Sec left!!\r";
    Sleep(1000);
    cout << "3 Sec left!!\r";
    Sleep(1000);
    cout << "2 Sec left!!\r";
    Sleep(1000);
    cout << "1 Sec left!!\r";
    Sleep(1000);

    //screen clear
    system("CLS");

    //Number checker to check if you fill in the correct number
    for (int i = 0; i < amount; i++) {
        int result;
        cout << "enter number" << i + 1 <<+ " from the row:";
        std::cin >> result;

        if (result == nums[i]) {
            cout << "Correct!" << std::endl;
            gehaald = true;
        }
        else {
            cout << "Jammer fout" << std::endl;
            i = startValue;
            gehaald = false;
        }
    }

    //if you survive the round it will reset the arrays here and redo the main array with a bigger size than before.
    if (gehaald) {
        tempArray = NULL;
        delete[] tempArray;
        system("CLS");

        int newAmount = amount + 1;
        tempArray = new (std::nothrow) int[newAmount];

        for (int n = 0; n < amount; n++) {
            tempArray[n] = nums[n];
        }
        tempArray[amount] = 0;
        
        nums = NULL;
        delete[] nums;

        gehaald = false;
        startValue = startValue + 1;
        startUp(startValue);
    }
    else {
        system("pause");
    }
}

//Set seed for random number, Makes an empty temp array at start. This is to store numbers from main array to clear it and refil a bigger main array
int main()
{
    srand(seed);

    startValue = 3;
    tempArray = new (std::nothrow) int[startValue];

    for (int i = 0; i < startValue; i++) {
        tempArray[i] = 0;
    }

    
    startUp(startValue);
}
