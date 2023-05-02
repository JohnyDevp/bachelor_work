Optimalizace průchodu skladem
===
## Autor
jméno: Jan Holáň \
login: xholan11 \
email: xholan11@vutbr.cz

# Intro
Kód implementuje GUI pro testování funkčnosti knihovny řešící optimalizaci průchodu skladem.

# Závislosti
Kód je počítá s přítomností knihoven **python3.11** a **nlohmann/json**.

Knihovna **nlohmann/json** slouží pro práci se soubory typu JSON. Lze stáhnout z https://github.com/nlohmann/json, případně lze využít nějakou z možností viz https://json.nlohmann.me/integration/package_managers (oficiální stránky knihovny). Následně by měla být tato knihovna umístěna do adresáře */usr/include*.

# Překlad a spuštění
Přeložit a spustit lze kód sekvencí příkazů zadaných v kořenovém adresáři (tedy nad složkou se zdrojovými kódy knihovny *./src*).
<pre>
qmake
make
./warehouse_visualizer
</pre>

# Použití
Popsáno v rámci textu bakalářské práce.

# Testovací data
Jako data pro otestování správného běhu aplikace lze využít data umístěná v adresáři *./testovací data*, nebo ta, která se nacházejí u zdrojových kódu knihovny (viz README ke knihovně).

