#include <page.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* FOS::DataPage::toByteArray(void)
    {
        char* buffer=(char*) malloc((SIZEARRAY*RECSIZE+1)*sizeof(char));
        for(int j=0;j<SIZEARRAY;j++)
            sprintf(buffer,"%s",Nodes[j].toByteArray());
        buffer[SIZEARRAY*RECSIZE+1]='\0';
    return buffer;
    }

void FOS::DataPage::fromByteArray(char* array)
    {
        for(int j=0;j<SIZEARRAY;j++)
            {
                char* buffer=(char*) malloc((SIZEARRAY*RECSIZE+1)*sizeof(char));
                memcpy(buffer,array+j*RECSIZE,RECSIZE);
                buffer[SIZEARRAY*RECSIZE+1]='\0';
                Nodes[j].fromByteArray(buffer);
                free(buffer);
            }
    }