#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//function prototype
int check_key(int argc, string argv[]);

int main(int argc, string argv[])
{
    int valid_key = check_key(argc, argv);
    
    if (valid_key == 1)
    {
        return 1;
    }

    //get input from user
    string pt = get_string("plaintext: ");

    printf("ciphertext: ");

    //cypher each character of the plain text according to the key
    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        int b, d;
        if (isupper(pt[i]))
        {
            b = (int)argv[1][(pt[i] - 65)];
            if (isupper(b))
            {
                printf("%c", b);
            }
            else
            {
                d = toupper(b);
                printf("%c", d);
            }
        }
        else if (islower(pt[i]))
        {
            b = (int)argv[1][(pt[i] - 97)];
            if (islower(b))
            {
                printf("%c", b);
            }
            else
            {
                d = tolower(b);
                printf("%c", d);
            }
        }
        else
        {
            //non alphabetic characters stay the same
            printf("%c", pt[i]);
        }
    }
    printf("\n");
}

//checking if user provided valid key
int check_key(int argc, string argv[])
{
    //if command line argument is provided
    if (argc != 2)
    {
        printf("Please enter the key that consist of 26 unique alphabetic characters\n");
        return 1;
    }
    
    //if key contains 26 characters
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    
    //if all characters are alphabetic and unique
    //defining new array 
    int char_set[26] = {0};

    for (int j = 0, m = strlen(argv[1]); j < m; j++)
    {
        //if character is alphabetic
        if (isalpha(argv[1][j]))
        {
            //converting all lower case to upper case 
            int upper;
            if (islower(argv[1][j]))
            {
                upper = toupper(argv[1][j]);
            }
            else
            {
                upper = argv[1][j];
            }
            
            //checking corresponding index in the array to character of the key
            if (char_set[(upper - 65)] == 0)
            {
                char_set[(upper - 65)] = 1;
            }
            else
            {
                printf("Key must contain unique characters\n");
                return 1;
            }
             
        }
        else
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }
    }
    return 0;
}
