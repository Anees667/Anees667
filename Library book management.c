#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int year;
};

void addBook(struct Book books[], int *count) {
    if (*count < 100) {  // Limit to 100 books for simplicity
        struct Book newBook;
        printf("Enter book ID: ");
        scanf("%d", &newBook.id);
        getchar();  // to consume newline character after id
        printf("Enter book title: ");
        fgets(newBook.title, sizeof(newBook.title), stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0';  // Remove newline character
        printf("Enter author name: ");
        fgets(newBook.author, sizeof(newBook.author), stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0';  // Remove newline character
        printf("Enter year of publication: ");
        scanf("%d", &newBook.year);

        // Add the new book to the array
        books[*count] = newBook;
        (*count)++;
        printf("Book added successfully.\n");
    } else {
        printf("Cannot add more books, storage full.\n");
    }
}

void searchBookByTitle(struct Book books[], int count) {
    char searchTitle[100];
    getchar();  // to consume newline character from previous input
    printf("Enter book title to search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found: \n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with that title.\n");
    }
}

void deleteBookById(struct Book books[], int *count) {
    int idToDelete;
    printf("Enter book ID to delete: ");
    scanf("%d", &idToDelete);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (books[i].id == idToDelete) {
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;  // Decrease the count of books
            printf("Book with ID %d deleted successfully.\n", idToDelete);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with that ID.\n");
    }
}

int main() {
    struct Book books[100]; 
    int bookCount = 0; 

    int choice;
    do {
        printf("\nBook Record Management System\n");
        printf("1. Add a Book\n");
        printf("2. Search a Book by Title\n");
        printf("3. Delete a Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                searchBookByTitle(books, bookCount);
                break;
            case 3:
                deleteBookById(books, &bookCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
