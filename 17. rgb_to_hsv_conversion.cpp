#include <bits/stdc++.h>
using namespace std;

void rgb_to_hsv(double r, double g, double b) {
	r = r / 255.0;
	g = g / 255.0;
	b = b / 255.0;
	double cmax = max(r, max(g, b));
	double cmin = min(r, min(g, b));
	double diff = cmax - cmin;
	double h, s;

	if (cmax == cmin)
		h = 0;
	else if (cmax == r)
		h = fmod(60 * ((g - b) / diff) + 360, 360);
	else if (cmax == g)
		h = fmod(60 * ((b - r) / diff) + 120, 360);
	else if (cmax == b)
		h = fmod(60 * ((r - g) / diff) + 240, 360);

	if (cmax == 0)
		s = 0;
	else
		s = (diff / cmax) * 100;
	double v = cmax * 100;
	cout << "(" << h << ", " << s << ", " << v << ")"
		<< endl;
}

int main() {
	rgb_to_hsv(129, 88, 47);
	return 0;
}
