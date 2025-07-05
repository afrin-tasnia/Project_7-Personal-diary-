// main.c
#include "diary.h"

int main() {
    int choice;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: editEntry(); break;
            case 5: deleteEntry(); break;
            case 6: encryptFile(); break;
            case 7: decryptFile(); break;
            case 8: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Personal Diary Management System ---\n");
    printf("1. Add New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Edit Entry\n");
    printf("5. Delete Entry\n");
    printf("6. Encrypt Diary File\n");
    printf("7. Decrypt Diary File\n");
    printf("8. Exit\n\n\n");
}
