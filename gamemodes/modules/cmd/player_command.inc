CMD:find(playerid, params[])
{
    new targetId,
        Float:posX,
        Float:posY,
        Float:posZ;

    if(sscanf(params, "u", targetId))
        return SendClientMessage(playerid, COLOR_USAGE, "USAGE: {ffffff}/find <id/player>");

    if(!IsPlayerConnected(targetId))
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Player tidak terkoneksi kedalam server");

    GetPlayerPos(targetId, posX, posY, posZ);
    g_CP[playerid] = 1;
    SetPlayerCheckpoint(playerid, posX, posY, posZ, 2);
    SendClientMessage(playerid, COLOR_SERVER, "SERVER: {ffffff}Pemain sudah tertandai dimap!");
    return 1;
}

CMD:disablecp(playerid)
{
    g_CP[playerid] = 0;
    DisablePlayerCheckpoint(playerid);
    SendClientMessage(playerid, COLOR_INFO, "INFO: {ffffff}Anda berhasil mematikan checkpoint");
    return 1;
}

CMD:tes(playerid)
{
    GameTextForPlayer(playerid, "Halo, kamu ~r~gay ya", 2000, 0);
    return 1;
}

// /stats 
CMD:stats(playerid)
{
    ShowStats(playerid);
    return 1; 
}

CMD:updatedata(playerid)
{
    UpdateDataPlayer(playerid);

    SendClientMessage(playerid, COLOR_WHITE, "Berhasil menyimpan data pemain!");
    return 1;
}

CMD:admins(playerid)
{
    new count;
    foreach(new i : Player)
    {
        if(!isPlayerLogged(playerid)) continue;
        if(g_PlayerData[i][pAdminLevel] < ADMIN_MODERATOR) continue;
        count++;
    }

    SendInfoMessage(playerid, "Admin yang sedang online : %d", count);
    return 1;
}

// CMD:tesmarker(playerid, params[])
// {
//     new targetId;
//     if(sscanf(params, "u", targetId))
//         return USAGE(playerid, "/tesmarker <id target>");
    
//     SetPlayerMarkerForPlayer(playerid, targetId, 0xFF0000FF);
//     SUCCESS(playerid, "Player ditandai dimap");
//     return 1;
// }