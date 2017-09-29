https://fi.inf.elte.hu/adatszerkezet/implementalas/69/index.htm

Egy versenyre jelentkezett N ember. Bármely két ember vagy ismeri egymást, vagy nem (feltesszük, hogy ha A ismeri B-t, akkor B is ismeri A-t). Kérdés, be tudjuk-e a résztvevőket két csoportba osztani úgy, hogy egy csoporton belül ne legyenek ismerős párok? Ha igen, adjunk meg egy lehetséges csoportosítást, ha nem, akkor írjuk ki, hogy nem létezik ilyen csoportosítás.


Bemenet: 

Az INPUT.TXT állományban egymás után több verseny adatai szerepelnek. Egy verseny estén először egy N érték található, ennyi ember jelentkezett a versenyre, az embereket 1-től, egyesével adott sorszámmal azonosítjuk, majd számpárok következnek, melyek az ismerősöket adják meg. A 0 0 számpár jelenti az ismerősök megadásának végét. Ha N=0, akkor nincs több adat a fájlban.

Kimenet: 

Írjuk az eredményeket az OUTPUT.TXT nevű állományba! Vagy adjunk meg egy lehetséges csoportosítást, vagy írjuk ki, ha nem létezik. A csoportokban a tagok azonosítóját nagyság szerint növekvően kell felsorolni! Egy feladathoz több lehetséges csoportosítást is találhatunk, elég egyet kiírni. 
 

INPUT.TXT

11

1 8 1 10 4 9 3 10 6 7 2 9 5 7 0 0

5

1 4 1 5 3 2 2 5 0 0

6

1 2 4 3 5 4 1 4 6 3 6 5 6 2 0 0

0

OUTPUT.TXT

1. feladat:

A. csoport: 1 2 3 4 5 6

B. csoport: 7 8 9 10 11

2. feladat:

A. csoport: 1 2

B. csoport: 3 4 5

3. feladat:

Nincs megoldas.

 

(Új algoritmusok 22.2-6 nyomán

Tesztfájlok:

t0.txt

t1.txt

t2.txt

t3.txt

t4.txt  

segítség

----------------------

http://www.informatom.hu/sze/01/LGB_SZ001/Cormen-Lieserson-Rivest-Stein.-.Uj.algoritmusok.pdf
    http://cs.bme.hu/bsz2/paros_graf_elszinezese.pdf
