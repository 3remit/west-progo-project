KickEx(playerid)
{
	SetTimerEx("_KickDelay", 2000, false, "i", playerid);
	return 1;
}

forward _KickDelay(playerid);
public _KickDelay(playerid) 
{
	Kick(playerid);
	return 1;
}

CreateConnectionDatabase(const host[], const user[], const pass[], const db[])
{
	g_SQL = mysql_connect(host, user, pass, db);

	if(g_SQL == MYSQL_INVALID_HANDLE || mysql_errno(g_SQL) != 0)
	{
		print("[MYSQL] Koneksi gagal!");
		SendRconCommand("exit");
	}

	print("[MYSQL] Berhasil terhubung");
}

// unused Dialog
Dialog:DialogUnused(playerid, response, listitem, inputtext[])
{
	if(response) return 1;
	return 1;
}

stock StartTickCount(playerid)
{
	g_TickCount[playerid] = GetTickCount();
	return 1;
}

stock CalculateTickCount(playerid, const reason[] = "")
{
	new loadtime = GetTickCount() - g_TickCount[playerid];

	new message[128];
	format(message, sizeof(message), "[LOAD TIME] %s: %d ms", reason, loadtime);

	SendClientMessage(playerid, COLOR_SERVER, message);
    printf("Player %d load time: %d ms (%s)", playerid, loadtime, reason);
	return loadtime;
}

stock RandomEx(minValue, maxValue)
{
	if(minValue == maxValue)
		return minValue;

	if(minValue > maxValue)
	{
		new temp = minValue;
		minValue = maxValue;
		maxValue = temp;
	}

	return random(maxValue - minValue + 1) + minValue;
}

strreplace(source[], find, replace)
{
	new len = strlen(source);
	for(new i = 0; i < len; i++)
	{
		if(source[i] == find)
		{
			source[i] = replace;
		}
	}
	return 1;
}

ProximityChatDetector(playerid, Float:radius, const message[], color1, color2, color3, color4, color5)
{
	new Float:posX,
		Float:posY,
		Float:posZ;

	GetPlayerPos(playerid, posX, posY, posZ);

	foreach(new i : Player)
	{
		if(IsPlayerInRangeOfPoint(i, radius / 16, posX, posY, posZ))
		{
			SendClientMessage(i, color1, message);
		}
		else if(IsPlayerInRangeOfPoint(i, radius / 8, posX, posY, posZ))
		{
			SendClientMessage(i, color2, message);
		}
		else if(IsPlayerInRangeOfPoint(i, radius / 4, posX, posY, posZ))
		{
			SendClientMessage(i, color3, message);
		}
		else if(IsPlayerInRangeOfPoint(i, radius / 2, posX, posY, posZ))
		{
			SendClientMessage(i, color4, message);
		}
		else if(IsPlayerInRangeOfPoint(i, radius, posX, posY, posZ))
		{
			SendClientMessage(i, color5, message);
		}
	}
	return 1;
}