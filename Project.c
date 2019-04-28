#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *Input;
    FILE *Output;
    FILE *Dictionary;
    
    
    printf("Select a Task (Input a number between 1 and 6):\n");                                                                                     //Creates a "Menu" which allows user to select the task they which to utilise
    printf("1. Encryption of a message with a rotation cipher given the message text and rotation amount\n");           //Task 1 
    printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");      //Task 2
    printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution\n");     //Task 3
    printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");    //Task 4
    printf("5. Decryption of a message encrypted with a rotation cipher given cipher text only\n");                     //Task 5
    printf("6. Decryption of a message encrypted with a substitution cipher given cipher text only\n");                 //Task 6
    
    int Task;       //Creates a Variable which just holds the choice the user makes for what task they wish to use
    
    scanf("%d", &Task);         //Reads a task value from user
    
        switch(Task) {             //Switch system that allows for each case to be executed independently from the others

            case 1: ;       //This is an empty statement to allow initialisation on next line
            
                char message1[1024];        //Initialises a string to be encoded
                int c;                      //Initialises a value which represents each letter in the string
                int shift;                  //Initialises a value which represents the rotation of the message
                int i = 0;
                     
                Input = fopen("Input.txt", "r");
                
                while(fgets(message1, 1024, Input)) {                               //Reads an input of a message to be encoded from Input.txt file on line 15 by ignoring each line until line 15
                
                    i++;
                    if(i == 15) {
                        break;
                    }
                }      
                
                fclose(Input);
                
                printf("Enter a value for which to rotate the text by:\n");
                scanf("%d", &shift);   
            
                for(c=0; message1[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message1[c] >= 'a') {                    
                        message1[c] = message1[c] - 32;
                    }
                }        
                
                for(c=0; message1[c] != '\0'; c++) {                //Takes every value and adds the shift value in order to reach new value
                    message1[c] = message1[c] + shift;
                    
                    if(message1[c] > 'Z' || message1[c] > 'z') {                         //Values that exceed Z loop back to A and continue
                        message1[c] = message1[c] - 26;
                    }
                }
            
                Output = fopen("Output.txt", "w");
                
                fprintf(Output, "Encrypted Message after shifting by %d is: %s\n", shift, message1);        //Prints final encrypted message to Output.txt file
                
                fclose(Output);
                
                break;
            
            case 2: ;       //This is an empty statement to allow initialisation on next line
            
                char message2[1024];        //Initialises a string to be decoded
                i = 0;
                
                Input = fopen("Input.txt", "r");
                
                while(fgets(message2, 1024, Input)) {                               //Reads an input of a message to be decrypted from Input.txt file on line 4 by ignoring each line until line 4
                
                    i++;
                    if(i == 4) {
                        break;
                    }
                }      
                
                fclose(Input);
                
                printf("Enter the known Rotation Value\n");
                scanf("%d", &shift);                            //Reads a value for the rotation already known by the user
                
                for(c=0; message2[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message2[c] >= 'a') {                    
                        message2[c] = message2[c] - 32;
                    }
                }
                
                for(c=0; message2[c] != '\0'; c++) {                //Takes every value and adds the shift value in order to reach new value
                    
                    message2[c] = message2[c] - shift;
                    
                    if(message2[c] < 'A') {                         //Values that are lower than A loop back to Z and continue
                        message2[c] = message2[c] + 26;
                    }
                }
        
                Output = fopen("Output.txt", "w");
                
                fprintf(Output, "Decrypted Message after shifting by %d is: %s\n", shift, message2);        //Prints final decrypted message to Output.txt file
                
                fclose(Output);
            
                break;
        
            case 3: ;       //This is an empty statement to allow initialisation on next line
            
                char message3[1024];                 //Initialises a string to be encoded
                char key1[26];                      //Initialises a key which will resemble the alphabet's subsitution
                char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};     //Initialises the alphabet
                i = 0;                      //Initialises a value to assist with determining string values
                
                Input = fopen("Input.txt", "r");
                
                while(fgets(message3, 1024, Input)) {                               //Reads an input of a message to be encoded from Input.txt file on line 15 by ignoring each line until line 15
                
                    i++;
                    if(i == 15) {
                        break;
                    }
                }      
                
                while(fgets(key1, 1024, Input)) {                               //Reads an input key which is 26 charcters long, each letter corresponding to the same numbered letter in the alphabet from Input.txt   
                
                    i++;
                    if(i == 18) {
                        break;
                    }
                }            
                
                fclose(Input);
                
                for(c=0; message3[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message3[c] >= 'a') {                    
                        message3[c] = message3[c] - 32;
                    }
                }
                
                for(c=0; key1[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(key1[c] >= 'a') {                    
                        key1[c] = key1[c] - 32;
                    }
                }
                
                for(c=0; message3[c] != '\0'; c++) {
                    
                    while(c >= 0 && i < 26) {
                                            
                        if(message3[c] == alphabet[i]) {                    //Checks to see if the cth letter of the message is the same as the ith letter of the alphabet
                        
                        message3[c] = key1[i];                              //If the cth letter is the same, it gets changed to the ith letter if the key
                        
                        break;
                        }
                        
                        else {
                            i++;                                            //Increments i to make sure all letters in alphabet are checked for each letter of the message
                        }
                    }
                    
                    i = 0;                                                  //Resets the value of i before restarting the loop
                }
                
                Output = fopen("Output.txt", "w");
                
                fprintf(Output, "The Encrypted Message is: %s\n", message3);         //Prints the encrypted message to Output.txt
                
                fclose(Output);
                
                break;
        
            case 4: ;       //This is an empty statement to allow initialisation on next line
            
                char message4[1024];                     //Initialises a string to be decrypted
                char key2[26];                          //Initialises a key which will resemble the alphabet's substitution
                char alphabet2[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};    //Initialises the alphabet
                i = 0;
                
                Input = fopen("Input.txt", "r");
                
                while(fgets(message4, 1024, Input)) {                               //Reads an input of a message to be decrypted from Input.txt file on line 15 by ignoring each line until line 15
                
                    i++;
                    if(i == 4) {
                        break;
                    }
                }      
                
                while(fgets(key2, 1024, Input)) {                               //Reads an input key which is 26 charcters long, each letter corresponding to the same numbered letter in the alphabet from Input.txt   
                
                    i++;
                    if(i == 10) {
                        break;
                    }
                }            
                
                fclose(Input);  
                i = 0;
                
                for(c=0; message4[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message4[c] >= 'a') {                    
                        message4[c] = message4[c] - 32;
                    }
                }
                
                for(c=0; key2[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(key2[c] >= 'a') {                    
                        key2[c] = key2[c] - 32;
                    }
                }
                
                for(c=0; message4[c] != '\0'; c++) {
                    
                    while(c >= 0 && i < 26) {
                                            
                        if(message4[c] == key2[i]) {                        //Checks to see if the cth letter of the message is the same as the ith letter in the key
                        
                        message4[c] = alphabet2[i];                         //If the cth letter is the same, it gets changed to the ith letter of the alphabet
                        
                        break;
                        }
                        
                        else {
                            i++;                                            //Increments i to make sure all letters in key are tested
                        }
                    }
                    
                    i = 0;                                                  //Resets value of i before loop repeats
                }
                
                Output = fopen("Output.txt", "w");
                
                fprintf(Output, "The Decrypted Message is: %s\n", message4);         //Prints the decrypted message to Output.txt

                fclose(Output);

                break;
                
            case 5: ;       //This is an empty statement to allow initialisation on next line
                
                char message5[1024];
                char message5firstword[100];
                char message5option[1024];
                char DictionaryLine[1024];
                int length;
                shift = 0;
                int determinedshift;   
                i = 0;
                
                Input = fopen("Input.txt", "r+");
                
                while(fgets(message5firstword, 1024, Input)) {
                
                    i++;
                    if(i == 7) {
                        break;
                    }
                }

                i = 0;
                fclose(Input);
                
                for(c=0; c <= 100; c++) {
                    
                    if(message5firstword[c] == '\n') {
                        message5firstword[c] = '\0';
                        break;
                    }
                }
                
                length = strlen(message5firstword);
                length = length - 1;
                
                for(c=0; message5firstword[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message5firstword[c] >= 'a') {                    
                        message5firstword[c] = message5firstword[c] - 32;
                    }
         
                }
                
                while(shift < 26) {
                    
                    for(c=0; message5firstword[c] != '\0'; c++) {
                    
                        message5option[c] = message5firstword[c] - shift;

                        if(message5option[c] < 'A') {
                            message5option[c] = message5option[c] + 26;
                        }   
                    }
                    
                    printf("An option for the first word after rotation by %d is %s\n", shift, message5option);

                    Dictionary = fopen("less_words.txt", "r+");
                    
                    while(fgets(DictionaryLine, sizeof DictionaryLine, Dictionary) != NULL) {
                        
                        for(c=0; DictionaryLine[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                            if(DictionaryLine[c] >= 'a') {                    
                            DictionaryLine[c] = DictionaryLine[c] - 32;
                            }
                        }
                        
                        if(strncmp(DictionaryLine, message5option, length) == 0) {
                           
                            printf("\nThe decrypted first word of the message is potentially %s\n\n", message5option);
                            
                            determinedshift = shift;
                            break;
                        }
                    } 
                    
                    fclose(Dictionary); 
                        
                    shift++; 
                } 

                Input = fopen("Input.txt", "r+");
                
                while(fgets(message5, 1024, Input)) {
                
                    i++;
                    if(i == 4) {
                        break;
                    }
                }
                
                fclose(Input);
                
                for(c=0; message5[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message5[c] >= 'a') {                    
                        message5[c] = message5[c] - 32;
                    }
         
                }
                
                for(c=0; message5[c] != '\0'; c++) {
                    
                    if(message5[c] < 'A') {
                        c++;
                    }

                    message5[c] = message5[c] - determinedshift;
                    
                    if(message5[c] < 'A') {
                        message5[c] = message5[c] + 26;
                    }
                    
                    if(message5[c] == 32 + 26 - determinedshift) {
                        message5[c] = 32;
                    }
                }
                
                Output = fopen("Output.txt", "w");
                
                fprintf(Output, "The decrypted message is: %s", message5);
                
                fclose(Output);
                
                break;
        
            case 6: ;       //This is an empty statement to allow initialisation on next line
                
                //char message6[256];
                
                break;
            
            default: 
            
                printf("Your failure to enter a number between 1 and 6 is astonoshing. Program will now  proceed to internally combust");
            
                return 0;
         }

    return 0;
}