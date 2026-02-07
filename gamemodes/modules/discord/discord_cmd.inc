#define CHANNEL_UCP "1452865547229331537"
#define GUILD_ID "1452308565682421840"
#define ROLE_ID "1454449144658792520"

DCMD:test(user, channel, params[]) {
    if(channel != DCC_FindChannelById(CHANNEL_UCP))
        return DCC_SendChannelMessage(channel, "**[BOT]** :x: kamu tidak dichannel yang tepat!");
    new DCC_Embed:testingembed = DCC_CreateEmbed(.title = "Test title", .footer_text = "footer test");
    DCC_SetEmbedDescription(testingembed, "Ini baru ya pepek");
    DCC_SetEmbedColor(testingembed, 0x0044FFFF);
    DCC_SendChannelEmbedMessage(channel, testingembed);
    return 1;
}

DCMD:createucp(user, channel, params[])
{
    new name[128],
        userID[21];


    if(channel != DCC_FindChannelById(CHANNEL_UCP))
        return 1;

    if(sscanf(params, "s[128]", name))
        return DCC_SendChannelMessage(channel, "**[USAGE]** !createucp <nama ucp>");

    DCC_GetUserId(user, userID, sizeof(userID));
    
    new dquery[128];
    mysql_format(g_SQL, dquery, sizeof(dquery), "SELECT ucp_name FROM ucp WHERE discord_id = '%e' LIMIT 1", userID);
    mysql_tquery(g_SQL, dquery, "OnDiscordIDChecked", "ss", name, userID);
    return 1;
}