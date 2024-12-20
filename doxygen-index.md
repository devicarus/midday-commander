# midday-commander - interaktivní file manager

> Výchozí nastavení vyžaduje terminál s podporou `8-bit color`, v případě že se barvy ve vašem terminálu špatně zobrazují (kurzor/výběr nelze rozeznat, atd.) je zkuste <a href="#konfigurace">v konfiguraci</a> přenastavit na některé ze standardních ANSI barev (`0`-`15`) 

## Použití

### Základní operace
- `q` - ukončit program
- `↑` - posunutí kurzoru nahoru
- `↓` - posunutí kurzoru dolu
- `↵` - vstup do složky
- `b` - návrat o úroveň výš

### Výběr záznamů
- `s` - vybrat/odvybrat záznam na kterém je kurzor
- `f` - vybrat záznamy pomocí RegExu
- `u` - zrušit veškerý výběr

### Operace se záznamy
- `n` - vytvořit soubor
- `N` - vytvořit složku
- `S` - vytvořit symlink na položku, na které se nachází kurzor
- `d` - smazat vybrané záznamy
- `c` - zkopírovat vybrané záznamy do právě otevřené složky
- `m` - přesunout vybrané záznamy do právě otevřené složky
  
> Tip: Výběr záznamů je při průchodu složkami zachován

### Pokročilé operace
- `1` - vybrat soubory podle obsahu (podporuje RegEx)
- `2` - deduplikovat soubor, na kterém je právě kurzor (najde a nahradí duplikáty symlinky)
- `3` - spojí vybrané soubory do nového (concat)

---

## Konfigurace {#konfigurace}
 
Umístění: `~/.midday.json`

Pokud není konfigurační soubor nalezen, je použita výchozí konfigurace

Ukázková konfigurace:
```json
{
    "theme": {
        "primary": 1,
        "secondary": 2,
        "background": -1,
        "accent1": 3,
        "accent2": 4,
        "accent3": 5	
    }
}
```

> Vysvětlení položek `theme` viz \link Theme.accent1 dokumentace \endlink