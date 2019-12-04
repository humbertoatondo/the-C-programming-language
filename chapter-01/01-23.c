/*
 * Write a program to remove all comments form a C program.
 * Don't forget to handle quoted strings and character
 * constants properly. C comments do not nest.
 */

#include <stdio.h>

FILE *fileIn;
FILE *fileOut;

void removeComments();

// This is a test comment
//Other test comment
int main()
{
    fileIn = fopen("./01-23.c", "r");
    fileOut = fopen("./01-23-out.c", "w+");

    removeComments();

    fclose(fileIn);
    fclose(fileOut);
}

/* removeComments: copy fileIn to fileOut with comments removed */
void removeComments()
{
    int cFlag, mcFlag;
    if (fileIn)
    {
        cFlag = mcFlag = 0;
        int c, cn;
        while ((c = fgetc(fileIn)) != EOF)
        {
            if (cFlag == 0 && mcFlag == 0 && c == '/') {
                if ((cn = fgetc(fileIn)) == '/') {
                    cFlag = 1;
                } else if (cn == '*') {
                    mcFlag = 1;
                } else {
                    fputc(c, fileOut);
                    fputc(cn, fileOut);
                }
            } else if (mcFlag == 1 && c == '*') {
                if ((cn = fgetc(fileIn) == '/')) {
                    mcFlag = 0;
                    if ((c = fgetc(fileIn)) != '\n') {
                        fputc(c, fileOut);
                    }
                }
            } else if (cFlag == 1 && c == '\n') {
                cFlag = 0;
            } else if (cFlag == 0 && mcFlag == 0) {
                fputc(c, fileOut);
            }
        }
    }
    else
    {
        printf("Invalid file\n");
    }
}