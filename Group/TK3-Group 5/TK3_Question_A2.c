#include <stdio.h>
#include <ctype.h>          
#include <stdlib.h>         //Libary ctype.h, stdlib.h, string.h, stdbool.h are used for the error check funtion of the input
#include <string.h>
#include <stdbool.h>        

#define BUFFER_SIZE 4000        //BUFFER_SIZE is used for the size of the integer_buffer variable

struct data_pegawai{        //struct data type to store data of the pegawai
    int nip;
    char nama[50];
    char alamat[100];
    int no_hp;
    char jabatan[20];
    char golongan[2];
    int gaji_pokok;
    int jam_lembur;
    int gaji_lembur;
    int gaji_total;
};

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

int main (){
    int jumlah_pegawai;
    char repeat;
    bool parsed_correct = true;     //variable for the return value from the error check function
    struct data_pegawai p;      //initializing p variable with struct data_pegawai data type

    system ("cls");
    printf ("Selamat datang di program perhitungan gaji pegawai.");
    printf ("\n(Press Enter to start)");


    do {
        getchar ();         //taking extra empty character
        system ("cls");

        do {
            printf ("\n\nMasukkan NIP  : ");

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

            parsed_correct = parse_int (buffer, &p.nip);      //calling the error check funtion

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct); 

        do {
            printf ("Masukkan Nama  : ");
            fgets (p.nama, 50, stdin);

            if (isalpha (*p.nama) == 0){
                printf ("\nEror, input salah.\n");      //error check for the Nama input
            }

        } while (isalpha (*p.nama) == 0);       //if the input is not consists of alphabet, the input is incorrect

        do {
            printf ("Masukkan Alamat  : ");
            fgets (p.alamat, 100, stdin);

            if (isalpha (*p.alamat) == 0){
                printf ("\nEror, input salah.\n");      //error check for the Alamat input
            }

        } while (isalpha (*p.alamat) == 0);         //if the input is not consists of alphabet, the input is incorrect

        do {
            printf ("Masukkan No. HP  : ");
            
            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);

            parsed_correct = parse_int (buffer, &p.no_hp);      //calling the error check funtion

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct); 
        
        do {
            printf ("Masukkan Jabatan  : ");
            fgets (p.jabatan, 20, stdin);

            if (isalpha (*p.jabatan) == 0){
                printf ("\nEror, input salah.\n");          //error check for the Jabatan input
            }

        } while (isalpha (*p.jabatan) == 0);            //if the input is not consists of alphabet, the input is incorrect

        do {
            printf ("Masukkan Golongan  : ");
            scanf (" %s", &p.golongan);

            if (p.golongan[1] < 49 || p.golongan[1] > 51){          //error check for the Golongan input
                printf ("\nEror, input salah.\n");
            }

        } while (p.golongan[1] < 49 || p.golongan[1] > 51);         //if the second input is not a character with ASCII value between 49 and 51, the input is wrong
                                                                    
        if (p.golongan[1] == 49){           //if the second character of the input is a character with ASCII value of 49, assign 2500000 to p.gaji_pokok
            p.gaji_pokok = 2500000;
        }
        else if (p.golongan[1] == 50){         //if the second character of the input is a character with ASCII value of 50, assign 2000000 to p.gaji_pokok
            p.gaji_pokok = 2000000;
        }
        else if (p.golongan[1] == 51){          //if the second character of the input is a character with ASCII value of 51, assign 1500000 to p.gaji_pokok
            p.gaji_pokok = 1500000;
        }
        else{
        }

        printf ("Gaji Pokok = Rp %d", p.gaji_pokok);

        do {
            getchar ();
            printf ("\n\nMasukkan NIP  : ");

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);

            parsed_correct = parse_int (buffer, &p.nip);      //calling the error check funtion

            if (!parsed_correct) {
                printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."
                printf ("\n(Press Enter to re-enter)");
            }
            
        } while (!parsed_correct); 

        do {
            printf ("Masukkan Golongan  : ");
            scanf (" %s", &p.golongan);

            if (p.golongan[1] < 49 || p.golongan[1] > 51){          //error check for the golongan input
                printf ("\nEror, input salah.\n");
            }

        } while (p.golongan[1] < 49 || p.golongan[1] > 51);         //if the second input is not a character with ASCII value between 49 and 51, the input is wrong

        do {
            getchar ();
            printf ("Masukkan jumlah jam lembur  : ");
            
            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);

            parsed_correct = parse_int (buffer, &p.jam_lembur);      //calling the error check funtion

            if (!parsed_correct) {
                printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."
                printf ("\n(Press Enter to re-enter)");
            }

        } while (!parsed_correct); 

        if (p.golongan[1] == 49){
            p.gaji_lembur = p.jam_lembur * 10000;           //if the second character of the input is a character with ASCII value of 49, p.gaji_lembur = p.jam_lembur * Rp 10000
            p.gaji_total = p.gaji_lembur + p.gaji_pokok;              
            printf ("Gaji Pokok = Rp %d", p.gaji_total);        
        }
        else if (p.golongan[1] == 50){
            p.gaji_lembur = p.jam_lembur * 5000;
            p.gaji_total = p.gaji_lembur + p.gaji_pokok;        //if the second character of the input is a character with ASCII value of 50, p.gaji_lembur = p.jam_lembur * Rp 5000  
            printf ("Gaji Pokok = Rp %d", p.gaji_total);
        }
        else if (p.golongan[1] == 51){
            p.gaji_lembur = p.jam_lembur * 2500;
            p.gaji_total = p.gaji_lembur + p.gaji_pokok;            //if the second character of the input is a character with ASCII value of 51, p.gaji_lembur = p.jam_lembur * Rp 2500
            printf ("Total gaji bulan ini = Rp %d", p.gaji_total);
        }

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