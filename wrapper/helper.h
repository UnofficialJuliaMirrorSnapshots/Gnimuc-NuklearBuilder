struct nk_glfw_vertex {
    float position[2];
    float uv[2];
    nk_byte col[4];
};

NK_API struct nk_context* nk_create_context(void);
NK_API struct nk_buffer* nk_create_buffer(void);
NK_API struct nk_font_atlas* nk_create_font_atlas(void);

NK_API struct nk_user_font* nk_create_user_font(void);
NK_API void nk_delete_user_font(struct nk_user_font* ufont);

// helper
NK_API void nk_set_clip(struct nk_context *ctx, nk_plugin_copy clipboard_copy, nk_plugin_paste clipboard_paste);
NK_API void nk_set_default_font(struct nk_context *ctx, struct nk_font_atlas *atlas);
NK_API struct nk_convert_config* nk_set_convert_config(enum nk_anti_aliasing AA, struct nk_draw_null_texture null);
NK_API void nk_unpack_draw_command(struct nk_draw_command *cmd, unsigned int *elem_count, struct nk_rect *clip_rect, nk_handle *texture);
NK_API struct nk_user_font* nk_get_font_handle(struct nk_font *font);
