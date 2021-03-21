#include "vkWindow.h"
#ifdef WIN64
#include "vkWindowWIN.h"
#endif

vk::WindowPtr vk::Window::Create(const std::wstring& name, const std::wstring& title, const int32_t posX, const int32_t posY, const uint32_t width, const uint32_t height)
{
#ifdef WIN64
	vk::WindowPtr windowPtr(new WindowWIN(name, title, posX, posY, width, height));
#else
#endif

	return windowPtr;
}

vk::Window::Window(const std::wstring& name, const std::wstring& title, const int32_t posX, const int32_t posY, const uint32_t width, const uint32_t height)
{

}

vk::Window::~Window()
{

}
