#define NK_IMPLEMENTATION
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

#include "nuklear.h"
#include "helper.h"

struct nk_context* nk_create_context(void) {
    struct nk_context *ctx = malloc(sizeof *ctx);
    return ctx;
}

struct nk_buffer* nk_create_buffer(void) {
    struct nk_buffer *buffer = malloc(sizeof *buffer);
    return buffer;
}

struct nk_font_atlas* nk_create_font_atlas(void) {
    struct nk_font_atlas *atlas = malloc(sizeof *atlas);
    return atlas;
}

struct nk_user_font* nk_create_user_font(void) {
    struct nk_user_font *ufont = malloc(sizeof *ufont);
    return ufont;
}

void nk_delete_user_font(struct nk_user_font *ufont) {
    free(ufont);
    ufont = NULL;
}

// helper
void nk_set_clip(struct nk_context *ctx, nk_plugin_copy clipboard_copy, nk_plugin_paste clipboard_paste) {
    ctx->clip.copy = clipboard_copy;
    ctx->clip.paste = clipboard_paste;
    ctx->clip.userdata = nk_handle_ptr(0);
}

void nk_unpack_draw_command(struct nk_draw_command *cmd, unsigned int *elem_count, struct nk_rect *clip_rect, nk_handle *texture) {
    *elem_count = cmd->elem_count;
    *clip_rect = cmd->clip_rect;
    *texture = cmd->texture;
}

void nk_set_default_font(struct nk_context *ctx, struct nk_font_atlas *atlas) {
    if (atlas->default_font)
        nk_style_set_font(ctx, &atlas->default_font->handle);
}

struct nk_convert_config* nk_set_convert_config(enum nk_anti_aliasing AA, struct nk_draw_null_texture null) {
    struct nk_convert_config *config = malloc(sizeof *config);
    static const struct nk_draw_vertex_layout_element vertex_layout[] = {
        {NK_VERTEX_POSITION, NK_FORMAT_FLOAT, NK_OFFSETOF(struct nk_glfw_vertex, position)},
        {NK_VERTEX_TEXCOORD, NK_FORMAT_FLOAT, NK_OFFSETOF(struct nk_glfw_vertex, uv)},
        {NK_VERTEX_COLOR, NK_FORMAT_R8G8B8A8, NK_OFFSETOF(struct nk_glfw_vertex, col)},
        {NK_VERTEX_LAYOUT_END}
    };
    NK_MEMSET(config, 0, sizeof *config);
    config->vertex_layout = vertex_layout;
    config->vertex_size = sizeof(struct nk_glfw_vertex);
    config->vertex_alignment = NK_ALIGNOF(struct nk_glfw_vertex);
    config->null = null;
    config->circle_segment_count = 22;
    config->curve_segment_count = 22;
    config->arc_segment_count = 22;
    config->global_alpha = 1.0f;
    config->shape_AA = AA;
    config->line_AA = AA;
    return config;
}

struct nk_user_font* nk_get_font_handle(struct nk_font *font) {
    return &font->handle;
}
