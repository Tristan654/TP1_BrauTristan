Explication du code à partir de la question 4.

Question 4 ) 

Le but de la question est de récupérer le code de retour de la commande précédente dans le prompt

Codes de retour
    0 : Indique que la commande a réussi sans erreur.
    1 : Indique une erreur générale. Cela peut signifier qu'un problème est survenu, mais ne spécifie pas nécessairement la nature de l'erreur.
    2 : Indique une erreur de syntaxe dans la commande.
    3-255 : D'autres codes peuvent être utilisés pour indiquer des erreurs spécifiques selon l'application.

Pour récupérer le code retour on va utiliser la fonction fork qui va créer un nouveau processus (processus fils), en fonction de la valeur de fork
on va savoir si notre code reconnais la commande qu'on lui a donné si cette valeur est nulle alors la commande donné est une commande que notre code reconnais. Dans ce cas la nous allons dans le 
processus enfant qui est une copie du processus parent et qui s'exécute indépendamment. Ce processus va executer la commande qu'on lui a donné quand l'éxécution est terminée nous retournons dans le 
processus parent. En exécutant la commande dans un processus enfant, le processus parent reste opérationnel et peut continuer à accepter d'autres commandes. Si la valeur de fork est supérieur à 1 alors
le code ne reconnais pas la commande dans ce cas la on renvoie le code de retour associé à l'erreur de la commande dans le shell.

											valeur fork
											      |
										      0 -------------- >0
											|	      |
									 processus enfant             processus parent
											|             |
                                                                         commande terminé             Attendre la fin du processus enfant :
										        |	  |---|
							                 processus parent         |   Récupérer le statut de sortie
											|	  |   |
											|---------|   Mesurer le temps d'exécution ( pour la question 5)
												      |
												      Afficher les résultats 
												      
												      
												      
												      
												      

Question 5 ) Mesure du temps d’exécution de la commande en utilisant l’appel clock_gettime

Pour mesurer le temps d'exécution d'une commande dans notre shell, nous créons un processus enfant qui exécute la commande. Nous enregistrons le moment de son lancement. Ensuite, après que le processus enfant a terminé, nous notons le temps de fin. En calculant la différence entre ces deux instants, nous obtenons le temps d'exécution de la commande. Ce temps est ensuite affiché dans le shell, fournissant ainsi un retour sur la durée de l'exécution.

Question 6 ) Exécution d’une commande complexe (avec arguments);


On execute des commandes avec un tableau d'arguments et ainsi la commande peut executer des arguments si il y'en a.







