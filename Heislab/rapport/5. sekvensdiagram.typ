#pagebreak()
#figure(
  placement: auto,
  image("sekvensdiagram.jpg", width: 120%),
  caption: [Sekvensdiagram som viser interaksjonen mellom modulene under vanlig kjøring av heisen. Merk at funksjonsnavnene er forkortet. Alle funksjonene har en prefiks som er navnet på modulen den tilhører. F.eks skal første kall fra main være inputUpdate() ikke update().],
  scope: "parent"
) <sekvensdiagram>
#pagebreak()

=== Sekvensdiagram for vanlig kjøring
@sekvensdiagram viser hvordan modulene intragerer under vanlig kjøring. main får de ulike modulene til å oppdatere sin interne tilstand. Når modulene skal oppdatere sin interne tilstand, henter de informasjon fra de modulene de trenger informasjon fra. At en modul oppdaterer sin interne tilstand betyr at de løser de oppgavene de har ansvar for, som beskrevet i delen om klassediagrammet. Se #link(<klassediagram_tekst>)[#emph[klassediagram]].