#include <stdio.h>
#include <stdlib.h>     //Library stdlib.h digunakan untuk clear screan

int perhitungan (int jam, int harga){       //Function untuk menghitung harga

    if (jam > 0 && jam <= 4){
        harga = jam * 10000;
    }
    else if (jam > 4 && jam <= 6){
        harga = jam * 10000 - (jam * 10000 * 0.1);      //Rumus untuk menghitung harga setelah diskon
    }
    else if (jam > 6 && jam <= 8){
        harga = jam * 10000 - (jam * 10000 * 0.15);
    }
    else if (jam > 8 && jam <= 10){
        harga = jam * 10000 - (jam * 10000 * 0.2);
    }
    else if (jam > 10){
        harga = jam * 10000 - (jam * 10000 * 0.25);
    }
    else {
    }

    return harga;
}

int main (){
    int lama_bermain = 0, jam, harga;       //int lama_bermain = 0 untuk ditambah dengan jam bermain
    char play_again;        //char play_again untuk looping Do While

    do {
        printf ("Selamat datang di program perhitungan game online.");
        printf ("\n\nMasukkan berapa lama anda ingin bermain (jam)  : ");

        if (scanf ("%d", &jam) == 1){    
            if (jam > 0){
                int harga = perhitungan (jam, harga);       //Function untuk menghitung harga digunakan       

                printf ("Harga yang perlu anda bayar senilai  : Rp. %d", harga);
        
                lama_bermain = lama_bermain + jam;      //Rumus untuk menghitung jumlah lama bermain
                printf ("\nAnda sudah bermain selama %d jam", lama_bermain);      
            }
            else if (jam <= 0){     //Error check untuk input jam                             
                printf ("Error, input yang anda masukkan salah.");
            }
        }
        else {
            printf ("Error, input yang anda masukkan salah.");
        }

        do {
            getchar ();     //getchar digunakan untuk mengambil white space agar scanf bisa berjalan
            printf ("\n\nIngin bermain? (Y/N)  : ");      
            scanf (" %c", &play_again);
        
            if (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N'){      //Error check untuk input Y/N
            printf ("Error, input yang anda masukkan salah.");
            }
            else{
            }

        } while (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N');     //Looping untuk mengulang "Ingin bermain?"

        system("cls");      //Digunakan untuk clear screan

    } while (play_again == 'y' || play_again == 'Y');

    printf ("\nTerima kasih.");

    return 0;
}