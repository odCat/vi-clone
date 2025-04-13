#include <glib.h>


void testExample1()
{
    g_assert_cmpint(5, ==, 5);
}

void testExample2()
{
    g_assert_cmpstr("abc", ==, "abc");
}

void testExample3()
{
    g_assert_cmpfloat(1.2, ==, 1.2);
}


int main(int argc, char *argv[])
{
    g_test_init(&argc, &argv, NULL);
    g_test_set_nonfatal_assertions();

    g_test_add_func("/vi/ex1", testExample1);
    g_test_add_func("/vi/ex2", testExample2);
    g_test_add_func("/vi/ex3", testExample3);

    return g_test_run();
}
