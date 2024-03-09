Evaluare de expresii:

Pentru inceput ne vom uita la o problema usoara, de parsare, [Ecuatii](https://kilonova.ro/problems/397).

Problema ne da o ecuatie intr-o forma "urata" pe care trebuie sa o rezolvam. Trebuie sa reducem forma ecuatiei la urmatoarea: $a\cdot x + b = 0$. Facem asta "citind" caracter cu caracter si facand decizii daca sa adaugam/scadem la a/b.

Acum ne vom uita la problema [Evaluarea unei expresii](https://infoarena.ro/problema/evaluare) din arhiva educationala pentru a analiza ideea generala de evaluare a unei expresii.

Ni se defineste o expresia drept o suma (sau diferenta) de unul sau mai multi termeni. Unde un termen este un produs (sau cât) de unul sau mai multi factori. Unde un factor este fie un numar, fie o expresie intre paranteze.

Formal:

$E = T \left[ \pm T \left[ \pm T \left[ \pm T \left[ \pm T \left[ ... \right] \right] \right] \right] \right]$

$T = F \left[ \cdot/\div F \left[ \cdot/\div F \left[ \cdot/\div F \left[ \cdot/\div F \left[ ... \right] \right] \right] \right] \right]$

$F = N / \left( E \right)$

$N = numar$

Exemplu:

$E = (1+1)*13+10/2 = T_1 + T_2$

$T_1 = (1+1)*13 = F_1 * F_2$

$T_2 = 10/2 = F_3 / F_4$

$F_1 = (1+1) = (E_1)$

$F_2 = 13 = N_1$

$F_3 = 10 = N_2$

$F_4 = 2 = N_3$

$E_1 = 1+1 = T_3 + T_4$

$T_3 = 1 = F_5$

$T_4 = 1 = F_6$

$F_5 = 1 = N_4$

$F_6 = 1 = N_5$

De observat ca odata ce stim pasii pe care trebuie sa ii facem ne putem intoarce cu valorile si calcula rezultatul. Pentru asta vom folosi recursivitatea.

Vom face ceva similar pentru problema [Bool](https://infoarena.ro/problema/bool).

$E = T \left[ \lor T \left[ \lor T \left[ \lor T \left[ \lor T \left[ ... \right] \right] \right] \right] \right]$

$T = F \left[ \land F \left[ \land F \left[ \land F \left[ \land F \left[ ... \right] \right] \right] \right] \right]$

$F = C | \lnot F | V | (E)$

$V = a | b | c | d | ... | z$

$C = TRUE | FALSE$

$|$ este separatorul de optiuni. $\lor$ este OR. $\land$ este AND. $\lnot$ este NOT.
