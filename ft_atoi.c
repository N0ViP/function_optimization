int     ft_atoi(const char *str)
{
        register long long		res;
        register const char		*s;
        int						sign;

        s = str;
        sign = 0;
        while (*s && (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f' || *s == '\r' || *s == ' '))
                s++;

        if (*s == '-' || *s == '+')
        {
                if (*s == '-')
                        sign = 1;
                s++;
        }

        if (!*s || (*s == '0' && !*(s + 1)))
                return (0);

        res = 0;
        while (*s >= '0' && *s <= '9')
        {
                res = (res << 3) + (res << 1) + (*s++ & 0X0F);
                if (res < 0)
                {
                        if (sign != 1)
                                return (-1);
                        return (0);
                }
        }

        if (sign == 1)
                res = -res;

        return ((int) res);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ITERATIONS 100000


double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

void benchmark(const char *test_case) {
    double start_time, std_time, custom_time;
    int std_result = 0, ft_result = 0;

    start_time = get_time();
    for (int i = 0; i < ITERATIONS; i++) {
        std_result = atoi(test_case);
    }
    std_time = (get_time() - start_time) / ITERATIONS;

    start_time = get_time();
    for (int i = 0; i < ITERATIONS; i++) {
        ft_result = ft_atoi(test_case);
    }
    custom_time = (get_time() - start_time) / ITERATIONS;

    printf("----------------------------------------------------------\n");
    printf("Test case: '%s'\n", test_case);
    printf("Standard atoi:\n");
    printf("  Result: %-11d | Avg Time: %e seconds\n", std_result, std_time);
    printf("Custom ft_atoi:\n");
    printf("  Result: %-11d | Avg Time: %e seconds\n", ft_result, custom_time);

    if (std_result == ft_result) {
        printf("✅ Results match\n");
    } else {
        printf("❌ Results differ\n");
    }
    printf("----------------------------------------------------------\n\n");
}

int main() {
    const char *test_cases[] = {
        "12345",
        "-67890",
        "   42",
        "42   ",
        "   -42   ",
        "0",
        "-0",
        "+42",
        "++42",
        "--42",
        "  +123abc456",
        "abc",
        "  ",
        "",
        "2147483647",
        "-2147483648",
        "2147483648",
        "-2147483649",
        "999999999999999999999",
        "-999999999999999999999",
        "\t\n42",
        "42\t\n",
        "42 56",
        "  007",
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        benchmark(test_cases[i]);
    }

    return 0;
}

