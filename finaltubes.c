#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
struct
{
    char nama[100], uname[100], pass[20], pitbek[100], hp[20];
    ;
} datacustomer, datacustomer2, datacustomertemp[100], temp;

struct
{
    char wisata[100];
    int harga;
} datawisata, datawisatatemp[100], temp1;
struct
{
    char feedback[100];
} ulasan;
struct
{
    char uname[100];
    char wisata[100];
} booking;
FILE *fp;
void admin();
void loginadmin(int);
void menuutamaadmin();
void tambahdaftarwisata();
void hapusdaftarwisata();
void user();
void loginuser(int);
void signupuser();
void menuutamauser();
void bookingtiket();
void lihatdaftarwisata();
void lihatwisatadibooking();
void lihatcustomer();
int main()
{
    int pilihan;
    printf("============== Arssanis Lombok Island ===========\n");
    printf("\n= (1) Masuk sebagai admin\t\t\t=\n= (2) Masuk sebagai user\t\t\t=\n= (3) Keluar\t\t\t\t\t=");
    printf("\n=================================================");
    printf("\nPilih : ");
    scanf("%d", &pilihan);
    getchar();
    switch (pilihan)
    {
    case 1:
    system("cls");
        admin();
        break;
    case 2:
        user();
        break;
    case 3:
        break;

    default:
        break;
    }
}
void admin()
{
    loginadmin(3);
    menuutamaadmin();
}
void loginadmin(int x)
{
    char uname[100], pass[20];
    printf("Masukkan nama admin\t: ");
    gets(uname);
    printf("Masukkan password admin : ");
    gets(pass);
    if (x > 1 && (strcmp(uname, "a") == 0 && strcmp(pass, "a") == 0))
    {
        printf("Login berhasil\n");
        system("pause");
    }
    else if (x > 1 && (strcmp(uname, "a") != 0 && strcmp(pass, "a") != 0))
    {
        x--;
        system("cls");
        printf("Username atau password salah!\nKesempatan anda sisa %d\n", x);
        loginadmin(x);
    }
    else
    {
        system("cls");
        printf("Gagal login\n");
        system("pause");
        system("cls");
        main();
    }
}

void menuutamaadmin()
{
    int in;
    system("cls");
    printf("==========Menu Admin==========\n");
    printf("1. Cek wisata yang telah dibooking\n2. Lihat customer\n3. Keluar\n");
    printf("Pilih : ");
    scanf("%d", &in);
    getchar();
    switch (in)
    {
    case 1:
    lihatwisatadibooking();
    menuutamaadmin();
        break;
    case 2:
    lihatcustomer();
    system("cls");
    menuutamaadmin();
        break;
    case 3:
    main();
        break;

    default:
        break;
    }
}
void lihatwisatadibooking(){
    system("cls");
    printf("====== Daftar Wisata yang Telah Dibooking ======\n");
    FILE *fp_booking = fopen("booking.dat", "rb");
    if (fp_booking == NULL) {
        printf("Belum ada wisata yang dibooking.\n");
        return;
    }

    while (fread(&booking, sizeof(booking), 1, fp_booking)) {
        printf("Username: %s, Wisata: %s\n", booking.uname, booking.wisata);
    }

    fclose(fp_booking);
    system("pause");
}
void lihatcustomer(){
    int n = 0;
    fp = fopen("user.dat", "rb");
    if (fp == NULL)
    {
        printf("Belum ada customer yang terdaftar.\n");
        return;
    }
    while (fread(&datacustomertemp[n], sizeof(datacustomer), 1, fp))
    {
        n++;
    }
    fclose(fp);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(datacustomertemp[j].uname, datacustomertemp[j + 1].uname) > 0)
            {
                temp = datacustomertemp[j];
                datacustomertemp[j] = datacustomertemp[j + 1];
                datacustomertemp[j + 1] = temp;
            }
        }
    }
    printf("========== Daftar Customer ==========\n");
    for (int i = 1; i < n; i++)
    {
        printf("Username: %s, Nomer HP: %s\n", datacustomertemp[i].uname, datacustomertemp[i].hp);
    }
    system("pause");
    
}
void user()
{
    int up;
    printf("======Menu User======\n");
    printf("Sudah punya akun?\n");
    printf("1. Sudah\n2. Belum\n");
    printf("Pilih : ");
    scanf("%d", &up);
    getchar();
    switch (up)
    {
    case 1:
        loginuser(3);
        break;
    case 2:
        signupuser();
        loginuser(3);
        break;

    default:
        break;
    }
}
void loginuser(int y)
{
    char uname[100], pass[20];
    bool cek = false;
    fp = fopen("user.dat", "rb");
    system("cls");
    printf("= = = = Login = = = =\n");
    printf("Masukkan username : ");
    gets(uname);
    printf("Masukkan password : ");
    gets(pass);
    while (fread(&datacustomer, sizeof(datacustomer), 1, fp) == 1)
    {
        if (strcmp(uname, datacustomer.uname) == 0 && strcmp(pass, datacustomer.pass) == 0)
        {
            cek = true;
            break;
        }
        else
        {
            cek = false;
        }
    }

    if (y > 1 && cek == true)
    {
        printf("Login berhasil\n");
        fclose(fp);
        menuutamauser();
    }
    else if (y > 1 && cek == false)
    {
        y--;
        printf("Username atau password salah\n");
        printf("Kesempatan anda tinggal %d kali\n", y);
        system("pause");
        fclose(fp);
        loginuser(y);
    }
    else
    {
        printf("Login gagal\n");
        main();
    }
}
void signupuser()
{
    system("cls");
    printf("= = = = Daftar = = = =\n");
    fp = fopen("user.dat", "ab");
    printf("Buat username\t\t: ");
    gets(datacustomer.uname);
    printf("Buat password\t\t: ");
    gets(datacustomer.pass);
    printf("Masukkan nomer hp : ");
    gets(datacustomer.hp);
    fwrite(&datacustomer, sizeof(datacustomer), 1, fp);
    fclose(fp);
}
void menuutamauser()
{
    int yy;
    system("cls");
    printf("====== Selamat Datang, Selamat Liburan ======\n");
    printf("1. Booking tiket wisata\n2. Lihat daftar wisata\n3. Rechedule\n4. Refund\n5. Keluar\nPilih : ");
    scanf("%d", &yy);
    switch (yy)
    {
    case 1:
        bookingtiket();
        break;
    case 2:
        lihatdaftarwisata();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;

    default:
        break;
    }
}
void bookingtiket()
{
    int pilihan;
    lihatdaftarwisata();
    printf("Pilih wisata yang ingin dibooking (1-9): ");
    scanf("%d", &pilihan);
    getchar();

    switch (pilihan)
    {
    case 1:
        strcpy(booking.wisata, "Pink beach");
        break;
    case 2:
        strcpy(booking.wisata, "Pulau Komodo");
        break;
    case 3:
        strcpy(booking.wisata, "Taka Makasar");
        break;
    case 4:
        strcpy(booking.wisata, "Pulau Padar");
        break;
    case 5:
        strcpy(booking.wisata, "Gili Trawangan Lombok");
        break;
    case 6:
        strcpy(booking.wisata, "Gili Nanggu");
        break;
    case 7:
        strcpy(booking.wisata, "Gili Kedis");
        break;
    case 8:
        strcpy(booking.wisata, "Pantai Kuta Lombok");
        break;
    case 9:
        strcpy(booking.wisata, "Bukit Merese");
        break;
    default:
        printf("Pilihan tidak valid.\n");
        return;
    }

    strcpy(booking.uname, datacustomer.uname);

    FILE *fp_booking;
    fp_booking = fopen("booking.dat", "ab");
    fwrite(&booking, sizeof(booking), 1, fp_booking);
    fclose(fp_booking);

    printf("Booking berhasil untuk %s\n", booking.wisata);
    system("pause");
}
void lihatdaftarwisata()
{
    system("cls");
    printf("=========== Daftar Wisata ===========\n");
    printf("1. Pink Beach\n");
    printf("2. Pulau Komodo\n");
    printf("3. Taka Makasar\n");
    printf("4. Pulau Padar\n");
    printf("5. Gili Trawangan Lombok\n");
    printf("6. Gili Nanggu\n");
    printf("7. Gili Kedis\n");
    printf("8. Pantai Kuta Lombok\n");
    printf("9. Bukit Merese\n");
    printf("=====================================\n");
}
