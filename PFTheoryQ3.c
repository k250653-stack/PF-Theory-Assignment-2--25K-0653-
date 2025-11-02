//Muhammad Hamza Siddiqui 
//25K-0653 BCS-1G
#include <stdio.h>

void updateSector(int grid[5][5], int rows, int columns) {
    int row, col, flag, action;
    printf("Enter row and column of sector: ");
    scanf("%d %d", &row, &col);
    printf("Enter flag to modify (0=Power, 1=Overload, 2=Maintenance): ");
    scanf("%d", &flag);
    printf("1 to set, 0 to clear: ");
    scanf("%d", &action);
    if (row >= 0 && row < rows && col >= 0 && col < columns) {
        if (action == 1) grid[row][col] |= (1 << flag);
        else grid[row][col] &= ~(1 << flag);
        printf("Sector updated.\n");
    } else printf("Invalid coordinates.\n");
}

void querySector(int grid[5][5], int rows, int columns) {
    int row, col;
    printf("Enter row and column to query: ");
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < rows && col >= 0 && col < columns) {
        int sector = grid[row][col];
        printf("\nSector (%d,%d) Status:\n", row, col);
        printf("Power: %s\n", (sector & 1) ? "ON" : "OFF");
        printf("Overload: %s\n", (sector & 2) ? "YES" : "NO");
        printf("Maintenance: %s\n", (sector & 4) ? "REQUIRED" : "NO");
    } else printf("Invalid coordinates.\n");
}

void runDiagnostic(int grid[5][5], int rows, int columns) {
    int overloadCount = 0, maintenanceCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] & 2) overloadCount++;
            if (grid[i][j] & 4) maintenanceCount++;
        }
    }
    printf("\nSystem Diagnostic:\n");
    printf("Overloaded sectors: %d\n", overloadCount);
    printf("Maintenance required sectors: %d\n", maintenanceCount);
}

int main() {
    int rows = 5, columns = 5;
    int grid[5][5] = {0};
    int option;

    do {
        printf("\n--- IESCO Power Grid System ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                updateSector(grid, rows, columns);
                break;
            case 2:
                querySector(grid, rows, columns);
                break;
            case 3:
                runDiagnostic(grid, rows, columns);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (option != 4);

    return 0;
}

