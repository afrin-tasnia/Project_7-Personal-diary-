// diary.h

#ifndef DIARY_H
#define DIARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function Declarations
void displayMenu();              // Displays the main menu
void addEntry();                 // Adds a new diary entry
void viewEntries();              // Views all diary entries
void searchEntry();              // Searches for a specific entry by date
void editEntry();                // Edits an existing entry
void deleteEntry();              // Deletes an entry
void encryptFile();              // Encrypts the diary file
void decryptFile();              // Decrypts the diary file
void backupDiary();              // Creates a backup of the diary

#endif




