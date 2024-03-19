# Color-Sorter

Proiectul propus se intituleaza Sorting Machine si reprezinta un dispozitiv care sorteaza obiecte in functie de culoare.

# Functionalitati 
Dispozitivul creat are scopul de a sorta bomboane in functie de cele cinci culori alese: rosu, mov, verde, galben si portocaliu. Aceste bomboane se introduc pe tubul vertical si cad pe placuta care deplaseaza bomboana sub senzorul de culoare. Dupa ce senzorul intercepteaza datele, toboganul se pozitioneaza astfel incat bomboana sa cada in recipientul aferent culorii sale. 

# Imagini
![Imagine1](Imagini/poza1.jpeg "Imagine1")
![Imagine2](Imagini/poza2.jpeg "Imagine2")
![Imagine3](Imagini/poza3.jpeg "Imagine3")



# Componente utilizate
|Componenta                |Cantitate                          |                        
|----------------|-------------------------------
|Senzor de culoare TCS3200|1            
|Arduino Uno          |  1           
|Breadboard          | 1 
|Fire | 11 
|Servo Motor | 2 

# Etapa de proiectare
Macheta proiectului a fost construita cu ajutorul cartonului mousse, un material usor, dar rezistent, cu care am putut lucra foarte usor. Bucatile de carton au fost asamblate cu ajutorul unui pistol de lipit.

Urmatoarea etapa a fost aceea de a imbina componentele circuitului electric pe macheta creata, etapa care a necesitat un timp indelungat pentru a face testele necesare. 

In ultima etapa am creat codul final Arduino. Aceasta etapa a presupus numeroase teste pentru fiecare culoare. Senzorul de culoare TCS3200 are capacitatea de a detecta culorile pe baza spectrului RGB (roșu, verde și albastru). Am creat functia de detectie a culorii analizand valorile furnizate de senzor.

# Dificultati intamplinate
Dificultatile intampinate au fost legate de detectia culorii. Valorile oferite de senzor semanau foarte mult pentru anumite culori, iar din aceasta cauza, uneori, dispozitivul conducea bomboana in recipientul gresit. Am reusit sa rezolv acest lucru din cod, modificand conditiile strucuturilor decizionale in functie de testele efectuate. Daca la inceput am incercat sa incadrez valorile furnizate in anumite intervale pentru fiecare culoare, am observat o imbunatatire atunci cand am folosit intervale nu direct pentru valori, ci pentru diferentele dintre ele. Insa, nici aceasta metoda nu oferea rezultatele asteptate, avand succes doar in 60% din cazuri. Solutia a fost sa analizez si sa folosesc rapoartele dintre valori, fapt care a imbunatatit rata de succes a dispozitivului

# Bibliografie 
1. https://docs.arduino.cc/hardware/uno-rev3
2. https://docs.arduino.cc/learn/
3. http://www.openimpulse.com/blog/wp-content/uploads/wpsc/downloadables/TCS3200-Color-Light-to-Frequency-Converter-Datasheet.pdf
