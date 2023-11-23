#pragma once

#include<list>
#include<vector>
#include<functional>

template <typename...> class Action;

class ActionEmpty {
public:
	void operator+=(void(*other)())
	{
		m_functions.push_back(other);
	}

	void operator-=(void(*other)())
	{
		m_functions.remove(other);
	}

	void invoke() {
		for (auto& func : m_functions) {
			func();
		}
	}
private:
	std::list<void(*)()> m_functions;
};

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

class GameEventHandler {
public:
	ActionEmpty* getBeforeUpdateEvent() {
		return &m_beforeUpdate;
	}

	ActionEmpty* getAfterUpdateEvent() {
		return &m_afterUpdate;
	}

private:
	ActionEmpty m_beforeUpdate;
	ActionEmpty m_afterUpdate;
};

class GameTime {
public:
	void updateTime(float timeForFrame);

	float getCurrentTime() const;
	float getDeltaTime() const;
private:
	float m_currentTime;
	float m_deltaTime;
};


struct CoroutineData
{
public:
	CoroutineData(float waitTime, float startTime, std::function<void()> invokeMethod) {
		m_timeToWait = waitTime;
		m_startTime = startTime;
		m_invokeMethod = invokeMethod;
	}

	bool validateInvoke(float curTime);
private:
	bool isTimeIsUp(float curTime) const;

	float m_timeToWait;
	float m_startTime;

	std::function<void()> m_invokeMethod;
};

class Coroutine {
public:
	void updateCoroutine(float curTime);

	void addCoroutine(float timeToWait, std::function<void()> invokeMethod);
private:
	std::vector<CoroutineData> m_coroutines;
	float m_currentTime;
};