#include <fos.h>
#include <node.h>
#include <vector>

#ifndef PAGE_H
#define PAGE_H

#define SIZEARRAY 4

namespace FOS{
class DataPage
    {
        FOS::Node Nodes[SIZEARRAY];
    public:
DataPage()
{}

        Node* getNodes() {
            return Nodes;
        }
        char* toByteArray(void);    
        void fromByteArray(char* array);    
    };
}

#endif