stock SetAdminLevel(targetID, level)
{
	if(!IsPlayerConnected(targetID) || !isPlayerLogged(targetID)) return 0;

	g_PlayerData[targetID][pAdminLevel] = level;

	new query[128];
	mysql_format(g_SQL, query, sizeof(query), "UPDATE ucp SET admin = '%d' WHERE ucp_name = '%e'", level, g_PlayerData[targetID][pUCP]);
	mysql_tquery(g_SQL, query);

	printf("[ADMIN] Level admin dari UCP %s telah diubah ke %d", g_PlayerData[targetID][pUCP], level);
	return 1;
}

stock SetAdminName(playerid, const name[])
{
	if(!IsPlayerConnected(playerid) || !isPlayerLogged(playerid)) return 0;

	format(g_PlayerData[playerid][pAdminName], MAX_PLAYER_NAME, "%s", name);
	new query[128];
	mysql_format(g_SQL, query, sizeof(query), "UPDATE ucp SET admin_name = '%e' WHERE ucp_name = '%e'", g_PlayerData[playerid][pAdminName], g_PlayerData[playerid][pUCP]);
	mysql_tquery(g_SQL, query);

	printf("[ADMIN] Nama admin dari UCP %s telah diubah ke %s", g_PlayerData[playerid][pUCP], g_PlayerData[playerid][pAdminName]);
	return 1;
}

stock ToggleAdminDuty(playerid, bool:toggle)
{
	if(!isPlayerLogged(playerid) || !IsPlayerConnected(playerid)) return 0;

	g_PlayerData[playerid][isAdminDuty] = toggle;
	if(g_PlayerData[playerid][isAdminDuty] == true)
	{
		GetPlayerHealth(playerid, g_PlayerData[playerid][pHealth]);
		GetPlayerArmour(playerid, g_PlayerData[playerid][pArmor]);
	}
	
	if(toggle)
	{
		SetPlayerHealth(playerid, 99999.0);
		SetPlayerArmour(playerid, 99999.0);

		SetPlayerName(playerid, g_PlayerData[playerid][pAdminName]);
		SetPlayerColor(playerid, COLOR_ADUTY);
		SendInfoMessage(playerid, "Kamu telah melakukan On Duty");
	}
	else
	{
		SetPlayerHealth(playerid, g_PlayerData[playerid][pHealth]);
		SetPlayerArmour(playerid, g_PlayerData[playerid][pArmor]);

		SetPlayerColor(playerid, COLOR_WHITE);
		SetPlayerName(playerid, g_PlayerData[playerid][pName]);
		SetPlayerColor(playerid, COLOR_WHITE);
		SendInfoMessage(playerid, "Kamu telah melakukan Off Duty");
	}
	return 1;
}