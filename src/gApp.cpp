/*
 * gApp.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#include "gApp.h"
#include "gCanvas.h"

gApp::gApp() {
}

gApp::gApp(int argc, char** argv) : gBaseApp(argc, argv) {
}

gApp::~gApp() {
}

void gApp::setup() {
	gCanvas* cnv = new gCanvas(this);
	appmanager->setTargetFramerate(165);
	appmanager->enableVsync();
	appmanager->setCurrentCanvas(cnv);
}

void gApp::update() {
}
