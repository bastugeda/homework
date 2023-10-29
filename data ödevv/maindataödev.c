#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int student_number;
    char name[50];
    int age;
};

struct Node {
    struct Student data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to add odd numbers to the beginning and even numbers to the end
void addNumbersToList() {
    int num;
    struct Node* newNode;
    
    while (1) {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data.student_number = num;
        newNode->next = NULL;
        
        if (num % 2 == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }
}

// Function to add 100 randomly generated numbers to the list
void addRandomNumbers() {
    for (int i = 0; i < 100; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data.student_number = rand() % 1000;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// Function to sort and print the list in descending order
void sortAndPrintList() {
    struct Node* current = head;
    int count = 0;
    int numbers[100];
    
    while (current != NULL) {
        numbers[count] = current->data.student_number;
        current = current->next;
        count++;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] < numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d", numbers[i]);
        if (i < count - 1) {
            printf("->");
        }
    }
    printf("\n");
}

// Function to add student information to the list
void addStudentInfo() {
    struct Student student;
    printf("Enter student number: ");
    scanf("%d", &student.student_number);
    printf("Enter name: ");
    scanf("%s", student.name);
    printf("Enter age: ");
    scanf("%d", &student.age);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display all student information and count
void displayStudentInfo() {
    struct Node* current = head;
    int count = 1;
    
    while (current != NULL) {
        printf("%d- %s %d %d\n", count, current->data.name, current->data.age, current->data.student_number);
        current = current->next;
        count++;
    }
    
    printf("Total number of students: %d\n", count - 1);
}

// Function to search records by student name
void searchStudentByName() {
    char searchName[50];
    printf("Enter the name to search: ");
    scanf("%s", searchName);
    
    struct Node* current = head;
    int found = 0;
    
    while (current != NULL) {
        if (strcmp(current->data.name, searchName) == 0) {
            printf("Student found: %d %s %d\n", current->data.student_number, current->data.name, current->data.age);
            found = 1;
            break;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to delete the next node after a student name match
void deleteNextNodeByName() {
    char searchName[50];
    printf("Enter the name to search: ");
    scanf("%s", searchName);
    
    struct Node* current = head;
    
    while (current != NULL) {
        if (strcmp(current->data.name, searchName) == 0 && current->next != NULL) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("Next node after %s deleted.\n", searchName);
            return;
        }
        current = current->next;
    }
    
    printf("No match found or no next node to delete.\n");
}

// Function to print the record with the longest name
void printLongestName() {
    struct Node* current = head;
    char longestName[50];
    int maxLength = 0;
    
    while (current != NULL) {
        int currentLength = strlen(current->data.name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strcpy(longestName, current->data.name);
        }
        current = current->next;
    }
    
    if (maxLength > 0) {
        printf("The longest name in the list: %s\n", longestName);
        printf("Length: %d\n", maxLength);
    } else {
        printf("No names in the list.\n");
    }
}

// Function to display the user menu
void displayMenu() {
    printf("\n----- Student Record Management Menu -----\n");
    printf("1. Add Odd and Even Numbers to List\n");
    printf("2. Add 100 Random Numbers to List\n");
    printf("3. Sort and Print List in Descending Order\n");
    printf("4. Add Student Information to List\n");
    printf("5. Display All Student Information\n");
    printf("6. Search Student by Name\n");
    printf("7. Delete Next Node by Name\n");
    printf("8. Print Longest Name\n");
    printf("9. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
}

  switch (choice) {
            case 1:
                addNumberToList();
                break;
            case 2:
                addRandomNumbersToList();
                break;
            case 3:
                sortList();
                break;
            case 4:
                printList();
                break;
            case 5:
                searchByName();
                break;
            case 6:
                deleteNextNodeByName();
                break;
            case 7:
                printLongestNameRecord();
                break;
            case 8:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

