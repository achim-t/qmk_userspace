# markstos: enable media keys
# EXTRAKEY_ENABLE = yes

# markstos: smaller file size, little down-side
LTO_ENABLE = yes

COMBO_ENABLE = no

# This is for RGB *underglow*
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

#VIA_ENABLE      = yes    # Enable VIA
OLED_ENABLE     = yes
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = no
REPEAT_KEY_ENABLE = yes

SRC += features/flow.c 
SRC += features/layer_lock.c