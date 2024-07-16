#pragma once

#include "imgui.h"

namespace c {

    namespace other
    {
        
        inline ImVec4 main_purple;
        inline ImVec4 color_black = ImColor(77, 77, 77, 255);
        inline ImVec4 low_color = ImColor(255, 255, 255, 0);
        inline ImVec4 text_purple = ImColor(205, 216, 255, 255);
        inline ImVec4 text_purple_no_active = ImColor(83, 83, 83, 255);
        inline ImVec4 background_color = ImColor(100, 100, 100, 255);

        inline ImVec4 backgroud;
        inline ImVec4 line;
        inline ImVec4 line_tab = ImColor(78, 78, 78, 58);
    }

    inline ImVec4 accent_color = ImColor(140, 0, 255, 255);
    inline ImVec4 accent_color_inact = ImColor(75, 75, 90, 255);

    namespace bg
    {
        inline ImVec4 rect;
        inline ImVec4 background = ImColor(27, 28, 34, 140);
        inline ImVec4 multicolor_tab;
        inline ImVec4 multicolor_tab1;
        inline ImVec2 size = ImVec2(60, 590);
        inline float rounding = 10.f;
        inline ImVec4 text;
    }

    namespace child
    {
        inline ImVec4 background;
        inline ImVec4 background_rect;
        inline ImVec4 rect = ImColor(75, 75, 90, 255);
        inline float rounding = 6.f;
    }

    namespace checkbox
    {
        inline ImVec4 background_active = ImColor(0, 255, 208, 80);
        inline ImVec4 background_inactive = ImColor(58, 63, 70, 80);
        inline ImVec4 color_background_active = ImColor(0, 255, 208, 80);
        inline ImVec4 rects;
        inline ImVec4 circle_active = ImColor(255, 255, 255, 255);
        inline ImVec4 circle_inactive = ImColor(140, 0, 255, 255);
        inline ImVec4 circle_outline = ImColor(42, 45, 51, 255);

        inline ImVec4 circle_shadow_activ = ImColor(0, 255, 208, 255);
        inline ImVec4 circle_shadow_inactiv = ImColor(140, 0, 255, 255);
        inline float rounding = 30.f;
    }

    namespace slider
    {
        inline ImVec4 background_active;
        inline ImVec4 background_inactive = ImColor(43, 43, 43, 199);
        inline ImVec4 circle_active;
        inline ImVec4 circle_active_inactive = ImColor(58, 58, 58, 255);
    }

    namespace tab
    {
        inline ImVec4 background = ImColor(27, 30, 45, 215);
        inline ImVec4 background_inactive = ImColor(27, 30, 45, 0);
        inline ImVec4 image_inactive = ImColor(255, 255, 255, 255);
        inline ImVec4 image_combo = ImColor(75, 75, 90, 255);
        inline ImVec4 line_inactive = ImColor(104, 114, 129, 0);
        inline ImVec4 circle_user = ImColor(114, 19, 42, 200);

        inline ImVec4 text_active = ImColor(200, 200, 200, 200);
        inline ImVec4 text_hov = ImColor(200, 200, 200, 200);
        inline ImVec4 text = ImColor(255, 255, 255, 255);


    }

    namespace combo
    {
        inline ImVec4 background_inactive;

        inline float rounding = 2.f;
    }

    namespace keybind
    {
        inline ImVec4 background_inactive = ImColor(58, 63, 70, 80);

        inline float rounding = 2.f;
    }

    namespace picker
    {
        inline ImVec4 background_inactive;
        inline float rounding = 2.f;
    }

    namespace button
    {
        inline ImVec4 background_active = ImColor(37, 37, 37, 255);
        inline ImVec4 background_inactive = ImColor(58, 63, 70, 80);

        inline float rounding = 2.f;
    }

    namespace input
    {
        inline ImVec4 cursor;
        inline ImVec4 background_active;
        inline ImVec4 rect = ImColor(43, 43, 43, 255);
        inline ImVec4 text_inactive = ImColor(83, 83, 83, 255);
        inline ImVec4 text;
        inline ImVec4 line;
        inline ImVec4 line_in;
        inline ImVec4 icon = ImColor(83, 83, 83, 255);
        inline float rounding = 2.f;
    }

    namespace text
    {
        inline ImVec4 text_black = ImColor(255, 255, 255, 255);
        inline ImVec4 texts;
        inline ImVec4 text_active = ImColor(255, 255, 255, 255);
        inline ImVec4 text_hov = ImColor(121, 130, 144, 255);
        inline ImVec4 text = ImColor(91, 100, 114, 255);
        inline ImVec4 text_1 = ImColor(91, 100, 114, 0);
        inline ImVec4 text_hide = ImColor(0, 0, 0, 0);
    }

}
