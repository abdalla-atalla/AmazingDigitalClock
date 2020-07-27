//  main.cpp
//  AmazingDigitalClock
//  This program is written by Abdalla Atalla and finished on 11/8/19. This program will ask the user to input a time in the format of HH:MM then based on the time that was entered the program will display if it is a lucky or normal time based on whether or not if the sum of the hours is equal to the sum of the minutes. Then the program will tell if the time carries a special meaning such as same digits or ascending/descending order. Lastly, the program will ask if the user wishes to enter another time or exit the program.
//  Created by Abdalla Atalla on 11/4/19.
//  Copyright © 2019 Abdalla Atalla. All rights reserved.

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string getEntry()
{
    string entry;
    cout << endl
         << "Enter a time (HH:MM):";
    cin >> entry;
    return entry;
}
bool isValid(string entry)
{
    if (entry.size() != 5 && entry.size() != 4)
    {
        return false;
    }
    if (entry.size() == 4)
    {
        entry.insert(0, "0");
    }
    if (entry.at(2) != ':')
    {
        return false;
    }
    if (entry.at(0) != '0' && entry.at(0) != '1')
    {
        return false;
    }

    if (entry.at(0) == '0')
    {
        if (entry.at(1) < '0' || entry.at(1) > '9')
        {
            return false;
        }
    }

    if (entry.at(0) == '1')
    {
        if (entry.at(1) < '0' || entry.at(1) > '2')
        {
            return false;
        }
    }
    if (entry.at(3) < '0' || entry.at(3) > '5')
    {
        return false;
    }
    if (entry.at(4) < '0' || entry.at(4) > '9')
    {
        return false;
    }
    return true;
}
void luckyTime(string entry)
{
    cout << endl
         << entry;
    if (entry.size() == 4)
    {
        entry.insert(0, "0");
    }
    int hourTenth = stoi(entry.substr(0, 1));
    int hourOnes = stoi(entry.substr(1, 1));
    int minuteTenth = stoi(entry.substr(3, 1));
    int minuteOnes = stoi(entry.substr(4, 1));
    if (hourTenth + hourOnes == minuteTenth + minuteOnes)
    {
        cout << " is a lucky time.";
    }
    else
    {
        cout << " is a normal time.";
    }
}
void prediction(string entry)
{
    if (entry.size() == 4)
    {
        if (entry.at(0) == entry.at(2) && entry.at(2) == entry.at(3))
        {
            cout << " BINGO! Go buy a lottery ticket." << endl;
        }
        else if (entry.at(0) + 1 == entry.at(2) && entry.at(2) + 1 == entry.at(3))
        {
            cout << "  -> UP! All dreams will come true." << endl;
        }
        else if (entry.at(0) - 1 == entry.at(2) && entry.at(2) - 1 == entry.at(3))
        {
            cout << "  -> DOWN! The challenging road is ahead." << endl;
        }
    }
    else
    {
        if (entry.at(0) == entry.at(1) && entry.at(1) == entry.at(3) && entry.at(3) == entry.at(4))
        {
            cout << " BINGO! Go buy a lottery ticket." << endl;
        }
        else if (entry.at(0) + 1 == entry.at(1) && entry.at(1) + 1 == entry.at(3) && entry.at(3) + 1 == entry.at(4))
        {
            cout << "  -> UP! All dreams will come true." << endl;
        }
        else if (entry.at(0) - 1 == entry.at(1) && entry.at(1) - 1 == entry.at(3) && entry.at(3) - 1 == entry.at(4))
        {
            cout << "  -> DOWN! The challenging road is ahead." << endl;
        }
    }
}
int main()
{

    string userInput;
    string answer = "y";
    bool valid;

    while (answer == "y" || answer == "Y")
    {
        userInput = getEntry();
        valid = isValid(userInput);
        while (!valid)
        {
            cout << "Invalid format, try again with the correct format (HH:MM)" << endl;
            cin >> userInput;
            valid = isValid(userInput);
        }
        luckyTime(userInput);
        prediction(userInput);

        cout << endl
             << endl
             << "Run again (y/n)? ";
        cin >> answer;
        valid = false;
    }
    cout << endl
         << "Programmer~~ Abdalla Atalla C++ CISC 192" << endl
         << "Goodbye!" << endl;
    return 0;
}
