Azi rezolvam probleme.

## [Xum](https://kilonova.ro/problems/578)

Pentru a rezolva problema ne vom folosi de o proprietate a xor-ului, anume:

(In urmatoarea ecuatie semnul de suma reprezinta suma xor)

$${\sum_{k=i}^j v_k} = {\sum_{k=1}^j v_k} \oplus {\sum_{k=1}^{i-1} v_k}$$

Pe langa asta ne vom folosi de faptul ca putem calcula independent pe fiecare bit de cate ori este acesta adaugat.

Sa zicem ca avem $cnt_j$ pozitii unde al $j$-lea bit este setat in suma xor. Daca suma xor pana in acest punct are bitul $j$ setat, atunci vom adauga numarul de pozitii pe care bitul $j$ nu este setat, adica $i-cnt_j$ inmultit cu contributia acestui bit ($2^j$ sau (1 << j) in cod). Similar daca bitul $j$ nu este setat, vrem sa adaugam numarul de pozitii cu bitul setat inmultit cu contributia, $cnt_j \cdot 2^j$.

Vom repeta asta pentru fiecare bit. Complexitatea finala va fi $O(N \cdot \log_2{\text{VMAX}})$, iar memoria necesara $O(\log_2{\text{VMAX}})$.

## [John Mex](https://kilonova.ro/problems/596)

Ideea se bazeaza pe cautarea binara. Daca mex-ul este mai mare decat $x$, atunci nu are sens sa verificam numerele $\le x$.

Avem insa nevoie de un mod rapid de a stii daca mex-ul este mai mare sau mai mic decat un numar dat $x$.

Pentru asta ne vom folosi de urmatorul rationament: Daca vreau ca mex-ul meu sa fie mai mare decat $x$ atunci toate numerele $\le x$ trebuie sa se afle in zona determinata de cele $4$ coordonate. Pentru asta vom considera "Bounding box"-ul unui prefix de numere. Adica linia minima, respectiv maxima si coloana minima, respectiv maxima pe care se gasesc numerele $\le x$. Acum putem raspunde rapid intrebarii "Toate numerele $\le x$ se afla in submatricea $l_0$, $c_0$, $l_1$, $c_1$?" verificand daca bounding box-ul acestora este complet inclus in submatrice.

Complexitatea finala este $O(N\cdot M + Q \cdot \log_2\left(N\cdot M\right))$, iar memoria necesara $O(N\cdot M)$.

## [Grigo](https://infoarena.ro/problema/grigo)

Ideea de baza este sa consideram o permutare care indeplineste primele cateva conditii de vizibilitate si apoi sa adaugam inca un numar.

Daca numarul trebuie sa fie vizibil, atunci exista o singura varianta pentru acesta.

Altfel, exista $i$ variante pentru acesta. Dar niciuna din aceste variante nu pastreasa sirul rezultat drept o permutare. Pentru a remedia asta vom incrementa toate valorile precedente $\ge x$ ($x$ este valoarea aleasa).

Exemplu: Din permutarea $[1, 2, 5, 3, 4, 6]$ putem obtine $6$ alte permutari:

* $[1, 2, 5, 3, 4, 7, 6]$
* $[1, 2, 6, 3, 4, 7, 5]$
* $[1, 2, 6, 3, 5, 7, 4]$
* $[1, 2, 6, 4, 5, 7, 3]$
* $[1, 3, 6, 4, 5, 7, 2]$
* $[2, 3, 6, 4, 5, 7, 1]$

Toate aceste permutari respecta conditiile precedente de vizibilitate si se poate arata ca acest procedeu genereaza unic toate permutarile cu aceasta proprietate.

Complexitatea finala este $O(N + M\cdot\log_2M)$, iar memoria necesara $O(M)$.

## [CF 1931 G](https://codeforces.com/problemset/problem/1931/G)

Se observa ca piesele $3$ si $4$ nu schimba tipul piesei langa care sunt puse. Adica o piesa $1$ combinata cu o piesa $3$ functioneaza de fapt ca o piesa $1$. Putem deci initial considera lipsa acestor piese. Ce ne raman sunt piesele de tip $1$ si $2$. Acestea se pot combina doar daca $|cnt_1-cnt_2| \le 1$. Daca aceasta conditie nu este indeplinita atunci nu exista nici o solutie.

Sa presupunem ca avem o configuratie de piese $1$ si piese $2$. Adaugarea unei piese $3$ se poate face doar la dreapta unei piese $1$ sau la stanga unei piese $2$. Similar pentru piesele $4$. Acestea formeaza un sistem similar sistemului "Stars and bars" de care am discutat acum cateva cursuri. Cu putina grija putem acoperi toate cazurile de aranjare initiala a pieselor $1$ si $2$ si obtine raspunsuri partiale pentru fiecare din ele. In final vom adauga aceste valori.

Complexitatea finala este $O(C_{max} + Q)$ deoarece trebuie sa precalculam factorialele pentru a avea combinarile rapid, iar memoria necesara $O(C_{max})$.

## [CF gym 104412 M](https://codeforces.com/gym/104412/problem/M)

Ideea de baza este sa o luam de la cel mai mic element. Acesta nu va putea fi eliminat niciodata, dar va putea elimina elemente adiacente. Mai mult, raspunsurile pentru zona stanga si zona dreapta sunt independente, raspunsul se va afla inmultind cele doua raspunsuri.

Cum aflam cate moduri pot fi obtinute pentru prima parte?

Aplicam un rationament similar. Cautam minimul. Acesta fie se afla in sirul final, fie nu. Daca nu se afla stim sigur ca a fost redus cu minimul si deci nimic intre minim si acesta nu mai conteaza, trebuie doar calculata zona stanga. Daca acesta se afla in sirul final, stim ca el poate fi folosit sa reduca anumite numere din stanga si dreapta lui. Putem observa ca acest rationament se repeta pana cand avem $0$ sau $1$ element. Ne vom folosi de recursivitate si de metoda Divide et Impera pentru a obtine solutia.

Complexitatea finala este $O(N^2)$, iar memoria necesara $O(N)$. Problema poate fi rezolvata si in timp $O(N\cdot\log_2N)$ cu memorie aditionala $O(N)$ sau $O(N\cdot\log_2N)$ folosind un arbore de intervale sau un RMQ dar nu vom discuta astfel de structuri la acest curs.
