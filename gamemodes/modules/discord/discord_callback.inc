Callback::OnDiscordIDChecked(const name[], const discord_id[])
{
    new tempUCP[24];
    new DCC_Channel:channel_register = DCC_FindChannelById(CHANNEL_UCP);
    
    if(cache_num_rows())
    {
        cache_get_value_name(0, "ucp_name", tempUCP);

        new str[200];
        format(str, sizeof(str), "**[BOT]** Kamu pernah mendaftarkan akun UCP sebelumnya dengan nama _%s_!", tempUCP);
        return DCC_SendChannelMessage(channel_register, str);
    }
    else
    {
        new dquery[128];
        mysql_format(g_SQL, dquery, sizeof(dquery), "SELECT * FROM ucp WHERE ucp_name = '%e' LIMIT 1", name);
        mysql_tquery(g_SQL, dquery, "OnDiscordUCPNameChecked", "ss", name, discord_id);
    }
    return 1;
}

Callback::OnDiscordUCPNameChecked(const name[], const discord_id[])
{
    new verifyCode = RandomEx(111111, 999999);
    new DCC_Channel:channel_register = DCC_FindChannelById(CHANNEL_UCP);
    
    if(cache_num_rows())
    {
        return DCC_SendChannelMessage(channel_register, "**[BOT]** Nama UCP tersebut sudah dipakai oleh orang lain!");
    }
    else
    {
        new formatName[30];
        format(formatName, sizeof(formatName), "MEMBER | %s", name);

        new DCC_Guild:guildID = DCC_FindGuildById(GUILD_ID);
        new DCC_Role:roleID = DCC_FindRoleById(ROLE_ID);
        new DCC_User:userID = DCC_FindUserById(discord_id);

        DCC_SetGuildMemberNickname(guildID, userID, formatName);
        DCC_AddGuildMemberRole(guildID, userID, roleID);
        DCC_SendChannelMessage(channel_register, "**[BOT]** UCP berhasil didaftarkan! Silahkan tunggu DM dari bot");
        DCC_CreatePrivateChannel(userID, "OnDirectMessageUCP", "sds", name, verifyCode, discord_id);

    }
    return 1;
}

Callback::OnDirectMessageUCP(const name[], verify_code, const discord_id[])
{
    new DCC_Channel:Private = DCC_GetCreatedPrivateChannel();

    new DCC_Embed:embedUCP = DCC_CreateEmbed(.title = "Basic Roleplay", .footer_text = "Akun UCP anda berhasil terdaftar!");

    new str[200];
    format(str, sizeof(str), "Gunakan verify code untuk memverifikasi bahwa ini akun anda (in-game)\
    \n** UCP : ** \n```%s```\
    \n** Discord ID : ** \n```%s```\
    \n** Verify Code : ** \n ```%d```", name, discord_id, verify_code);

    DCC_SetEmbedDescription(embedUCP, str);
    DCC_SetEmbedColor(embedUCP, 0x0000EDFF);
    DCC_SendChannelEmbedMessage(DCC_Channel:Private, embedUCP);

    new dquery[350];
    mysql_format(g_SQL, dquery, sizeof(dquery), "INSERT INTO ucp (ucp_name, discord_id, verifycode) VALUES ('%e', '%e', '%d')", name, discord_id, verify_code);
    mysql_tquery(g_SQL, dquery);
    return 1;
}