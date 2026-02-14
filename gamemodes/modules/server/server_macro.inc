#define Callback::%0(%1) forward %0(%1); public %0(%1)
#define isPlayerLogged(%0) g_PlayerData[%0][isLogin]

// sendclient
#define SendErrorMessage(%0,%1) SendClientMessage(%0, COLOR_ERROR, "ERROR :{ffffff} "%1)
#define SendSuccessMessage(%0,%1) SendClientMessage(%0, COLOR_SUCCESS, "SUCCESS :{ffffff} "%1)
#define SendUsageMessage(%0,%1) SendClientMessage(%0, COLOR_USAGE, "USAGE :{ffffff} "%1)
#define SendInfoMessage(%0,%1) SendClientMessage(%0, COLOR_INFO, "INFO :{ffffff} "%1)
#define SendServerMessage(%0,%1) SendClientMessage(%0, COLOR_SERVER, "SERVER :{ffffff} "%1)

#define NoPermision(%0) SendClientMessage(%0, COLOR_ERROR, "NO PERMISION :{ffffff} Anda tidak menggunakan fitur atau command ini!")