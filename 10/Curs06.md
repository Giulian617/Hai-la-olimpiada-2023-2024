# Numere mari

## Ce e ala numar mare?

Un numar mare e un numar care nu poate fi stocat pe tipul predefinit in
limbajul standard. 
Mai precis este un numar mai mare de 2^63-1 = 9,223,372,036,854,775,807
care este limita tipului de date long long int.

## Ce facem daca avem numere mari?

### 1. Python

- Python are suport pentru numere mari "by default" si pentru ce presupun
  numerele mari chiar se descurca bine
  
- Cu toate astea Python e incet din alte motive asa ca nu recomandam
  utilizarea lui in practica

### 2. Folosirea unei versiuni deja implementate, printr-o biblioteca

- Nu trebuie sa le scriem noi

- Cu toate astea simplul fapt ca sunt facute pentru cazul general nu le
  face potrivite neaparat pentru cazul nostru, unde de obicei vrem viteza

### 3. Implementarea "de mana"

- Vom implementa:
    - Adunarea unui numar mare cu un alt numar, mic sau mare
    - Inmultirea unui numar mare cu un alt numar, mic sau mare
    - Impartirea unui numar mare la un numar mic (Impartirea unui numar
    mare la un alt numar mare e o operatie foarte inceata si foarte greu
    de implementat)
    - Scaderea unui numar mare cu un alt numar, mic sau mare, cu rezultat pozitiv

## Pentru testarea implementarii

- https://www.pbinfo.ro/probleme/2392/sumaxl

- https://www.pbinfo.ro/probleme/2409/produsxl

- https://www.pbinfo.ro/probleme/2393/sumaxxl

- https://www.pbinfo.ro/probleme/2410/produsxxl

## Cateva probleme cu numere mari

- https://infoarena.ro/problema/biti2

- https://infoarena.ro/problema/patrate2

- https://infoarena.ro/problema/culori3

- (Problema aceasta necesita mai multe cunostiinte, daca nu puteti rezolva
  puneti intrebari pe discord) https://infoarena.ro/problema/bombar
