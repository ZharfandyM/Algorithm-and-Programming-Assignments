#include <stdio.h>
#include <ctype.h>          
#include <stdlib.h>         //Libary ctype.h, stdlib.h, string.h, stdbool.h are used for the error check funtion of the input
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 4000        //BUFFER_SIZE is used for the size of the integer_buffer variable

bool parse_int (char *string, int *integer){            //the error check funtion of the input
    int i = 0;

    while (isspace (string[i])) i++;        //skipping every whitespaces in the input

    int length = strlen (string);           //length variable to check the length of the string before \0

    if (length == i) return false;          //if every characters in the input

    char integer_buffer[BUFFER_SIZE];       //integer_buffer variable for storing the input string
    int integer_chars = 0;                  //integer_chars variable for counting the characters in integer_buffer

    if (string[i] == '-') return false;     //if there is a negative that means the input is incorrect

    while (i < length && !isspace (string[i])){         //checking every characters in the input
        if (!isdigit (string[i])) return false;         //if there is something other than an integer in the input, the input is incorrect

        integer_buffer[integer_chars] = string[i];      //assigning every qualified characters into the integer_buffer

        integer_chars++;                                
        i++;
    }

    integer_buffer[integer_chars] = '\0';           //adding \0 into the end of the integer_buffer

    while (isspace (string[i])) i++;                //skipping every whitespaces at the end of the input

    if (string[i] != '\0') return false;            //if there is still something after the \0 the input is incorrect

    *integer = atoi (integer_buffer);               //assigning the input into the integer variable

    if (*integer <= 0) return false;

    return true;
}

int main(){
    int mo, mt, w, p;       //mo = jumlah tabungan mula-mula (Rp), mt = jumlah tabungan setelah waktu tertentu (Rp), w = lamanya menabung (tahun), p = persentase bunga (%)
    char repeat;
    bool parsed_correct = true;     //variable for the return value from the error check function

    system ("cls");

    printf ("Selamat datang di program perhitungan jumlah tabungan.");

    do {    
        do {
            printf ("\n\nMasukkan Jumlah Tabungan Mula-mula  : Rp ");  

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

            parsed_correct = parse_int (buffer, &mo);      //calling the error check funtion

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct); 

        do {
            printf ("\nMasukkan Lama Menabung (Tahun)  : ");

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

            parsed_correct = parse_int (buffer, &w);      //calling the error check funtion

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct); 

        do {
            printf ("\nMasukkan Presentase Bunga (Persen)  : ");

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

            parsed_correct = parse_int (buffer, &p);      //calling the error check funtion

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct); 

        mt = mo * (1 + w * (p * 0.01) );        //the formula for the result of mt

        printf ("\n\nJumlah tabungan setelah %d tahun adalah  : Rp %d", w, mt);

        do {
            printf ("\n\nApakah anda ingin menghitung lagi? (Y/N) ");           //asking if the user wants to repeat the program                 
            scanf (" %c", &repeat);
                
            if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                printf ("\nInput salah.");
            }
            else{
            }

        } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');     //if the input is neither of (Y,y,N,n) repeat the asking statement
    
    } while (repeat == 'Y' || repeat == 'y');          //if the user input either one of (Y,y) repeat the program    

    printf ("\n\nTerima kasih.");  
  
    return 0;
}