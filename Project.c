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
void addAccount (struct Account acc[],int *n);
void updateAccount (struct Account acc[],int n);
void locketAccount (struct Account acc[],int *n); 
void searchAccount (struct Account acc[],int *n); 
int main () {
	struct Account acc[100];
	char input[20];
    int choice;
    int n=0;
    do {
    	printf ("+--------Quan ly ngan hang--------+\n");
    	printf ("|1.Them tai khoan moi             |\n");
    	printf ("|2.Cap nhat thong tin             |\n");
    	printf ("|3.Quan ly trang thai             |\n");
    	printf ("|4.Tra cuu                        |\n");
    	printf ("|5.Danh sach                      |\n");
    	printf ("|6.Sap xep danh sach              |\n");
    	printf ("|7.Giao dich chuyen khoan         |\n");
    	printf ("|8.Lich su giao dich              |\n");
    	printf ("|9.Thoat                          |\n");
    	printf ("+---------------------------------+\n");
        printf("Lua chon cua ban la : ");
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")]='\0'; 
        if (strlen(input)==0) {
            printf("Khong duoc nhap rong.Vui long nhap lai!\n");
            continue;
        }
        choice = atoi(input); //chuyen chuoi sang so
		switch (choice) {
			case 1:
                addAccount(acc,&n);
                break;
            case 2:
                updateAccount(acc,n); 
                break;
            case 3:
                locketAccount(acc,&n); 
                break;
            case 4:
                searchAccount(acc,&n); 
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
    } while (choice!=9);
    return 0; 
}
int isDuplicateId (struct Account acc[],int n,char id[]) {
    for (int i=0;i<n;i++) {
        if (strcmp(acc[i].accountId,id)==0) {
            return 1;
        }
    }
    return 0;
}
int isNumber (char s[]) {
    for (int i=0;s[i]!='\0';i++) {
        if (s[i]<'0' || s[i]>'9')
		return 0;
    }
    return 1;
}
void addAccount (struct Account acc[],int *n) {
	printf("\n-----Them tai khoan moi-----\n");
    while (1) {
        printf("Nhap ma tai khoan : ");
        fgets(acc[*n].accountId,sizeof(acc[*n].accountId),stdin);
        acc[*n].accountId[strcspn(acc[*n].accountId,"\n")]='\0';
        if (strlen(acc[*n].accountId)==0) {
            printf("Ma tai khoan khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
        if (isDuplicateId(acc,*n,acc[*n].accountId)) {
            printf("Ma tai khoan da ton tai.Vui long nhap id khac!\n");
            continue;
        }
        break;
    }
    while (1) {
        printf("Nhap ten tai khoan : ");
        fgets (acc[*n].fullName,sizeof(acc[*n].fullName),stdin);
        acc[*n].fullName[strcspn(acc[*n].fullName,"\n")]='\0';
        if (strlen(acc[*n].fullName)==0) {
            printf("Ten tai khoan khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
        break;
    }
    while (1) {
        printf("Nhap so dien thoai : ");
        fgets(acc[*n].phone,sizeof(acc[*n].phone),stdin);
        acc[*n].phone[strcspn(acc[*n].phone,"\n")]='\0';
        if (strlen(acc[*n].phone)==0) {
            printf("So dien thoai khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
        if (strlen(acc[*n].phone)!=10) {
            printf("So dien thoai phai du 10 ky tu!\n");
            continue;
        }
        if (!isNumber(acc[*n].phone)) {
            printf("So dien thoai chi duoc chua chu so!\n");
            continue;
        }
        break;
    }
    acc[*n].balance = 0;   
    acc[*n].status = 1;   
    (*n)++;
}
void updateAccount (struct Account acc[],int n) {
	if (n==0) {
        printf("Chua co tai khoan!\n\n");
        return;
    }
    char id[20];
    int pos=-1;
    printf("\n-----Cap nhat thong tin tai khoan-----\n");
    while (1) {
        printf("Nhap ma tai khoan can cap nhat : ");
        fgets(id,sizeof(id),stdin);
        id[strcspn(id,"\n")]='\0';
         if (strlen(id)==0) {
            printf("Ma tai khoan khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
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
        break; 
    }
    printf("\n=>Da tim thay tai khoan.\n");
    printf ("Id : %s\n",acc[pos].accountId);
    printf("Ten hien tai : %s\n",acc[pos].fullName);
    printf("So dien thoai hien tai : %s\n",acc[pos].phone);
    char newFullName[50];
    while (1) { 
    printf("\nNhap ten moi : ");
    fgets(newFullName,sizeof(newFullName),stdin);
    newFullName[strcspn(newFullName,"\n")]='\0';
        if (strlen(newFullName)==0) {
            printf("Ten moi tai khoan khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
        break;
	}
	char newPhone[15]; 
    while (1) {
        printf("Nhap so dien thoai moi : ");
        fgets(newPhone,sizeof(newPhone),stdin);
        newPhone[strcspn(newPhone,"\n")]='\0';
        if (strlen(newPhone)==0) {
            printf("So dien thoai moi khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
        if (strlen(newPhone)!=10) {
            printf("So dien thoai phai du 10 ky tu!\n");
            continue;
        }
        if (!isNumber(newPhone)) {
            printf("So dien thoai chi duoc chua chu so!\n");
            continue;
        }
        strcpy(acc[pos].phone,newPhone);
        break;
    }
    printf("\n=>Cap nhat thong tin thanh cong!\n\n");
}
void locketAccount (struct Account acc[],int *n) {
	if (*n==0) {
        printf("Chua co tai khoan!\n");
        return;
    }
    while (1) {
        char id[20];
        printf("\n-----Tim tai khoan theo id-----\n");
        printf("Nhap id tai khoan : ");
        fgets(id,sizeof(id),stdin);
        id[strcspn(id,"\n")]='\0';
        if (strlen(id)==0) {
            printf("Ma tai khoan khong duoc rong.Vui long nhap lai!\n");
            continue;
        }
        int pos=-1;
        for (int i=0;i<*n;i++) {
            if (strcmp(acc[i].accountId,id)==0) {
                pos = i;
                break;
            }
        }
        if (pos==-1) {
            printf("Khong tim thay tai khoan!\n");
            return;
        }
        printf("\n=>Tim thay tai khoan :\n");
        printf("Id : %s\n",acc[pos].accountId);
        printf("Ten : %s\n",acc[pos].fullName);
        printf("So dien thoai : %s\n",acc[pos].phone);
        printf("Trang thai : %s\n",acc[pos].status==1 ? "Hoat dong" : "Da bi khoa");
        char confirm[5];
        printf("\nBan co muon khoa tai khoan nay(Y/N) ? ");
        fgets(confirm, sizeof(confirm),stdin);
        confirm[strcspn(confirm,"\n")]='\0';
        if (strcasecmp(confirm,"Y") == 0) {
            acc[pos].status = 0;
            printf("\n=>Da khoa tai khoan thanh cong!\n\n");
        } else {
            printf("\n=>Huy thao tac.Tai khoan khong bi khoa.\n\n");
        }
        break;
    }
}
void searchAccount (struct Account acc[],int *n) {
	 if (*n==0) {
        printf("Chua co tai khoan nao!\n\n");
        return;
    }
    char keyWord[50];
    printf("\n-----Tra cuu tai khoan-----\n");
    printf("Nhap ma tai khoan hoac ten can tim : ");
    fgets(keyWord,sizeof(keyWord),stdin);
    keyWord[strcspn(keyWord,"\n")]='\0';
    if (strlen(keyWord)==0) {
        printf("Ma hoac ten tai khoan can tim khong duoc rong.Vui long nhap lai!\n");
        return;
    }
    int found=0;
    for (int i=0;i<*n;i++) {
        if (strstr(acc[i].accountId,keyWord)!=NULL || strstr(acc[i].fullName,keyWord)!=NULL) {
            printf("\n-----Tai khoan %d-----\n",i+1);
            printf("Id : %s\n",acc[i].accountId);
            printf("Ten : %s\n",acc[i].fullName);
            printf("So dien thoai : %s\n",acc[i].phone);
            printf("Trang thai : %s\n",acc[i].status==1 ? "Hoat dong" : "Da bi khoa");
            found = 1;
        }
    }
    if (!found) {
        printf("\nKhong tim thay tai khoan nao!\n");
    }
}	 



