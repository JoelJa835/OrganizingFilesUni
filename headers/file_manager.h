#include <string>
#include <fos.h>
#include <page.h>

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define PAGE_SIZE 128

namespace FOS
{
	class FileManager
		{
			std::string fileName;
			long int filePtr;
			char* buffer;
	//Getters
	public:
		char* getBuffer() 
			{ 
			return buffer; 
			}

		std::string getFileName()
			{
			return fileName;
			}

		long getFilePtr() 
			{
			return filePtr;
			}

		//file operators
		int CreateFile(std::string filename);

		int OpenFile(FILE* file,std::string filename);
		int CloseFile(FILE* file);

		int FileHandle(FILE* file);

		//block handlers
		int ReadBlock(long int pagePos,FOS::DataPage* Page,FILE* file);
		//int ReadNextBlock(FILE* file);
		//int ReadPrevBlock(FILE* file);

		int WriteBlock(long int pagePos,FOS::DataPage* Page,FILE* file);
		};

};
#endif
