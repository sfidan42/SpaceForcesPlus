//
// Created by sadettin on 7/13/25.
//

#ifndef PLATFORMCONTROLLER_H
#define PLATFORMCONTROLLER_H
#include <string>
#include <glm/glm.hpp>
#include "datatypes/Object2D.h"


class PlatformController {
public:
	PlatformController(const std::string& path, std::initializer_list<glm::vec2> positions, const glm::vec2& platformSize, float angle);
	~PlatformController();
	void mouseLeftRelease(const glm::vec2& clickedPos);
	void draw() const;

	Object2D<Type2D::NODE, Pos2D::FIXED, Tex2D::IMAGE>* getSelectedPlatform() const {
		return dynamic_cast<Object2D<Type2D::NODE, Pos2D::FIXED, Tex2D::IMAGE>*>(selectedplatform);
	}

private:
	Object2D<Type2D::INTERFACE, Pos2D::FIXED, Tex2D::IMAGE>* selectedplatform;
	Object2D<Type2D::VECTOR, Pos2D::FIXED, Tex2D::IMAGE>* platforms;
};



#endif //PLATFORMCONTROLLER_H
