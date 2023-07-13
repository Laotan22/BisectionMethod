import math

def bisection(fun, a, b, curr_count, max_count):
        if(curr_count > max_count):
                return
        c = (a+b)/2
        u = fun(a)
        v = fun(b)
        w = fun(c)
        prod = u * w
        
        print("Iteration:", curr_count)
        print("a: %.4f, b: %.4f"%(a,b))
        print("c: %.4f"%(c))
        print("f(a): %.4f"%(u))
        print("f(c): %.4f"%(w))
        print("f(a) * f(c): %.4f"%(prod))

        if(curr_count == max_count):
                root = (a+b)/2
                val = fun(root)
                print("After %d iterations, the root, r is:"%(max_count))
                print("%.4f"%(root))
                print("With the value:")
                print("f(r) = %.4f"%(val))
        if(prod) < 0:
                bisection(fun, a, c, curr_count+1, max_count)
        else:
                bisection(fun, c, b, curr_count+1, max_count)

def func_a(x):
        return x**3-(3*x)+1

def func_b(x):
        return x-math.cos(x)

print("For function f(x)=x^3-3x+1 on interval [0,1]:")
bisection(func_a, 0, 1, 1, 7)
print()
print("For function f(x)=x-cos(x) on interval [0.5,0.9]:")
bisection(func_b, 0.5, 0.9, 1, 7)
