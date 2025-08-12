// view_search.c

#include "diary.h"

// Function to view all diary entries
void viewEntries() {
    // Open file in read mode to view entries
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No entries found!\n");
        return;
    }

    char line[1000];  // Buffer to read each line
    
    // Display header for entries
    printf(" _______________________________\n");
    printf("|                               |\n");
    printf("| !..All Diary Entries..!      |\n");
    printf("|_______________________________|\n\n");

    // Read and print each line of the file
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to search for a specific diary entry by date
void searchEntry() {
    // Open diary.txt in read mode
    FILE *file = fopen("diary.txt", "r");
    char searchDate[20];
    char line[1000];
    int found = 0;

    // Get date to search for
    printf("Enter date to search (DD-MM-YYYY): ");
    scanf("%s", searchDate);

    // Search through each line of the file
    while (fgets(line, sizeof(line), file)) {
        // Check if the current line contains the search date
        if (strstr(line, searchDate) != NULL) {
            printf("Entry found:\n%s", line);
            found = 1;
            // Print the rest of the entry until next date or EOF
            while (fgets(line, sizeof(line), file)) {
                if (strstr(line, "Date:") != NULL) break;
                printf("%s", line);
            }
        }
    }

    // Inform user if no entry was found
    if (!found) printf("No entry found for %s\n", searchDate);
    fclose(file);
}

