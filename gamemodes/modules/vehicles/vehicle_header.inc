enum E_VEHICLE_DATA{
	vID,
	vOwner,
	vModel,
	Float: vPosX, Float: vPosY, Float: vPosZ, Float: vPosA,
	vColor1,
	vColor2,
	// temp
	bool:isExists,
	vCooldownSave,

	vEngine,
	vLight,
	vAlarm,
	vLock,
	vBonnet,
	vBoot,
	vObjective
		
};

new g_VehicleData[MAX_VEHICLES][E_VEHICLE_DATA];
new Iterator:PlayerVehicle<MAX_VEHICLES>; 