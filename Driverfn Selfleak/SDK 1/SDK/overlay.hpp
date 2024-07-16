#pragma once
#include <Windows.h>

#include "Cache.hpp"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <D3DX11tex.h>
#pragma comment(lib,"D3DX11.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx11.lib")

#include "hooks.hpp"

#include "imgui/main.h"
#include "imgui/Font.h"
#include "imgui/Image.h"
#include <string>
ID3D11Device* d3d_device;
ID3D11DeviceContext* d3d_device_ctx;
IDXGISwapChain* d3d_swap_chain;
ID3D11RenderTargetView* d3d_render_target;
namespace c {
    inline ImVec4 accent = ImColor(255, 255, 0, 255);
    inline ImVec4 cbackground = ImColor(0, 0, 0, 200);
    inline ImVec4 outline = ImColor(18, 20, 18, 255);
    inline float rounding = 8.f;
    inline float crounding = 9.f;
}
HWND window_handle = 0;

namespace image
{
    ID3D11ShaderResourceView* aimbot = nullptr;
    ID3D11ShaderResourceView* visuals = nullptr;
    ID3D11ShaderResourceView* drop = nullptr;
    ID3D11ShaderResourceView* croshair = nullptr;
    ID3D11ShaderResourceView* exploits = nullptr;
    ID3D11ShaderResourceView* settings = nullptr;
    ID3D11ShaderResourceView* save = nullptr;
    ID3D11ShaderResourceView* arrow = nullptr;
}
D3DX11_IMAGE_LOAD_INFO info; ID3DX11ThreadPump* pump{ nullptr };

static const char* KeyNames1[] = {
    "Aimbot Bot Key",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const char* KeyNames[] = {
    "Trigger Bot Key",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const int KeyCodes[] = {
    0x0,  //Undefined
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07, //Undefined
    0x08,
    0x09,
    0x0A, //Reserved
    0x0B, //Reserved
    0x0C,
    0x0D,
    0x0E, //Undefined
    0x0F, //Undefined
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16, //IME On
    0x17,
    0x18,
    0x19,
    0x1A, //IME Off
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A, //Undefined
    0x3B, //Undefined
    0x3C, //Undefined
    0x3D, //Undefined
    0x3E, //Undefined
    0x3F, //Undefined
    0x40, //Undefined
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4B,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E, //Rservered
    0x5F,
    0x60, //Numpad1
    0x61, //Numpad2
    0x62, //Numpad3
    0x63, //Numpad4
    0x64, //Numpad5
    0x65, //Numpad6
    0x66, //Numpad7
    0x67, //Numpad8
    0x68, //Numpad8
    0x69, //Numpad9
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x6E,
    0x6F,
    0x70, //F1
    0x71, //F2
    0x72, //F3
    0x73, //F4
    0x74, //F5
    0x75, //F6
    0x76, //F7
    0x77, //F8
    0x78, //F9
    0x79, //F10
    0x7A, //F11
    0x7B, //F12
    0x7C, //F13
    0x7D, //F14
    0x7E, //F15
    0x7F, //F16
    0x80, //F17
    0x81, //F18
    0x82, //F19
    0x83, //F20
    0x84, //F21
    0x85, //F22
    0x86, //F23
    0x87, //F24
    0x88, //Unkown
    0x89, //Unkown
    0x8A, //Unkown
    0x8B, //Unkown
    0x8C, //Unkown
    0x8D, //Unkown
    0x8E, //Unkown
    0x8F, //Unkown
    0x90,
    0x91,
    0x92, //OEM Specific
    0x93, //OEM Specific
    0x94, //OEM Specific
    0x95, //OEM Specific
    0x96, //OEM Specific
    0x97, //Unkown
    0x98, //Unkown
    0x99, //Unkown
    0x9A, //Unkown
    0x9B, //Unkown
    0x9C, //Unkown
    0x9D, //Unkown
    0x9E, //Unkown 
    0x9F, //Unkown
    0xA0,
    0xA1,
    0xA2,
    0xA3,
    0xA4,
    0xA5
};


static HWND get_gdi_window(int dwProcessID)
{
    HWND hCurWnd = nullptr;
    while (true)
    {
        hCurWnd = FindWindowEx(nullptr, hCurWnd, nullptr, nullptr);
        DWORD checkProcessID;
        GetWindowThreadProcessId(hCurWnd, &checkProcessID);
        if (checkProcessID == dwProcessID)
        {
            char className[256];
            GetClassNameA(hCurWnd, className, 256);
            if (strstr(className, E("GDI+ Hook Window Class")))
                return hCurWnd;
        }
    }
}
void HotKey(int* k, const ImVec2& size_arg = ImVec2(0, 0))
{
    static bool waitingforkey = false;
    if (waitingforkey == false) {
        if (ImGui::Button(KeyNames1[*(int*)k], size_arg))
            waitingforkey = true;
    }
    else if (waitingforkey == true) {
        ImGui::Button("Change Key...", size_arg);
        Sleep(50);
        for (auto& Key : KeyCodes)
        {
            if (GetAsyncKeyState_Spoofed(Key)) {
                *(int*)k = Key;
                waitingforkey = false;
            }
        }
    }
}
void HotKeytrig(int* k, const ImVec2& size_arg = ImVec2(0, 0))
{
    static bool waitingforkey = false;
    if (waitingforkey == false) {
        if (ImGui::Button(KeyNames[*(int*)k], size_arg))
            waitingforkey = true;
    }
    else if (waitingforkey == true) {
        ImGui::Button("Change Key...", size_arg);
        Sleep(50);
        for (auto& Key : KeyCodes)
        {
            if (GetAsyncKeyState_Spoofed(Key)) {
                *(int*)k = Key;
                waitingforkey = false;
            }
        }
    }
}
auto Hijack() -> bool {
    window_handle = FindWindowA_Spoofed(E("MedalOverlayClass"), E("MedalOverlay"));

    if (!window_handle)
    {
        MessageBoxA(NULL, E("Medal Not Found"), NULL, ALERT_SYSTEM_WARNING);
        return false;
    }

    MARGINS Margin = { -1 };
    DwmExtendFrameIntoClientArea(window_handle, &Margin);
    SetWindowPos_Spoofed(window_handle, 0, 0, 0, GetSystemMetrics_Spoofed(SM_CXSCREEN), GetSystemMetrics_Spoofed(SM_CYSCREEN), SWP_SHOWWINDOW);
    ShowWindow_Spoofed(window_handle, SW_SHOW);
    return true;
}

DWORD picker_flags = ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview;
void Menu()
{
    CustomStyleColor();
    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    ImGui::SetNextWindowSize(ImVec2(696, 700));
    ImGui::Begin(E("DriverFN"), &globals->render_menu, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize);
    {
        const auto& p = ImGui::GetWindowPos();



        const ImVec2& region = ImGui::GetContentRegionMax();

        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + region.x, p.y + 120), ImGui::GetColorU32(c::other::backgroud), 15.f, ImDrawFlags_RoundCornersTop);

        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y + 121), ImVec2(p.x + region.x, p.y + 124), ImGui::GetColorU32(c::other::line));

        if (Logotip == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, Logo, sizeof(Logo), &info, pump, &Logotip, 0);
        ImGui::GetWindowDrawList()->AddImageRounded(Logotip, ImVec2(p.x + 0, p.y - 5), ImVec2(p.x + 90, p.y + 90), ImVec2(0, 0), ImVec2(1, 1), ImGui::GetColorU32(c::other::main_purple) /*color*/, 0 /*rounding*/);

        ImGui::GetWindowDrawList()->AddText(Roboto, 35.f, ImVec2(p.x + 80, p.y + 34), ImGui::GetColorU32(c::other::main_purple), "DriverFN");

        ImGui::GetWindowDrawList()->AddText(Lexend, 17.f, ImVec2(p.x + 80, p.y + 68), ImGui::GetColorU32(c::other::color_black), "Build : 2.0 | Private");

        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + 229, p.y + 34), ImVec2(p.x + 231, p.y + 87), ImGui::GetColorU32(c::other::line_tab));

        static int page = 0;

        static float tab_alpha = 0.f; /* */ static float tab_add; /* */ static int active_tab = 0;

        tab_alpha = ImClamp(tab_alpha + (5.f * ImGui::GetIO().DeltaTime * (page == active_tab ? 1.f : -1.f)), 0.f, 1.f);

        tab_add = ImClamp(tab_add + (std::round(350.f) * ImGui::GetIO().DeltaTime * (page == active_tab ? 1.f : -1.f)), 0.f, 1.f);

        if (tab_alpha == 0.f && tab_add == 0.f) active_tab = page;

        ImGui::SetCursorPos(ImVec2(292, 30));
        ImGui::BeginGroup();
        {
            if (ImGui::Tab(E("Aimbot"), image::aimbot, 0 == page, ImVec2(60, 60))) page = 0;
            ImGui::SameLine(0, 20);
            if (ImGui::Tab(E("Visuals"), image::visuals, 1 == page, ImVec2(60, 60))) page = 1;
            ImGui::SameLine(0, 20);
            if (ImGui::Tab(E("Misc"), image::drop, 2 == page, ImVec2(60, 60))) page = 2;
        }
        ImGui::EndGroup();

        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, tab_alpha * style.Alpha);
        if (active_tab == 0)
        {
            ImGui::SetCursorPos(ImVec2(32, 175));
            ImGui::BeginChild(E("Aimbot"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {
                    ImGui::Checkbox(E("Aimbot"), &globals->bAim);

                    ImGui::Checkbox(E("AimLock"), &globals->bAimLock);

                    ImGui::Checkbox(E("Draw Fov"), &globals->render_field_of_view);

                    ImGui::SliderFloat(E("Fov"), &globals->field_of_view, 10.f, 500.f);

                    HotKey(&globals->iAimKey, ImVec2(200, 20));
                    

                }ImGui::EndGroup();
            }
            ImGui::EndChild();

            ImGui::SetCursorPos(ImVec2(32, 455));
            ImGui::BeginChild(E("Aim Settings"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {
                    ImGui::Checkbox(E("Visible Check"), &globals->bVcheck);

                    ImGui::SliderFloat(E("Smoothing"), &globals->fSmooth, 1.f, 50.f);

                    ImGui::Checkbox(E("Controller Support"), &globals->bController);

                    ImGui::Combo(E("Aim Bone"), &boneSelected, boneItems, IM_ARRAYSIZE(boneItems), 2);



                }ImGui::EndGroup();
            }
            ImGui::EndChild();

            ImGui::SetCursorPos(ImVec2(365, 175));
            ImGui::BeginChild(E("Triggerbot"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {

                    ImGui::Checkbox(E("Triggerbot"), &globals->bTrigger);

                    HotKeytrig(&globals->iTriggerKey, ImVec2(200, 20));

                    ImGui::SliderFloat(E("Distance"), &globals->fDistance, 1.f, 500.f);

                    ImGui::SliderFloat(E("Triggerbot Delay"), &globals->fTriggerDelay, 0.1f, 5.f);

                }ImGui::EndGroup();
            }
            ImGui::EndChild();

            ImGui::SetCursorPos(ImVec2(365, 455));
            ImGui::BeginChild(E("Aim Prediction"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {

                    ImGui::Checkbox(E("Sniper Prediction"), &globals->bPrediction);

                }ImGui::EndGroup();
            }
            ImGui::EndChild();
        }
        if (active_tab == 1)
        {
            ImGui::SetCursorPos(ImVec2(32, 175));
            ImGui::BeginChild(E("Visuals 1"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {

                    ImGui::Checkbox(E("Player Boxes"), &globals->bBox);

                    ImGui::Checkbox(E("Player Distance"), &globals->bDistance);

                    ImGui::Checkbox(E("Player Skeleton"), &globals->bSkeleton);

                    ImGui::SliderFloat(E("Skeleton Thickness"), &globals->fBoneThick, 1.f, 10.f);


                }ImGui::EndGroup();
            }
            ImGui::EndChild();

            ImGui::SetCursorPos(ImVec2(365, 175));
            ImGui::BeginChild(E("Visuals 2"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {

                    ImGui::Checkbox(E("Player Name"), &globals->bPlrName);

                    ImGui::Checkbox(E("Player Snapline"), &globals->bSnapLine);

                    ImGui::Checkbox(E("Player Team Check"), &globals->bTCheck);

                    ImGui::SliderFloat(E("Box Thickness"), &globals->fBoxThick, 1.f, 10.f);

                }ImGui::EndGroup();
            }
            ImGui::EndChild();

            ImGui::SetCursorPos(ImVec2(32, 455));
            ImGui::BeginChild(E("Visuals 3"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {
                    ImGui::Checkbox(E("Player Round Boxes"), &globals->bRoundBox);

                    ImGui::Checkbox(E("Player Fill Boxes"), &globals->bFillbox);

                    ImGui::Checkbox(E("Player Corner Boxes"), &globals->bCornerbox);

                }ImGui::EndGroup();
            }
            ImGui::EndChild();
            ImGui::SetCursorPos(ImVec2(365, 455));
            //ImGui::BeginChild(E("Visible Colors"), ImVec2(300, 200));
            //{
            //    ImGui::SetCursorPos(ImVec2(13, 25));
            //    ImGui::BeginGroup();
            //    {
            //        ImGui::ColorEdit4("Player Box", globals->BoxColorVis, globals->picker_flags);
            //        ImGui::ColorEdit4("Player Skeleton", globals->SkeletonColorVis, globals->picker_flags);
            //        ImGui::ColorEdit4("Player Text", globals->NameColorVis, globals->picker_flags);
            //        ImGui::ColorEdit4("Player Snapline", globals->SnaplineColorVis, globals->picker_flags);

            //    }ImGui::EndGroup();
            //}
            //ImGui::EndChild();

            //ImGui::SetCursorPos(ImVec2(32, 455));
            //ImGui::BeginChild(E("Invisble Colors"), ImVec2(300, 200));
            //{
            //    ImGui::SetCursorPos(ImVec2(13, 25));
            //    ImGui::BeginGroup();
            //    {
            //        ImGui::ColorEdit4("Player Box", globals->BoxColor, globals->picker_flags);
            //        ImGui::ColorEdit4("Player Skeleton", globals->SkeletonColor, globals->picker_flags);
            //        ImGui::ColorEdit4("Player Text", globals->NameColor, globals->picker_flags);
            //        ImGui::ColorEdit4("Player Snapline", globals->SnaplineColor, globals->picker_flags);

            //    }ImGui::EndGroup();
            //}
            ImGui::EndChild();
        }

        if (active_tab == 2)
        {
            ImGui::SetCursorPos(ImVec2(32, 175));
            ImGui::BeginChild(E("Radar"), ImVec2(300, 200));
            {
                ImGui::SetCursorPos(ImVec2(13, 25));
                ImGui::BeginGroup();
                {

                    ImGui::Checkbox(E("(COMMING SOON) Radar"), &globals->bRadar);

                }ImGui::EndGroup();
            }
            ImGui::EndChild();
        }

        ImGui::PopStyleVar();
    }ImGui::End();
}

auto Init() -> bool {
    DXGI_SWAP_CHAIN_DESC swap_chain_description = {};
    swap_chain_description.BufferCount = 2;
    swap_chain_description.BufferDesc.Width = globals->width; // Set the appropriate width based on your requirements
    swap_chain_description.BufferDesc.Height = globals->height; // Set the appropriate height based on your requirements
    swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swap_chain_description.BufferDesc.RefreshRate.Numerator = 1000;
    swap_chain_description.BufferDesc.RefreshRate.Denominator = 1;
    swap_chain_description.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swap_chain_description.OutputWindow = window_handle;
    swap_chain_description.SampleDesc.Count = 1;
    swap_chain_description.SampleDesc.Quality = 0;
    swap_chain_description.Windowed = TRUE;
    swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    D3D_FEATURE_LEVEL d3d_feature_lvl;

    const D3D_FEATURE_LEVEL d3d_feature_array[1] = { D3D_FEATURE_LEVEL_11_0 };

    D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        d3d_feature_array,
        1,
        D3D11_SDK_VERSION,
        &swap_chain_description,
        &d3d_swap_chain,
        &d3d_device,
        &d3d_feature_lvl,
        &d3d_device_ctx);

    ID3D11Texture2D* pBackBuffer;

    d3d_swap_chain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));

    d3d_device->CreateRenderTargetView(pBackBuffer, NULL, &d3d_render_target);

    pBackBuffer->Release();

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();

    io.IniFilename = NULL;

    (void)io;
    D3DX11_IMAGE_LOAD_INFO info;
    ID3DX11ThreadPump* pump{ nullptr };

    MainFont = io.Fonts->AddFontFromMemoryTTF(&Main_Font, sizeof Main_Font, 15.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    Inters = io.Fonts->AddFontFromMemoryTTF(&Inter_Font, sizeof Inter_Font, 12.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    Roboto = io.Fonts->AddFontFromMemoryTTF(&Roboto_Font, sizeof Roboto_Font, 35.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    Lexend = io.Fonts->AddFontFromMemoryTTF(&Lexend_Font, sizeof Lexend_Font, 17.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    Lexend_tab = io.Fonts->AddFontFromMemoryTTF(&Lexend_Font_1, sizeof Lexend_Font_1, 15.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    if (image::aimbot == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, aimbot_icon, sizeof(aimbot_icon), &info, pump, &image::aimbot, 0);

    if (image::visuals == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, visuals_icon, sizeof(visuals_icon), &info, pump, &image::visuals, 0);

    if (image::drop == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, drop_icon, sizeof(drop_icon), &info, pump, &image::drop, 0);

    if (image::settings == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, settings_icon, sizeof(settings_icon), &info, pump, &image::settings, 0);

    if (image::exploits == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, exploits_icon, sizeof(exploits_icon), &info, pump, &image::exploits, 0);

    if (image::arrow == nullptr) D3DX11CreateShaderResourceViewFromMemory(d3d_device, arrow_icon, sizeof(arrow_icon), &info, pump, &image::arrow, 0);

    ImGui_ImplWin32_Init(window_handle);

    ImGui_ImplDX11_Init(d3d_device, d3d_device_ctx);

    d3d_device->Release();

    return true;

}

void StartOverlay()
{
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.f);

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    if (GetAsyncKeyState_Spoofed(VK_INSERT) & 1)
        globals->render_menu = !globals->render_menu;

    if (globals->render_field_of_view) {

        if (globals->normal_fov)
        {
            if (globals->outline)
            {
                ImGui::GetForegroundDrawList()->AddCircle(ImVec2(globals->width / 2, globals->height / 2), globals->field_of_view, ImColor(0, 0, 0, 255), 100, 5.f);
                ImGui::GetForegroundDrawList()->AddCircle(ImVec2(globals->width / 2, globals->height / 2), globals->field_of_view, ImColor(255, 255, 225, 255), 100, 2.f);
            }
            else
            {
                ImGui::GetForegroundDrawList()->AddCircle(ImVec2(globals->width / 2, globals->height / 2), globals->field_of_view, ImColor(10, 15, 225, 255), 100, 2.f);
            }
        }
    }

    ImGui::GetForegroundDrawList()->AddText(ImVec2(20, 20), ImColor(1.f, 1.f, 1.f), E("DriverFN | Private"));
    char fps[356]; // 64
    sprintf_s(fps, ("Frames: %.3f"), ImGui::GetIO().Framerate);
    ImGui::GetForegroundDrawList()->AddText(ImVec2(20, 40), ImColor(1.f, 1.f, 1.f), fps);


    //float fps = ImGui::GetIO().Framerate;

    //const char* cheat_name = "DriverFN";
    //const char* developer = "Private Build";

    //std::string ping = "FPS: " + std::to_string(static_cast<int>(fps));
    //const char* ping_cstr = ping.c_str();

    //const char* world_time = "Version: 2.0        ";



    ////ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(globals->width - 362, 15), ImVec2(globals->width - 47, 46), ImColor(0, 0, 0, 150), 3.f, ImDrawFlags_RoundCornersAll);

    ////ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(globals->width - 359, 18), ImVec2(globals->width - 50, 43), ImColor(0, 145, 255, 100), 3.f, ImDrawFlags_RoundCornersAll);
    ////
    ////ImGui::GetForegroundDrawList()->AddText(ImVec2(globals->width - 345, 21), ImColor(1.f, 1.f, 1.f), E("CARBON | "));

    ////ImGui::GetBackgroundDrawList()->AddText(ImVec2(globals->width - 300, 21), ImColor(255, 255, 255), (E("FPS: ").decrypt() + std::to_string(static_cast<int>(fps))).c_str());

    ////ImGui::GetForegroundDrawList()->AddText(ImVec2(globals->width - 245, 21), ImColor(1.f, 1.f, 1.f), E("| Private Build | Version: 1337"));
    //ImGuiStyle* style = &ImGui::GetStyle();
    //static float ibar_size = ImGui::CalcTextSize(cheat_name).x + ImGui::CalcTextSize("|").x + ImGui::CalcTextSize(developer).x + ImGui::CalcTextSize("|").x + ImGui::CalcTextSize(ping_cstr).x + ImGui::CalcTextSize("|").x + ImGui::CalcTextSize(world_time).x + (style->ItemSpacing.x * 8) - 15;

    //ImGui::Begin("info-bar", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration);
    //{

    //    const ImVec2& pos = ImGui::GetWindowPos(), spacing = style->ItemSpacing, region = ImGui::GetContentRegionMax();


    //    ImGui::GetBackgroundDrawList()->AddRectFilled(pos, pos + ImVec2(ibar_size, 45), ImGui::GetColorU32(c::cbackground), c::rounding);
    //    ImGui::GetBackgroundDrawList()->AddRectFilled(pos + ImVec2(0, 10), pos + ImVec2(4, 35), ImGui::GetColorU32(c::accent), c::crounding, ImDrawCornerFlags_Right);
    //    ImGui::GetBackgroundDrawList()->AddRectFilled(pos + ImVec2(region.x - 4, 10), pos + ImVec2(region.x, 35), ImGui::GetColorU32(c::accent), c::crounding, ImDrawCornerFlags_Left);
    //    ImGui::GetBackgroundDrawList()->AddRect(pos, pos + ImVec2(ibar_size, 45), ImGui::GetColorU32(c::outline), c::rounding);

    //    const char* info_set[4] = { cheat_name, developer, ping_cstr, world_time };
    //    static int info_bar_size = 0;

    //    ImGui::SetCursorPos(ImVec2(spacing.x, (45 - ImGui::CalcTextSize(developer).y) / 2));
    //    ImGui::BeginGroup();
    //    {

    //        for (int i = 0; i < sizeof(info_set) / sizeof(info_set[0]); i++) {
    //            ImGui::TextColored(i < 1 ? ImColor(ImGui::GetColorU32(c::accent)) : ImColor(ImGui::GetColorU32(c::text::text)), info_set[i]);
    //            ImGui::SameLine();

    //            if (i < 3) {
    //                ImGui::TextColored(ImColor(ImGui::GetColorU32(c::text::text)), "|");
    //                ImGui::SameLine();
    //            }
    //        }
    //    }
    //    ImGui::EndGroup();
    //}

    EntityLoop();

    if (globals->render_menu)
    {
        Menu();
    }
    if (GetAsyncKeyState_Spoofed(VK_DELETE))
    {
        exit(0);
    }

    ImGui::Render();
    const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
    d3d_device_ctx->OMSetRenderTargets(1, &d3d_render_target, nullptr);
    d3d_device_ctx->ClearRenderTargetView(d3d_render_target, clear_color_with_alpha);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    d3d_swap_chain->Present(1, 0);
}

bool Draw()
{
    static RECT rect_og;
    MSG msg = { NULL };
    ZeroMemory(&msg, sizeof(MSG));

    while (msg.message != WM_QUIT)
    {
        UpdateWindow_Spoofed(window_handle);
        ShowWindow_Spoofed(window_handle, SW_SHOW);

        if ((PeekMessageA_Spoofed)(&msg, window_handle, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        ImGuiIO& io = ImGui::GetIO();
        io.ImeWindowHandle = window_handle;
        io.DeltaTime = 1.0f / 60.0f;


        POINT p_cursor;
        GetCursorPos(&p_cursor);
        io.MousePos.x = p_cursor.x;
        io.MousePos.y = p_cursor.y;

        if (GetAsyncKeyState_Spoofed(VK_LBUTTON)) {
            io.MouseDown[0] = true;
            io.MouseClicked[0] = true;
            io.MouseClickedPos[0].x = io.MousePos.x;
            io.MouseClickedPos[0].x = io.MousePos.y;
        }
        else
            io.MouseDown[0] = false;

        StartOverlay();

    }
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    (DestroyWindow)(window_handle);

    return true;
}