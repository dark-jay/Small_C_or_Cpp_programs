//created by jay nath on 20.4.17
//this program read each line from a text file and modifies it as <md "text from .txt file">
//then creat a folder with system call with that paritcular name

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char str[1000000];
    char *p = str;

    char str_cpy[1000000]="";
    char *p2 = str_cpy;

    printf("Press Enter to Read: \n\n");
    getch();

    fp = fopen("input.txt", "r");
    if (fp == NULL) { /* Test for error */
        fprintf(stderr, "Error: Unable to input file 'input.txt'\n");
        exit(8);
    }
    printf("Reading of File Completed.\n");

    printf("Converting to recommended File started...\n");
    while(!feof(fp)){
        //first read the first line
        fgets(p, 200, fp);
        //printf("%s", p); commenting it because i dont wanna print the input list, if u want to, remove these //

        //wite <md "> after each loop
        *p2 = '\n'; p2++;
        *p2 = 'm'; p2++;
        *p2 = 'd'; p2++;
        *p2 = ' '; p2++;
        *p2 = '"'; p2++;

        //copy each character of the current line to new str_cpy variable
        while(*p != '\n'){
            if(*p == 124 || *p == 47 || *p == 47 || *p == 58 || *p == 63 || *p == 42 || *p == 60 || *p == 62 || *p == 92)
                *p++;
            *p2 = *p;
            p++;
            p2++;
        }

        //put " at the end of each line
        *p2='"'; p2++;
    }
    fclose(fp);
    printf("Converting to recommended File Completed.\n");

    //printf("\n\nModified Text: \n"); commenting it because i dont wanna print the input list, if u want to, remove these //
    //*p2='A'; p2++; useless code, i didn't delete it because one may think that with thses 2 line we dont have to go for another pointer(*lastPointer), but its not worked, i tried, fix it if u can,
    //*p2='\0';  Dont forget to let me know the correction at darkprince14p@gmail.com
    //printf("\n%s", str_cpy); commenting it because i dont wanna print a list of wrong list

    //this part is to solve the last double quote which dont appear on screen
    char *lastPointer = str_cpy;
    lastPointer = lastPointer + strlen(str_cpy);
    //lastPointer++;
    *lastPointer = '"';
    lastPointer++;
    *lastPointer = '\0';
    //printf("\n\n%s", str_cpy); commenting it because i dont wanna print the input list, if u want to, remove these //



    //Finally creat the folder with desired name
    //it will first write the system command to a txt file
    //then read each line and will creat a folder with it
    fp = fopen("list.txt", "w");
    fprintf(fp, "%s", str_cpy);
    fclose(fp);

    printf("\n\nPress Enter to Creat the Folders: \n");
    getch();
    printf("\nCreating...\n");
    fp = fopen("list.txt", "r");
    while(!feof(fp)){
        fgets(str_cpy, 200, fp);
        //printf("%s", str);
        system(str_cpy);
    }
    fclose(fp);

    printf("Process Completed");

    getch();
    return 0;
}
