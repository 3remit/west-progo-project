#define COLOR_ADUTY		0xFF1B1AFF // merah 
#define ADMIN_MESSAGE	0xFF3F3EFF // merah muda

#define SendAdminInfo(%0,%1) SendClientMessage(%0, ADMIN_MESSAGE, "ADMIN INFO:{ffffff} "%1)

enum {
	ADMIN_NONE = 0,
	ADMIN_MODERATOR,
	ADMIN_JUNIOR,
	ADMIN_HEAD,
	ADMIN_DEVELOPER
};