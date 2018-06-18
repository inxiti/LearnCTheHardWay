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

}