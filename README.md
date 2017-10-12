# ABC Algorithm
Projet autour de l'algorithme Artificial Bee Colony<br>
Voir : https://en.wikipedia.org/wiki/Artificial_bee_colony_algorithm

## Aide à l'utilisation de Git ##
### Branches ###
Rappel des différentes branches ainsi que leur utilité :
* <b>master</b> : On y ajoute que le code déjà fonctionnel et testé de la branche <b>dev</b>. Le code doit :
  * Compiler ;
  * Non buggé ;
  * Commenté.
* <b>dev</b> : On retrouve le code en développement. C'est ici que la majorité du travail se situe. On travaille dans cette branche.
* <b>testing</b> : Cette branche contient des codes à tester, et des ajouts un peu plus exotique. Si vous pensez que votre code peut être dangereux pour le programme en général, ou si vous n'êtes pas du tout sur de ce que vous faites, travaillez dedans.

N'hésitez pas à créer des branches issues de <b>testing</b> pour faire du code précis et pour pas empiéter sur les autres.<br>
<b>URGENT : Ne faites pas de pull sans faire une requête de pull au préalable.</b> Plus d'information ici : https://help.github.com/articles/about-pull-requests/

### Le bug tracker ###
Si vous devez :
* Reporter un bug ;
* Proposer une amélioration / création ;
* Demander de l'aide ;

Rendez vous dans l'onglet <b>Issues</b> sur GitHub. Pensez à bien définir la personne qui doit se charger de l'issue si besoin est, ainsi qu'à le <b>LABELISER !</b> 

### Git et Visual Studio 2017 ###
#### Début ####
Pour récuperer le projet une première fois sur Visual Studio 2017, rendez vous dans l'onglet <b>Team Explorer</b> en bas du panneau de gauche sur Visual Studio, cliquez sur <b>Cloner</b>, et saisissez l'URL suivante pour le dépôt : https://github.com/Olivier-Delierre/ABC-Algorithm.git <br>
Retournez ensuite dans l'onglet <b>Team Explorer</b> puis double-cliquez sur le nom du dépôt (ABC-Algorithm), cliquez sur <b>Branches</b>, déroulez <b>remotes/origin</b> et double-cliquez sur <b>dev</b>.<br>
Finalement, cliquez sur la maison dans le panneau de <b>Team Explorer</b>, puis double-cliquez sur <b>ABC-Algorithm</b> sous la catégorie <b>Solutions</b>.

#### Modifications ####
Une fois vos modifications réalisés, il faut les envoyer sur le Git. Allez dans le <b>Team Explorer</b>. Ici, en cliquant droit sur les différents fichiers que vous avez modifié, vous pouvez soit le comparer avec l'ancien, soit annuler la modification que vous avez apporté depuis le dernier Fetch.<br><br>

Une fois vos modifications terminés, vous devez entrer un message, puis appuyer sur "Valider tout".

#### Envoi sur le Git ####
Après avoir Commit vos modifications, il vous suffit de vous rendre dans la catégorie <b>Synchroniser</b> de <b>Team Explorer</b>, puis cliquer sur <b>Synchroniser</b>. <br>
<b>Vérifiez bien que vous soyez sur la branche "dev" ou "testing" avant de synchroniser, le master est uniquement modifiable via les <b>Pull Requests</b>.

#### Réceptionner la dernière mise à jour ####
Allez dans la catégorie <b>Synchroniser</b>, puis cliquez sur <b>Tirer</b>.
