## Miskolci Egyetem Párhuzamos Algoritmusok
<sub>Ebben a repoban a Párhuzamos algorimusok gyakorlat gyakorlati feladatai lesznek feltöltve!</sub>

> Egyetemi Polgár: Czikó Tivadar
>
> Neptun kód: O2IXLB
>
> Beadandó témája: 
> Shel rendezés megvalósítása szálkezeléssel, párhuzamosítás választott technológiával és C nyelveben OpenMP-vel, és ezek futásának mérése, összehasonlítása.
>>  Mi az shell rendezés és hogyan működik:
>> - Donald Shell-ről kapta a nevét aki 1959-ben találta ki. Az alapelve az, hogy sokat javíthat a rendezésen, ha először etz egymástól nagy távolságban lévő elemeket hasonlítjuk, cseréljük, mert így egyes elemek gyorsabban kerülhetnek a végleges helyükre.
>> - Az elvárás a növekmények sorozatára vonatkozóan az az, hogy a növekmények (gap) sorozata olyan módon legyen választva, hogy a rendezés hatékony legyen és minél kevesebb iterációt igényeljen. A növekmények sorozata határozza meg, hogy milyen lépésközökkel történik a rendezés. Általában csökkenően rendezett kell, hogy legyen. Ennek az a következménye, hogy a növekmény (gap) kissebb legyen, mint az előző nővekmény.
>> Választott technológia:
>> - Go (Golang): egy nyílt forrású technológia, amit a google fejlesztett ki a hatékonyság, a könnyű kezelhetőség és a megbízhatóság elveit tartja szem előtt. A Go nyelv célja a hatékony végrehajtás, nagy sebesség, alacsony memória foglaltság és egyszerrű szintaxis. A nyelv lehetősvé teszi a párhuzamosítást és az asszinkron programozást. A goroutines lehetővé teszi a könnyű párhuzamosítást.
>> A Shell rendezés futás idejének összehasonlítása, kölünböző megvalósításokkal:
>> - Szálkezelésel (szálak számának változtatásával).
>> - OpenMP C könyvtár segítségével.
>> - Go (Golang) nyelvel való párhuzamosságnak megfelelő megvalósítása.
>> Az alábbi ábrán az látható, hogy különböző technológiák mennyi idő alatt végzik el a számításokat.
>> <img src="https://github.com/cziko1/parallel-o2ixlb-gyak/blob/main/chart2.jpg">

<br>
<br>
<img src="https://github.com/cziko1/parallel-o2ixlb-gyak/blob/main/picture.PNG" width="97" height="102">

### Gyakorlatok:
<rb> **1.** 2023.02.27 
  
<rb> **2.** 2023.03.06

<rb> **3.** 2023.03.13 

<rb> **4.** 2023.03.20

<rb> **5.** 2023.04.27 NEM VOLTAM

<rb> **6.** 2023.04.03

<rb> **7.** 2023.04.10 SZÜNET VOLT

<rb> **8.** 2023.04.17  

<rb> **9.** 2023.04.25 
  
<rb> **10.** 2023.05.01 SZÜNET VOLT
  
<rb> **11.** 2023.05.08 
  
<rb> **12.** 2023.05.15 
    
<rb> **13.** 2023.05.22 MAI ÓRA
