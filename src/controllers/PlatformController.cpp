//
// Created by sadettin on 7/13/25.
//

#include "controllers/PlatformController.h"

PlatformController::PlatformController(const std::string& path, std::initializer_list<glm::vec2> positions, const glm::vec2& platformSize, float angle)
	: selectedplatform(nullptr) {
	platforms = new Object2D<Type2D::VECTOR, Pos2D::FIXED, Tex2D::IMAGE>();
	size_t index = 0;
	for (const auto& pos : positions) {
		auto* texture = new gImage();
		if (!texture->loadImage(path)) {
			gLoge("PlatformController::PlatformController") << "Failed to load platform image from: " << path;
			delete texture;
			break;
		}
		platforms->addTexture(texture);
		platforms->addObject2D(index, pos, angle, platformSize, 1.0f);
		index++;
	}
}

PlatformController::~PlatformController() {
	delete platforms;
}

void PlatformController::mouseLeftRelease(const glm::vec2& clickedPos) {
	selectedplatform = nullptr;
	auto selectionIter = platforms->selectObject2D(clickedPos);
	if (selectionIter != platforms->end()) {
		gLogi("PlatformController::mouseLeftRelease") << "Platform selected at position: " << clickedPos.x << ", " << clickedPos.y;
		selectedplatform = *selectionIter;
	}
}

void PlatformController::draw() const {
	platforms->draw();
}
