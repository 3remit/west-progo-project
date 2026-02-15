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
    DateAndTime[playerid][0] = CreatePlayerTextDraw(playerid, 520.000, 138.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, DateAndTime[playerid][0], 90.000, 42.000);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][0], 160);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][0], 255);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][0], true);

    DateAndTime[playerid][1] = CreatePlayerTextDraw(playerid, 539.000, 129.000, "Date");
    PlayerTextDrawLetterSize(playerid, DateAndTime[playerid][1], 0.459, 1.700);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][1], 1);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][1], 255);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][1], TEXT_DRAW_FONT_0);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][1], true);

    DateAndTime[playerid][2] = CreatePlayerTextDraw(playerid, 528.000, 146.000, "24:60:60");
    PlayerTextDrawLetterSize(playerid, DateAndTime[playerid][2], 0.329, 1.600);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][2], 1);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][2], 150);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][2], true);

    DateAndTime[playerid][3] = CreatePlayerTextDraw(playerid, 528.000, 161.000, "14, Feb 2026");
    PlayerTextDrawLetterSize(playerid, DateAndTime[playerid][3], 0.300, 1.399);
    PlayerTextDrawAlignment(playerid, DateAndTime[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, DateAndTime[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, DateAndTime[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, DateAndTime[playerid][3], 1);
    PlayerTextDrawBackgroundColour(playerid, DateAndTime[playerid][3], 150);
    PlayerTextDrawFont(playerid, DateAndTime[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, DateAndTime[playerid][3], true);
    // End date and time textdraw

    // Hunger and thirst textdraw
    HungerAndThirst[playerid][0] = CreatePlayerTextDraw(playerid, 520.000, 260.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, HungerAndThirst[playerid][0], 90.000, 64.000);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][0], -96);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][0], 255);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][0], true);

    HungerAndThirst[playerid][1] = CreatePlayerTextDraw(playerid, 540.000, 250.000, "Stats");
    PlayerTextDrawLetterSize(playerid, HungerAndThirst[playerid][1], 0.458, 1.799);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][1], 1);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][1], 150);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][1], TEXT_DRAW_FONT_0);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][1], true);

    HungerAndThirst[playerid][2] = CreatePlayerTextDraw(playerid, 535.000, 273.000, "HUD:radar_burgerShot");
    PlayerTextDrawTextSize(playerid, HungerAndThirst[playerid][2], 16.000, 16.000);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][2], 255);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][2], true);

    HungerAndThirst[playerid][3] = CreatePlayerTextDraw(playerid, 535.000, 298.000, "HUD:radar_diner");
    PlayerTextDrawTextSize(playerid, HungerAndThirst[playerid][3], 16.000, 16.000);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][3], 255);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][3], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][3], true);

    HungerAndThirst[playerid][4] = CreatePlayerTextDraw(playerid, 560.000, 271.000, "80%");
    PlayerTextDrawLetterSize(playerid, HungerAndThirst[playerid][4], 0.409, 1.899);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][4], 1);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][4], 150);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][4], TEXT_DRAW_FONT_3);
    PlayerTextDrawSetProportional(playerid, HungerAndThirst[playerid][4], true);

    HungerAndThirst[playerid][5] = CreatePlayerTextDraw(playerid, 561.000, 297.000, "100%");
    PlayerTextDrawLetterSize(playerid, HungerAndThirst[playerid][5], 0.409, 1.899);
    PlayerTextDrawAlignment(playerid, HungerAndThirst[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HungerAndThirst[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, HungerAndThirst[playerid][5], 1);
    PlayerTextDrawSetOutline(playerid, HungerAndThirst[playerid][5], 1);
    PlayerTextDrawBackgroundColour(playerid, HungerAndThirst[playerid][5], 150);
    PlayerTextDrawFont(playerid, HungerAndThirst[playerid][5], TEXT_DRAW_FONT_3);
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