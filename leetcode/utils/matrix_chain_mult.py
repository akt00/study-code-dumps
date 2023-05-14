import numpy as np


def mcm(p):
    n = len(ins) - 1
    m = np.zeros(shape=(n+1, n+1))

     # l is chain length
    for l in range(1, n+1):
        print(l)
        # i is left bound
        for i in range(0, n-l+1):
          # j is right bound
            j = i + l
            m[i, j] = np.inf
            print(i, j)
            # k starts at i and ends at j - 1
            for k in range(i, j):
                left_bound = i - 1
                p1 = p[left_bound][1] if left_bound >= 0 else p[0][0]
                q = m[i, k] + m[k+1, j] + p1 * p[k][1] * p[j][1]

                print(f'm[{i},{k}] + m[{k+1},{j}] + p{left_bound}p{k}p{j} = {q}')
                if q < m[i, j]:
                    m[i, j] = q
    return m


if __name__ == '__main__':
    ins = [(30, 35), (35, 15), (15, 5), (5, 10), (10, 20), (20, 25)]
    print(mcm(ins))
