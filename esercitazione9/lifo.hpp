#pragma once
#include <list>

template<typename T>
class lifo
{
private:
    std::list<T> elementi;

public:
	lifo() {}
	void put(const T& valore)
    {
        elementi.push_back(valore);
    }

    T get()
    {
        T valore = elementi.back();
		elementi.pop_back();
		return valore;
    }

    bool empty() const
    {
        return elementi.empty();
    }
};