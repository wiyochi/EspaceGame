# Info skillTree

## Forme du JSon
```json
{
    "tree": [
        {
            "name": "<nomSkill1>",
            "description": "<descriptionSkill1>",
            "need": []
        },
        {
            "name": "<nomSkill2>",
            "description": "<descriptionSkill2>",
            "need": []
        },
        {
            "name": "<nomSkill3>",
            "description": "<descriptionSkill3>",
            "need": [
                {
                    "name": "<nomSKill1>",
                    "quantity": 3
                },
                {
                    "name": "<nomSKill2>",
                    "quantity": 4
                }
            ]
        },
        {
            "name": "<nomSkill4>",
            "description": "<descriptionSkill4>",
            "need": [
                {
                    "name": "<nomSKill2>",
                    "quantity": 5
                },
                {
                    "name": "<nomSKill3>",
                    "quantity": 2
                }
            ]
        },
        ...
    ]
}
```
## Explications
La valeur "tree" du document json contient un tableau d'objets représentant chacun une compétence.
Chaque compétence contient:
 - un nom (sous la valeur "name")
 - une description (sous la valeur "description")
 - un tableau d'objet représentant les compétences requises pour augmenter celle-ci (sous la valeur "need")
Les objets de compétences requises contiennent:
 - un nom d'une compétence existante (sous la valeur "name")
 - une quantité requise (sous la valeur "quantity")

 Ainsi les arbres de compétences sont sous forme de "niveau" :  
 Le 1er niveau est composé de compétences qui n'ont pas de compétences requises  
 Le 2nd niveau est composé de compétences qui ont besoin d'un certain nombre de points dans des compétences de niveau 1  
 Le 3e  niveau est composé de compétences qui ont besoin d'un certain nombre de points dans des compétences de niveau 1 et de niveau 2  
 ...  
 Le ne  niveau est composé de compétences qui ont besoin d'un certain nombre de points dans des compétences de niveau 1 à (n-1)