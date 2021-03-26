#include <page.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* FOS::DataPage::toByteArray(void)
    //{
        //char* buffer=(char*) malloc((SIZEARRAY*RECSIZE+1)*sizeof(char));
        //*buffer='\0';
        //for(int j=0;j<SIZEARRAY;j++)
            //{
                //char* buffer_string=this->Nodes[j].toByteArray();
                //int string_size=strlen(buffer_string);
                //strncat(buffer,buffer_string,RECSIZE);
                //if(string_size==RECSIZE-sizeof(int))
                    //continue;
                //else
                    //buffer
            //}
        //buffer[SIZEARRAY*RECSIZE+1]='\0';
        //printf("%s\n",buffer);
    //return buffer;
    //}

//void FOS::DataPage::fromByteArray(char* array)
    //{
        //for(int j=0;j<SIZEARRAY;j++)
            //{
                //char* buffer=(char*) malloc((SIZEARRAY*RECSIZE+1)*sizeof(char));
                //memcpy(buffer,array+j*RECSIZE,RECSIZE);
                //buffer[SIZEARRAY*RECSIZE+1]='\0';
                //this->Nodes[j].fromByteArray(buffer);
                //free(buffer);
            //}
    //}
