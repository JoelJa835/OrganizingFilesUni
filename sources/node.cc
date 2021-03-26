#include <node.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <bitset>

char* FOS::Node::toByteArray(void)
    {
        char* buffer=(char*) malloc((RECSIZE+1)*sizeof(char));
        for(int j=0;j<RECSIZE;buffer[j++]='0');
        //fwrite(buffer,sizeof(char),RECSIZE,stdout);
        //printf("\n");
        

        int tmp1=this->getKey();
        char* tmp=(char*)&tmp1;
        sprintf(buffer,"%c%c%c%c%s",(tmp)[0],(tmp)[1],(tmp)[2],(tmp)[3],this->data);
        //fwrite(buffer,sizeof(char),RECSIZE,stdout);
        //printf("\n");
        //int len=strlen(buffer);
        char* buffer1=(char*) malloc((RECSIZE)*sizeof(char));
        for(int j=0;j<RECSIZE;j++)
            {
                buffer1[j]=buffer[j];
            }
        free(buffer);
        //fwrite(buffer1,sizeof(char),RECSIZE,stdout);
        //printf("\n");
    return buffer1;
    }

void FOS::Node::fromByteArray(char* array)
    {
        
        int tmp1;
        char* tmp=(char*)&tmp1;
        sscanf(array,"%c%c%c%c%s",(&tmp)[0],(&tmp)[1],(&tmp)[2],(&tmp)[3],this->data);
        this->setKey(tmp1);
        printf("%i\n",tmp1);
    }
