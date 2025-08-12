// main.c

#include "diary.h"
#include <locale.h>
#include <windows.h>

// Extended color definitions for console text
#define COLOR_RED 12
#define COLOR_GREEN 10
#define COLOR_YELLOW 14
#define COLOR_BLUE 9
#define COLOR_MAGENTA 13
#define COLOR_CYAN 11
#define COLOR_WHITE 15
#define COLOR_PURPLE 5
#define COLOR_LIME 10
#define COLOR_TEAL 3
#define COLOR_ORANGE 6
#define COLOR_PINK 13
#define COLOR_GRAY 8 // Added for backup option

// Function to set console text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Main function
int main() {
    setlocale(LC_ALL, "");    // Set locale for proper character display
    system("chcp 65001");      // Set console code page to UTF-8

    int choice;
    while(1) { // Infinite loop to keep the program running
        displayMenu(); // Display the main menu
        
        // Prompt user for choice
        setColor(COLOR_CYAN);
        printf("Choose a option...! ");
        setColor(COLOR_WHITE);
        scanf("%d", &choice);

        // // Handle menu selection with different colors
        switch(choice) {
            case 1: setColor(COLOR_LIME); addEntry(); break;
            case 2: setColor(COLOR_TEAL); viewEntries(); break;
            case 3: setColor(COLOR_ORANGE); searchEntry(); break;
            case 4: setColor(COLOR_PINK); editEntry(); break;
            case 5: setColor(COLOR_RED); deleteEntry(); break;
            case 6: setColor(COLOR_PURPLE); encryptFile(); break;
            case 7: setColor(COLOR_YELLOW); decryptFile(); break;
            case 8: setColor(COLOR_GRAY); backupDiary(); break; // New option
            case 9: setColor(COLOR_CYAN);
                    printf("\nExiting... See you next time! \n\n");
                    exit(0); // Exit the program
            default: setColor(COLOR_RED);
                    printf("\nInvalid choice! Please try again.\n");
        }
        setColor(COLOR_WHITE); // Reset color to white
    }
    return 0;
}


