#include <node.h>
#include <stdio.h>
#include <string.h>

char* FOS::Node::toByteArray(void)
    {
        char* buffer=(char*) malloc(RECSIZE*sizeof(char));
        sprintf(buffer,"%i%s",this->key,this->data);
    return buffer;
    }

void FOS::Node::fromByteArray(char* array)
    {
        char* buffer=(char*) malloc(sizeof(int)+1);
        for(int j=0;j<sizeof(int);j++)
            buffer[j] = array[j];
        buffer[sizeof(int)+1]='\0';
        this->key = atoi(buffer);

        for(int j=0;j<RECSIZE-sizeof(int);j++)
            data[j] = array[4+j];
        data[RECSIZE-sizeof(int)+1]='\0';

        free(buffer);
    }