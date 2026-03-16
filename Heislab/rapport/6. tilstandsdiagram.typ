#pagebreak()
#figure(
  placement: auto,
    image("tilstandsdiagram.jpg", width: 120%),
  caption: [Tilstandsdiagram som beskriver hvordan systemet vi har implementert styrer motoren og døren.],
  scope: "parent"
) <tilstandsdiagram>
#pagebreak()

== Tilstandsdiagram
@tilstandsdiagram viser hvordan vi styrer motoren og døren. Heisen har fire tilstander, stå stille med lukket dør, stå stille med åpen dør, kjør oppover og kjør nedover. Heisen har dessuten to moduser: opp- og ned-modus. Dersom heisen er i opp-modus betjener den bare ordre til personer som befinner seg i samme etasje som heisen eller i en etasje over heisen. Den betjener kun ordrene til folk som vil oppover, men dersom ingen vil oppover betjener heisen den øvreste ordren som vil nedover. Dersom det ikke finnes en eneste ordre over posisjonen til heisen, bytter heisen til ned-modus. Ned-modus virker som opp-modus, men motsatt. 

Mens heisen venter på å betjene ordre står den stille og oscillerer den mellom opp- og ned-modus. 