//Muhammad Hamza Siddiqui
//25K-0653 BCS-1G
#include <stdio.h>
#include <string.h>

#define maxLength 100
void stringrev(char str[]){
    
    int length = strlen(str);
    int middle = length / 2;
    char temp;

    for( int i=0; i<middle; i++)
 {
    temp = str[i];
    str[i]= str[length - i - 1];
    str[length - i - 1] = temp;
 }

}
void toggle(char str[]){
    int length = strlen(str);

    for(int i=0; i<length; i++)
 {
    str[i] = str[i]^(1<<2);
    str[i] = str[i]^(1<<5);
 }
}
void unreverse(char str[])
{
    stringrev(str);
}
void untoggle(char str[]){
    int length = strlen(str);

    for(int i=0; i<length; i++)
 {
    str[i] = str[i]^(1<<2);
    str[i] = str[i]^(1<<5);
 }

}
int main(){

 int choice;
 char message[maxLength];

 do{

    printf("=======TCS Security System (Message Encryption)======= \n");
    printf("PRESS: 1 To Encrypt a text \n");
    printf("PRESS: 2 To Decrypt a text \n");
    printf("PRESS: 3 To Exit The Program \n");
    scanf("%d",&choice);

    switch(choice){

    case 1:
    printf("\nEnter the Text that You want to Encrypt: \n");
    scanf(" %[^\n]", message);
    getchar();
    
    stringrev(message);
    toggle(message);
    printf("\nEncrypted Text: %s\n", message);

    break;

    case 2:
    printf("\nEnter the Text that You want to Decrypt: \n");
    scanf(" %[^\n]", message);
    getchar();

    toggle(message);
    stringrev(message);
    printf("\nDecrypted Text: %s \n", message);
    break;

    case 3:
    printf("\nExiting the Program....\n");
    break;

    default:
    printf("Invalid Input Provided! \n");
    }
 }while(choice!=3);

 return 0;
}
