// add_entry.c
#include "diary.h"

void addEntry() {
    FILE *file = fopen("diary.txt", "a");  // Append mode

    if (file == NULL) {
        printf("Error opening file!\n");
        return
    }

    char date[20];
    char entry[1000];

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", date);
    printf("Write your diary entry:\n");
    scanf(" %[^\n]s", entry);  // Read until newline

    fprintf(file, "Date: %s\nEntry: %s\n\n", date, entry);
    fclose(file);

    printf("Entry saved successfully!\n");
}