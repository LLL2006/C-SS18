#include <stdio.h>
#include <string.h>

typedef struct {
    int id;            
    char name[50];     
    int age;             
    char phoneNumber[15];
} SinhVien;

int main() {
    SinhVien sv[50];
    int nsv = 5;

    for (int i = 0; i < nsv; i++) {
        sv[i].id = i + 1;

        printf("Nhap thong tin cho sinh vien thu %d:\n", sv[i].id);

        printf("Nhap ten: ");
        scanf(" %s", sv[i].name);

        printf("Nhap tuoi: ");
        scanf("%d", &sv[i].age);

        printf("Nhap so dien thoai: ");
        scanf(" %s", sv[i].phoneNumber);

        printf("\n");
    }


    printf("Thong tin cac sinh vien:\n");
    for (int i = 0; i < nsv; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("\n");
    }

    return 0;
}

