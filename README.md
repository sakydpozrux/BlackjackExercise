BlackjackExercise
==================

Blackjack 

Do Blackjack'a wykorzystuje się talię złożoną z 52 kart. Gra polega na tym, aby zdobyć 21 punktów lub jak najbardziej zbliżyć się do tej liczby.

W kasynie rozgrywka odbywa się między grającym, a krupierem. Gra podzielona jest na rundy. Jeśli przed rozpoczęciem rundy w talii znajduje się mniej niż 4 karty, gra kończy się.

Każda runda rozpoczyna się od rozdania 2 kart każdej ze stron. Gracz na podstawie wartości posiadanych kart (patrz punktacja kart w Blackjacku) podejmuje decyzje czy chce dobierać
kolejne karty. Jeżeli suma jego kart przekroczy 21 automatycznie przegrywa, w przypadku gdy zdobędzie 21 punktów wygrywa automatycznie. 

W momencie gdy gracz zrezygnuje z dobierania kolejnych kart, krupier odkrywa swoje i rozpoczyna grę. Jeżeli suma kart krupiera wynosi mniej niż 17 to według zasad musi on dobrać kolejną kartę, 
w przeciwnym wypadku zawsze kończy dobieranie kart. Jeśli krupier zdobędzie więcej punktów niż gracz, nie przekraczając 21, wygrywa rundę. W przypadku remisu, rundę wygrywa krupier.

Napisz program realizujący grę w Blackjack'a wg. wymienionych zasad. Zaimplementuj dwie strategie dla gracza:

 - bezpieczną polegającą na nie dobieraniu kart, w momencie gdy suma posiadanych przez niego kart jest większa od 11
 - maksymalizującą ilość wygranych

W trakcie każdej rundy program powinien wyświetlać na stdout jej przebieg w postaci:
   
    [PLAYER/CROUPIER] : [wartości dobranych kart] : [suma dobranych kart]
    ...
    END OF ROUND: [PLAYER/CROUPIER] WON, SCORE(PLAYER: [wartość], CROUPIER: [wartosc])
    ...
    
np:
    
    PLAYER: 10 8 : 18
    PLAYER: 10 8 2 : 20 
    CROUPIER: 2 4 : 6
    CROUPIER: 2 4 9 : 15
    CROUPIER: 2 4 9 3 : 18
    END OF ROUND: PLAYER WON, SCORE(PLAYER: 1, CROUPIER: 0)
    ...

Talia do gry dostarczona jest w pliku. Program powinien wczytywać plik podany jako argument.

Przykładowa talia wejściowa:
----------------------------

    10 4 10 3 10 2 3 6 9 9 5 1 9 10 10 5 1 8 8 8 10 6 5 6 10 10 3 10 1 7 4 2 3 7 10 2 7 1 5 10 8 10 7 2 10 10 10 6 9 10 4 4

Punktacja kart w Blackjacku:
----------------------------

 - Karty 2 do 9 mają wartość równą wartości karty (3 karo ma wartość 3 itd).
 - 10, Walet, Dama i Król mają wartość równą 10 punktów.
 - As ma wartość równą 1

Uwagi dodatkowe:
---------------

 - gra kończy się również jeśli podczas rundy w talii zabraknie kart
 - rozwiązanie powinno zawierać również testy jednostkowe.

Kryteria oceny programu:
------------------------

 - poprawność, 
 - obsługa błędów,
 - styl (nazwenictwo, konstrukcje obiektowe),
 - kompletność dostarczonego materiału (powinien być łatwy do skompilowania i uruchomienia)
