
// Caesar cipher - offset letters and digits by specified key (character)
//
#include <stdio.h>
#define Max 100

void encrypt(char str[Max],int wordCount,char charcter[36],int key);
void decrypt(char str[Max],int wordCount,char character[36],int key);

int main()
{
    char mode = 0;
    char dummy = 0;
    int key = -1;
    char  character[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    char text[100]; // to store the input string
    char letter; // to take input string as letter by letter
    int loopCount = 0;
    int wordCount = 0;
    // Get information from user -- encrypt/decrypt mode and key

    // does not check for errors: assumes user will enter 'e' or 'd' only
    printf("Enter mode -- encrypt (e) or decrypt (d): ");
    fflush(stdout);
    scanf("%c", &mode);
    while ((key < 0) || (key > 35))
    {
        printf("Enter key (0-35): ");
        fflush(stdout);
        scanf("%d", &key);
    }
    scanf("%*c");  // read and ignore linefeed after key
    printf("Enter text, ending with ##:\n");
    fflush(stdout);
    while(loopCount == 0)
        {
           scanf("%c",&letter);
             text[wordCount] = letter;
             if(wordCount >0)
             {
                 if((text[wordCount]== '#')&&(text[wordCount-1] == '#'))
                    {
                        loopCount++;
                    }
             }
             wordCount++;
        }
        int count = 0;
        char str[wordCount];// this only contains letters
        for(int i = 0;i<wordCount;i++)
            {
                if((isalpha(text[i]) != 0)||(isdigit(text[i]) != 0))
                {
                   str[count] = text[i];
                   count++;
                }
             }
     if(mode == 'e')
        {
           encrypt(str,count,character,key);
        }
    else if(mode == 'd')
        {
            decrypt(str,count,character,key);
        }
    else
        {
            printf("Wrong mode entered");
        }
    // Read input one character at a time
    // Encrypt or decrypt, according to mode
    // Print as described in program spec
    return 0;
}

void encrypt(char str[Max],int wordCount,char character[36],int key)
{

    char letter;
    char newText[wordCount];
    for(int i = 0;i< wordCount;i++)
        {
            letter = toupper(str[i]);
            int found = 0;
            for(int j = 0;j<36;j++)
                {

                    if(letter  == character[j])
                        {

                            if(j+key<=35)
                            {
                               newText[i] = character[j+key];
                               found++;
                            }
                            else
                            {
                                newText[i] = character[j+key-36];
                                found++;
                            }

                        }
                }
                if(found == 0)
                    {
                        newText[i] = letter;
                    }

        }
        //printf("%s",newText);
        int spaceCount = 0;
        int letterCount = 0;
        for(int i = 0;i<wordCount;i++)
            {
                printf("%c",newText[i]);
                letterCount++;
                if(letterCount == 4)
                    {
                        letterCount = 0;
                         printf(" ");
                         spaceCount++;
                    }
                if(spaceCount == 5)
                    {
                        spaceCount = 0;
                        printf("\n");
                    }
            }
}

void decrypt(char str[Max],int wordCount,char character[36],int key)
{
    char letter;
    char newText[wordCount];
    for(int i = 0;i< wordCount;i++)
        {
            letter = str[i];
            int found = 0;
            for(int j = 0;j<36;j++)
                {
                    if(letter  == character[j])
                        {
                            if(j-key >=0)
                            {
                               newText[i] = character[j-key];
                               found++;
                            }
                            else
                            {
                                newText[i] = character[j-key+36];
                                found++;
                            }

                        }
                }
                if(found == 0)
                    {
                        newText[i] = letter;
                    }

        }
        int spaceCount = 0;
        int letterCount = 0;
        for(int i = 0;i<wordCount;i++)
            {
                printf("%c",newText[i]);
                letterCount++;
                if(letterCount == 4)
                    {
                        letterCount = 0;
                         printf(" ");
                         spaceCount++;
                    }
                if(spaceCount == 5)
                    {
                        spaceCount = 0;
                        printf("\n");
                    }
            }
}
