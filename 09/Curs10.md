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
& F_{n-1} F_{n+1} - F_n^2 = (-1)^n \\
& F_{n+k} = F_k F_{n+1} + F_{k-1} F_n \\
& F_{2n} = F_n (F_{n+1} + F_{n-1}) \\
& \text{GCD}(F_m, F_n) = F_{\text{GCD}(m, n)} \\
& F_{2k+1} = F_{k+1}^2 + F_{k}^2 \\
& F_{2k} = F_k(F_{k+1}+F_{k-1}) = F_k (2F_{k+1} - F_{k})
\end{align*}
$$

