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

// Define the number of iterations for timing
#define ITERATIONS 100000

// Prototype of your custom atoi function
int ft_atoi(const char *str);

// Function to get the current time in seconds (with nanosecond precision)
double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

void benchmark(const char *test_case) {
    double start_time, std_time, custom_time;
    int std_result = 0, ft_result = 0;

    // Benchmark standard atoi
    start_time = get_time();
    for (int i = 0; i < ITERATIONS; i++) {
        std_result = atoi(test_case);
    }
    std_time = (get_time() - start_time) / ITERATIONS;

    // Benchmark custom ft_atoi
    start_time = get_time();
    for (int i = 0; i < ITERATIONS; i++) {
        ft_result = ft_atoi(test_case);
    }
    custom_time = (get_time() - start_time) / ITERATIONS;

    // Debugging the results
    printf("----------------------------------------------------------\n");
    printf("Test case: '%s'\n", test_case);
    printf("Standard atoi:\n");
    printf("  Result: %-11d | Avg Time: %e seconds\n", std_result, std_time);
    printf("Custom ft_atoi:\n");
    printf("  Result: %-11d | Avg Time: %e seconds\n", ft_result, custom_time);

    // Compare results
    if (std_result == ft_result) {
        printf("✅ Results match\n");
    } else {
        printf("❌ Results differ\n");
    }
    printf("----------------------------------------------------------\n\n");
}

int main() {
    // Expanded test cases
    const char *test_cases[] = {
        "12345",             // Simple positive number
        "-67890",            // Simple negative number
        "   42",             // Leading spaces
        "42   ",             // Trailing spaces
        "   -42   ",         // Leading and trailing spaces
        "0",                 // Zero
        "-0",                // Negative zero
        "+42",               // Positive sign
        "++42",              // Invalid input
        "--42",              // Invalid input
        "  +123abc456",      // Mixed valid and invalid characters
        "abc",               // Non-numeric input
        "  ",                // Only spaces
        "",                  // Empty string
        "2147483647",        // INT_MAX
        "-2147483648",       // INT_MIN
        "2147483648",        // Overflow case (greater than INT_MAX)
        "-2147483649",       // Underflow case (less than INT_MIN)
        "999999999999999999999", // Large positive number
        "-999999999999999999999", // Large negative number
        "\t\n42",            // Leading tab and newline
        "42\t\n",            // Trailing tab and newline
        "42 56",             // Multiple numbers
        "  007",             // Leading zeros
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    // Run benchmarks for each test case
    for (int i = 0; i < num_cases; i++) {
        benchmark(test_cases[i]);
    }

    return 0;
}

