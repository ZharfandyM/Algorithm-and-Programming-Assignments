#include <stdio.h>
#include <stdlib.h>

int main(){
    int km_input, hasil_m, hasil_cm;

    printf ("Masukkan nilai km  : ");
    scanf ("%d", &km_input);
    
    hasil_m = km_input * 1000;
    hasil_cm = km_input * 100000;
    
    getchar ();
    printf ("%d = %d m", km_input, hasil_m);

    getchar ();
    printf ("%d = %d cm", km_input, hasil_cm);
    
    return 0;
}
