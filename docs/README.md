**DEFUSE THE BOMB**

CONTRIBUTORI:
 - Manuel Menghetti | manuel.menghetti@studio.unibo.it
 - Fabian Costinel Calangiu | fabian.calangiu@studio.unibo.it

SVILUPPO:

L'approccio iniziale scelto per lo sviluppo del progetto consiste nella suddivisione di 3 stati di cui 2 principali e uno intermedio senza guardia.

Tali stati sono:
 - INITIAL: dove il programma attende due input dell'utente, quali impostare la difficoltà tramite potenziometro e pressione del bottone verde per avviare il gioco.
 - CREATE PATTERN: creato in seguito per modularità, qui avviene la generazione del pattern randomico che poi dovrà essere replicato dall'utente tramite la pressione dei bottoni dai colori corrispondenti ai led che lampeggiano in un determinato ordine. Inoltre nello stesso stato avviene il lampeggio dei led e solo alla fine il timer viene attivato.
 - GAME ON: in questo stato avviene il parsing degli input dell'utente. I bottoni premuti vengono salvati in array e associati ai corrispettivi led colorati.
 Se il pattern è corretto e il tempo non è scaduto la guardia incrementa il numero di lampeggi al prossimo round e lo score, resettando il timer.
 Altrimenti il gioco finisce, stampando lo score (su cui viene calcolato un moltiplicatore di difficoltà) e tornando allo stato iniziale.

