# Info save

## Forme du JSon
```json
{
  "mine": {
    "machines": [
      {
        "machine": "<nomMachineMine1>",
        "x": 2,
        "y": 2
      },
      {
        "machine": "<nomMachineMine2>",
        "x": 5,
        "y": 4
      },
      ...
    ]
  },
  "factory": {
    "machines": [
      {
        "machine": "<nomMachineUsine1>",
        "x": 3,
        "y": 3
      },
      {
        "machine": "<nomMachineUsine2>",
        "x": 0,
        "y": 0
      },
      ...
    ]
  },
  "garage": {
    "machines": [
      {
        "machine": "<nomMachineGarage1>",
        "x": 3,
        "y": 3
      },
      {
        "machine": "<nomMachineGarage2>",
        "x": 0,
        "y": 0
      },
      ...
    ]
  },
  "energy": {
    "machines": [
      {
        "machine": "<nomMachineEnergie1>",
        "x": 3,
        "y": 3
      },
      {
        "machine": "<nomMachineEnergie2>",
        "x": 0,
        "y": 0
      },
      ...
    ]
  }
}
```
## Explications
Le document JSon a une valeur pour chaque pole du jeu donc
 - valeur "mine"
 - valeur "factory"
 - valeur "garage"
 - valeur "energy"

Chaque pole est un objet composé d'une valeur "machines" contenant un tableau
d'objets qui eux représentent une machine dans le pole et sa position.
Ainsi chaque objet de ce tableau contient:
 - le nom de la machine (sous la valeur "machine")
 - la position en x (entier sous la valeur "x")
 - la position en y (entier sous la valeur "y")

Cette position représente l'emplacement dans la grille du pole de la case (0,0)
de la "shape" de la machine.