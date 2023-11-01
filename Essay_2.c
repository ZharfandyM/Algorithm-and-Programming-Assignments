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

int main (){
    int jb;         //jb = jumlah baris
    char repeat;    //variable reepat is used for the repetition of the program
    bool parsed_correct = true;     //variable for the return value from the error check function

    system ("cls");

    printf ("Selamat datang di program segitiga angka.");

    do {
        do {
            printf ("\n\nMasukkan Jumlah Baris (1-25)  : ");  

            char buffer[BUFFER_SIZE];       //variable for the buffer of the input

            fgets (buffer, BUFFER_SIZE, stdin);         //taking input and storing it in the buffer variable

            parsed_correct = parse_int (buffer, &jb);      //calling the error check funtion

            if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."

        } while (!parsed_correct); 

        if (jb == 1){               //printing the number triangle based on the user input for the amount of lines
            printf ("2");
        }
        else if (jb == 2){          
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 3){
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 4){
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 5){          
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 6){                      //printing the number triangle based on the user input for the amount of lines
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 7){
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 8){
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 9){
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 10){
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 11){                                 //printing the number triangle based on the user input for the amount of lines
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 12){
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 13){
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 14){
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 14){
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 15){
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 16){                                                 //printing the number triangle based on the user input for the amount of lines
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 17){
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 18){
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 19){
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 20){
            printf ("40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40\n");
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }   
        else if (jb == 21){                     //printing the number triangle based on the user input for the amount of lines                                                        
            printf ("42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42\n");
            printf ("40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40\n");
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 22){
            printf ("44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44\n");
            printf ("42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42\n");
            printf ("40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40\n");
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 23){
            printf ("46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46\n");
            printf ("44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44\n");
            printf ("42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42\n");
            printf ("40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40\n");
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 24){
            printf ("48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48\n");
            printf ("46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46\n");
            printf ("44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44\n");
            printf ("42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42\n");
            printf ("40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40\n");
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else if (jb == 25){                     //printing the number triangle based on the user input for the amount of lines
            printf ("50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50\n");
            printf ("48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48 48\n");
            printf ("46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46 46\n");
            printf ("44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44 44\n");
            printf ("42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42\n");
            printf ("40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40\n");
            printf ("38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38 38\n");
            printf ("36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36 36\n");
            printf ("34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34\n");
            printf ("32 32 32 32 32 32 32 32 32 32 32 32 32 32 32 32\n");
            printf ("30 30 30 30 30 30 30 30 30 30 30 30 30 30 30\n");
            printf ("28 28 28 28 28 28 28 28 28 28 28 28 28 28\n");
            printf ("26 26 26 26 26 26 26 26 26 26 26 26 26\n");
            printf ("24 24 24 24 24 24 24 24 24 24 24 24\n");
            printf ("22 22 22 22 22 22 22 22 22 22 22\n");
            printf ("20 20 20 20 20 20 20 20 20 20\n");
            printf ("18 18 18 18 18 18 18 18 18\n");
            printf ("16 16 16 16 16 16 16 16\n");
            printf ("14 14 14 14 14 14 14\n");
            printf ("12 12 12 12 12 12\n");
            printf ("10 10 10 10 10\n");
            printf ("8 8 8 8\n");
            printf ("6 6 6\n");
            printf ("4 4\n");
            printf ("2");
        }
        else {
            printf ("\nInput salah, Jumlah Baris hanya boleh 1 - 25.");     //if the input is not in between 1-20, the input is incorrect
        }

        do {
            printf ("\n\nApakah anda ingin menghitung lagi? (Y/N)  : ");           //asking if the user wants to repeat the program                 
            scanf (" %c", &repeat);
                
            if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the input is neither of (Y,y,N,n) the input is incorrect
                printf ("\nInput salah.");  
            }
            else{
            }

            getchar ();

        } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');     //if the input is neither of (Y,y,N,n) repeat the asking statement
    
    } while (repeat == 'Y' || repeat == 'y');          //if the user input either one of (Y,y) repeat the program    

    printf ("\n\nTerima kasih.");      

    return 0;
}