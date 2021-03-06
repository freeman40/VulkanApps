#pragma once

#include <vulkan/vulkan.hpp>

namespace Vulkan {

class Image {
public:

   Image(vk::Device device, const vk::PhysicalDevice physicalDevice, const vk::ImageViewType type, const uint32_t width, const uint32_t height, const uint32_t mipLevels, vk::SampleCountFlagBits numSamples, const vk::Format format, const vk::ImageTiling tiling, const vk::ImageUsageFlags usage, const vk::MemoryPropertyFlags properties);
   Image(vk::Device device, const vk::Image& image);
   Image(const Image&) = delete;   // You cannot copy Vulkan::Image wrapper object
   Image(Image&& that);  // but you can move it (i.e. move the underlying vulkan resources to another Vulkan::Image wrapper)

   Image& operator=(const Image&) = delete;
   Image& operator=(Image&& that);

   virtual ~Image();

   vk::ImageViewType m_Type = vk::ImageViewType::e2D;
   vk::Image m_Image;
   vk::DeviceMemory m_Memory;
   vk::ImageView m_ImageView;

   void CreateImageView(const vk::Format format, const vk::ImageAspectFlags imageAspect, const uint32_t mipLevels);
   void DestroyImageView();

protected:
   vk::Device m_Device;
};

}