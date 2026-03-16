#figure(
  placement: auto,
  image("Sekvensdiagram Startup.jpg", width: 120%),
  caption: [Sekvensdiagram som viser interaksjonene mellom modulene under oppstart av heisen.],
  scope: "parent"
) <sekvensdiagram_oppstart>

== Sekvensdiagramer
=== Sekvensdiagram for oppstart
@sekvensdiagram_oppstart viser sekvensdiagrammet for oppstart. Oppstart-fasen kjører til heisen kommer i en kjent tilstand, altså befinner seg i en etasje. Under oppstart får main startUp og Output til å oppdatere sin interne tilstand. Dette betyr at de løser oppgavene sine som beskrevet i delen om klassediagrammet. Se #link(<klassediagram_tekst>)[#text(blue)[klassediagram]].