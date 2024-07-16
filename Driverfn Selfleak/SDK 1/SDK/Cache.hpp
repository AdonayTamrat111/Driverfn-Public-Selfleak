#pragma once
#include "SDK.hpp"
#include <thread>
#include "Crypt.h"

inline std::vector<PlayerCacheList> EntList;
inline std::vector<PlayerCacheList> TempEntList;



inline void EntityCache()
{
	for (;;)
	{
		TempEntList.clear();

		/*Pointers->World = Engine->GetWorld();
		Pointers->GameInstance = Engine->GetGameInstance(Pointers->World);
		Pointers->GameState = Engine->GetGameState(Pointers->World);

		Pointers->LocalPlayers = ULocalPlayer->GetLocalPlayer(Pointers->GameInstance);

		Pointers->PlayerController = Engine->GetPlayerController(Pointers->LocalPlayers);

		Pointers->Apawn = APawn->GetPawn(Pointers->PlayerController);
		Pointers->RootComponent = APawn->GetRootComponent(Pointers->Apawn);

		Pointers->PlayerArray = AGameStateAthena->GetPlayerArray(Pointers->GameState);
		Pointers->PlayerArraySize = AGameStateAthena->GetPlayerArraySize(Pointers->GameState);*/

		Pointers->World = io::Read<uintptr_t>(base_address + offset::uworld);
		//std::cout << pointer->uworld << std::endl;
		Pointers->GameInstance = io::Read<uintptr_t>(Pointers->World + offset::game_instance);
		//std::cout << pointer->game_instance << std::endl;

		Pointers->GameState = io::Read<uintptr_t>(Pointers->World + offset::game_state);
		//std::cout << pointer->game_state << std::endl;
		Pointers->LocalPlayers = io::Read<uintptr_t>(io::Read<uintptr_t>(Pointers->GameInstance + offset::local_player));
		//std::cout << pointer->local_player << std::endl;
		Pointers->PlayerController = io::Read<uintptr_t>(Pointers->LocalPlayers + offset::player_controller);
		//std::cout << pointer->player_controller << std::endl;
		Pointers->Apawn = io::Read<uintptr_t>(Pointers->PlayerController + offset::acknowledged_pawn);
		//std::cout << Pointers->acknowledged_pawn << std::endl;
		//Pointerss-> = io::Read<uintptr_t>(Pointers->acknowledged_pawn + offset::current_weapon);
		//std::cout << Pointers->current_weapon << std::endl;
		//Pointers->me = io::Read<uintptr_t>(pointer->acknowledged_pawn + offset::skeletal_mesh);
		//std::cout << pointer->skeletal_mesh << std::endl;
		Pointers->PlayerState = io::Read<uintptr_t>(Pointers->Apawn + offset::player_state);
		//std::cout << pointer->player_state << std::endl;
		Pointers->RootComponent = io::Read<uintptr_t>(Pointers->Apawn + offset::root_component);
		//std::cout << pointer->root_component << std::endl;
		//Pointers-> = io::Read<int>(pointer->player_state + offset::team_index);
		//std::cout << pointer->team_index << std::endl;
		Pointers->RelativeLocation = io::Read<FVector>(Pointers->RootComponent + offset::relative_location);
		Pointers->PlayerArray = io::Read<uintptr_t>(Pointers->GameState + offset::player_array);
		//std::cout << pointer->player_array << std::endl;
		Pointers->PlayerArraySize = io::Read<int>(Pointers->GameState + (offset::player_array + sizeof(uintptr_t)));

		for (int i = 0; i < Pointers->PlayerArraySize; i++)
		{
			auto player_state = io::Read<uintptr_t>(Pointers->PlayerArray + (i * sizeof(uintptr_t)));
			auto current_actor = io::Read<uintptr_t>(player_state + offset::pawn_private);

			if (current_actor == Pointers->Apawn) continue;

			auto skeletalmesh = io::Read<uintptr_t>(current_actor + offset::skeletal_mesh);
			if (!skeletalmesh) continue;

			auto base_bone = ASkeleton->GetBoneLocation(skeletalmesh, bone::HumanHead);
			if (base_bone.x == 0 && base_bone.y == 0 && base_bone.z == 0) continue;

			if (!InScreen(APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(skeletalmesh, bone::HumanHead)))) continue;

			auto is_despawning = (io::Read<char>(current_actor + 0x758) >> 3); //bDying or bIsDying
			if (is_despawning) continue;

			PlayerCacheList cached_actors{};
			cached_actors.actor = current_actor;
			cached_actors.skeletal_mesh = io::Read<uintptr_t>(current_actor + offset::skeletal_mesh);
			cached_actors.relative_location = io::Read<FVector>(current_actor + offset::relative_location);
			cached_actors.root_component = io::Read<uintptr_t>(current_actor + offset::root_component);
			cached_actors.player_state = io::Read<uintptr_t>(current_actor + offset::player_state);
			cached_actors.team_index = io::Read<int>(cached_actors.player_state + offset::team_index);
			TempEntList.push_back(cached_actors);
		}

		EntList.clear();
		EntList = TempEntList;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}


inline float target_dist = FLT_MAX;
inline uintptr_t target_entity = NULL;

inline void EntityLoop()
{
	target_dist = FLT_MAX;
	target_entity = NULL;
	APlayerCameraManager->UpdateCamera();

	/*for (LootEntity LEntityList : LootentityList)
	{
		uintptr_t ItemRootComponent = io::Read<uintptr_t>(LEntityList.ACurrentItem + offset::root_component);
		FVector ItemPosition = io::Read<FVector>(ItemRootComponent + 0x120);
		float ItemDist = Pointers->RelativeLocation.Distance(ItemPosition) / 100.f;
		std::string null = ("");

		if (strstr(LEntityList.GNames.c_str(), (E("Tiered_Chest"))) && globals->bChest)
		{
			if (ItemDist < globals->iLootDistance) {
				FVector2d ChestPosition;
				ChestPosition = APlayerCameraManager->ProjectWorldToScreen(ItemPosition);
				std::string Text = null + ("Chest [") + std::to_string((int)ItemDist) + ("m]");
				UCanvas->K2_DrawOutlinedString(ImVec2(ChestPosition.x, ChestPosition.y), ImColor(0, 0, 255, 255), Text.c_str());
			}
		}

		else if ((globals->bVehicles && (strstr(LEntityList.GNames.c_str(), E("Vehicl")) || strstr(LEntityList.GNames.c_str(), E("Valet_Taxi").decrypt()) || strstr(LEntityList.GNames.c_str(), E("Valet_BigRig")) || strstr(LEntityList.GNames.c_str(), E("Valet_BasicTr")) || strstr(LEntityList.GNames.c_str(), E("Valet_SportsC")) || strstr(LEntityList.GNames.c_str(), E("Valet_BasicC")))))
		{
			if (ItemDist < globals->iLootDistance) {
				FVector2d VehiclePosition = APlayerCameraManager->ProjectWorldToScreen(ItemPosition);
				std::string Text = null + (E("Vehicle [").decrypt()) + std::to_string((int)ItemDist) + E("m]").decrypt();
				UCanvas->K2_DrawOutlinedString(ImVec2(VehiclePosition.x, VehiclePosition.y), ImColor(0, 0, 255, 255), Text.c_str());
			}
		}

		else if (strstr(LEntityList.GNames.c_str(), (E("AthenaSupplyDrop_C"))) && globals->bLoot)
		{
			if (ItemDist < globals->iLootDistance) {
				FVector2d ChestPosition;
				ChestPosition = APlayerCameraManager->ProjectWorldToScreen(ItemPosition);

				std::string Text = null + (E("Supply Drop [").decrypt()) + std::to_string((int)ItemDist) + E("m]").decrypt();
				UCanvas->K2_DrawOutlinedString(ImVec2(ChestPosition.x, ChestPosition.y), ImColor(0, 0, 255, 255), Text.c_str());

			}
		}

		else if (strstr(LEntityList.GNames.c_str(), (E("Tiered_Ammo"))) && globals->bAmmo)
		{
			if (ItemDist < globals->iLootDistance) {
				FVector2d ChestPosition;
				ChestPosition = APlayerCameraManager->ProjectWorldToScreen(ItemPosition);
				std::string Text = null + (E("Ammo Box [").decrypt()) + std::to_string((int)ItemDist) + (E("m]").decrypt());
				UCanvas->K2_DrawOutlinedString(ImVec2(ChestPosition.x, ChestPosition.y), ImColor(0, 0, 255, 255), Text.c_str());
			}
		}
	}*/

	for (auto& Entity : EntList) {
		auto root_location = ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanBase);
		auto root_screen = APlayerCameraManager->ProjectWorldToScreen(root_location);
		auto head_location = ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanHead);
		auto head_screen = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanHead));
		auto head_screen1 = ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanHead);

		float distance = Pointers->RelativeLocation.Distance(root_location) / 100;

		FVector2d head_box = APlayerCameraManager->ProjectWorldToScreen(FVector(head_screen1.x, head_screen1.y, head_screen1.z + 15));
		float box_height = abs(head_screen.y - root_screen.y);


		if (globals->bTrigger && GetAsyncKeyState(globals->iTriggerKey))
		{
			POINT cursor;
			GetCursorPos(&cursor);
			if (IsShootable(io::Read<FVector>(Pointers->PlayerController + offset::location_under_reticle), head_location)) {
				if (distance <= globals->fDistance) {
					if (has_clicked) {
						tb_begin = std::chrono::steady_clock::now();
						has_clicked = 0;
					}
					tb_end = std::chrono::steady_clock::now();
					tb_time_since = std::chrono::duration_cast<std::chrono::milliseconds>(tb_end - tb_begin).count();
					if (tb_time_since >= globals->fTriggerDelay) {
						PostMessage(fortnite_handle, WM_LBUTTONDOWN | MK_LBUTTON, 0, MAKELPARAM(cursor.x, cursor.y));
						PostMessage(fortnite_handle, WM_LBUTTONUP, 0, MAKELPARAM(cursor.x, cursor.y));
						has_clicked = 1;
					}
				}
			}
		}


		/*if (globals->bRadar)
		{
			ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
			ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize, ImGuiCond_Once);
			static const auto flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground;
			ImGui::Begin(("##radar"), nullptr, flags);

			float render_size = 5;
			ImDrawList* drawList = ImGui::GetWindowDrawList();

			if (rect) {
				drawList->AddRectFilled(ImVec2(x, y), ImVec2(x + size, y + size), ImGui::GetColorU32({ 0.13f, 0.13f, 0.13f, 1.f }), 0.0f, 0);
				drawList->AddRect(ImVec2(x, y), ImVec2(x + size, y + size), ImGui::GetColorU32({ 0.f, 0.f, 0.f, 1.f }), 0.0f, 0, 1.0f);
			}
			else {
				drawList->AddRectFilled(ImVec2(x, y), ImVec2(x + size, y + size), ImGui::GetColorU32({ 0.13f, 0.13f, 0.13f, 1.f }), 0.0f, 50);
				drawList->AddCircleFilled(ImVec2(x + size / 2, y + size / 2), render_size / 2 * sqrt(2), ImGui::GetColorU32({ 1.0f, 1.0f, 1.0f, 1.0f }), 1000);
				drawList->AddRect(ImVec2(x, y), ImVec2(x + size, y + size), ImGui::GetColorU32({ 0.f, 0.f, 0.f, 1.f }), 0.0f, 0, 1.0f);
			}

			ImGui::End();
		}*/

		if (globals->bVcheck)
		{
			if (hjesgrw346823(Entity.skeletal_mesh))
			{

				if (globals->bSnapLine)
				{
					UCanvas->K2_DrawLine(ImVec2(root_screen.x, root_screen.y), ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN)), ImColor(0, 255, 255, 255));
				}

				if (globals->bBox)
				{
					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));

					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.5f;
					UCanvas->K2_DrawBox(ImVec2(head_box.x - (CornerWidth / 2), head_box.y), ImVec2(CornerWidth, CornerHeight), ImColor(0, 255, 255, 255));
				}

				if (globals->bRoundBox) {

					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));
					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.5f;

					ImGui::GetForegroundDrawList()->AddRect(ImVec2(head_box.x - CornerWidth / 2, head_box.y), ImVec2((head_box.x - CornerWidth / 2) + CornerWidth, head_box.y + box_height), ImColor(0, 0, 0), 10, ImDrawCornerFlags_All, globals->fBoxThick + 2.0);
					ImGui::GetForegroundDrawList()->AddRect(ImVec2(head_box.x - CornerWidth / 2, head_box.y), ImVec2((head_box.x - CornerWidth / 2) + CornerWidth, head_box.y + box_height), ImColor(0, 255, 255), 10, ImDrawCornerFlags_All, globals->fBoxThick);

				}

				if (globals->bFillbox) {

					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));

					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.5f;

					UCanvas->K2_DrawBoxFilled(ImVec2(head_box.x - (CornerWidth / 2), head_box.y), ImVec2(CornerWidth, CornerHeight), ImColor(0, 0, 0, 100));
				}

				if (globals->bDistance)
				{
					std::string distance_string = E("").decrypt() + std::to_string((int)distance) + E("m").decrypt();
					std::string distance_string1 = E("").decrypt() + std::to_string((int)distance) + E("m | ").decrypt();
					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));
					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.50f;
					ImVec2 text_size = ImGui::CalcTextSize(distance_string.c_str());
					ImVec2 head_positionplat = ImVec2(ImVec2(head_box.x - (CornerWidth / 2) + head_box.x / 4 - 60, head_box.y - 25));
					ImVec2 head_positionplat1 = ImVec2(ImVec2(head_box.x - (CornerWidth / 2) + head_box.x / 4 - 120, head_box.y - 25));


					K2_DrawOutlinedText(15, root_screen.x - (text_size.x / 2), root_screen.y + 5, ImColor(0, 255, 255, 255), false, true, distance_string.c_str());
				}


				if (globals->bAim) {
					auto dx = head_screen.x - (globals->width / 2);
					auto dy = head_screen.y - (globals->height / 2);
					auto dist = sqrtf(dx * dx + dy * dy);

					if (dist < globals->field_of_view && dist < target_dist) {
						target_dist = dist;
						target_entity = Entity.actor;
					}
				}

				if (globals->bPlrName) {

					auto username = APawn->DecryptName(Entity.player_state);

					ImVec2 text_size = ImGui::CalcTextSize(username.c_str());

					if (globals->outline)
					{
						K2_DrawOutlinedText(15, head_box.x - (text_size.x / 2), head_box.y - 18, ImColor(0, 255, 255, 255), false, true, username.c_str());
					}
					else
					{
						K2_DrawOutlinedText(15, head_box.x - (text_size.x / 2), head_box.y - 18, ImColor(0, 255, 255, 255), false, false, username.c_str());
					}

				}

				if (globals->bSkeleton)
				{
					auto neck = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanNeck));
					auto left_shoulder = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 9));
					auto left_elbow = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLForearm23));
					auto left_hand = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLHand));
					auto right_shoulder = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 38));
					auto right_elbow = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRForearm23));
					auto right_hand = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRHand));
					auto pelvis = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanPelvis));
					auto left_hip = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLThigh1));
					auto left_knee = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLThigh3));
					auto left_foot = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLFoot2));
					auto right_hip = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRThigh1));
					auto right_knee = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRThigh3));
					auto right_foot = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRFoot2));

					/*ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(right_shoulder.x, right_shoulder.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(left_elbow.x, left_elbow.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_elbow.x, left_elbow.y), ImVec2(left_hand.x, left_hand.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_shoulder.x, right_shoulder.y), ImVec2(right_elbow.x, right_elbow.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_elbow.x, right_elbow.y), ImVec2(right_hand.x, right_hand.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(neck.x, neck.y), ImVec2(pelvis.x, pelvis.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(left_hip.x, left_hip.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_hip.x, left_hip.y), ImVec2(left_knee.x, left_knee.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_knee.x, left_knee.y), ImVec2(left_foot.x, left_foot.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(right_hip.x, right_hip.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_hip.x, right_hip.y), ImVec2(right_knee.x, right_knee.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_knee.x, right_knee.y), ImVec2(right_foot.x, right_foot.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);*/

					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(right_shoulder.x, right_shoulder.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(left_elbow.x, left_elbow.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_elbow.x, left_elbow.y), ImVec2(left_hand.x, left_hand.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_shoulder.x, right_shoulder.y), ImVec2(right_elbow.x, right_elbow.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_elbow.x, right_elbow.y), ImVec2(right_hand.x, right_hand.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(neck.x, neck.y), ImVec2(pelvis.x, pelvis.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(left_hip.x, left_hip.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_hip.x, left_hip.y), ImVec2(left_knee.x, left_knee.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_knee.x, left_knee.y), ImVec2(left_foot.x, left_foot.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(right_hip.x, right_hip.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_hip.x, right_hip.y), ImVec2(right_knee.x, right_knee.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_knee.x, right_knee.y), ImVec2(right_foot.x, right_foot.y), ImColor(0, 255, 255, 255), globals->fBoneThick);
				}
			}
			else
			{
				if (globals->bSnapLine)
				{
					UCanvas->K2_DrawLine(ImVec2(root_screen.x, root_screen.y), ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN)), ImColor(255, 0, 0, 255));
				}
				if (globals->bBox)
				{
					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));

					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.4f;
					UCanvas->K2_DrawBox(ImVec2(head_box.x - (CornerWidth / 2), head_box.y), ImVec2(CornerWidth, CornerHeight), ImColor(255, 0, 0, 255));
				}

				if (globals->bRoundBox) {

					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));
					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.5f;

					ImGui::GetForegroundDrawList()->AddRect(ImVec2(head_box.x - CornerWidth / 2, head_box.y), ImVec2((head_box.x - CornerWidth / 2) + CornerWidth, head_box.y + box_height), ImColor(0, 0, 0), 10, ImDrawCornerFlags_All, globals->fBoxThick + 2.0);
					ImGui::GetForegroundDrawList()->AddRect(ImVec2(head_box.x - CornerWidth / 2, head_box.y), ImVec2((head_box.x - CornerWidth / 2) + CornerWidth, head_box.y + box_height), ImColor(220, 20, 60), 10, ImDrawCornerFlags_All, globals->fBoxThick);

				}

				if (globals->bFillbox) {

					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));

					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.5f;

					UCanvas->K2_DrawBoxFilled(ImVec2(head_box.x - (CornerWidth / 2), head_box.y), ImVec2(CornerWidth, CornerHeight), ImColor(0, 0, 0, 100));
				}

				if (globals->bDistance)
				{
					std::string distance_string = E("").decrypt() + std::to_string((int)distance) + E("m").decrypt();
					std::string distance_string1 = E("").decrypt() + std::to_string((int)distance) + E("m | ").decrypt();
					auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));
					float CornerHeight = abs(head_box.y - root_box1.y);
					float CornerWidth = box_height * 0.50f;
					ImVec2 text_size = ImGui::CalcTextSize(distance_string.c_str());
					ImVec2 head_positionplat = ImVec2(ImVec2(head_box.x - (CornerWidth / 2) + head_box.x / 4 - 60, head_box.y - 25));
					ImVec2 head_positionplat1 = ImVec2(ImVec2(head_box.x - (CornerWidth / 2) + head_box.x / 4 - 120, head_box.y - 25));


					K2_DrawOutlinedText(15, root_screen.x - (text_size.x / 2), root_screen.y + 5, ImColor(255, 0, 0, 255), false, true, distance_string.c_str());
				}



				if (globals->bPlrName) {

					auto username = APawn->DecryptName(Entity.player_state);

					ImVec2 text_size = ImGui::CalcTextSize(username.c_str());

					if (globals->outline)
					{
						K2_DrawOutlinedText(15, head_box.x - (text_size.x / 2), head_box.y - 18, ImColor(255, 0, 0, 255), false, true, username.c_str());
					}
					else
					{
						K2_DrawOutlinedText(15, head_box.x - (text_size.x / 2), head_box.y - 18, ImColor(255, 0, 0, 255), false, false, username.c_str());
					}

				}

				if (globals->bSkeleton)
				{
					auto neck = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanNeck));
					auto left_shoulder = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 9));
					auto left_elbow = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLForearm23));
					auto left_hand = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLHand));
					auto right_shoulder = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 38));
					auto right_elbow = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRForearm23));
					auto right_hand = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRHand));
					auto pelvis = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanPelvis));
					auto left_hip = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLThigh1));
					auto left_knee = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLThigh3));
					auto left_foot = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLFoot2));
					auto right_hip = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRThigh1));
					auto right_knee = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRThigh3));
					auto right_foot = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRFoot2));

					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(right_shoulder.x, right_shoulder.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(left_elbow.x, left_elbow.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_elbow.x, left_elbow.y), ImVec2(left_hand.x, left_hand.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_shoulder.x, right_shoulder.y), ImVec2(right_elbow.x, right_elbow.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_elbow.x, right_elbow.y), ImVec2(right_hand.x, right_hand.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(neck.x, neck.y), ImVec2(pelvis.x, pelvis.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(left_hip.x, left_hip.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_hip.x, left_hip.y), ImVec2(left_knee.x, left_knee.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_knee.x, left_knee.y), ImVec2(left_foot.x, left_foot.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(right_hip.x, right_hip.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_hip.x, right_hip.y), ImVec2(right_knee.x, right_knee.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
					ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_knee.x, right_knee.y), ImVec2(right_foot.x, right_foot.y), ImColor(255, 0, 0, 255), globals->fBoneThick);
				}
			}
		}
		else
		{
			if (globals->bSnapLine)
			{
				UCanvas->K2_DrawLine(ImVec2(root_screen.x, root_screen.y), ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN)), ImColor(255, 255, 0, 255));
			}
			if (globals->bBox)
			{
				auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));

				float CornerHeight = abs(head_box.y - root_box1.y);
				float CornerWidth = box_height * 0.4f;
				UCanvas->K2_DrawBox(ImVec2(head_box.x - (CornerWidth / 2), head_box.y), ImVec2(CornerWidth, CornerHeight), ImColor(255, 255, 0, 255));
			}

			if (globals->bRoundBox) {

				auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));
				float CornerHeight = abs(head_box.y - root_box1.y);
				float CornerWidth = box_height * 0.5f;

				ImGui::GetForegroundDrawList()->AddRect(ImVec2(head_box.x - CornerWidth / 2, head_box.y), ImVec2((head_box.x - CornerWidth / 2) + CornerWidth, head_box.y + box_height), ImColor(0, 0, 0), 10, ImDrawCornerFlags_All, globals->fBoxThick + 2.0);
				ImGui::GetForegroundDrawList()->AddRect(ImVec2(head_box.x - CornerWidth / 2, head_box.y), ImVec2((head_box.x - CornerWidth / 2) + CornerWidth, head_box.y + box_height), ImColor(255, 255, 0), 10, ImDrawCornerFlags_All, globals->fBoxThick);

			}

			if (globals->bFillbox) {

				auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));

				float CornerHeight = abs(head_box.y - root_box1.y);
				float CornerWidth = box_height * 0.5f;

				UCanvas->K2_DrawBoxFilled(ImVec2(head_box.x - (CornerWidth / 2), head_box.y), ImVec2(CornerWidth, CornerHeight), ImColor(0, 0, 0, 100));
			}


			if (globals->bDistance)
			{
				std::string distance_string = E("").decrypt() + std::to_string((int)distance) + E("m").decrypt();
				std::string distance_string1 = E("").decrypt() + std::to_string((int)distance) + E("m | ").decrypt();
				auto root_box1 = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 0));
				float CornerHeight = abs(head_box.y - root_box1.y);
				float CornerWidth = box_height * 0.50f;
				ImVec2 text_size = ImGui::CalcTextSize(distance_string.c_str());
				ImVec2 head_positionplat = ImVec2(ImVec2(head_box.x - (CornerWidth / 2) + head_box.x / 4 - 60, head_box.y - 25));
				ImVec2 head_positionplat1 = ImVec2(ImVec2(head_box.x - (CornerWidth / 2) + head_box.x / 4 - 120, head_box.y - 25));


				K2_DrawOutlinedText(15, root_screen.x - (text_size.x / 2), root_screen.y + 5, ImColor(255, 255, 0, 255), false, true, distance_string.c_str());
			}


			if (globals->bPlrName) {

				auto username = APawn->DecryptName(Entity.player_state);

				ImVec2 text_size = ImGui::CalcTextSize(username.c_str());

				if (globals->outline)
				{
					K2_DrawOutlinedText(15, head_box.x - (text_size.x / 2), head_box.y - 18, ImColor(255, 255, 0, 255), false, true, username.c_str());
				}
				else
				{
					K2_DrawOutlinedText(15, head_box.x - (text_size.x / 2), head_box.y - 18, ImColor(255, 255, 0, 255), false, false, username.c_str());
				}

			}

			if (globals->bSkeleton)
			{
				auto neck = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanNeck));
				auto left_shoulder = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 9));
				auto left_elbow = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLForearm23));
				auto left_hand = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLHand));
				auto right_shoulder = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, 38));
				auto right_elbow = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRForearm23));
				auto right_hand = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRHand));
				auto pelvis = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanPelvis));
				auto left_hip = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLThigh1));
				auto left_knee = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLThigh3));
				auto left_foot = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanLFoot2));
				auto right_hip = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRThigh1));
				auto right_knee = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRThigh3));
				auto right_foot = APlayerCameraManager->ProjectWorldToScreen(ASkeleton->GetBoneLocation(Entity.skeletal_mesh, bone::HumanRFoot2));

				/*ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(right_shoulder.x, right_shoulder.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(left_elbow.x, left_elbow.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_elbow.x, left_elbow.y), ImVec2(left_hand.x, left_hand.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_shoulder.x, right_shoulder.y), ImVec2(right_elbow.x, right_elbow.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_elbow.x, right_elbow.y), ImVec2(right_hand.x, right_hand.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(neck.x, neck.y), ImVec2(pelvis.x, pelvis.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(left_hip.x, left_hip.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_hip.x, left_hip.y), ImVec2(left_knee.x, left_knee.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_knee.x, left_knee.y), ImVec2(left_foot.x, left_foot.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(right_hip.x, right_hip.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_hip.x, right_hip.y), ImVec2(right_knee.x, right_knee.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_knee.x, right_knee.y), ImVec2(right_foot.x, right_foot.y), ImColor(0, 0, 0), globals->fBoneThick + 2.5);*/
				//ImColor SkeletonColorImColor = ImColor::HSV(globals->SkeletonColor[1], globals->SkeletonColor[2], globals->SkeletonColor[3], globals->SkeletonColor[4]);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(right_shoulder.x, right_shoulder.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_shoulder.x, left_shoulder.y), ImVec2(left_elbow.x, left_elbow.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_elbow.x, left_elbow.y), ImVec2(left_hand.x, left_hand.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_shoulder.x, right_shoulder.y), ImVec2(right_elbow.x, right_elbow.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_elbow.x, right_elbow.y), ImVec2(right_hand.x, right_hand.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(neck.x, neck.y), ImVec2(pelvis.x, pelvis.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(left_hip.x, left_hip.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_hip.x, left_hip.y), ImVec2(left_knee.x, left_knee.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(left_knee.x, left_knee.y), ImVec2(left_foot.x, left_foot.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pelvis.x, pelvis.y), ImVec2(right_hip.x, right_hip.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_hip.x, right_hip.y), ImVec2(right_knee.x, right_knee.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(right_knee.x, right_knee.y), ImVec2(right_foot.x, right_foot.y), ImColor(255, 255, 0, 255), globals->fBoneThick);
			}
		}
	}

	if (globals->bAim) {
		if (globals->bPrediction)
		{
			FVector hitbox;
			auto closest_mesh = io::Read<uint64_t>(target_entity + offset::skeletal_mesh);
			hitbox = ASkeleton->GetBoneLocation(closest_mesh, bone::HumanHead);
			float projectileSpeed = 62000.f;
			float projectileGravityScale = 3.5f;
			float distance = ACamera::location.Distance(hitbox);
			auto test = io::Read<uintptr_t>(target_entity + offset::root_component);
			FVector Velocity = io::Read<FVector>(test + 0x168);
			FVector hitpredict = APawn->PredictLocation(hitbox, Velocity, projectileSpeed, projectileGravityScale, distance); // Reaper Sniper 
			FVector2d hitbox_screen_predict = APlayerCameraManager->ProjectWorldToScreen(hitpredict);
			Pointers->predictedloc = hitbox_screen_predict;
			if (hitbox.x != 0 || hitbox.y != 0 && (GetCrossDistance(hitbox.x, hitbox.y, globals->width / 2, globals->height / 2) <= globals->field_of_view))
			{
				if (hjesgrw346823(closest_mesh))
				{
					if (globals->bTargetLine) 
					{
						ImGui::GetForegroundDrawList()->AddLine(ImVec2(globals->width / 2, globals->height / 2), ImVec2(Pointers->predictedloc.x, Pointers->predictedloc.y), ImColor(255, 0, 0, 255), 1);
					}
					if (GetAsyncKeyState(globals->iAimKey))
						AController->SetControlRotation(Pointers->predictedloc.x, Pointers->predictedloc.y);
				}
			}
		}
		else
		{
			FVector hitbox;
			auto closest_mesh = io::readm<uint64_t>(target_entity + offset::skeletal_mesh);
			hitbox = ASkeleton->GetBoneLocation(closest_mesh, bone::HumanHead);
	
			FVector2d hitbox_screen = APlayerCameraManager->ProjectWorldToScreen(hitbox);
	
			if (hitbox.x != 0 || hitbox.y != 0 && (GetCrossDistance(hitbox.x, hitbox.y, globals->width / 2, globals->height / 2) <= globals->field_of_view))
			{
				if (hjesgrw346823(closest_mesh)) {
	
					if (globals->bTargetLine) {
						ImGui::GetForegroundDrawList()->AddLine(ImVec2(globals->width / 2, globals->height / 2), ImVec2(hitbox_screen.x, hitbox_screen.y), ImColor(255, 0, 0, 255), 1);
					}
	
					if (GetAsyncKeyState(globals->iAimKey) || globals->bAimLock)
						AController->SetControlRotation(hitbox_screen.x, hitbox_screen.y);
				}
			}
			else {
				target_dist = FLT_MAX;
				target_entity = NULL;
			}
		}
	}
}


