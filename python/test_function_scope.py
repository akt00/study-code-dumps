def test_function_scope():
    print('x', id(x), x) # funciton looks outside the scope for the value with the same name
    # x = 777  # error cannot modify the value outside the fucntion
    global x += 10 # now this can modify the global variable
    flag = False
    def inner():
        nonlocal flag  # now this function can modify the value outside this function
        flag = True
        return flag
    
    inner()
    return flag


if __name__ == '__main__':
    x = 77
    print('x', id(x), x)
    ret = test_function_scope()
    assert(ret == True)
    print('ret value = ', ret)
    
