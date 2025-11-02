//Muhammad Hamza Siddiqui 
//25K-0653 BCS-1G
#include <stdio.h>
#include <string.h>

void addBook(int ISBN[], char Btitle[][50], float price[], int quantity[], int *bookamount, int maxbooks) {
    if (*bookamount >= maxbooks) {
        printf("Inventory full.\n");
        return;
    }
    int newIsbn;
    printf("Enter ISBN: ");
    scanf("%d", &newIsbn);
    for (int i = 0; i < *bookamount; i++) {
        if (ISBN[i] == newIsbn) {
            printf("Book with ISBN %d already exists.\n", newIsbn);
            return;
        }
    }
    ISBN[*bookamount] = newIsbn;
    printf("Enter Title: ");
    getchar();
    fgets(Btitle[*bookamount], 50, stdin);
    Btitle[*bookamount][strcspn(Btitle[*bookamount], "\n")] = '\0';
    printf("Enter Price: ");
    scanf("%f", &price[*bookamount]);
    printf("Enter Quantity: ");
    scanf("%d", &quantity[*bookamount]);
    (*bookamount)++;
    printf("Book added successfully.\n");
}

void sellBook(int ISBN[], int quantity[], int bookamount) {
    if (bookamount == 0) {
        printf("No books in inventory.\n");
        return;
    }
    int targetIsbn, soldQty;
    printf("Enter ISBN of book sold: ");
    scanf("%d", &targetIsbn);
    for (int i = 0; i < bookamount; i++) {
        if (ISBN[i] == targetIsbn) {
            printf("Enter number of copies sold: ");
            scanf("%d", &soldQty);
            if (soldQty > quantity[i]) {
                printf("Not enough stock. Available: %d\n", quantity[i]);
            } else {
                quantity[i] -= soldQty;
                printf("Sale processed. Remaining stock: %d\n", quantity[i]);
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void showLowStock(int ISBN[], char Btitle[][50], float price[], int quantity[], int bookamount) {
    int lowStockFound = 0;
    printf("\nLow Stock Report (Quantity < 5):\n");
    for (int i = 0; i < bookamount; i++) {
        if (quantity[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   ISBN[i], Btitle[i], price[i], quantity[i]);
            lowStockFound = 1;
        }
    }
    if (!lowStockFound) printf("All books have sufficient stock.\n");
}

int main() {
    int maxbooks = 100;
    int ISBN[100];
    char Btitle[100][50];
    float price[100];
    int quantity[100];
    int bookamount = 0;
    int choice;
    do {
        printf("\n--- Liberty Books Inventory ---\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Show Low Stock\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(ISBN, Btitle, price, quantity, &bookamount, maxbooks); break;
            case 2: sellBook(ISBN, quantity, bookamount); break;
            case 3: showLowStock(ISBN, Btitle, price, quantity, bookamount); break;
            case 4: printf("Exiting program...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}

