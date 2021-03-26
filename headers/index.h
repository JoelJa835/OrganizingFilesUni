#include <fos.h>
#include <page.h>
#include <vector>
#include <array>

#ifndef INDEX_H
#define INDEX_H

#define INDEX_PAGE_SIZE 128
#define DATAPAGE_COUNT 4
#define PAIR_SIZE 8

namespace FOS
{
	class IndexDataPage
		{
			public:
			FOS::DataPage pages[4];

			//first key then index
			std::vector<std::array<int,2>> index;

			public:

			std::string toIndexArray(void);
			void fromIndexArray(char* array);

		};
}

#endif
