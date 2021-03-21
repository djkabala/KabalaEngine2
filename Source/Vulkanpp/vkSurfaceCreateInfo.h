#pragma once

#include "vkWindow.h"
#include <memory>

namespace vk
{

typedef std::shared_ptr<class SurfaceCreateInfo> SurfaceCreateInfoPtr;

class SurfaceCreateInfo
{
public:
	static SurfaceCreateInfoPtr Create(WindowPtr window);

	virtual void makeMyPoly() {}
protected:
};

};
