/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_ACQUIRE_SWAPCHAIN_IMAGE_NODE_H
#define VKGL_VK_ACQUIRE_SWAPCHAIN_IMAGE_NODE_H

#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_frame_graph_node.h"

namespace OpenGL
{
    namespace VKNodes
    {
        class AcquireSwapchainImage : public OpenGL::IVKFrameGraphNode
        {
        public:
            /* Public functions */
            static VKFrameGraphNodeUniquePtr create(const IContextObjectManagers*         in_frontend_ptr,
                                                    IBackend*                             in_backend_ptr,
                                                    OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr);

            ~AcquireSwapchainImage();

        private:
            /* IVKFrameGraphNode */
            void do_cpu_prepass();

            const VKFrameGraphNodeInfo* get_info_ptr() const final
            {
                return m_info_ptr.get();
            }

            bool get_input_access_properties(const uint32_t&            in_n_input,
                                             Anvil::PipelineStageFlags* out_pipeline_stages_ptr,
                                             Anvil::AccessFlags*        out_access_flags_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();

                return false;
            }

            bool get_output_access_properties(const uint32_t&            in_n_output,
                                              Anvil::PipelineStageFlags* out_pipeline_stages_ptr,
                                              Anvil::AccessFlags*        out_access_flags_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();

                return false;
            }

            void get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                              const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            void on_commands_finished_executing_gpu_side() final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            void record_commands(Anvil::CommandBufferBase* in_cmd_buffer_ptr,
                                 const bool&               in_inside_renderpass) const final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            bool requires_cpu_prepass() const final
            {
                /* Image acquisition is a host-side operation. */
                return true;
            }

            bool requires_gpu_side_execution() const final
            {
                /* Nothing to do */
                return false;
            }

            bool supports_primary_command_buffers() const final
            {
                /* Should never be called. */
                vkgl_assert_fail();

                return false;
            }

            bool supports_renderpasses() const final
            {
                /* Should never be called. */
                vkgl_assert_fail();

                return false;
            }

            bool supports_secondary_command_buffers() const final
            {
                /* Should never be called. */
                vkgl_assert_fail();

                return false;
            }

            /* Private functions */

            AcquireSwapchainImage(const IContextObjectManagers*         in_frontend_ptr,
                                  OpenGL::IBackend*                     in_backend_ptr,
                                  OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr);

            /* Private variables */
            IBackend*                             m_backend_ptr;
            const IContextObjectManagers*         m_frontend_ptr;
            OpenGL::VKFrameGraphNodeInfoUniquePtr m_info_ptr;
            OpenGL::VKSwapchainReferenceUniquePtr m_swapchain_reference_ptr;

            Anvil::SemaphoreUniquePtr             m_frame_acquire_sem_ptr;
        };
    };
};

#endif /* VKGL_VK_ACQUIRE_SWAPCHAIN_IMAGE_NODE_H */