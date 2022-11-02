
def simple_linear_regression(X, Y):
    x_mean, y_mean = X.mean(), Y.mean()
    
    slope_num = ((X - x_mean) * (Y - y_mean)).sum()
    
    slope_den = ((X - x_mean)**2).sum()
    
    slope = slope_num / slope_den
    
    intercept = y_mean - (slope * x_mean)

    return (intercept, slope)