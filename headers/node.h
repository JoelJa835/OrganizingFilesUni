#include <fos.h>
#include <stdlib.h>
#include <string.h>

#ifndef NODE_H
#define NODE_H

#define DATASIZE 28
#define RECSIZE 32

namespace FOS
{
    class Node
        {
            int key;
            char* data;
        
        public:
            Node()
                {
                    this->data=(char*)malloc((DATASIZE+1)*sizeof(char));
                }
            ~Node()
                {
                    free(this->data);
                }    

        void setKey(int key)
            {
                this->key=key;
            }

        void setData(char* data)
            {
                strcpy(this->data,data);   
            }

        int getKey(void)
            {
                return this->key;
            }

        char* getData(void)
            {
                return this->data;
            }

        char* toByteArray(void);    
        void fromByteArray(char* array);    
        
        };   
}

#endif