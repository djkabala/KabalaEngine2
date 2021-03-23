#pragma once

#include "keCamera.h"
#include <External/glm/vec3.hpp>

namespace ke
{

class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera(const float fieldOfView, const float aspectRatio, const float near, const float far, const glm::vec3& pos, const glm::vec3& lookAt, const glm::vec3& up);

    void setProjection(const float fieldOfView, const float aspectRatio, const float near, const float far);

    void setView(const glm::vec3& pos, const glm::vec3& lookAt, const glm::vec3& up);

protected:

};

typedef std::shared_ptr<PerspectiveCamera> PerspectiveCameraPtr;

};
