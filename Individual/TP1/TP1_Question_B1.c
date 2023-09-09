#include <stdio.h>
#include <stdlib.h>

int main(){
    int km_input, hasil_m, hasil_cm;

    printf ("Masukkan nilai km  : ");
    scanf ("%d", &km_input);
    
    hasil_m = km_input * 1000;
    hasil_cm = km_input * 100000;
    
    getchar ();
    printf ("%d Km = %d m", km_input, hasil_m);

    getchar ();
    printf ("%d Km = %d Cm", km_input, hasil_cm);
    
    return 0;
}
