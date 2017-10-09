#ifdef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <vector>

using namespace std;

class Counting_sort
{
	private:
		int len;
		int max;
		vector<int> list;
		vector<int> result;
	public:
		Counting_sort(vector<int> _list,int _len,int _max);
		void counting_sort();
		void out();
	
};

#endif

















