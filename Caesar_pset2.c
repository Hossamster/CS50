#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
bool check(string s);
int main(int argc, string argv[])
{
   
    //if arg counter = 2 and argv[1] is number go ahead
    if (argc == 2 && check(argv[1]))
    {
        string plain_text = get_string("plaintext: ");
    
        int num = strlen(plain_text);
        
        printf("ciphertext: "); 
        
        for (int i = 0; i < strlen(plain_text); i++)
        {
            if (isalpha(plain_text[i]))
            
            {
                
                if (isupper(plain_text[i])) //upper begins from 65
                {
                   
                    printf("%c", (((plain_text[i] + atoi(argv[1])) - 65) % 26) + 65);
                }
                
                else if (islower(plain_text[i])) //lower begins from 97
                {
                    printf("%c", (((plain_text[i] + atoi(argv[1])) - 97) % 26) + 97);
                }
                
            }
            else
            {
                printf("%c", plain_text[i]);
            }
        }
        printf("\n");
        
    }
    
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
   
}

bool check(string s)
{
    int len = strlen(s); 
    
    int count = 0;
    
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            count++;
        }
    }
    
    // printf ("ur count is %d \n",count);
    
    if (len == count)
    {
        printf("success\n");
        return true;
    }
    
    else 
    {
        // printf("not okay\n");
        return false;
    }
}