


# <center>**Sort me out**</center>
Dokumentacja grupowego projektu z dziedziny algorytmów sortowania oraz generowania losowych ciągów w języku programowania C++. Projekt jest realizowany w cztero osobowym zespole. Zadanie jest przygotowywane na zajęcia z informatyki rozszerzonej.

----------

<center>Autorzy projektu:</center>
<center>Krzysztof "Dzban",</center>
<center>Łukasz  "lokcio",</center>
<center>Krzysztof "kak500"</center>
<center>Tomasz  </center>

----------
<center>Poznań 2018</center>
<center>ver. 1.0</center>


----------
Dokumentacja przygotowana w języku znaczników Markdown. Zalecane jest czytanie tej dokumentacji na dokumentacji repozytorium pod adresem: **https://github.com/Dzban/sortmeout**
Tam również znajduje się kod źródłowy programu. Dokumentacja w formie PDFa została stworzona tylko na potrzeby wymagań do projektu znajdującego się pod adresem http://druggist.github.io/teaching/data/proj_prog.pdf

# Opis projektu
Projekt groupowy sortmeout to projekt mający na celu poznanie oraz popularyzacje algorytmów sortowania oraz naukę pracy zespołowej podczas programowania.
W celu lepszego zarządzania projektem grupa zdecydowała na użycie rozproszonego systemu kontroli wersji - Git.

Projekt składa się z następujących funkcjonalności
* generowanie ciągów o podanej przez użytkownika długości
* zapisywanie ciągów do pliku
* odczytywanie ciągów z pliku
* sortowanie ciągów za pomocą selection sort
* sortowanie ciągów za pomocą insertion sort
* sortowanie ciągów za pomocą bubble sort
* sortowanie ciągów za pomocą merge sort
* sortowanie ciągów za pomocą quick sort
* pomiary czasu sortowań

# Algorytmy sortowań
## Selection sort (sortowanie przez wybieranie)
![selection sort](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/Selection_sort_animation.gif/240px-Selection_sort_animation.gif)

Algorytm selection sort wyszukuje najmniejszy element z całej tablicy i wstawia go jako ostatni element tablicy posortowanej.

## Pseudokod
```c++
function selectionSort(array a)
  for i in 0 -> a.length - 2 do
    maxIndex = i
		  for j in (i + 1) -> (a.length - 1) do
  		  if a[j] > a[maxIndex]
      		maxIndex = j
  		swap(a[i], a[maxIndex])
```

## Złożoność
| Sytuacja | Złożoność |
| --- | --- |
| pesymistyczna | O(n^2) |
| typowa | O(n^2) |
| optymistyczna | O(n^2) |

## Przykład
| iteracja | tablica | minimum |
| ---: | :---: | :---: |
| 0 | [/**15, 14, 3, >>1<<, 2, 5, 11, 4**] | 1 |
| 1 | [1, /**15, 14, 3, >>2<<, 5, 11, 4**] | 2 |
| 2 | [1, 2, /**15, 14, >>3<<, 5, 11, 4**] | 3 |
| 3 | [1, 2, 3, /**15, 14, 5, 11, >>4<<**] | 4 |
| 4 | [1, 2, 3, 4, /**15, 14, >>5<<, 11**] | 5 |
| 5 | [1, 2, 3, 4, 5, /**15, 14, >>11<<**] | 11 |
| 6 | [1, 2, 3, 4, 5, 11, /**15, >>14<<**] | 14 |
| 7 | [1, 2, 3, 4, 5, 11, 14, /**>>15<<**] | 15 |
| 8 | [1, 2, 3, 4, 5, 11, 14, 15] | ciąg jest posortowany |
* _**porgrubione** - nieposortowana tablica_
* _/ - granica nieposortowanej tablicy_
* _>>5<< - minimalna wartość_

---

## Insertion sort (sortowanie przez wstawianie)
![insertion sort](https://upload.wikimedia.org/wikipedia/commons/thumb/2/25/Insertion_sort_animation.gif/240px-Insertion_sort_animation.gif)

Algorytm insertion sort bierze dowolny (nie ma znaczenia który) element z tablicy nieposortowanej i wstawia w odpowiednie miejsce w tablicy posortowanej.

![insertion sort](https://upload.wikimedia.org/wikipedia/commons/thumb/0/0f/Insertion-sort-example-300px.gif/220px-Insertion-sort-example-300px.gif)

## Pseudokod
```c++
function  insertionSort(A, n) // A[0..n-1]
  for i=1 to n:
    klucz = A[i]
    // Wstaw A[i] w posortowany ciąg A[1 ... i-1]
    j = i - 1
    while j>=0 and A[j]>klucz:
      A[j + 1] = A[j]
      A[j] = klucz
      j--
```

## Złożoność
| Sytuacja | Złożoność |
| --- | --- |
| pesymistyczna | O(n^2) |
| typowa | O(n^2) |
| optymistyczna | O(n) |

## Przykład
| iteracja | tablica |
| ---: | :---: |
| 0 | [3, **15, 14, 1, 2, 5, 11, 4**] |
| 1 | [3, 15, **14, 1, 2, 5, 11, 4**] |
| 2 | [3, 14, 15, **1, 2, 5, 11, 4**] |
| 3 | [1, 3, 14, 15, **2, 5, 11, 4**] |
| 4 | [1, 2, 3, 14, 15, **5, 11, 4**] |
| 5 | [1, 2, 3, 5, 14, 15, **11, 4**] |
| 6 | [1, 2, 3, 5, 11, 14, 15, **4**] |
| 7 | [1, 2, 3, 4, 5, 11, 14, 15] |
* _**porgrubione** - nieposortowana tablica_

---

## Bubble sort (sortowanie bąbelkowe)
![bubble sort](https://upload.wikimedia.org/wikipedia/commons/thumb/3/37/Bubble_sort_animation.gif/240px-Bubble_sort_animation.gif)

Algorytm bubble sort porównuje dwa kolejne sąsiadujące elementy i w razie konieczności zamienia je aż do końca. Czynność jest powtarzana, aż do sytuacji w której w ciągu przejścia całej tablicy nie dokonano żadnej zmiany - tablica jest posortowana.

![bubble sort](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

### Pseudokod
```c++
function  bubbleSort(A, n) // A[0..n-1]
  for i=0 to n:
    for j=1 to n:
      if A[j-1] > A[j]:
        swap(A[j-1], A[j])
```

### Złożoność
| Sytuacja | Złożoność |
| --- | --- |
| pesymistyczna | O(n^2) |
| typowa | O(n^2) |
| optymistyczna | O(n) |

### Przykład
| iteracja | tablica |
| ---: | :---: |
| 0 | [3, 15, 14, 1, 2, 5, 11, 4] |
| 1 | [3, 14, 1, 2, 5, 11, 4, 15] |
| 2 | [3, 1, 2, 5, 11, 4, 14, 15] |
| 3 | [1, 2, 3, 5, 4, 11, 14, 15] |
| 4 | [1, 2, 3, 4, 5, 11, 14, 15] |

## Merge sort (sortowanie przez scalanie)
![merge sort](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c5/Merge_sort_animation2.gif/240px-Merge_sort_animation2.gif)

Algorytm mergesort dzieli tablice na dwie równe części. Dla każdej z części stosouje algorytm sortowanie przez scalanie lub zwraca element jeśli został tylko jeden. Po wykonanych działaniach łączy tablice w całość.

Scalanie wykonuje się następująco:
* Indeksy tablicy A oraz B są ustawione na pierwsze elementy.
* Jeżeli ciąg A wyczerpany (i>n), dołącz pozostałe elementy ciągu B do C i zakończ pracę.
* Jeżeli ciąg B wyczerpany (j>m), dołącz pozostałe elementy ciągu A do C i zakończ pracę.
* Jeżeli A[i] <= B[j] dołącz A[i] do C i zwiększ i o jeden, w przeciwnym przypadku dołącz B[j] do C i zwiększ j o jeden
* Powtarzaj od kroku 2 aż wszystkie wyrazy A i B trafią do C.

![merge sort](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)


### Pseudokod
```c++
function mergesort( var a as array )
  if(n ==1)
    return a
  var l1 as array = a[0] ... a[n/2]
  var l2 as array = a[n/2+1] ... a[n]

  l1 = mergesort( l1 )
  l2 = mergesort( l2 )

  return merge( l1, l2 )
```

Funkcja scalająca
```c++
function merge( var a as array, var b as array )
  var c as array

  while ( a and b have elements )
    if ( a[0] > b[0] )
      add b[0] to the end of c
      remove b[0] from b
    else
      add a[0] to the end of c
      remove a[0] from a

    while ( a has elements )
      add a[0] to the end of c
      remove a[0] from a
    while ( b has elements )
      add b[0] to the end of c
      remove b[0] from b

  return c
```

### Złożoność
| Sytuacja | Złożoność |
| --- | --- |
| pesymistyczna | O(n^2) |
| typowa | O(n^2) |
| optymistyczna | O(n) |

### Przykład
![merge sort](https://upload.wikimedia.org/wikipedia/commons/6/60/Mergesort_algorithm_diagram.png)

## Quicksort (sortowanie szybkie)
 ![merge sort](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

Z tablicy wybiera się element rozdzielający, po czym tablica jest dzielona na dwa fragmenty: do początkowego przenoszone są wszystkie elementy nie większe od rozdzielającego, do końcowego wszystkie większe. Potem sortuje się osobno początkową i końcową część tablicy. Rekursja kończy się, gdy kolejny fragment uzyskany z podziału zawiera pojedynczy element, jako że jednoelementowa tablica nie wymaga sortowania.

### Pseudokod
```c++
function quick(s){
    quickPart(s,0,s.size()-1);
    return s;
}

quickPart(s[] , b, e){
    j = b;
    pivot = s[e];
    for i = b to e:
        if (s[i] <= pivot)
            std::swap(s[i], s[j]);
            j++;
    j--;
    if(j + 1 < e)
        quickPart(s, j+1, e);

    if(j-1 > b)
        quickPart(s, b, j-1);
    return true;
}
```

 ### Złożoność
 | Sytuacja | Złożoność |
 | --- | --- |
 | pesymistyczna | O(n^2) |
 | typowa | O(n log n) |
 | optymistyczna | O(n log n) |

 ### Przykład
 ![merge sort](https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/Quicksort-diagram.svg/240px-Quicksort-diagram.svg.png)


# Działanie algorytmów
![wykres](wykres.svg)
Powyższy wykres obrazuje czas jaki potrzebują dane algorytmy w zależności od liczby danych do posortowania. Czyli przedstawia złożoność czasową.
# Wnioski
Wnioski zostały podzielone na część. Trzy odnoszą się do wykonywania projektu ostatni jest wnioskami który wynika z obserwacji już działającego programu (obserwacje). Pierwsze dwie z tym co się udało zrealizować (sukcesy) i na to co się nie udało i co warto by było poprawić (porażki) przy realizacji następnych projektów. Ostatni akapit wskazuje na możliwe rozwiązania porażek oraz rozwinięcie sukcesów (wnioski z projektu).


## Sukcesy
* Napisanie aplikacji w paradygmacie obiektowym.
* Zapoznanie części zespołu z Gitem, Jest to podwójny sukces ze względu na to że:
  * Krzysztof usystematyzował swoją wiedzę do poziomu aby nauczyć gita Łukasza, poznał i wymyślił rozwiązania problemów i błędów na które sam by nie wpadł. Co bez wątpienia podniosła umiejętności dydaktyczne Krzysztofa.
   * Łukasz poznał Gita.
 * Poznanie nowej technologi pisania dokumentacji - Markdown.
 * Implementacja wszystkich wymaganych algorytmów sortowania.
 * Nabycie większego doświadczenia w przeszukiwaniu anglojęzycznych źródeł informacji i pomocy dotyczącej programowania.
## Porażki
* Nie wszyscy członkowie zespołu byli skłonni nauczyć się Gita.
* Tylko Krzysztof przeprowadził refaktoryzacje kodu.
* Brak przeprowadzenia dokładnych testów wydajnościowych implementacji algorytmów.
* Kiepski kontakt między niektórymi członkami grupy.
* Brak spotkań podsumowujących etapy wykonywania projektu.  
## Wnioski z projektu
* Dobrze by było spotkać się aby stworzyć całą grupą plan wykonania projektu i nadawać terminy na zakończenie poszczególnych etapów.
* Większe zangarzowanie nie których członków zespołu poprzez lepszy kontakt - brak facebooka można nadrobić zakładając grupę na Slacku.
* Po poszczególnych etapach wykonywanie refaktoryzacji przez kolejnych członków grupy.
* W czasie pierwszego spotkania zaznajomić wszystkich z Gitem.
## Obserwacje
* Dzięki zastosowaniu OOP dalszy rozwój będzie łatwy do zrealizowania.
* Różne algorytmy różnią się zarówno skomplikowaniem jak i złożonością obliczeniową. Zazwyczaj jest ona odwrotnie proporcjonalna do złożoności algorytmu.
*  Niektóre algorytmy mogą przepełnić stos wywołując się rekurencyjnie.
* Wykorzystanie wektorów zamiast tablic znacznie przyśpieszyło pisanie kodu.
# Dalszy rozwój projektu
Oto dalsze pomysły na rozwój programu:
* możliwa implementacja dodatkowych algorytmów sortowania
* refaktoryzacja kodu
* printowanie wyników w ładnych tabelach
* dodanie dodatkowych presetów sortowań (np. quicksort ze zmienną długością ciągu z przeskokiem **n** )
* dodanie sortowanie stringów
* obsługa parametrów uruchomieniowych
* optymalizacja algorytmów sortowania

# Podział procentowy wykonanej pracy
Krzysztof - 30%
Łukasz - 25%
Krzysztof - 25%
Tomasz - 20%
