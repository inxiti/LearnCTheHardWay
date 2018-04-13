#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
    log_info("count is: %d", count);

    if (count > 10) {
        // likely to cause bugs because of naming/scoping
        int count = 100; // BAD! BUGS! NEVER shadow variables(same names)

        log_info("count in this scope is: %d", count);
    }

    log_info("count is at exit: %d", count);

    count = 3000;

    log_info("count after assign: %d", count);
}

int main()
{
    // test out THE_AGE accessors
    log_info("my name: %s, age: %d", MY_NAME, get_age());

    set_age(100);

    log_info("my age is now: %d", get_age());

    // test out THE_SIZE extern
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();

    THE_SIZE = 9;

    log_info("THE_SIZE is now: %d", THE_SIZE);
    print_size();

    // test the ratio function static
    log_info("ratio at first: %f", update_ratio(2.0));
    log_info("ratio again: %f", update_ratio(10.0));
    log_info("ratio once more: %f", update_ratio(300.0));

    // test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("count after calling scope_demo: %d", count);

    return 0;
}
