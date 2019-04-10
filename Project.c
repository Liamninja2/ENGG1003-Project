#include <stdio.h>

int main() {
    printf("Select a Task:\n");                                                                                     //Creates a "Menu"
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
            
            case 2: ;
            
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
        
            case 3: ;
            
                char message3[256];
                char key[256];
                char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                int i = 0;
                
                printf("Enter a Message to Decrypt\n");        
                scanf("%s", message3);
                
                printf("Enter Key (in the form abcdef... where a = the a equivalent within key)\n");
                scanf("%s", key);
                
                for(c=0; message3[c] != '\0'; c++) {
                    
                    while(c >= 0 && i < 26) {
                                            
                        if(message3[c] == alphabet[i]) {
                        
                        message3[c] = key[i];
                        
                        break;
                        }
                        
                        else {
                            i++;
                        }
                    }
                    
                    i = 0;
                }
                
                printf("The Encrypted Message is: %s\n", message3);
            
                break;
        
            case 4: ;
            
                
                
        
                break;
                
            case 5: ;
            
                break;
        
            case 6: ;
            
                break;
            
            default:
            
                return 0;
         }

    return 0;
}