# Mise-a-jour-DEVOIR-IP
Ceci est un mise a jour du mon code, il contient des nouveaux fonctionnalites.

Voici les instructions a suivre pour utiliser cet oeuvre ! 
Petit introduction: Ceci est un programme creer par moi-meme, qui peut faciliter votre comprenhension de votre Lecon Reseaux. JE VOUS SOUHAITE BONNE COMPILATION.

-Les methodes de compilation a suivre :
gcc inscription.c mesfonction1.c -o inscription.cgi -lm
gcc connexion.c fonction2.c mesfonction1.c -o connexion.cgi -lm
gcc interface-fin.c mesfonction1.c -o interface-fin.cgi -lm
gcc code_source.c mesfonction1.c -o ip.cgi -lm
mv *.cgi ip_enregistrement.txt /var/www/html

-Ouvrez votre navigateurs: 
http://localhost/inscription.cgi

-Assurez-vous de bien configurer aussi votre serveur.


Voila tout, assurez-vous d'avoir le persmission d'ecrire dans le fichier ip_enregistrement.txt; si vous ne savez pas comment le faire voici un petit tuto: 
chmod +x ip_enregistrement.txt 
