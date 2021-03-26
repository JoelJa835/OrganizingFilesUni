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
        spage-td::cout<<page->getNodes()[3].getKey()<<"\n";
        std::cout<<page->getNodes()[3].getData()<<"\n";

        FOS::FileManager fs;
        FILE* file;

        fs.CreateFile("./testfile","./index");
        //std::cout<<"Open file returned "<<fs.OpenFile(file,"./testfile")<<"\n";
        fs.WriteBlock(1,page,file);

        FOS::DataPage* page1=new FOS::DataPage();
        fs.ReadBlock(1,page1,file);

        
        std::cout<<page1->getNodes()[0].getKey()<<"\n";
        std::cout<<page1->getNodes()[0].getData()<<"\n";
        std::cout<<page1->getNodes()[1].getKey()<<"\n";
        std::cout<<page1->getNodes()[1].getData()<<"\n";
        std::cout<<page1->getNodes()[2].getKey()<<"\n";
        std::cout<<page1->getNodes()[2].getData()<<"\n";
        std::cout<<page1->getNodes()[3].getKey()<<"\n";
        std::cout<<page1->getNodes()[3].getData()<<"\n";

        fs.CloseFile(file);

        FOS::IndexDataPage* test=new FOS::IndexDataPage;
        test->index.push_back({1,2});
        test->index.push_back({1,2});
        test->index.push_back({3,2});
        test->index.push_back({5,1});
        test->index.push_back({6,7});
        test->index.push_back({90,1});
        test->index.push_back({123,0});
        test->index.push_back({90,1});
        test->index.push_back({123,0});
        test->index.push_back({3,2});
        test->index.push_back({5,1});
        test->index.push_back({6,7});
        test->index.push_back({90,1});
        test->index.push_back({123,0});
        test->index.push_back({90,1});
        test->index.push_back({123,0});
        fs.WriteIndex(0,test,file);
    return 0;
    }
