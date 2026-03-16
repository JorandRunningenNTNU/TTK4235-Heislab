#figure(
  placement: auto,
  image("klassediagram.jpg", width: 120%),
  caption: [Klassediagram som beskriver systemet vi har implementert.],
  scope: "parent"
) <klassediagram>

== Klassediagram <klassediagram_tekst>
@klassediagram viser klassediagrammet vårt. Systemet består av seks moduler, som er implementert som hver sin c-fil i prosjektet. output-modulen benyttes til både oppstart og vanlig kjøring av heisen, mens startUp-modulen kun brukes i oppstart. De restrende modulene brukes kun under vanlig kjøring. De ulike modulene har ulike ansvarsområder.

=== StartUp-modulen
StartUp-modulen henter informasjon fra heisen om hva etasjesensorene viser og bestemmer retningen heisen skal kjøre. 

=== Input-modulen
Input-modulen henter informasjon fra heisen og kontrollboksen, altså hvilke knapper som er trykket inn og hva etasjesensorene viser. 

=== State-modulen
State-modulen har i oppgave å vite posisjonen til heisen, hvilken vei motoren beveger seg, og om døren er åpen eller lukket.  

=== Queue-modulen
Queue-modulen beregner hva den neste handlingen til heisen skal være, altså som den skal stå stille, stå stille med åpen dør eller eventuelt hvilken etasje den skal bevege seg til.

=== Control-modulen
Control-modulen beregner hvilke lys som skal være på og hvilken retning motoren skal bevege seg. 

=== Output-modulen
Output-modulen videresender til heisen og kontrollboksen hvilke lys som skal være på og hvilken vei motoren skal bevege seg.