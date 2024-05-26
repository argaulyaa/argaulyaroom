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
FILE *fp;
void admin();
void loginadmin(int);
void menuutamaadmin();
void loginuser(int);
int main()
{
    int pilihan;
    printf("============== Arssanis Lombok Island ===========\n");
    printf("\n= (1) Masuk sebagai admin\t\t\t=\n= (2) Masuk sebagai user\t\t\t=\n= (3) Keluar\t\t\t\t\t=");
    printf("\n=================================================");
    printf("\nPilih : ");
    scanf("%d", &pilihan);
    getchar();
    system("cls");
    switch (pilihan)
    {
    case 1:
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
        printf("Login berhasil");
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
    printf("==========Menu Admin==========\n");
    printf("1. Tambah daftar wisata\n2. Hapus daftar wisata\n3. Cek daftar wisata yang telah dibooking\n4. Lihat customer\n5.Keluar\n");
    printf("Pilih : ");
    scanf("%d", &in);
    getchar();
    switch (in)
    {
    case 1:
        tambahdaftarwisata();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        exit(0);
        break;

    default:
        break;
    }
}
void tambahdaftarwisata()
{
}
void hapusdaftarwisata() {}
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
    printf("1. Booking tiket wisata\n2. Lihat daftar wisata\3. Rechedule\n4. Refund\n5. Keluar\n");
    scanf("%d", &yy);
    switch (yy)
    {
    case 1:
        lihatdaftarwisata();
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
}
void lihatdaftarwisata()
{
    printf("=========== Daftar wisata ===========\n1. Pink beach\n2. Pulau  komodo\n3. Taka Makasar\n");
    printf("4. Pulau padar\n5. Gili trawangan lombok\n6. Gili nanggu\n7. Gili kedis\n");
    printf("8. Pantai kuta lombok\n9. Bukit merese\n");
}