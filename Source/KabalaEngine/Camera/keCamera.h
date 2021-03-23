#pragma once

#include <memory>
#include <External/glm/mat4x4.hpp>

namespace ke
{

class Camera
{
public:
    inline const glm::mat4x4 getProjectionViewClipMatrix(void) const { return _vkClipMatrix * getProjectionViewMatrix(); }

    inline const glm::mat4x4 getProjectionViewMatrix(void) const { return _projectionMatrix * _viewMatrix; }

    inline void setProjectionMatrix(const glm::mat4x4& matrix) { _projectionMatrix = matrix; }

    inline const glm::mat4x4& getProjectionMatrix(void) const { return _projectionMatrix; }

    inline void setViewMatrix(const glm::mat4x4& matrix) { _viewMatrix = matrix; }

    inline const glm::mat4x4& getViewMatrix(void) const { return _viewMatrix; }

protected:
    static glm::mat4x4 _vkClipMatrix;

    glm::mat4x4 _projectionMatrix;

    glm::mat4x4 _viewMatrix;
};

typedef std::shared_ptr<Camera> CameraPtr;

};