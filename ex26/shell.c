#include "shell.h"
#include "dbg.h"
#include <stdarg.h>

int Shell_exec(Shell template, ...)
{

}

int Shell_run(apr_pool_t *p, Shell *cmd)
{

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