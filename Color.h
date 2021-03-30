#ifndef COLOR_H
#define COLOR_H



typedef struct {
    float rgba[4];
} Color;


namespace Colors {
    const Color WHITE = {1, 1, 1, 1};
    const Color BLACK = {0, 0, 0, 0};
    const Color RED = {1, 0, 0, 1};
    const Color GREEN = {0, 1, 0, 1};
    const Color BLUE = {0, 0, 1, 1};
    const Color SKY_BLUE = {0.529, 0.808, 0.922, 1};
    const Color SILVER = {0.6, 0.6, 0.6, 1};
    const Color LIGHT_GREY = {0.4, 0.4, 0.4, 1};
    const Color DARK_GREY = {0.125, 0.125, 0.125, 1};
    const Color BROWN = {0.75390625, 0.6015625, 0.41796875, 1};

}

#endif 