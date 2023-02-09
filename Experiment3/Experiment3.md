---
header-includes:
 - \usepackage{fontspec}
 - \usepackage{fvextra}
 - \setmainfont{Times New Roman}
 - \setmonofont{Consolas}
 - \fvset{breaklines=true, breakanywhere=true}
 - \renewcommand{\theFancyVerbLine}{\textcolor[rgb]{0.0,0.0,0.0}{\small\arabic{FancyVerbLine}}}
 - \DefineVerbatimEnvironment{Highlighting}{Verbatim}{commandchars=\\\{\}, frame=leftline, numbersep=4pt, framesep=4pt}
fontsize: 12pt
geometry: left=2cm,right=2cm,top=2cm,bottom=2cm
---
Name: Aum Kulkarni  
RollNo: 36  
Div: D6AD  
**Prims Algorithm**:
```{.C include="PrimsAlgo.c" .numberLines}
```
**Output:**
```
0 - 2: 3
2 - 3: 2
3 - 4: 1
3 - 1: 4

Spanning tree cost: 10
```
\newpage
**Kruskals Algorithm**:
```{.C include="KruskalsAlgo.c" .numberLines}
```
**Output:**
```
2 - 1 : 2
5 - 2 : 2
3 - 2 : 3
4 - 3 : 3
1 - 0 : 4
Spanning tree cost: 14
```
\newpage
**Dijkstras Algorithm**:
```{.C include="DijkstrasAlgo.c" .numberLines}
```
**Output:**
```
Vertex           Distance from Source
0                                0
1                                3
2                                5
3                                3
4                                1
5                                6
6                                8
7                                11
8                                15
```