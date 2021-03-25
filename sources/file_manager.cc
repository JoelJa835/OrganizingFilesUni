#include <file_manager.h>
#include <stdio.h>

int FOS::FileManager::CreateFile(std::string filename)
    {
        printf("file name is: %s\n",filename.c_str());
        FILE* myFile=fopen(filename.c_str(),"w");
        if(myFile==NULL)
            {
               // printf("File does not exist! Creating!\n");
               // fclose(myFile);
               // myFile=fopen(filename.c_str(),"w");
               // printf("check");
               // if(myFile==NULL)
               //     {
                        fprintf(stderr,"Error opening file!\n");
                        return 0;
               //     }
            }
        printf("File initialized!\n");
        fclose(myFile);
    return 1;
    }

int FOS::FileManager::OpenFile(FILE* file,std::string filename)
    {
        file=fopen(filename.c_str(),"rb+");
        if(file==NULL)
            return 0;
        int numPages=this->FileHandle(file);
    return numPages;
    }

int FOS::FileManager::CloseFile(FILE* file)
    {
        fclose(file);
    }

int FOS::FileManager::FileHandle(FILE* file)
    {
        fseek(file, 0L, SEEK_END);
        long int size = ftell(file);
        int numPages=size/PAGE_SIZE;
        fprintf(file,"%i%s",numPages,this->fileName.c_str());
        return numPages;
    }

int FOS::FileManager::ReadBlock(long int pagePos,FOS::DataPage* Page,FILE* file)
    {
        char* buffer=(char*)malloc((PAGE_SIZE+1)*sizeof(char));
        fseek(file,pagePos*PAGE_SIZE,SEEK_SET);
        if(fread(buffer,sizeof(char),PAGE_SIZE,file)!=PAGE_SIZE)
            {
                free(buffer);
                return 0;
            }
        Page->fromByteArray(buffer);
        free(buffer);
    return 1;
    };

//implement next and previous block here

int FOS::FileManager::WriteBlock(long int pagePos,FOS::DataPage* Page,FILE* file)
    {
        fseek(file,pagePos*PAGE_SIZE,SEEK_SET);
        //if(fprintf(file,"%s",Page->toByteArray())<0)
        //    return 0;
    return 1;
    }

//implement next and previous block here