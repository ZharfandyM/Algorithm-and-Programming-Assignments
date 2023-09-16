#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#define BUFFER_SIZE 1000

struct Mahasiswa{
        char nama[50];
        int quis;
        int tugas;
        int absensi;
        int praktek;
        int uas;
        int mean;
        char grade;
        char kelulusan[20];
};

bool parse_m (char *string, int *m){
    int i = 0;

    while (isspace(string[i])) 
        i++;

    int length = strlen (string);

    if (length == 1){
        return false;
    }

    char integer_buffer[BUFFER_SIZE];
    int integer_chars = 0;

    if (string[i] == '-'){
        return false;
    }

    while (i < length && !isspace(string[i])){
        if (!isdigit(string[i])){
            return false;
        }

        integer_buffer[integer_chars] = string[i];

        integer_chars++;
        i++;
    }
    
    integer_buffer[integer_chars] = '\0';

    while (isspace(string[i])) i++;

    if (string[i] != '\0'){
        return false;
    }

    *m = atoi (integer_buffer);

    if (*m < 10){
        return false;
    }

    return true;
}

int main (){
    int total_score = 0, mean_all, check_1, repeat_j, repeat_y, m = 0;
    struct Mahasiswa s[50];
    bool parsed_correct = true;
    
    system ("cls");
    printf ("Selamat datang di program perhitungan nilai.");
    
    do {    
        printf ("\n\n\nMasukkan jumlah mahasiswa (min. 10)  : ");
        char buffer[BUFFER_SIZE];
        fgets (buffer, BUFFER_SIZE, stdin);

        parsed_correct = parse_m (buffer, &m);

        if (!parsed_correct){
            printf ("\nError, minimal 10 mahasiswa.");
        }

    } while (!parsed_correct);
    
    int i = 0;
    printf ("\nPress ""Enter"" to continue ");

    do {
        getchar ();
        printf ("\n\nMasukkan nama mahasiswa ke-%d  : ", i + 1);
        fgets (s[i].nama, 50, stdin);

        //error check

        printf ("Masukkan nilai quis  : ");
        scanf ("%d", &s[i].quis);

        printf ("Masukkan nilai tugas  : ");
        scanf ("%d", &s[i].tugas);

        printf ("Masukkan nilai absensi  : ");
        scanf ("%d", &s[i].absensi);

        printf ("Masukkan nilai praktek  : ");
        scanf ("%d", &s[i].praktek);

        printf ("Masukkan nilai UAS  : ");
        scanf ("%d", &s[i].uas);

        system ("cls");

        i++;

    } while (i < m);

    i = 0;
    
    for (i = 0; i < m; i++){
        s[i].mean = (s[i].quis +  s[i].tugas + s[i].absensi + s[i].praktek + s[i].uas) / 5;
    }

    i = 0;

    do {
        if (s[i].mean <= 55){
            s[i].grade = 'E';
        }
        else if (s[i].mean > 55 && s[i].mean <= 65){
            s[i].grade = 'D';
        }
        else if (s[i].mean > 65 && s[i].mean <= 75){
            s[i].grade = 'C';
        }
        else if (s[i].mean > 75 && s[i].mean <= 85){
            s[i].grade = 'B';
        }
        else if (s[i].mean > 85 && s[i].mean <= 100){
            s[i].grade = 'A';
        }
        else {
        }
        
        i++;

    } while (i < m);

    i = 0;

    do {
        if (s[i].grade == 'E' || s[i].grade == 'D'){
            strcpy (s[i].kelulusan, "Tidak Lulus");
        }
        else if (s[i].grade == 'A' || s[i].grade == 'B' || s[i].grade == 'C'){
            strcpy (s[i].kelulusan, "Lulus");
        }
        else {
        }
        
        i++;

    } while (i < m); 

    i = 0;

    do {
        total_score = total_score + s[i].mean;
        mean_all = total_score / m;  
         
        i++;

    } while (i < m);

    i = 0;
    printf ("Hasil perhitungan nilai  :");

    do {
        printf ("\n\nNama mahasiswa   : %s", s[i].nama);
        printf ("Rata-rata nilai  : %d", s[i].mean);
        printf ("\nGrade  : %c", s[i].grade);
        printf ("\nStatus kelulusan : %s", s[i].kelulusan);
        i++;

    } while (i < m);

    printf ("\n\nJumlah mahasiswa  : %d", m);
    printf ("\nRata-rata nilai keseluruhan mahasiswa  : %d", mean_all);
    printf ("\nTerima kasih telah menggunakan program ini.");

    return 0;
}