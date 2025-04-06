#include <stdio.h>
#include <limits.h>
int main(void) {
    int pink, green, red, orange, target;
    int total = 0, combination = 0;
    int min = INT_MAX, tmin = 0;
    scanf("%d", &pink);
    scanf("%d", &green);
    scanf("%d", &red);
    scanf("%d", &orange);
    scanf("%d", &target);
    for (int p = 0; p <= target / pink; ++p) {
        for (int g = 0; g <= target / green; ++g) {
            for (int r = 0; r <= target / red; ++r) {
                for (int o = 0; o <= target / orange; ++o) {
                    total = (p * pink + g * green + r * red + o * orange);
                    if (total == target) {
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
                        combination++;
                        tmin = p + g + r + o;
                        if (min > tmin) {
                            min = tmin;
                        }
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\n", combination);
    printf("Minimum number of tickets to print is %d.\n", min);
    return 0;
}
