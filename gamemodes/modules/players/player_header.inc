#define MAX_CHARS 3

enum E_PLAYER_DATA{
	pID,
	Text3D:pNameTag,

	// UCP
	pUCP[MAX_PLAYER_NAME],
	pPassword[BCRYPT_HASH_LENGTH],
	pVerifyCode,
	pActivation,

	// character
	pCharacter,
	Float:pHealth,
	Float:pArmor,
	pName[MAX_PLAYER_NAME],
	Float:pPos[4],
	pInterior,
	pVirtual_World,
	pSkin,
	pMoney,
	pLevel,
	pBirthDay,
	pBirthMonth,
	pBirthYear,
	pGender,
	
	// admin
	pAdminLevel,
	pAdminName[MAX_PLAYER_NAME],
	bool:isAdminDuty,

	// temp variable
	bool:isLogin,
	pLoginAttempt,
	bool:isOfficialClient
};

new g_PlayerData[MAX_PLAYERS][E_PLAYER_DATA];
new PlayerCharacter[MAX_PLAYERS][MAX_CHARS][MAX_PLAYER_NAME + 1];