/*
 * An example of how to read, write, and append to a file.
 * We will also compare a string from STDIN and one from FILE

*/



#include <stdio.h>
#include <stdlib.h>
#include <strings.h> //bezero(buffer, sizeof(buffer));


int main(int argc, char *argv[]){



  //Append to the file using system calls...
  system("echo \"Line 2\" >> hi.txt");
  system("echo \"Line 3\" >> hi.txt");
  system("echo \"Line 4\" >> hi.txt");

  

  /******** WRITTING TO A FILE *********/
  
  FILE *myFile = fopen("hi.txt", "w");
  
  if(myFile){
    
    char *temp = "Now I am on File";
    fprintf(myFile, "From Variable: %s\n",temp);
    
    int a = 1;
    float b = 3.142323;
    fprintf(myFile, "I can write ints: %d, And floats: %f\n", a, b);
    
    char c = 'A';
    fprintf(myFile, "Or just a Char: %c\n", c);
    
    fclose(myFile);
  }
  
  
  
  /******** APPENDING TO A FILE. aka add a new line *********/
  
  char toFile[] = "Im will be on a file";
  
  // Open file in apend mode..
  FILE *myFile2 = fopen("hi.txt", "a");
  
  // Checks if the file exists/
  if( myFile2 ){
    puts("File exitst\n");
    
    //fprintf(FILE *, data_type, var);
    fprintf(myFile2, "%s\n", toFile);
    fclose(myFile2);
  }
  else
    puts("No file\n");

  fclose(myFile2);



  
  /******** READING LINE BY LINE UNTIL EOF *********/
  /*** AND COMPARING STRING FROM FILE WITH STDIN ***/
  FILE *myFile3 = fopen("hi.txt", "r");
  if( myFile2 ){
    char buffer[1024];
    char temp2[1024];
    char tempBuff[1024];
    
    while( 1 ){
      fgets(buffer, sizeof(buffer), myFile3);

      if( feof(myFile3) ){
	break;
      }

      //NOTE:
      //scanf stops reading after an space and does not add '\n'
      //scanf("%s", temp2);


      //NOTE:
      //fgets stops reading at EOF which means it add '\n'
      fgets( temp2, sizeof(temp2), stdin);


      //NOTE:
      // Regarless of the size of the string, remove '\n'
      temp2[strlen(temp2) - 1] = 0;
      
      //Copy the string from file without: '\n'
      strncpy(tempBuff, buffer, ( strlen(buffer)-1) );
      printf("Your entered: '%s' Current Line is: '%s'\n", temp2, tempBuff);
      
      if(strcmp(tempBuff, temp2) == 0){
	puts("\n\nMatched\n\n");
	break;
      }

      bzero(temp2, sizeof(temp2));
      bzero(buffer, sizeof(buffer));
      bzero(tempBuff, sizeof(tempBuff));
    } 

    fclose(myFile3);
  }


  /************** Reading: while 'true' **************/
  puts("Last Iteration on the file\n");
   
  FILE *myFile4 = fopen("hi.txt", "r");
  char last[1024] = {0};

  while( fgets(last, sizeof(last), myFile4) ){
    printf("%s", last);
    
    //Note:
    //The buffer reads including '\n'
  }

  fclose(myFile4);
  
  puts("The End...\n");

  return 0;
}

