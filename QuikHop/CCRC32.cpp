#include <assert.h>
#include "CCRC32.h"

CCRC GCRC;

DWORD* crctable = 0;

void CCRC::generate_crc32_table()
{
	assert(!crctable);

	DWORD dwPolynomial = 0xEDB88320;
	crctable = new DWORD[256];

	DWORD x;
	D_CHECKPOINT
	for(int i = 0; i < 256; i++)
	{
		x = i;
		for(int j = 8; j > 0; j--)
		{
			if(x & 1) { x = (x >> 1) ^ dwPolynomial; }
			else      { x >>= 1; }
		}
		crctable[i] = x;
	}
	D_CHECKPOINT
}