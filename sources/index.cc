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

std::string FOS::IndexDataPage::toIndexArray(void)
    {
        //char* buffer=(char*) malloc(INDEX_PAGE_SIZE+1);
    std::string buffer;
        for(int j=0;j<this->index.size();j++)
            {
                buffer+=std::to_string(this->index[j][0]);
                buffer+=std::to_string(this->index[j][1]);
            }
    return buffer;
    }
