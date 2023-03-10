#pragma once
#include <array>
#include <gl/GL.h>

// prepared by Artiom Drankevich (archql)

// https://cloford.com/resources/colours/namedcol.htm
// ([a-z]+)\*?[\t ]+[a-z]+\*?[\t ]+#[0-9A-Z]+[\t ]+([0-9]+)[\t ]+([0-9]+)[\t ]+([0-9]+)[\t ]+([0-9]+)$
// $1 = { $2, $3, $4 };

// openGL usage:
// use it as glColorubv(NamedColorTable::NAME);

class NamedColorTable {
    using color = GLubyte[3];
public:
    static constexpr color lightpink = { 255, 182, 193 };
    static constexpr color pink = { 255, 192, 203 };
    static constexpr color crimson = { 220, 20, 60 };
    static constexpr color lavenderblush = { 255, 240, 245 };
    static constexpr color palevioletred = { 219, 112, 147 };
    static constexpr color hotpink = { 255, 105, 180 };
    static constexpr color deeppink = { 255, 20, 147 };
    static constexpr color mediumvioletred = { 199, 21, 133 };
    static constexpr color orchid = { 218, 112, 214 };
    static constexpr color thistle = { 216, 191, 216 };
    static constexpr color plum = { 221, 160, 221 };
    static constexpr color violet = { 238, 130, 238 };
    static constexpr color fuchsia = { 255, 0, 255 };
    //static constexpr color fuchsia = { 255, 0, 255 };
    static constexpr color darkmagenta = { 139, 0, 139 };
    static constexpr color purple = { 128, 0, 128 };
    static constexpr color mediumorchid = { 186, 85, 211 };
    static constexpr color darkviolet = { 148, 0, 211 };
    static constexpr color darkorchid = { 153, 50, 204 };
    static constexpr color indigo = { 75, 0, 130 };
    static constexpr color blueviolet = { 138, 43, 226 };
    static constexpr color mediumpurple = { 147, 112, 219 };
    static constexpr color mediumslateblue = { 123, 104, 238 };
    static constexpr color slateblue = { 106, 90, 205 };
    static constexpr color darkslateblue = { 72, 61, 139 };
    static constexpr color ghostwhite = { 248, 248, 255 };
    static constexpr color lavender = { 230, 230, 250 };
    static constexpr color blue = { 0, 0, 255 };
    static constexpr color mediumblue = { 0, 0, 205 };
    static constexpr color darkblue = { 0, 0, 139 };
    static constexpr color navy = { 0, 0, 128 };
    static constexpr color midnightblue = { 25, 25, 112 };
    static constexpr color royalblue = { 65, 105, 225 };
    static constexpr color cornflowerblue = { 100, 149, 237 };
    static constexpr color lightsteelblue = { 176, 196, 222 };
    static constexpr color lightslategray = { 119, 136, 153 };
    static constexpr color slategray = { 112, 128, 144 };
    static constexpr color dodgerblue = { 30, 144, 255 };
    static constexpr color aliceblue = { 240, 248, 255 };
    static constexpr color steelblue = { 70, 130, 180 };
    static constexpr color lightskyblue = { 135, 206, 250 };
    static constexpr color skyblue = { 135, 206, 235 };
    static constexpr color deepskyblue = { 0, 191, 255 };
    static constexpr color lightblue = { 173, 216, 230 };
    static constexpr color powderblue = { 176, 224, 230 };
    static constexpr color cadetblue = { 95, 158, 160 };
    static constexpr color darkturquoise = { 0, 206, 209 };
    static constexpr color azure = { 240, 255, 255 };
    static constexpr color lightcyan = { 224, 255, 255 };
    static constexpr color paleturquoise = { 175, 238, 238 };
    static constexpr color aqua = { 0, 255, 255 };
    //static constexpr color aqua = { 0, 255, 255 };
    static constexpr color darkcyan = { 0, 139, 139 };
    static constexpr color teal = { 0, 128, 128 };
    static constexpr color darkslategray = { 47, 79, 79 };
    static constexpr color mediumturquoise = { 72, 209, 204 };
    static constexpr color lightseagreen = { 32, 178, 170 };
    static constexpr color turquoise = { 64, 224, 208 };
    static constexpr color aquamarine = { 127, 255, 212 };
    static constexpr color mediumaquamarine = { 102, 205, 170 };
    static constexpr color mediumspringgreen = { 0, 250, 154 };
    static constexpr color mintcream = { 245, 255, 250 };
    static constexpr color springgreen = { 0, 255, 127 };
    static constexpr color mediumseagreen = { 60, 179, 113 };
    static constexpr color seagreen = { 46, 139, 87 };
    static constexpr color honeydew = { 240, 255, 240 };
    static constexpr color darkseagreen = { 143, 188, 143 };
    static constexpr color palegreen = { 152, 251, 152 };
    static constexpr color lightgreen = { 144, 238, 144 };
    static constexpr color limegreen = { 50, 205, 50 };
    static constexpr color lime = { 0, 255, 0 };
    static constexpr color forestgreen = { 34, 139, 34 };
    static constexpr color green = { 0, 128, 0 };
    static constexpr color darkgreen = { 0, 100, 0 };
    static constexpr color lawngreen = { 124, 252, 0 };
    static constexpr color chartreuse = { 127, 255, 0 };
    static constexpr color greenyellow = { 173, 255, 47 };
    static constexpr color darkolivegreen = { 85, 107, 47 };
    static constexpr color yellowgreen = { 154, 205, 50 };
    static constexpr color olivedrab = { 107, 142, 35 };
    static constexpr color ivory = { 255, 255, 240 };
    static constexpr color beige = { 245, 245, 220 };
    static constexpr color lightyellow = { 255, 255, 224 };
    static constexpr color lightgoldenrodyellow = { 250, 250, 210 };
    static constexpr color yellow = { 255, 255, 0 };
    static constexpr color olive = { 128, 128, 0 };
    static constexpr color darkkhaki = { 189, 183, 107 };
    static constexpr color palegoldenrod = { 238, 232, 170 };
    static constexpr color lemonchiffon = { 255, 250, 205 };
    static constexpr color khaki = { 240, 230, 140 };
    static constexpr color gold = { 255, 215, 0 };
    static constexpr color cornsilk = { 255, 248, 220 };
    static constexpr color goldenrod = { 218, 165, 32 };
    static constexpr color darkgoldenrod = { 184, 134, 11 };
    static constexpr color floralwhite = { 255, 250, 240 };
    static constexpr color oldlace = { 253, 245, 230 };
    static constexpr color wheat = { 245, 222, 179 };
    static constexpr color orange = { 255, 165, 0 };
    static constexpr color moccasin = { 255, 228, 181 };
    static constexpr color papayawhip = { 255, 239, 213 };
    static constexpr color blanchedalmond = { 255, 235, 205 };
    static constexpr color navajowhite = { 255, 222, 173 };
    static constexpr color antiquewhite = { 250, 235, 215 };
    static constexpr color tan = { 210, 180, 140 };
    static constexpr color burlywood = { 222, 184, 135 };
    static constexpr color darkorange = { 255, 140, 0 };
    static constexpr color bisque = { 255, 228, 196 };
    static constexpr color linen = { 250, 240, 230 };
    static constexpr color peru = { 205, 133, 63 };
    static constexpr color peachpuff = { 255, 218, 185 };
    static constexpr color sandybrown = { 244, 164, 96 };
    static constexpr color chocolate = { 210, 105, 30 };
    static constexpr color saddlebrown = { 139, 69, 19 };
    static constexpr color seashell = { 255, 245, 238 };
    static constexpr color sienna = { 160, 82, 45 };
    static constexpr color lightsalmon = { 255, 160, 122 };
    static constexpr color coral = { 255, 127, 80 };
    static constexpr color orangered = { 255, 69, 0 };
    static constexpr color darksalmon = { 233, 150, 122 };
    static constexpr color tomato = { 255, 99, 71 };
    static constexpr color salmon = { 250, 128, 114 };
    static constexpr color mistyrose = { 255, 228, 225 };
    static constexpr color lightcoral = { 240, 128, 128 };
    static constexpr color snow = { 255, 250, 250 };
    static constexpr color rosybrown = { 188, 143, 143 };
    static constexpr color indianred = { 205, 92, 92 };
    static constexpr color red = { 255, 0, 0 };
    static constexpr color brown = { 165, 42, 42 };
    static constexpr color firebrick = { 178, 34, 34 };
    static constexpr color darkred = { 139, 0, 0 };
    static constexpr color maroon = { 128, 0, 0 };
    static constexpr color white = { 255, 255, 255 };
    static constexpr color whitesmoke = { 245, 245, 245 };
    static constexpr color gainsboro = { 220, 220, 220 };
    static constexpr color lightgrey = { 211, 211, 211 };
    static constexpr color silver = { 192, 192, 192 };
    static constexpr color darkgray = { 169, 169, 169 };
    static constexpr color gray = { 128, 128, 128 };
    static constexpr color dimgray = { 105, 105, 105 };
    static constexpr color black = { 0, 0, 0 };

};