CMD:createvehicle(playerid, params[])
{
    new targetID, modelid, color1, color2;
    if(sscanf(params, "iiii", targetID, modelid, color1, color2))
        return SendClientMessage(playerid, COLOR_USAGE, "USAGE: {ffffff}/createprivateveh <ID> <ModelID> <Color1> <Color2>");
    
    if(!IsPlayerConnected(targetID) || !isPlayerLogged(targetID)) return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam sever!");
    
    if(modelid < 400 || modelid >611)
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Model id tidak boleh kurang dari 411 atau lebih dari 611!");
    
    new Float:x, Float:y, Float:z, Float:a;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);
    if(AddVeh(playerid, modelid, x, y, z, a, color1, color2))
    {
        SendClientMessage(playerid, COLOR_SUCCESS, "SUCCESS: {ffffff}Kamu berhasil membuat kendaraan!");
    }
    else
        SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Gagal membuat kendaraan!");
    return 1;
}

stock AddVeh(playerid, model, Float:x, Float:y, Float:z, Float:a, color1, color2)
{
    new vehicleid = CreateVehicle(model, x, y, z, a, color1, color2, -1, false);
    if(vehicleid == INVALID_VEHICLE_ID) return 0;
    

    g_VehicleData[vehicleid][vOwner] = g_PlayerData[playerid][pID];
    g_VehicleData[vehicleid][vModel] = model;
    g_VehicleData[vehicleid][vPosX] = x;
    g_VehicleData[vehicleid][vPosY] = y;
    g_VehicleData[vehicleid][vPosZ] = z;
    g_VehicleData[vehicleid][vPosA] = a;
    g_VehicleData[vehicleid][vColor1] = color1;
    g_VehicleData[vehicleid][vColor2] = color2;
    g_VehicleData[vehicleid][isExists] = true;
    SetVehicleAllParamsOff(vehicleid);

    Iter_Add(PlayerVehicle, vehicleid);

    new query[450];
    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO vehicles (owner_id, model, pos_x, pos_y, pos_z, pos_a, color1, color2) VALUES ('%d', '%d', '%f', '%f', '%f', '%f', '%d', '%d')", 
    g_PlayerData[playerid][pID], model, x, y, z, a, color1, color2);
    mysql_tquery(g_SQL, query, "OnVehicleCreated", "d", vehicleid);
    return 1;
}

Callback::OnVehicleCreated(vehicleid)
{
    new insert_id = cache_insert_id();
    if(vehicleid != INVALID_VEHICLE_ID && insert_id > 0)
    {
        g_VehicleData[vehicleid][vID] = insert_id;
    }
    printf("[VEHICLE] Sebuah kendaraan berhasil dibuat dengan id = %d",  g_VehicleData[vehicleid][vID]);
    return 1;
}

