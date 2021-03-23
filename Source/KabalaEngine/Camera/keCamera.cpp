#include "keCamera.h"

// Vulkan clip space has inverted Y and half Z.
// clang-format off
glm::mat4x4 ke::Camera::_vkClipMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
                                                0.0f,-1.0f, 0.0f, 0.0f,
                                                0.0f, 0.0f, 0.5f, 0.0f,
                                                0.0f, 0.0f, 0.5f, 1.0f);
