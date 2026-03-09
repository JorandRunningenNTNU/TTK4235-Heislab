== Refleksjoner rundt UML og V-modellen
=== Startfasen av implementasjonen
Vi begynte med å skissere hvilke moduler vi ville dele systemet opp i. Ideen vår var å lage moduler med enkle sammhandlinger og konkrete oppgaver, slik at vi kunne feilsøke modulene helt uavhening av hverandre, ved å kontrollere input til hver modul og se på output-et. Dette skulle gjøre enhetstesting eneklt, og ettersom modulene har enkle sammhandlinger håpet vi integrasjonstestingen ville bli enkel. For å ha en ide om hva hver enkelt modul skulle gjøre, fordelte vi de ulike punktene i kravspesifiaksjonen på de ulike modulene. Deretter skisserte vi også noen sekvensdiagrammer for å finne ut hvordan modulene kunne virke sammen. På dette stadiet revurderte vi noen av modulene våre og hvordan vi hadde fordelt ansvaret på de ulike modulene. 

Noen fornuftige nøkkelideer for systemet vi kom frem til i dette steget var: 1) main forteller hver modul når den skal oppdatere sin interne tilstand, for øverig endres ikke tilstanden i en modul. På denne måten er den interne tilstanden i modulen forutsigbar. 2) modulene oppdaterer intern tilstand og returnerer deretter til main, ingen moduler har dermed lov til å oppholde progammet mer enn et kort øyeblikk. Dette sikrer at hver modul får oppdatert sin interne informasjon ofte, slik at man unngår alle problemer med at man f.eks ikke rekker å registrere at en knapp trykkes inn, eller at heisen passerer forbi en etasje. 

=== Midtfasen av implementasjonen
Etter å ha bestemt oss for hvilke moduler vi skulle ha, bestemte vi oss for nøyaktig hvilken informasjon de skulle utveksle, og formatet på informasjonen, slik at vi kunne programere modulene hver for seg. Dette steget gjorde vi i stor grad uten å tenke på hvilken funksjonalitet c tilbyr, og vi kikket heller ikke på hvordan kommunikasjon med heisen var implementert. Dette var en tabbe som vi i etterkant måtte rette opp i, ved for eksmepel å definere noen felles struct-er og enum-er som hele prosjektet forholder seg til. Noen ting har derimot blitt med gjennom hele prosjektet, for eksempel bruker systemt vårt 1-4 som etasjer, i motsetning til den utdelte koden, som benytter 0-3. 

Vi oppdaget mens vi programerte modulene at én av modulene var redundant, så vi fjernet den, og ente opp med modulene beskrevet tildligere i rapporten. 

=== Sluttfasen av implementasjonen
Når vi hadde skrevet all koden fant vi ut at det var litt jobb å skrive kode for teste hver modul hver for seg. Vi droppet derfor enhetstesting og gikk rett på implementasjonstestning. Koden var nesten helt problemfri, og så tydelig som vi hadde fordelt ansvaret mellom modulene var det enkelt å spore feil til korrekt modul. Og siden kommunikajsonen mellom modulene er enkel, er systemet vårt lite komplekst, vi hadde derfor ikke problemer med feil som oppstår i obskure spesialtilfeller. Etter litt enkel implementasjonstestning hadde vi et fungerende system.

Vi oppdaget derimot at vi hadde tenkt litt feil på hvilken rekkefølge man burde prioritere etasjene, men siden queue-modulen har ansvaret for å bestemme hva heisen skal gjøre, og resten av systemet virker uavhening av queue, kunne vi endre queue til korrekt oppførsel, uten at dette ga bug-er i resten av systemet. 

=== Vurdering av vår bruk av UML og V-modellen
Vi hadde stor nytte av å dele prosjektet i mindre moduler med tydelige oppgaver, slik V-modellen legger opp til. Modulene vi endte opp med var i veldig stor grad enkle å oversette til kode, kanskje med unntak av queue, og det er relativt tydelig hva de ulike modulene skal gjøre. For å klare å dele prosjektet på denne måten hadde vi stor nytte av klassediagrammet vi satte opp, og noen sekvensdiagrammer vi skisserte.

Systemet virket derimot så godt at det var fornuftig å ignorere enhetstesting, vi har altså til en viss grad tilpasset V-modellen litt. 
\

Vi benyttet oss derimot ikke av tilstandsdiagramet tidligere i rapporten, det er lagd i etterkant, etter at heisen fungerte. Vi tror derimot det ville vært veldig nyttig for å få et enda enklere system. Koden til queue gjør i praksis det tilstandsdiagramet sier, men den er ikke tydelig implementert som en tilstandmaskin med klart definerte tilstander, dette gjør queue mer kompleks enn den trenger å være. Så erfaringen vår er at UML-skjemaene var svært nyttige, og at det ikke lønnte seg å ikke ta seg tid til også å lage et tilstandsdiagram. 