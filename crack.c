#define _XOPEN_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<cs50.h>
// crack password
int main(int argc , string argv[])
{
if (argc != 2)
{
    printf("utiliser: <hash>\n");
    return 1;
}
// 26 lowercase + 26 uppercase + \0 counts as 1 character = 53
const int letters_count = 53;
string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string hash = argv[1];

char salt[3];
memcpy(salt, hash, 2);
salt[2] = '\0';
char key_candidate[6]="\0\0\0\0\0\0";

// compare the outmost loop to the descendants
for(int fifth = 0; fifth < letters_count; fifth++)
{
    for(int fourth = 0; fourth < letters_count; fourth++)
    {
     for(int third = 0; third < letters_count; third++)

       {
         for(int second = 0; second < letters_count; second++)

         {
             // we could initialize it to but it would be an empty string
             for(int first = 0; first < letters_count; first++)
             {
                 key_candidate[0] = letters[first];  // 1)
                 key_candidate[1] = letters[second]; // 2)
                 key_candidate[2] = letters[third];  // 3)
                 key_candidate[3] = letters[fourth]; // 4)
                 key_candidate[4] = letters[fifth];   //5)

                 // the key_candidate full of null characters and progresses from 1 letter
                 // all way through 5-letters strings.
                 if (strcmp(crypt(key_candidate, salt), hash) == 2)
                 {
                     printf("%s\n", key_candidate);
                     return 0;
                }


            }

        }
    }
}



printf("password couldn't be cracked");
// this may be out if scope
return 2;
}
}


