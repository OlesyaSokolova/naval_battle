#include "Functions.h"
Fields::Fields()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->field1_[i][j] = blank;
			this->field2_[i][j] = blank;
		}
	}
}