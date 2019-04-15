Zamfir Ovidiu - Ionut 325 CD

		README - Lowest Common Ancestor

Cele doua surse cu implementarile algoritmului LCA sunt LCA_using_RMQ.cpp si TarjanLCA.cpp.
Cele doua programe primesc datele de intrare in fisierul lca.in si afiseaza output-ul in lca.out.
Testele au fost generate automat random cu ajutorul sursei generator.cpp,
implementata de mine, care pentru doua numere N si M genereaza un arbore cu N noduri si M query-uri pe arbore.
	Algoritmul de generare a arborelui functioneaza in felul urmator:
		-> consideram mereu ca radacina se afla in nodul 1
		-> ca sa retinem un arbore este suficient sa stim pentru fiecare
			nod care este parintele acestuia, mai putin pentru 				
			radacina
		-> astfel orice arbore poate fi reprezentat ca o insiruire de
			N - 1 numere de la 1 la N
		-> pentru a genera un arbore cu N noduri este suficient sa 				
			generam o astfel de insiruire, iar apoi sa verificam
			daca graful rezultat este conex
		-> graful are N - 1 muchii si exte conex => graful este arbore
		-> repetam algoritmul pana cand graful generat este arbore
	
Pentru a genera cele M query-uri pur si simplu generam aleator perechi de numere de la 1 la N, avand grija sa nu generam un query de 2 ori.
Nu am automatizat generarea testelor de intrare deoarece generarea acestora dureaza foarte mult (spre exemplu 25 de minute pentru testul 11) si nu am avut timp sa le generez pe toate deodata, generatorul fiind unul brute-force.
Pentru a genera output-ul testelor de intrare am folosit varianta brute-force a algoritmului, precum si script-ul gen_out.sh care a generat automat un output pentru fiecare din cele 10 teste de intrare.
Pentru verificare am implementat script-urile Tarjan_check.sh si RMQcheck.sh care testeaza corectitudinea algoritmilor, afiseaza durata, memoria si calculeaza scorul obtinut de fiecare implementare.

Am generat teste de dimensiune mica (N >= 1 && N <= 20), medie (N >= 20 && N <= 1000), cat si teste foarte mari(N >= 1000 && N <= 10^5).Testele au un atat un numar variat de noduri, cat si un numar variat de query-uri( pana la 2 * 10^6) pentru a putea analiza cat mai bine comportamentul implementarilor, si a putea vedea care este cea mai eficienta (considerand criterii de timp, memorie etc.)

Input-ul are urmatorul format:
	-> pe prima linie 2 numere N si M
	-> pe linia a doua N - 1 numere, numarul de pe pozitia i reprezentand parintele nodului i + 1
	-> pe urmatoarele M linii cate o pereche de noduri din arbore, reprezentand fiecare cate un query

Output-ul are urmatorul format:
	-> pe M linii raspunsul la fiecare din cele M query-uri

Restrictii:
	-> N <= 10^5
	-> M <= 2 * 10^6

