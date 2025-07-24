/*
 * ShipController.h
 *
 *  Created on: Jul 3, 2025
 *      Author: sadettin
 */

#ifndef SRC_CONTROLLERS_SHIPCONTROLLER_H_
#define SRC_CONTROLLERS_SHIPCONTROLLER_H_
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include "gImage.h"
#include "gFile.h"
#include "gFont.h"
#include "animation/SpriteAnimator.h"
#include "datatypes/Object2D.h"


class ShipController {
public:
	ShipController();
	~ShipController();
	void WPressed() { speed.y -= 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void APressed() { speed.x -= 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void SPressed() { speed.y += 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void DPressed() { speed.x += 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void FPressed();
	void GPressed();
	void WReleased() { speed.y += 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void AReleased() { speed.x += 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void SReleased() { speed.y -= 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void DReleased() { speed.x -= 1000.0f; if(selectedship) selectedship->setSpeed(speed); }
	void mouseLeftRelease(const glm::vec2& clickedPos);
	void mouseRightRelease(const glm::vec2& clickedPos);

	void setup(const glm::vec2& minBoundary, const glm::vec2& maxBoundary);
	void update(float deltaTime);
	void draw() const;

	Object2D<Type2D::NODE, Pos2D::MOVING, Tex2D::SPRITE>* getSelectedShip() const {
		return dynamic_cast<Object2D<Type2D::NODE, Pos2D::MOVING, Tex2D::SPRITE>*>(selectedship);
	}

private:
	glm::vec2 speed = glm::vec2(0.0f);

	Object2D<Type2D::VECTOR, Pos2D::FIXED, Tex2D::SPRITE>* fixedships = nullptr;
	Object2D<Type2D::VECTOR, Pos2D::MOVING, Tex2D::SPRITE>* movableships = nullptr;
	Object2D<Type2D::INTERFACE, Pos2D::MOVING, Tex2D::SPRITE>* selectedship = nullptr;

	Object2D<Type2D::VECTOR, Pos2D::MOVING, Tex2D::IMAGE>* bullets;
	gImage bulletframe;

	SpriteAnimator *animator = nullptr;

	gFont* font;
};

#endif /* SRC_CONTROLLERS_SHIPCONTROLLER_H_ */
