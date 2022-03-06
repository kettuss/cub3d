//
// Created by Iraida Kathrine on 3/2/22.
//

#include "../includes/cub_3D.h"

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
    if (i == 7)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Are you sure that the required file is located on the path indicated in the map? It's impossible to read it!");
    }
    if (i == 8)
    {
        printf("%s\n", "Error");
        printf("%s\n", "The file is not available at the specified path. Come on in, bro!! Please provide the correct link :)))");
    }
    if (i == 9)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Your file did not pass another check!!! Check that the file before the map contains all the necessary parameters");
    }
    if (i == 10)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Check if you really have 3 colors in F and C parameters!!");
    }

    if (i == 11)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Hey bro!! Colors in F or C are outside the [0; 255] range. Fix it!!");
    }
    if (i == 12)
    {
        printf("%s\n", "Error");
        printf("%s\n", "Oh no!! Memory allocation error bro :(((");
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
