#pragma once

#include<list>

template <typename...> class Action;

template <typename T>
class Action<T> {
public:
	void operator+=(void(*other)(T))
	{
		m_functions.push_back(other);
	}

	void operator-=(void(*other)(T))
	{
		m_functions.remove(other);
	}

	void invoke(const T& val) {
		for (auto& func : m_functions) {
			func(val);
		}
	}
private:
	std::list<void(*)(T)> m_functions;
};

template <typename T, typename T1>
class Action<T, T1> {
public:
	void operator+=(void(*other)(T, T))
	{
		m_functions.push_back(other);
	}

	void operator-=(void(*other)(T, T))
	{
		m_functions.remove(other);
	}

	void invoke(const T& val, const T& val2) {
		for (auto& func : m_functions) {
			func(val, val2);
		}
	}
private:
	std::list<void(*)(T, T)> m_functions;
};