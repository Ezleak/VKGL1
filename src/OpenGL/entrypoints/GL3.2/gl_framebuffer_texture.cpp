/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_framebuffer_texture.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_attachment,
                     const GLuint&  in_texture,
                     const GLint&   in_level)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glFramebufferTexture(GLenum target,
                                                 GLenum attachment,
                                                 GLuint texture,
                                                 GLint  level)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFramebufferTexture(dispatch_table_ptr->bound_context_ptr,
                                              target,
                                              attachment,
                                              texture,
                                              level);
}

void vkglFramebufferTexture_execute(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLenum&  in_attachment,
                                    const GLuint&  in_texture,
                                    const GLint&   in_level)
{
    const auto attachment_vkgl = VKGL::Utils::get_framebuffer_attachment_point_for_gl_enum(in_attachment);
    const auto target_vkgl     = VKGL::Utils::get_framebuffer_target_for_gl_enum          (in_target);

    in_context_ptr->framebuffer_texture(target_vkgl,
                                        attachment_vkgl,
                                        in_texture,
                                        in_level);
}

void vkglFramebufferTexture_with_validation(VKGL::Context* in_context_ptr,
                                            const GLenum&  in_target,
                                            const GLenum&  in_attachment,
                                            const GLuint&  in_texture,
                                            const GLint&   in_level)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_attachment,
                 in_texture,
                 in_level) )
    {
        vkglFramebufferTexture_execute(in_context_ptr,
                                       in_target,
                                       in_attachment,
                                       in_texture,
                                       in_level);
    }
}
