stock AccountCheck(playerid)
{
    g_MysqlRaceCheck[playerid]++;

    GetPlayerName(playerid, g_PlayerData[playerid][pUCP], MAX_PLAYER_NAME);

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM ucp WHERE ucp_name = '%e' LIMIT 1", g_PlayerData[playerid][pUCP]);
    mysql_tquery(g_SQL, query, "OnUCPChecked", "dd", playerid, g_MysqlRaceCheck[playerid]);
    return 1;
}

stock CheckUserCharacter(playerid)
{
    g_MysqlRaceCheck[playerid]++;

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT username FROM player WHERE ucp = '%s' LIMIT %d", g_PlayerData[playerid][pUCP], MAX_CHARS);
    mysql_tquery(g_SQL, query, "OnCharacterLoaded", "dd", playerid, g_MysqlRaceCheck[playerid]);
    return 1;
}

stock ShowCharacterList(playerid)
{
    new name[268],
        str[128],
        count;

    for(new i; i < MAX_CHARS; i++)
    {
        if(PlayerCharacter[playerid][i][0] != EOS)
        {
            format(str, sizeof(str), "%s\n", PlayerCharacter[playerid][i]);
            strcat(name, str);
            count++;
        }
    }

    if(count < MAX_CHARS) strcat(name, "+ New Character");
    
    Dialog_Show(playerid, DialogListChar, DIALOG_STYLE_LIST, "List Character", name, "Choose", "Close");
    return 1;
}

stock ShowStats(playerid)
{
    new str[155], 
        strhead[64],
        client[8];
    if(!g_PlayerData[playerid][isOfficialClient])
        format(client, sizeof(client), "Android");
    else
        format(client, sizeof(client), "PC");
    
    format(strhead, sizeof(strhead), "%s|[%d]", g_PlayerData[playerid][pName], playerid);
    format(str, sizeof(str), "{ffffff}Client\t:\t%s\nID_Database\t:\t%d\nInterior\t:\t%d\nVirtual World\t:\t%d\nSkin\t:\t%d\nMoney\t:\t%d\nLevel\t:\t%d", 
    client, g_PlayerData[playerid][pID], 
    g_PlayerData[playerid][pInterior], g_PlayerData[playerid][pVirtual_World], 
    g_PlayerData[playerid][pSkin], g_PlayerData[playerid][pMoney],
    g_PlayerData[playerid][pLevel]);

    return Dialog_Show(playerid, DialogUnused, DIALOG_STYLE_MSGBOX, strhead, str, "Oke", "");
}

stock ParseBirthDate(playerid, const date[])
{
    new day,
        month,
        year;

    if(sscanf(date, "p</>ddd", day, month, year))
    {
        Dialog_Show(playerid, DialogAge, DIALOG_STYLE_INPUT, "Age", "{ffffff}Kamu memasukan format yang {B82B2B}salah!\n{ffffff}Masukan kembali tanggal lahir dengan format DD/MM/YYYY (16/01/2005)", "Input", "Tutup");
        return 0;
    }

    if(!IsValidDate(day, month, year))
    {
        Dialog_Show(playerid, DialogAge, DIALOG_STYLE_INPUT, "Age", "{ffffff}Kamu memasukan tanggal yang {B82B2B}tidak valid!\n{ffffff}Masukan kembali tanggal lahir dengan format DD/MM/YYYY dan valid!", "Input", "Tutup");
        return 0;
    }

    g_PlayerData[playerid][pBirthDay] = day;
    g_PlayerData[playerid][pBirthMonth] = month;
    g_PlayerData[playerid][pBirthYear] = year;
    Dialog_Show(playerid, DialogGender, DIALOG_STYLE_LIST, "Gender", "Male\nFemale", "Continue", "");
    return 1;
}

stock IsValidDate(day, month, year)
{
    if(year < 1900 || year > 2100) return 0;
    if(month < 1 || month > 12) return 0;
    if(day < 1) return 0;

    new daysInMonth[] = {
    31,28,31,30,31,30,31,31,30,31,30,31};

    return day <= daysInMonth[month - 1];
}

stock IsValidRPName(const name[])
{
    new len = strlen(name);

    if(len < 3 || len > MAX_PLAYER_NAME)
        return 0;

    new underscorePos = strfind(name, "_");
    if(underscorePos == -1)
        return 0;

    if(underscorePos == 0 || underscorePos == len - 1)
        return 0;

    if(name[0] < 'A' || name[0] > 'Z')
        return 0;

    if(name[underscorePos + 1] < 'A' || name[underscorePos + 1] > 'Z')
        return 0;

    for(new i = 0; i < len; i++)
    {
        if(name[i] == '_') continue;

        if(name[i] < 'a' || name[i] > 'z')
        {
            if(name[i] < 'A' || name[i] > 'Z')
                return 0;
        }
    }
    return 1;
}

CreateSetupCharacter(playerid)
{
    if(!g_PlayerData[playerid][isLogin]) return NoPermision(playerid);

    SetSpawnInfo(playerid, NO_TEAM, g_PlayerData[playerid][pSkin], DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_POS_Z, DEFAULT_POS_A, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
    GivePlayerMoneyEx(playerid, 5000);
    SpawnPlayer(playerid);
    return 1;
}

stock GetPlayerNameEx(playerid)
{   
    GetPlayerName(playerid, g_PlayerData[playerid][pName], MAX_PLAYER_NAME);
    return g_PlayerData[playerid][pName];
}

ResetValueVariable(playerid)
{
    g_PlayerData[playerid][pID] = -1;
    g_PlayerData[playerid][pName] = EOS;
    g_PlayerData[playerid][pSkin] = 0;
    g_PlayerData[playerid][pMoney] = 0;
    g_PlayerData[playerid][pLevel] = 0;
    g_PlayerData[playerid][pPos][0] = 0.0;
    g_PlayerData[playerid][pPos][1] = 0.0;
    g_PlayerData[playerid][pPos][2] = 0.0;
    g_PlayerData[playerid][pPos][3] = 0.0;
    g_PlayerData[playerid][pBirthDay] = 0;
    g_PlayerData[playerid][pBirthMonth] = 0;
    g_PlayerData[playerid][pBirthYear] = 0;
    g_PlayerData[playerid][pGender] = -1;

    g_PlayerData[playerid][pHealth] = 0.0;
    g_PlayerData[playerid][pArmor] = 0.0;

    // admin
    g_PlayerData[playerid][pAdminLevel] = 0;
    g_PlayerData[playerid][pAdminName] = EOS;
    g_PlayerData[playerid][isAdminDuty] = false;

    // bagian login register
    g_PlayerData[playerid][isLogin] = false;
    g_PlayerData[playerid][pLoginAttempt] = 0;
    g_PlayerData[playerid][isOfficialClient] = false;
    g_PlayerData[playerid][pVerifyCode] = 0;
    g_PlayerData[playerid][pActivation] = 0;

    return 1;
}

GivePlayerMoneyEx(playerid, ammount)
{
    GivePlayerMoney(playerid, ammount);
    g_PlayerData[playerid][pMoney] += ammount;
    return 1;
}