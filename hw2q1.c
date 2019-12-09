
#include <stdio.h>

int main()
{
    if(fileExists("PE-1.txt")){
        return readFile();
    }
    else {
        return createFile();
    }

    return 0;
}

int fileExists(const char *fname){
    FILE *file;
    if((file = fopen(fname, "r"))){
        fclose(file);
        return 1;
    }
    else return 0;
}

int createFile(){
    char msg[] = "I want to learn PE file format!";
    FILE *fp = fopen("PE-1.txt","a");
    fprintf(fp,msg);
    return 1;
}

int readFile(){
    FILE *file;
    char msg[] = "I want to learn PE file format!";
    char buffer[5000];
    file = fopen("PE-1.txt","a+");
    if(!file){
        return 0;
    }
    char* match;
    while(fgets(buffer,5000,file)!=NULL){

        match = strstr(buffer, msg);
        if(match != NULL){
            printf("%s",buffer);
        } else{
            fprintf(file,msg);
        }
        
    }
    fclose(file);
    return 1;
    
}