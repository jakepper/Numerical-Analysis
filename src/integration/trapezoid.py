def trapezoid(f, a , b, n):
    h = (b - a) / n
    integral = 0.0
    integral += f(a) / 2
    for k in range(1, n):
        integral  += f(a + k * h)
    integral += f(b) / 2

    return integral * h