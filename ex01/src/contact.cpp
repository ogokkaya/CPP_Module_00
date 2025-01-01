#include "../include/contact.hpp"

std::string Contact::field_names[5] =
{
    "First Name      ",
	"Last Name       ",
	"Nick Name       ",
	"Phone Number    ",
	"Darkest Secret  "
};

void Contact::set_contact(void)
{
    for(int i = FirstName ; i <= DarkestSecret ; i++)
    {
        std::cout << "\033[34mPlease enter the " << this->field_names[i] << "\033[0m\n* ";
        while(!(std::getline(std::cin, this->informations[i])) || (this->informations[i].length() == 0))
        {
            if(std::cin.eof())
                return (std::cout << "\033[32mYou Pressed ^D. Exiting phonebook\033[0m" << std::endl, std::exit(0));
            else if(this->informations[i].length() == 0)
            {
                std::cout << "\033[31mEmpty contact information cannot be entered\033[0m" << std::endl;
                std::cout << "\033[34mPlease enter the " << this->field_names[i] << "\033[0m\n*";
                this->informations[i].clear();
            }
            else
                return (std::cout << "\033[31mError reading input\033[0m" << std::endl, std::exit(1));
        }
    }
    std::cout << "\033[32mThe process of adding a new person has been completed successfully\033[0m" << std::endl;
}

void    Contact::get_contact(int index, int flag) const
{
    if(flag == 9)
    {
        if(Contact::informations[0].length() == 0)
            return;
        std::cout << "|" << std::setw(10) << index;
        for(int i = FirstName ; i <= Nickname ; i++)
        {
            std::cout << "|";
            if(Contact::informations[i].length() > 10)
                std::cout << this->informations[i].substr(0, 9) << ".";
            else
                std::cout << std::setw(10) << this->informations[i];
        }
        std::cout << "|";
        std::cout << "\n|-------------------------------------------|\n";
    }
    else
    {
        for(int i = FirstName ; i <= DarkestSecret; i++)
        {
            if(Contact::informations[i].length() > 0)
            {
                std::cout << std::endl;
                if(i == 0)
                    std::cout << "-------------------------------------------" << std::endl;
                std::cout << Contact::field_names[i] << ": " << Contact::informations[i] << std::endl;
                std::cout << "-------------------------------------------";
            }
            else
            {
                std::cout << "\n\033[31mNot found";
                break;
            }
        }
    }
}
