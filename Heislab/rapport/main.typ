#set text(lang: "nb")
#show heading.where(level: 2): set text(size: 12pt) 


#include "1. forside.typ"

#set page(columns: 2,
    footer: context{
        let p = counter(page).get().at(0)
        let total = counter(page).final().at(0)
        
        if p > 1{
            align(center)[side #(p - 1) av #(total - 1)]
        }
    }
)

#include "2. intro UML.typ"

\

#include "3. klassediagram.typ"

\

#include "4. sekvensdiagram.typ"

\

#include "5. tilstandsdiagram.typ"

\

#include "6. refleksjoner UML og V-modell.typ"

\

#include "7. refleksjoner KI.typ"

\

#include "8. refleksjoner robushet.typ"