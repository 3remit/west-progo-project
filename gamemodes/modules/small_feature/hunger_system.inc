CMD:eat(playerid)
{
	new hunger = g_PlayerData[playerid][pHunger] += 10;
	if(g_PlayerData[playerid][pHunger] >= 100)
	{
		new left = hunger - 100;
		SendInfoMessage(playerid, "Kamu terlalu kenyang, kamu tidak bisa menghabiskan sisa makanan sebanyak %d%%", left);
		g_PlayerData[playerid][pHunger] = 100;
	}
	else
	{
		g_PlayerData[playerid][pHunger] = hunger;
		SendSuccessMessage(playerid, "Kamu berhasil makan, bar makan kamu %d", g_PlayerData[playerid][pHunger]);
	}
	UpdateDisplayHungerAndThirst(playerid);
	return 1;
}

CMD:sethunger(playerid, params[])
{
	new hunger;
	if(sscanf(params, "d", hunger)) return SendUsageMessage(playerid, "/sethunger <Value>");
	if(hunger > 100) return SendErrorMessage(playerid, "Limit stats lapar adalah 100!");

	g_PlayerData[playerid][pHunger] = hunger;
	UpdateDisplayHungerAndThirst(playerid);
	SendSuccessMessage(playerid, "Kamu berhasil mengubah stats hunger");
	return 1;
}

stock GetColorHungerThirst(value, dest[], size)
{
	if(value >= 70) format(dest, size, "~g~");
	else if(value >= 40) format(dest, size, "~y~");
	else format(dest, size, "~r~");
}

stock UpdateDisplayHungerAndThirst(playerid)
{
	new string[10];
	new color[4];

	GetColorHungerThirst(g_PlayerData[playerid][pHunger], color, sizeof(color));
	format(string, sizeof(string), "%s%d%%", color, g_PlayerData[playerid][pHunger]);
	PlayerTextDrawSetString(playerid, HungerAndThirst[playerid][2], string);

	GetColorHungerThirst(g_PlayerData[playerid][pThirst], color, sizeof(color));
	format(string, sizeof(string), "%s%d%%", color, g_PlayerData[playerid][pThirst]);
	PlayerTextDrawSetString(playerid, HungerAndThirst[playerid][3], string);
	return 1;
}

ptask UpdateHungerSystem[10000](playerid)
{
	if(!isPlayerLogged(playerid) || !IsPlayerConnected(playerid)) return 1;

	g_PlayerData[playerid][pHunger] -= 1;
	g_PlayerData[playerid][pThirst] -= 1;

	if(g_PlayerData[playerid][pHunger] < 0) g_PlayerData[playerid][pHunger] = 0;
	if(g_PlayerData[playerid][pThirst] < 0) g_PlayerData[playerid][pThirst] = 0;

	UpdateDisplayHungerAndThirst(playerid);

	if(g_PlayerData[playerid][pHunger] == 0 || g_PlayerData[playerid][pThirst] == 0)
	{
		defer CheckHungerThirstEffects(playerid);
	}
	return 1;
}

timer CheckHungerThirstEffects[5000](playerid)
{
	if(!isPlayerLogged(playerid) || !IsPlayerConnected(playerid)) return 1;

	new Float:currentHealth;
	GetPlayerHealth(playerid, currentHealth);

	if(g_PlayerData[playerid][pHunger] == 0 && g_PlayerData[playerid][pThirst] == 0)
	{
		SetPlayerHealth(playerid, currentHealth - 15.0);
		SendInfoMessage(playerid, "Kamu kelaparan dan kehausan! segera dapatkan makanan dan minuman");
	}
	else if(g_PlayerData[playerid][pHunger] == 0)
	{
		SetPlayerHealth(playerid, currentHealth - 5.0);
		SendInfoMessage(playerid, "Kamu kelaparan! segera dapatkan makanan");
	}
	else if(g_PlayerData[playerid][pThirst] == 0)
	{
		SetPlayerHealth(playerid, currentHealth - 5.0);
		SendInfoMessage(playerid, "Kamu kehausan! segera dapatkan minuman");
	}
	return 1;
}