#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int i = 1, total_belanja_input, persen_diskon, diskon_jumlah_pembelian, potongan_harga, total_belanja_diskon_harga;
    char yes;

    printf ("Selamat datang di program perhitungan kasir.\n");

    do {
        printf ("\n\nMasukkan total belanja : Rp. ");
        scanf ("%d", &total_belanja_input);
        
        if (i == 4){
        diskon_jumlah_pembelian = 20;
        }
        else {
        diskon_jumlah_pembelian = 0;
        }

        if (total_belanja_input < 200000){
        printf ("Diskon yang anda peroleh   : 0%%");
        }
        else if (total_belanja_input >= 200000 && total_belanja_input <= 500000){
        printf ("Diskon yang anda peroleh   : 10%%");
        }
        else if (total_belanja_input >= 550000 && total_belanja_input <= 1000000){
        printf ("Diskon yang anda peroleh   : 20%%");
        }
        else if (total_belanja_input > 1000000){
        printf ("Diskon yang anda peroleh   : 30%%");
        }
        else {
        }

        if (total_belanja_input < 200000){
        printf ("\nPotongan harga yang anda peroleh   : Rp. %d", total_belanja_input * 1);
        }
        else if (total_belanja_input >= 200000 && total_belanja_input <= 500000){
        printf ("\nPotongan harga yang anda peroleh   : Rp. %d", total_belanja_input * 10 / 100);
        }
        else if (total_belanja_input >= 550000 && total_belanja_input <= 1000000){
        printf ("\nPotongan harga yang anda peroleh   : Rp. %d", total_belanja_input * 20 / 100);
        }
        else if (total_belanja_input > 1000000){
        printf ("\nPotongan harga yang anda peroleh   : Rp. %d", total_belanja_input * 30 / 100);
        }
        else {
        }

        printf ("\nEkstra diskon pembelian  : %d%%", diskon_jumlah_pembelian);

        if (total_belanja_input < 200000){
        printf ("\nJumlah harga yang perlu dibayar    : Rp. %d", total_belanja_input - (total_belanja_input * diskon_jumlah_pembelian / 100));
        }
        else if (total_belanja_input >= 200000 && total_belanja_input <= 500000){
        printf ("\nJumlah harga yang perlu dibayar    : Rp. %d", total_belanja_input - (total_belanja_input * (10 + diskon_jumlah_pembelian) / 100));
        }
        else if (total_belanja_input >= 550000 && total_belanja_input <= 1000000){
        printf ("\nJumlah harga yang perlu dibayar    : Rp. %d", total_belanja_input - (total_belanja_input * (20 + diskon_jumlah_pembelian) / 100));
        }
        else if (total_belanja_input > 1000000){
        printf ("\nJumlah harga yang perlu dibayar    : Rp. %d", total_belanja_input - (total_belanja_input * (30 + diskon_jumlah_pembelian) / 100));
        }
        else {
        }
        
        printf ("\n\nAnda sudah belanja sebanyak  : %d kali", i);    
        
        printf ("\n\nApakah anda ingin berbelanja lagi? (Y/N)   : ");
        scanf (" %c", &yes);
        
        i++;
    } while (yes == 'y' || yes == 'Y');

    printf ("\n\nTerima kasih.");

    return 0;
}