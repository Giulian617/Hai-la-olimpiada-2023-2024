# Impartire dupa radical:

Problema: [Arbori de intervale](https://infoarena.ro/problema/arbint)

Nu vrem sa rezolvam optim problema, ci sa intelegem ideea din spate. ~(desi momentan solutia cu radical se incadreaza in timp)~

## Ideea de baza:

Facem un trade off intre complexitatile celor 2 tipuri de operatii.

Pentru fiecare bloc pastram maximul. Astfel operatia de update va avea complexitatea $O(B)$ iar cea de calcul la maximului $O(\frac{N}{B} + B)$ unde $B$ este dimensiunea blocului.

Observam ca putem optimiza aceste functii pentru a obtine un minim in $B=\sqrt{N}$

Astfel vom obtine $O(\sqrt{N})$ pentru fiecare tip de query in cazul cel mai rau.

[Solutie](https://infoarena.ro/job_detail/3200166?action=view-source)

### Nota

Poate o valoare sub/peste radical este mai potrivita in anumite situatii, deoarece ignoram factorii constanti in calcule sau daca unele query-uri sunt mai abundente.

# Delayed update:

Problema + solutie in [folderul resurse](https://github.com/Giulian617/Hai-la-olimpiada-2023-2024/blob/main/10/resources/curs_10_delayed_update.png)

Vom face din nou trade off intre cele 2 complexitati, vom pastra un vector sortat in care putem obtine raspunsul in $O(\log{N})$ folosind cautarea binara.

Pentru adaugari nu vom resorta vectorul deoarece aceasta ar putea dura $O(N)$ sau $O(N \cdot \log{N})$ vom pastra un vector aditional de lungime maxim $L$.

Astfel adaugarea va dura $O(1)$ in cele mai multe cazuri si $O(L \cdot \log{L} + N)$ la fiecare $L$ adaugari. In medie obtinem $O(\log{L} + \frac{N}{L})$

Calculul va dura acum $O(\log{N} + L)$ pentru ca facem cautare binara in vectorul sortat si cautare liniara in cel nesortat.

Minimul se poate atinge in jurul lui $L=\sqrt{N}$

# Algoritmul lui Mo

Problema: [fsecv](https://www.pbinfo.ro/probleme/3085/fsecv)

Vom sorta query-urile intr-o ordine preferentiala.

Spargem vectorul in blocuri. In cazul in care query-urile au acelasi bloc pentru capatul stanga le vom sorta crescator dupa capatul dreapta.

Daca nu au acelasi bloc al capatului stang le vom sorta crescator dupa blocul capatului stang.

[Solutie](https://github.com/Giulian617/Hai-la-olimpiada-2023-2024/blob/main/10/resources/)

# Probleme aditionale:

* [Toorcmmdc](https://www.pbinfo.ro/probleme/3393/toorcmmdc)

* [kth1](https://www.pbinfo.ro/probleme/4433/kth1)