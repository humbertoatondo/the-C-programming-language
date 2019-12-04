/*
 * Write a program entab that replaces tabs in the input with
 * the proper number of blanks to achieve the same spacing. Use 
 * the same tabs stops as for detab. When either a tab or a
 * single blank would suffice to reach a tab stop, which should
 * be given preference.
 */

#include <stdio.h>

#define MAXSIZE 1000
#define TABWIDTH 8

char line[MAXSIZE];
char newLine[MAXSIZE];

int getLine();
void entab(int len);

int main()
{
    printf("All blank spaces ar represented with '-'.\n");
    int len;
    while ((len = getLine()) > 0) {
        entab(len - 1);
        printf("%s", line);
        printf("%s", newLine);
    }
}

/* getLine: read a line into line */
int getLine()
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = '-';
    }
    if (c == '\n') {
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i;
}

/* entab: replaces spaces with tabs */
void entab(int k)
{
    int i, j;
    for (i = 0; i < (k / TABWIDTH); ++i) {
        newLine[i] = '\t';
    }
    int cal = (k % TABWIDTH);
    for (j = i; (j - i) < cal; j++) {
        newLine[j] = '-';
    }
    newLine[j++] = '\n';
    newLine[j] = '\0';
}