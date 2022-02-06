// PasswordGenerator.cpp : This Program Was Built By Me, I'm trying to learning CPP with converting Python Language to CPP,
//                         Next release i'll add some GUI. Thanks For Supporting Me.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main()
{
    // Password Generator
    char fileOption;
    std::cout << "Loading password generator...\n\n";
    statement:
    std::cout << "Would you like to use a separate file? (y/n) \n";
    std::cin >> fileOption;
    if (fileOption != 'y' && fileOption != 'n' && fileOption != 'Y' && fileOption != 'N') 
    {
        goto statement;
    }
    if (fileOption == 'y' && fileOption == 'n' && fileOption == 'Y' && fileOption == 'N')
    {
        goto generator;
    }

    generator:
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*(){}[]_-+=:;<>?~ ";
    std::string password;
    int length, rNum;

    std::ofstream out_file;
    out_file.open("Password.txt");

    std::cout << "How many password length do you want?\n";
    std::cin >> length;

    srand(time(NULL));

    for (int i = 1; i <= length; i++)
    {
        rNum = rand() % 64 + 1;

        if (fileOption == 'y' || fileOption == 'Y') {
            out_file << characters[rNum];
            std::cout << "Done\n\n";
        }
        else if (fileOption == 'n' || fileOption == 'N') {
            std::cout << characters[rNum];
            std::cout << "\0";
        }
        
    }


    char reload;
    reload:
    std::cout << std::endl << "Do you wanna generate password again? (y/n) \n";
        std::cin >> reload;
        if (reload == 'y' || reload == 'Y') {
            goto statement;
        }
        else if (reload == 'n' || reload == 'N') {
            std::cout << "Thanks For Using This Program \n";
            std::cout << std::endl << "Closing Program...";
        }
        else {
            std::cout << "Wrong Character\n";
            goto reload;
        }
}
