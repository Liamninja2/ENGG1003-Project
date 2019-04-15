#include <stdio.h>

int main() {
    printf("Select a Task (Input a number between 1 and 6):\n");                                                                                     //Creates a "Menu"
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
            
                char message1[256];        //Initialises a string to be encoded
                int c;                      //Initialises a value which represents each letter in the string
                int shift;                  //Initialises a value which represents the rotation of the message
                
                printf("Enter a Message to Encrypt\n");        
                scanf("%s", message1);                          //Reads an input of a message to be encoded
                
                printf("Enter a value for which to shift the message\n");
                scanf("%d", &shift);                                            //Reads a value for the rotation
                
                printf("Original Message: %s\n", message1);         //Both print the values just input by user
                printf("Shift Value: %d\n", shift);
                
                
                for(c=0; message1[c] != '\0'; c++) {                //Takes every value and adds the shift value in order to reach new value
                    message1[c] = message1[c] + shift;
                    
                    if(message1[c] > 'Z') {                         //Values that exceed Z loop back to A and continue
                        message1[c] = message1[c] - 26;
                    }
                }
            
                printf("Encrypted Message: %s\n", message1);        //Prints final encrypted message
                
                break;
            
            case 2: ;       //This is an empty statement to allow initialisation on next line
            
                char message2[256];        //Initialises a string to be decoded
                
                printf("Enter a Message to Decrypt\n");        
                scanf("%s", message2);                          //Reads an input of a message to be encoded
                
                printf("Enter the Rotation Value\n");
                scanf("%d", &shift);                            //Reads a value for the rotation
                
                printf("Encoded Message: %s\n", message2);         //Both print the values just input by user
                printf("Rotation Value: %d\n", shift);
                
                
                for(c=0; message2[c] != '\0'; c++) {                //Takes every value and adds the shift value in order to reach new value
                    message2[c] = message2[c] - shift;
                    
                    if(message2[c] < 'A') {                         //Values that are lower than A loop back to Z and continue
                        message2[c] = message2[c] + 26;
                    }
                }
            
                printf("Decrypted Message: %s\n", message2);        //Prints final encrypted message
            
                break;
        
            case 3: ;       //This is an empty statement to allow initialisation on next line
            
                char message3[256];                 //Initialises a string to be encoded
                char key1[26];                      //Initialises a key which will resemble the alphabet's subsitution
                char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};     //Initialises the alphabet
                int i = 0;                      //Initialises a value to assist with determining string values
                
                printf("Enter a Message to Encrypt\n");        
                scanf("%s", message3);                              //Reads an input message to be encoded
                
                printf("Enter Key (in the form abcdef... where a = the a equivalent within key)\n");
                scanf("%s", key1);                                  //Reads an input key which is 26 charcters long, each letter corresponding to the same numbered letter in the alphabet
                
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
                
                printf("The Encrypted Message is: %s\n", message3);         //Prints the encrypted message
            
                break;
        
            case 4: ;       //This is an empty statement to allow initialisation on next line
            
                char message4[256];                     //Initialises a string to be decrypted
                char key2[26];                          //Initialises a key which will resemble the alphabet's substitution
                char alphabet2[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};    //Initialises the alphabet
                i = 0;
                
                printf("Enter a Message to Decrypt\n");        
                scanf("%s", message4);                                      //Reads an input message which will be decrypted
                
                printf("Enter Key (in the form abcdef... where a = the a equivalent within key)\n");
                scanf("%s", key2);                                          //Reads an input key which is 26 charcters long, each letter corresponding to the same numbered letter in the alphabet         
                
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
                
                printf("The Decrypted Message is: %s\n", message4);         //Prints the decrypted message
        
                break;
                
            case 5: ;       //This is an empty statement to allow initialisation on next line
                
                char message5[256];
                shift = 0;
                
                printf("Enter a Message to Decrypt\n");        
                scanf("%s", message5);                          //Reads an input message which will be decrypted
                
                while //message 5 is not a word 
                
                for(c=0; message5[c] != '\0'; c++) {
                    
                    message5[c] = message5[c] + shift
                }

                //check dictionary for a word that resembles that
            
                break;
        
            case 6: ;       //This is an empty statement to allow initialisation on next line
                
                char message6[256];
                
                break;
            
            default:
            
                return 0;
         }

    return 0;
}