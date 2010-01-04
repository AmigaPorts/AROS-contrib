### Lists of source files, included by Makefiles

AROS_STATE_TRACKER_SOURCES = \
            state_trackers/aros/arosmesa_api \
            
AROS_WINSYS_SOURCES = \
            winsys/aros/arosmesa_winsys \
            winsys/aros/arosmesa_softpipe \
            winsys/aros/arosmesa_nouveau \
            winsys/aros/arosmesa_intel \
            winsys/drm/intel/gem/intel_drm_batchbuffer \
            winsys/drm/intel/gem/intel_drm_fence \
            winsys/drm/intel/gem/intel_drm_buffer \
            
AROS_LIBDRM_SOURCES = \
            winsys/aros/drm/libdrm/nouveau/nouveau_device \
            winsys/aros/drm/libdrm/nouveau/nouveau_resource \
            winsys/aros/drm/libdrm/nouveau/nouveau_pushbuf \
            winsys/aros/drm/libdrm/nouveau/nouveau_notifier \
            winsys/aros/drm/libdrm/nouveau/nouveau_grobj \
            winsys/aros/drm/libdrm/nouveau/nouveau_channel \
            winsys/aros/drm/libdrm/nouveau/nouveau_bo \
            winsys/aros/drm/libdrm/intel/intel_bufmgr \
            winsys/aros/drm/libdrm/intel/intel_bufmgr_gem \
            winsys/aros/drm/libdrm/arosdrm \

AROS_DRM_SOURCES = \
            winsys/aros/drm/drm-aros/drm_aros \
            winsys/aros/drm/drm-aros/drm_bufs \
            winsys/aros/drm/drm-aros/drm_irq \
            winsys/aros/drm/drm-aros/drm_pci \
            winsys/aros/drm/drm-aros/drm_drv \
            winsys/aros/drm/drm-aros/drm_compat_funcs \
            winsys/aros/drm/drm-aros/nouveau/nouveau_drv \
            winsys/aros/drm/drm-aros/i915/i915_drv \
            winsys/aros/drm/drm-changed/drm_mm \
            winsys/aros/drm/drm-changed/drm_gem \
            winsys/aros/drm/drm-changed/drm_cache \
            winsys/aros/drm/drm-changed/drm_memory \
            winsys/aros/drm/drm-changed/drm_agpsupport \
            winsys/aros/drm/drm-changed/nouveau/nouveau_state \
            winsys/aros/drm/drm-changed/nouveau/nouveau_mem \
            winsys/aros/drm/drm-changed/nouveau/nouveau_fence \
            winsys/aros/drm/drm-changed/nouveau/nouveau_sgdma \
            winsys/aros/drm/drm-changed/nouveau/nouveau_ttm \
            winsys/aros/drm/drm-changed/nouveau/nouveau_irq \
            winsys/aros/drm/drm-changed/nouveau/nv50_instmem \
            winsys/aros/drm/drm-changed/nouveau/nv50_display \
            winsys/aros/drm/drm-changed/i915/i915_dma \
            winsys/aros/drm/drm-changed/i915/i915_gem \
            winsys/aros/drm/drm-changed/i915/i915_gem_tiling \
            winsys/aros/drm/drm-changed/i915/i915_irq \
            winsys/aros/drm/drm-changed/i915/i915_mem \
            winsys/aros/drm/drm-changed/ttm/ttm_global \
            winsys/aros/drm/drm-changed/ttm/ttm_bo \
            winsys/aros/drm/drm-changed/ttm/ttm_bo_util \
            winsys/aros/drm/drm-changed/ttm/ttm_tt \
            winsys/aros/drm/drm-changed/ttm/ttm_agp_backend \
            winsys/aros/drm/drm-unchanged/nouveau/nouveau_channel_renamed \
            winsys/aros/drm/drm-unchanged/nouveau/nouveau_bo_renamed \
            winsys/aros/drm/drm-unchanged/nouveau/nouveau_dma \
            winsys/aros/drm/drm-unchanged/nouveau/nouveau_object \
            winsys/aros/drm/drm-unchanged/nouveau/nouveau_notifier_renamed \
            winsys/aros/drm/drm-unchanged/nouveau/nouveau_gem \
            winsys/aros/drm/drm-unchanged/nouveau/nv04_fb \
            winsys/aros/drm/drm-unchanged/nouveau/nv04_fifo \
            winsys/aros/drm/drm-unchanged/nouveau/nv04_graph \
            winsys/aros/drm/drm-unchanged/nouveau/nv04_instmem \
            winsys/aros/drm/drm-unchanged/nouveau/nv04_mc \
            winsys/aros/drm/drm-unchanged/nouveau/nv04_timer \
            winsys/aros/drm/drm-unchanged/nouveau/nv10_fb \
            winsys/aros/drm/drm-unchanged/nouveau/nv10_fifo \
            winsys/aros/drm/drm-unchanged/nouveau/nv10_graph \
            winsys/aros/drm/drm-unchanged/nouveau/nv20_graph \
            winsys/aros/drm/drm-unchanged/nouveau/nv40_fb \
            winsys/aros/drm/drm-unchanged/nouveau/nv40_fifo \
            winsys/aros/drm/drm-unchanged/nouveau/nv40_graph \
            winsys/aros/drm/drm-unchanged/nouveau/nv40_mc \
            winsys/aros/drm/drm-unchanged/nouveau/nv50_fifo \
            winsys/aros/drm/drm-unchanged/nouveau/nv50_mc \
            winsys/aros/drm/drm-unchanged/nouveau/nv50_graph \

AROS_DRM_OLD_SOURCES = \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_resource \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_grobj \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_pushbuf \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_fence \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_dma \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_notifier \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_bo \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_channel \
            winsys/aros/libdrm/libdrm/nouveau/nouveau_device \
            winsys/aros/libdrm/libdrm/arosdrm \
            winsys/aros/libdrm/aros-core/nouveau_state \
            winsys/aros/libdrm/aros-core/nouveau_object \
            winsys/aros/libdrm/aros-core/nouveau_mem \
            winsys/aros/libdrm/aros-core/nouveau_backlight \
            winsys/aros/libdrm/aros-core/nouveau_sgdma \
            winsys/aros/libdrm/aros-core/drm_nouveau_dma \
            winsys/aros/libdrm/aros-core/drm_nouveau_notifier \
            winsys/aros/libdrm/aros-core/drm_memory \
            winsys/aros/libdrm/aros-core/drm_irq \
            winsys/aros/libdrm/aros-core/drm_bufs \
            winsys/aros/libdrm/aros-core/drm_aros \
            winsys/aros/libdrm/aros-core/drm_scatter \
            winsys/aros/libdrm/aros-core/drm_drv \
            winsys/aros/libdrm/aros-core/nv50_instmem \
            winsys/aros/libdrm/aros-core/nouveau_drv \
            winsys/aros/libdrm/shared-core/nv04_fifo \
            winsys/aros/libdrm/shared-core/nv10_fifo \
            winsys/aros/libdrm/shared-core/nv40_fifo \
            winsys/aros/libdrm/shared-core/nv50_fifo \
            winsys/aros/libdrm/shared-core/nv04_graph \
            winsys/aros/libdrm/shared-core/nv10_graph \
            winsys/aros/libdrm/shared-core/nv20_graph \
            winsys/aros/libdrm/shared-core/nv40_graph \
            winsys/aros/libdrm/shared-core/nv50_graph \
            winsys/aros/libdrm/shared-core/nv04_fb \
            winsys/aros/libdrm/shared-core/nv10_fb \
            winsys/aros/libdrm/shared-core/nv40_fb \
            winsys/aros/libdrm/shared-core/nv04_instmem \
            winsys/aros/libdrm/shared-core/nv04_timer \
            winsys/aros/libdrm/shared-core/nv04_mc \
            winsys/aros/libdrm/shared-core/nv40_mc \
            winsys/aros/libdrm/shared-core/nv50_mc \
            winsys/aros/libdrm/shared-core/nouveau_irq \
            winsys/aros/libdrm/shared-core/nouveau_swmthd \
            winsys/aros/libdrm/shared-core/nouveau_fifo \

GALLIUM_AUXILIARY_SOURCES = \
            auxiliary/util/u_debug \
            auxiliary/util/u_debug_symbol \
            auxiliary/util/u_debug_stack \
            auxiliary/util/u_blit \
            auxiliary/util/u_cache \
            auxiliary/util/u_draw_quad \
            auxiliary/util/u_gen_mipmap \
            auxiliary/util/u_handle_table \
            auxiliary/util/u_hash_table \
            auxiliary/util/u_hash \
            auxiliary/util/u_keymap \
            auxiliary/util/u_linear \
            auxiliary/util/u_mm \
            auxiliary/util/u_rect \
            auxiliary/util/u_simple_shaders \
            auxiliary/util/u_snprintf \
            auxiliary/util/u_stream_stdc \
            auxiliary/util/u_stream_wd \
            auxiliary/util/u_surface \
            auxiliary/util/u_tile \
            auxiliary/util/u_timed_winsys \
            auxiliary/util/u_upload_mgr \
            auxiliary/util/u_simple_screen \
            auxiliary/draw/draw_context \
            auxiliary/draw/draw_pipe \
            auxiliary/draw/draw_pipe_aaline \
            auxiliary/draw/draw_pipe_aapoint \
            auxiliary/draw/draw_pipe_cull \
            auxiliary/draw/draw_pipe_flatshade \
            auxiliary/draw/draw_pipe_offset \
            auxiliary/draw/draw_pipe_pstipple \
            auxiliary/draw/draw_pipe_stipple \
            auxiliary/draw/draw_pipe_twoside \
            auxiliary/draw/draw_pipe_unfilled \
            auxiliary/draw/draw_pipe_util \
            auxiliary/draw/draw_pipe_validate \
            auxiliary/draw/draw_pipe_vbuf \
            auxiliary/draw/draw_pipe_wide_line \
            auxiliary/draw/draw_pipe_wide_point \
            auxiliary/draw/draw_pt \
            auxiliary/draw/draw_pt_elts \
            auxiliary/draw/draw_pt_emit \
            auxiliary/draw/draw_pt_fetch \
            auxiliary/draw/draw_pt_fetch_emit \
            auxiliary/draw/draw_pt_fetch_shade_emit \
            auxiliary/draw/draw_pt_fetch_shade_pipeline \
            auxiliary/draw/draw_pt_post_vs \
            auxiliary/draw/draw_pt_util \
            auxiliary/draw/draw_pt_varray \
            auxiliary/draw/draw_pt_vcache \
            auxiliary/draw/draw_vertex \
            auxiliary/draw/draw_vs \
            auxiliary/draw/draw_vs_varient \
            auxiliary/draw/draw_vs_aos \
            auxiliary/draw/draw_vs_aos_io \
            auxiliary/draw/draw_vs_aos_machine \
            auxiliary/draw/draw_vs_exec \
            auxiliary/draw/draw_vs_llvm \
            auxiliary/draw/draw_vs_ppc  \
            auxiliary/draw/draw_vs_sse  \
            auxiliary/tgsi/tgsi_sanity \
            auxiliary/tgsi/tgsi_build \
            auxiliary/tgsi/tgsi_dump \
            auxiliary/tgsi/tgsi_exec \
            auxiliary/tgsi/tgsi_info \
            auxiliary/tgsi/tgsi_iterate \
            auxiliary/tgsi/tgsi_parse \
            auxiliary/tgsi/tgsi_ppc \
            auxiliary/tgsi/tgsi_scan \
            auxiliary/tgsi/tgsi_sse2 \
            auxiliary/tgsi/tgsi_text \
            auxiliary/tgsi/tgsi_transform \
            auxiliary/tgsi/tgsi_ureg \
            auxiliary/tgsi/tgsi_util \
            auxiliary/rtasm/rtasm_cpu \
            auxiliary/rtasm/rtasm_execmem \
            auxiliary/rtasm/rtasm_x86sse \
            auxiliary/rtasm/rtasm_ppc \
            auxiliary/rtasm/rtasm_ppc_spe \
            auxiliary/translate/translate_generic \
            auxiliary/translate/translate_sse \
            auxiliary/translate/translate \
            auxiliary/translate/translate_cache \
            auxiliary/cso_cache/cso_context \
            auxiliary/cso_cache/cso_cache \
            auxiliary/cso_cache/cso_hash \
            auxiliary/draw/draw_pipe_clip \
            auxiliary/util/u_math \
            auxiliary/util/u_time \

GALLIUM_SOFTPIPE_SOURCES = \
            drivers/softpipe/sp_fs_exec \
            drivers/softpipe/sp_fs_sse \
            drivers/softpipe/sp_clear \
            drivers/softpipe/sp_flush \
            drivers/softpipe/sp_query \
            drivers/softpipe/sp_context \
            drivers/softpipe/sp_draw_arrays \
            drivers/softpipe/sp_prim_vbuf \
            drivers/softpipe/sp_quad_pipe \
            drivers/softpipe/sp_quad_blend \
            drivers/softpipe/sp_quad_depth_test \
            drivers/softpipe/sp_quad_fs \
            drivers/softpipe/sp_quad_stipple \
            drivers/softpipe/sp_screen \
            drivers/softpipe/sp_setup \
            drivers/softpipe/sp_state_blend \
            drivers/softpipe/sp_state_clip \
            drivers/softpipe/sp_state_derived \
            drivers/softpipe/sp_state_fs \
            drivers/softpipe/sp_state_sampler \
            drivers/softpipe/sp_state_rasterizer \
            drivers/softpipe/sp_state_surface \
            drivers/softpipe/sp_state_vertex \
            drivers/softpipe/sp_texture \
            drivers/softpipe/sp_tex_sample \
            drivers/softpipe/sp_tile_cache \
            drivers/softpipe/sp_tex_tile_cache \
            drivers/softpipe/sp_surface

GALLIUM_NVIDIA_SOURCES = \
            drivers/nouveau/nouveau_screen \
            drivers/nouveau/nouveau_context \
            drivers/nv40/nv40_clear \
            drivers/nv40/nv40_context \
            drivers/nv40/nv40_draw \
            drivers/nv40/nv40_fragprog \
            drivers/nv40/nv40_fragtex \
            drivers/nv40/nv40_miptree \
            drivers/nv40/nv40_query \
            drivers/nv40/nv40_screen \
            drivers/nv40/nv40_state \
            drivers/nv40/nv40_state_blend \
            drivers/nv40/nv40_state_emit \
            drivers/nv40/nv40_state_fb \
            drivers/nv40/nv40_state_rasterizer \
            drivers/nv40/nv40_state_scissor \
            drivers/nv40/nv40_state_stipple \
            drivers/nv40/nv40_state_viewport \
            drivers/nv40/nv40_state_zsa \
            drivers/nv40/nv40_surface \
            drivers/nv40/nv40_transfer \
            drivers/nv40/nv40_vbo \
            drivers/nv40/nv40_vertprog \
            drivers/nv04/nv04_surface_2d \
            drivers/nv04/nv04_clear \
            drivers/nv04/nv04_context \
            drivers/nv04/nv04_fragprog \
            drivers/nv04/nv04_fragtex \
            drivers/nv04/nv04_miptree \
            drivers/nv04/nv04_prim_vbuf \
            drivers/nv04/nv04_screen \
            drivers/nv04/nv04_state \
            drivers/nv04/nv04_state_emit \
            drivers/nv04/nv04_surface \
            drivers/nv04/nv04_transfer \
            drivers/nv04/nv04_vbo \
            drivers/nv20/nv20_clear \
            drivers/nv20/nv20_context \
            drivers/nv20/nv20_fragprog \
            drivers/nv20/nv20_fragtex \
            drivers/nv20/nv20_miptree \
            drivers/nv20/nv20_prim_vbuf \
            drivers/nv20/nv20_screen \
            drivers/nv20/nv20_state \
            drivers/nv20/nv20_state_emit \
            drivers/nv20/nv20_surface \
            drivers/nv20/nv20_transfer \
            drivers/nv20/nv20_vbo \
            drivers/nv10/nv10_clear \
            drivers/nv10/nv10_context \
            drivers/nv10/nv10_fragprog \
            drivers/nv10/nv10_fragtex \
            drivers/nv10/nv10_miptree \
            drivers/nv10/nv10_prim_vbuf \
            drivers/nv10/nv10_screen \
            drivers/nv10/nv10_state \
            drivers/nv10/nv10_state_emit \
            drivers/nv10/nv10_surface \
            drivers/nv10/nv10_transfer \
            drivers/nv10/nv10_vbo \
            drivers/nv30/nv30_clear \
            drivers/nv30/nv30_context \
            drivers/nv30/nv30_draw \
            drivers/nv30/nv30_fragprog \
            drivers/nv30/nv30_fragtex \
            drivers/nv30/nv30_miptree \
            drivers/nv30/nv30_query \
            drivers/nv30/nv30_screen \
            drivers/nv30/nv30_state \
            drivers/nv30/nv30_state_blend \
            drivers/nv30/nv30_state_emit \
            drivers/nv30/nv30_state_fb \
            drivers/nv30/nv30_state_rasterizer \
            drivers/nv30/nv30_state_scissor \
            drivers/nv30/nv30_state_stipple \
            drivers/nv30/nv30_state_viewport \
            drivers/nv30/nv30_state_zsa \
            drivers/nv30/nv30_surface \
            drivers/nv30/nv30_transfer \
            drivers/nv30/nv30_vbo \
            drivers/nv30/nv30_vertprog \
            drivers/nv50/nv50_clear \
            drivers/nv50/nv50_context \
            drivers/nv50/nv50_draw \
            drivers/nv50/nv50_miptree \
            drivers/nv50/nv50_query \
            drivers/nv50/nv50_program \
            drivers/nv50/nv50_screen \
            drivers/nv50/nv50_state \
            drivers/nv50/nv50_state_validate \
            drivers/nv50/nv50_tex \
            drivers/nv50/nv50_vbo \
            drivers/nv50/nv50_surface \
            drivers/nv50/nv50_transfer \

GALLIUM_I915_SOURCES = \
            drivers/i915/i915_blit \
            drivers/i915/i915_buffer \
            drivers/i915/i915_clear \
            drivers/i915/i915_context \
            drivers/i915/i915_debug \
            drivers/i915/i915_debug_fp \
            drivers/i915/i915_flush \
            drivers/i915/i915_fpc_emit \
            drivers/i915/i915_fpc_translate \
            drivers/i915/i915_prim_emit \
            drivers/i915/i915_prim_vbuf \
            drivers/i915/i915_screen \
            drivers/i915/i915_state \
            drivers/i915/i915_state_derived \
            drivers/i915/i915_state_dynamic \
            drivers/i915/i915_state_emit \
            drivers/i915/i915_state_immediate \
            drivers/i915/i915_state_sampler \
            drivers/i915/i915_surface \
            drivers/i915/i915_texture \
            
AROS_GALLIUM_SOURCES = \
            $(AROS_STATE_TRACKER_SOURCES) \
            $(AROS_WINSYS_SOURCES) \
            $(AROS_LIBDRM_SOURCES) \
            $(AROS_DRM_SOURCES) \
            $(GALLIUM_AUXILIARY_SOURCES) \
            $(GALLIUM_SOFTPIPE_SOURCES) \
            $(GALLIUM_NVIDIA_SOURCES) \
            $(GALLIUM_I915_SOURCES) \
