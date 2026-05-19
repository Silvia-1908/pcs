#pragma once
#include <list>

template<typename T>
class fifo
{
private:
    std::list<T> elementi;

public:
	fifo() {}
	void put(const T& valore)
    {
        elementi.push_back(valore);
    }

    T get()
    {
        T valore = elementi.front();
		elementi.pop_front();
		return valore;
    }

    bool empty() const
    {
        return elementi.empty();
    }
};