#pragma once
#include "../ext/minhook/minhook.h"

namespace hooks
{
	inline MH_STATUS CreateHook(uintptr_t address, void* hook, void* call);
	bool Setup();
	bool SetupPart2(IDirect3DDevice9* device);
	void Destroy();

	HRESULT __cdecl DxInitHook();
	static inline decltype(&DxInitHook) DxInit;

	long __stdcall EndSceneHook(IDirect3DDevice9* device);
	static inline decltype(&EndSceneHook) EndScene;

	HRESULT __stdcall ResetHook(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* params);
	static inline decltype(&ResetHook) Reset;

	bool __fastcall NeedsEncounterHook(void* traffic_manager);
	static inline decltype(&NeedsEncounterHook) NeedsEncounter;

	bool __fastcall NeedsTrafficHook(void* traffic_manager);
	static inline decltype(&NeedsTrafficHook) NeedsTraffic;

	bool __fastcall GpsEngageHook(void* gps, void* edx, nfsc::Vector3* vec3target, float max_deviation, bool re_engage, bool always_re_establish);
	static inline decltype(&GpsEngageHook) GpsEngage;

	void __fastcall WorldMapPadAcceptHook(void* fe_state_manager);
	static inline decltype(&WorldMapPadAcceptHook) WorldMapPadAccept;

	void __fastcall WorldMapButtonPressedHook(uintptr_t fe_state_manager, void* edx, int unk);
	static inline decltype(&WorldMapButtonPressedHook) WorldMapButtonPressed;

	void __fastcall WorldMapShowDialogHook(uintptr_t fe_state_manager);
	static inline decltype(&WorldMapShowDialogHook) WorldMapShowDialog;

	void __fastcall ResetDriveToNavHook(void* ai_vehicle, void* edx, int lane_selection);
	static inline decltype (&ResetDriveToNavHook) ResetDriveToNav;

	void* __fastcall RacerInfoCreateVehicleHook(uintptr_t racer_info, void* edx, uint32_t key, int racer_index, uint32_t seed);
	static inline decltype (&RacerInfoCreateVehicleHook) RacerInfoCreateVehicle;

	const char* __cdecl GetPursuitVehicleNameHook(bool is_player);
	static inline decltype (&GetPursuitVehicleNameHook) GetPursuitVehicleName;

	void __fastcall RaceStatusUpdateHook(void* race_status, void* edx, float dt);
	static inline decltype (&RaceStatusUpdateHook) RaceStatusUpdate;

	//void* __cdecl PursuitSwitchHook(int racer_index, bool is_busted, int* result);
	//static inline decltype (&PursuitSwitchHook) PursuitSwitch;

	float __fastcall GetTimeLimitHook(void* race_parameters);
	static inline decltype (&GetTimeLimitHook) GetTimeLimit;

	void __cdecl ShowLosingScreenHook();
	static inline decltype (&ShowLosingScreenHook) ShowLosingScreen;

	void __cdecl ShowWinningScreenHook();
	static inline decltype (&ShowWinningScreenHook) ShowWinningScreen;

	void __fastcall CareerManagerChildFlowDoneHook(uintptr_t fe_career_state_manager, void* edx, int unk);
	static inline decltype (&CareerManagerChildFlowDoneHook) CareerManagerChildFlowDone;

	//void CreateRoadBlockHook();
	void UpdateCopElementsHook1();
	void UpdateCopElementsHook2();
	//void UpdateRoadBlocksHook();
	void MoveVinylVerticalHook();
	void MoveVinylHorizontalHook();
	void VehicleChangeCacheHook();
	void UpdateAIPlayerListingHook();
	void PTagBustedHook();
}