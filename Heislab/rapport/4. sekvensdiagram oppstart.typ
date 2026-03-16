#figure(
  placement: auto,
  image("Sekvensdiagram Startup.jpg", width: 120%),
  caption: [Sekvensdiagram som viser interaksjonene mellom modulene under oppstart av heisen.],
  scope: "parent"
) <sekvensdiagram_oppstart>

== Sekvensdiagramer
=== Sekvensdiagram for oppstart
@sekvensdiagram_oppstart viser sekvensdiagrammet for oppstart. Oppstartfasen kjører til heisen kommer i en kjent tilstand, altså befinner seg i en etasje. Under oppstart får main startup- og output-modulen til å oppdatere sin interne tilstand. At de oppdaterer sin interne tilstand betyr at de løser oppgavene sine, som beskrevet i delen om klassediagrammet. Se #link(<klassediagram_tekst>)[#text(blue)[klassediagram]]. StartUp returnerer nedover som motorretning til output, helt til heisen når en etasje, da skal motoren stoppe. 