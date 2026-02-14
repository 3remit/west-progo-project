/*                                                
                                       
▄▄▄▄▄▄▄                                
▀▀▀▀████                      ▀▀  ██   
  ▄▄██▀  ████▄ ▄█▀█▄ ███▄███▄ ██ ▀██▀▀ 
    ███▄ ██ ▀▀ ██▄█▀ ██ ██ ██ ██  ██   
███████▀ ██    ▀█▄▄▄ ██ ██ ██ ██▄ ██   
                                       
                                       
Gamemode by 3remit

credit to : - open.mp/openmultiplayer for base gamemode
						- Y-Less for sscanf
						- Y-Less for YSI Includes 
						- pBlueG for MySQL
						- Sreyas Sreelal for Samp Bcrypt
						- katursis for Pawn.CMD
						- samp-incognito for Streamer
						- vdgiapp for mSelection
						- Awsomedude for easyDialog
						- maddinat0r for Samp Discord Connector
						- AkshayMohan for Pawn Discord CMD                  
*/
#include <open.mp>

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

#undef MAX_VEHICLES
#define MAX_VEHICLES 100

#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_timers>

#include <streamer>
#include <Pawn.CMD>
#include <a_mysql>
#include <samp_bcrypt>
#include <sscanf2>
#include <easyDialog>
#include <mSelection>
#include <discord-connector>
#include <discord-cmd>
#include <streamer>

// server module 
#include "modules\server\server_define.inc"
#include "modules\server\server_macro.inc"
#include "modules\server\server_textdraw.pwn"
#include "modules\server\server_variable.inc"
#include "modules\server\server_utils.inc"

// player module
#include "modules\players\player_header.inc"
#include "modules\players\player_utils.inc"
#include "modules\players\player_callback.inc"
#include "modules\players\player_dialog.inc"
#include "modules\players\player_saveload.inc"

// admin module
#include "modules\admin\admin_header.inc"
#include "modules\admin\admin_function.inc"
#include "modules\admin\admin_command.inc"

// vehicle module
#include "modules\vehicles\vehicle_header.inc"
#include "modules\vehicles\vehicle_create.inc"
#include "modules\vehicles\vehicle_saveload.inc"

// public command module
#include "modules\cmd\vehicle_command.inc"
#include "modules\cmd\player_command.inc"

// file discord module
#include "modules\discord\discord_cmd.inc"
#include "modules\discord\discord_callback.inc"

// small_feature
#include "modules\small_feature\nametag_player.inc"
#include "modules\small_feature\date_system.inc"
#include "modules\small_feature\hunger_system.inc"

main(){
}

public OnGameModeInit()
{	
	ShowNameTags(false);

	DisableInteriorEnterExits();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);

	SetGameModeText(GAMEMODE);

	m_SkinSpawn = LoadModelSelectionMenu("male_spawnskin.txt");
	f_SkinSpawn = LoadModelSelectionMenu("female_spawnskin.txt");

	CreateConnectionDatabase(MYSQL_HOST, MYSQL_USER, MYSQL_PASS, MYSQL_DBNAME);
	
	CreateGlobalTextdraw();

	Iter_Init(PlayerVehicle);

	mysql_tquery(g_SQL, "SELECT * FROM vehicles", "OnVehicleLoaded", "");
	return 1;
}

public OnGameModeExit()
{
	mysql_close(g_SQL);
	foreach(new i : Player)
	{
		CallLocalFunction("OnPlayerDisconnect", "d", i);
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
	CreateTextdrawForPlayer(playerid);

	SetPlayerColor(playerid, COLOR_WHITE);

	for(new i = 0; i < 3; i++)
	{
		TextDrawShowForPlayer(playerid, ServerName[i]);
	}

	ResetValueVariable(playerid);
	
	AccountCheck(playerid);

	if (IsPlayerUsingOfficialClient(playerid))
		g_PlayerData[playerid][isOfficialClient] = true;

	g_PlayerData[playerid][pNameTag] = CreateDynamic3DTextLabel("Loading....", COLOR_WHITE, 0.0, 0.0, 0.1, NAMETAG_DISTANCE, .attachedplayer = playerid, .testlos = 1);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	g_MysqlRaceCheck[playerid]++;
	
	UpdateDataPlayer(playerid);
	SetPlayerName(playerid, g_PlayerData[playerid][pUCP]);

	DestroyAllTextdraw(playerid);

	if(IsValidDynamic3DTextLabel(g_PlayerData[playerid][pNameTag]))
	{
		DestroyDynamic3DTextLabel(g_PlayerData[playerid][pNameTag]);
	}

	g_PlayerData[playerid][isLogin] = false;
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if(!isPlayerLogged(playerid)) return Kick(playerid);

	for(new i = 0; i < 4; i++)
	{
		PlayerTextDrawShow(playerid, DateAndTime[playerid][i]);
	}

	for(new i = 0; i < 6; i++)
	{
		PlayerTextDrawShow(playerid, HungerAndThirst[playerid][i]);
	}
	
	g_PlayerData[playerid][pHunger] = 90;
	g_PlayerData[playerid][pThirst] = 90;
	UpdateDisplayHungerAndThirst(playerid);
	return 1;
}

public OnPlayerDeath(playerid, killerid, WEAPON:reason)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;

	new currentTime = gettime();
	if(currentTime - g_VehicleData[vehicleid][vCooldownSave] < 20) return 0;

	g_VehicleData[vehicleid][vCooldownSave] = currentTime;

	GetVehiclePos(vehicleid, g_VehicleData[vehicleid][vPos][0], g_VehicleData[vehicleid][vPos][1], g_VehicleData[vehicleid][vPos][2]);
	GetVehicleZAngle(vehicleid, g_VehicleData[vehicleid][vPos][3]);

	UpdateDataVehicle(vehicleid);
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	if(!isPlayerLogged(playerid))
	{
		SendClientMessage(playerid, COLOR_ERROR, "ERROR: Kamu tidak diizinkan menekan tombol spawn!");
		return 0;
	}
	return 1;
}

public OnPlayerText(playerid, text[])
{
	new msg[144];
	if(!g_PlayerData[playerid][isAdminDuty])
	{
		format(msg, sizeof(msg), "%s says %s", g_PlayerData[playerid][pName], text);
	}
	else
	{
		format(msg, sizeof(msg), "{FF1B1A}[ADMIN] %s {ffffff}: %s", g_PlayerData[playerid][pAdminName], text);
	}

	ProximityChatDetector(playerid, CHAT_RADIUS, msg, COLOR_WHITE, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4);

	return 0;
}

public OnPlayerEnterCheckpoint(playerid)
{
	if(g_CP[playerid] == 1)
	{
		DisablePlayerCheckpoint(playerid);
		g_CP[playerid] = 0;
		SendClientMessage(playerid, COLOR_SERVER, "SERVER: {ffffff}Kamu sudah sampai dicheckpoint!");
		return 1;
	}
	return 1;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
  if (result == -1)
  {
    SendClientMessage(playerid, COLOR_SERVER, "SERVER: {ffffff}Command tidak tersedia, /help untuk melihat command yang tersedia");
    return 0;
  }

  return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	SetPlayerPosFindZ(playerid, Float:fX, Float:fY, Float:fZ);
	SendClientMessage(playerid, COLOR_SERVER, "SERVER: Kamu melakukan teleport melalui map!");
	return 1;
}

public OnPlayerModelSelection(playerid, response, listid, modelid)
{
	if(listid == m_SkinSpawn) 
	{
		if(response)
		{
			g_PlayerData[playerid][pSkin] = modelid;
			
			new query[288];
			mysql_format(g_SQL, query, sizeof(query), "INSERT INTO player (username, ucp) VALUES ('%e', '%e')", g_PlayerData[playerid][pName], g_PlayerData[playerid][pUCP]);
			mysql_tquery(g_SQL, query, "OnInsertCharacter", "d", playerid);
		}
	}

	if(listid == f_SkinSpawn)
	{
		if(response)
		{
			g_PlayerData[playerid][pSkin] = modelid;
			
			new query[288];
			mysql_format(g_SQL, query, sizeof(query), "INSERT INTO player (username, ucp) VALUES ('%e', '%e')", g_PlayerData[playerid][pName], g_PlayerData[playerid][pUCP]);
			mysql_tquery(g_SQL, query, "OnInsertCharacter", "d", playerid);
		}
	}
	return 1;
}

