#pragma once

#include "contact.hpp"

class Phonebook
{
    private:
        Contact contact[8];
        int index;
        bool full;

    public:
        Phonebook(void);
    
    void usual_outpud(void);
    void set_phonebook(void);
    void search_phonebook(void);
};