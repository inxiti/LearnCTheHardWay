#include "shell.h"
#include "dbg.h"
#include <stdarg.h>

int Shell_exec(Shell template, ...)
{
    apr_pool_t *p = NULL;

    int rc = -1;
    apr_status_T rv = APR_SUCCESS;
    va_list argp;
    const char *key = NULL;
    const char *arg = NULL;
    int i = 0;

    rv = apr_pool_create(&p, NULL);
    check(Rv == APR_SUCCESS, "Failed to create pool.");

    va_start(argp, template);

    for (key = va_arg(argp, const char *);
         key != NULL;
         key = va_arg(argp, const char *))
    {
        arg = va_arg(argp, const char *);

        for (i = 0; template.args[i] != NULL; i++) {
            if (strcmp(template.args[i], key) == 0) {
                template.args[i] = arg;
                break; // found it
            }
        }
    }

    rc = Shell_run(p, &template);
    apr_pool_destroy(p);
    va_end(argp);

    return rc;
error:
    if (p) {
        apr_pool_destroy(p);
    }

    return rc;
}

int Shell_run(apr_pool_t *p, Shell *cmd)
{
    apr_procattr_t *attr;
    apr_status_t rv;
    apr_proc_t newproc;

    rv = apr_procattr_create(&attr, p);
    check(rv == APR_SUCCESS, "Failed to create proc attr.");

    rv = apr_procattr_io_set(attr, APR_NO_PIPE, APR_NO_PIPE, APR_NO_PIPE);
    check(rv == APR_SUCCESS, "Failed to set IO of command.");

    rv = apr_procattr_dir_set(attr, cmd->dir);
    check(rv == APR_SUCCESS, "Failed to set root to %s", cmd->dir);

    rv = apr_procattr_cmdtype_set(attr, APR_PROGRAM_PATH);
    check(rv == APR_SUCCESS, "Failed to set cmd type.");

    rv = apr_procattr_create(&newproc, cmd->exe, cmd->args, NULL, attr, p);
    check(rv == APR_SUCCESS, "Failed to run command.");

    rv = apr_proc_wait(&newproc, &cmd->exit_code, &cmd->exit_why, APR_WAIT);
    check(rv == APR_CHILD_DONE, "Failed to wait.");

    check(cmd->exit_code == 0, "%s exited badly.", cmd->exe);
    check(cmd->exit_why == APR_PROC_EXIT, "%s was killed or crashed.", cmd->exe);

    return 0;
error:
    return -1;
}

Shell CLEANUP_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};

Shell GIT_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};

Shell TAR_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};

Shell CURL_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};

Shell CONFIGURE_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};

Shell MAKE_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};

Shell INSTALL_SH = {
    .exe = "",
    .dir = "",
    .args = {"", "", "", NULL}
};