/*
This program allows users to encrypt and decrypt plain and cipher text through the means of both a rotational
and substitution cipher. Using the Input.txt file provided in the project folder, users can input plain or
cipher text on the lines provided alongside a key for substitution ciphers or any other items required.
When the program is run, the user will be met with a task selection screen from which they can select a task given
the information input into the Input.txt file. This is simply done by entering a number between 1 and 6 which
relates to the desired task. After the task is selected, the program may ask for a rotation value if tasks 1 or 2
were selected. After this, the program will run, ocassionally showing information in stdout until the program
is complete. The user may now look at the Output.txt file in order to see the completed decrypted or encrypted text,
which will refresh each time the program is run.
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *Input;                        //Initialises a file which will be accessed in order to acquire plain and cipher text as well as substitution keys
    FILE *Output;                       //Initialises a file which will have the resulted encrypted or decrypted message sent to
    FILE *Dictionary;                   //Initialises a file which contains a list of many English words to aid with decryption in task 5
    
    
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
                     
                Input = fopen("Input.txt", "r");                            //Opens the Input.txt file for reading
                
                while(fgets(message1, 1024, Input)) {                               //Reads an input of a message to be encoded from Input.txt file on line 15 by ignoring each line until line 15
                
                    i++;
                    if(i == 15) {
                        break;
                    }
                }      
                
                fclose(Input);                                                  //Closes the Input.txt file as it is no longer needed
                
                printf("Enter a value for which to rotate the text by (Between 0 and 25):\n");     //Takes a rotation value from the user which the message will be shifted and encrypted by
                scanf("%d", &shift);   
            
                for(c=0; message1[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message1[c] >= 'a') {                    
                        message1[c] = message1[c] - 32;
                    }
                }        
                
                for(c=0; message1[c] != '\0'; c++) {                //Takes every value and adds the shift value in order to reach new value
                    
                    if(message1[c] >= 'A') {                          //If the current element is not a letter, moves to next element
                        c++;
                    }

                    message1[c] = message1[c] + shift;
                    
                    if(message1[c] > 'Z' || message1[c] > 'z') {                         //Values that exceed Z loop back to A and continue
                        message1[c] = message1[c] - 26;
                    }
                }
            
                Output = fopen("Output.txt", "w");                                                          //Opens the Output.txt file for writing results into
                    
                fprintf(Output, "Encrypted Message after shifting by %d is: %s\n", shift, message1);        //Prints final encrypted message to Output.txt file
                
                fclose(Output);                                                                             //Closes the Output.txt file as it is no longer needed
                
                break;
            
            case 2: ;       //This is an empty statement to allow initialisation on next line
            
                char message2[1024];        //Initialises a string to be decoded
                i = 0;
                
                Input = fopen("Input.txt", "r");                                    //Opens the Input.txt file for reading
                
                while(fgets(message2, 1024, Input)) {                               //Reads an input of a message to be decrypted from Input.txt file on line 4 by ignoring each line until line 4
                
                    i++;
                    if(i == 4) {
                        break;
                    }
                }      
                
                fclose(Input);                                                      //Closes the Input.txt file as it is no longer needed
                
                printf("Enter the known Rotation Value\n");
                scanf("%d", &shift);                            //Reads a value for the rotation already known by the user in order to decrypt the cipher text
                
                for(c=0; message2[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message2[c] >= 'a') {                    
                        message2[c] = message2[c] - 32;
                    }
                }
                
                for(c=0; message2[c] != '\0'; c++) {                //Takes every value and adds the shift value in order to reach new value
                    
                    if(message2[c] < 'A') {                             //If the current element is not a letter, moves to next element
                        c++;
                    }

                    message2[c] = message2[c] - shift;    
                    
                    if(message2[c] < 'A') {                         //Values that are lower than A loop back to Z and continue
                        message2[c] = message2[c] + 26;
                    }
                    
                    if(message2[c] == 32 + 26 - shift) {     //For whitespaces which occur after periods, this if statement returns them to being whitespaces
                        message2[c] = 32;
                    }
                }
        
                Output = fopen("Output.txt", "w");                                                          //Opens the Output.txt file for writing results into
                
                fprintf(Output, "Decrypted Message after shifting by %d is: %s\n", shift, message2);        //Prints final decrypted message to Output.txt file
                
                fclose(Output);                                                                             //Closes the Output.txt file as it is no longer needed
            
                break;
        
            case 3: ;       //This is an empty statement to allow initialisation on next line
            
                char message3[1024];                 //Initialises a string to be encoded
                char key1[26];                      //Initialises a key which will resemble the alphabet's subsitution
                char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};     //Initialises the alphabet
                i = 0;                      //Resets the value of the i integer used throughout the program
                
                Input = fopen("Input.txt", "r");                                    //Opens the Input.txt file for reading
                
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
                
                fclose(Input);                                                      //Closes the Input.txt file as it is no longer needed
                i = 0;
                
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
                
                Output = fopen("Output.txt", "w");                                  //Opens the Output.txt file for writing results into
                
                fprintf(Output, "The Encrypted Message is: %s\n", message3);        //Prints the encrypted message to Output.txt
                
                fclose(Output);                                                     //Closes the Output.txt file as it is no longer needed
                
                break;
        
            case 4: ;       //This is an empty statement to allow initialisation on next line
            
                char message4[1024];                     //Initialises a string to be decrypted
                char key2[26];                          //Initialises a key which will resemble the alphabet's substitution
                char alphabet2[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};    //Initialises the alphabet
                i = 0;
                
                Input = fopen("Input.txt", "r");                                    //Opens the Input.txt file for reading
                
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
                
                fclose(Input);                                                  //Closes the Input.txt file as it is no longer needed
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
                
                Output = fopen("Output.txt", "w");                                  //Opens the Output.txt file for writing results into
                
                fprintf(Output, "The Decrypted Message is: %s\n", message4);        //Prints the decrypted message to Output.txt

                fclose(Output);                                                     //Closes the Output.txt file as it is no longer needed 

                break;
                
            case 5: ;       //This is an empty statement to allow initialisation on next line
                
                char message5[1024];                                //Initialises a string which will be input by the user and decrypted
                char message5firstword[100];                        //Initialises a string which contains only the first word of the cipher text input by the user
                char message5option[1024];                          //Initialises a string which will hold each potential word the text could be after each rotation
                char DictionaryLine[1024];                          //Initialises a string which will hold each consecutive word from the dictionary
                int length;                                         //Initialises an integer value which represents the length of first word in order to compare strings later on
                shift = 0;                                          //Resets the value of shift from previous tasks
                int determinedshift;                                //Initialises an integer which represents the shift value of the entire message after decypting the first word
                i = 0;                                              //Resets the value of i
                
                Input = fopen("Input.txt", "r");                                       //Opens the Input.txt file for reading
                
                while(fgets(message5firstword, 1024, Input)) {                          //Reads an input of a message to be decrypted from Input.txt file on line 7 by ignoring each line until line 7
                
                    i++;
                    if(i == 7) {
                        break;
                    }
                }

                i = 0;                                                                  //Resets the value of i back to 0 to be used again
                fclose(Input);                                                          //Closes the Input.txt file as it is no longer needed
                
                for(c=0; c <= 100; c++) {                                               //Removes all trailing newlinecharacters first word string and replaces them with null characters
                    
                    if(message5firstword[c] == '\n') {
                        message5firstword[c] = '\0';
                        break;
                    }
                }
                
                length = strlen(message5firstword);                                     //Finds the length of the first word and stores it in length
                length = length - 1;
                
                for(c=0; message5firstword[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message5firstword[c] >= 'a') {                    
                        message5firstword[c] = message5firstword[c] - 32;
                    }
         
                }
                
                while(shift < 26) {
                    
                    for(c=0; message5firstword[c] != '\0'; c++) {                   
                    
                        message5option[c] = message5firstword[c] - shift;           //Shifts the value of the first word by the current shift value which starts at 0

                        if(message5option[c] < 'A') {                               //Values that are lower than A loop back to Z and continue
                            message5option[c] = message5option[c] + 26;
                        }   
                    }
                    
                    printf("An option for the first word after rotation by %d is %s\n", shift, message5option);         //Prints each consecutive option for the first word as the loop loops

                    Dictionary = fopen("less_words.txt", "r");                         //Opens the less_words.txt file for reading
                    
                    while(fgets(DictionaryLine, sizeof DictionaryLine, Dictionary) != NULL) {    //Reads a line from less_words.txt and brings it into the next section
                        
                        for(c=0; DictionaryLine[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                            if(DictionaryLine[c] >= 'a') {                    
                            DictionaryLine[c] = DictionaryLine[c] - 32;
                            }
                        }
                        
                        if(strncmp(DictionaryLine, message5option, length) == 0) {              //Compares if the current option and current line of the dictionary are the same and if they are, returns a value of 0
                           
                            printf("\nThe decrypted first word of the message is potentially %s\n\n", message5option);      //If messages are the same, prints a potential option for what the first word is
                            
                            determinedshift = shift;                            //Sets the determined shift value to the shift value used to obtain this word
                            break;
                        }
                    } 
                    
                    fclose(Dictionary);                             //Closes the less_words.txt file as it is no longer needed
                        
                    shift++;                //Increases shift value by 1 and restarts the loop to test next option
                } 

                Input = fopen("Input.txt", "r");                                       //Opens the Input.txt file for reading
                
                while(fgets(message5, 1024, Input)) {                           //Reads an input of a message to be decrypted from Input.txt file on line 4 by ignoring each line until line 4
                
                    i++;
                    if(i == 4) {
                        break;
                    }
                }
                
                fclose(Input);                                      //Closes the Input.txt file as it is no longer needed
                
                for(c=0; message5[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message5[c] >= 'a') {                    
                        message5[c] = message5[c] - 32;
                    }
         
                }
                
                for(c=0; message5[c] != '\0'; c++) {            //Progresses through each element of the string
                    
                    if(message5[c] < 'A') {                     //If the current element is not a letter, moves to next element 
                        c++;
                    }

                    message5[c] = message5[c] - determinedshift;   //Given the current element is now guranteed to be a letter, shifts the current element by the determined shift value
                    
                    if(message5[c] < 'A') {                         //Values that are lower than A loop back to Z and continue
                        message5[c] = message5[c] + 26;
                    }
                    
                    if(message5[c] == 32 + 26 - determinedshift) {     //For whitespaces which occur after periods, this if statement returns them to being whitespaces
                        message5[c] = 32;
                    }
                }
                
                Output = fopen("Output.txt", "w");                                      //Opens the Output.txt file for writing results into
                
                fprintf(Output, "The decrypted message is: %s", message5);              //Prints final decrypted message to Output.txt file
                
                fclose(Output);                                                         //Closes the Output.txt file as it is no longer needed
                
                break;
        
            case 6: ;       //This is an empty statement to allow initialisation on next line
                
                char message6[1024];                    //initialises a string which will be decrypted
                char message6firstword[1024];           // initialises a second string which will only contain the first word of the cipher text 
                char key3[26] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};       //Initialises a blank key that will get added to as more letters are known, leaving each element as 0 will result in no interference from unknown values
                char alphabet3[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};  //Initialises an alphabet used for cross refrencing and converting letters in cipher text
                i = 0;
                
                Input = fopen("Input.txt", "r");                   //Opens the Input.txt file for reading     
                
                while(fgets(message6firstword, 1024, Input)) {                      //Reads an input of a message to be decrypted from Input.txt file on line 7 by ignoring each line until line 7
                
                    i++;
                    if(i == 7) {
                        break;
                    }
                }

                i = 0;
                fclose(Input);                                      //Closes the Input.txt file as it is no longer needed
                
                for(c=0; message6firstword[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message6firstword[c] >= 'a') {                    
                        message6firstword[c] = message6firstword[c] - 32;
                    }
                }
                
                key3[3] = message6firstword[0];                           //Considering it's a question, the first word is most likely DID, meaning R = D and C = I
                key3[8] = message6firstword[1];
                key3[19] = 'V';                                           //Given the second word following DID is most likely THE, V = T, Y = H and B = E
                key3[7] = 'Y';
                key3[4] = 'B';
                
                
                Input = fopen("Input.txt", "r");                           //Opens the Input.txt file for reading
                
                while(fgets(message6, 1024, Input)) {                       //Reads an input of a message to be decrypted from Input.txt file on line 4 by ignoring each line until line 4
                
                    i++;
                    if(i == 4) {
                        break;
                    }
                }

                i = 0;
                fclose(Input);                                          //Closes the Input.txt file as it is no longer needed
                
                for(c=0; message6[c] != '\0'; c++) {              //Converts lower case letters in input into upper case letters before continuing
                    
                    if(message6[c] >= 'a') {                    
                        message6[c] = message6[c] - 32;
                    }
                }

                for(c=0; message6[c] != '\0'; c++) {
                    
                    while(c >= 0 && i < 26) {
                                            
                        if(message6[c] == key3[i]) {                        //Checks to see if the cth letter of the message is the same as the ith letter in the key
                        
                        message6[c] = alphabet3[i];                         //If the cth letter is the same, it gets changed to the ith letter of the alphabet
                        
                        break;
                        }
                        
                        else {
                            i++;                                            //Increments i to make sure all letters in key are tested
                        }
                    }
                    
                    i = 0;                                                  //Resets value of i before loop repeats
                }
               
                Output = fopen("Output.txt", "w");                          //Opens the Output.txt file for writing results into
               
                fprintf(Output, "The current progress of decryption is: %s\n\n", message6);                 //Prints final decrypted message to Output.txt file
                
                fclose(Output);                                             //Closes the Output.txt file as it is no longer needed
                
                break;
            
            default: 
            
                printf("Your failure to enter a number between 1 and 6 is astonoshing. Program will now  proceed to internally combust");       //Just a message to remind the user they are incompotent and should try again
            
                return 0;
         }

    return 0;   //Ends the program
}