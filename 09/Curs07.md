# Curs 07 - Probleme cu matrice (continuare)

### Recapitulare Sume parțiale (2D)

Întrucât o imagine face cât o mie de cuvinte:

<!-- | Image 1                           | Image 2       |
| --------------------------------- | ------------- |
| <img src="sp0.png" width="300" height="300"> | ![Description 2](sp1.png) |
| Image 3                           | Image 4       |
| ![Description 3](sp2.png)         | ![Description 4](sp3.png) | -->

|  |  |
| ------- | ------- |
| <img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp0.png" width="300" height="300"> | <img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp1.png" width="300" height="300"> |
|  |  |
| <img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp2.png" width="300" height="300"> | <img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp3.png" width="300" height="300"> |


<!--<img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp0.png" width="300" height="300">
<img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp1.png" width="300" height="300">
<img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp2.png" width="300" height="300">
<img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/sp3.png" width="300" height="300"> -->

#### Probleme:
* [forest queries](https://cses.fi/problemset/task/1652) -> [solutie](https://cses.fi/problemset/result/707149/)
* [gradina](https://www.pbinfo.ro/probleme/1515/gradina) -> [solutie](https://ideone.com/jFYvXj)
* [terencasa](https://www.pbinfo.ro/probleme/3472/terencasa) -> [solutie 1](https://ideone.com/jVmF3I); [solutie 2](https://ideone.com/hAauDD)
* [matrix_replace](https://www.pbinfo.ro/probleme/3632/matrix-replace) -> [solutie](https://ideone.com/LzHcG5)


### Recapitulare Difference arrays (Șmenul lui Mars)
```cpp
void add(int s, int d, int val){
    B[s] += val;
    B[d+1] -= val;
}

void get(){
    A[1] = B[1];
    for(int i = 2 ; i <= n ; i ++)
        A[i] = A[i-1] + B[i];
}

```

#### Probleme:
* [paint](https://www.pbinfo.ro/probleme/1233/paint/) -> [solutie](https://ideone.com/rVlrmF)

### 2D Difference arrays (Șmenul lui Mars pe matrice)

Operațiile devin:

```cpp
void add(int i1, int j1, int i2, int j2, int x ){
    M[i1][j1] += x;
    M[i1][j2+1] -= x;
    M[i2+1][j1] -= x;
    M[i2+1][j2+1] += x;
}

void get_matrix(){
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1; j <= m ; j ++)
          A[i][j] += M[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
}
```

<img src="https://raw.githubusercontent.com/Giulian617/Hai-la-olimpiada-2023-2024/main/09/resources/mars2d.png" >

#### Probleme:
* [diff2Darrays](https://www.pbinfo.ro/probleme/3903/diff2darrays) -> [solutie](https://ideone.com/Al5jOl)
* [amat](https://kilonova.ro/problems/1544) -> [solutie](https://kilonova.ro/submissions/156730)

### Temă:
* [usaco](http://www.usaco.org/index.php?page=viewproblem2&cpid=919)
* [usaco](http://www.usaco.org/index.php?page=viewproblem2&cpid=1063)
