#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "student_records.dat"
#define RECORD_SIZE sizeof(struct Student)

struct Student 
{
    int rollNumber;
    char name[50];
    char phoneNumber[20];
    char email[50];
};

void addRecord(FILE *file) 
{
    struct Student student;
    printf("Enter Roll Number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("\nEnter Phone Number: ");
    scanf("%s", student.phoneNumber);
    printf("Enter Email: ");
    scanf("%s", student.email);

    fseek(file, 0, SEEK_END);
    fwrite(&student, RECORD_SIZE, 1, file);
    printf("Record added successfully!\n");
}

void displayRecord(FILE *file) 
{
    struct Student student;
    int rollNumber;
    printf("Enter Roll Number to display record: ");
    scanf("%d", &rollNumber);

    fseek(file, (rollNumber - 1) * RECORD_SIZE, SEEK_SET);
    fread(&student, RECORD_SIZE, 1, file);

    printf("\nRoll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Phone Number: %s\n", student.phoneNumber);
    printf("Email: %s\n", student.email);
}

int main() 
{
    FILE *file = fopen(FILENAME, "r+");
    if (file == NULL) 
    {
        file = fopen(FILENAME, "w+");
        if (file == NULL) 
        {
            printf("Error opening file!\n");
            return 1;
        }
    }

    int choice;
    do {
        printf("\nStudent Address Management System\n");
        printf("1. Add Record\n");
        printf("2. Display Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addRecord(file);
                break;
            case 2:
                displayRecord(file);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
                break;
        }
    } 
    while (choice != 3);

    fclose(file);
    return 0;
}

