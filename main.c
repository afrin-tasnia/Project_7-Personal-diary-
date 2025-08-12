// main.c
#include "diary.h"
#include <locale.h>
#include <windows.h>

// Extended color definitions
#define COLOR_RED       12
#define COLOR_GREEN     10
#define COLOR_YELLOW    14
#define COLOR_BLUE       9
#define COLOR_MAGENTA   13
#define COLOR_CYAN      11
#define COLOR_WHITE     15
#define COLOR_PURPLE     5
#define COLOR_LIME      10
#define COLOR_TEAL       3
#define COLOR_ORANGE     6
#define COLOR_PINK      13
#define COLOR_GRAY       8  // Added for backup option


void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    setlocale(LC_ALL, "");
    system("chcp 65001");

        int choice;
    while(1) {
        displayMenu();
        setColor(COLOR_CYAN);
        printf("Choose a option...! ");
        setColor(COLOR_WHITE);
        scanf("%d", &choice);

        switch(choice) {
            case 1: setColor(COLOR_LIME); addEntry(); break;
            case 2: setColor(COLOR_TEAL); viewEntries(); break;
            case 3: setColor(COLOR_ORANGE); searchEntry(); break;
            case 4: setColor(COLOR_PINK); editEntry(); break;
            case 5: setColor(COLOR_RED); deleteEntry(); break;
            case 6: setColor(COLOR_PURPLE); encryptFile(); break;
            case 7: setColor(COLOR_YELLOW); decryptFile(); break;
            case 8: setColor(COLOR_GRAY); backupDiary(); break;  // New option
            case 9: setColor(COLOR_CYAN);
                   printf("\nExiting... See you next time! \n\n");
                   exit(0);
            default: setColor(COLOR_RED);
                     printf("\nInvalid choice! Please try again.\n");
        }
        setColor(COLOR_WHITE);
    }
    return 0;

}






