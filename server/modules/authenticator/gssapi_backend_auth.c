#include <gw_authenticator.h>
#include <maxscale/alloc.h>
#include <dcb.h>
#include <mysql_client_server_protocol.h>

static int gssapi_extract(DCB *dcb, GWBUF *buffer)
{
    return MXS_AUTH_SUCCEEDED;
}

bool gssapi_connectssl(DCB *dcb)
{
    return false;
}

int gssapi_authenticate(DCB *dcb)
{
    return MXS_AUTH_SUCCEEDED;
}

void gssapi_free_data(DCB *dcb)
{
}

/**
 * Implementation of the authenticator module interface
 */
static GWAUTHENTICATOR MyObject =
{
    gssapi_extract,             /* Extract data into structure   */
    gssapi_connectssl,          /* Check if client supports SSL  */
    gssapi_authenticate,        /* Authenticate user credentials */
    gssapi_free_data,           /* Free the client data held in DCB */
    NULL,                       /* Load users from backend databases */
    "auth_gssapi_client"
};

MODULE_INFO info =
{
    MODULE_API_AUTHENTICATOR,
    MODULE_GA,
    GWAUTHENTICATOR_VERSION,
    "GSSAPI backend authenticator"
};

static char *version_str = "V1.0.0";

/**
 * Version string entry point
 */
char* version()
{
    return version_str;
}

/**
 * Module initialization entry point
 */
void ModuleInit()
{
}

/**
 * Module handle entry point
 */
GWAUTHENTICATOR* GetModuleObject()
{
    return &MyObject;
}
