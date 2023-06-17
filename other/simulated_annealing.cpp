mt19937 rng((unsigned long long)(new char));
auto rnd = [&]() -> double {
    return 2 * ((double)rng() / rng.max()) - 1;
};

auto run = [&](int l, int r, int u, int d) -> double {
        double x = (l+r)/2., y = (u+d)/2., s = cal(x, y);
        double nx, ny;
        for (double t = hypot(l-r, u-d); t >= 1e-8; t *= 0.99995) {
            do {
                nx = x + t * rnd(); 
                ny = y + t * rnd();
            } while (!safe(nx, ny));
            if (chmax(s, cal(nx, ny)))
                x = nx, y = ny;
        }
        return s;
    };