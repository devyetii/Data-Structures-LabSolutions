#pragma once
template <typename T>

class LazyList
{
	T* arr; int sz;
	bool* isDel;
	int del_cnt, kept_cnt;
	void _PhysicalDelete();
public :
	LazyList(T*, int);
	int Search(const T) const;
	bool Delete(const T val);
	void Display() const;
};

template <typename T>
void LazyList<T>::_PhysicalDelete()
{
	T* new_arr = new T[kept_cnt]; int cnt = 0;
	for (int i = 0; i < sz; ++i)
		if (!isDel[i]) new_arr[cnt++] = arr[i];
	delete[] this->arr;
	this->arr = new_arr;
	this->del_cnt = 0; this->kept_cnt = cnt;
	this->sz = cnt;
}

template <typename T>
LazyList<T>::LazyList(T* arr, int sz)
{
	this->arr = new T[sz];
	for (int i = 0; i < sz; ++i) this->arr[i] = arr[i];
	this->sz = sz;
	this->del_cnt = 0;
	this->kept_cnt = sz;
	for(int i =0;i<sz;i++) isDel[i] = 0;
}

template <typename T>
int LazyList<T>::Search(const T val) const
{
	for (int i = 0; i <sz; ++i)
		if (arr[i] == val && !isDel[i]) return i;
	return -1;
}

template <typename T>
void LazyList<T>::Display() const
{
	for(int i = 0; i<sz; ++i)
		if (!isDel[i]) cout << arr[i]; << ' ';
	cout << '\n';
}

template <typename T>
bool LazyList<T>::Delete(const T val)
{
	if (this->Search(val) == -1) return false;
	isDel[Search(val)] = 1;
	del_cnt++; kept_cnt--;
	if( del_cnt >= kept_cnt )
		_PhysicalDelete();
	return true;
}
