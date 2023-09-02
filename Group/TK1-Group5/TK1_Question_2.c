#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#define BUFFSIZE 200

void membalik(char *s);

int main(){
    char kalimat_1_input[BUFFSIZE], kalimat_2_input[BUFFSIZE], kalimat_3_input[BUFFSIZE];
    char hasil_membalik_kalimat_1[BUFFSIZE], hasil_membalik_kalimat_2[BUFFSIZE], hasil_membalik_kalimat_3[BUFFSIZE];
    char gabungan_3_kalimat[BUFFSIZE], hasil_membalik_3_kalimat[BUFFSIZE];
    int jumlah_huruf_kalimat_1, jumlah_huruf_kalimat_2, jumlah_huruf_kalimat_3, total_jumlah_huruf;

    printf ("Masukkan kalimat-kalimat berikut :\n");

    printf ("Kalimat 1  : ");
    scanf ("%[^\n]%*c", kalimat_1_input);

    printf ("Kalimat 2  : ");
    scanf ("%[^\n]%*c", kalimat_2_input);

    printf ("Kalimat 3  : ");
    scanf ("%[^\n]%*c", kalimat_3_input);

    srand (time (NULL) );
    strcpy (hasil_membalik_kalimat_1, kalimat_1_input);
    membalik (hasil_membalik_kalimat_1);
    strcpy (hasil_membalik_kalimat_2, kalimat_2_input);
    membalik (hasil_membalik_kalimat_2);
    strcpy (hasil_membalik_kalimat_3, kalimat_3_input);
    membalik (hasil_membalik_kalimat_3);
    jumlah_huruf_kalimat_1 = strlen(kalimat_1_input);
    jumlah_huruf_kalimat_2 = strlen(kalimat_2_input);
    jumlah_huruf_kalimat_3 = strlen(kalimat_3_input);
    total_jumlah_huruf = jumlah_huruf_kalimat_1 + jumlah_huruf_kalimat_2 + jumlah_huruf_kalimat_3;
    
    printf ("Gabungan 3 Kalimat Tersebut        : %s %s %s\n", kalimat_1_input, kalimat_2_input, kalimat_3_input);
    printf ("Hasil Membalik 3 Kalimat Tersebut  : %s %s %s\n", hasil_membalik_kalimat_1, hasil_membalik_kalimat_2, hasil_membalik_kalimat_3);
    printf ("Jumlah Huruf Kalimat Pertama       : %d\n", jumlah_huruf_kalimat_1);
    printf ("Jumlah Huruf Kalimat Kedua         : %d\n", jumlah_huruf_kalimat_2);
    printf ("Jumlah Huruf Kalimat Ketiga        : %d\n", jumlah_huruf_kalimat_3);
    printf ("Total Jumlah Huruf                 : %d\n", total_jumlah_huruf);
    

    return 0;

}

void membalik(char *s){
    int panjang = strlen(s);
    for (int i = 0; i < panjang; i++)
    s[i] = tolower (s[i]);
    if (panjang == 1) return;
    if (panjang == 2){
        char sementara = s[0];
        s[0] = s[1];
        s[1] = sementara;
        return;
    }
    char asli[panjang + 1];
    strcpy (asli, s);
    double beda = 0;
    bool awal_sama = false;
    bool akhir_sama = false;
    int saat_tersangkut = 0;
    do{
        int i = 0;
        while (i < panjang){
             int posisi_1 = rand() % panjang;
             int posisi_2 = rand () % panjang;
            if (posisi_1 != posisi_2){
                char sementara = s[posisi_1];
                s[posisi_1] = s[posisi_2];
                s[posisi_2] = sementara;
                i++;
            }
        }
        int perbedaan = 0;
        for (int j = 0; j < panjang; j++)
            if (asli[j] != s[j]) beda++;
        beda = (double) perbedaan / panjang;
        awal_sama = s[0] == asli[0];
        akhir_sama = s[panjang - 1] == asli[panjang - 1];
        saat_tersangkut++;
    } while ( ((awal_sama && akhir_sama) || (beda < 0.5)) && (saat_tersangkut < 100) );

}
