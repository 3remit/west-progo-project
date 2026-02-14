new Text: ServerName[3];
new PlayerText: DateAndTime[MAX_PLAYERS][4];
new PlayerText: HungerAndThirst[MAX_PLAYERS][6];

stock CreateGlobalTextdraw()
{
    ServerName[0] = TextDrawCreate(320.000, 7.000, "West Progo");
    TextDrawLetterSize(ServerName[0], 0.398, 1.799);
    TextDrawAlignment(ServerName[0], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(ServerName[0], 255);
    TextDrawSetShadow(ServerName[0], 0);
    TextDrawSetOutline(ServerName[0], 0);
    TextDrawBackgroundColour(ServerName[0], 1768516095);
    TextDrawFont(ServerName[0], TEXT_DRAW_FONT_3);
    TextDrawSetProportional(ServerName[0], true);

    ServerName[1] = TextDrawCreate(320.000, 5.000, "West Progo");
    TextDrawLetterSize(ServerName[1], 0.379, 1.699);
    TextDrawAlignment(ServerName[1], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(ServerName[1], -1);
    TextDrawSetShadow(ServerName[1], 1);
    TextDrawSetOutline(ServerName[1], 1);
    TextDrawBackgroundColour(ServerName[1], 150);
    TextDrawFont(ServerName[1], TEXT_DRAW_FONT_3);
    TextDrawSetProportional(ServerName[1], true);

    ServerName[2] = TextDrawCreate(320.000, 14.000, "Roleplay");
    TextDrawLetterSize(ServerName[2], 0.569, 1.899);
    TextDrawAlignment(ServerName[2], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(ServerName[2], -1);
    TextDrawSetShadow(ServerName[2], 0);
    TextDrawSetOutline(ServerName[2], 1);
    TextDrawBackgroundColour(ServerName[2], 150);
    TextDrawFont(ServerName[2], TEXT_DRAW_FONT_0);
    TextDrawSetProportional(ServerName[2], true);
}

stock CreateTextdrawForPlayer(playerid)
{
    // Date and time textdraw
    DateAndTime[playerid][0] = CreatePlayerTextDraw(playerid, 519.000, 108.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, DateAndTime[playerid][0], 89.000, 39.000);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][0], -126);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][0], 255);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][0], true);

    DateAndTime[playerid][1] = CreatePlayerTextDraw(playerid, 533.000, 98.000, "Time");
    PlayerTextDrawLetterSize(playerid, DateAndTime[playerid][1], 0.359, 1.999);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][1], 1);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][1], 150);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][1], TEXT_DRAW_FONT_0);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][1], true);

    DateAndTime[playerid][2] = CreatePlayerTextDraw(playerid, 524.000, 117.000, "24:01:25");
    PlayerTextDrawLetterSize(playerid, DateAndTime[playerid][2], 0.270, 1.399);
    PlayerTextDrawTextSize(playerid, DateAndTime[playerid][2], 10.000, 0.000);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][2], 1);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][2], 150);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][2], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][2], true);

    DateAndTime[playerid][3] = CreatePlayerTextDraw(playerid, 524.000, 130.000, "16, Feb 2026");
    PlayerTextDrawLetterSize(playerid, DateAndTime[playerid][3], 0.270, 1.399);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][3], 1);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][3], 150);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][3], TEXT_DRAW_FONT_2);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][3], true);
    // End date and time textdraw

    // Hunger and thirst textdraw
    HungerAndThirst[playerid][0] = CreatePlayerTextDraw(playerid, 537.000, 285.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, HungerAndThirst[playerid][0], 82.000, 51.000);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][0], -121);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][0], 255);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][0], true);

    HungerAndThirst[playerid][1] = CreatePlayerTextDraw(playerid, 557.000, 276.000, "Stats");
    PlayerTextDrawLetterSize(playerid, HungerAndThirst[playerid][1], 0.389, 1.700);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][1], 1);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][1], 150);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][1], TEXT_DRAW_FONT_0);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][1], true);

    HungerAndThirst[playerid][2] = CreatePlayerTextDraw(playerid, 563.000, 294.000, "100%");
    PlayerTextDrawLetterSize(playerid, HungerAndThirst[playerid][2], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][2], 1);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][2], 150);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][2], true);

    HungerAndThirst[playerid][3] = CreatePlayerTextDraw(playerid, 564.000, 315.000, "100%");
    PlayerTextDrawLetterSize(playerid, HungerAndThirst[playerid][3], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][3], 1);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][3], 150);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][3], true);

    HungerAndThirst[playerid][4] = CreatePlayerTextDraw(playerid, 544.000, 294.000, "HUD:radar_dateFood");
    PlayerTextDrawTextSize(playerid, HungerAndThirst[playerid][4], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][4], 255);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][4], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][4], true);

    HungerAndThirst[playerid][5] = CreatePlayerTextDraw(playerid, 545.000, 315.000, "HUD:radar_diner");
    PlayerTextDrawTextSize(playerid, HungerAndThirst[playerid][5], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][5], 255);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][5], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][5], true);
    // End hunger and thirst textdraw
}

stock DestroyAllTextdraw(playerid)
{
    // destroy server name
    for(new i; i < 3; i++)
    {
        TextDrawDestroy(ServerName[i]);
    }

    for(new i; i < 4; i++)
    {
        PlayerTextDrawDestroy(playerid, DateAndTime[playerid][i]);
    }

    for(new i; i < 6; i++)
    {
        PlayerTextDrawDestroy(playerid, HungerAndThirst[playerid][i]);
    }
    return 1;
}