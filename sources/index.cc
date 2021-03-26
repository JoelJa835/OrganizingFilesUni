#include <index.h>
#include <string.h>
#include <stdio.h>
#include <string>

void FOS::IndexDataPage::fromIndexArray(char* array)
    {
        for(int j=0;j<INDEX_PAGE_SIZE/PAIR_SIZE;j++)
            {
                std::array<int,2> tmp;
                sscanf(array,"%i%i",&tmp[0],&tmp[1]);
                this->index.push_back(tmp);
            }
    }

char* FOS::IndexDataPage::toIndexArray(void)
    {
        //char* buffer=(char*) malloc(INDEX_PAGE_SIZE+1);
        char* buffer=(char*) malloc(INDEX_PAGE_SIZE+sizeof(char));;
        for(int j=0;j<this->index.size();j++)
            {
                char* buffer1=(char*) malloc(PAIR_SIZE+sizeof(char));;
                int* temp=this->index[j].data();
                //hardcoded to be faster since block size is fixed
                sprintf(buffer1,"%c%c%c%c%c%c%c%c",(char)(temp[0]),(char)(temp[1]),(char)(temp[2]),(char)(temp[3]),(char)(temp[4]),(char)(temp[5]),(char)(temp[6]),(char)(temp[7]));
                strncat(buffer,buffer1,PAIR_SIZE);
                free(buffer1);
            }
        char* buffer2=(char*) malloc(index.size()*PAIR_SIZE);
        for(int j=0;j<INDEX_PAGE_SIZE;j++)
            buffer2[j]=buffer[j];
        free(buffer);
    return buffer2;
    }
