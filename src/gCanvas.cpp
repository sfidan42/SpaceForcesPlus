/*
* gCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
*/

#include "gCanvas.h"

gCanvas::gCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
	gamecontroller = new GameController();
	font = new gFont();
}

gCanvas::~gCanvas() {
	delete gamecontroller;
	delete font;
}

void gCanvas::setup() {
	std::string backgroundImg = "map.png";
	if(!background.loadImage(backgroundImg)) {
		gLoge("gCanvas::setup") << "Failed to load background image.";
	} else {
		gLogi("gCanvas::setup") << "Background image loaded from " << backgroundImg;
	}
	glm::vec2 windowSize = {
		renderer->getUnitWidth(),
		renderer->getUnitHeight()
	};
	gamecontroller->setup(glm::vec2(0.0f), windowSize);
	font->loadFont("FreeSansBold.ttf", 16);
}

void gCanvas::update() {
	const float deltaTime = appmanager->getElapsedTime();
	gamecontroller->update(deltaTime);
}

void gCanvas::draw() {
	background.draw(0, 0);
	gamecontroller->draw();
	font->drawText("fps: " + gToStr(appmanager->getFramerate()), 0.0f, 16.0f);
}

void gCanvas::keyPressed(int key) {
	switch(key) {
	case G_KEY_W: gamecontroller->WPressed();
		break;
	case G_KEY_A: gamecontroller->APressed();
		break;
	case G_KEY_S: gamecontroller->SPressed();
		break;
	case G_KEY_D: gamecontroller->DPressed();
		break;
	case G_KEY_F: gamecontroller->FPressed();
		break;
	case G_KEY_G: gamecontroller->GPressed();
		break;
	default: break;
	}
}

void gCanvas::keyReleased(int key) {
	switch(key) {
	case G_KEY_W: gamecontroller->WReleased();
		break;
	case G_KEY_A: gamecontroller->AReleased();
		break;
	case G_KEY_S: gamecontroller->SReleased();
		break;
	case G_KEY_D: gamecontroller->DReleased();
		break;
	default: break;
	}
}

void gCanvas::charPressed(unsigned int codepoint) {
	//	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
	//	gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
	//	gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mousePressed(int x, int y, int button) {
	//	gLogi("gCanvas") << "mousePressed" << ", x:" << x << ", y:" << y << ", button:" << button;
}

void gCanvas::mouseReleased(int x, int y, int button) {
	switch(button) {
	case GLFW_MOUSE_BUTTON_LEFT:
		gamecontroller->mouseLeftRelease(glm::vec2(x, y));
		break;
	case GLFW_MOUSE_BUTTON_RIGHT:
		gamecontroller->mouseRightRelease(glm::vec2(x, y));
		break;
	default:
		break;
	}
}

void gCanvas::mouseScrolled(int x, int y) {
	//	gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseEntered() {
}

void gCanvas::mouseExited() {
}

void gCanvas::windowResized(int w, int h) {
}

void gCanvas::showNotify() {
}

void gCanvas::hideNotify() {
}
