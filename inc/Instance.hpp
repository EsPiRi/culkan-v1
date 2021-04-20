#pragma once
#include <vulkan/vulkan.h>
#include <vector>

// void createInstance()
// {
// 	if (enableValidationLayers && !checkValidationLayerSupport())
// 	{
// 		throw std::runtime_error("validation layers requested, but not available!");
// 	}

// 	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;
// 	if (enableValidationLayers)
// 	{
// 		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
// 		createInfo.ppEnabledLayerNames = validationLayers.data();

// 		populateDebugMessengerCreateInfo(debugCreateInfo);
// 		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT *)&debugCreateInfo;
// 	}
// 	else
// 	{
// 		createInfo.enabledLayerCount = 0;
// 		createInfo.pNext = nullptr;
// 	}
// }
class Instance
{

public:
	VkInstance handle;
	Instance()
	{
		std::vector<const char *> requiredExtensions = getRequiredExtensions();

		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Culkan";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(requiredExtensions.size());
		createInfo.ppEnabledExtensionNames = requiredExtensions.data();
		createInfo.enabledLayerCount = 0;
		createInfo.pNext = nullptr;

		if (vkCreateInstance(&createInfo, nullptr, &handle) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create instance!");
		}
	}
	~Instance()
	{
		vkDestroyInstance(handle, nullptr);
	}

	std::vector<const char *> getRequiredExtensions()
	{
		uint32_t glfwExtensionCount = 0;
		const char **glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		std::vector<const char *> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
		// if (enableValidationLayers)
		// {
		// 	extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		// }

		return extensions;
	}
};