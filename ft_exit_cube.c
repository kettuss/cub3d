//
// Created by Iraida Kathrine on 3/2/22.
//

#include "cub.h"

void    exit_cube(int i)
{
    if (i == 4)
    {
        printf("%s\n", "Error");
        printf("%s\n", "You have not selected a file to build the map. Do it right now!!");
    }
    if (i == 5)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Too many arguments. Just choose one file!");
    }
    if (i == 6)
    {
        printf("%s\n", "Error");
        printf("%s\n", "OMG!! I can't read your file. Is it really okay?");
    }
    if (i == 1)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Your card is wrong. Check it and start the program again");
    }
    if (i == 2)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Congratulations!!!! You did it!!!! You won!!!");
    }
    if (i == 3)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Do not worry. Next time you win !!! I believe in you!!!");
    }
    exit(1);
}
