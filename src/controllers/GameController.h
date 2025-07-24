//
// Created by sadettin on 7/15/25.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "controllers/ShipController.h"
#include "controllers/PlatformController.h"

class GameController {
public:
	GameController();
	~GameController();
	void WPressed() { shipcontroller->WPressed(); }
	void APressed() { shipcontroller->APressed(); }
	void SPressed() { shipcontroller->SPressed(); }
	void DPressed() { shipcontroller->DPressed(); }
	void FPressed() { shipcontroller->FPressed(); }
	void GPressed() { shipcontroller->GPressed(); }
	void WReleased() { shipcontroller->WReleased(); }
	void AReleased() { shipcontroller->AReleased(); }
	void SReleased() { shipcontroller->SReleased(); }
	void DReleased() { shipcontroller->DReleased(); }
	void mouseLeftRelease(const glm::vec2& clickedPos);
	void mouseRightRelease(const glm::vec2& clickedPos);

	void setup(const glm::vec2& minBoundary, const glm::vec2& maxBoundary) { shipcontroller->setup(minBoundary, maxBoundary); }
	void update(float deltaTime) { shipcontroller->update(deltaTime); }
	void draw() { playerplatformctrl->draw(); enemyplatformctrl->draw(); shipcontroller->draw(); }
private:
	ShipController* shipcontroller;
	PlatformController* playerplatformctrl;
	PlatformController* enemyplatformctrl;
};

#endif //GAMECONTROLLER_H
