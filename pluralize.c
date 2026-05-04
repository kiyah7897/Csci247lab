//Rakiyah Jackson
// 04/10/2026

#include <stdio.h>
#include <string.h>


int main(){

//Part 1
  /*
  int num;
    char w [50];

    printf("Enter a number: \n");
    scanf("%d", &num);

    printf("Enter a word: %s\n" , &w);
    scanf("%s", &w);

    //debugg 
    //printf("your word is: %s\n",&w);

     if(num == 0 || num > 1){
        strcat(w , "s");
        printf("%s\n" , &w);

    }else{

         printf("%s\n", &w);
    }

  */  

//Boss Level
   char s [100];
    printf("Enter special word: \n");
    scanf("%s" , &s);

    int len = strlen(s);
   if( strcmp ("ife" , s +(len - 3)) ==0){
    //change "ife" -> ives
    s[len - 3] = '\0'; 
    strcat(s , "ives");
    printf("%s\n" ,&s);

   }else if(strcmp("sh" , s +(len - 2))==0){
    //change "sh" -> shes by adding es at the end 
    strcat(s , "es");
    printf("%s\n" ,&s);
    
   } else if(strcmp("ch" , s +(len - 2))==0){
    //change "sh" -> shes by adding es a the end 
    strcat(s , "es");
    printf("%s\n" ,&s);
    
   }else if(strcmp("us" , s +(len - 2))==0){
    //change us to i
    s[len - 2] = '\0'; 
    strcat(s , "i");
    printf("%s\n" ,&s);

   }else if(strcmp("ay" , s +(len - 2))==0){
    strcat(s , "s");
    printf("%s\n" ,&s);

   }else if(strcmp("oy" , s +(len - 2))==0){
    strcat(s , "s");
    printf("%s\n" ,&s);

   }else if(strcmp("ey" , s +(len - 2))==0){
    strcat(s , "s");
    printf("%s\n" ,&s);

   }else if(strcmp("uy" , s +(len - 2))==0){
    strcat(s , "s");
    printf("%s\n" ,&s);

   }else if(strcmp("y" , s +(len - 1))==0){
    //change y -> ies
    s[len - 1] = '\0'; 
    strcat(s , "ies");
    printf("%s\n" ,&s);

   }else{
    strcat(s , "s"); 
    printf("%s\n" ,&s);

   }

    return 0;
}