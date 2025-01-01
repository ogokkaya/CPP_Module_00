#include "../include/phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->full = false;
    this->index = 0;
}

void Phonebook::usual_outpud(void)
{
    std::cout << "Enter your command [ADD <-> SEARCH <-> EXIT]" << std::endl;
    std::cout << "* ";
}

void Phonebook::set_phonebook(void)
{
    std::string input;
    if(this->full == false)
    {
        std::cout << "\033[31mThis is your contact # " << this->index + 1 << "\n\033[0m";
        this->contact[this->index].set_contact();
        if(this->index == 7)
            this->full = true;
        else
            this->index++;
    }
    else
    {
        std::cout << "\033[33mYour phonebook is full.\033[0m\n" << "\033[33mIf you want to add a new contact, your oldest saved contact will be deleted\033[0m\n";
        std::cout << "\033[mIf you want to proceed, press '1' and confirm with 'enter'\nif not, press anything but '1' and confirm with 'enter' to go back to main menu.\n";
        while(std::getline(std::cin, input))
        {
            if(!input.compare("1"))
            {
                for(int i = 1; i < 8 ; i++)
                    this->contact[i - 1] = this->contact[i];
                std::cout << "This is your contact # " << this->index + 1 << std::endl;
                this->contact[this->index].set_contact();
                return;
            }
            else
                return(std::cin.clear());
        }
        if(std::cin.eof())
            return (std::cout << "You Pressed ^D. Exiting phonebook" << std::endl, std::exit(0));
        else
            return (std::cout << "Error reading input" << std::endl, std::exit(1));
    }

}

void Phonebook::search_phonebook(void)
{
    int index;

    if(this->index == 0)
    {
        std::cout << "Please add at least one contact before searching." << std::endl;
        return;
    }
    else
    {
        std::string input;
        std::cout << "\033[33mPress 9 to see your entire phone book (0 to quit searching)\033[0m" << std::endl;
        std::cout << "\033[33mEnter index for detailed person information between (1 - 8) \033[0m" << "\n* ";
        while(std::getline(std::cin, input))
        {
            if(input == "0")
                return;
            index = std::atoi(input.c_str());
            if(index == 0 || index > 9)
                std::cout << "\n\033[31mNot found";
            if(index == 9)
            {
                std::cout << "\n|-------------------------------------------|" << std::endl;
                std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
                std::cout << "|----------|----------|----------|----------|" << std::endl;
                for(int i = 0; i <= this->index; i++)
                {
                    Phonebook::contact[i].get_contact(i + 1, 9);
                }
            }
            else if(index < 9 && index > 0)
            {
                Phonebook::contact[index - 1].get_contact(index, 0);
                std::cout << std::endl;
            }
             std::cout << "\033[33m\nPress 9 to see your entire phone book (0 to quit searching)\033[0m" << std::endl;
            std::cout << "\033[33mEnter index for detailed person information between (1 - 8) \033[0m" << "\n* ";
        }
        if(std::cin.eof())
            return (std::cout << "\nYou Pressed ^D. Exiting phonebook." << std::endl, std::exit(0));
        else
            return (std::cout << "\nError reading input" << std::endl, std::exit(0));
    }
}
