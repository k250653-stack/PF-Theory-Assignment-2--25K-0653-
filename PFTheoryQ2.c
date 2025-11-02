//Muhammad Hamza Siddiqui 
//25K-0653 BCS-1G
#include <stdio.h>
#include <string.h>

void getCustomer(char customerName[], char CNIC[]) {
    printf("Enter customer name: ");
    getchar();
    fgets(customerName, 50, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';
    printf("Enter customer CNIC(In Format xxxxx-xxxxxxx-x): ");
    fgets(CNIC, 20, stdin);
    CNIC[strcspn(CNIC, "\n")] = '\0';
}

void showInventory(int itemCode[], int itemStock[], float itemPrice[], int itemCount) {
    printf("\nItem Code | Quantity | Price\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t\t%d\t\t%.2f\n", itemCode[i], itemStock[i], itemPrice[i]);
    }
}

void updateInventory(int itemCode[], int itemStock[], int itemCount, int chosenCode, int chosenQty) {
    for (int i = 0; i < itemCount; i++) {
        if (itemCode[i] == chosenCode) {
            itemStock[i] -= chosenQty;
            return;
        }
    }
}

void addToCart(int cartCode[], int cartAmount[], int *cartItems, int chosenCode, int chosenQty) {
    cartCode[*cartItems] = chosenCode;
    cartAmount[*cartItems] = chosenQty;
    (*cartItems)++;
}

float calcTotal(int cartCode[], int cartAmount[], int itemCode[], float itemPrice[], int cartItems, int itemCount) {
    float billTotal = 0;
    for (int i = 0; i < cartItems; i++) {
        for (int j = 0; j < itemCount; j++) {
            if (cartCode[i] == itemCode[j]) {
                billTotal += itemPrice[j] * cartAmount[i];
            }
        }
    }
    return billTotal;
}

float applyPromo(float billTotal, char promoCode[]) {
    if (strcmp(promoCode, "Eid2025") == 0) return billTotal * 0.75;
    return billTotal;
}

void showInvoice(char customerName[], char CNIC[], float billTotal, float billAfterDiscount, int promoApplied) {
    printf("\n--- INVOICE ---\n");
    printf("Customer Name: %s\n", customerName);
    printf("CNIC: %s\n", CNIC);
    printf("Total Bill: %.2f\n", billTotal);
    if (promoApplied) printf("Discounted Bill: %.2f\n", billAfterDiscount);
}

int main() {
    int itemCode[] = {1, 2, 3, 4};
    int itemStock[] = {50, 10, 20, 8};
    float itemPrice[] = {100, 200, 300, 150};
    int itemCount = 4;

    int cartCode[50];
    int cartAmount[50];
    int cartItems = 0;

    char customerName[50];
    char CNIC[20];
    float billTotal = 0;
    float billAfterDiscount = 0;
    int promoApplied = 0;
    int menuOption;

    do {
        printf("\n--- Supermarket Menu ---\n");
        printf("1. Enter Customer Info\n");
        printf("2. Show Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Show Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1:
                getCustomer(customerName, CNIC);
                break;
            case 2:
                showInventory(itemCode, itemStock, itemPrice, itemCount);
                break;
            case 3: {
                int chosenCode, chosenQty;
                printf("Enter item code: ");
                scanf("%d", &chosenCode);
                printf("Enter quantity: ");
                scanf("%d", &chosenQty);
                for (int i = 0; i < itemCount; i++) {
                    if (itemCode[i] == chosenCode && itemStock[i] >= chosenQty) {
                        addToCart(cartCode, cartAmount, &cartItems, chosenCode, chosenQty);
                        updateInventory(itemCode, itemStock, itemCount, chosenCode, chosenQty);
                        printf("Item added to cart.\n");
                        break;
                    }
                }
                break;
            }
            case 4: {
                billTotal = calcTotal(cartCode, cartAmount, itemCode, itemPrice, cartItems, itemCount);
                char promoCode[20];
                printf("Do you have a promo code? (enter or press Enter to skip): ");
                getchar();
                fgets(promoCode, 20, stdin);
                promoCode[strcspn(promoCode, "\n")] = '\0';
                if (strcmp(promoCode, "Eid2025") == 0) {
                    billAfterDiscount = applyPromo(billTotal, promoCode);
                    promoApplied = 1;
                } else {
                    billAfterDiscount = billTotal;
                    promoApplied = 0;
                }
                printf("Total Bill: %.2f\n", billTotal);
                if (promoApplied) printf("Discounted Bill: %.2f\n", billAfterDiscount);
                break;
            }
            case 5:
                showInvoice(customerName, CNIC, billTotal, billAfterDiscount, promoApplied);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (menuOption != 6);

    return 0;
}

