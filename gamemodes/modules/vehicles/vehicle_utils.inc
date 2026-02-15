isVehicleBicycle(vehicleid)
{
	if(GetVehicleModel(vehicleid) == 481 || GetVehicleModel(vehicleid) == 509 || GetVehicleModel(vehicleid) == 510) return 1;
	return 0;
}

SetVehicleParamsForAll(vehicleid, objective, doorLocked)
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		SetVehicleParamsForPlayer(vehicleid, i, objective, doorLocked);
	}
	return 1;
}

SetVehicleAllParamsOff(vehicleid)
{
	if(vehicleid == INVALID_VEHICLE_ID || !g_VehicleData[vehicleid][isExists]) return 0;

	g_VehicleData[vehicleid][vEngine] = VEHICLE_PARAMS_OFF;
	g_VehicleData[vehicleid][vLight] = VEHICLE_PARAMS_OFF;
	g_VehicleData[vehicleid][vAlarm] = VEHICLE_PARAMS_OFF;
	g_VehicleData[vehicleid][vLock] = VEHICLE_PARAMS_OFF;
	g_VehicleData[vehicleid][vBonnet] = VEHICLE_PARAMS_OFF;
	g_VehicleData[vehicleid][vBoot] = VEHICLE_PARAMS_OFF;
	g_VehicleData[vehicleid][vObjective] = VEHICLE_PARAMS_OFF;

	if(isVehicleBicycle(vehicleid))
	{
		g_VehicleData[vehicleid][vEngine] = VEHICLE_PARAMS_ON;
	}

	SetVehicleParamsEx(vehicleid, g_VehicleData[vehicleid][vEngine], g_VehicleData[vehicleid][vLight], g_VehicleData[vehicleid][vAlarm], g_VehicleData[vehicleid][vLock], g_VehicleData[vehicleid][vBonnet], g_VehicleData[vehicleid][vBoot], g_VehicleData[vehicleid][vObjective]);
	SetVehicleParamsForAll(vehicleid, g_VehicleData[vehicleid][vObjective], g_VehicleData[vehicleid][vLock]);
	return 1;
}