#include <node.h>
#include <stdio.h>
#include <string.h>
#include <string>

char* FOS::Node::toByteArray(void)
    {
        char* buffer=(char*) malloc(RECSIZE*sizeof(char));
        sprintf(buffer,"%i%s",this->key,this->data);
        int len=strlen(buffer);
    return buffer;
    }

void FOS::Node::fromByteArray(char* array)
    {
        sscanf(array,"%i%s",&this->key,this->data);
    }
