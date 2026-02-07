stock UpdateDataPlayer(playerid)
{
    if(!g_PlayerData[playerid][isLogin]) return 1;

    GetPlayerPos(playerid, g_PlayerData[playerid][pPos][0], g_PlayerData[playerid][pPos][1], g_PlayerData[playerid][pPos][2]);
    GetPlayerFacingAngle(playerid, g_PlayerData[playerid][pPos][3]);
    g_PlayerData[playerid][pInterior] = GetPlayerInterior(playerid);
    g_PlayerData[playerid][pVirtual_World] = GetPlayerVirtualWorld(playerid);
    g_PlayerData[playerid][pSkin] = GetPlayerSkin(playerid);
    g_PlayerData[playerid][pMoney] = GetPlayerMoney(playerid);
    g_PlayerData[playerid][pLevel] = GetPlayerScore(playerid);

    if(!g_PlayerData[playerid][isAdminDuty])
    {
        GetPlayerHealth(playerid, g_PlayerData[playerid][pHealth]);
        GetPlayerArmour(playerid, g_PlayerData[playerid][pArmor]);    
    }

    new query[500];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE player SET birth_day = '%d', birth_month = '%d', birth_year = '%d', gender = '%d', \
        pos_x = %f, pos_y = %f, pos_z = %f, pos_a = %f, \
        health = %f, armor = %f, interior = %d, virtual_world = %d, skin = %d, money = %d, level = %d \
        WHERE id = %d LIMIT 1",
    g_PlayerData[playerid][pBirthDay], g_PlayerData[playerid][pBirthMonth], g_PlayerData[playerid][pBirthYear], g_PlayerData[playerid][pGender],
    g_PlayerData[playerid][pPos][0], g_PlayerData[playerid][pPos][1], g_PlayerData[playerid][pPos][2], 
    g_PlayerData[playerid][pPos][3], g_PlayerData[playerid][pHealth], g_PlayerData[playerid][pArmor], g_PlayerData[playerid][pInterior], g_PlayerData[playerid][pVirtual_World], 
    g_PlayerData[playerid][pSkin], g_PlayerData[playerid][pMoney], g_PlayerData[playerid][pLevel],
    g_PlayerData[playerid][pID]);

    mysql_tquery(g_SQL, query);
    return 1;
}

Callback::OnCharacterDataLoaded(playerid)
{
    CalculateTickCount(playerid, "Load Character");

	cache_get_value_name_int(0, "id", g_PlayerData[playerid][pID]);

    if(g_PlayerData[playerid][pID] < 1)
    {
        SendErrorMessage(playerid, "Akun ini tidak terdaftar dalam database");
        KickEx(playerid);
        return 1;
    }

    cache_get_value_name_int(0, "birth_day", g_PlayerData[playerid][pBirthDay]);
    cache_get_value_name_int(0, "birth_month", g_PlayerData[playerid][pBirthMonth]);
    cache_get_value_name_int(0, "birth_year", g_PlayerData[playerid][pBirthYear]);
    cache_get_value_name_int(0, "gender", g_PlayerData[playerid][pGender]);

	cache_get_value_name_float(0, "pos_x", g_PlayerData[playerid][pPos][0]);
	cache_get_value_name_float(0, "pos_y", g_PlayerData[playerid][pPos][1]);
	cache_get_value_name_float(0, "pos_z", g_PlayerData[playerid][pPos][2]);
	cache_get_value_name_float(0, "pos_a", g_PlayerData[playerid][pPos][3]);

    cache_get_value_name_float(0, "health", g_PlayerData[playerid][pHealth]);
    cache_get_value_name_float(0, "armor", g_PlayerData[playerid][pArmor]);

	cache_get_value_name_int(0, "interior", g_PlayerData[playerid][pInterior]);
	cache_get_value_name_int(0, "virtual_world", g_PlayerData[playerid][pVirtual_World]);
	cache_get_value_name_int(0, "skin", g_PlayerData[playerid][pSkin]);
	cache_get_value_name_int(0, "money", g_PlayerData[playerid][pMoney]);
	cache_get_value_name_int(0, "level", g_PlayerData[playerid][pLevel]);

    g_PlayerData[playerid][isLogin] = true;
    SetSpawnInfo(playerid, NO_TEAM, g_PlayerData[playerid][pSkin], g_PlayerData[playerid][pPos][0], g_PlayerData[playerid][pPos][1], g_PlayerData[playerid][pPos][2], g_PlayerData[playerid][pPos][3], WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
    SpawnPlayer(playerid);
    GetPlayerNameEx(playerid);
    
    SetPlayerInterior(playerid, g_PlayerData[playerid][pInterior]);
    SetPlayerVirtualWorld(playerid, g_PlayerData[playerid][pVirtual_World]);
    GivePlayerMoney(playerid, g_PlayerData[playerid][pMoney]);
    SetPlayerScore(playerid, g_PlayerData[playerid][pLevel]);
    SetPlayerHealth(playerid, g_PlayerData[playerid][pHealth]);
    SetPlayerArmour(playerid, g_PlayerData[playerid][pArmor]);
    SetPlayerColor(playerid, COLOR_WHITE);
	return 1;
}