#include "SceneModule.h"

using namespace EngineScene;
extern SceneManager global_sceneManager;

SceneObject::SceneObject(const std::string name) {
	m_name = name;
}

SceneObject::SceneObject() { }

std::string SceneObject::getName() const {
	return m_name;
}

void SceneObject::setName(const std::string name) {
	m_name = name;
}

void SceneObject::update() {
	for (auto& component : m_components) {
		component->update();
	}
}

void SceneEntity::update() {
	for (auto& sceneObj : m_objects) {
		sceneObj->update();
	}
}

void SceneEntity::initialize() {
	if (m_initFunc)
		m_initFunc(this);
}

void SceneEntity::setInitFunc(void(*initFunc)(SceneEntity* const&)) {
	m_initFunc = initFunc;
}

SceneObject* SceneEntity::findObjectByName(const std::string name, const bool& first) {
	SceneObject* output = nullptr;

	for (auto& sceneObj : m_objects) {
		if (sceneObj->getName() == name) {
			output = sceneObj.get();

			if (first)
				break;
		}
	}

	return output;
}

SceneObject* SceneEntity::findInActiveScene(const std::string name) {
	EngineScene::SceneObject* output = nullptr;

	for (auto& sceneObj : global_sceneManager.getActiveScene()->getAllObjectsOnScene()) {
		if (sceneObj.get()->getName() == name) {
			output = sceneObj.get();
			break;
		}
	}

	return output;
}

void SceneEntity::addObject(SceneObject& const obj) {
	m_objects.push_back(std::shared_ptr<SceneObject>(new SceneObject(obj)));
}

void SceneEntity::removeObject(SceneObject* const& obj) {
	m_objects.remove(static_cast<std::shared_ptr<SceneObject>>(obj));
}

std::list<std::shared_ptr<SceneObject>> SceneEntity::getAllObjectsOnScene() const {
	return m_objects;
}

void SceneEntity::create(SceneObject& sceneObj) {
	global_sceneManager.getActiveScene()->addObject(sceneObj);
}

void SceneManager::addScene(const SceneEntity& scene) {
	m_scenes.push_back(scene);
}

//---TODO---
void SceneManager::removeScene(const int sceneIndex) {
	//m_scenes.erase(m_scenes.begin() + sceneIndex);
}

void SceneManager::initialize(const int startSceneIndex) {
	setScene(startSceneIndex);
}

void SceneManager::setScene(const int index) {
	if (m_currentScene != nullptr) {
		delete m_currentScene;
	}

	m_currentScene = new SceneEntity(m_scenes.at(index));
	m_currentScene->initialize();
}

void SceneManager::update() {
	if (m_currentScene != nullptr) {
		m_currentScene->update();
	}
}

SceneEntity* SceneManager::getActiveScene() {
	return m_currentScene;
}