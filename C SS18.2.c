#include<stdio.h>
#include<string.h>

struct SinhVien{
	char name[50];
	int age;
	char phoneNumber[50];
};

typedef struct SinhVien SinhVien;
	
void nhap(SinhVien *x){
	printf("Nhap ten : ");
	fgets(x->name, sizeof(x->name), stdin);
	x->name[strcspn(x->name, "\n")] = 0;
	
	printf("Nhap tuoi : ");
	scanf("%d", &x->age);
	
	getchar();
	
	printf("Nhap sdt : ");
	fgets(x->phoneNumber, sizeof(x->phoneNumber), stdin);
	x->phoneNumber[strcspn(x->phoneNumber, "\n")] = 0;
}

int main() {
	SinhVien s;
	nhap(&s);
	
	printf("Ten cua sinh vien : %s\n", s.name);
	printf("Tuoi cua sinh vien : %d\n", s.age);
	printf("Sdt cua sinh vien : %s", s.phoneNumber);
	return 0;
}

