new Text: ServerName[3];

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