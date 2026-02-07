task UpdateCustomNameTag[2000]()
{
	foreach(new i : Player)
	{
		new str[128],
			name[MAX_PLAYER_NAME],
			Float:health,
			Float:armor;

		GetPlayerName(i, name, MAX_PLAYER_NAME);
		strreplace(name, '_', ' ');
		GetPlayerHealth(i, health);
		GetPlayerArmour(i, armor);

		if(armor > 1.0)
		{
			format(str, sizeof(str), "{%06x}%s {ffffff}(%d)\n{E4120C}HP : [%.2f] {ffffff}AM : [%.2f]", GetPlayerColor(i) >>> 8, name, i, health, armor);	
		}
		else
		{
			format(str, sizeof(str), "{%06x}%s {ffffff}(%d)\n{E4120C}HP : [%.2f]", GetPlayerColor(i) >>> 8, name, i, health);
		}

		UpdateDynamic3DTextLabelText(g_PlayerData[i][pNameTag], COLOR_WHITE, str);
	}
}