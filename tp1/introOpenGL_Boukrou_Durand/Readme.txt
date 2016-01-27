BOUKROU Malik
DURAND Jean-Frédéric

TP1 M3DS


- ce que vous n'avez pas fait (et pourquoi). Précisez explicitement "tout à été fait et fonctionne parfaitement" si c'est le cas.
- difficultés rencontrées.
- commentaires éventuels sur le TP (points à éclaircir, longueur du sujet, etc).


Q8.

VBO : son rôle est de permettre la copie du client vers le serveur (serveur = mémoire).

VAO : il fait le lien entre le shader et le VBO.

Program shader : il contient un vertex shader et un fragment shader. Le rôle du vertex shader est de convertir les coordonnées données en coordonnées normalisées et il est lié au fragment shader qui produit la couleur finale. 


Q9.




Q13.
0, 2, 3, 1, 4, 5



Q15.
Le tableau d'index se nourrit des 2 attributs position et couleur dans l'ordre dans lequel ils sont déclarés dans leurs tableaux respectifs.
Q16.
Changements : 
 - _indexData = {0, 2, 3, 1, 4, 2};
 - on supprime la coordonnée en double 0.0,0.2,0.0 dans le triangle position

On obtient : 














La différence de couleur provient du fait que l'on utilise le sommet n°2 (donc vert) pour les 2 triangles, et donc on obtient 2 fois la même couleur puisque l'on utilise plus la couleur associée au sommet que l'on a supprimé dans le triangle position.

Q20.
glDrawArrays(GL_TRIANGLE_STRIP,0,8);
_trianglePosition = {
        -0.8,-0.8,0.0,
        -0.8,0.8,0.0,
        -0.4,-0.8,0.0,
        -0.4,0.8,0.0,
        0.0,-0.8,0.0,
        0.0,0.8,0.0,
        0.4,-0.8,0.0,
        0.4,0.8,0.0
    };

