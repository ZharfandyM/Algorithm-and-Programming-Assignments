#include <stdio.h>

int main(){
    int detik_input, jam, menit, detik;

    printf ("Masukan jumlah detik yang ingin dikonversi : ");
    scanf ("%d", &detik_input);

    jam = (detik_input % 86400) / 3600;
    menit = (detik_input % 3600) / 60;
    detik = (detik_input % 60);

    printf ("Hasil konversi : Jam = %d  Menit = %d  Detik = %d", jam, menit, detik);

    return 0;
}
