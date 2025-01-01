#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>


class Contact
{
    private:
        static std::string field_names[5];
        std::string informations[5];
    
        enum field
        {
            FirstName,
	        LastName,
	        Nickname,
	        PhoneNumber,
	        DarkestSecret
        };
    public:
    
    void set_contact(void);
	void get_contact(int index, int flag)const;
};