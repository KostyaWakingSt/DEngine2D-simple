#include "BaseModule.h"

void GameTime::updateTime(float timeForFrame) {
	m_currentTime += timeForFrame;
	m_deltaTime = timeForFrame;
}

float GameTime::getCurrentTime() const {
	return m_currentTime;
}

float GameTime::getDeltaTime() const {
	return m_deltaTime;
}

bool CoroutineData::validateInvoke(float curTime) {
	if (isTimeIsUp(curTime)) {
		m_invokeMethod();
		return true;
	}

	return false;
}

bool CoroutineData::isTimeIsUp(float curTime) const {
	return (curTime - m_startTime) >= m_timeToWait;
}

void Coroutine::updateCoroutine(float curTime) {
	m_currentTime = curTime;

	for (int i = 0; i < m_coroutines.size(); i++) {
		if (m_coroutines[i].validateInvoke(m_currentTime))
			m_coroutines.erase(m_coroutines.begin() + i);
	}
}

void Coroutine::addCoroutine(float timeToWait, std::function<void()> invokeMethod) {
	m_coroutines.push_back(CoroutineData(timeToWait, m_currentTime, invokeMethod));
}
