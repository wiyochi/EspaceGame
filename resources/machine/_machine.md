# Info machine
## Forme du JSon
```json
{
    "in": [
        [
            {
                "item": "<nomItemEntree1_1>",
                "quantity": 1
            },
            {
                "item": "<nomItemEntree1_2>",
                "quantity": 2
            }
        ],
        {
            "item": "<nomItemEntree2>",
            "quantity": 1
        },
        ...
    ],
    "out": [
      {
        "item": "<nomItemSortie1>",
        "quantity": 1
      },
      {
        "item": "<nomItemSortie2>",
        "quantity": 1
      },
      ...
    ],
    "energy": 25,
     "shape": [
        [ 1, 1 ],
        [ 2, 1 ],
        [ 0, 1 ]
      ],
    ],
    "texture": "resources/textures/<nomTextureMachine>"
}
```
Autre exemple plus simple :
```json
{
  "in": [
    {
      "item": "<nomItemEntree1>",
      "quantity": 2
    }
  ],
  "out": [
    {
      "item": "<nomItemSortie1>",
      "quantity": 1
    }
  ],
  "energy": 12.3,
  "shape": [
    [ 0, 0 ],
    [ 2, 0 ],
    [ 1, 1 ],
    [ 2, 1 ],
    [ 0, 1 ]
  ],
  "texture": "resources/textures/<nomTextureMachine>"
}
```
## Explications
La valeur "in" contient le set d'item en entrée de la machine.
C'est un tableau de taille n dont les eléments sont
 - soit un couple nomItem/quantité
 - soit un tableau contenant des couples nomItem/quantité

Les couples nomItem/quantité sont des objets contenant:
 - le nom de l'item (sous la valeur "item" cf items.json)
 - la quantité demandée (sous la valeur "quantity")

La valeur "out" contient le set d'item en sortie de la machine.  
C'est un tableau de taille n contenant des couples nomItem/quantité.  
Chaque elément du tableau dans "in" correspond à un couple du tableau "out".

in[x] en entrée de la machine donnera out[x] en sortie
sachant que out[x] est forcement un couple nomItem/quantité alors que in[x]
est soit un couple nomItem/quantité soit un tableau de couple nomItem/quantité.

Cela permet des machines plus flexibles.  
Par exemple, on peut faire une machine qui prend n'importe quel minerai et donne sont équivalent en fusion
ou des machines qui demandent plusieurs choses en entrée pour donner la sortie.

La valeur "energy" contient l'enregie demandée par la machine (en float).

La valeur "shape" contient un tableau de coordonnées qui représentent les carrées pleins
dans une grille. Dans le 1er exemple, la "shape" est trois carrés alignés formant une ligne,
sachant que le point (0,0) est une case au dessus.

La valeur "texture" contient une string avec le chemin relatif de la texture de la machine.