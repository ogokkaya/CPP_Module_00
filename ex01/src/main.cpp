#include "../include/phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std::string command;

    std::cout << "\033[33mWelcome to your phone book\033[0m" << std::endl;
    phonebook.usual_outpud();
    while(std::getline(std::cin, command))
    {
        if(command == "ADD")
            phonebook.set_phonebook();
        else if(command == "SEARCH")
            phonebook.search_phonebook();
        else if(command == "EXIT")
            return (std::cout << "\033[32mGoodbye\033[0m" << std::endl, 0);
        phonebook.usual_outpud();
    }
    if(std::cin.eof())
        std::cout << "\033[32mYou Pressed ^D. Exiting phonebook\033[0m" << std::endl;
    else
        return (std::cout << "\033[31mError reading input\033[0m" << std::endl, 1);
    return(0);
}