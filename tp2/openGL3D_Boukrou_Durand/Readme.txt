DURAND Jean-Frédéric
BOUKROU Malik

# Général

Tout fonctionne, excepté la question Bonus. 

Question 7 :

Les couleurs sont (rouge, rouge, rouge, vert, vert, vert, bleu, bleu, bleu, cyan, cyan, cyan) pour chaque point.
Les triangles associés sont ((0,1,2)-> rouge;(0,2,3)->vert;(0,1,3)->bleu;(1,2,3)->cyan);
(Voir q7.png pour un schéma, celui ci j'ai volontairement laissé dépassé les anciennes couleurs dans l'optique d'observer la superposition).
On ne gère pas l'axe z, en conséquence les couleurs se superposent dans l'ordre dans lequel elles sont appelés.

Question 8 :

Cela signifie que les triangles rouge et bleu sont au premier plan par rapport aux deux autres.

Question 9 :

1. On obtient un écran blanc. C'est normal cela signifie que les valeurs passées entrantes sont inférieures et non supérieures aux valeurs stockées.

2. On a spécifié une valeure initiale à 0, soit inférieure à celle initiale. En conséquence avec le GL_GREATER les triangles vert et cyan étant chargés avec le z le plus élevé s'affichent.

3. idem que pour la 2. sauf qu'il calcule ce qui est supérieur à la valeure initiale et ce qui est inférieur. Il efface donc la partie inférieur à la valeure initialisée soit les extrémités des triangles car ils ont un z à -1

Question 16 :

cube = 24 sommets (1 couleur par face)



