#include <stdio.h>
#include <ctype.h>          
#include <stdlib.h>         //Libary ctype.h, stdlib.h, string.h, stdbool.h are used for the error check funtion of the input
#include <string.h>
#include <stdbool.h> 

#define BUFFER_SIZE 4000        //BUFFER_SIZE is used for the size of the integer_buffer variable
#define MAX_LINE 2048           //MAX_LINE is used for the size of the maximum characters from a single line

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

    if (*integer <= 0) return false;                //if the user input an integer less than 1, the input is incorrect

    return true;
}

int main (){
    bool parsed_correct = true;         //a bool variable for the integers input error check
    int menu, delete_line = 0;          //menu variable is used for the menu selection input, delete_line variable is used for the line deleting selection input
    char buffer[BUFFER_SIZE], buffer_dp[MAX_LINE], buffer_db[MAX_LINE], repeat, input_db[256], output_dp, output_db, input_dp[256], back;       //db means data buku, dp means data pembelian, back variable is used for the back to the menu selection input
    
    FILE *filedb, *filedp, *tempdp, *tempdb;           //db means data buku, dp means data pembelian, temp variable is used for the deleting line menu
    
    do {
        filedb = fopen ("databuku.txt", "r");           //open the file "databuku.txt" in reading mode

        printf ("Program Toko Buku\n\n");
        
        printf ("Menu :\n\n");
        printf ("(1) Input\n");
        printf ("(2) View History\n");
        printf ("(3) View Data Buku\n");            //print the menu selections
        printf ("(4) Pembelian\n");
        printf ("(5) Delete History\n");
        printf ("(6) Delete Buku\n");
        printf ("(7) Exit\n\n");

        do {
            printf ("Pilih menu  : ");          //asking the user to input the selected menu

            fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

            parsed_correct = parse_int (buffer, &menu);      //calling the error check funtion

            if (menu > 7) parsed_correct = false;       //if the user input an integer greater than 7, the input is incorrect

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct);      //repeat the statements if the input is incorrect

        fclose (filedb);        //close the file with file handle filedb

        if (menu == 1){
            do {
                filedb = fopen ("databuku.txt", "a");           //open the file "databuku.txt" with append mode

                printf ("\nMenu Input\n\n");

                printf ("Masukkan data buku  : ");          
                fgets (input_db, 256, stdin);

                fprintf (filedb, "%s", input_db);           //write the use input into the filedb

                fclose (filedb);            //close the file
    
                do {
                    printf ("\n\nApakah anda ingin menghitung lagi? (Y/N)  : ");           //asking if the user wants to repeat the program                 
                    scanf (" %c", &repeat);
                        
                    if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                        printf ("\nInput salah.");
                    }
                    else{
                    }

                    getchar ();         //getchar is used to take the whitespace

                } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');     //if the input is incorrect, repeat the statements

            } while (repeat == 'Y' || repeat == 'y');       
        }
        else if (menu == 2){
            filedp = fopen ("datapembelian.txt", "r");          //open the file "datapembelian.txt" in reading mode

            printf ("\nMenu View History\n\n");
            printf ("History Penjualan  : \n");         

            while ( (output_dp = fgetc (filedp)) != EOF){           //while the value of the assigned character is not the end of file, print the character
                putchar (output_dp);
            } 

            fclose (filedp);        //close the file

            do {
                printf ("\nInput 'M' untuk kembali ke menu  : ");
                scanf (" %c", &back);
                
                if (back != 'M' && back != 'm'){      //if the input is neither of (M,m) the input is incorrect
                    printf ("\nInput salah.");
                }
                else{
                }

                getchar ();         //getchar is used to take the whitespace

            } while (back != 'M' && back != 'm');       //if the input is incorrect, repeat the statements
        }
        else if (menu == 3){
            filedb = fopen ("databuku.txt", "r");       //open the file "databuku.txt" in reading mode

            printf ("\nMenu View Data Buku\n\n");
            printf ("Data Buku  : \n");

            while ( (output_db = fgetc (filedb)) != EOF){       //while the value assigned from the file is not the end of file, print the character
                putchar (output_db);
            } 

            fclose (filedb);        //close the file

            do {
                printf ("\nInput 'M' untuk kembali ke menu  : ");
                scanf (" %c", &back);
                
                if (back != 'M' && back != 'm'){      //if the input is neither of (M,m) the input is incorrect
                    printf ("\nInput salah.");
                }
                else{
                }

                getchar ();         //getchar is used to take the whitespace

            } while (back != 'M' && back != 'm');       //if the input is incorrect, repeat the statements
        }
        else if (menu == 4){
            do {
                filedp = fopen ("datapembelian.txt", "a");          //open the file "datapembelian.txt" in append mode

                filedb = fopen ("databuku.txt", "r");              //open the file "databuku.txt" in reading mode

                printf ("\nData Buku  : \n");

                while ( (output_db = fgetc (filedb)) != EOF){       //while the value of the character assigned to output_db is not the end of the file, print the character
                    putchar (output_db);
                } 

                fclose (filedb);        //close the file "databuku.txt"

                printf ("\nMasukkan nama dan jumlah buku  : ");
                fgets (input_dp, 256, stdin);

                fprintf (filedp, "%s", input_dp);           //writing the user input into the file "datapembelian.txt"

                fclose (filedp);

                do {
                    printf ("\n\nPembelian lagi? (Y/N)  : ");           //asking if the user wants to repeat the program                 
                    scanf (" %c", &repeat);
                            
                    if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                        printf ("\nInput salah.");
                    }
                    else{
                    }

                    getchar ();         //getchar is used to take the whitespace

                } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');         //if the user input is incorrect, repeat the statements

            } while (repeat == 'Y' || repeat == 'y');
        }
        else if (menu == 5){
            do {
                filedp = fopen ("datapembelian.txt", "r");          //open the file "datapembelian.txt" in reading mode

                printf ("\nMenu Delete History\n\n");

                printf ("History Penjualan  : \n");

                while ( (output_dp = fgetc (filedp)) != EOF){       //while the value assigned to output_dp is not the end of file, print the character
                    putchar (output_dp);
                } 

                fclose (filedp);        //close the file "datapembelian.txt"

                do {
                    printf ("\n\nInput line yang akan dihapus  : ");

                    fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

                    parsed_correct = parse_int (buffer, &delete_line);      //calling the error check funtion

                    if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

                } while (!parsed_correct); 

                filedp = fopen ("datapembelian.txt", "r");                  //open the file "datapembelian.txt" in reading mode
                tempdp = fopen ("temp____datapembelian.txt", "w");          //the file "temp____datapembelian.txt" is used for storing the file from "datapembelian.txt" without the deleted line

                bool keep_reading = true;           //keep_reading variable is used for the loop statements of reading the file which has the line we want to delete
                int current_line = 1;           //current_line variable is used to count the current line that the program is reading

                do {
                    fgets (buffer_dp, MAX_LINE, filedp);            //reading the strings "datapembelian.txt" and storing them in the buffer variable

                    if (feof (filedp)) keep_reading = false;            //if the program reach the end of file, stop reading
                    
                    else if (current_line != delete_line){          //if the current line is not the line we want to delete, store the strings into the temporary file 
                        fputs (buffer_dp, tempdp);
                    }
                    current_line++;         //increament current_line for counting the line the program currently reading

                } while (keep_reading);         //keep reading the file while keep_reading is true

                fclose (filedp);            //close the file "datapembelian.txt"
                fclose (tempdp);            //close the file "temp____datapembelian.txt"

                remove ("datapembelian.txt");               //remove the old "datapembelian.txt" file                     
                rename ("temp____datapembelian.txt", "datapembelian.txt");          //rename the "temp____datapembelian.txt" with "datapembelian.txt"

                printf ("\nData Successfully Deleted.");            //noticing the user that the line is deleted

                do {
                    printf ("\n\nHapus data lagi? (Y/N)  : ");           //asking if the user wants to repeat the program                 
                    scanf (" %c", &repeat);
                            
                    if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                        printf ("\nInput salah.");
                    }
                    else{
                    }

                    getchar ();         //getchar is used to take the whitespace

                } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');         //while the input is incorrect, repeat the statements

            } while (repeat == 'Y' || repeat == 'y');
        }
        else if (menu == 6){
            do {
                filedb = fopen ("databuku.txt", "r");           //open the file "databuku.txt" in reading mode

                printf ("\nMenu Delete Data Buku\n\n");

                printf ("Data Buku  : \n");

                while ( (output_db = fgetc (filedb)) != EOF){           //while the value assigned to output_db is not the end of file, print the character
                    putchar (output_db);
                } 

                fclose (filedb);            //close the file "databuku.txt"

                do {
                    printf ("\n\nInput line yang akan dihapus  : ");

                    fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

                    parsed_correct = parse_int (buffer, &delete_line);      //calling the error check funtion

                    if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

                } while (!parsed_correct); 

                filedb = fopen ("databuku.txt", "r");           //open the file "databuku.txt" in reading mode
                tempdb = fopen ("temp____databuku.txt", "w");       //the file "temp____databuku.txt" is used for storing the file from "databuku.txt" without the deleted line

                bool keep_reading = true;           //keep_reading variable is used for the loop statements of reading the file which has the line we want to delete
                int current_line = 1;           //current_line variable is used to count the current line that the program is reading

                do {
                    fgets (buffer_db, MAX_LINE, filedb);            //reading the strings "databuku.txt" and storing them in the buffer variable

                    if (feof (filedb)) keep_reading = false;            //if the program reach the end of file, stop reading
                    
                    else if (current_line != delete_line){          //if the current line is not the line we want to delete, store the strings into the temporary file 
                        fputs (buffer_db, tempdb);
                    }
                    current_line++;         //increament current_line for counting the line the program currently reading

                } while (keep_reading);             //keep reading the file while keep_reading is true

                fclose (filedb);            //close the file "databuku.txt"
                fclose (tempdb);            //close the file "temp____databuku.txt"

                remove ("databuku.txt");            //remove the old "databuku.txt" file  
                rename ("temp____databuku.txt", "databuku.txt");            //rename the "temp____databuku.txt" with "databuku.txt"

                printf ("\nData Successfully Deleted.");            //noticing the user that the line is deleted

                do {
                    printf ("\n\nHapus data lagi? (Y/N)  : ");           //asking if the user wants to repeat the program                 
                    scanf (" %c", &repeat);
                            
                    if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                        printf ("\nInput salah.");
                    }
                    else{
                    }

                    getchar ();         //getchar is used to take the whitespace

                } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');         //while the input is incorrect, repeat the statements

            } while (repeat == 'Y' || repeat == 'y');
        }
        else if (menu == 7){
            printf ("\n\nTerima kasih.");

            break;          //if the user chose the menu 7, break from the do while loop
        }

    } while (back == 'M' || back == 'm' || repeat == 'N' || repeat == 'n');

    return 0;
}