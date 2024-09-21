#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

//Functions
int command();
int action();
int write();
int read();
int append();
int quit();


char options[][25] = {"1. Write A File","2. Append Text To A File","3. Read A File","4. Quit File Editor "};
int size = sizeof(options)/sizeof(options[0]);
int pick;

//Descriptions
int command()
{   
    printf("Pick A Command : \n");
    printf("---------------------------------------------\n");
    for(int i = 0;i < size ; i++)
    {
        printf("%s\n",options[i]);
    }
    printf("Your Command : ");
    scanf("%d",&pick);
    
    return 0;
}

int action()
{   
    while (1)
    {
        if (pick == 1){
        write();
        break;
        }
        else if (pick == 2){
        append();
        break;
        }
        else if (pick == 3){
        read();
        break;
        }
        else if (pick == 4){
        quit();
        break;
        }
        else{
        printf("Invalid Command !!");
        break;
        }
    }
    
    

}
int write()
{   
    FILE *file;
    char buffer[BUFFER_SIZE];
    char filename[100];
    char choice;

    printf("Enter File Name : ");
    scanf("%s", filename);

    file = fopen(filename, "w");

    if (file == NULL){
        perror("Error opening the file !!");
        exit(EXIT_FAILURE);
    }

    printf("File Opened Successfully !!\n");
    printf("------------------------------------------\n");
    printf("{Use Underscore Instead of Whitespaces}");
    printf("\nEnter Your Text (Max. %d Characters) : ",BUFFER_SIZE - 1);

    scanf("%s", buffer);
    fputs(buffer, file);
    fclose(file);
    printf("Text written successfully.\n");

    return 0;

}

int read()
{  
    FILE *file;
    char buffer[BUFFER_SIZE];
    char filename[100];

    printf("Enter File Name : ");
    scanf("%99s", filename);
    
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening the file !!");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully.\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s\n", buffer);
    }

    fclose(file);
    printf("-------------------------------------------\n");

    return 0;
}

int append()
{   
    FILE *file;
    char buffer[BUFFER_SIZE];
    char filename[100];
    char choice;

    
    printf("Enter filename: ");
    scanf("%99s", filename);

    
    file = fopen(filename, "a");

    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully.\n");
    printf("-------------------------------------------\n");
    printf("{Use Underscore Instead of Whitespaces}\n");

    
    
    printf("Enter text to write (max %d characters): ", BUFFER_SIZE - 1);
    scanf("%s", buffer);
    fprintf(file, "\n%s", buffer);
    
    return 0;
}

int quit()
{   
    printf("-------------------------------------------\n");
    printf("Thank You :) ");
    return 0;
}


//Main Function
int main(){
    char repeat;
    do
    {
        command();
        action();
        printf("\nWant to Do Again ? (Y/N) : ");
        scanf("%s",&repeat);

    } while (repeat == 'Y' || repeat == 'y');
    
    return 0;
}