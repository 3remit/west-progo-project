Callback::OnUCPChecked(playerid, race_check)
{
	if(race_check != g_MysqlRaceCheck[playerid]) return KickEx(playerid);

	new string[180];
	if(cache_num_rows() > 0)
	{
        cache_get_value_name_int(0, "verifycode", g_PlayerData[playerid][pVerifyCode]);
        cache_get_value_name_int(0, "activation", g_PlayerData[playerid][pActivation]);
		cache_get_value_name(0, "password", g_PlayerData[playerid][pPassword]);

        cache_get_value_name_int(0, "admin", g_PlayerData[playerid][pAdminLevel]);
        cache_get_value_name(0, "admin_name", g_PlayerData[playerid][pAdminName]);

        if(g_PlayerData[playerid][pActivation] == 0)
        {
            format(string, sizeof(string), "{ffffff}Username: {04d400}%s\n{ffffff} Status: {04d400}Terdaftar\n{ffffff}Akun UCP kamu sudah terdaftar, silahkan masukan kode verifikasi.", g_PlayerData[playerid][pUCP]);
            Dialog_Show(playerid, DialogVerifyCode, DIALOG_STYLE_INPUT, "Verifikasi UCP", string, "Input", "Close");
        }
        else
        {
            format(string, sizeof(string), "{ffffff}Username: {04d400}%s\n{ffffff}Status: {04d400}Terdaftar\n{ffffff}Akun UCP kamu sudah terdaftar kedalam server.\nLogin ke akun kamu dengan memasukan password dibawah:", g_PlayerData[playerid][pUCP]);
            Dialog_Show(playerid, DialogLogin, DIALOG_STYLE_PASSWORD, "Login", string, "Login", "Close");
        }

	}
	else
	{
		format(string, sizeof(string), "{ffffff}Username: {04d400}%s\n{ffffff} Status: {bd0000}Tidak terdaftar\n{ffffff}Akun UCP kamu belum terdaftar didalam server.\nSilahkan kunjungi discord server untuk membuat akun UCP.", g_PlayerData[playerid][pUCP]);
		Dialog_Show(playerid, DialogUnused, DIALOG_STYLE_MSGBOX, "UCP", string, "Close", "");
        Kick(playerid);
	}
	return 1;
}

Callback::OnPasswordHashed(playerid, hash_id)
{
	bcrypt_get_hash(g_PlayerData[playerid][pPassword], BCRYPT_HASH_LENGTH);
    g_PlayerData[playerid][pActivation] = 1;
    
    new query[250];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE ucp set activation = '%d', password = '%e' WHERE ucp_name = '%e'", g_PlayerData[playerid][pActivation], g_PlayerData[playerid][pPassword], g_PlayerData[playerid][pUCP]);
    mysql_tquery(g_SQL, query);
	return 1;
}

Callback::OnPasswordVerify(playerid, bool:success)
{
    new str[185];
	if(success)
	{
        CheckUserCharacter(playerid);
	}
	else
	{
		g_PlayerData[playerid][pLoginAttempt]++;

		if(g_PlayerData[playerid][pLoginAttempt] >= 3)
		{
            format(str, sizeof(str), "{ffffff}Username: {04d400}%s\n{ffffff}Status: {04d400}Terdaftar\n{ffffff}Kamu dikick karena salah memasukan password sebanyak 3X!\n{FBFF00}Lupa password? Ajukan reset password pada moderator di discord kammi", g_PlayerData[playerid][pUCP]);
			Dialog_Show(playerid, DialogUnused, DIALOG_STYLE_MSGBOX, "Failed Login", str, "Oke", "");
			KickEx(playerid);
		}
		else
        {
            format(str, sizeof(str), "{ffffff}Username: {04d400}%s\n{ffffff}Status: {04d400}Terdaftar\n{FBFF00}Kamu salah memasukan password! kesempatan kamu %d/3.\n{ffffff}Isi kembali kolom password dengan benar:", g_PlayerData[playerid][pUCP], g_PlayerData[playerid][pLoginAttempt]);
            Dialog_Show(playerid, DialogLogin, DIALOG_STYLE_PASSWORD, "Login", str, "Input", "Close");
        }
	}
	return 1;
}

Callback::OnCharacterLoaded(playerid, race_check)
{
    if(race_check != g_MysqlRaceCheck[playerid]) return KickEx(playerid);

    new rows = cache_num_rows();

    for(new i = 0; i < MAX_CHARS; i++)
    {
        PlayerCharacter[playerid][i][0] = EOS;
    }

    for(new k = 0; k < rows; k++)
    {
        cache_get_value_name(k, "username", PlayerCharacter[playerid][k]);
    }
    
    ShowCharacterList(playerid);
    return 1;
}

Callback::OnUsernameChecked(playerid, const name[], race_check)
{
    if(race_check != g_MysqlRaceCheck[playerid])    
        return KickEx(playerid);
    
    new rows = cache_num_rows();
    if(rows)
        return Dialog_Show(playerid, DialogCreateChar, DIALOG_STYLE_INPUT, "Create New Character", "{bd0000}Nama sudah pernah dipakai! {ffffff}Gunakan nama lain\nMasukan nama :", "Input", "");

    Dialog_Show(playerid, DialogAge, DIALOG_STYLE_INPUT, "Age", "Masukan tanggal lahir dengan format DD/MM/YYYY (16/01/2005)", "Input", "Tutup");
    return 1;
}

Callback::OnInsertCharacter(playerid)
{
    g_PlayerData[playerid][pID] = cache_insert_id();

    SetPlayerName(playerid, g_PlayerData[playerid][pName]);

    g_PlayerData[playerid][isLogin] = true;
    CreateSetupCharacter(playerid);
    return 1;
}