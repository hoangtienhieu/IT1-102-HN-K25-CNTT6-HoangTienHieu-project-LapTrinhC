#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    char accountId[20];
    char fullName[50];
    char phone[15];
    double balance;
    int status;
};
struct Transaction {
    char transId[20];
    char senderId[20];
    char receiverId[20];
    double amount;
    char type[10];
    char date[20];
}; 
void addAccount ();
int isDuplicateId ();
void updateAccount ();
int main () {
	struct Account acc[100];
	char input[20];
    int choice;
    int n=0;
    do {
    	printf ("+--------Quan ly ngan hang--------+\n");
    	printf ("|1.Them tai khoan moi             |\n");
    	printf ("|2.Cap nhat thong tin             |\n");
    	printf ("|3.Quan ly trang thai(khoa/xoa)   |\n");
    	printf ("|4.Tra cuu(tim kiem)              |\n");
    	printf ("|5.Danh sach(phan trang)          |\n");
    	printf ("|6.Sap xep danh sach              |\n");
    	printf ("|7.Giao dich chuyen khoan         |\n");
    	printf ("|8.Lich su giao dich              |\n");
    	printf ("|9.Thoat                          |\n");
    	printf ("+---------------------------------+\n");
        printf("Lua chon cua ban la : ");
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")] = '\0'; 
        if (strlen(input) == 0) {
            printf("Khong duoc nhap rong!\n");
            continue;
        }
        choice = atoi(input); //chuyen chuoi sang so
		switch (choice) {
			case 1:
                addAccount(acc,&n);
                break;
            case 2:
                updateAccount(acc,&n); 
                break;
            case 3:
                printf("Quan ly trang thai\n");
                break;
            case 4:
                printf("Tra cuu\n");
                break;
            case 5:
                printf("Danh sach\n");
                break;
            case 6:
                printf("Sap xep\n");
                break;
            case 7:
                printf("Giao dich chuyen khoan\n");
                break;
            case 8:
                printf("Lich su giao dich\n");
                break;
            case 9:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);
    return 0; 
}
int isDuplicateId(struct Account acc[],int n,char id[]) {
    for (int i=0;i<n;i++) {
        if (strcmp(acc[i].accountId,id) == 0) {
            return 1;
        }
    }
    return 0;
}
void addAccount (struct Account acc[],int *n) {
	printf("\n-----Them tai khoan moi-----\n");
    while (1) {
        printf("Nhap ma tai khoan : ");
        fgets(acc[*n].accountId,sizeof(acc[*n].accountId),stdin);
        acc[*n].accountId[strcspn(acc[*n].accountId,"\n")] = '\0';
        if (strlen(acc[*n].accountId) == 0) {
            printf("Ma tai khoan khong duoc rong. Vui long nhap lai!\n");
            continue;
        }
        if (isDuplicateId(acc,*n,acc[*n].accountId)) {
            printf("Ma tai khoan da ton tai. Vui long nhap Id khac!\n");
            continue;
        }
        break;
    }
    printf("Nhap ten tai khoan : ");
    fgets (acc[*n].fullName,sizeof(acc[*n].fullName),stdin);
    acc[*n].fullName[strcspn(acc[*n].fullName,"\n")] = '\0';
    printf ("Nhap so dien thoai : ");
    fgets (acc[*n].phone,sizeof(acc[*n].phone),stdin);
    acc[*n].phone[strcspn(acc[*n].phone,"\n")] = '\0';
    acc[*n].balance = 0;   
    acc[*n].status = 1;   
    (*n)++;
}
void updateAccount (struct Account acc[],int n) {
	if (n==0) {
        printf("Chua co tai khoan nao de cap nhat!\n\n");
        return;
    }
    char id[20];
    printf("\n-----Cap nhat thong tin tai khoan-----\n");
    printf("Nhap id tai khoan can cap nhat : ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")] = '\0';
    int pos = -1;
    for (int i=0;i<n;i++) {
        if (strcmp(acc[i].accountId,id)==0) {
            pos = i;
            break;
        }
    }
    if (pos==-1) {
        printf("Khong tim thay tai khoan co id '%s'!\n\n",id);
        return;
    }
    printf("\n=>Da tim thay tai khoan.\n");
    printf ("Id : %s\n",acc[pos].accountId);
    printf("Ten hien tai : %s\n",acc[pos].fullName);
    printf("So dien thoai hien tai : %s\n",acc[pos].phone);
    char newFullName[50];
    char newPhone[15];
    printf("\nNhap ten moi : ");
    fgets(newFullName,sizeof(newFullName),stdin);
    newFullName[strcspn(newFullName,"\n")] = '\0';
    if (strlen(newFullName)>0) {
        strcpy(acc[pos].fullName,newFullName);
    }
    printf("Nhap so dien thoai moi : ");
    fgets(newPhone,sizeof(newPhone),stdin);
    newPhone[strcspn(newPhone,"\n")] = '\0';
    if (strlen(newPhone)>0) {
        strcpy(acc[pos].phone,newPhone);
    }
    printf("\n=>Cap nhat thong tin thanh cong!\n\n");
}


