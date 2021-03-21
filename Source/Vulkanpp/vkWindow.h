#pragma once

#include <stdint.h>
#include <string>
#include <memory>

namespace vk
{

typedef std::shared_ptr<class Window> WindowPtr;

class Window
{
public:
	static WindowPtr Create(const std::wstring& name, const std::wstring& title, const int32_t posX, const int32_t posY, const uint32_t width, const uint32_t height);

	Window(const std::wstring& name, const std::wstring& title, const int32_t posX, const int32_t posY, const uint32_t width, const uint32_t height);

	virtual ~Window();

	virtual std::uintptr_t getWindowHandle(void) const = 0;
	virtual std::uintptr_t getOsInstanceHandle(void) const = 0;
protected:
};

};

