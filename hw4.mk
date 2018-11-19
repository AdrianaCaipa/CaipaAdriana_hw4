Resultados_hw4.pdf: Promedio_f.png Promedio_p.png Promedio_l.png Temperatura_f.png Temperatura_estadof.png Temperatura_estado2f.png Temperatura_estadofinf.png Temperatura_p.png Temperatura_estado1p.png Temperatura_estado2p.png Temperatura_estadofinp.png Temperatura_l.png Temperatura_estadol.png Temperatura_estado2l.png Temperatura_finl.png Adriana_CaipaGrafica45.png Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
	rm *.png
	rm *.txthw
Promedio_f.png Promedio_p.png Promedio_l.png Temperatura_f.png Temperatura_estadof.png Temperatura_estado2f.png Temperatura_estadofinf.png Temperatura_p.png Temperatura_estado1p.png Temperatura_estado2p.png Temperatura_estadofinp.png Temperatura_l.png Temperatura_estadol.png Temperatura_estado2l.png Temperatura_finl.png Adriana_CaipaGrafica45.png: Plots_hw4.py promedio_f.txt promedio_p.txt promedio_l.txt temperatura_f.txt temperatura_p.txt temperatura_l.txt datos45.txt

	python Plots_hw4.py

datos45.txt: ODE.cpp
	g++ ODE.cpp
	./a.out
	rm *.out

promedio_f.txt promedio_p.txt promedio_l.txt temperatura_f.txt temperatura_p.txt temperatura_l.txt: PDE.cpp
	g++ PDE.cpp
	./a.out
	rm *.out

