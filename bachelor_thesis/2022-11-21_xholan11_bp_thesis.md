Poznámky a popis vzniku base-line algoritmu a návrhy možného řešení
===
# Logistické problémy
Logistika je obor, kde se ve velkém množství uplatňují optimalizační procesy, které mají sloužit pro zrychlení procesů, úsporu zaměstnanců či zvýšení produktivity na skladech. Mnoho z problémů jsou již známé z historie - patří mezi ně slavný *Problém obchodního cestujícího* či *Problém čínského listonoše*. Některé jsou novodobého rázu - například *Bin packing problem* nebo *Vehicle routing problem*.
- **Problém obchodního cestujícího (známý jako TSP - Travelling Salesman Problem)**  je prolémem, který řeší průchod skrz graf tak, aby žádný vrchol nebyl navštíven vícekrát (konkrténě se jednalo o obchodníka, který má navštívit všechna na seznamu tak, aby urazil co nejkratší vzdálenost a zároveň nenavštívil žádné město víc než jednou). Patří do kategorie NP-úplných problémů a tedy zatím nemá řešení pro libovolný počet uzlů. Aktuálně je tento problém řešen heuristikami, kterými je například algoritmus *Nejblížšího souseda (Nearest neighbour)*, či použitím genetických algoritmů.

    Tento problém úzce souvisí s problémem Hamiltonova cyklu - to je cyklus obsahující takovou cestu, na které lze všechny uzly navštívit právě jednou a navrátit se přitom do počátečního vrcholu. (cit. Wróblewski P. Algoritmy)*Pokud najdeme takový (tj. Hamiltonovský) cyklus s minimální sumou jeho hran, vyřešíme slavný problém obchodního cestujícího.*
- **Problém čínského listonoše (známý jako Chinese postman Problem)** je jakýmsi protějškem Dijkstrova algoritmu - zabýváme se totiž při něm hledáním způsobu, jak navštívit všechny hrany daného grafu, a to tak, aby každá byla navštívena v ideálním případě jedenkrát - to je sice předem známo (takový graf by totiž musel být Eulerovským - tedy má všechny uzly sudého stupně a tudíž existuje uzavřený tah obsahující všechny hrany), nicméně je cílem tohoto dosáhnout.
- **Bin packing problem** opět spadá pod NP-úplné problémy, nicméně existuje řada heuristik pro jeho výpočet. Má mnoho podob, jejichž cílem je vždy poskládání N předmětů do prostoru (boxu) o dané kapacitě  K, či rozměrech X,Y,Z. Možnosti řešení jsou rozděleny od jednodušších ke složitějším. Z povahy problému jistě vidíme, že největší složitost budou mít algoritmy řešící druhou variantu, tedy skládání objektů do prostoru dle rozměrů.
  - Nejdříve se zaměřme na první variantu. Každý z N předmětů je definován veličinou X, X e R. Dále mějme P boxů, každý o maximální kapacitě (odpovídající veličině charakterizující předměty) K, K e R. Cílem je naplnit nejmenší možný počet boxů. **Tento typ problému zároveň využíváme v základním řešení bakalářské práce jako zjednodušení výpočtu s reálnými objemy**
    1. Next fit 
    2. First fit
    3. Best fit