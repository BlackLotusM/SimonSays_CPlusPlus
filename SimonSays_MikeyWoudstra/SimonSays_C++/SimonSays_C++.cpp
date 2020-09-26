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
 
using namespace std;

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
    nums = new (nothrow) int[amount];

    cout << "Remember the numbers!!\n";

    for (int i = 0; i < amount; i++) {
        if (tempArray[i] != 0) {
            nums[i] = tempArray[i];
            cout << nums[i] << endl;
        }
        else {
            int num = randomNumer();
            cout << num << endl;
            nums[i] = num;
        }
    }
    
    cout << endl;
    cout << "4 Sec left!!\r";
    Sleep(1000);
    cout << "3 Sec left!!\r";
    Sleep(1000);
    cout << "2 Sec left!!\r";
    Sleep(1000);
    cout << "1 Sec left!!\r";
    Sleep(1000);

    system("CLS");

    for (int i = 0; i < amount; i++) {
        int result;
        cout << "enter number" << i + 1 <<+ " from the row:";
        cin >> result;

        if (result == nums[i]) {
            cout << "Correct!" << endl;
            gehaald = true;
        }
        else {
            cout << "Jammer fout" << endl;
            i = startValue;
            gehaald = false;
        }
    }

    if (gehaald) {
        tempArray = NULL;
        delete[] tempArray;
        system("CLS");

        tempArray = new (nothrow) int[amount + 1];

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

int main()
{
    startValue = 3;
    tempArray = new (nothrow) int[startValue];

    for (int i = 0; i < startValue; i++) {
        tempArray[i] = 0;
    }

    srand(seed);
    startUp(startValue);
}
