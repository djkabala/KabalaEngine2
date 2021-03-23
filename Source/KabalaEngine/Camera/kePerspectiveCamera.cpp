#include "kePerspectiveCamera.h"
#include <External/glm/gtc/matrix_transform.hpp>

ke::PerspectiveCamera::PerspectiveCamera(const float fieldOfView, const float aspectRatio, const float near, const float far, const glm::vec3& pos, const glm::vec3& lookAt, const glm::vec3& up)
{
    setProjection(fieldOfView, aspectRatio, near, far);
    setView(pos, lookAt, up);
}

void ke::PerspectiveCamera::setProjection(const float fieldOfView, const float aspectRatio, const float near, const float far)
{
    _projectionMatrix = glm::perspective(fieldOfView, aspectRatio, near, far);
}

void  ke::PerspectiveCamera::setView(const glm::vec3& pos, const glm::vec3& lookAt, const glm::vec3& up)
{
    _viewMatrix = glm::lookAt(pos, lookAt, up);
}
