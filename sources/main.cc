#include <file_manager.h>
#include <page.h>
#include <node.h>
#include <iostream>
#include <string>

int main(int argc,char** argv)
    {
        FOS::DataPage* page=new FOS::DataPage();

        page->getNodes()[0].setKey(123);
        page->getNodes()[1].setKey(456);
        page->getNodes()[2].setKey(789);
        page->getNodes()[3].setKey(101112);


        page->getNodes()[0].setData("Manolis");
        page->getNodes()[1].setData("Giannis");
        page->getNodes()[2].setData("Kostas");
        page->getNodes()[3].setData("Spyros");

        std::cout<<page->getNodes()[0].getKey()<<"\n";
        std::cout<<page->getNodes()[0].getData()<<"\n";
        std::cout<<page->getNodes()[1].getKey()<<"\n";
        std::cout<<page->getNodes()[1].getData()<<"\n";
        std::cout<<page->getNodes()[2].getKey()<<"\n";
        std::cout<<page->getNodes()[2].getData()<<"\n";
        std::cout<<page->getNodes()[3].getKey()<<"\n";
        std::cout<<page->getNodes()[3].getData()<<"\n";

        FOS::FileManager fs;
        FILE* file;

        fs.CreateFile("./testfile");
        fs.OpenFile(file,"./testfile");
        fs.WriteBlock(123,page,file);
    }