#pragma once

#include "BaseEngineComponents.h";

using namespace EngineComponent;

class ImageComponent : public Component {
public:
	void update(const float deltaTime) override;
	void initialize() override;

	void setRenderer(RendererComponent* const& renderer);
	void setSizeX(float X, bool scaleX = false);
	void setSizeY(float Y, bool scaleY = false);
private:
	RendererComponent* m_renderer;
};
//class GridComponent : public Component {
//public:
//	void update() override;
//	void initialize() override;
//private:
//	std::list<TransformComponent*> m_transforms;
//	std::TransformComponent*
//};