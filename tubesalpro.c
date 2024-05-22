#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

struct{
    char nama[100], pass[20];
}user;
void login(int);
void loginadmin(int);
void loginuser();
void signup();
int main(){
int berhasilloginadmin = 0, pilih, n = 3;
    printf("SELAMAT DATANG DI ARSSANIS LOMBOK ISLAND\n");
    printf("LOGIN SEBAGAI :\n");
    printf("1.ADMIN\n2.USER\n3.KELUAR\n");
    printf("PILIH : "); scanf("%d", &pilih);
    getchar();
    switch (pilih)
    {
    case 1:
    system("cls");
        loginadmin(n);
        break;
    
    default:
        break;
    }
}
void loginadmin(int x){
    char namaadmin[100], sandiadmin[20];
    printf("Masukkan username : ");
    gets(namaadmin);
    printf("Masukkan password : ");
    gets(sandiadmin);
    if (strcmp(namaadmin, "1") == 0 && strcmp(sandiadmin, "1") == 0)
    {
        printf("BERHASIL LOGIN");
    }
    else
    {
        if (x > 1)
        {
            system("cls");
            printf("Username atau password salah!!!\n");
            printf("sisa kesempatan login : %d\n", x - 1);
            system("pause");
            getchar();
            system("cls");
            loginadmin(x - 1);
        }
        else
        {
            system("cls");
            printf("Anda mencapai batas maksimum login!!!\n");
        }
    }
}

void loginuser(){
    int milih;
    printf("Apakah anda sudah memiliki akun?\n");
    printf("PILIH : ");
    scanf("%d", &milih);
    switch (milih)
    {
    case 1:
    system("cls");
    printf("LOGIN");
    login(3);

        break;
    
    default:
        break;
    }
}
void login(int x){
    char username [100], sandi[20];
    printf("Masukkan username akun\t: ");
    gets(username);
    printf("Masukkan password\t: ");
    gets(sandi);
    FILE *file = fopen("user.dat", "rb");
    while(fread(&user, sizeof(user),1,file)==1){

    }
    if (strcmp(username, user.nama) == 0 && strcmp(sandi, user.pass)==0)
    {
        printf("BERHASIL LOGIN");
        berhasilloginadmin = 1;
    }
    else {
        if (x > 1)
        {
            system("cls");
            printf("Username atau password salah!!!\n");
            printf("sisa kesempatan login : %d\n", x - 1);
            system("pause");
            getchar();
            system("cls");
            loginadmin(x - 1);
        }
        else
        {
            system("cls");
            printf("Anda mencapai batas maksimum login!!!\n");
        }
    }
}
