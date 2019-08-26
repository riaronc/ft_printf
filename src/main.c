#include "ft_printf.h"

int main() {

	double d;
	int p = 5;

	d = 545444554.5656156146156000;
    ft_printf("\n%.*f\n",p, d);
	printf("\n%.*f\n",p, d);
    //printf("%.17f", 3.2563);
    return 0;
}