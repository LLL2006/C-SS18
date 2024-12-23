#include <stdio.h>
#include <string.h>

#define MAX_MENU 100

typedef struct {
    int id;
    char name[50];
    float price;
} Dish;

Dish menu[MAX_MENU] = {
    {1, "Pho", 35000},
    {2, "Banh Mi", 20000},
    {3, "Com Tam", 40000},
    {4, "Bun Bo", 45000},
    {5, "Cha Gio", 30000}
};
int menuSize = 5;

void printMenu() {
    for (int i = 0; i < menuSize; i++) {
        printf("%d. ID: %d, Ten: %s, Gia: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
    }
}

void addDish(int position, Dish dish) {
    for (int i = menuSize; i > position; i--) {
        menu[i] = menu[i - 1];
    }
    menu[position] = dish;
    menuSize++;
}

void editDish(int position, Dish dish) {
    menu[position] = dish;
}

void deleteDish(int position) {
    for (int i = position; i < menuSize - 1; i++) {
        menu[i] = menu[i + 1];
    }
    menuSize--;
}

int comparePriceDescending(const void *a, const void *b) {
    return ((Dish *)b)->price - ((Dish *)a)->price;
}

int comparePriceAscending(const void *a, const void *b) {
    return ((Dish *)a)->price - ((Dish *)b)->price;
}

void sortMenu(int order) {
    if (order == 1) {
        qsort(menu, menuSize, sizeof(Dish), comparePriceDescending);
    } else if (order == 2) {
        qsort(menu, menuSize, sizeof(Dish), comparePriceAscending);
    } else {
        printf("Thu tu sap xep khong hop le.\n");
    }
}

void linearSearch(char *name) {
    int found = 0;
    for (int i = 0; i < menuSize; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            printf("Tim thay: ID: %d, Ten: %s, Gia: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an.\n");
    }
}

int binarySearch(char *name) {
    int left = 0, right = menuSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(menu[mid].name, name);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int choice;
    do {
        printf("\nTHUC DON\n");
        printf("1. In thuc don\n");
        printf("2. Them mon an\n");
        printf("3. Sua mon an\n");
        printf("4. Xoa mon an\n");
        printf("5. Sap xep mon an\n");
        printf("6. Tim kiem mon an\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu();
                break;
            case 2: {
                Dish newDish;
                int position;
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                printf("Nhap ID, ten, gia: ");
                scanf("%d %s %f", &newDish.id, newDish.name, &newDish.price);
                addDish(position - 1, newDish);
                break;
            }
            case 3: {
                Dish updatedDish;
                int position;
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                printf("Nhap Id, ten, gia: ");
                scanf("%d %s %f", &updatedDish.id, updatedDish.name, &updatedDish.price);
                editDish(position - 1, updatedDish);
                break;
            }
            case 4: {
                int position;
                printf("Nhap vi tri: ");
                scanf("%d", &position);
                deleteDish(position - 1);
                break;
            }
            case 5: {
                int sortChoice;
                printf("1. Giam dan theo gia\n2. Tang dan theo gia\nChon thu tu sap xep: ");
                scanf("%d", &sortChoice);
                sortMenu(sortChoice);
                break;
            }
            case 6: {
                char name[50];
                int searchChoice;
                printf("Nhap ten mon an can tim: ");
                scanf("%s", name);
                printf("1. Tim kiem tuyen tinh\n2. Tim kiem nhi phan\nChon phuong phap tim kiem: ");
                scanf("%d", &searchChoice);
                if (searchChoice == 1) {
                    linearSearch(name);
                } else if (searchChoice == 2) {
                    int index = binarySearch(name);
                    if (index != -1) {
                        printf("Tim thay: ID: %d, Ten: %s, Gia: %.2f\n", menu[index].id, menu[index].name, menu[index].price);
                    } else {
                        printf("Khong tim thay mon an.\n");
                    }
                } else {
                    printf("Phuong phap tim kiem khong hop le.\n");
                }
                break;
            }
            case 7:
                printf("Ðang thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}


