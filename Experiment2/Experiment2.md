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

**Merge Sort:**
```{.c include="MergeSort.c" .numberLines}
```

**Output:**
```{include="MergeSort.txt"}
```

**Quick Sort:**
```{.c include="QuickSort.c" .numberLines}
```
\newpage
**Output:**
```{include="QuickSort.txt"}
```

**Binary Search:**
```{.c include="BinarySearch.c" .numberLines}
```
\newpage
**Output:**
```{include="BinarySearch.txt"}
```