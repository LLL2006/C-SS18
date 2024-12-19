#include <stdio.h>
#include <string.h>

typedef struct {
    int id;              
    char name[50]; 
    int age;            
    char phoneNumber[15];
} SinhVien;

void printSinhVien(SinhVien sv[], int size) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("-----------------------\n");
    }
}

int xoaSv(SinhVien sv[], int size, char nameToDelete[]) {
    int found = -1; 

    for (int i = 0; i < size; i++) {
        if (strcmp(sv[i].name, nameToDelete) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        return size;
    }

    for (int i = found; i < size - 1; i++) {
        sv[i] = sv[i + 1];
    }

    return size - 1;
}

int main() {
    SinhVien sv[50] = {
        {1, "Nguyen Van A", 20, "0987654321"},
        {2, "Tran Thi B", 22, "0912345678"},
        {3, "Le Van C", 19, "0934567890"},
        {4, "Hoang Minh D", 21, "0971234567"},
        {5, "Pham Thu E", 23, "0956789012"}
    };
    int nsv = 5;

    printSinhVien(sv, nsv);

    char nameToDelete[50];
    printf("Nhap ten sinh vien can xoa: ");
    scanf(" %s", nameToDelete);

    int newSize = xoaSv(sv, nsv, nameToDelete);

    if (newSize == nsv) {
        printf("Khong tim thay sinh vien co ten: %s\n", nameToDelete);
    } else {
        printf("Sinh vien co ten %s da duoc xoa thanh cong.\n", nameToDelete);
        nsv = newSize; 
    }

    printSinhVien(sv, nsv);

    return 0;
}

