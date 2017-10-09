#include "test.h"
#include <iostream>

using namespace std;

Counting_sort::Counting_sort(vector<int> _list,int _len,int _max)
{
	this->max = _max;
	this->len = _len;
	
	for(int i=0;i<_len;i++)
	{
		list.push_back(_list[i]);
		result.push_back(0);
		
		
	}
	
	
}











