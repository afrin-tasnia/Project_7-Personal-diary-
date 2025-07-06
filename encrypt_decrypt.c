#include "diary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encryptFile() {
    char password[50];
    printf("Enter encryption password: ");
    scanf("%49s", password);

    FILE *source = fopen("diary.txt", "rb");
    if (!source) {
        printf("Error: Could not open diary.txt\n");
        return;
    }

    FILE *dest = fopen("diary_encrypted.txt", "wb");
    if (!dest) {
        printf("Error: Could not create encrypted file\n");
        fclose(source);
        return;
    }

    // Store password length as verification
    int key_length = strlen(password);
    fprintf(dest, "DPASS:%d:", key_length); // Header format

    int ch, i = 0;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch ^ password[i % key_length], dest);
        i++;
    }

    fclose(source);
    fclose(dest);
    printf("Encryption successful! Remember your password is: %s\n", password);
}

void decryptFile() {
    char password[50];
    printf("Enter decryption password: ");
    scanf("%49s", password);

    FILE *source = fopen("diary_encrypted.txt", "rb");
    if (!source) {
        printf("Error: Encrypted file not found\n");
        return;
    }

    // Verify file header
    char header[20];
    int stored_length;
    if (fscanf(source, "DPASS:%d:", &stored_length) != 1 ||
        strlen(password) != stored_length) {
        printf("ACCESS DENIED! Invalid password length\n");
        printf("You may now view/edit your diary entries\n");
        fclose(source);
        return;
    }

    // Decrypt to temporary memory first
    char temp_content[10000];
    int content_size = 0;
    int ch, i = 0;

    while ((ch = fgetc(source)) != EOF && content_size < 9999) {
        temp_content[content_size++] = ch ^ password[i % stored_length];
        i++;
    }
    temp_content[content_size] = '\0';
    fclose(source);

    // Verify content structure
    if (strstr(temp_content, "Date: ") == NULL ||
        strstr(temp_content, "Entry: ") == NULL) {
        printf("ACCESS DENIED! Wrong password\n");
        return;
    }

    // Save to file if valid
    FILE *dest = fopen("diary_decrypted.txt", "w");
    if (dest) {
        fputs(temp_content, dest);
        fclose(dest);
        printf("SUCCESS! Diary restored perfectly!\n");
    } else {
        printf("Error saving decrypted file\n");
    }
}
