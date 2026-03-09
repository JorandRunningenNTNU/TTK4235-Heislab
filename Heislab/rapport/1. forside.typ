#let month = ("januar", "februar", "mars", "april", "mai", "juni", "juli", "august",
              "september", "oktober", "november", "desember")

#align(center)[
  #v(1fr)
  #text(size: 28pt, weight: "bold")[Heislab TTK4235 Gruppe 55]
  #v(12pt)
  #text(size: 16pt)[Emma Øverbø Johannessen, Jørand Runningen]
  #v(8pt)
  #let today = datetime.today()
  #text(size: 14pt)[#today.day(). #month.at(today.month()-1) #today.year()]
  #v(1fr)
]