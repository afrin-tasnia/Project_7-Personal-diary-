// view_search.c
#include "diary.h"

void viewEntries() {
    FILE *file = fopen("diary.txt", "r");

    if (file == NULL) {
        printf("No entries found!\n");
        return;
    }

    char line[1000];
    printf("\n--- All Diary Entries ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void searchEntry() {
    FILE *file = fopen("diary.txt", "r");
    char searchDate[20];
    char line[1000];
    int found = 0;

    printf("Enter date to search (DD-MM-YYYY): ");
    scanf("%s", searchDate);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, searchDate) != NULL) {
            printf("Entry found:\n%s", line);
            found = 1;
            while (fgets(line, sizeof(line), file)) {
                if (strstr(line, "Date:") != NULL) break;
                printf("%s", line);
            }
        }
    }

    if (!found) printf("No entry found for %s\n", searchDate);
    fclose(file);
}
