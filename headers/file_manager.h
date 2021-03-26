#include <string>
#include <fos.h>
#include <page.h>
#include <index.h>

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define PAGE_SIZE 128

namespace FOS
{
	class FileManager
		{
			std::string fileName;
			std::string IndexFile;
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

		//file operators
		int CreateFile(std::string filename);
		int CreateFile(std::string filename,std::string index_name);

		int OpenFile(FILE* file,std::string filename);
		int CloseFile(FILE* file);

		int FileHandle(FILE* file);

		//block handlers
		int ReadBlock(long int pagePos,FOS::DataPage* Page,FILE* not_used);
		//int ReadNextBlock(FILE* file);
		//int ReadPrevBlock(FILE* file);

		int WriteBlock(long int pagePos,FOS::DataPage* Page,FILE* not_used);

		int ReadIndex(long int pagePos,FOS::IndexDataPage* Index,FILE* not_used);
		int WriteIndex(long int pagePos,FOS::IndexDataPage* Index,FILE* not_used);
		};

};
#endif
