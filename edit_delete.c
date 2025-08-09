#include "diary.h"
#include <ctype.h>

// Edit entry function
void editEntry() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error: Diary file not found!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char searchDate[20];
    char line[1000];
    int found = 0;

    printf("Enter date of the entry to edit (DD-MM-YYYY): ");
    scanf("%19s", searchDate);

    while (fgets(line, sizeof(line), file)) {
        if (!found && strstr(line, searchDate) != NULL) {
            found = 1;
            printf("Current entry:\n%s", line);

            // Get the existing entry content
            if (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }

            // Get new entry
            char newEntry[1000];
            printf("Enter new entry text: ");
            scanf(" %[^\n]", newEntry);

            // Write updated entry
            fprintf(temp, "Date: %s\nEntry: %s\n\n", searchDate, newEntry);
        } else {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found) {
        printf("No entry found for %s\n", searchDate);
        remove("temp.txt");
    } else {
        remove("diary.txt");
        rename("temp.txt", "diary.txt");
        printf("Entry updated successfully!\n");
    }
}

// Delete function
void deleteEntry() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error: No entries found!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char searchDate[20];
    char line[1000];
    int found = 0;

    printf("Enter date of the entry to delete (DD-MM-YYYY): ");
    scanf("%19s", searchDate);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, searchDate) != NULL) {
            found = 1;
            printf("Deleted entry:\n%s", line);
            // Skip the entry content
            fgets(line, sizeof(line), file);
        } else {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found) {
        printf("No entry found for %s\n", searchDate);
        remove("temp.txt");
    } else {
        remove("diary.txt");
        rename("temp.txt", "diary.txt");
        printf("Entry deleted successfully!\n");
    }
}



