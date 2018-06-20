#include <apr_uri.h>
#include <apr_fnmatch.h>
#include <unistd.h>
#include "commands.h"
#include "dbg.h"
#include "bstrlib.h"
#include "db.h"
#include "shell.h"

int Command_fetch(apr_pool_t *p, const char *url, int fetch_only)
{

}

int Command_install(apr_pool_t *p, const char *url, const char *configure_opts,
                    const char *make_opts, const char *install_opts)
{
    int rc = 0;
    check(Shell_exec(CLEANUP_SH, NULL) == 0, "Failed to cleanup before building.");

    rc = DB_find(url);
    check(rc != 1, "Error checking the install database.");

    if (rc == 1){
        log_info("Package %s already installed.", url);
        return 0;
    }

    rc = Command_fetch(p, url, 0);

    if (rc == 1) {
        rc = Command_build(p, url, configure_opts, make_opts, install_opts);
        check(rc == 0, "Failed to build: %s", url);
    } else if(rc == 0) {
        // no install needed
        log_info("Depends successfully installed: %s", url);
    } else {
        // had an error
        sentinel("Install failed: %s", url);
    }

    Shell_exec(CLEANUP_SH, NULL);
    return 0;

error:
    Shell_exec(CLEANUP_SH, NULL);
    return -1;
}

int Command_depends(apr_pool_t *p, const char *path)
{
    FILE *in = NULL;
    bstring line = NULL;

    in = fopen(path, "r");
    check(in != NULL, "Failed to open downloaded depends: %s", path);

    for (line = bgets((bNgetc)fgetc, in, '\n');
         line != NULL;
         line = bgets((bNgetc)fgetc, in, '\n'))
    {
        btrimws(line);
        log_info("Processing depends: %s", bdata(line));
        int rc = Command_install(p, bdata(line), NULL, NULL, NULL);
        check(rc == 0, "Failed to install: %s", bdata(line));
        bdestroy(line);
    }

    fclose(in);
    
    return 0;
error:
    if (line) bdestroy(line);
    if (in) fclose(in);
    
    return -1;
}

int Command_build(apr_pool_t *p, const char *url, const char *configure_opts,
                  const char *make_opts, const char *install_opts)
{
    int rc = 0;
    
    check(access(BUILD_DIR, X_OK | R_OK | W_OK) == 0, "Build directory doesn't exist: %s", BUILD_DIR);

    // actually do an install
    if (access(CONFIG_SCRIPT, X_OK) == 0) {
        log_info("Has a configure script, running it.");
        rc = Shell_exec(CONFIGURE_SH, "OPTS", configure_opts, NULL);
        check(rc == 0, "Failed to configure.");
    }

    rc = Shell_exec(MAKE_SH, "OPTS", make_opts, NULL);
    check(rc == 0, "Failed to build.");

    rc = Shell_exec(INSTALL_SH, "TARGET", install_ops ? install_opts : "install", NULL);
    check(rc == 0, "Failed to install.");

    rc = Shell_exec(CLEANUP_SH, NULL);
    check(rc == 0, "Failed to cleanup after build.");

    rc = DB_update(url);
    check(rc == 0, "Failed to add this package to the database.");

    return 0;

error:
    return -1;
}