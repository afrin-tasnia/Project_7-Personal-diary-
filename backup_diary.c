// backup_diary.c
#include "diary.h"
#include <time.h>

void backupDiary() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char backupFilename[50];

    // Create timestamped filename
    sprintf(backupFilename, "diary_backup_%04d%02d%02d_%02d%02d%02d.txt",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);

    FILE *source = fopen("diary.txt", "r");
    if (!source) {
        printf("Error: No diary entries found to backup!\n");
        return;
    }

    FILE *dest = fopen(backupFilename, "w");
    if (!dest) {
        printf("Error creating backup file!\n");
        fclose(source);
        return;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    fclose(source);
    fclose(dest);
    printf("Backup created successfully as: %s\n", backupFilename);
}

