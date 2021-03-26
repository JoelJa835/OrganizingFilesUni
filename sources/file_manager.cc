#include <file_manager.h>
#include <stdio.h>

int FOS::FileManager::CreateFile(std::string filename)
    {
        printf("file name is: %s\n",filename.c_str());
        FILE* myFile=fopen(filename.c_str(),"w");
        for(int j=0;j<PAGE_SIZE;j++)
            fputc('0',myFile);
        if(myFile==NULL)
            {
                fprintf(stderr,"Error opening file!\n");
                return 0;
            }
        this->fileName=filename;
        printf("File initialized!\n");
        fclose(myFile);
    return 1;
    }

int FOS::FileManager::CreateFile(std::string filename,std::string index_name)
    {
        this->CreateFile(filename);
        FILE* myFile=fopen(index_name.c_str(),"w");
        if(myFile==NULL)
            {
                fprintf(stderr,"Error opening file!\n");
                return 0;
            }
        this->IndexFile=index_name;
        printf("IndexInitialized!\n");
        fclose(myFile);
    return 1;
    }



    //h open file tha diavazei to synolo apo thn prvth grammh toy arxeioy 
    //kai ua to apouhkeyoyme sth mnhmh opoto panta jeroyume 
    //to plhthos xoris na metrhsoyme kai apla analoga me tis allages 
    //maw tha prepei na allazoyme ak to plhthos
    //NA POY THA XRHSIMOEYSEI H AXRHSH OPEN FILE !!!!!
int FOS::FileManager::OpenFile(FILE* file,std::string filename)
    {
        //file=fopen(filename.c_str(),"rb+");
        //if(file==NULL)
            //return 0;
        //printf("%c\n",fgetc(file));
        //if(!feof(file))
            //return 0;
        //else 
        //fseek(file, 0L, SEEK_END);
        //int size=ftell(file)/PAGE_SIZE;
        //fclose(file); 
    //return size;
    }

int FOS::FileManager::CloseFile(FILE* file)
    {
        int numPages=this->FileHandle(file);
        //fclose(file);
    return 1;
    }

int FOS::FileManager::FileHandle(FILE* not_used)
    {
        FILE* myFile=fopen(this->fileName.c_str(),"rb+");
        size_t buffer_size=128+1-sizeof(int);
        char* buffer=(char*)malloc(buffer_size);
        sprintf(buffer,"%s",fileName.c_str());
        for(int j=0;j<buffer_size-fileName.length()-1;j++)
                strcat(buffer,"0");
        buffer[buffer_size]='\0';

        //calculate page count 
        fseek(myFile, 0L, SEEK_END);
        long int size = ftell(myFile);
        int numPages=size/PAGE_SIZE;

        //move to top and write info
        fseek(myFile, 0, SEEK_SET);
        int tmp1=numPages;
        char* tmp=(char*)&tmp1;
        //sprintf(buffer,"%c%c%c%c%s",(tmp)[0],(tmp)[1],(tmp)[2],(tmp)[3],this->data);
        fwrite(tmp,sizeof(char),4,myFile);
        fwrite(buffer,sizeof(char),strlen(buffer)-1,myFile);
        //fprintf(myFile,"%s",numPages,buffer);
        fclose(myFile);
    return numPages;
    }

int FOS::FileManager::ReadBlock(long int pagePos,FOS::DataPage* Page,FILE* file)
    {
        FILE* myFile=fopen(this->fileName.c_str(),"rb+");
        char* buffer=(char*)malloc((PAGE_SIZE)*sizeof(char));
        fseek(myFile,pagePos*PAGE_SIZE,SEEK_SET);
        fread(buffer,sizeof(char),PAGE_SIZE,myFile);
        for(int j=0;j<SIZEARRAY;j++)
            {
                fwrite(&buffer[j*RECSIZE],sizeof(char),RECSIZE,stdout);
            }
        fclose(myFile);
        free(buffer);
    return 1;
    };

//implement next and previous block here

int FOS::FileManager::WriteBlock(long int pagePos,FOS::DataPage* Page,FILE* not_used)
    {
        FILE* myFile=fopen(this->fileName.c_str(),"rb+");
        //char* buffer=(char*)malloc((PAGE_SIZE)*sizeof(char));
        std::string buffer;
        fseek(myFile,pagePos*PAGE_SIZE,SEEK_SET);
        for(int j=0;j<SIZEARRAY;j++)
            {
                char* tmp=Page->getNodes()[j].toByteArray();
                for(int j=0;j<RECSIZE;j++)
                    buffer.push_back(tmp[j]);
            }
        fwrite(buffer.c_str(),sizeof(char),PAGE_SIZE,myFile);
    fclose(myFile);
    return 1;
    }

//implement next and previous block here


int FOS::FileManager::ReadIndex(long int pagePos,FOS::IndexDataPage* Index,FILE* not_used)
    {
        FILE* myFile=fopen(this->IndexFile.c_str(),"rb+");
        if(myFile==NULL)
            return 0;
        char* buffer=(char*) malloc(sizeof(char)*INDEX_PAGE_SIZE+1);
        fread(buffer,sizeof(char),INDEX_PAGE_SIZE,myFile);
        fclose(myFile);
        buffer[INDEX_PAGE_SIZE+1]='\0';
        Index->fromIndexArray(buffer);
    return 1;
    }

int FOS::FileManager::WriteIndex(long int pagePos,FOS::IndexDataPage* Index,FILE* not_used)
    {
        std::string buffer=Index->toIndexArray();
        FILE* myFile=fopen(this->IndexFile.c_str(),"rb+");
        if(myFile==NULL)
            return 0;
        fwrite(buffer.c_str(),sizeof(char),buffer.length(),myFile);
        fclose(myFile);
    return 1;
    } 
