#pragma once

#include "Includes.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui/imgui.h"
#include <math.h>
#include <xmmintrin.h>
#include <immintrin.h>

#include <sstream>
#include "hex.hpp"

#include <chrono>

inline bool debug = false;

inline ImFont* Roboto = nullptr;

inline void LOOG(std::string str, uintptr_t Addr)
{
    std::cout << "[" << str << "]" << " - " << std::to_string(Addr) << std::endl;
}

inline void LOG(std::string str)
{
    std::cout << "[MEMORY] - " << str << std::endl;
}

namespace ACamera
{
    inline FVector location, rotation;
    inline float fov;
}

enum bone : int
{
    HumanBase = 0,
    HumanPelvis = 2,
    HumanLThigh1 = 71,
    HumanLThigh2 = 77,
    HumanLThigh3 = 72,
    HumanLCalf = 74,
    HumanLFoot2 = 73,
    HumanLFoot = 86,
    HumanLToe = 76,
    HumanRThigh1 = 78,
    HumanRThigh2 = 84,
    HumanRThigh3 = 79,
    HumanRCalf = 81,
    HumanRFoot2 = 82,
    HumanRFoot = 87,
    HumanRToe = 83,
    HumanSpine1 = 7,
    HumanSpine2 = 5,
    HumanSpine3 = 2,
    HumanLCollarbone = 9,
    HumanLUpperarm = 35,
    HumanLForearm1 = 36,
    HumanLForearm23 = 10,
    HumanLForearm2 = 34,
    HumanLForearm3 = 33,
    HumanLPalm = 32,
    HumanLHand = 11,
    HumanRCollarbone = 98,
    HumanRUpperarm = 64,
    HumanRForearm1 = 65,
    HumanRForearm23 = 39,
    HumanRForearm2 = 63,
    HumanRForearm3 = 62,
    HumanRHand = 40,
    HumanRPalm = 58,
    HumanNeck = 67,
    HumanHead = 109,
    HumanChest = 66
}; 

enum offset {
    uworld = 0x12BA7050,
    game_instance = 0x1d0,
    game_state = 0x160,
    local_player = 0x38,
    player_controller = 0x30,
    acknowledged_pawn = 0x338,
    skeletal_mesh = 0x318,
    player_state = 0x2b0,
    root_component = 0x198,
    relative_location = 0x120,
    relative_rotation = 0x138,
    team_index = 0x1211,
    player_array = 0x2A8,
    pawn_private = 0x308,
    current_weapon = 0xA20,
    is_cached = 0x5e0,
    bone_array = 0x5B8,
    component_to_world = 0x1c0,
    location_under_reticle = 0x2560,
    reviveDBNO = 0x4b68,
    fLastSubmitTime = 0x358,
    fLastRenderTimeOnScreen = 0x360,
};



struct _globals_
{
    float width = GetSystemMetrics(0);
    float height = GetSystemMetrics(1);

    bool render_menu = true;

    bool render_field_of_view = true;
    bool normal_fov = true;
    bool outline = true;
    float field_of_view = 50.f;

    //Aim
    bool bAim = false;
    bool bAimLock = false;
    bool bFOV = false;
    bool bVcheck = true;
    bool bController = false;
    int iAimKey;
    float fSmooth = 1.f;

    //Triggerbot

    bool bTrigger = false;
    int iTriggerKey;
    float fDistance = 550.f;
    float fTriggerDelay = 0.f;

    //Weapon Config (Later)

    //Prediction

    bool bPrediction = 0;

    //Close Aim (Later)

    //Visuals

    bool bBox = false;
    bool bDistance = false;
    bool bPlatform = false;
    bool bSkeleton = false;
    bool bLines = false;
    bool bTCheck = false;
    bool bRadar = false;
    bool bSnapLine = false;
    bool bPlrName = false;
    bool bCornerbox = false;
    bool bRoundBox = false;
    bool bFillbox = false;
    bool bMagicBullet = false;
    bool bSpinbot = false;
    bool bHeadEsp = false;
    bool bLootEsp = false;
    bool bTargetLine = false;
    float fBoxThick = 0.f;

    bool bChest = false;
    bool bLoot = false;
    bool bAmmo = false;
    bool bVehicles = false;
    
    float fBoneThick = 0.f;


    float BoxColor[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    float SkeletonColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float SnaplineColor[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    float NameColor[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    ImColor NameColorImColor = ImVec4(NameColor[0], NameColor[1], NameColor[2], NameColor[3]);
    ImColor BoxColorImColor = ImVec4(BoxColor[0], BoxColor[1], BoxColor[2], BoxColor[3]);
    ImColor SkeletonColorImColor = ImVec4(SkeletonColor[0], SkeletonColor[1], SkeletonColor[2], 1.0);
    ImColor SnaplineColorImColor = ImVec4(SnaplineColor[0], SnaplineColor[1], SnaplineColor[2], SnaplineColor[3]);


    float BoxColorVis[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    float SkeletonColorVis[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    float SnaplineColorVis[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    float NameColorVis[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
    ImColor BoxColorVisImColor = ImVec4(BoxColorVis[0], BoxColorVis[1], BoxColorVis[2], BoxColorVis[3]);
    ImColor SkeletonColorVisImColor = ImVec4(SkeletonColorVis[0], SkeletonColorVis[1], SkeletonColorVis[2], 1.0);
    ImColor SnaplineColorVisImColor = ImVec4(SnaplineColorVis[0], SnaplineColorVis[1], SnaplineColorVis[2], SnaplineColorVis[3]);
    ImColor NameColorVisImColor = ImVec4(NameColorVis[0], NameColorVis[1], NameColorVis[2], NameColorVis[3]);



    int iLootDistance = 100.f;

    DWORD picker_flags = ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaPreview;

}; static _globals_* globals = new _globals_();

class PlayerCacheList {
public:
    uintptr_t
        actor,
        skeletal_mesh,
        root_component,
        player_state;
    int
        team_index;
    FVector
        relative_location;
    FVector2d
        predictedloc;
};

struct _pointers_
{
    uintptr_t World = NULL;
    FVector RelativeLocation;
    FVector2d predictedloc;
    uintptr_t GameInstance = NULL;
    uintptr_t GameState = NULL;
    uintptr_t LocalPlayers = NULL;
    uintptr_t PlayerController = NULL;
    uintptr_t Apawn = NULL;
    uintptr_t RootComponent = NULL;
    uintptr_t PlayerArray = NULL;
    uintptr_t PlayerState = NULL;
    uintptr_t PlayerArraySize = NULL;
}; static _pointers_* Pointers = new _pointers_();

typedef struct _LootEntity {
    std::string GNames;
    uintptr_t ACurrentItem;
}LootEntity;
static std::vector<LootEntity> LootentityList;

inline auto InScreen(FVector2d screen_position) -> bool {

    if (screen_position.x > 0 && screen_position.x < GetSystemMetrics(0) && screen_position.y > 0 && screen_position.y < GetSystemMetrics(1))
        return true;
    else
        return false;
}

struct _Engine_
{
#define FNAMEPOOL_OFFSET 0x11947880

    static std::string GetNameFromIndex(int key)
    {
        uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
        uint16_t NameOffset = (uint16_t)key;
        uint64_t NamePoolChunk = io::Read<uint64_t>(base_address + FNAMEPOOL_OFFSET + (8 * ChunkOffset) + 16) + (unsigned int)(2 * NameOffset);
        uint16_t nameEntry = io::Read<uint16_t>(NamePoolChunk);
        int nameLength = nameEntry >> 6;
        char buff[1024] = {};

        char* v2 = buff; // rdi
        int v4 = nameLength; // ebx
        int v5; // edx
        int v6; // ecx
        int v7; // ecx
        __int16 v8; // ax
        __int16 v9; // ax

        v6 = 0;
        v7 = 42;
        if (v4)
        {
            io::ReadArray((NamePoolChunk + 2), (PVOID)buff, 2 * nameLength);
            do
            {
                v8 = v6++ | v7;
                v9 = v8;
                v7 = 2 * v8;
                *v2++ ^= ~v8;
            } while (v6 < v4);
            buff[nameLength] = '\0';
            return std::string(buff);
        }
        return std::string("");
    }

    static std::string GetNameFromFName(int key)
    {
        uint32_t ChunkOffset = (uint32_t)((int)(key) >> 16);
        uint16_t NameOffset = (uint16_t)key;

        uint64_t NamePoolChunk = io::Read<uint64_t>(base_address + FNAMEPOOL_OFFSET + (8 * ChunkOffset) + 16) + (unsigned int)(2 * NameOffset); //((ChunkOffset + 2) * 8) ERROR_NAME_SIZE_EXCEEDED
        if (io::Read<uint16_t>(NamePoolChunk) < 64)
        {
            auto a1 = io::Read<DWORD>(NamePoolChunk + 2);
            return GetNameFromIndex(a1);
        }
        else
        {
            return GetNameFromIndex(key);
        }
    }
    
    uintptr_t GetWorld()
    {
        uintptr_t world = io::Read<uintptr_t>(base_address + offset::uworld);

        if (debug == true)
        {
            LOOG("world", world);
        }
        
        return world;
    }
    
    uintptr_t GetGameInstance(uintptr_t world)
    {
        uintptr_t ginstance = io::Read<uintptr_t>(world + offset::game_instance);

        if (debug == true)
        {
            LOOG("ginstance", ginstance);
        }

        return ginstance;
    }

    uintptr_t GetGameState(uintptr_t world)
    {
        uintptr_t gState = io::Read<uintptr_t>(world + offset::game_state);

        if (debug == true)
        {
            LOOG("gState", gState);
        }

        return gState;
    }

    uintptr_t GetPlayerController(uintptr_t localPlr)
    {
        uintptr_t plrController = io::Read<uintptr_t>(localPlr + offset::player_controller);

        if (debug == true)
        {
            LOOG("plrController", plrController);
        }

        return plrController;
    }

}; static _Engine_* Engine = new _Engine_();

struct _ULocal_Player
{
    uintptr_t GetLocalPlayer(uintptr_t GameInstance)
    {
        uintptr_t lplr = io::Read<uintptr_t>(io::Read<uintptr_t>(GameInstance + offset::local_player));

        if (debug == true)
        {
            LOOG("lplr", lplr);
        }

        return lplr;
    }
}; static _ULocal_Player* ULocalPlayer = new _ULocal_Player();

struct _Apawn_
{
    uintptr_t GetPawn(uintptr_t PlrController)
    {
        uintptr_t aPawn = io::Read<uintptr_t>(PlrController + offset::acknowledged_pawn);

        if (debug == true)
        {
            LOOG("aPawn", aPawn);
        }

        return aPawn;
    }

    uintptr_t GetRootComponent(uintptr_t Pawn)
    {
        uintptr_t RootComponent = io::Read<uintptr_t>(Pawn + offset::root_component);

        if (debug == true)
        {
            LOOG("RootComponent", RootComponent);
        }

        return RootComponent;
    }
    FVector PredictLocation(FVector target, FVector targetVelocity, float projectileSpeed, float projectileGravityScale, float distance)
    {
        float horizontalTime = distance / projectileSpeed;
        float verticalTime = distance / projectileSpeed;

        target.x += targetVelocity.x * horizontalTime;
        target.y += targetVelocity.y * horizontalTime;
        target.z += targetVelocity.z * verticalTime +
            abs(-980 * projectileGravityScale) * 0.5f * (verticalTime * verticalTime);

        return target;

    }
    std::string DecryptName(__int64 PlayerState)
    {
        auto fstring = (io::Read<__int64>)(PlayerState + 0xaf0);
        auto length = (io::Read<int>)(fstring + 16);

        auto v6 = (__int64)length;
        if (!v6) return std::string(("AI/NONE"));

        auto ftext = (uintptr_t)(io::Read<__int64>)(fstring + 8);

        wchar_t* buffer = new wchar_t[length];
        io::ReadArray(ftext, buffer, length * sizeof(wchar_t));

        char v21;
        int v22;
        int i;

        int v25;
        UINT16* v23;

        v21 = v6 - 1;
        if (!(UINT32)v6)
            v21 = 0;
        v22 = 0;
        v23 = (UINT16*)buffer;
        for (i = (v21) & 3; ; *v23++ += i & 7)
        {
            v25 = v6 - 1;
            if (!(UINT32)v6)
                v25 = 0;
            if (v22 >= v25)
                break;
            i += 3;
            ++v22;
        }

        std::wstring username{ buffer };
        return std::string(username.begin(), username.end());
    }


}; static _Apawn_* APawn = new _Apawn_();

struct _AGameStateAthena_
{
    uintptr_t GetPlayerArray(uintptr_t GameState)
    {
        uintptr_t PlayerArray = io::Read<uintptr_t>(GameState + offset::player_array);

        if (debug == true)
        {
            LOOG("PlayerArray", PlayerArray);
        }

        return PlayerArray;
    }

    uintptr_t GetPlayerArraySize(uintptr_t GameState)
    {
        uintptr_t PlayerArraySize = io::Read<uintptr_t>(GameState + (offset::player_array + sizeof(uintptr_t)));

        if (debug == true)
        {
            LOOG("Players In Lobby", PlayerArraySize);
        }

        return PlayerArraySize;
    }
}; static _AGameStateAthena_* AGameStateAthena = new _AGameStateAthena_();

struct _Player_Camera_Manager
{
    static auto UpdateCamera() -> void
    {
        auto location_pointer = io::Read<uintptr_t>(Pointers->World + 0x110);
        auto rotation_pointer = io::Read<uintptr_t>(Pointers->World + 0x120);

        struct FNRotation
        {
            double a;
            char pad_0008[24];
            double b;
            char pad_0028[424];
            double c;
        }tpmrotation;

        tpmrotation.a = io::Read<double>(rotation_pointer);
        tpmrotation.b = io::Read<double>(rotation_pointer + 0x20);
        tpmrotation.c = io::Read<double>(rotation_pointer + 0x1d0);

        ACamera::rotation.x = asin(tpmrotation.c) * (180.0 / M_PI);
        ACamera::rotation.y = ((atan2(tpmrotation.a * -1, tpmrotation.b) * (180.0 / M_PI)) * -1) * -1;
        ACamera::rotation.z = 0;
        ACamera::location = io::Read<FVector>(location_pointer);
        ACamera::fov = io::Read<float>(Pointers->PlayerController + 0x394) * 90.f;
    }

    static auto ProjectWorldToScreen(FVector worldlocation) -> FVector2d {
        D3DMATRIX tempMatrix = Matrix(ACamera::rotation);

        FVector vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
        FVector vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
        FVector vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

        FVector vDelta = worldlocation - ACamera::location;
        FVector vTransformed = FVector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

        if (vTransformed.z < 1.f)
            vTransformed.z = 1.f;

        // Assuming FVector2d has separate x and y components
        double x = (GetSystemMetrics(0) / 2.0) + vTransformed.x * (((GetSystemMetrics(0) / 2.0) / tanf(ACamera::fov * (float)M_PI / 360.f))) / vTransformed.z;
        double y = (GetSystemMetrics(1) / 2.0) - vTransformed.y * (((GetSystemMetrics(0) / 2.0) / tanf(ACamera::fov * (float)M_PI / 360.f))) / vTransformed.z;

        FVector2d result;
        result.x = x;
        result.y = y;

        return result;
    }



}; static _Player_Camera_Manager* APlayerCameraManager = new _Player_Camera_Manager();

struct _A_Skeleton_
{
    uintptr_t GetActorLocation(uintptr_t Actor)
    {
        return io::Read<uintptr_t>(Actor + offset::relative_location);
    }

    static FVector GetBoneLocation(uintptr_t skeletal_mesh, int bone_index) {

        auto is_cached = io::Read<int>(skeletal_mesh + offset::is_cached);

        auto bone_array = io::Read<uintptr_t>(skeletal_mesh + offset::bone_array + (is_cached * 0x10));

        auto bone = io::Read<ftransform>(bone_array + (bone_index * 0x60));

        auto component_to_world = io::Read<ftransform>(skeletal_mesh + offset::component_to_world);

        D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());

        return FVector(matrix._41, matrix._42, matrix._43);
    } 
}; static _A_Skeleton_* ASkeleton = new _A_Skeleton_();

auto hjesgrw346823(uintptr_t skeletal_mesh) -> bool {
    float last_submit = io::Read<float>(skeletal_mesh + 0x2E8);
    float last_render = io::Read<float>(skeletal_mesh + 0x2F0);
    const float fVisionTick = 0.06f;
    bool visible = last_render + fVisionTick >= last_submit;
    return visible;
}

static float powf_(float _X, float _Y) {
    return (_mm_cvtss_f32(_mm_pow_ps(_mm_set_ss(_X), _mm_set_ss(_Y))));
}

static double GetCrossDistance(double x1, double y1, double x2, double y2) {
    return sqrtf(powf((x2 - x1), 2) + powf_((y2 - y1), 2));
}


struct _UCanvas_
{
    void K2_DrawLine(ImVec2 Location, ImVec2 Location1, ImColor color)
    {
        ImGui::GetForegroundDrawList()->AddLine(Location, Location1, ImColor(0, 0, 0, 255), 4.f);
        ImGui::GetForegroundDrawList()->AddLine(Location, Location1, color, 2.f);
    }

    void K2_DrawBox(ImVec2 Location, ImVec2 Location1, ImColor color)
    {
        int X = Location.x;
        int Y = Location.y;
        int W = Location1.x;
        int H = Location1.y;

        float lineW = (W / 1);
        float lineH = (Location1.y / 1);

        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), color, globals->fBoxThick);
    }

    void K2_DrawBoxFilled(ImVec2 Location, ImVec2 Location1, ImColor color)
    {
        ImGui::GetForegroundDrawList()->AddRectFilled(Location, ImVec2(Location.x + Location1.x, Location.y + Location1.y), color, globals->fBoxThick);
        ImGui::GetForegroundDrawList()->AddRect(Location, ImVec2(Location.x + Location1.x, Location.y + Location1.y), ImColor(0, 0, 0, 100), globals->fBoxThick + 3.f);
    }

    /*ImVec2 K2_DrawCornerBox(ImVec2 Location, ImVec2 Location1, ImColor color)
    {
        ImGui::GetForegroundDrawList()->AddRectFilled(Location, ImVec2(Location.x + Location1.x, Location.y + Location1.y), color, 2.f);
        ImGui::GetForegroundDrawList()->AddRectFilled(Location, ImVec2(Location.x + Location1.x, Location.y + Location1.y), ImColor(0, 0, 0, 255), 4.f);
    }*/

    __forceinline void K2_DrawOutlinedString(ImVec2 pos, ImColor color, std::string text)
    {
        std::stringstream stream(text);
        std::string line;

        float y = 0.0f;
        int i = 0;

        while (std::getline(stream, line))
        {
            ImVec2 textSize = ImGui::CalcTextSize(line.c_str());
            ImGui::PushFont(Roboto);

            ImGui::GetForegroundDrawList()->AddText(ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), color, line.c_str());
            ImGui::PopFont();
            y = pos.y + textSize.y * (i + 1);
            i++;
        }
    }

}; static _UCanvas_* UCanvas = new _UCanvas_();
inline std::wstring MBytesToWString(const char* lpcszString)
{


    int len = strlen(lpcszString);
    int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
    wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
    memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
    ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
    std::wstring wString = (wchar_t*)pUnicode;
    delete[] pUnicode;
    return wString;
}
inline std::string WStringToUTF8(const wchar_t* lpwcszWString)
{


    char* pElementText;
    int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
    pElementText = new char[iTextLen + 1];
    memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
    ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
    std::string strReturn(pElementText);
    delete[] pElementText;
    return strReturn;
}
inline void K2_DrawOutlinedText(float fontSize, int x, int y, ImColor color, bool bCenter, bool stroke, const char* pText, ...)
{
    va_list va_alist;
    char buf[1024] = { 0 };
    va_start(va_alist, pText);
    _vsnprintf_s(buf, sizeof(buf), pText, va_alist);
    va_end(va_alist);
    std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
    if (bCenter)
    {
        ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
        x = x - textSize.x / 4;
        y = y - textSize.y;
    }
    if (stroke)
    {
        ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
        ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
        ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
        ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
    }
    ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImColor(color), text.c_str());
}

enum InjectedInputMouseOptions
{
    move = 1,
    left_up = 4,
    left_down = 2,
    right_up = 8,
    right_down = 16
};

struct InjectedInputMouseInfo
{
    int move_direction_x;
    int move_direction_y;
    unsigned int mouse_data;
    InjectedInputMouseOptions mouse_options;
    unsigned int time_offset_in_miliseconds;
    void* extra_info;
};

inline bool(*_NtUserInjectMouseInput)(InjectedInputMouseInfo*, int) = nullptr;

inline bool has_clicked;
inline std::chrono::steady_clock::time_point tb_begin;
inline std::chrono::steady_clock::time_point tb_end;
inline int tb_time_since;

inline HWND fortnite_handle = FindWindowA(NULL, "Fortnite  ");

inline auto IsShootable(FVector lur, FVector wl) -> bool {

    if (lur.x >= wl.x - 20 && lur.x <= wl.x + 20 && lur.y >= wl.y - 20 && lur.y <= wl.y + 20 && lur.z >= wl.z - 30 && lur.z <= wl.z + 30)
        return true;
    else
        return false;

}

struct _AController_
{
    auto WINAPI set_cursor_position(int X, int Y, unsigned int time = 0) -> BOOLEAN {
        InjectedInputMouseInfo temp = {};
        temp.mouse_data = 0;
        temp.mouse_options = InjectedInputMouseOptions::move;
        temp.move_direction_x = X;
        temp.move_direction_y = Y;
        temp.time_offset_in_miliseconds = time;
        return _NtUserInjectMouseInput(&temp, 1);
    }
    void SetControlRotation(float x, float y)
    {
        FVector center(globals->width / 2, globals->height / 2, 0);
        FVector target(0, 0, 0);

        if (x != 0) {
            if (x > center.x) {
                target.x = -(center.x - x);
                target.x /= (globals->fSmooth);
                if (target.x + center.x > center.x * 2)
                    target.x = 0;
            }

            if (x < center.x) {
                target.x = x - center.x;
                target.x /= (globals->fSmooth);
                if (target.x + center.x < 0)
                    target.x = 0;
            }
        }
        if (y != 0) {
            if (y > center.y) {
                target.y = -(center.y - y);
                target.y /= (globals->fSmooth);
                if (target.y + center.y > center.y * 2)
                    target.y = 0;
            }

            if (y < center.y) {
                target.y = y - center.y;
                target.y /= (globals->fSmooth);
                if (target.y + center.y < 0)
                    target.y = 0;
            }
        }

        const float snapThreshold = 1.0f;
        if (std::abs(target.x) < snapThreshold) {
            target.x = 0;
        }
        if (std::abs(target.y) < snapThreshold) {
            target.y = 0;
        }

        set_cursor_position(target.x, target.y);
    }
}; static _AController_* AController = new _AController_();