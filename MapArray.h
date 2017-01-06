


#include<iostream>
using namespace std;

#include<algorithm>
#include<iterator>

#include<initializer_list>
#include<iomanip>
//template
//   <typename T>


class MapArray
{ 
	int siz;
	pair<int, string>* buf;
	
public:
struct iterator
	{ 
	typedef std::forward_iterator_tag iterator_category;
	typedef iterator self_type;
	typedef pair<int, string> value_type;
	typedef pair<int, string>& reference;
	typedef pair<int, string>* pointer;
	typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		iterator(pointer ptr) : buf(ptr) { }
		self_type operator++() { ++buf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf++; return cpy; }
		reference operator*() { return *buf; }
		pointer operator->(){ return buf; }
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	}; 
class const_iterator
	{ 
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef pair<int, string> value_type;
		typedef pair<int, string>& reference;
		typedef pair<int, string>* pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		const_iterator(pointer ptr) : buf(ptr) { }
		self_type operator++() { ++buf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf++; return cpy; }
		const reference operator*() { return *buf; }
		const pointer operator->(){ return buf;} 
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	};


MapArray(int size) : buf(new pair<int , string>[siz]), siz(size) {}	
MapArray(initializer_list<pair<int, string>> s) : buf(new pair<int , string>[siz]), siz(s.size()){ uninitialized_copy(s.begin(), s.end(), buf);}
	
	
	int size() const { return siz; }
	int & operator[](string str)
	{
	for(int i=0; i<=siz;i++)		
		if(buf[i].second==str)
			return buf[i].first;
	}

	string & operator[](int index) const { 
	for(int i=0; i<=siz;i++)	
		if(buf[i].first==index)		
			return buf[i].second;
			
		
	}
	iterator begin() { return iterator(buf); }
	iterator end() { return iterator(buf + siz); }
	const_iterator begin() const { return const_iterator(buf); }
	const_iterator end() const { return const_iterator(buf + siz); }

	~MapArray() { delete[] buf; }
};
/*
int main()
{
MapArray M{{1,"apple"},{2,"oranges"},{10,"watermelon"},{22, "kiwi"},{5, "banana"}};
cout<<M.size()<<endl;
cout<<M[1]<<endl;
cout<<M[5]<<endl;
cout<<M["watermelon"]<<endl;
cout<<M["banana"]<<endl;
cout<<M[22]<<endl;
return 0;
}
*/





