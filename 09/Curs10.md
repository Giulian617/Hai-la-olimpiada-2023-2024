# Curs 10

## Fibonacci

$$
F(n) = \begin{cases} 
0 & \text{if } n = 0 \\
1 & \text{if } n = 1 \\
F(n-1) + F(n-2) & \text{otherwise}
\end{cases}
$$


$$
\begin{align*}
& \text{ }\text{ }\text{ } F_{n-1} F_{n+1} - F_n^2 = (-1)^n \\
& \text{}\\
& \text{ }\text{ }\text{ } F_{n+k} = F_k F_{n+1} + F_{k-1} F_n \\
& \text{}\\
& \text{ }\text{ }\text{ } F_{2n} = F_n (F_{n+1} + F_{n-1}) \\
& \text{}\\
& \text{ }\text{ }\text{ } \text{GCD}(F_m, F_n) = F_{\text{GCD}(m, n)} \\
& \text{}\\
& \text{ }\text{ }\text{ } F_{2k+1} = F_{k+1}^2 + F_{k}^2 \\
& \text{}\\
& \text{ }\text{ }\text{ } F_{2k} = F_k(F_{k+1}+F_{k-1}) = F_k (2F_{k+1} - F_{k})
\end{align*}
$$

```cpp
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n % 2 == 1)
        return {d, c + d};
    else
        return {c, d};
}
```

# Funcții

![functie](https://github.com/Giulian617/Hai-la-olimpiada-2023-2024/blob/main/09/resources/image.png)
![void](https://cdn.programiz.com/sites/tutorial2program/files/cpp-function-call.png)
![rec1](https://github.com/Giulian617/Hai-la-olimpiada-2023-2024/blob/main/09/resources/0wap3cp4khm01.png)
![rec2](https://i.pinimg.com/564x/fc/09/2e/fc092ecfa54cecbef34cb4745b9f6b42.jpg)


* https://www.pbinfo.ro/probleme/497/majoritar -> https://algo.monster/liteproblems/169
* https://www.pbinfo.ro/probleme/4337/normalizare
* https://www.pbinfo.ro/probleme/1472/castel
* https://www.pbinfo.ro/probleme/1374/numere9
* https://www.pbinfo.ro/probleme/2961/deminare

### Tema

* https://www.pbinfo.ro/probleme/3730/cartofi
