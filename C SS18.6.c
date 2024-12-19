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

    if (nsv < 50) { 
        SinhVien newSv;
        newSv.id = nsv + 1; 

        printf("Nhap thong tin sinh vien moi:\n");

        printf("Nhap ten: ");
        scanf(" %s", newSv.name); 

        printf("Nhap tuoi: ");
        scanf("%d", &newSv.age);

        printf("Nhap so dien thoai: ");
        scanf(" %s", newSv.phoneNumber);

        sv[nsv] = newSv;
        nsv++;

        printf("Sinh vien moi da duoc them thanh cong\n");
    }
    printSinhVien(sv, nsv);

    return 0;
}

