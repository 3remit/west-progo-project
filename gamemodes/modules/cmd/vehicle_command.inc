CMD:countvehicle(playerid)
{
    new count;
    foreach(new i : PlayerVehicle)
    {
        count++;
    }
    SendClientMessage(playerid, COLOR_WHITE, "Ada %d kendaraan terhitung didalam server", count);
    return 1;
}

CMD:parkveh(playerid)
{
    if(!IsPlayerInAnyVehicle(playerid))
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Kamu tidak sedang didalam mobil!");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Kamu tidak sedang didalam kursi kemudi!");

    new vehicleid = GetPlayerVehicleID(playerid);
    
    if(!g_VehicleData[vehicleid][isExists])   
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Kendaraan tidak terspawn!");

    if(g_VehicleData[vehicleid][vOwner] != g_PlayerData[playerid][pID])
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Kendaraan ini bukan milikmu!");

    if(g_VehicleData[vehicleid][vID] <= 0)
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Kendaraan ini tidak tersedia didalam database");

    GetVehiclePos(vehicleid, g_VehicleData[vehicleid][vPosX], g_VehicleData[vehicleid][vPosY], g_VehicleData[vehicleid][vPosZ]);
    GetVehicleZAngle(vehicleid, g_VehicleData[vehicleid][vPosA]);

    UpdateDataVehicle(vehicleid);
    SendClientMessage(playerid, COLOR_SERVER, "SERVER: {ffffff}Kendaraan kamu berhasil diparkirkan!");
    return 1;
}