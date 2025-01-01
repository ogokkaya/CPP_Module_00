#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

int main(int ac , char **av)
{
    if(ac > 1)
    {
        for(int i = 1; av[i]; i++)
        {
            for(int j = 0 ; av[i][j]; j++)
            {
                if(isalpha(av[i][j]))
                    cout << (char)toupper(av[i][j]);
                else
                    cout << av[i][j];
            }
        }
    }
    else
        return(cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl, 1);
    return(cout << endl ,0);
}