#pragma once
#include "imgui_internal.h"
#include "settings.h"
#include <D3D11.h>

int boneSelected = 0;
int boxSelected = 0;

const char* boneItems[5]{ "Head", "Neck", "Torso", "Penis", "Foot" };

const char* boxItems[5]{ "2D Box", "3D Box", "Filled", "Corner" };

static int iTheme = 0;
void CustomStyleColor() // Отрисовка цветов
{
    ImGuiStyle& s = ImGui::GetStyle();
    ImGuiContext& g = *GImGui;

    if (iTheme == 0)
    {
        s.Colors[ImGuiCol_WindowBg] = ImLerp(s.Colors[ImGuiCol_WindowBg], iTheme == 0 ? ImColor(22, 22, 22, 255) : ImColor(22, 22, 22, 255), g.IO.DeltaTime * 5.f);
        s.Colors[ImGuiCol_ChildBg] = ImLerp(s.Colors[ImGuiCol_ChildBg], iTheme == 0 ? ImColor(29, 29, 29, 255) : ImColor(29, 29, 29, 255), g.IO.DeltaTime * 5.f);
        c::other::main_purple = ImLerp(c::other::main_purple, iTheme == 0 ? ImColor(200, 200, 0, 255) : ImColor(200, 200, 0, 255), g.IO.DeltaTime * 5.f);
        c::other::text_purple = ImLerp(c::other::text_purple, iTheme == 0 ? ImColor(205, 216, 0, 255) : ImColor(205, 216, 0, 255), g.IO.DeltaTime * 5.f);
        c::bg::rect = ImLerp(c::bg::rect, iTheme == 0 ? ImColor(43, 43, 43, 255) : ImColor(43, 43, 43, 255), g.IO.DeltaTime * 5.f);
        c::other::backgroud = ImLerp(c::other::backgroud, iTheme == 0 ? ImColor(29, 29, 29, 255) : ImColor(29, 29, 29, 255), g.IO.DeltaTime * 5.f);
        c::bg::multicolor_tab = ImLerp(c::bg::multicolor_tab, iTheme == 0 ? ImColor(200, 200, 0, 255) : ImColor(200, 200, 0, 255), g.IO.DeltaTime * 5.f);
        c::bg::multicolor_tab1 = ImLerp(c::bg::multicolor_tab1, iTheme == 0 ? ImColor(48, 45, 46, 51) : ImColor(48, 45, 46, 51), g.IO.DeltaTime * 5.f);
        c::other::line = ImLerp(c::other::line, iTheme == 0 ? ImColor(200, 200, 0, 255) : ImColor(200, 200, 0, 255), g.IO.DeltaTime * 5.f);
        c::checkbox::background_active = ImLerp(c::checkbox::background_active, iTheme == 0 ? ImColor(205, 216, 0, 255) : ImColor(205, 216, 0, 255), g.IO.DeltaTime * 5.f);
        c::checkbox::background_inactive = ImLerp(c::checkbox::background_inactive, iTheme == 0 ? ImColor(43, 43, 43, 59) : ImColor(43, 43, 43, 59), g.IO.DeltaTime * 5.f);
        c::checkbox::rects = ImLerp(c::checkbox::rects, iTheme == 0 ? ImColor(43, 43, 43, 255) : ImColor(43, 43, 43, 255), g.IO.DeltaTime * 5.f);
        c::bg::text = ImLerp(c::bg::text, iTheme == 0 ? ImColor(196, 209, 250, 255) : ImColor(196, 209, 250, 255), g.IO.DeltaTime * 5.f);
        c::input::background_active = ImLerp(c::input::background_active, iTheme == 0 ? ImColor(27, 27, 27, 255) : ImColor(27, 27, 27, 255), g.IO.DeltaTime * 5.f);
        c::slider::background_active = ImLerp(c::slider::background_active, iTheme == 0 ? ImColor(205, 216, 0, 199) : ImColor(205, 216, 0, 199), g.IO.DeltaTime * 5.f);
        c::slider::circle_active = ImLerp(c::slider::circle_active, iTheme == 0 ? ImColor(205, 216, 0, 255) : ImColor(205, 216, 0, 255), g.IO.DeltaTime * 5.f);
        c::input::text = ImLerp(c::input::text, iTheme == 0 ? ImColor(205, 216, 0, 255) : ImColor(205, 216, 0, 255), g.IO.DeltaTime * 5.f);
        c::input::line = ImLerp(c::input::line, iTheme == 0 ? ImColor(205, 216, 0, 255) : ImColor(205, 216, 0, 255), g.IO.DeltaTime * 5.f);
        c::input::cursor = ImLerp(c::input::cursor, iTheme == 0 ? ImColor(255, 255, 255, 255) : ImColor(255, 255, 255, 255), g.IO.DeltaTime * 5.f);
        c::combo::background_inactive = ImLerp(c::combo::background_inactive, iTheme == 0 ? ImColor(22, 22, 22, 255) : ImColor(22, 22, 22, 255), g.IO.DeltaTime * 5.f);
        c::combo::background_inactive = ImLerp(c::combo::background_inactive, iTheme == 0 ? ImColor(22, 22, 22, 255) : ImColor(22, 22, 22, 255), g.IO.DeltaTime * 5.f);
        c::text::texts = ImLerp(c::text::texts, iTheme == 0 ? ImColor(255, 255, 255, 255) : ImColor(255, 255, 255, 255), g.IO.DeltaTime * 5.f);
        c::child::background = ImLerp(c::child::background, iTheme == 0 ? ImColor(41, 43, 44, 255) : ImColor(41, 43, 44, 255), g.IO.DeltaTime * 15.f);
        c::picker::background_inactive = ImLerp(c::picker::background_inactive, iTheme == 0 ? ImColor(29, 29, 29, 205) : ImColor(29, 29, 29, 205), g.IO.DeltaTime * 5.f);
        s.Colors[ImGuiCol_PopupBg] = ImLerp(s.Colors[ImGuiCol_PopupBg], iTheme == 0 ? ImColor(22, 22, 22, 255) : ImColor(22, 22, 22, 255), g.IO.DeltaTime * 5.f);


    }
    if (iTheme == 1)
    {
        c::other::backgroud = ImLerp(c::other::backgroud, iTheme == 1 ? ImColor(248, 248, 248, 255) : ImColor(248, 248, 248, 255), g.IO.DeltaTime * 5.f);
        s.Colors[ImGuiCol_WindowBg] = ImLerp(s.Colors[ImGuiCol_WindowBg], iTheme == 1 ? ImColor(255, 255, 255, 255) : ImColor(255, 255, 255, 255), g.IO.DeltaTime * 5.f);
        s.Colors[ImGuiCol_ChildBg] = ImLerp(s.Colors[ImGuiCol_ChildBg], iTheme == 1 ? ImColor(239, 239, 239, 255) : ImColor(239, 239, 239, 255), g.IO.DeltaTime * 5.f);
        s.Colors[ImGuiCol_PopupBg] = ImLerp(s.Colors[ImGuiCol_PopupBg], iTheme == 1 ? ImColor(255, 255, 255, 255) : ImColor(255, 255, 255, 255), g.IO.DeltaTime * 5.f);
        c::other::main_purple = ImLerp(c::other::main_purple, iTheme == 1 ? ImColor(255, 158, 45, 255) : ImColor(255, 158, 45, 255), g.IO.DeltaTime * 5.f);
        c::bg::multicolor_tab = ImLerp(c::bg::multicolor_tab, iTheme == 1 ? ImColor(255, 138, 0, 255) : ImColor(255, 138, 0, 255), g.IO.DeltaTime * 5.f);
        c::bg::multicolor_tab1 = ImLerp(c::bg::multicolor_tab1, iTheme == 1 ? ImColor(48, 45, 46, 51) : ImColor(48, 45, 46, 51), g.IO.DeltaTime * 5.f);
        c::other::text_purple = ImLerp(c::other::text_purple, iTheme == 1 ? ImColor(255, 158, 45, 255) : ImColor(255, 158, 45, 255), g.IO.DeltaTime * 5.f);
        c::other::line = ImLerp(c::other::line, iTheme == 1 ? ImColor(255, 138, 0, 255) : ImColor(255, 138, 0, 255), g.IO.DeltaTime * 5.f);
        c::bg::rect = ImLerp(c::bg::rect, iTheme == 1 ? ImColor(233, 233, 233, 255) : ImColor(233, 233, 233, 255), g.IO.DeltaTime * 5.f);
        c::checkbox::background_active = ImLerp(c::checkbox::background_active, iTheme == 1 ? ImColor(255, 138, 0, 255) : ImColor(255, 138, 0, 255), g.IO.DeltaTime * 5.f);
        c::checkbox::background_inactive = ImLerp(c::checkbox::background_inactive, iTheme == 1 ? ImColor(255, 255, 255, 58) : ImColor(255, 255, 255, 58), g.IO.DeltaTime * 5.f);
        c::checkbox::rects = ImLerp(c::checkbox::rects, iTheme == 1 ? ImColor(43, 43, 43, 255) : ImColor(43, 43, 43, 255), g.IO.DeltaTime * 5.f);
        c::bg::text = ImLerp(c::bg::text, iTheme == 1 ? ImColor(255, 203, 141, 255) : ImColor(255, 203, 141, 255), g.IO.DeltaTime * 5.f);
        c::input::background_active = ImLerp(c::input::background_active, iTheme == 1 ? ImColor(255, 255, 255, 255) : ImColor(255, 255, 255, 255), g.IO.DeltaTime * 5.f);
        c::slider::background_active = ImLerp(c::slider::background_active, iTheme == 1 ? ImColor(255, 158, 45, 198) : ImColor(205, 216, 255, 198), g.IO.DeltaTime * 5.f);
        c::slider::circle_active = ImLerp(c::slider::circle_active, iTheme == 1 ? ImColor(255, 138, 0, 255) : ImColor(255, 138, 0, 255), g.IO.DeltaTime * 5.f);
        c::input::text = ImLerp(c::input::text, iTheme == 1 ? ImColor(255, 158, 45, 255) : ImColor(255, 158, 45, 255), g.IO.DeltaTime * 5.f);
        c::input::line = ImLerp(c::input::line, iTheme == 1 ? ImColor(255, 138, 0, 255) : ImColor(255, 138, 0, 255), g.IO.DeltaTime * 5.f);
        c::input::cursor = ImLerp(c::input::cursor, iTheme == 1 ? ImColor(43, 43, 43, 255) : ImColor(43, 43, 43, 255), g.IO.DeltaTime * 5.f);
        c::combo::background_inactive = ImLerp(c::combo::background_inactive, iTheme == 1 ? ImColor(255, 255, 255, 255) : ImColor(255, 255, 255, 255), g.IO.DeltaTime * 5.f);
        c::text::texts = ImLerp(c::text::texts, iTheme == 1 ? ImColor(43, 43, 43, 255) : ImColor(43, 43, 43, 255), g.IO.DeltaTime * 5.f);
        c::picker::background_inactive = ImLerp(c::picker::background_inactive, iTheme == 1 ? ImColor(239, 239, 239, 205) : ImColor(239, 239, 239, 205), g.IO.DeltaTime * 5.f);
        c::child::background = ImLerp(c::child::background, iTheme == 1 ? ImColor(230, 230, 230, 255) : ImColor(230, 230, 230, 255), g.IO.DeltaTime * 15.f);
    }
    s.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
    s.Colors[ImGuiCol_TextDisabled] = ImColor(255, 255, 255, 255);
    //    s.Colors[ImGuiCol_FrameBg] = ImColor(11, 11, 16, 160);
    s.Colors[ImGuiCol_Border] = ImColor(14, 13, 19, 0);
    s.Colors[ImGuiCol_TextSelectedBg] = ImColor(35, 32, 43, 160);

    s.ChildRounding = 12.f;
    s.WindowRounding = 15.f;
    s.WindowPadding = ImVec2(0, 0);
}
ID3D11ShaderResourceView* Logotip = nullptr;
ID3D11ShaderResourceView* bg = nullptr;
ImFont* MainFont = nullptr;
ImFont* Inters = nullptr;

ImFont* Lexend = nullptr;
ImFont* Lexend_tab = nullptr;
