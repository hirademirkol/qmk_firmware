RGB_MATRIX_EFFECT(LINE_EFFECT)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV LINE_EFFECT_math(HSV hsv, uint16_t offset) {
    hsv.h = scale16by8(g_rgb_timer, add8(rgb_matrix_config.speed, 1) >> 6);
    hsv.v = scale8(255 - (offset << 1), hsv.v);
    return hsv;
}

static bool LINE_EFFECT(effect_params_t* params) {
    return effect_runner_reactive(params, &LINE_EFFECT_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS