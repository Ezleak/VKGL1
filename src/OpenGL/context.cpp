/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "Common/types.h"
#include "OpenGL/types.h"
#include "OpenGL/context.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "OpenGL/frontend/gl_program_manager.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/gl_renderbuffer_manager.h"
#include "OpenGL/frontend/gl_shader_manager.h"
#include "OpenGL/frontend/gl_vao_manager.h"
#include "OpenGL/frontend/gl_compatibility_manager.h"
#include "OpenGL/backend/vk_buffer_manager.h"
#include "OpenGL/backend/vk_spirv_manager.h"
#include "OpenGL/backend/vk_renderpass_manager.h"
#include "OpenGL/backend/vk_framebuffer_manager.h"
#include "OpenGL/backend/vk_image_manager.h"
#include "OpenGL/utils_enum.h"
/*
#include "OpenGL/entrypoints/GL1.0/gl_blend_func.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear_color.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear_depth.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear_stencil.h"
#include "OpenGL/entrypoints/GL1.0/gl_color_mask.h"
#include "OpenGL/entrypoints/GL1.0/gl_cull_face.h"
#include "OpenGL/entrypoints/GL1.0/gl_depth_func.h"
#include "OpenGL/entrypoints/GL1.0/gl_depth_mask.h"
#include "OpenGL/entrypoints/GL1.0/gl_depth_range.h"
#include "OpenGL/entrypoints/GL1.0/gl_disable.h"
#include "OpenGL/entrypoints/GL1.0/gl_draw_buffer.h"
#include "OpenGL/entrypoints/GL1.0/gl_enable.h"
#include "OpenGL/entrypoints/GL1.0/gl_finish.h"
#include "OpenGL/entrypoints/GL1.0/gl_flush.h"
#include "OpenGL/entrypoints/GL1.0/gl_front_face.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_booleanv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_doublev.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_error.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_floatv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_integerv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_string.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_image.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameterfv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameteriv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_parameterfv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_parameteriv.h"
#include "OpenGL/entrypoints/GL1.0/gl_hint.h"
#include "OpenGL/entrypoints/GL1.0/gl_is_enabled.h"
#include "OpenGL/entrypoints/GL1.0/gl_line_width.h"
#include "OpenGL/entrypoints/GL1.0/gl_logic_op.h"
#include "OpenGL/entrypoints/GL1.0/gl_pixel_storef.h"
#include "OpenGL/entrypoints/GL1.0/gl_pixel_storei.h"
#include "OpenGL/entrypoints/GL1.0/gl_point_size.h"
#include "OpenGL/entrypoints/GL1.0/gl_polygon_mode.h"
#include "OpenGL/entrypoints/GL1.0/gl_read_buffer.h"
#include "OpenGL/entrypoints/GL1.0/gl_read_pixels.h"
#include "OpenGL/entrypoints/GL1.0/gl_scissor.h"
#include "OpenGL/entrypoints/GL1.0/gl_stencil_func.h"
#include "OpenGL/entrypoints/GL1.0/gl_stencil_mask.h"
#include "OpenGL/entrypoints/GL1.0/gl_stencil_op.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_image_1d.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_image_2d.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterf.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterfv.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteri.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteriv.h"
#include "OpenGL/entrypoints/GL1.0/gl_viewport.h"

#include "OpenGL/entrypoints/GL1.1/gl_bind_texture.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_1d.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_2d.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_1d.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_2d.h"
#include "OpenGL/entrypoints/GL1.1/gl_delete_textures.h"
#include "OpenGL/entrypoints/GL1.1/gl_draw_arrays.h"
#include "OpenGL/entrypoints/GL1.1/gl_draw_elements.h"
#include "OpenGL/entrypoints/GL1.1/gl_gen_textures.h"
#include "OpenGL/entrypoints/GL1.1/gl_is_texture.h"
#include "OpenGL/entrypoints/GL1.1/gl_polygon_offset.h"
#include "OpenGL/entrypoints/GL1.1/gl_tex_sub_image_1d.h"
#include "OpenGL/entrypoints/GL1.1/gl_tex_sub_image_2d.h"

#include "OpenGL/entrypoints/GL1.2/gl_copy_tex_sub_image_3d.h"
#include "OpenGL/entrypoints/GL1.2/gl_draw_range_elements.h"
#include "OpenGL/entrypoints/GL1.2/gl_tex_image_3d.h"
#include "OpenGL/entrypoints/GL1.2/gl_tex_sub_image_3d.h"

#include "OpenGL/entrypoints/GL1.3/gl_active_texture.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_1d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_2d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_3d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_1d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_2d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_3d.h"
#include "OpenGL/entrypoints/GL1.3/gl_get_compressed_tex_image.h"
#include "OpenGL/entrypoints/GL1.3/gl_sample_coverage.h"

#include "OpenGL/entrypoints/GL1.4/gl_blend_color.h"
#include "OpenGL/entrypoints/GL1.4/gl_blend_equation.h"
#include "OpenGL/entrypoints/GL1.4/gl_blend_func_separate.h"
#include "OpenGL/entrypoints/GL1.4/gl_multi_draw_arrays.h"
#include "OpenGL/entrypoints/GL1.4/gl_multi_draw_elements.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterf.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterfv.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameteri.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameteriv.h"

#include "OpenGL/entrypoints/GL1.5/gl_begin_query.h"
#include "OpenGL/entrypoints/GL1.5/gl_bind_buffer.h"
#include "OpenGL/entrypoints/GL1.5/gl_buffer_data.h"
#include "OpenGL/entrypoints/GL1.5/gl_buffer_sub_data.h"
#include "OpenGL/entrypoints/GL1.5/gl_delete_buffers.h"
#include "OpenGL/entrypoints/GL1.5/gl_delete_queries.h"
#include "OpenGL/entrypoints/GL1.5/gl_end_query.h"
#include "OpenGL/entrypoints/GL1.5/gl_gen_buffers.h"
#include "OpenGL/entrypoints/GL1.5/gl_gen_queries.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_parameteriv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_pointerv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_sub_data.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_queryiv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_query_objectiv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_query_objectuiv.h"
#include "OpenGL/entrypoints/GL1.5/gl_is_buffer.h"
#include "OpenGL/entrypoints/GL1.5/gl_is_query.h"
#include "OpenGL/entrypoints/GL1.5/gl_map_buffer.h"
#include "OpenGL/entrypoints/GL1.5/gl_unmap_buffer.h"

#include "OpenGL/entrypoints/GL2.0/gl_attach_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_bind_attrib_location.h"
#include "OpenGL/entrypoints/GL2.0/gl_blend_equation_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_compile_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_create_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_create_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_delete_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_delete_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_detach_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_disable_vertex_attrib_array.h"
#include "OpenGL/entrypoints/GL2.0/gl_draw_buffers.h"
#include "OpenGL/entrypoints/GL2.0/gl_enable_vertex_attrib_array.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_active_attrib.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_active_uniform.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_attached_shaders.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_attrib_location.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_programiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_program_info_log.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_shaderiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_shader_info_log.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_shader_source.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_uniformfv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_uniformiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_uniform_location.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribdv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribfv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attrib_pointerv.h"
#include "OpenGL/entrypoints/GL2.0/gl_is_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_is_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_link_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_shader_source.h"
#include "OpenGL/entrypoints/GL2.0/gl_stencil_func_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_stencil_mask_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_stencil_op_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_2fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_3fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_4fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_use_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_validate_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4bv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nbv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Niv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nsv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nub.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nubv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nuiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nusv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4ubv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4uiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4usv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_pointer.h"

#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_2x3_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_2x4_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_3x2_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_3x4_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_4x2_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_4x3_fv.h"

#include "OpenGL/entrypoints/GL3.0/gl_begin_conditional_render.h"
#include "OpenGL/entrypoints/GL3.0/gl_begin_transform_feedback.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_buffer_base.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_buffer_range.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_frag_data_location.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_framebuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_renderbuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_vertex_array.h"
#include "OpenGL/entrypoints/GL3.0/gl_blit_framebuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_check_framebuffer_status.h"
#include "OpenGL/entrypoints/GL3.0/gl_clamp_color.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fi.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fv.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_color_maski.h"
#include "OpenGL/entrypoints/GL3.0/gl_delete_framebuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_delete_renderbuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_delete_vertex_arrays.h"
#include "OpenGL/entrypoints/GL3.0/gl_disablei.h"
#include "OpenGL/entrypoints/GL3.0/gl_enablei.h"
#include "OpenGL/entrypoints/GL3.0/gl_end_conditional_render.h"
#include "OpenGL/entrypoints/GL3.0/gl_end_transform_feedback.h"
#include "OpenGL/entrypoints/GL3.0/gl_flush_mapped_buffer_range.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_renderbuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_1d.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_2d.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_3d.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_layer.h"
#include "OpenGL/entrypoints/GL3.0/gl_generate_mipmap.h"
#include "OpenGL/entrypoints/GL3.0/gl_gen_framebuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_gen_renderbuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_gen_vertex_arrays.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_booleani_v.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_frag_data_location.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_framebuffer_attachment_parameteriv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_integeri_v.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_renderbuffer_parameteriv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_stringi.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_tex_parameter_i_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_tex_parameter_i_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_transform_feedback_varying.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_uniformuiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_vertex_attrib_i_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_vertex_attrib_i_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_enabledi.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_framebuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_renderbuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_vertex_array.h"
#include "OpenGL/entrypoints/GL3.0/gl_map_buffer_range.h"
#include "OpenGL/entrypoints/GL3.0/gl_renderbuffer_storage.h"
#include "OpenGL/entrypoints/GL3.0/gl_renderbuffer_storage_multisample.h"
#include "OpenGL/entrypoints/GL3.0/gl_tex_parameter_i_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_tex_parameter_i_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_transform_feedback_varyings.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_1ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_1uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_2ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_2uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_3ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_3uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_4ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_4uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4bv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4sv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4ubv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4usv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_pointer.h"

#include "OpenGL/entrypoints/GL3.1/gl_copy_buffer_sub_data.h"
#include "OpenGL/entrypoints/GL3.1/gl_draw_arrays_instanced.h"
#include "OpenGL/entrypoints/GL3.1/gl_draw_elements_instanced.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniformsiv.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_blockiv.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_block_name.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_name.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_block_index.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_indices.h"
#include "OpenGL/entrypoints/GL3.1/gl_primitive_restart_index.h"
#include "OpenGL/entrypoints/GL3.1/gl_tex_buffer.h"
#include "OpenGL/entrypoints/GL3.1/gl_uniform_block_binding.h"

#include "OpenGL/entrypoints/GL3.2/gl_client_wait_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_delete_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_draw_elements_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_draw_elements_instanced_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_draw_range_elements_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_fence_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_framebuffer_texture.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_buffer_parameteri64v.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_integer64i_v.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_integer64v.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_multisamplefv.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_synciv.h"
#include "OpenGL/entrypoints/GL3.2/gl_is_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_multi_draw_elements_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_provoking_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_sample_maski.h"
#include "OpenGL/entrypoints/GL3.2/gl_tex_image_2d_multisample.h"
#include "OpenGL/entrypoints/GL3.2/gl_tex_image_3d_multisample.h"
#include "OpenGL/entrypoints/GL3.2/gl_wait_sync.h"

#include "OpenGL/entrypoints/GL_ARB_color_buffer_float/gl_clamp_color_arb.h"

#include "OpenGL/entrypoints/GL_ARB_draw_buffers/gl_draw_buffers_arb.h"

#include "OpenGL/entrypoints/GL_ARB_draw_instanced/gl_draw_arrays_instanced_arb.h"
#include "OpenGL/entrypoints/GL_ARB_draw_instanced/gl_draw_elements_instanced_arb.h"

#include "OpenGL/entrypoints/GL_ARB_multisample/gl_sample_coverage_arb.h"

#include "OpenGL/entrypoints/GL_ARB_multitexture/gl_active_texture_arb.h"

#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_begin_query_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_delete_queries_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_end_query_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_gen_queries_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_get_queryiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_get_query_objectiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_get_query_objectuiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_is_query_arb.h"

#include "OpenGL/entrypoints/GL_ARB_point_parameters/gl_point_parameterf_arb.h"
#include "OpenGL/entrypoints/GL_ARB_point_parameters/gl_point_parameterfv_arb.h"

#include "OpenGL/entrypoints/GL_ARB_texture_buffer_object/gl_tex_buffer_arb.h"

#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_image_1d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_image_2d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_image_3d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_sub_image_1d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_sub_image_2d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_sub_image_3d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_get_compressed_tex_image_arb.h"

#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_bind_buffer_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_buffer_data_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_buffer_sub_data_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_delete_buffers_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_gen_buffers_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_get_buffer_parameteriv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_get_buffer_pointerv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_get_buffer_sub_data_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_is_buffer_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_map_buffer_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_unmap_buffer_arb.h"

#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_disable_vertex_attrib_array_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_enable_vertex_attrib_array_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attribdv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attribfv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attribiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attrib_pointerv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4bv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4iv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nbv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Niv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nsv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nubv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nub_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nuiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4ubv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4uiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4usv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_pointer_arb.h"

#include "OpenGL/entrypoints/GL_ARB_vertex_shader/gl_bind_attrib_location_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_shader/gl_get_active_attrib_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_shader/gl_get_attrib_location_arb.h"
*/
#include <algorithm>
#include <sstream>

#ifdef min
    #undef min
#endif

OpenGL::Context::Context(const VKGL::IWSIContext*     in_wsi_context_ptr,
                         const OpenGL::IBackend*		in_backend_ptr,
                         OpenGL::IBackendGLCallbacks* in_backend_gl_callbacks_ptr,
                         const IBackendCapabilities*  in_backend_caps_ptr)
    :m_backend_caps_ptr        (in_backend_caps_ptr),
     m_backend_gl_callbacks_ptr(in_backend_gl_callbacks_ptr),
     m_backend_ptr				(in_backend_ptr),
     m_wsi_context_ptr         (in_wsi_context_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    /* Stub */
}

OpenGL::Context::~Context()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    /* Before continuing, flush any outstanding commands & wait till they complete GPU-side */
    finish();

    /* Go on.. */
    m_gl_compatibility_manager_ptr.reset();
    
    m_gl_state_manager_ptr.reset();

    m_gl_buffer_manager_ptr.reset      ();
    m_gl_framebuffer_manager_ptr.reset ();
    m_gl_program_manager_ptr.reset     ();
    m_gl_renderbuffer_manager_ptr.reset();
    m_gl_shader_manager_ptr.reset      ();
    m_gl_texture_manager_ptr.reset     ();
    m_gl_vao_manager_ptr.reset         ();

    /* Stub */
}

void OpenGL::Context::attach_shader(const GLuint& in_program,
                                    const GLuint& in_shader)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_program_manager_ptr != nullptr);
    vkgl_assert(m_gl_shader_manager_ptr  != nullptr);

    auto shader_reference_ptr = m_gl_shader_manager_ptr->acquire_current_latest_snapshot_reference(in_shader);

    if (shader_reference_ptr == nullptr)
    {
        vkgl_assert(shader_reference_ptr != nullptr);

        goto end;
    }

    if (!m_gl_program_manager_ptr->attach_shader(in_program,
                                                 std::move(shader_reference_ptr) ))
    {
        vkgl_assert_fail();
    }

end:
    ;
}

void OpenGL::Context::begin_conditional_render(const GLuint&                        in_occlusion_query_id,
                                               const OpenGL::ConditionalRenderMode& in_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::begin_query(const OpenGL::QueryTarget& in_target,
                                  const uint32_t&            in_id)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->begin_query(in_target,
                                        in_id);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::begin_transform_feedback(const OpenGL::TransformFeedbackPrimitiveMode& in_primitive_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::bind_attrib_location(const GLuint& in_program,
                                           const GLuint& in_index,
                                           const GLchar* in_name)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->cache_attribute_location_binding(in_program,
                                                                    in_name,
                                                                    in_index) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::bind_buffer(const OpenGL::BufferTarget& in_target,
                                  const uint32_t&             in_buffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);
vkgl_printf("line = %d file = %s", __LINE__, __FILE__);
vkgl_printf("in_target = %d", in_target);
vkgl_printf("in_buffer = %d", in_buffer);
	m_gl_buffer_manager_ptr->mark_id_as_alive(in_buffer);
    vkgl_printf("line = %d file = %s", __LINE__, __FILE__);
    auto buffer_reference_ptr = m_gl_buffer_manager_ptr->acquire_current_latest_snapshot_reference(in_buffer);
    vkgl_printf("line = %d file = %s", __LINE__, __FILE__);
    if (buffer_reference_ptr == nullptr)
    {
        vkgl_assert(buffer_reference_ptr != nullptr);
    }
    else
    {
        if (in_target == OpenGL::BufferTarget::Element_Array_Buffer)
        {
            const auto bound_vao_reference_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();
            vkgl_assert(bound_vao_reference_ptr != nullptr);

            m_gl_vao_manager_ptr->set_element_array_buffer_binding(bound_vao_reference_ptr->get_payload().id,
                                                                   std::move(buffer_reference_ptr) );
        }
        else
        {
            m_gl_state_manager_ptr->set_bound_buffer_object(in_target,
                                                            std::move(buffer_reference_ptr) );
        }

        if (in_buffer != 0)
        {
            m_gl_buffer_manager_ptr->on_buffer_bound_to_buffer_target(in_buffer,
                                                                      in_target);
        }
    }
}

void OpenGL::Context::bind_buffer_base(const OpenGL::BufferTarget& in_target,
                                       const GLuint&               in_index,
                                       const GLuint&               in_buffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    bind_buffer_range(in_target,
                     in_index,
                     in_buffer,
                     0, /* in_offset */
                     m_gl_buffer_manager_ptr->get_buffer_size(in_buffer,
                                                                      nullptr /* in_opt_time_marker_ptr */) );
}

void OpenGL::Context::bind_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLuint&               in_index,
                                        const GLuint&               in_buffer,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_size)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    m_gl_buffer_manager_ptr->mark_id_as_alive(in_buffer);

    auto buffer_reference_ptr = m_gl_buffer_manager_ptr->acquire_current_latest_snapshot_reference(in_buffer);
    
    if (buffer_reference_ptr == nullptr)
    {
        vkgl_assert(buffer_reference_ptr != nullptr);
    }
    else
    {
        if (in_target == OpenGL::BufferTarget::Element_Array_Buffer)
        {
            const auto bound_vao_reference_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();
            vkgl_assert(bound_vao_reference_ptr != nullptr);

            m_gl_vao_manager_ptr->set_element_array_buffer_binding(bound_vao_reference_ptr->get_payload().id,
                                                                   std::move(buffer_reference_ptr) );
        }
        else
        {
            m_gl_state_manager_ptr->set_bound_buffer_object(in_target,
                                                            in_index,
                                                            std::move(buffer_reference_ptr),
                                                            in_offset,
                                                            in_size);
        }

        if (in_buffer != 0)
        {
            m_gl_buffer_manager_ptr->on_buffer_bound_to_buffer_target(in_buffer,
                                                                      in_target);
        }
    }
}

void OpenGL::Context::bind_frag_data_location(const GLuint& in_program,
                                              const GLuint& in_color,
                                              const GLchar* in_name)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->cache_frag_data_location(in_program,
                                                            in_name,
                                                            in_color) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::bind_framebuffer(const OpenGL::FramebufferTarget& in_target,
                                       const GLuint&                    in_framebuffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);

    m_gl_framebuffer_manager_ptr->mark_id_as_alive(in_framebuffer);

	auto fb_handle_ptr = m_gl_framebuffer_manager_ptr->acquire_current_latest_snapshot_reference(in_framebuffer);
	
    if (fb_handle_ptr == nullptr)
    {
        vkgl_assert(fb_handle_ptr != nullptr);
    }
    else
    {
        m_gl_state_manager_ptr->set_bound_framebuffer_object(in_target,
                                                             std::move(fb_handle_ptr) );
    	
    	{
    		if (in_framebuffer == 0)
    		{
            	set_draw_buffer(OpenGL::DrawBuffer::Back);
            }
            else
            {
            	set_draw_buffer(OpenGL::DrawBuffer::Color_Attachment0);
            }
    	}
	}
}

void OpenGL::Context::bind_renderbuffer(const OpenGL::RenderbufferTarget& in_target,
                                        const GLuint&                     in_renderbuffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr        != nullptr);

    m_gl_renderbuffer_manager_ptr->mark_id_as_alive(in_renderbuffer);

	auto rb_handle_ptr = m_gl_renderbuffer_manager_ptr->acquire_current_latest_snapshot_reference(in_renderbuffer);
	
    if (rb_handle_ptr == nullptr)
    {
        vkgl_assert(rb_handle_ptr != nullptr);
    }
    else
    {
        m_gl_state_manager_ptr->set_bound_renderbuffer_object(std::move(rb_handle_ptr) );
    }
}

void OpenGL::Context::bind_texture(const OpenGL::TextureTarget& in_target,
                                   const uint32_t&              in_texture)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

	m_gl_texture_manager_ptr->mark_id_as_alive(in_texture);

    m_gl_state_manager_ptr->set_texture_binding(m_gl_state_manager_ptr->get_state()->active_texture_unit,
                                                in_target,
                                                in_texture);

	if (in_texture != 0)
	{
        m_gl_texture_manager_ptr->on_texture_bound_to_target(in_texture,
                                                         in_target);
	}
}

void OpenGL::Context::bind_vertex_array(const GLuint& in_array)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    m_gl_vao_manager_ptr->mark_id_as_alive(in_array);

    auto vao_handle_ptr = m_gl_vao_manager_ptr->acquire_current_latest_snapshot_reference(in_array);

    if (vao_handle_ptr == nullptr)
    {
        vkgl_assert(vao_handle_ptr != nullptr);
    }
    else
    {
        m_gl_state_manager_ptr->set_bound_vertex_array_object(std::move(vao_handle_ptr) );
    }
}

void OpenGL::Context::blit_framebuffer(const GLint&                in_src_x0,
                                       const GLint&                in_src_y0,
                                       const GLint&                in_src_x1,
                                       const GLint&                in_src_y1,
                                       const GLint&                in_dst_x0,
                                       const GLint&                in_dst_y0,
                                       const GLint&                in_dst_x1,
                                       const GLint&                in_dst_y1,
                                       const OpenGL::BlitMaskBits& in_mask,
                                       const OpenGL::BlitFilter&   in_filter)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::buffer_data(const OpenGL::BufferTarget& in_target,
                                  const GLsizeiptr&           in_size,
                                  const void*                 in_data_ptr,
                                  const OpenGL::BufferUsage&  in_usage)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    GLuint buffer_id = 0;

    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_buffer_manager_ptr    != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    if (in_target == OpenGL::BufferTarget::Element_Array_Buffer)
    {
        const auto                 bound_vao_reference_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();
        GLBufferReferenceUniquePtr buffer_reference_ptr;

        m_gl_vao_manager_ptr->get_element_array_buffer_binding(bound_vao_reference_ptr->get_payload().id,
                                                               nullptr, /* in_opt_time_marker */
                                                              &buffer_reference_ptr);

        vkgl_assert(buffer_reference_ptr != nullptr);

        buffer_id = buffer_reference_ptr->get_payload().id;
    }
    else
    {
        buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;
    }

    vkgl_assert(buffer_id != 0);

    m_gl_buffer_manager_ptr->set_buffer_store_size(buffer_id,
                                                   in_size);
    m_gl_buffer_manager_ptr->set_buffer_usage     (buffer_id,
                                                   in_usage);

    m_backend_gl_callbacks_ptr->buffer_data(buffer_id,
                                            in_size,
                                            in_data_ptr);
}

void OpenGL::Context::buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                      const GLintptr&             in_offset,
                                      const GLsizeiptr&           in_size,
                                      const void*                 in_data_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_buffer_manager_ptr    != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;
    vkgl_assert(buffer_id != 0);

    m_backend_gl_callbacks_ptr->buffer_sub_data(buffer_id,
                                                in_offset,
                                                in_size,
                                                in_data_ptr);
}

OpenGL::FramebufferStatus OpenGL::Context::check_framebuffer_status(const OpenGL::FramebufferTarget& in_target) const
{
    vkgl_not_implemented();

    return OpenGL::FramebufferStatus::Complete;
}

void OpenGL::Context::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->clear(in_buffers_to_clear);
}

void OpenGL::Context::clear_buffer(const OpenGL::ClearBuffer&        in_buffer,
                                   const GLint&                      in_drawbuffer,
                                   const OpenGL::GetSetArgumentType& in_color_arg_type,
                                   const uint32_t&                   in_color_n_components,
                                   const void*                       in_color_data_ptr,
                                   const GLfloat&                    in_depth,
                                   const GLint&                      in_stencil)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

OpenGL::WaitResult OpenGL::Context::client_wait_sync(const GLsync&               in_sync,
                                                     const OpenGL::WaitSyncBits& in_flags,
                                                     const GLuint64&             in_timeout)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();

    return OpenGL::WaitResult::Unknown;
}

void OpenGL::Context::compile_shader(const GLuint& in_shader)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->compile_shader(in_shader);
}

void OpenGL::Context::compressed_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei                 in_width,
                                              const GLint                   in_border,
                                              const GLsizei                 in_image_size,
                                              const void*                   in_data)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->compressed_tex_image_1d(texture_id,
                                                        in_level,
                                                        in_internalformat,
                                                        in_width,
                                                        in_border,
                                                        in_image_size,
                                                        in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei&                in_width,
                                              const GLsizei&                in_height,
                                              const GLint&                  in_border,
                                              const GLsizei&                in_image_size,
                                              const void*                   in_data)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->compressed_tex_image_2d(texture_id,
                                                        in_level,
                                                        in_internalformat,
                                                        in_width,
                                                        in_height,
                                                        in_border,
                                                        in_image_size,
                                                        in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_image_3d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei&                in_width,
                                              const GLsizei&                in_height,
                                              const GLsizei&                in_depth,
                                              const GLint&                  in_border,
                                              const GLsizei&                in_image_size,
                                              const void*                   in_data)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->compressed_tex_image_3d(texture_id,
                                                        in_level,
                                                        in_internalformat,
                                                        in_width,
                                                        in_height,
                                                        in_depth,
                                                        in_border,
                                                        in_image_size,
                                                        in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLsizei&               in_width,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->compressed_tex_sub_image_1d(texture_id,
                                                            in_level,
                                                            in_xoffset,
                                                            in_width,
                                                            in_format,
                                                            in_image_size,
                                                            in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLint&                 in_yoffset,
                                                  const GLsizei&               in_width,
                                                  const GLsizei&               in_height,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->compressed_tex_sub_image_2d(texture_id,
                                                            in_level,
                                                            in_xoffset,
                                                            in_yoffset,
                                                            in_width,
                                                            in_height,
                                                            in_format,
                                                            in_image_size,
                                                            in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLint&                 in_yoffset,
                                                  const GLint&                 in_zoffset,
                                                  const GLsizei&               in_width,
                                                  const GLsizei&               in_height,
                                                  const GLsizei&               in_depth,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->compressed_tex_sub_image_3d(texture_id,
                                                            in_level,
                                                            in_xoffset,
                                                            in_yoffset,
                                                            in_zoffset,
                                                            in_width,
                                                            in_height,
                                                            in_depth,
                                                            in_format,
                                                            in_image_size,
                                                            in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_buffer_sub_data(const OpenGL::BufferTarget& in_read_target,
                                           const OpenGL::BufferTarget& in_write_target,
                                           const GLintptr&             in_read_offset,
                                           const GLintptr&             in_write_offset,
                                           const GLsizeiptr&           in_size)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto dst_buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_write_target)->get_payload().id;
    const auto src_buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_read_target)->get_payload().id;

    m_backend_gl_callbacks_ptr->copy_buffer_sub_data(src_buffer_id,
                                                     dst_buffer_id,
                                                     in_read_offset,
                                                     in_write_offset,
                                                     in_size);
}

void OpenGL::Context::copy_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                        const GLint                   in_level,
                                        const OpenGL::InternalFormat& in_internalformat,
                                        const GLint&                  in_x,
                                        const GLint&                  in_y,
                                        const GLsizei&                in_width,
                                        const GLint&                  in_border)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    vkgl_assert(!OpenGL::Utils::is_texture_target_multisample(in_target) );

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_gl_texture_manager_ptr->set_texture_mip_properties(texture_id,
                                                         in_level,
                                                         in_internalformat,
                                                         in_width,
                                                         1, /* in_height */
                                                         1, /* in_depth  */
                                                         in_border,
                                                         1,     /* in_n_samples              */
                                                         true); /* in_fixed_sample_locations */

    m_backend_gl_callbacks_ptr->copy_tex_image_1d(texture_id,
                                                  in_level,
                                                  in_internalformat,
                                                  in_x,
                                                  in_y,
                                                  in_width,
                                                  in_border);
}

void OpenGL::Context::copy_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                        const GLint&                  in_level,
                                        const OpenGL::InternalFormat& in_internalformat,
                                        const GLint&                  in_x,
                                        const GLint&                  in_y,
                                        const GLsizei&                in_width,
                                        const GLsizei&                in_height,
                                        const GLint&                  in_border)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    vkgl_assert(!OpenGL::Utils::is_texture_target_multisample(in_target) );

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_gl_texture_manager_ptr->set_texture_mip_properties(texture_id,
                                                         in_level,
                                                         in_internalformat,
                                                         in_width,
                                                         in_height,
                                                         1, /* in_depth  */
                                                         in_border,
                                                         1,     /* in_n_samples              */
                                                         true); /* in_fixed_sample_locations */

    m_backend_gl_callbacks_ptr->copy_tex_image_2d(texture_id,
                                                  in_level,
                                                  in_internalformat,
                                                  in_x,
                                                  in_y,
                                                  in_width,
                                                  in_height,
                                                  in_border);
}

void OpenGL::Context::copy_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->copy_tex_sub_image_1d(texture_id,
                                                      in_level,
                                                      in_xoffset,
                                                      in_x,
                                                      in_y,
                                                      in_width);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_yoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width,
                                            const GLsizei&               in_height)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->copy_tex_sub_image_2d(texture_id,
                                                      in_level,
                                                      in_xoffset,
                                                      in_yoffset,
                                                      in_x,
                                                      in_y,
                                                      in_width,
                                                      in_height);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_yoffset,
                                            const GLint&                 in_zoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width,
                                            const GLsizei&               in_height)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->copy_tex_sub_image_3d(texture_id,
                                                      in_level,
                                                      in_xoffset,
                                                      in_yoffset,
                                                      in_zoffset,
                                                      in_x,
                                                      in_y,
                                                      in_width,
                                                      in_height);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::ContextUniquePtr OpenGL::Context::create(const VKGL::IWSIContext*     in_wsi_context_ptr,
                                                 const OpenGL::IBackend*		in_backend_ptr,
                                                 OpenGL::IBackendGLCallbacks* in_backend_gl_callbacks_ptr,
                                                 const IBackendCapabilities*  in_backend_caps_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    OpenGL::ContextUniquePtr result_ptr;

    result_ptr.reset(
        new OpenGL::Context(in_wsi_context_ptr,
                            in_backend_ptr,
                            in_backend_gl_callbacks_ptr,
                            in_backend_caps_ptr)
    );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

GLuint OpenGL::Context::create_program()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    GLuint result_id = 0;

    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_program_manager_ptr   != nullptr);

    if (!m_gl_program_manager_ptr->generate_ids(1, /* in_n_ids */
                                               &result_id) )
    {
        vkgl_assert_fail();

        goto end;
    }

    m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Program,
                                                   1, /* in_n_ids */
                                                  &result_id);
end:
    return result_id;
}

GLuint OpenGL::Context::create_shader(const OpenGL::ShaderType& in_type)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    GLuint result_id = 0;

    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_shader_manager_ptr    != nullptr);

    if (!m_gl_shader_manager_ptr->generate_ids(1, /* in_n_ids */
                                              &result_id) )
    {
        vkgl_assert_fail();

        goto end;
    }

    if (!m_gl_shader_manager_ptr->set_shader_type(result_id,
                                                  in_type) )
    {
        vkgl_assert_fail();

        goto end;
    }

    m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Shader,
                                                   1, /* in_n_ids */
                                                  &result_id);
end:
    return result_id;
}

void OpenGL::Context::delete_buffers(const GLsizei&  in_n,
                                     const uint32_t* in_ids_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    bool result;

    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_buffer_manager_ptr    != nullptr);

    for(int n = 0;
        	n < in_n;
        	n++)
    {
        if (m_gl_buffer_manager_ptr->is_alive_id(in_ids_ptr[n]) )
        {
            result = m_gl_buffer_manager_ptr->delete_ids(1,
                                                         in_ids_ptr + n);
        
            if (!result)
            {
                vkgl_assert_fail();
            }
        
            m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Buffer,
                                                             1,
                                                             in_ids_ptr + n);
		}
	}
}

void OpenGL::Context::delete_framebuffers(const GLsizei&  in_n,
                                          const uint32_t* in_framebuffers_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    bool result;

    vkgl_assert(m_backend_gl_callbacks_ptr   != nullptr);
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);

    for(int n = 0;
        	n < in_n;
        	n++)
    {
        if (m_gl_framebuffer_manager_ptr->is_alive_id(in_framebuffers_ptr[n]) )
        {
            result = m_gl_framebuffer_manager_ptr->delete_ids(1,
                                                              in_framebuffers_ptr + n);
        
            if (!result)
            {
                vkgl_assert_fail();
            }
        
            m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Framebuffer,
                                                             1,
                                                             in_framebuffers_ptr + n);
		}
	}
}

void OpenGL::Context::delete_program(const GLuint& in_id)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_program_manager_ptr   != nullptr);

    if (m_gl_program_manager_ptr->is_alive_id(in_id) )
    {
        m_gl_program_manager_ptr->delete_ids(1, /* in_n_ids */
                                            &in_id);
    
        m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Program,
                                                         1,
                                                        &in_id);
	}
}

void OpenGL::Context::delete_queries(const GLsizei&  in_n,
                                     const uint32_t* in_ids_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if 0
    bool result;

    for(int n = 0;
        	n < in_n;
        	n++)
    {
        if (m_gl_query_manager_ptr->is_alive_id(in_ids_ptr[n]) )
        {
            vkgl_assert(m_gl_query_manager_ptr != nullptr);
        
            result = m_gl_query_manager_ptr->delete_ids(in_n,
                                                        in_ids_ptr);
        
            if (!result)
            {
                vkgl_assert_fail();
            }
		}
	}
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_renderbuffers(const GLsizei& in_n,
                                           const GLuint*  in_renderbuffers_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    bool result;

    vkgl_assert(m_backend_gl_callbacks_ptr    != nullptr);
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);

    for(int n = 0;
        	n < in_n;
        	n++)
    {
        if (m_gl_renderbuffer_manager_ptr->is_alive_id(in_renderbuffers_ptr[n]) )
        {
            result = m_gl_renderbuffer_manager_ptr->delete_ids(1,
                                                               in_renderbuffers_ptr + n);
        
            if (!result)
            {
                vkgl_assert_fail();
            }
        
            m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Renderbuffer,
                                                             1,
                                                             in_renderbuffers_ptr + n);
		}
	}
}

void OpenGL::Context::delete_shader(const GLuint& in_id)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_shader_manager_ptr    != nullptr);

    if (m_gl_shader_manager_ptr->is_alive_id(in_id) )
    {
        m_gl_shader_manager_ptr->delete_ids(1, /* in_n_ids */
                                           &in_id);
    
        m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Shader,
                                                         1, /* in_n_ids */
                                                        &in_id);
	}
}

void OpenGL::Context::delete_sync(const GLsync& in_sync)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::delete_textures(const GLsizei& in_n,
                                      const GLuint*  in_ids_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
	bool result;

    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr    != nullptr);

    for(int n = 0;
        	n < in_n;
        	n++)
    {
        if (m_gl_texture_manager_ptr->is_alive_id(in_ids_ptr[n]) )
        {
            result = m_gl_texture_manager_ptr->delete_ids(1,
                                                         in_ids_ptr);
        
            if (!result)
            {
                vkgl_assert_fail();
            }
        
            m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Texture,
                                                             1,
                                                             in_ids_ptr);
		}
	}
}

void OpenGL::Context::delete_vertex_arrays(const GLsizei& in_n,
                                           const GLuint*  in_arrays_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_vao_manager_ptr       != nullptr);

    for(int n = 0;
        	n < in_n;
        	n++)
    {
        if (m_gl_vao_manager_ptr->is_alive_id(in_arrays_ptr[n]) )
        {
            m_gl_vao_manager_ptr->delete_ids(1,
                                             in_arrays_ptr + n);
        
            m_backend_gl_callbacks_ptr->on_objects_destroyed(OpenGL::ObjectType::Vertex_Array_Object,
                                                             1,
                                                             in_arrays_ptr + n);
		}
	}
}

void OpenGL::Context::detach_shader(const GLuint& in_program,
                                    const GLuint& in_shader)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->detach_shader(in_program,
                                                 in_shader) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::disable(const OpenGL::Capability& in_capability)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->disable(in_capability);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::disable_indexed(const OpenGL::Capability& in_capability,
                                      const GLuint&             in_index)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::disable_vertex_attrib_array(const GLuint& in_index)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    set_vaa_enabled_state(in_index,
                          false); /* in_new_state */
}

void OpenGL::Context::draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                  const GLint&                in_first,
                                  const GLsizei&              in_count)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->draw_arrays(in_mode,
                                            in_first,
                                            in_count);
}

void OpenGL::Context::draw_arrays_instanced(const OpenGL::DrawCallMode& in_mode,
                                            const GLint&                in_first,
                                            const GLsizei&              in_count,
                                            const GLsizei&              in_instancecount)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                    const GLsizei&                   in_count,
                                    const OpenGL::DrawCallIndexType& in_type,
                                    const void*                      in_indices)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->draw_elements(in_mode,
                                              in_count,
                                              in_type,
                                              in_indices);
}

void OpenGL::Context::draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                const GLsizei&                   in_count,
                                                const OpenGL::DrawCallIndexType& in_type,
                                                const void*                      in_indices,
                                                const GLint&                     in_basevertex)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements_instanced(const OpenGL::DrawCallMode&      in_mode,
                                              const GLsizei&                   in_count,
                                              const OpenGL::DrawCallIndexType& in_type,
                                              const void*                      in_indices_ptr,
                                              const GLsizei&                   in_instancecount)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements_instanced_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                          const GLsizei&                   in_count,
                                                          const OpenGL::DrawCallIndexType& in_type,
                                                          const void*                      in_indices_ptr,
                                                          const GLsizei&                   in_instancecount,
                                                          const GLint&                     in_basevertex)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                          const GLuint&                    in_start,
                                          const GLuint&                    in_end,
                                          const GLsizei&                   in_count,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void*                      in_indices)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->draw_range_elements(in_mode,
                                                    in_start,
                                                    in_end,
                                                    in_count,
                                                    in_type,
                                                    in_indices);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_range_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                      const GLuint&                    in_start,
                                                      const GLuint&                    in_end,
                                                      const GLsizei&                   in_count,
                                                      const OpenGL::DrawCallIndexType& in_type,
                                                      const void*                      in_indices,
                                                      const GLint&                     in_basevertex)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::enable(const OpenGL::Capability& in_capability)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->enable(in_capability);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::enable_indexed(const OpenGL::Capability& in_capability,
                                     const GLuint&             in_index)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::enable_vertex_attrib_array(const GLuint& in_index)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    set_vaa_enabled_state(in_index,
                          true); /* in_new_state */
}

void OpenGL::Context::end_conditional_render()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::end_transform_feedback()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::end_query(const OpenGL::QueryTarget& in_target)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    const auto query_id = m_gl_state_manager_ptr->get_query_binding(in_target);
    vkgl_assert(query_id != 0);

    m_gl_query_manager_ptr->end_query(query_id);
#else
    vkgl_not_implemented();
#endif
}

GLsync OpenGL::Context::fence_sync(const OpenGL::SyncCondition& in_condition)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::Context::finish()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->finish();
}

void OpenGL::Context::flush()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->flush(nullptr); /* in_opt_fence_ptr */
}

void OpenGL::Context::flush_mapped_buffer_range(const OpenGL::BufferTarget& in_target,
                                                const GLintptr&             in_offset,
                                                const GLsizeiptr&           in_length)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto dst_buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;

    m_backend_gl_callbacks_ptr->flush_mapped_buffer_range(dst_buffer_id,
                                                          in_offset,
                                                          in_length);
}

void OpenGL::Context::framebuffer_renderbuffer(const OpenGL::FramebufferTarget&          in_target,
                                               const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                               const OpenGL::RenderbufferTarget&         in_renderbuffertarget,
                                               const GLuint&                             in_renderbuffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr  != nullptr);
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr        != nullptr);
    vkgl_assert(in_renderbuffertarget         == OpenGL::RenderbufferTarget::Renderbuffer);

    const auto bound_fb_id            = m_gl_state_manager_ptr->get_bound_framebuffer_object                    (in_target)->get_payload().id;
    auto       bound_rb_reference_ptr = m_gl_renderbuffer_manager_ptr->acquire_current_latest_snapshot_reference(in_renderbuffer);

    m_gl_framebuffer_manager_ptr->set_attachment_renderbuffer(bound_fb_id,
                                                              in_attachment,
                                                              std::move(bound_rb_reference_ptr) );
}

void OpenGL::Context::framebuffer_texture(const OpenGL::FramebufferTarget&          in_target,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          const GLuint&                             in_texture,
                                          const GLint&                              in_level)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr     != nullptr);

    const auto bound_fb_id                 = m_gl_state_manager_ptr->get_bound_framebuffer_object (in_target)->get_payload().id;
    auto       bound_texture_reference_ptr = m_gl_texture_manager_ptr->acquire_current_latest_snapshot_reference(in_texture);

    m_gl_framebuffer_manager_ptr->set_attachment_texture(bound_fb_id,
                                                         in_attachment,
                                                         std::move(bound_texture_reference_ptr),
                                                         in_level);
}

void OpenGL::Context::framebuffer_texture_1D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr     != nullptr);
    vkgl_assert(in_textarget                 == OpenGL::TextureTarget::_1D);

    const auto bound_fb_id                 = m_gl_state_manager_ptr->get_bound_framebuffer_object               (in_target)->get_payload().id;
    auto       bound_texture_reference_ptr = m_gl_texture_manager_ptr->acquire_current_latest_snapshot_reference(in_texture);

    m_gl_framebuffer_manager_ptr->set_attachment_texture_1D(bound_fb_id,
                                                            in_attachment,
                                                            std::move(bound_texture_reference_ptr),
                                                            in_level);
}

void OpenGL::Context::framebuffer_texture_2D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr     != nullptr);

    const auto bound_fb_id                 = m_gl_state_manager_ptr->get_bound_framebuffer_object               (in_target)->get_payload().id;
    auto       bound_texture_reference_ptr = m_gl_texture_manager_ptr->acquire_current_latest_snapshot_reference(in_texture);

    m_gl_framebuffer_manager_ptr->set_attachment_texture_2D(bound_fb_id,
                                                            in_attachment,
                                                            in_textarget,
                                                            std::move(bound_texture_reference_ptr),
                                                            in_level);
}

void OpenGL::Context::framebuffer_texture_3D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level,
                                             const GLint&                              in_zoffset)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr     != nullptr);

    const auto bound_fb_id                 = m_gl_state_manager_ptr->get_bound_framebuffer_object               (in_target)->get_payload().id;
    auto       bound_texture_reference_ptr = m_gl_texture_manager_ptr->acquire_current_latest_snapshot_reference(in_texture);

    m_gl_framebuffer_manager_ptr->set_attachment_texture_3D(bound_fb_id,
                                                            in_attachment,
                                                            in_textarget,
                                                            std::move(bound_texture_reference_ptr),
                                                            in_level,
                                                            in_zoffset);
}

void OpenGL::Context::framebuffer_texture_layer(const OpenGL::FramebufferTarget&          in_target,
                                                const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                const GLuint&                             in_texture,
                                                const GLint&                              in_level,
                                                const GLint&                              in_layer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr     != nullptr);

    const auto bound_fb_id                 = m_gl_state_manager_ptr->get_bound_framebuffer_object               (in_target)->get_payload().id;
    auto       bound_texture_reference_ptr = m_gl_texture_manager_ptr->acquire_current_latest_snapshot_reference(in_texture);

    m_gl_framebuffer_manager_ptr->set_attachment_texture_layer(bound_fb_id,
                                                               in_attachment,
                                                               std::move(bound_texture_reference_ptr),
                                                               in_level,
                                                               in_layer);
}

void OpenGL::Context::generate_mipmap(const OpenGL::MipmapGenerationTextureTarget& in_target)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    
    const auto gl_target = OpenGL::Utils::get_gl_enum_for_mipmap_generation_texture_target(in_target);
    const auto tex_target = OpenGL::Utils::get_texture_target_for_gl_enum(gl_target);
    
    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  tex_target);
    
    m_backend_gl_callbacks_ptr->generate_mipmap(texture_id);
}

void OpenGL::Context::gen_buffers(const uint32_t& in_n,
                                  uint32_t*       out_ids_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    if (!m_gl_buffer_manager_ptr->generate_ids(in_n,
                                               out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
    else
    {
        m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Buffer,
                                                       in_n,
                                                       out_ids_ptr);
    }
}

void OpenGL::Context::gen_framebuffers(const GLsizei& in_n,
                                       GLuint*        out_framebuffers_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);

    if (!m_gl_framebuffer_manager_ptr->generate_ids(in_n,
                                                    out_framebuffers_ptr) )
    {
        vkgl_assert_fail();
    }
    else
    {
        m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Framebuffer,
                                                       in_n,
                                                       out_framebuffers_ptr);
    }
}

void OpenGL::Context::gen_queries(const uint32_t& in_n,
                                  uint32_t*       out_ids_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    if (!m_gl_query_manager_ptr->generate_ids(in_n,
                                              out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_renderbuffers(const GLsizei& in_n,
                                        GLuint*        out_renderbuffers_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);

    if (!m_gl_renderbuffer_manager_ptr->generate_ids(in_n,
                                                     out_renderbuffers_ptr) )
    {
        vkgl_assert_fail();
    }
    else
    {
        m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Renderbuffer,
                                                       in_n,
                                                       out_renderbuffers_ptr);
    }
}

void OpenGL::Context::gen_textures(const GLsizei& in_n,
                                   GLuint*        out_ids_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    if (!m_gl_texture_manager_ptr->generate_ids(in_n,
                                               out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
    else
    {
        m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Texture,
                                                       in_n,
                                                       out_ids_ptr);
    }
}

void OpenGL::Context::gen_vertex_arrays(const GLsizei& in_n,
                                        GLuint*        out_arrays_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_vao_manager_ptr != nullptr);

    if (!m_gl_vao_manager_ptr->generate_ids(in_n,
                                            out_arrays_ptr) )
    {
        vkgl_assert_fail();
    }
    else
    {
        m_backend_gl_callbacks_ptr->on_objects_created(OpenGL::ObjectType::Vertex_Array_Object,
                                                       in_n,
                                                       out_arrays_ptr);
    }
}

void OpenGL::Context::get_active_attrib(const GLuint&         in_program,
                                        const GLuint&         in_index,
                                        const GLsizei&        in_buf_size,
                                        GLsizei*              out_length_ptr,
                                        GLint*                out_size_ptr,
                                        OpenGL::VariableType* out_type_ptr,
                                        GLchar*               out_name_ptr) const
{
    uint32_t     attribute_name_length   = 0;
    const char*  attribute_name_ptr      = nullptr;
    GLuint       attribute_size          = 0;
    VariableType attribute_variable_type = VariableType::Unknown;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_attribute(in_program,
                                                        nullptr, /* in_opt_time_marker_ptr */
                                                        in_index,
                                                       &attribute_name_ptr,
                                                       &attribute_size,
                                                       &attribute_variable_type) )
    {
        vkgl_assert_fail();

        goto end;
    }

    vkgl_assert(attribute_name_ptr != nullptr);

    attribute_name_length = strlen(attribute_name_ptr);

    if (out_length_ptr != nullptr)
    {
        *out_length_ptr = attribute_name_length;
    }

    *out_size_ptr = attribute_size;
    *out_type_ptr = attribute_variable_type;

    if (out_name_ptr != nullptr)
    {
        memcpy(out_name_ptr,
               attribute_name_ptr,
               std::min(static_cast<uint32_t>(in_buf_size), attribute_name_length + 1) );
    }

end:
    ;
}

void OpenGL::Context::get_active_uniform(const GLuint&         in_program,
                                         const GLuint&         in_index,
                                         const GLsizei&        in_buf_size,
                                         GLsizei*              out_length_ptr,
                                         GLint*                out_size_ptr,
                                         OpenGL::VariableType* out_type_ptr,
                                         GLchar*               out_name_ptr) const
{
    uint32_t     uniform_name_length   = 0;
    const char*  uniform_name_ptr      = nullptr;
    GLuint       uniform_size          = 0;
    VariableType uniform_variable_type = VariableType::Unknown;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_uniform(in_program,
                                                       nullptr, /* in_opt_time_marker_ptr */
                                                      in_index,
                                                      OpenGL::GLProgramManager::DEFAULT_UNIFORM_BLOCK_INDEX,
                                                     &uniform_name_ptr,
                                                     &uniform_size,
                                                     &uniform_variable_type) )
    {
        vkgl_assert_fail();

        goto end;
    }

    vkgl_assert(uniform_name_ptr != nullptr);

    uniform_name_length = strlen(uniform_name_ptr);

    if (out_length_ptr != nullptr)
    {
        *out_length_ptr = uniform_name_length;
    }

    *out_size_ptr = uniform_size;
    *out_type_ptr = uniform_variable_type;

    if (out_name_ptr != nullptr)
    {
        memcpy(out_name_ptr,
               uniform_name_ptr,
               std::min(static_cast<uint32_t>(in_buf_size), uniform_name_length + 1) );
    }

end:
    ;
}

void OpenGL::Context::get_active_uniform_block_name(const GLuint&  in_program,
                                                    const GLuint&  in_uniform_block_index,
                                                    const GLsizei& in_buf_size,
                                                    GLsizei*       out_length_ptr,
                                                    GLchar*        out_uniform_block_name_ptr) const
{
    uint32_t     uniform_block_name_length   = 0;
    const char*  uniform_block_name_ptr      = nullptr;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_uniform_block_name(in_program,
                                                                 nullptr, /* in_opt_time_marker_ptr */
                                                                 in_uniform_block_index,
                                                                &uniform_block_name_ptr) )
    {
        vkgl_assert_fail();

        goto end;
    }

    vkgl_assert(uniform_block_name_ptr != nullptr);

    uniform_block_name_length = strlen(uniform_block_name_ptr);

    if (out_length_ptr != nullptr)
    {
        *out_length_ptr = uniform_block_name_length;
    }

    if (out_uniform_block_name_ptr != nullptr)
    {
        memcpy(out_uniform_block_name_ptr,
               uniform_block_name_ptr,
               std::min(static_cast<uint32_t>(in_buf_size), uniform_block_name_length + 1) );
    }

end:
    ;
}

void OpenGL::Context::get_active_uniform_block_property(const GLuint&                       in_program,
                                                        const GLuint&                       in_uniform_block_index,
                                                        const OpenGL::UniformBlockProperty& in_pname,
                                                        const OpenGL::GetSetArgumentType&   in_params_type,
                                                        void*                               out_params_ptr) const
{
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_uniform_block_property(in_program,
                                                                     nullptr, /* in_opt_time_marker_ptr */
                                                                     in_uniform_block_index,
                                                                     in_pname,
                                                                     in_params_type,
                                                                     out_params_ptr) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::get_active_uniform_name(const GLuint&  in_program,
                                              const GLuint&  in_uniform_index,
                                              const GLsizei& in_buf_size,
                                              GLsizei*       out_length_ptr,
                                              GLchar*        out_uniform_name_ptr) const
{
    uint32_t     uniform_block_index   = UINT32_MAX;
    uint32_t     uniform_index         = UINT32_MAX;
    uint32_t     uniform_name_length   = 0;
    const char*  uniform_name_ptr      = nullptr;
    GLuint       uniform_size          = 0;
    VariableType uniform_variable_type = VariableType::Unknown;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    /* 1. Convert the input "flattened" index to a <uniform block index , uniform index> pair. */
    if (!m_gl_program_manager_ptr->map_global_uniform_index_to_uniform_and_ub_indices(in_program,
                                                                                      nullptr, /* in_opt_time_marker_ptr */
                                                                                      in_uniform_index,
                                                                                     &uniform_block_index,
                                                                                     &uniform_index) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* 2. Retrieve the name. */
    if (!m_gl_program_manager_ptr->get_active_uniform(in_program,
                                                      nullptr, /* in_opt_time_marker_ptr */
                                                      uniform_index,
                                                      uniform_block_index,
                                                     &uniform_name_ptr,
                                                      nullptr,   /* out_opt_size_ptr     */
                                                      nullptr) ) /* out_opt_variable_ptr */
    {
        vkgl_assert_fail();

        goto end;
    }

    vkgl_assert(uniform_name_ptr != nullptr);

    uniform_name_length = strlen(uniform_name_ptr);

    if (out_length_ptr != nullptr)
    {
        *out_length_ptr = uniform_name_length;
    }

    if (out_uniform_name_ptr != nullptr)
    {
        memcpy(out_uniform_name_ptr,
               uniform_name_ptr,
               std::min(static_cast<uint32_t>(in_buf_size), uniform_name_length + 1) );
    }

end:
    ;
}

void OpenGL::Context::get_active_uniforms(const GLuint&                  in_program,
                                          const GLsizei&                 in_uniform_count,
                                          const GLuint*                  in_uniform_indices_ptr,
                                          const OpenGL::UniformProperty& in_pname,
                                          GLint*                         out_params_ptr) const
{
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_uniforms_property(in_program,
                                                                nullptr, /* in_opt_time_marker_ptr */
                                                                in_uniform_count,
                                                                in_uniform_indices_ptr,
                                                                in_pname,
                                                                out_params_ptr) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::get_attached_shaders(const GLuint&  in_program,
                                           const GLsizei& in_max_count,
                                           GLsizei*       out_count_ptr,
                                           GLuint*        out_shaders_ptr) const
{
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    const auto attached_shader_refs_ptr = m_gl_program_manager_ptr->get_attached_shaders(in_program,
                                                                                         nullptr /* in_opt_time_marker_ptr */);
    uint32_t   n_attached_shader_refs   = 0;
    uint32_t   n_shader_ids_to_store    = 0;

    if (attached_shader_refs_ptr == nullptr)
    {
        vkgl_assert(attached_shader_refs_ptr != nullptr);

        goto end;
    }

    n_attached_shader_refs = static_cast<uint32_t>(attached_shader_refs_ptr->size() );

    if (out_count_ptr != nullptr)
    {
        *out_count_ptr = n_attached_shader_refs;
    }

    n_shader_ids_to_store = std::min(static_cast<uint32_t>(in_max_count), n_attached_shader_refs);

    for (uint32_t n_shader_id = 0;
                  n_shader_id < n_shader_ids_to_store;
                ++n_shader_id)
    {
        out_shaders_ptr[n_shader_id] = (*attached_shader_refs_ptr)[n_shader_id]->get_payload().id;
    }

end:
    ;
}

GLint OpenGL::Context::get_attrib_location(const GLuint& in_program,
                                           const GLchar* in_name) const
{
    GLint result = -1;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_attribute_location(in_program,
                                                                 nullptr, /* in_opt_time_marker_ptr */
                                                                 in_name,
                                                                &result) )
    {
        goto end;
    }

end:
    return result;
}

void OpenGL::Context::get_buffer_pointerv(const OpenGL::BufferTarget&          in_target,
                                          const OpenGL::BufferPointerProperty& in_pname,
                                          void**                               out_params_ptr) const
{
    vkgl_assert(in_pname                == OpenGL::BufferPointerProperty::Buffer_Map_Pointer);
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;

    *out_params_ptr = m_gl_buffer_manager_ptr->get_buffer_map_pointer(buffer_id,
                                                                      nullptr /* in_opt_time_marker_ptr */);
}

void OpenGL::Context::get_buffer_property(const OpenGL::BufferTarget&       in_target,
                                          const OpenGL::BufferProperty&     in_pname,
                                          const OpenGL::GetSetArgumentType& in_arg_type,
                                          const uint32_t&                   in_n_args,
                                          void*                             out_result_ptr) const
{
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;

    m_gl_buffer_manager_ptr->get_buffer_property(buffer_id,
                                                 nullptr, /* in_opt_time_marker_ptr */
                                                 in_pname,
                                                 in_arg_type,
                                                 in_n_args,
                                                 out_result_ptr);
}

void OpenGL::Context::get_buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                          const GLintptr&             in_offset,
                                          const GLsizeiptr&           in_size,
                                          void*                       out_data_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;
    vkgl_assert(buffer_id != 0);

    m_backend_gl_callbacks_ptr->get_buffer_sub_data(buffer_id,
                                                    in_offset,
                                                    in_size,
                                                    out_data_ptr);
}

void OpenGL::Context::get_compressed_tex_image(const OpenGL::TextureTarget& in_target,
                                               const GLint&                 in_level,
                                               void*                        in_img)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    m_backend_gl_callbacks_ptr->get_compressed_tex_image(texture_id,
                                                         in_level,
                                                         in_img);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::ErrorCode OpenGL::Context::get_error()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->get_error();
}

GLint OpenGL::Context::get_frag_data_location(const GLuint& in_program,
                                              const GLchar* in_name_ptr) const
{
    GLint result = -1;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_frag_data_location(in_program,
                                                          nullptr, /* in_opt_time_marker_ptr */
                                                          in_name_ptr,
                                                         &result) )
    {
        vkgl_assert_fail();

        goto end;
    }

end:
    return result;
}

void OpenGL::Context::get_framebuffer_attachment_property(const OpenGL::FramebufferTarget&             in_target,
                                                          const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                                          const OpenGL::FramebufferAttachmentProperty& in_pname,
                                                          const OpenGL::GetSetArgumentType&            in_params_type,
                                                          void*                                        out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_parameter(const OpenGL::ContextProperty&    in_pname,
                                    const OpenGL::GetSetArgumentType& in_arg_type,
                                    void*                             out_arg_value_ptr) const
{
    if (OpenGL::Utils::is_context_property_gl_constant(in_pname) )
    {
        vkgl_assert(m_gl_constants_ptr != nullptr);

        m_gl_constants_ptr->get_parameter(in_pname,
                                          in_arg_type,
                                          out_arg_value_ptr);
    }
    else
    if (OpenGL::Utils::is_context_property_gl_limit(in_pname) )
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        m_gl_limits_ptr->get_parameter(in_pname,
                                       in_arg_type,
                                       out_arg_value_ptr);
    }
    else
#if 0
    if (OpenGL::Utils::is_framebuffer_pname(in_pname) ) // todo: gl_doublebuffer, _drawbuffer, _drawbufferN, _readbuffer, samples, sample_buffers, stereo
    {
        vkgl_not_implemented();

    }
    else
#endif
    if (in_pname == OpenGL::ContextProperty::Renderbuffer_Binding) // todo
    {
        vkgl_not_implemented();
    }
    else
    if (in_pname == OpenGL::ContextProperty::Max_Viewport_Dims) // todo
    {
        /* Can change in time, so this is neither a GL constant, nor a GL limit in a typical sense. */
        vkgl_not_implemented();
    }
    else
#if 0
    if (OpenGL::Utils::is_buffer_binding_pname(in_pname) ) // todo: buffer bindings
    {
        vkgl_not_implemented();
    }
    else
#endif
    if (OpenGL::Utils::is_texture_binding_pname(in_pname) ) // todo
    {
        vkgl_not_implemented();
    }
    else
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::get_parameter_indexed(const OpenGL::ContextProperty&    in_pname,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            const GLuint&                     in_index,
                                            void*                             out_data_ptr) const
{
    if (OpenGL::Utils::is_context_property_gl_constant(in_pname) )
    {
        vkgl_assert(m_gl_constants_ptr != nullptr);

        m_gl_constants_ptr->get_parameter_indexed(in_pname,
                                                  in_arg_type,
                                                  in_index,
                                                  out_data_ptr);
    }
    else
    {
        /* TODO: See get_parameter() for the remaining bits. */
        vkgl_not_implemented();
    }
}

void OpenGL::Context::get_program_info_log(const GLuint&  in_program,
                                           const GLsizei& in_buf_size,
                                           GLsizei*       out_length_ptr,
                                           GLchar*        out_info_log_ptr) const
{
    uint32_t    info_log_length = 0;
    const char* info_log_ptr    = nullptr;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_program_info_log(in_program,
                                                        nullptr, /* in_opt_time_marker_ptr */
                                                       &info_log_ptr) )
    {
        vkgl_assert_fail();

        goto end;
    }

    info_log_length = strlen(info_log_ptr) + 1; /* null terminator */

    if (out_length_ptr != nullptr)
    {
        *out_length_ptr = info_log_length;
    }

    if (out_info_log_ptr != nullptr)
    {
        memcpy(out_info_log_ptr,
               info_log_ptr,
               std::min(info_log_length, static_cast<uint32_t>(in_buf_size) ));
    }

end:
    ;
}

void OpenGL::Context::get_program_property(const GLuint&                     in_program,
                                           const OpenGL::ProgramProperty&    in_pname,
                                           const OpenGL::GetSetArgumentType& in_params_type,
                                           const uint32_t&                   in_n_params_components,
                                           void*                             out_params_ptr) const
{
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_program_property(in_program,
                                                        nullptr, /* in_opt_time_marker_ptr */
                                                        in_pname,
                                                        in_params_type,
                                                        in_n_params_components,
                                                        out_params_ptr) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::get_query_property(const uint32_t&                   in_id,
                                         const OpenGL::QueryProperty&      in_pname,
                                         const OpenGL::GetSetArgumentType& in_arg_type,
                                         const uint32_t&                   in_n_args,
                                         void*                             out_result_ptr) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->get_query_property(in_id,
                                               in_pname,
                                               in_arg_type,
                                               in_n_args,
                                               out_result_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_query_target_property(const OpenGL::QueryTarget&         in_target,
                                                const OpenGL::QueryTargetProperty& in_pname,
                                                int32_t*                           out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->get_query_target_property(in_target,
                                                      in_pname,
                                                      out_params_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_renderbuffer_property(const OpenGL::RenderbufferTarget&   in_target,
                                                const OpenGL::RenderbufferProperty& in_pname,
                                                const OpenGL::GetSetArgumentType&   in_params_type,
                                                void*                               out_params_ptr) const
{
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr        != nullptr);

    const auto renderbuffer_id = m_gl_state_manager_ptr->get_bound_renderbuffer_object()->get_payload().id;

    m_gl_renderbuffer_manager_ptr->get_renderbuffer_property(renderbuffer_id,
                                                             nullptr, /* in_opt_time_marker_ptr */
                                                             in_pname,
                                                             in_params_type,
                                                             1, /* in_n_args */
                                                             out_params_ptr);
}

void OpenGL::Context::get_sample_position(const GLuint& in_index,
                                          GLfloat*      out_val_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_info_log(const GLuint&  in_shader,
                                          const GLsizei& in_buf_size,
                                          GLsizei*       inout_length_ptr,
                                          GLchar*        out_info_log_ptr) const
{
    const char* infolog_ptr      = nullptr;
    uint32_t    infolog_length   = 0;
    uint32_t    n_bytes_to_write = 0;

    if (!m_gl_shader_manager_ptr->get_shader_infolog(in_shader,
                                                     nullptr, /* in_opt_time_marker_ptr */
                                                    &infolog_ptr) )
    {
        vkgl_assert_fail();

        goto end;
    }

    infolog_length   = strlen(infolog_ptr) + 1;
    n_bytes_to_write = std::min(infolog_length, static_cast<uint32_t>(in_buf_size) );

    if (inout_length_ptr != nullptr)
    {
        *inout_length_ptr = n_bytes_to_write;
    }

    if (out_info_log_ptr != nullptr &&
        in_buf_size      != 0)
    {
        memcpy(out_info_log_ptr,
               infolog_ptr,
               n_bytes_to_write);
    }

end:
    ;
}

void OpenGL::Context::get_shader_property(const GLuint&                     in_shader,
                                          const OpenGL::ShaderProperty&     in_pname,
                                          const OpenGL::GetSetArgumentType& in_params_type,
                                          const uint32_t&                   in_n_params_components,
                                          GLint*                            out_params_ptr) const
{
    vkgl_assert(m_gl_shader_manager_ptr != nullptr);

    if (!m_gl_shader_manager_ptr->get_shader_property(in_shader,
                                                      nullptr, /* in_opt_time_marker_ptr */
                                                      in_pname,
                                                      in_params_type,
                                                      in_n_params_components,
                                                      out_params_ptr) )
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::get_shader_source(const GLuint&  in_shader,
                                        const GLsizei& in_buf_size,
                                        GLsizei*       inout_length_ptr,
                                        GLchar*        out_source_ptr) const
{
    const char* glsl_ptr         = nullptr;
    uint32_t    glsl_length      = 0;
    uint32_t    n_bytes_to_write = 0;

    if (!m_gl_shader_manager_ptr->get_shader_glsl(in_shader,
                                                  nullptr, /* in_opt_time_marker_ptr */
                                                 &glsl_ptr) )
    {
        vkgl_assert_fail();

        goto end;
    }

    glsl_length      = strlen(glsl_ptr);
    n_bytes_to_write = std::min(glsl_length, static_cast<uint32_t>(in_buf_size) );

    if (inout_length_ptr != nullptr)
    {
        *inout_length_ptr = n_bytes_to_write;
    }

    if (out_source_ptr != nullptr)
    {
        memcpy(out_source_ptr,
               glsl_ptr,
               n_bytes_to_write);
    }
end:
    ;
}

void OpenGL::Context::get_sync_property(const GLsync&                     in_sync,
                                        const GLenum&                     in_pname,
                                        const OpenGL::GetSetArgumentType& in_values_type,
                                        const GLsizei&                    in_buf_size,
                                        GLsizei*                          inout_length_ptr,
                                        void*                             out_values_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_texture_image(const OpenGL::TextureTarget& in_target,
                                        const uint32_t&              in_level,
                                        const OpenGL::PixelFormat&   in_format,
                                        const OpenGL::PixelType&     in_type,
                                        void*                        out_pixels_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    m_backend_gl_callbacks_ptr->get_texture_image(texture_id,
                                                  in_level,
                                                  in_format,
                                                  in_type,
                                                  out_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_texture_level_parameter(const OpenGL::TextureTarget&        in_target,
                                                  const int32_t&                      in_level,
                                                  const OpenGL::TextureLevelProperty& in_pname,
                                                  const OpenGL::GetSetArgumentType&   in_arg_type,
                                                  void*                               out_params_ptr) const
{
#if true
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

	if (in_target == OpenGL::TextureTarget::Proxy_Texture_2D 		||
		in_target == OpenGL::TextureTarget::Proxy_Texture_1D_Array ||
		in_target == OpenGL::TextureTarget::Proxy_Texture_Rectangle ||
		in_target == OpenGL::TextureTarget::Proxy_Texture_Cube_Map)
	{
        m_gl_texture_manager_ptr->get_texture_level_parameter(0,
            													  in_level,
                                                                  in_pname,
                                                                  in_arg_type,
                                                                  out_params_ptr);
	}
	else
	{
        const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
        const auto  active_texture_unit = context_state_ptr->active_texture_unit;
        const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                      in_target);
    
        if (texture_id != 0)
        {
            m_gl_texture_manager_ptr->get_texture_level_parameter(texture_id,
            													  in_level,
                                                                  in_pname,
                                                                  in_arg_type,
                                                                  out_params_ptr);
        }
        else
        {
            vkgl_assert_fail();
        }
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_texture_parameter(const OpenGL::TextureTarget&      in_target,
                                            const OpenGL::TextureProperty&    in_property,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            void*                             out_arg_value_ptr) const
{
#if true
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->get_texture_parameter(texture_id,
        												in_property,
                                                        in_arg_type,
                                                        out_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_transform_feedback_varying(const GLuint&         in_program,
                                                     const GLuint&         in_index,
                                                     const GLsizei&        in_buf_size,
                                                     GLsizei*              out_length_ptr,
                                                     GLsizei*              out_size_ptr,
                                                     OpenGL::VariableType* out_type_ptr,
                                                     GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

GLuint OpenGL::Context::get_uniform_block_index(const GLuint& in_program,
                                                const GLchar* in_uniform_block_name) const
{
    GLuint result = GL_INVALID_INDEX;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_uniform_block_index(in_program,
                                                            nullptr, /* in_opt_time_marker_ptr */
                                                           in_uniform_block_name,
                                                          &result) )
    {
        result = GL_INVALID_INDEX;
    }

    return result;
}

void OpenGL::Context::get_uniform_indices(const GLuint&        in_program,
                                          const GLsizei&       in_uniform_count,
                                          const GLchar* const* in_uniform_names_ptr_ptr,
                                          GLuint*              out_uniform_indices_ptr) const
{
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_uniform_indices(in_program,
                                                              nullptr, /* in_opt_time_marker_ptr */
                                                              in_uniform_count,
                                                              in_uniform_names_ptr_ptr,
                                                              out_uniform_indices_ptr) )
    {
        vkgl_assert_fail();
    }
}

GLint OpenGL::Context::get_uniform_location(const GLuint& in_program,
                                            const GLchar* in_name) const
{
    GLint result = GL_INVALID_INDEX;

    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    if (!m_gl_program_manager_ptr->get_active_uniform_by_name(in_program,
                                                              nullptr, /* in_opt_time_marker_ptr */
                                                              in_name,
                                                             &result) )
    {
        vkgl_assert_fail();
    }

    return result;
}

void OpenGL::Context::get_uniform_value(const GLuint&                     in_program,
                                        const GLint&                      in_location,
                                        const OpenGL::GetSetArgumentType& in_params_type,
                                        void*                             out_params_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::get_vertex_attrib_pointer_property(const GLuint&                                 in_index,
                                                         const OpenGL::VertexAttributePointerProperty& in_pname,
                                                         void**                                        out_pointer_ptr) const
{
    vkgl_assert(m_gl_vao_manager_ptr != nullptr);
    vkgl_assert(in_pname             == OpenGL::VertexAttributePointerProperty::Vertex_Attribute_Array_Pointer);

    const auto& bound_vao_reference_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();
    vkgl_assert(bound_vao_reference_ptr != nullptr);

    const auto bound_vao_time_marker = bound_vao_reference_ptr->get_payload().time_marker;

    m_gl_vao_manager_ptr->get_vaa_property(bound_vao_reference_ptr->get_payload().id,
                                          &bound_vao_time_marker,
                                           in_index,
                                           OpenGL::VertexAttributeProperty::Pointer,
                                           OpenGL::GetSetArgumentType::Pointer,
                                           out_pointer_ptr);
}

void OpenGL::Context::get_vertex_attribute_property(const GLuint&                          in_index,
                                                    const OpenGL::VertexAttributeProperty& in_pname,
                                                    const OpenGL::GetSetArgumentType&      in_src_type,
                                                    const OpenGL::GetSetArgumentType&      in_dst_type,
                                                    void*                                  out_params_ptr) const
{
    if (in_pname == OpenGL::VertexAttributeProperty::Current_Vertex_Attribute)
    {
        /* Generic vertex attribute support is TODO
         *
         * NOTE: in_src_type is relevant to this case. */
        vkgl_not_implemented();
    }
    else
    {
        /* NOTE: in_src_type is irrelevant for this path. */
        vkgl_assert(m_gl_vao_manager_ptr != nullptr);

        const auto& bound_vao_reference_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();
        vkgl_assert(bound_vao_reference_ptr != nullptr);

        const auto bound_vao_time_marker = bound_vao_reference_ptr->get_payload().time_marker;

        m_gl_vao_manager_ptr->get_vaa_property(bound_vao_reference_ptr->get_payload().id,
                                              &bound_vao_time_marker,
                                               in_index,
                                               in_pname,
                                               in_dst_type,
                                               out_params_ptr);
    }
}

bool OpenGL::Context::init()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    bool result = false;

    /* Init dispatch table */
    result = init_dispatch_table();

    if (!result)
    {
        vkgl_assert(result);

        goto end;
    }

    /* Cache supported extensions */
    result = init_supported_extensions();

    if (!result)
    {
        vkgl_assert(result);

        goto end;
    }

    /* Set up GL constants container */
    m_gl_constants_ptr.reset(
        new OpenGL::GLConstants(dynamic_cast<IContext*>(this) )
    );

    if (m_gl_constants_ptr == nullptr)
    {
        vkgl_assert(m_gl_constants_ptr != nullptr);

        goto end;
    }

    /* Set up GL limits container */
    m_gl_limits_ptr.reset(
        new OpenGL::GLLimits(m_backend_caps_ptr)
    );

    if (m_gl_limits_ptr == nullptr)
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        goto end;
    }

    /* Set up shader manager */
    m_gl_shader_manager_ptr = OpenGL::GLShaderManager::create(m_backend_gl_callbacks_ptr);

    if (m_gl_shader_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_shader_manager_ptr != nullptr);

        goto end;
    }

    /* Set up program manager */
    m_gl_program_manager_ptr = OpenGL::GLProgramManager::create(this,
                                                                m_backend_gl_callbacks_ptr);

    if (m_gl_program_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_program_manager_ptr != nullptr);

        goto end;
    }

    /* Set up GL buffer manager */
    m_gl_buffer_manager_ptr = OpenGL::GLBufferManager::create();

    if (m_gl_buffer_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

        goto end;
    }

    /* Set up GL texture manager */
    m_gl_texture_manager_ptr = OpenGL::GLTextureManager::create(dynamic_cast<const IGLLimits*>(m_gl_limits_ptr.get() ) );

    if (m_gl_texture_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_texture_manager_ptr != nullptr);

        goto end;
    }

    /* Set up VAO manager */
    m_gl_vao_manager_ptr = OpenGL::GLVAOManager::create(dynamic_cast<const IGLLimits*>(m_gl_limits_ptr.get() ),
                                                        this);

    if (m_gl_vao_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_vao_manager_ptr != nullptr);

        goto end;
    }

    /* Set up GL renderbuffer manager */
    m_gl_renderbuffer_manager_ptr = OpenGL::GLRenderbufferManager::create();

    if (m_gl_renderbuffer_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);

        goto end;

    }

    /* Set up GL framebuffer manager */
    m_gl_framebuffer_manager_ptr = OpenGL::GLFramebufferManager::create(m_gl_limits_ptr.get(),
                                                                        m_wsi_context_ptr,
                                                                        this);

    if (m_gl_framebuffer_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);

        goto end;

    }

    /* Set up GL state manager */
    m_gl_state_manager_ptr.reset(
        new OpenGL::GLStateManager(dynamic_cast<IGLLimits*>(m_gl_limits_ptr.get() ),
                                   this,
                                   m_wsi_context_ptr)
    );

    if (m_gl_state_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_state_manager_ptr != nullptr);

        goto end;
    }

    /* Set up GL compatibility manager */
    m_gl_compatibility_manager_ptr.reset(
        new OpenGL::GLCompatibilityManager(dynamic_cast<IContextObjectManagers*>(this) )
    );

    if (m_gl_compatibility_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_compatibility_manager_ptr != nullptr);

        goto end;
    }

    /* All done */
    result = true;
end:
    return result;
}

bool OpenGL::Context::init_dispatch_table()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    bool result = false;

    m_dispatch_table.bound_context_ptr         = this;
    m_dispatch_table.pGLBindTexture            = glBindTexture;
    m_dispatch_table.pGLBlendFunc              = glBlendFunc;
    m_dispatch_table.pGLClear                  = glClear;
    m_dispatch_table.pGLClearColor             = glClearColor;
    m_dispatch_table.pGLClearDepth             = glClearDepth;
    m_dispatch_table.pGLClearStencil           = glClearStencil;
    m_dispatch_table.pGLColorMask              = glColorMask;
    m_dispatch_table.pGLCopyTexImage1D         = glCopyTexImage1D;
    m_dispatch_table.pGLCopyTexImage2D         = glCopyTexImage2D;
    m_dispatch_table.pGLCopyTexSubImage1D      = glCopyTexSubImage1D;
    m_dispatch_table.pGLCopyTexSubImage2D      = glCopyTexSubImage2D;
    m_dispatch_table.pGLCullFace               = glCullFace;
    m_dispatch_table.pGLDeleteTextures         = glDeleteTextures;
    m_dispatch_table.pGLDepthFunc              = glDepthFunc;
    m_dispatch_table.pGLDepthMask              = glDepthMask;
    m_dispatch_table.pGLDepthRange             = glDepthRange;
    m_dispatch_table.pGLDisable                = glDisable;
    m_dispatch_table.pGLDrawArrays             = glDrawArrays;
    m_dispatch_table.pGLDrawBuffer             = glDrawBuffer;
    m_dispatch_table.pGLDrawElements           = glDrawElements;
    m_dispatch_table.pGLEnable                 = glEnable;
    m_dispatch_table.pGLFinish                 = glFinish;
    m_dispatch_table.pGLFlush                  = glFlush;
    m_dispatch_table.pGLFrontFace              = glFrontFace;
    m_dispatch_table.pGLGenTextures            = glGenTextures;
    m_dispatch_table.pGLGetBooleanv            = glGetBooleanv;
    m_dispatch_table.pGLGetDoublev             = glGetDoublev;
    m_dispatch_table.pGLGetError               = glGetError;
    m_dispatch_table.pGLGetFloatv              = glGetFloatv;
    m_dispatch_table.pGLGetIntegerv            = glGetIntegerv;
    m_dispatch_table.pGLGetString              = glGetString;
    m_dispatch_table.pGLGetTexImage            = glGetTexImage;
    m_dispatch_table.pGLGetTexLevelParameterfv = glGetTexLevelParameterfv;
    m_dispatch_table.pGLGetTexLevelParameteriv = glGetTexLevelParameteriv;
    m_dispatch_table.pGLGetTexParameterfv      = glGetTexParameterfv;
    m_dispatch_table.pGLGetTexParameteriv      = glGetTexParameteriv;
    m_dispatch_table.pGLHint                   = glHint;
    m_dispatch_table.pGLIsEnabled              = glIsEnabled;
    m_dispatch_table.pGLIsTexture              = glIsTexture;
    m_dispatch_table.pGLLineWidth              = glLineWidth;
    m_dispatch_table.pGLLogicOp                = glLogicOp;
    m_dispatch_table.pGLPixelStoref            = glPixelStoref;
    m_dispatch_table.pGLPixelStorei            = glPixelStorei;
    m_dispatch_table.pGLPointSize              = glPointSize;
    m_dispatch_table.pGLPolygonMode            = glPolygonMode;
    m_dispatch_table.pGLPolygonOffset          = glPolygonOffset;
    m_dispatch_table.pGLReadBuffer             = glReadBuffer;
    m_dispatch_table.pGLReadPixels             = glReadPixels;
    m_dispatch_table.pGLScissor                = glScissor;
    m_dispatch_table.pGLStencilFunc            = glStencilFunc;
    m_dispatch_table.pGLStencilMask            = glStencilMask;
    m_dispatch_table.pGLStencilOp              = glStencilOp;
    m_dispatch_table.pGLTexImage1D             = glTexImage1D;
    m_dispatch_table.pGLTexImage2D             = glTexImage2D;
    m_dispatch_table.pGLTexParameterf          = glTexParameterf;
    m_dispatch_table.pGLTexParameterfv         = glTexParameterfv;
    m_dispatch_table.pGLTexParameteri          = glTexParameteri;
    m_dispatch_table.pGLTexParameteriv         = glTexParameteriv;
    m_dispatch_table.pGLTexSubImage1D          = glTexSubImage1D;
    m_dispatch_table.pGLTexSubImage2D          = glTexSubImage2D;
    m_dispatch_table.pGLViewport               = glViewport;

    m_dispatch_table.pGLCopyTexSubImage3D = glCopyTexSubImage3D;
    m_dispatch_table.pGLDrawRangeElements = glDrawRangeElements;
    m_dispatch_table.pGLTexImage3D        = glTexImage3D;
    m_dispatch_table.pGLTexSubImage3D     = glTexSubImage3D;

    m_dispatch_table.pGLActiveTexture           = glActiveTexture;
    m_dispatch_table.pGLCompressedTexImage1D    = glCompressedTexImage1D;
    m_dispatch_table.pGLCompressedTexImage2D    = glCompressedTexImage2D;
    m_dispatch_table.pGLCompressedTexImage3D    = glCompressedTexImage3D;
    m_dispatch_table.pGLCompressedTexSubImage1D = glCompressedTexSubImage1D;
    m_dispatch_table.pGLCompressedTexSubImage2D = glCompressedTexSubImage2D;
    m_dispatch_table.pGLCompressedTexSubImage3D = glCompressedTexSubImage3D;
    m_dispatch_table.pGLGetCompressedTexImage   = glGetCompressedTexImage;
    m_dispatch_table.pGLSampleCoverage          = glSampleCoverage;

    m_dispatch_table.pGLBlendColor        = glBlendColor;
    m_dispatch_table.pGLBlendEquation     = glBlendEquation;
    m_dispatch_table.pGLBlendFuncSeparate = glBlendFuncSeparate;
    m_dispatch_table.pGLMultiDrawArrays   = glMultiDrawArrays;
    m_dispatch_table.pGLMultiDrawElements = glMultiDrawElements;
    m_dispatch_table.pGLPointParameterf   = glPointParameterf;
    m_dispatch_table.pGLPointParameterfv  = glPointParameterfv;
    m_dispatch_table.pGLPointParameteri   = glPointParameteri;
    m_dispatch_table.pGLPointParameteriv  = glPointParameteriv;

    m_dispatch_table.pGLBeginQuery           = glBeginQuery;
    m_dispatch_table.pGLBindBuffer           = glBindBuffer;
    m_dispatch_table.pGLBufferData           = glBufferData;
    m_dispatch_table.pGLBufferSubData        = glBufferSubData;
    m_dispatch_table.pGLDeleteBuffers        = glDeleteBuffers;
    m_dispatch_table.pGLDeleteQueries        = glDeleteQueries;
    m_dispatch_table.pGLEndQuery             = glEndQuery;
    m_dispatch_table.pGLGenBuffers           = glGenBuffers;
    m_dispatch_table.pGLGenQueries           = glGenQueries;
    m_dispatch_table.pGLGetBufferParameteriv = glGetBufferParameteriv;
    m_dispatch_table.pGLGetBufferPointerv    = glGetBufferPointerv;
    m_dispatch_table.pGLGetBufferSubData     = glGetBufferSubData;
    m_dispatch_table.pGLGetQueryiv           = glGetQueryiv;
    m_dispatch_table.pGLGetQueryObjectiv     = glGetQueryObjectiv;
    m_dispatch_table.pGLGetQueryObjectuiv    = glGetQueryObjectuiv;
    m_dispatch_table.pGLIsBuffer             = glIsBuffer;
    m_dispatch_table.pGLIsQuery              = glIsQuery;
    m_dispatch_table.pGLMapBuffer            = glMapBuffer;
    m_dispatch_table.pGLUnmapBuffer          = glUnmapBuffer;

    m_dispatch_table.pGLAttachShader             = glAttachShader;
    m_dispatch_table.pGLBindAttribLocation       = glBindAttribLocation;
    m_dispatch_table.pGLBlendEquationSeparate    = glBlendEquationSeparate;
    m_dispatch_table.pGLCompileShader            = glCompileShader;
    m_dispatch_table.pGLCreateProgram            = glCreateProgram;
    m_dispatch_table.pGLCreateShader             = glCreateShader;
    m_dispatch_table.pGLDeleteProgram            = glDeleteProgram;
    m_dispatch_table.pGLDeleteShader             = glDeleteShader;
    m_dispatch_table.pGLDetachShader             = glDetachShader;
    m_dispatch_table.pGLDisableVertexAttribArray = glDisableVertexAttribArray;
    m_dispatch_table.pGLDrawBuffers              = glDrawBuffers;
    m_dispatch_table.pGLEnableVertexAttribArray  = glEnableVertexAttribArray;
    m_dispatch_table.pGLGetActiveAttrib          = glGetActiveAttrib;
    m_dispatch_table.pGLGetActiveUniform         = glGetActiveUniform;
    m_dispatch_table.pGLGetAttachedShaders       = glGetAttachedShaders;
    m_dispatch_table.pGLGetAttribLocation        = glGetAttribLocation;
    m_dispatch_table.pGLGetProgramiv             = glGetProgramiv;
    m_dispatch_table.pGLGetProgramInfoLog        = glGetProgramInfoLog;
    m_dispatch_table.pGLGetShaderiv              = glGetShaderiv;
    m_dispatch_table.pGLGetShaderInfoLog         = glGetShaderInfoLog;
    m_dispatch_table.pGLGetShaderSource          = glGetShaderSource;
    m_dispatch_table.pGLGetUniformfv             = glGetUniformfv;
    m_dispatch_table.pGLGetUniformiv             = glGetUniformiv;
    m_dispatch_table.pGLGetUniformLocation       = glGetUniformLocation;
    m_dispatch_table.pGLGetVertexAttribdv        = glGetVertexAttribdv;
    m_dispatch_table.pGLGetVertexAttribfv        = glGetVertexAttribfv;
    m_dispatch_table.pGLGetVertexAttribiv        = glGetVertexAttribiv;
    m_dispatch_table.pGLGetVertexAttribPointerv  = glGetVertexAttribPointerv;
    m_dispatch_table.pGLIsProgram                = glIsProgram;
    m_dispatch_table.pGLIsShader                 = glIsShader;
    m_dispatch_table.pGLLinkProgram              = glLinkProgram;
    m_dispatch_table.pGLShaderSource             = glShaderSource;
    m_dispatch_table.pGLStencilFuncSeparate      = glStencilFuncSeparate;
    m_dispatch_table.pGLStencilMaskSeparate      = glStencilMaskSeparate;
    m_dispatch_table.pGLStencilOpSeparate        = glStencilOpSeparate;
    m_dispatch_table.pGLUniform1f                = glUniform1f;
    m_dispatch_table.pGLUniform1fv               = glUniform1fv;
    m_dispatch_table.pGLUniform1i                = glUniform1i;
    m_dispatch_table.pGLUniform1iv               = glUniform1iv;
    m_dispatch_table.pGLUniform2f                = glUniform2f;
    m_dispatch_table.pGLUniform2fv               = glUniform2fv;
    m_dispatch_table.pGLUniform2i                = glUniform2i;
    m_dispatch_table.pGLUniform2iv               = glUniform2iv;
    m_dispatch_table.pGLUniform3f                = glUniform3f;
    m_dispatch_table.pGLUniform3fv               = glUniform3fv;
    m_dispatch_table.pGLUniform3i                = glUniform3i;
    m_dispatch_table.pGLUniform3iv               = glUniform3iv;
    m_dispatch_table.pGLUniform4f                = glUniform4f;
    m_dispatch_table.pGLUniform4fv               = glUniform4fv;
    m_dispatch_table.pGLUniform4i                = glUniform4i;
    m_dispatch_table.pGLUniform4iv               = glUniform4iv;
    m_dispatch_table.pGLUniformMatrix2fv         = glUniformMatrix2fv;
    m_dispatch_table.pGLUniformMatrix3fv         = glUniformMatrix3fv;
    m_dispatch_table.pGLUniformMatrix4fv         = glUniformMatrix4fv;
    m_dispatch_table.pGLUseProgram               = glUseProgram;
    m_dispatch_table.pGLValidateProgram          = glValidateProgram;
    m_dispatch_table.pGLVertexAttrib1d           = glVertexAttrib1d;
    m_dispatch_table.pGLVertexAttrib1dv          = glVertexAttrib1dv;
    m_dispatch_table.pGLVertexAttrib1f           = glVertexAttrib1f;
    m_dispatch_table.pGLVertexAttrib1fv          = glVertexAttrib1fv;
    m_dispatch_table.pGLVertexAttrib1s           = glVertexAttrib1s;
    m_dispatch_table.pGLVertexAttrib1sv          = glVertexAttrib1sv;
    m_dispatch_table.pGLVertexAttrib2d           = glVertexAttrib2d;
    m_dispatch_table.pGLVertexAttrib2dv          = glVertexAttrib2dv;
    m_dispatch_table.pGLVertexAttrib2f           = glVertexAttrib2f;
    m_dispatch_table.pGLVertexAttrib2fv          = glVertexAttrib2fv;
    m_dispatch_table.pGLVertexAttrib2s           = glVertexAttrib2s;
    m_dispatch_table.pGLVertexAttrib2sv          = glVertexAttrib2sv;
    m_dispatch_table.pGLVertexAttrib3d           = glVertexAttrib3d;
    m_dispatch_table.pGLVertexAttrib3dv          = glVertexAttrib3dv;
    m_dispatch_table.pGLVertexAttrib3f           = glVertexAttrib3f;
    m_dispatch_table.pGLVertexAttrib3fv          = glVertexAttrib3fv;
    m_dispatch_table.pGLVertexAttrib3s           = glVertexAttrib3s;
    m_dispatch_table.pGLVertexAttrib3sv          = glVertexAttrib3sv;
    m_dispatch_table.pGLVertexAttrib4bv          = glVertexAttrib4bv;
    m_dispatch_table.pGLVertexAttrib4d           = glVertexAttrib4d;
    m_dispatch_table.pGLVertexAttrib4dv          = glVertexAttrib4dv;
    m_dispatch_table.pGLVertexAttrib4f           = glVertexAttrib4f;
    m_dispatch_table.pGLVertexAttrib4fv          = glVertexAttrib4fv;
    m_dispatch_table.pGLVertexAttrib4iv          = glVertexAttrib4iv;
    m_dispatch_table.pGLVertexAttrib4Nbv         = glVertexAttrib4Nbv;
    m_dispatch_table.pGLVertexAttrib4Niv         = glVertexAttrib4Niv;
    m_dispatch_table.pGLVertexAttrib4Nsv         = glVertexAttrib4Nsv;
    m_dispatch_table.pGLVertexAttrib4Nub         = glVertexAttrib4Nub;
    m_dispatch_table.pGLVertexAttrib4Nubv        = glVertexAttrib4Nubv;
    m_dispatch_table.pGLVertexAttrib4Nuiv        = glVertexAttrib4Nuiv;
    m_dispatch_table.pGLVertexAttrib4Nusv        = glVertexAttrib4Nusv;
    m_dispatch_table.pGLVertexAttrib4s           = glVertexAttrib4s;
    m_dispatch_table.pGLVertexAttrib4sv          = glVertexAttrib4sv;
    m_dispatch_table.pGLVertexAttrib4ubv         = glVertexAttrib4ubv;
    m_dispatch_table.pGLVertexAttrib4uiv         = glVertexAttrib4uiv;
    m_dispatch_table.pGLVertexAttrib4usv         = glVertexAttrib4usv;
    m_dispatch_table.pGLVertexAttribPointer      = glVertexAttribPointer;

    m_dispatch_table.pGLUniformMatrix2x3fv = glUniformMatrix2x3fv;
    m_dispatch_table.pGLUniformMatrix2x4fv = glUniformMatrix2x4fv;
    m_dispatch_table.pGLUniformMatrix3x2fv = glUniformMatrix3x2fv;
    m_dispatch_table.pGLUniformMatrix3x4fv = glUniformMatrix3x4fv;
    m_dispatch_table.pGLUniformMatrix4x2fv = glUniformMatrix4x2fv;
    m_dispatch_table.pGLUniformMatrix4x3fv = glUniformMatrix4x3fv;

    m_dispatch_table.pGLBeginConditionalRender              = glBeginConditionalRender;
    m_dispatch_table.pGLBeginTransformFeedback              = glBeginTransformFeedback;
    m_dispatch_table.pGLBindBufferBase                      = glBindBufferBase;
    m_dispatch_table.pGLBindBufferRange                     = glBindBufferRange;
    m_dispatch_table.pGLBindFragDataLocation                = glBindFragDataLocation;
    m_dispatch_table.pGLBindFramebuffer                     = glBindFramebuffer;
    m_dispatch_table.pGLBindRenderbuffer                    = glBindRenderbuffer;
    m_dispatch_table.pGLBindVertexArray                     = glBindVertexArray;
    m_dispatch_table.pGLBlitFramebuffer                     = glBlitFramebuffer;
    m_dispatch_table.pGLCheckFramebufferStatus              = glCheckFramebufferStatus;
    m_dispatch_table.pGLClampColor                          = glClampColor;
    m_dispatch_table.pGLClearBufferfi                       = glClearBufferfi;
    m_dispatch_table.pGLClearBufferfv                       = glClearBufferfv;
    m_dispatch_table.pGLClearBufferiv                       = glClearBufferiv;
    m_dispatch_table.pGLClearBufferuiv                      = glClearBufferuiv;
    m_dispatch_table.pGLColorMaski                          = glColorMaski;
    m_dispatch_table.pGLDeleteFramebuffers                  = glDeleteFramebuffers;
    m_dispatch_table.pGLDeleteRenderbuffers                 = glDeleteRenderbuffers;
    m_dispatch_table.pGLDeleteVertexArrays                  = glDeleteVertexArrays;
    m_dispatch_table.pGLDisablei                            = glDisablei;
    m_dispatch_table.pGLEnablei                             = glEnablei;
    m_dispatch_table.pGLEndConditionalRender                = glEndConditionalRender;
    m_dispatch_table.pGLEndTransformFeedback                = glEndTransformFeedback;
    m_dispatch_table.pGLFlushMappedBufferRange              = glFlushMappedBufferRange;
    m_dispatch_table.pGLFramebufferRenderbuffer             = glFramebufferRenderbuffer;
    m_dispatch_table.pGLFramebufferTexture1D                = glFramebufferTexture1D;
    m_dispatch_table.pGLFramebufferTexture2D                = glFramebufferTexture2D;
    m_dispatch_table.pGLFramebufferTexture3D                = glFramebufferTexture3D;
    m_dispatch_table.pGLFramebufferTextureLayer             = glFramebufferTextureLayer;
    m_dispatch_table.pGLGenerateMipmap                      = glGenerateMipmap;
    m_dispatch_table.pGLGenFramebuffers                     = glGenFramebuffers;
    m_dispatch_table.pGLGenRenderbuffers                    = glGenRenderbuffers;
    m_dispatch_table.pGLGenVertexArrays                     = glGenVertexArrays;
    m_dispatch_table.pGLGetBooleani_v                       = glGetBooleani_v;
    m_dispatch_table.pGLGetFragDataLocation                 = glGetFragDataLocation;
    m_dispatch_table.pGLGetFramebufferAttachmentParameteriv = glGetFramebufferAttachmentParameteriv;
    m_dispatch_table.pGLGetIntegeri_v                       = glGetIntegeri_v;
    m_dispatch_table.pGLGetRenderbufferParameteriv          = glGetRenderbufferParameteriv;
    m_dispatch_table.pGLGetStringi                          = glGetStringi;
    m_dispatch_table.pGLGetTexParameterIiv                  = glGetTexParameterIiv;
    m_dispatch_table.pGLGetTexParameterIuiv                 = glGetTexParameterIuiv;
    m_dispatch_table.pGLGetTransformFeedbackVarying         = glGetTransformFeedbackVarying;
    m_dispatch_table.pGLGetUniformuiv                       = glGetUniformuiv;
    m_dispatch_table.pGLGetVertexAttribIiv                  = glGetVertexAttribIiv;
    m_dispatch_table.pGLGetVertexAttribIuiv                 = glGetVertexAttribIuiv;
    m_dispatch_table.pGLIsEnabledi                          = glIsEnabledi;
    m_dispatch_table.pGLIsFramebuffer                       = glIsFramebuffer;
    m_dispatch_table.pGLIsRenderbuffer                      = glIsRenderbuffer;
    m_dispatch_table.pGLIsVertexArray                       = glIsVertexArray;
    m_dispatch_table.pGLMapBufferRange                      = glMapBufferRange;
    m_dispatch_table.pGLRenderbufferStorage                 = glRenderbufferStorage;
    m_dispatch_table.pGLRenderbufferStorageMultisample      = glRenderbufferStorageMultisample;
    m_dispatch_table.pGLTexParameterIiv                     = glTexParameterIiv;
    m_dispatch_table.pGLTexParameterIuiv                    = glTexParameterIuiv;
    m_dispatch_table.pGLTransformFeedbackVaryings           = glTransformFeedbackVaryings;
    m_dispatch_table.pGLUniform1ui                          = glUniform1ui;
    m_dispatch_table.pGLUniform1uiv                         = glUniform1uiv;
    m_dispatch_table.pGLUniform2ui                          = glUniform2ui;
    m_dispatch_table.pGLUniform2uiv                         = glUniform2uiv;
    m_dispatch_table.pGLUniform3ui                          = glUniform3ui;
    m_dispatch_table.pGLUniform3uiv                         = glUniform3uiv;
    m_dispatch_table.pGLUniform4ui                          = glUniform4ui;
    m_dispatch_table.pGLUniform4uiv                         = glUniform4uiv;
    m_dispatch_table.pGLVertexAttribI1i                     = glVertexAttribI1i;
    m_dispatch_table.pGLVertexAttribI1iv                    = glVertexAttribI1iv;
    m_dispatch_table.pGLVertexAttribI1ui                    = glVertexAttribI1ui;
    m_dispatch_table.pGLVertexAttribI1uiv                   = glVertexAttribI1uiv;
    m_dispatch_table.pGLVertexAttribI2i                     = glVertexAttribI2i;
    m_dispatch_table.pGLVertexAttribI2iv                    = glVertexAttribI2iv;
    m_dispatch_table.pGLVertexAttribI2ui                    = glVertexAttribI2ui;
    m_dispatch_table.pGLVertexAttribI2uiv                   = glVertexAttribI2uiv;
    m_dispatch_table.pGLVertexAttribI3i                     = glVertexAttribI3i;
    m_dispatch_table.pGLVertexAttribI3iv                    = glVertexAttribI3iv;
    m_dispatch_table.pGLVertexAttribI3ui                    = glVertexAttribI3ui;
    m_dispatch_table.pGLVertexAttribI3uiv                   = glVertexAttribI3uiv;
    m_dispatch_table.pGLVertexAttribI4bv                    = glVertexAttribI4bv;
    m_dispatch_table.pGLVertexAttribI4i                     = glVertexAttribI4i;
    m_dispatch_table.pGLVertexAttribI4iv                    = glVertexAttribI4iv;
    m_dispatch_table.pGLVertexAttribI4sv                    = glVertexAttribI4sv;
    m_dispatch_table.pGLVertexAttribI4ubv                   = glVertexAttribI4ubv;
    m_dispatch_table.pGLVertexAttribI4ui                    = glVertexAttribI4ui;
    m_dispatch_table.pGLVertexAttribI4uiv                   = glVertexAttribI4uiv;
    m_dispatch_table.pGLVertexAttribI4usv                   = glVertexAttribI4usv;
    m_dispatch_table.pGLVertexAttribIPointer                = glVertexAttribIPointer;

    m_dispatch_table.pGLCopyBufferSubData         = glCopyBufferSubData;
    m_dispatch_table.pGLDrawArraysInstanced       = glDrawArraysInstanced;
    m_dispatch_table.pGLDrawElementsInstanced     = glDrawElementsInstanced;
    m_dispatch_table.pGLGetActiveUniformsiv       = glGetActiveUniformsiv;
    m_dispatch_table.pGLGetActiveUniformBlockiv   = glGetActiveUniformBlockiv;
    m_dispatch_table.pGLGetActiveUniformBlockName = glGetActiveUniformBlockName;
    m_dispatch_table.pGLGetActiveUniformName      = glGetActiveUniformName;
    m_dispatch_table.pGLGetUniformBlockIndex      = glGetUniformBlockIndex;
    m_dispatch_table.pGLGetUniformIndices         = glGetUniformIndices;
    m_dispatch_table.pGLPrimitiveRestartIndex     = glPrimitiveRestartIndex;
    m_dispatch_table.pGLTexBuffer                 = glTexBuffer;
    m_dispatch_table.pGLUniformBlockBinding       = glUniformBlockBinding;

    m_dispatch_table.pGLClientWaitSync                  = glClientWaitSync;
    m_dispatch_table.pGLDeleteSync                      = glDeleteSync;
    m_dispatch_table.pGLDrawElementsBaseVertex          = glDrawElementsBaseVertex;
    m_dispatch_table.pGLDrawElementsInstancedBaseVertex = glDrawElementsInstancedBaseVertex;
    m_dispatch_table.pGLDrawRangeElementsBaseVertex     = glDrawRangeElementsBaseVertex;
    m_dispatch_table.pGLFenceSync                       = glFenceSync;
    m_dispatch_table.pGLFramebufferTexture              = glFramebufferTexture;
    m_dispatch_table.pGLGetBufferParameteri64v          = glGetBufferParameteri64v;
    m_dispatch_table.pGLGetInteger64i_v                 = glGetInteger64i_v;
    m_dispatch_table.pGLGetInteger64v                   = glGetInteger64v;
    m_dispatch_table.pGLGetMultisamplefv                = glGetMultisamplefv;
    m_dispatch_table.pGLGetSynciv                       = glGetSynciv;
    m_dispatch_table.pGLIsSync                          = glIsSync;
    m_dispatch_table.pGLMultiDrawElementsBaseVertex     = glMultiDrawElementsBaseVertex;
    m_dispatch_table.pGLProvokingVertex                 = glProvokingVertex;
    m_dispatch_table.pGLSampleMaski                     = glSampleMaski;
    m_dispatch_table.pGLTexImage2DMultisample           = glTexImage2DMultisample;
    m_dispatch_table.pGLTexImage3DMultisample           = glTexImage3DMultisample;
    m_dispatch_table.pGLWaitSync                        = glWaitSync;

    result = true;
    return result;
}

bool OpenGL::Context::init_supported_extensions()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    bool result = false;

    vkgl_assert(m_supported_extensions.size() == 0);

    /* TODO: This array should probably be generated by an external Python script executed at cmake build time
     *       by looking up directory names under OpenGL/entrypoints and excluding everything that starts with GL{number}* ..
     */
    m_supported_extensions =
    {
        "GL_ARB_color_buffer_float",
        "GL_ARB_copy_buffer",
        "GL_ARB_depth_buffer_float",
        "GL_ARB_depth_clamp",
        "GL_ARB_depth_texture",
        "GL_ARB_draw_buffers",
        "GL_ARB_draw_elements_base_vertex",
        "GL_ARB_draw_instanced",
        "GL_ARB_fragment_coord_conventions",
        "GL_ARB_fragment_program_shadow",
        "GL_ARB_fragment_shader",
        "GL_ARB_framebuffer_object",
        "GL_ARB_framebuffer_sRGB",
        "GL_ARB_half_float_pixel",
        "GL_ARB_half_float_vertex",
        "GL_ARB_map_buffer_range",
        "GL_ARB_multisample",
        "GL_ARB_multitexture",
        "GL_ARB_occlusion_query",
        "GL_ARB_pixel_buffer_object",
        "GL_ARB_point_parameters",
        "GL_ARB_point_sprite",
        "GL_ARB_provoking_vertex",
        "GL_ARB_seamless_cube_map",
        "GL_ARB_shader_texture_lod",
        "GL_ARB_shading_language_100",
        "GL_ARB_shadow",
        "GL_ARB_sync",
        "GL_ARB_texture_border_clamp",
        "GL_ARB_texture_buffer_object",
        "GL_ARB_texture_compression",
        "GL_ARB_texture_compression_rgtc",
        "GL_ARB_texture_cube_map",
        "GL_ARB_texture_cube_map_array",
        "GL_ARB_texture_float",
        "GL_ARB_texture_gather",
        "GL_ARB_texture_mirrored_repeat",
        "GL_ARB_texture_multisample",
        "GL_ARB_texture_non_power_of_two",
        "GL_ARB_texture_query_lod",
        "GL_ARB_texture_rectangle",
        "GL_ARB_texture_rg",
        "GL_ARB_uniform_buffer_object",
        "GL_ARB_vertex_array_bgra",
        "GL_ARB_vertex_array_object",
        "GL_ARB_vertex_buffer_object",
        "GL_ARB_vertex_program",
        "GL_ARB_vertex_shader"
    };

    result = true;
    return result;
}

bool OpenGL::Context::is_buffer(const GLuint& in_id) const
{
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    return m_gl_buffer_manager_ptr->is_alive_id(in_id);
}

bool OpenGL::Context::is_enabled(const OpenGL::Capability& in_capability) const
{
#if true
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->is_enabled(in_capability);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_enabled_indexed(const OpenGL::Capability& in_capability,
                                         const GLuint&             in_index) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_framebuffer(const GLuint& in_framebuffer) const
{
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);

    return m_gl_framebuffer_manager_ptr->is_alive_id(in_framebuffer);
}

bool OpenGL::Context::is_program(const GLuint& in_program) const
{
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    return m_gl_program_manager_ptr->is_alive_id(in_program);
}

bool OpenGL::Context::is_query(const GLuint& in_id) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    return m_gl_query_manager_ptr->is_alive_id(in_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_renderbuffer(const GLuint& in_renderbuffer) const
{
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);

    return m_gl_renderbuffer_manager_ptr->is_alive_id(in_renderbuffer);
}

bool OpenGL::Context::is_shader(const GLuint& in_shader) const
{
    return m_gl_shader_manager_ptr->is_alive_id(in_shader);
}

bool OpenGL::Context::is_sync(const GLsync& in_sync)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_texture(const GLuint& in_texture) const
{
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    return m_gl_texture_manager_ptr->is_alive_id(in_texture);
}

bool OpenGL::Context::is_vertex_array(const GLuint& in_array) const
{
    vkgl_assert(m_gl_vao_manager_ptr != nullptr);

    return m_gl_vao_manager_ptr->is_alive_id(in_array);
}

void OpenGL::Context::link_program(const GLuint& in_program)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->link_program(in_program);
}

void* OpenGL::Context::map_buffer(const OpenGL::BufferTarget& in_target,
                                  const OpenGL::BufferAccess& in_access)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_buffer_manager_ptr    != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto& buffer_reference_ptr = m_gl_state_manager_ptr->get_bound_buffer_object(in_target);
    vkgl_assert(buffer_reference_ptr != nullptr);

    const auto buffer_reference_time_marker = buffer_reference_ptr->get_payload().time_marker;
    const auto buffer_size                  = m_gl_buffer_manager_ptr->get_buffer_size( buffer_reference_ptr->get_payload().id,
                                                                                       &buffer_reference_time_marker);

    return m_backend_gl_callbacks_ptr->map_buffer(buffer_reference_ptr->get_payload().id,
                                                  in_access,
                                                  0, /* in_start_offset */
                                                  buffer_size);
}

void* OpenGL::Context::map_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_length,
                                        const OpenGL::BufferAccess& in_access)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;
    vkgl_assert(buffer_id != 0);

    return m_backend_gl_callbacks_ptr->map_buffer(buffer_id,
                                                  in_access,
                                                  in_offset,
                                                  in_length);
}

void OpenGL::Context::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                        const GLint*                in_first_ptr,
                                        const GLsizei*              in_count_ptr,
                                        const GLsizei&              in_drawcount)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->multi_draw_arrays(in_mode,
                                                  in_first_ptr,
                                                  in_count_ptr,
                                                  in_drawcount);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                          const GLsizei*                   in_count_ptr,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void* const*               in_indices_ptr,
                                          const GLsizei&                   in_drawcount)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->multi_draw_elements(in_mode,
                                                    in_count_ptr,
                                                    in_type,
                                                    in_indices_ptr,
                                                    in_drawcount);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::multi_draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                      const GLsizei*                   in_count_ptr,
                                                      const OpenGL::DrawCallIndexType& in_type,
                                                      const void* const*               in_indices_ptr,
                                                      const GLsizei&                   in_drawcount,
                                                      const GLint*                     in_basevertex_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::present()
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    m_backend_gl_callbacks_ptr->present();
}

void OpenGL::Context::read_pixels(const int32_t&             in_x,
                                  const int32_t&             in_y,
                                  const size_t&              in_width,
                                  const size_t&              in_height,
                                  const OpenGL::PixelFormat& in_format,
                                  const OpenGL::PixelType&   in_type,
                                  void*                      out_pixels_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->read_pixels(in_x,
                                            in_y,
                                            in_width,
                                            in_height,
                                            in_format,
                                            in_type,
                                            out_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::set_active_texture(const uint32_t& in_n_texture_unit)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_active_texture(in_n_texture_unit);
}

void OpenGL::Context::set_blend_color(const float& in_red,
                                      const float& in_green,
                                      const float& in_blue,
                                      const float& in_alpha)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_color(in_red,
                                            in_green,
                                            in_blue,
                                            in_alpha);
}

void OpenGL::Context::set_blend_equation(const OpenGL::BlendEquation& in_blend_equation)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_equation(in_blend_equation);
}

void OpenGL::Context::set_blend_equation_separate(const OpenGL::BlendEquation& in_modeRGB,
                                                  const OpenGL::BlendEquation& in_modeAlpha)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_blend_functions(const OpenGL::BlendFunction& in_src_rgba_function,
                                          const OpenGL::BlendFunction& in_dst_rgba_function)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions(in_src_rgba_function,
                                                in_dst_rgba_function);
}

void OpenGL::Context::set_blend_functions_separate(const OpenGL::BlendFunction& in_src_rgb_function,
                                                   const OpenGL::BlendFunction& in_dst_rgb_function,
                                                   const OpenGL::BlendFunction& in_src_alpha_function,
                                                   const OpenGL::BlendFunction& in_dst_alpha_function)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions_separate(in_src_rgb_function,
                                                         in_dst_rgb_function,
                                                         in_src_alpha_function,
                                                         in_dst_alpha_function);
}

void OpenGL::Context::set_clamp_color(const bool& in_enable)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_clear_color_value(const float& in_red,
                                            const float& in_green,
                                            const float& in_blue,
                                            const float& in_alpha)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_color_value(in_red,
                                                  in_green,
                                                  in_blue,
                                                  in_alpha);
}

void OpenGL::Context::set_clear_depth_value(const double& in_value)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_depth_value(in_value);
}

void OpenGL::Context::set_clear_stencil_value(const int& in_value)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_stencil_value(in_value);
}

void OpenGL::Context::set_color_mask(const bool& in_red,
                                     const bool& in_green,
                                     const bool& in_blue,
                                     const bool& in_alpha)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_color_mask(in_red,
                                           in_green,
                                           in_blue,
                                           in_alpha);
}

void OpenGL::Context::set_color_mask_indexed(const GLuint& in_index,
                                             const bool&   in_r,
                                             const bool&   in_g,
                                             const bool&   in_b,
                                             const bool&   in_a)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_cull_mode(const OpenGL::CullMode& in_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_cull_mode(in_mode);
}

void OpenGL::Context::set_depth_function(const OpenGL::DepthFunction& in_function)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_function(in_function);
}

void OpenGL::Context::set_depth_mask(const bool& in_flag)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_mask(in_flag);
}

void OpenGL::Context::set_depth_range(const double& in_near,
                                      const double& in_far)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_range(in_near,
                                            in_far);
}

void OpenGL::Context::set_draw_buffer(const OpenGL::DrawBuffer& in_draw_buffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);

    const auto bound_fb_reference_ptr = m_gl_state_manager_ptr->get_bound_framebuffer_object(OpenGL::FramebufferTarget::Draw_Framebuffer);
    vkgl_assert(bound_fb_reference_ptr != nullptr);

    m_gl_framebuffer_manager_ptr->set_draw_buffers(bound_fb_reference_ptr->get_payload().id,
                                                   1,
                                                  &in_draw_buffer);
}

void OpenGL::Context::set_draw_buffers(const GLsizei&            in_n,
                                       const OpenGL::DrawBuffer* in_bufs_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);

    const auto bound_fb_reference_ptr = m_gl_state_manager_ptr->get_bound_framebuffer_object(OpenGL::FramebufferTarget::Draw_Framebuffer);
    vkgl_assert(bound_fb_reference_ptr != nullptr);

    m_gl_framebuffer_manager_ptr->set_draw_buffers(bound_fb_reference_ptr->get_payload().id,
                                                   in_n,
                                                   in_bufs_ptr);
}

void OpenGL::Context::set_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_front_face_orientation(in_orientation);
}

void OpenGL::Context::set_hint(const OpenGL::HintTarget& in_target,
                               const OpenGL::HintMode&   in_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_hint(in_target,
                                     in_mode);
}

void OpenGL::Context::set_line_width(const float& in_width)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_line_width(in_width);
}

void OpenGL::Context::set_logic_op(const OpenGL::LogicOpMode& in_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_logic_op(in_mode);
}

void OpenGL::Context::set_matrix_uniform(const GLint&    in_location,
                                         const uint32_t& in_n_columns,
                                         const uint32_t& in_n_rows,
                                         const uint32_t& in_n_array_items,
                                         const bool&     in_transpose,
                                         const GLfloat*  in_value_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    //vkgl_not_implemented();
    
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    
    auto program_id = m_gl_state_manager_ptr->get_state()->program_proxy_reference_ptr->get_payload().id;
    
    m_backend_gl_callbacks_ptr->update_uniform_data(program_id,
    													in_location,
    													in_n_array_items,
    													in_value_ptr);
}

void OpenGL::Context::set_pixel_store_property(const OpenGL::PixelStoreProperty& in_property,
                                               const OpenGL::GetSetArgumentType& in_arg_type,
                                               const void*                     in_arg_value_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_pixel_store_property(in_property,
                                                     in_arg_type,
                                                     in_arg_value_ptr);
}

void OpenGL::Context::set_point_property(const OpenGL::PointProperty&      in_property,
                                         const OpenGL::GetSetArgumentType& in_arg_type,
                                         const void*                       in_arg_value_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_property(in_property,
                                               in_arg_type,
                                               in_arg_value_ptr);
}

void OpenGL::Context::set_point_size(const float& in_size)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_size(in_size);
}

void OpenGL::Context::set_polygon_mode(const OpenGL::PolygonMode& in_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_mode(in_mode);
}

void OpenGL::Context::set_polygon_offset(const GLfloat& in_factor,
                                         const GLfloat& in_units)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_offset(in_factor,
                                               in_units);
}

void OpenGL::Context::set_primitive_restart_index(const GLuint& in_index)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_provoking_vertex(const OpenGL::ProvokingVertexConvention& in_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_read_buffer(const OpenGL::ReadBuffer& in_read_buffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_framebuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr       != nullptr);

    const auto bound_fb_reference_ptr = m_gl_state_manager_ptr->get_bound_framebuffer_object(OpenGL::FramebufferTarget::Read_Framebuffer);
    vkgl_assert(bound_fb_reference_ptr != nullptr);

    m_gl_framebuffer_manager_ptr->set_read_buffer(bound_fb_reference_ptr->get_payload().id,
                                                  in_read_buffer);
}

void OpenGL::Context::set_renderbuffer_storage(const OpenGL::RenderbufferTarget& in_target,
                                               const OpenGL::InternalFormat&     in_internalformat,
                                               const GLsizei&                    in_width,
                                               const GLsizei&                    in_height)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr    != nullptr);
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr        != nullptr);
    vkgl_assert(m_gl_limits_ptr        			!= nullptr);

    const auto renderbuffer_id = m_gl_state_manager_ptr->get_bound_renderbuffer_object()->get_payload().id;
    vkgl_assert(renderbuffer_id != 0);

    m_gl_renderbuffer_manager_ptr->set_renderbuffer_storage(renderbuffer_id,
                                                           in_internalformat,
                                                           in_width,
                                                           in_height,
                                                           1 /* in_n_samples */);

    m_backend_gl_callbacks_ptr->renderbuffer_storage(renderbuffer_id,
                                                     in_internalformat,
                                                     in_width,
                                                     in_height,
                                                     1 /* in_n_samples */);
}

void OpenGL::Context::set_renderbuffer_storage_multisample(const OpenGL::RenderbufferTarget& in_target,
                                                           const GLsizei&                    in_samples,
                                                           const OpenGL::InternalFormat&     in_internalformat,
                                                           const GLsizei&                    in_width,
                                                           const GLsizei&                    in_height)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr    != nullptr);
    vkgl_assert(m_gl_renderbuffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr        != nullptr);

    const auto renderbuffer_id = m_gl_state_manager_ptr->get_bound_renderbuffer_object()->get_payload().id;
    vkgl_assert(renderbuffer_id != 0);

    m_gl_renderbuffer_manager_ptr->set_renderbuffer_storage(renderbuffer_id,
                                                           in_internalformat,
                                                           in_width,
                                                           in_height,
                                                           in_samples);

    m_backend_gl_callbacks_ptr->renderbuffer_storage(renderbuffer_id,
                                                     in_internalformat,
                                                     in_width,
                                                     in_height,
                                                     in_samples);
}

void OpenGL::Context::set_sample_coverage(const GLfloat&   in_value,
                                          const GLboolean& in_invert)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_sample_coverage(in_value,
                                                (in_invert == GL_TRUE) );
}

void OpenGL::Context::set_sample_mask_indexed(const GLuint&     in_mask_number,
                                              const GLbitfield& in_mask)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_scissor(const int32_t& in_x,
                                  const int32_t& in_y,
                                  const size_t&  in_width,
                                  const size_t&  in_height)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_scissor(in_x,
                                        in_y,
                                        in_width,
                                        in_height);
}

void OpenGL::Context::set_shader_source(const GLuint&        in_shader,
                                        const GLsizei&       in_count,
                                        const GLchar* const* in_string_ptr_ptr,
                                        const GLint*         in_length_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    std::stringstream result_stream;

    /* Form the GLSL string */
    for (uint32_t n_chunk = 0;
                  n_chunk < static_cast<uint32_t>(in_count);
                ++n_chunk)
    {
        const auto current_string_ptr = in_string_ptr_ptr[n_chunk];

        if (in_length_ptr == nullptr)
        {
            result_stream << current_string_ptr;
        }
        else
        {
            const auto& current_length = in_length_ptr[n_chunk];

            vkgl_assert(current_string_ptr != nullptr);

            if (current_length < 0)
            {
                result_stream << current_string_ptr;
            }
            else
            {
                result_stream << std::string(current_string_ptr,
                                             current_length);
            }
        }
    }

    /* Assign it to the shader obhject */
    vkgl_assert(m_gl_shader_manager_ptr != nullptr);

    m_gl_shader_manager_ptr->set_shader_glsl(in_shader,
                                             result_stream.str() );
}

void OpenGL::Context::set_stencil_function(const OpenGL::StencilFunction& in_func,
                                           const int32_t&                 in_ref,
                                           const uint32_t&                in_mask)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_function(in_func,
                                                 in_ref,
                                                 in_mask);
}

void OpenGL::Context::set_stencil_function_separate(const OpenGL::StencilStateFace& in_face,
                                                    const OpenGL::StencilFunction&  in_func,
                                                    const GLint&                    in_ref,
                                                    const GLuint&                   in_mask)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_mask(const uint32_t& in_mask)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_mask(in_mask);
}

void OpenGL::Context::set_stencil_mask_separate(const OpenGL::StencilStateFace& in_face,
                                                const GLuint&                   in_mask)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_operations(const OpenGL::StencilOperation& in_fail,
                                             const OpenGL::StencilOperation& in_zfail,
                                             const OpenGL::StencilOperation& in_zpass)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_operations(in_fail,
                                                   in_zfail,
                                                   in_zpass);
}

void OpenGL::Context::set_stencil_operations_separate(const OpenGL::StencilStateFace& in_face,
                                                      const OpenGL::StencilOperation& in_sfail,
                                                      const OpenGL::StencilOperation& in_dpfail,
                                                      const OpenGL::StencilOperation& in_dppass)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_texture_parameter(const OpenGL::TextureTarget&      in_target,
                                            const OpenGL::TextureProperty&    in_property,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            const void*                       in_arg_value_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->set_texture_parameter(texture_id,
                                                        in_property,
                                                        in_arg_type,
                                                        in_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::set_transform_feedback_varyings(const GLuint&                              in_program,
                                                      const GLsizei&                             in_count,
                                                      const GLchar* const*                       in_varyings_ptr_ptr,
                                                      const OpenGL::TransformFeedbackBufferMode& in_buffer_mode)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_uniform(const GLint&                      in_location,
                                  const OpenGL::GetSetArgumentType& in_data_type,
                                  const uint32_t&                   in_n_components,
                                  const uint32_t&                   in_n_array_items,
                                  const void*                       in_data_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    //vkgl_not_implemented();
    
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    
    auto program_id = m_gl_state_manager_ptr->get_state()->program_proxy_reference_ptr->get_payload().id;
    
    m_backend_gl_callbacks_ptr->update_uniform_data(program_id,
    													in_location,
    													in_n_array_items,
    													in_data_ptr);
}

void OpenGL::Context::set_uniform_block_binding(const GLuint& in_program,
                                                const GLuint& in_uniform_block_index,
                                                const GLuint& in_uniform_block_binding)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_program_manager_ptr != nullptr);

    m_gl_program_manager_ptr->set_uniform_block_binding(in_program,
                                                        in_uniform_block_index,
                                                        in_uniform_block_binding);
}

bool OpenGL::Context::set_vaa_enabled_state(const GLuint& in_index,
                                            const bool&   in_new_state)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    GLuint                            bound_vao_id;
    OpenGL::TimeMarker                bound_vao_time_marker;
    bool                              result        = false;
    OpenGL::VertexAttributeArrayState vaa_state;
    OpenGL::GLBufferReferenceUniquePtr buffer_binding_ptr;

    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_gl_vao_manager_ptr   != nullptr);

    /* Retrieve properties of the VAA we're about to update.
     *
     * This is needed since there's only one setter for VAAs and all states unrelated to "enabled" state of the
     * VAA are set using a separate entrypoint.
     **/
    auto bound_vao_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();

    bound_vao_id 			= bound_vao_ptr->get_payload().id;
    bound_vao_time_marker = bound_vao_ptr->get_payload().time_marker;

    if (!m_gl_vao_manager_ptr->get_vaa_state_copy(bound_vao_id,
                                                  nullptr, /* in_opt_time_marker_ptr */
                                                  in_index,
                                                 &vaa_state) )
    {
        vkgl_assert_fail();

        goto end;
    }

	buffer_binding_ptr = std::move(vaa_state.buffer_binding_ptr);

    vaa_state.buffer_binding_ptr = std::move(buffer_binding_ptr); /* moot as per comment above */
    vaa_state.enabled            = in_new_state;
    vaa_state.integer            = vaa_state.integer;        /* moot as per comment above */
    vaa_state.normalized         = vaa_state.normalized;     /* moot as per comment above */
    vaa_state.pointer            = vaa_state.pointer;        /* moot as per comment above */
    vaa_state.size               = vaa_state.size;           /* moot as per comment above */
    vaa_state.stride             = vaa_state.stride;         /* moot as per comment above */
    vaa_state.type               = vaa_state.type;           /* moot as per comment above */

    m_gl_vao_manager_ptr->set_vaa_state(bound_vao_id,
                                        in_index,
                                        vaa_state);

    result = true;
end:
    return result;
}

void OpenGL::Context::set_vertex_attribute(const GLuint&                     in_index,
                                           const OpenGL::GetSetArgumentType& in_src_type,
                                           const OpenGL::GetSetArgumentType& in_dst_type,
                                           const uint32_t&                   in_n_components,
                                           const bool&                       in_normalized,
                                           const void*                       in_data_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::set_vertex_attrib_pointer(const GLuint&                           in_index,
                                                const GLint&                            in_size,
                                                const OpenGL::VertexAttributeArrayType& in_type,
                                                const OpenGL::GetSetArgumentType&       in_data_type,
                                                const bool&                             in_normalized,
                                                const GLsizei&                          in_stride,
                                                const void*                             in_pointer_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    GLuint                            bound_vao_id;
    OpenGL::TimeMarker                bound_vao_time_marker;
    OpenGL::VertexAttributeArrayState vaa_state;

    vkgl_assert(in_data_type           == OpenGL::GetSetArgumentType::Float ||
                in_data_type           == OpenGL::GetSetArgumentType::Int);
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_gl_vao_manager_ptr   != nullptr);

    /* Retrieve properties of the VAA we're about to update.
     *
     * This is needed since there's only one setter for VAAs and disabled/enabled state for these is set
     * using separate entrypoints.
     **/
    auto bound_vao_ptr = m_gl_state_manager_ptr->get_bound_vertex_array_object();

    bound_vao_id          = bound_vao_ptr->get_payload().id;
    bound_vao_time_marker = bound_vao_ptr->get_payload().time_marker;

    if (!m_gl_vao_manager_ptr->get_vaa_state_copy(bound_vao_id,
                                                 nullptr, /* in_opt_time_marker_ptr */
                                                  in_index,
                                                 &vaa_state) )
    {
        vkgl_assert_fail();
    }

    {
        const auto buffer_id            = m_gl_state_manager_ptr->get_bound_buffer_object                  (OpenGL::BufferTarget::Array_Buffer)->get_payload().id;
        auto       buffer_reference_ptr = m_gl_buffer_manager_ptr->acquire_current_latest_snapshot_reference(buffer_id);

        vaa_state.buffer_binding_ptr = std::move(buffer_reference_ptr);
    }

    vaa_state.enabled        = vaa_state.enabled; /* moot as per comment above */
    vaa_state.integer        = (in_data_type == OpenGL::GetSetArgumentType::Int);
    vaa_state.normalized     = in_normalized;
    vaa_state.pointer        = in_pointer_ptr;
    vaa_state.size           = in_size;
    vaa_state.stride         = in_stride;
    vaa_state.type           = in_type;

    m_gl_vao_manager_ptr->set_vaa_state(bound_vao_id,
                                        in_index,
                                        vaa_state);
}

void OpenGL::Context::set_viewport(const int32_t& in_x,
                                   const int32_t& in_y,
                                   const size_t&  in_width,
                                   const size_t&  in_height)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_viewport(in_x,
                                         in_y,
                                         in_width,
                                         in_height);
}

void OpenGL::Context::tex_buffer(const OpenGL::InternalFormat& in_internalformat,
                                 const GLuint&                 in_buffer)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                   const int32_t&                in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const int32_t&                in_width,
                                   const int32_t&                in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_gl_texture_manager_ptr->set_texture_mip_properties(texture_id,
                                                         in_level,
                                                         in_internalformat,
                                                         in_width,
                                                         1, /* in_height */
                                                         1, /* in_depth  */
                                                         in_border,
                                                         1,     /* in_n_samples              */
                                                         true); /* in_fixed_sample_locations */

    m_backend_gl_callbacks_ptr->tex_image_1d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_border,
                                             in_format,
                                             in_type,
                                             in_pixels_ptr);
}

void OpenGL::Context::tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                   const GLint&                  in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const GLsizei&                in_width,
                                   const GLsizei&                in_height,
                                   const GLint&                  in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr   != nullptr);
    vkgl_assert(m_gl_limits_ptr     		!= nullptr);

	if (in_target == OpenGL::TextureTarget::Proxy_Texture_2D 		||
		in_target == OpenGL::TextureTarget::Proxy_Texture_1D_Array ||
		in_target == OpenGL::TextureTarget::Proxy_Texture_Rectangle ||
		in_target == OpenGL::TextureTarget::Proxy_Texture_Cube_Map)
	{
        m_gl_texture_manager_ptr->set_texture_mip_properties(0,
                                                             in_level,
                                                             in_internalformat,
                                                             in_width,
                                                             in_height,
                                                             1, /* in_depth  */
                                                             in_border,
                                                             1,     /* in_n_samples              */
                                                             true); /* in_fixed_sample_locations */
	}
	else
	{
	    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
        const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                     in_target);
        
        m_gl_texture_manager_ptr->set_texture_mip_properties(texture_id,
                                                             in_level,
                                                             in_internalformat,
                                                             in_width,
                                                             in_height,
                                                             1, /* in_depth  */
                                                             in_border,
                                                             1,     /* in_n_samples              */
                                                             true); /* in_fixed_sample_locations */
    
        m_backend_gl_callbacks_ptr->tex_image_2d(texture_id,
                                                 in_level,
                                                 in_internalformat,
                                                 in_width,
                                                 in_height,
                                                 in_border,
                                                 in_format,
                                                 in_type,
                                                 in_pixels_ptr);
    }
}

void OpenGL::Context::tex_image_2d_multisample(const OpenGL::TextureTarget&  in_target,
                                               const GLsizei&                in_samples,
                                               const OpenGL::InternalFormat& in_internalformat,
                                               const GLsizei&                in_width,
                                               const GLsizei&                in_height,
                                               const bool&                   in_fixedsamplelocations)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::tex_image_3d(const OpenGL::TextureTarget&  in_target,
                                   const GLint&                  in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const GLsizei&                in_width,
                                   const GLsizei&                in_height,
                                   const GLsizei&                in_depth,
                                   const GLint&                  in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_gl_texture_manager_ptr->set_texture_mip_properties(texture_id,
                                                         in_level,
                                                         in_internalformat,
                                                         in_width,
                                                         in_height,
                                                         in_depth,
                                                         in_border,
                                                         1,     /* in_n_samples              */
                                                         true); /* in_fixed_sample_locations */

    m_backend_gl_callbacks_ptr->tex_image_3d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_height,
                                             in_depth,
                                             in_border,
                                             in_format,
                                             in_type,
                                             in_pixels_ptr);
}

void OpenGL::Context::tex_image_3d_multisample(const OpenGL::TextureTarget&  in_target,
                                               const GLsizei&                in_samples,
                                               const OpenGL::InternalFormat& in_internalformat,
                                               const GLsizei&                in_width,
                                               const GLsizei&                in_height,
                                               const GLsizei&                in_depth,
                                               const bool&                   in_fixedsamplelocations)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}

void OpenGL::Context::tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLsizei&               in_width,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->tex_sub_image_1d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_width,
                                                 in_format,
                                                 in_type,
                                                 in_pixels);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLsizei&               in_width,
                                       const GLsizei&               in_height,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->tex_sub_image_2d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_yoffset,
                                                 in_width,
                                                 in_height,
                                                 in_format,
                                                 in_type,
                                                 in_pixels);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLint&                 in_zoffset,
                                       const GLsizei&               in_width,
                                       const GLsizei&               in_height,
                                       const GLsizei&               in_depth,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
#if true
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_backend_gl_callbacks_ptr->tex_sub_image_3d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_yoffset,
                                                 in_zoffset,
                                                 in_width,
                                                 in_height,
                                                 in_depth,
                                                 in_format,
                                                 in_type,
                                                 in_pixels);
#else
    vkgl_not_implemented();
#endif
}

bool OpenGL::Context::unmap_buffer(const OpenGL::BufferTarget& in_target)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);
    vkgl_assert(m_gl_buffer_manager_ptr    != nullptr);
    vkgl_assert(m_gl_state_manager_ptr     != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_bound_buffer_object(in_target)->get_payload().id;
    vkgl_assert(buffer_id != 0);

    return m_backend_gl_callbacks_ptr->unmap_buffer(buffer_id);
}

void OpenGL::Context::use_program(const GLuint& in_program)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_gl_program_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_backend_ptr   		!= nullptr);
    
    bool result 			= false;
    auto spirv_manager_ptr = m_backend_ptr->get_spirv_manager_ptr();
    vkgl_assert(spirv_manager_ptr != nullptr);

    auto program_reference_ptr = m_gl_program_manager_ptr->acquire_current_latest_snapshot_reference(in_program);
    vkgl_assert(program_reference_ptr != nullptr);
    
    if (in_program != 0)
    {
        const OpenGL::PostLinkData* post_link_data_ptr = nullptr;
        OpenGL::SPIRVBlobID 		spirv_id 			= UINT_MAX;
        
        {
            m_gl_program_manager_ptr->get_program_post_link_data_ptr(program_reference_ptr->get_payload().id,
            																&program_reference_ptr->get_payload().time_marker,
            																&post_link_data_ptr);
            vkgl_assert(post_link_data_ptr != nullptr);
        }
        
        {
            result = spirv_manager_ptr->get_spirv_blob_id_for_program_reference(program_reference_ptr->get_payload().id,
            																program_reference_ptr->get_payload().time_marker,
            																&spirv_id);
        	vkgl_assert(result != false);
    	}
    	
    	{
        	result = spirv_manager_ptr->build_uniform_resources(spirv_id,
        													post_link_data_ptr);
        	vkgl_assert(result != false);
    	}
	}

    m_gl_program_manager_ptr->mark_id_as_alive      (in_program);
    m_gl_state_manager_ptr->set_bound_program_object(std::move(program_reference_ptr) );
}

void OpenGL::Context::validate_program(const GLuint& in_program)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_assert(m_backend_gl_callbacks_ptr != nullptr);

    m_backend_gl_callbacks_ptr->validate_program(in_program);
}

void OpenGL::Context::wait_sync(const GLsync&   in_sync,
                                const GLuint64& in_timeout)
{
    FUN_ENTRY(DEBUG_DEPTH);
    
    vkgl_not_implemented();
}
