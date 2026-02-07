CMD:OtomatisAdmin(playerid)
{
    SetAdminLevel(playerid, 4);

    SendAdminInfo(playerid, "Level berhasil diubah");
    return 1;
}

CMD:changeadminname(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new aname[24];
    if(sscanf(params, "s[24]", aname)) return SendUsageMessage(playerid, "/changeadminname <Name>");

    SetAdminName(playerid, aname);
    SendAdminInfo(playerid, "Nama admin berhasil diubah ke %s", g_PlayerData[playerid][pAdminName]);
    return 1;
}

CMD:aduty(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new bool:toggle = g_PlayerData[playerid][isAdminDuty];
    ToggleAdminDuty(playerid, !toggle);
    return 1;
}

CMD:addmoney(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId, 
        amountMoney;

    if(sscanf(params, "ui", targetId, amountMoney)) 
        return SendUsageMessage(playerid, "/addmoney <ID> <Uang>");

    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");

    if(amountMoney < 0 || amountMoney > 10000000) 
        return SendErrorMessage(playerid, "Jumlah uang tidak boleh kurang 0 atau lebih dari 10000000!");

    GivePlayerMoneyEx(targetId, amountMoney);

    // info untuk player
    SendSuccessMessage(playerid, "Kamu berhasil menambah uang dari %s sebanyak %d", g_PlayerData[targetId][pName], amountMoney);

    // info untuk target 
    SendInfoMessage(targetId, "Kamu mendapatkan uang dari %s sebanyak %d", g_PlayerData[playerid][pName], amountMoney);
    return 1;
}

CMD:kick(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId,
        reasonKick[64];

    if(sscanf(params, "us[64]", targetId, reasonKick)) 
        return SendUsageMessage(playerid, "/kick <ID> <Reason>");

    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");

    KickEx(targetId);
    // info untuk player
    SendSuccessMessage(playerid, "Kamu telah menendang %s keluar server dengan alasan %s", g_PlayerData[targetId][pName], reasonKick);

    // info untuk target
    SendInfoMessage(targetId, "Kamu telah ditendang keluar server oleh %s dengan alasan %s", g_PlayerData[playerid][pName], reasonKick);
    return 1;
}

CMD:sethp(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId, 
        Float:healthPlayer;

    if(sscanf(params, "uf", targetId, healthPlayer)) 
        return SendUsageMessage(playerid, "/sethp <ID> <Health>");

    if(!IsPlayerConnected(targetId)) 
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");

    if(healthPlayer > 100.00 || healthPlayer < 0) 
        return SendErrorMessage(playerid, "Health tidak bisa kurang dari 0 atau lebih dari 100!");

    SetPlayerHealth(targetId, healthPlayer);
    g_PlayerData[targetId][pHealth] = healthPlayer;

    // info untuk player
    SendSuccessMessage(playerid, "Kamu telah mengubah health dari %s sebanyak %.2f", g_PlayerData[targetId][pName], healthPlayer);

    // info untuk target
    SendInfoMessage(targetId, "Health kamu telah diubah oleh %s sebanyak %.2f", g_PlayerData[playerid][pName], healthPlayer);
    return 1;
}

CMD:setarmor(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId,
        Float:amountArmor;

    if(sscanf(params, "uf", targetId, amountArmor))
        return SendUsageMessage(playerid, "/setarmor <ID> <Armour>");

    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");

    if(amountArmor < 0 || amountArmor > 100.00) 
        return SendClientMessage(playerid, COLOR_ERROR, "ERROR: {ffffff}Armor tidak bisa kurang dari 0 atau lebih dari 100!");
    
    SetPlayerArmour(targetId, amountArmor);
    g_PlayerData[targetId][pArmor] = amountArmor;

    // info untuk player
    SendSuccessMessage(playerid, "Kamu telah mengubah armor dari %s sebanyak %.2f", g_PlayerData[targetId][pName], amountArmor);

    // info untuk target
    SendInfoMessage(targetId, "Armor kamu telah diubah oleh %s sebanyak %.2f", g_PlayerData[playerid][pName], amountArmor);
    return 1;
}

CMD:gotopos(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new Float:posX,
        Float:posY,
        Float:posZ;

    if(sscanf(params, "fff", posX, posY, posZ))
        return SendUsageMessage(playerid, "/gotopos <X> <Y> <Z>");

    SetPlayerPos(playerid, posX, posY, posZ);
    SendSuccessMessage(playerid, "Anda telah teleport ke koordinat X:%.4f Y:%.4f Z:%.4f", posX, posY, posZ);
    return 1;
}

CMD:setlevel(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId, 
        amountLevel;
    if(sscanf(params, "ud", targetId, amountLevel)) 
        return SendUsageMessage(playerid, "/setlevel <ID> <Level>");

    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");
    
    SetPlayerScore(targetId, amountLevel);
    g_PlayerData[targetId][pLevel] = amountLevel;

    // info untuk player
    SendSuccessMessage(playerid, "Kamu berhasil mengubah level dari player %s ke level %d", g_PlayerData[targetId][pName], amountLevel);

    // info untuk target
    SendInfoMessage(targetId, "Level kamu diubah oleh %s ke level %d", g_PlayerData[playerid][pName], amountLevel);
    return 1;
}

CMD:setinterior(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId, 
        interior;

    if(sscanf(params, "ud", targetId, interior)) 
        return SendUsageMessage(playerid, "/setinterior <ID> <Interior>");
    
    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");
    
    SetPlayerInterior(playerid, interior);
    g_PlayerData[targetId][pInterior] = interior;

    // info player
    SendSuccessMessage(playerid, "Kamu telah mengubah interior dari %s ke %d", g_PlayerData[targetId][pName], interior);

    // info untuk target
    SendInfoMessage(targetId, "Interior kamu telah diubah oleh %s ke %d", g_PlayerData[playerid][pName], interior);
    return 1;
}

CMD:setskin(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId,
        skinId;
    
    if(sscanf(params, "ud", targetId, skinId))
        return SendUsageMessage(playerid, "/setskin <ID> <SkinID>");

    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");
    
    if(skinId < 0 || skinId > 311)
        return SendErrorMessage(playerid, "Id skin tidak boleh kurang dari 0 atau lebih dari 311!");
    
    SetPlayerSkin(targetId, skinId);
    g_PlayerData[targetId][pSkin] = skinId;

    // info untuk player
    SendSuccessMessage(playerid, "Kamu telah mengubah skin dari %s ke id %d", g_PlayerData[targetId][pName], skinId);
    // info utntuk target
    SendInfoMessage(targetId, "Skin kamu telah diubah oleh %s ke id %d", g_PlayerData[playerid][pName], skinId);
    return 1;
}

CMD:setvw(playerid, params[])
{
    if(g_PlayerData[playerid][pAdminLevel] < ADMIN_MODERATOR) return NoPermision(playerid);

    new targetId,
        vwId;

    if(sscanf(params, "ud", targetId, vwId))
        return SendUsageMessage(playerid, "/setvw <ID> <VW>");
    
    if(!IsPlayerConnected(targetId))
        return SendErrorMessage(playerid, "Player tidak terkoneksi kedalam server!");
    
    SetPlayerVirtualWorld(targetId, vwId);
    g_PlayerData[targetId][pVirtual_World] = vwId;

    // info untuk player
    SendSuccessMessage(playerid, "Kamu telah mengubah virtual world dari %s ke id %d", g_PlayerData[targetId][pName], vwId);

    // info Untuk target
    SendInfoMessage(targetId, "Virtual world kamu telah diubah oleh %s ke id %d", g_PlayerData[playerid][pName], vwId);
    return 1;
}
