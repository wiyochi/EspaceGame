# Info items
## Forme du JSon
```json
{
    "items": [
        {
            "class": "<classItem1>",
            "name": "<nomItem1>",
            "texture": "resources/textures/items/<nomTextureItem1>"
        },
        {
            "class": "<classItem1>",
            "name": "<nomItem2>",
            "texture": "resources/textures/items/<nomTextureItem2>"
        },
        {
            "class": "<classItem2>",
            "name": "<nomItem3>",
            "texture": "resources/textures/items/<nomTextureItem3>"
        },
        {
            "class": "<classItem3>",
            "name": "<nomItem4>",
            "texture": "resources/textures/items/<nomTextureItem4>"
        },
        ...
    ]
}
```
## Explications
La valeur "items" du document JSon contient un tableau d'objets représentants des items
Chaque objet contient:
 - la classe de l'item (sous la valeur "class")
 - le nom de l'item (sous la valeur "name")
 - le chemin relatif de la texture liée à l'item (sous la valeur "texture")