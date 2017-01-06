//Pairut Dumkuengthanant
//64856070

#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <initializer_list>
#include <utility>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include "setlist.h"
#include "MapArray.h"
int main()
{
	map<string, int>map_in;
	map<string, int>map_ex;

	ifstream file_in("sample_doc.txt");
	ifstream file_ex("stopwords.txt");
	ofstream file_out("frequency.txt");
	for_each(istream_iterator<string>(file_ex), istream_iterator<string>(),[&](string s)
			{
			map_ex[s]++;
			map_ex.insert(make_pair(s,1));
			});
	for_each(istream_iterator<string>(file_in), istream_iterator<string>(),[&](string s)
			{
			if(map_ex[s]!=1)
				{
				map_in[s]++;
				map_in.insert(make_pair(s,1));
				}
			});

	file_in.close();
	file_ex.close();
	
	for_each(map_in.begin(), map_in.end(), [&](pair<string, int>m)
	{
		cout<<m.first<<"__"<<m.second<<endl;
		file_out<<m.first<<"__"<<m.second<<endl;
	});
	file_out.close();
	return 0;
}
	
		
	
