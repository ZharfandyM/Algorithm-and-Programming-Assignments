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

    if (length == i) return false;          //if every characters in the input is whitespaces, the input is incorrect

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

int main (){
    int total_pembelian, total_bayar;
    char diskon[5], repeat;
    bool parsed_correct = true;         //variable for the return value from the error check function

    do {
        system ("cls");         //clear the screen
        printf ("Selamat datang di program belanja.");
        printf ("\n(Press Enter to start)");

        do {
            getchar ();         //taking extra empty character
            system ("cls");
            printf ("\n\nMasukkan total belanja  : Rp ");

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);

            parsed_correct = parse_int (buffer, &total_pembelian);      //calling the error check funtion

            if (!parsed_correct) {
                printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."
                printf ("\n(Press Enter to re-enter)");
            }
            
        } while (!parsed_correct);          //if the input is incorrect, repeat the statements

        if (total_pembelian >= 100000){
            strcpy (diskon, "10%");         //assigning "10%" into the diskon variable
            total_bayar = total_pembelian - (total_pembelian * 0.1);            //calculating the total price after discount

            printf ("\n\nSelamat anda mendapatkan diskon sebesar  : %s", diskon);
            printf ("\nJumlah harga yang perlu anda bayar adalah sebesar  : Rp %d", total_bayar);
        }
        else if (total_pembelian >= 0 && total_pembelian < 100000){
            total_bayar = total_pembelian;          //no discount

            printf ("\n\nMohon maaf anda belum mendapatkan diskon.");
            printf ("\nJumlah harga yang perlu anda bayar adalah sebesar  : Rp %d", total_bayar);
        }

        do {
            printf ("\n\nApakah anda ingin berbelanja lagi? (Y/N) ");           //asking if the user wants to repeat the program
            scanf (" %c", &repeat);
            
            if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                printf ("\nInput salah.");
            }
            else{
            }

        } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');     //if the input is neither of (Y,y,N,n) repeat the asking statement
        
    } while (repeat == 'Y' || repeat == 'y');           //if the user input either one of (Y,y) repeat the program

    printf ("\nTerima kasih.");

    return 0;
}